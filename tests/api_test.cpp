// The module's functions over compat.zlib: a one-call round trip, a stream
// compressed in pieces and inflated through the macros of
// <mwrap/zlib/macros.hpp>, the two checksums against published values, and a
// gzip file written and read back.
#include <mwrap/zlib/macros.hpp>
import std;
import mcpplibs.mwrap.zlib;

namespace m = mcpplibs::mwrap::zlib::macros;

int main()
{
    int failures = 0;
    auto check = [&](bool ok, std::string_view what) {
        std::println("{} {}", ok ? "ok  " : "FAIL", what);
        failures += ok ? 0 : 1;
    };

    std::string text;
    for (int i = 0; i < 400; ++i) text += std::format("line {} of a repetitive text\n", i % 17);
    const auto* bytes = reinterpret_cast<const Bytef*>(text.data());

    // One call each way.
    std::vector<Bytef> packed(compressBound(text.size()));
    uLongf packed_size = packed.size();
    check(compress2(packed.data(), &packed_size, bytes, text.size(), m::Z_BEST_COMPRESSION) == m::Z_OK,
          "compress2 at Z_BEST_COMPRESSION");
    check(packed_size < text.size() / 4, "the repetitive text shrinks");
    std::string back(text.size(), '\0');
    uLongf back_size = back.size();
    check(uncompress(reinterpret_cast<Bytef*>(back.data()), &back_size, packed.data(), packed_size) == m::Z_OK
              && back == text, "uncompress restores it");

    // A raw stream, fed in pieces; deflateInit2 and inflateInit2 are macros.
    z_stream out{};
    check(deflateInit2(&out, m::Z_DEFAULT_COMPRESSION, m::Z_DEFLATED, -m::MAX_WBITS, m::MAX_MEM_LEVEL,
                       m::Z_DEFAULT_STRATEGY) == m::Z_OK, "deflateInit2, raw");
    std::vector<Bytef> raw(deflateBound(&out, text.size()));
    out.next_out = raw.data();
    out.avail_out = static_cast<uInt>(raw.size());
    for (std::size_t at = 0; at < text.size(); at += 1000) {
        const auto n = std::min<std::size_t>(1000, text.size() - at);
        out.next_in = const_cast<Bytef*>(bytes + at);
        out.avail_in = static_cast<uInt>(n);
        const bool last = at + n == text.size();
        const int rc = deflate(&out, last ? m::Z_FINISH : m::Z_NO_FLUSH);
        if (rc != (last ? m::Z_STREAM_END : m::Z_OK)) check(false, "deflate a piece");
    }
    const auto raw_size = out.total_out;
    check(deflateEnd(&out) == m::Z_OK, "deflateEnd");
    z_stream in{};
    check(inflateInit2(&in, -m::MAX_WBITS) == m::Z_OK, "inflateInit2, raw");
    std::string inflated(text.size(), '\0');
    in.next_in = raw.data();
    in.avail_in = static_cast<uInt>(raw_size);
    in.next_out = reinterpret_cast<Bytef*>(inflated.data());
    in.avail_out = static_cast<uInt>(inflated.size());
    check(inflate(&in, m::Z_FINISH) == m::Z_STREAM_END && inflated == text, "inflate restores the stream");
    check(inflateEnd(&in) == m::Z_OK, "inflateEnd");

    // The checksums of "123456789", as their specifications publish them.
    const auto* digits = reinterpret_cast<const Bytef*>("123456789");
    check(crc32(crc32(0, nullptr, 0), digits, 9) == 0xCBF43926u, "crc32 of 123456789");
    check(adler32(adler32(0, nullptr, 0), digits, 9) == 0x091E01DEu, "adler32 of 123456789");

    // A gzip file; gzgetc is a macro over the file's buffer.
    const auto path = (std::filesystem::temp_directory_path() / "zlib-m-api-test.gz").string();
    gzFile file = gzopen(path.c_str(), "wb9");
    check(file != nullptr && gzwrite(file, text.data(), static_cast<unsigned>(text.size())) == int(text.size())
              && gzclose(file) == m::Z_OK, "gzwrite a file");
    file = gzopen(path.c_str(), "rb");
    std::string read;
    for (int c; file && (c = gzgetc(file)) != -1;) read += static_cast<char>(c);
    check(file != nullptr && gzclose(file) == m::Z_OK && read == text, "gzgetc reads it back");
    std::filesystem::remove(path);

    check(std::string_view(zlibVersion()) == m::ZLIB_VERSION, "zlibVersion() is ZLIB_VERSION");
    std::println("{} failures", failures);
    return failures != 0;
}
