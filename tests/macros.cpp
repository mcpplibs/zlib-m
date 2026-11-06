// Each constant and type of mcpplibs.mwrap.zlib.macros equals its macro. A macro
// expands even in a qualified name, so the values of the headers are taken under other
// names and the macros undefined before the mapped names are used. Written by
// tools/generate.py.
#include <zlib.h>

namespace header {
inline constexpr auto value_MAX_MEM_LEVEL = (MAX_MEM_LEVEL);
inline constexpr auto value_MAX_WBITS = (MAX_WBITS);
inline constexpr auto value_ZLIB_VERNUM = (ZLIB_VERNUM);
inline constexpr auto value_ZLIB_VERSION = (ZLIB_VERSION);
inline constexpr auto value_ZLIB_VER_MAJOR = (ZLIB_VER_MAJOR);
inline constexpr auto value_ZLIB_VER_MINOR = (ZLIB_VER_MINOR);
inline constexpr auto value_ZLIB_VER_REVISION = (ZLIB_VER_REVISION);
inline constexpr auto value_ZLIB_VER_SUBREVISION = (ZLIB_VER_SUBREVISION);
inline constexpr auto value_Z_ASCII = (Z_ASCII);
inline constexpr auto value_Z_BEST_COMPRESSION = (Z_BEST_COMPRESSION);
inline constexpr auto value_Z_BEST_SPEED = (Z_BEST_SPEED);
inline constexpr auto value_Z_BINARY = (Z_BINARY);
inline constexpr auto value_Z_BLOCK = (Z_BLOCK);
inline constexpr auto value_Z_BUF_ERROR = (Z_BUF_ERROR);
inline constexpr auto value_Z_DATA_ERROR = (Z_DATA_ERROR);
inline constexpr auto value_Z_DEFAULT_COMPRESSION = (Z_DEFAULT_COMPRESSION);
inline constexpr auto value_Z_DEFAULT_STRATEGY = (Z_DEFAULT_STRATEGY);
inline constexpr auto value_Z_DEFLATED = (Z_DEFLATED);
inline constexpr auto value_Z_ERRNO = (Z_ERRNO);
inline constexpr auto value_Z_FILTERED = (Z_FILTERED);
inline constexpr auto value_Z_FINISH = (Z_FINISH);
inline constexpr auto value_Z_FIXED = (Z_FIXED);
inline constexpr auto value_Z_FULL_FLUSH = (Z_FULL_FLUSH);
inline constexpr auto value_Z_HUFFMAN_ONLY = (Z_HUFFMAN_ONLY);
inline constexpr auto value_Z_MEM_ERROR = (Z_MEM_ERROR);
inline constexpr auto value_Z_NEED_DICT = (Z_NEED_DICT);
inline constexpr auto value_Z_NO_COMPRESSION = (Z_NO_COMPRESSION);
inline constexpr auto value_Z_NO_FLUSH = (Z_NO_FLUSH);
inline constexpr auto value_Z_NULL = (Z_NULL);
inline constexpr auto value_Z_OK = (Z_OK);
inline constexpr auto value_Z_PARTIAL_FLUSH = (Z_PARTIAL_FLUSH);
inline constexpr auto value_Z_RLE = (Z_RLE);
inline constexpr auto value_Z_STREAM_END = (Z_STREAM_END);
inline constexpr auto value_Z_STREAM_ERROR = (Z_STREAM_ERROR);
inline constexpr auto value_Z_SYNC_FLUSH = (Z_SYNC_FLUSH);
inline constexpr auto value_Z_TEXT = (Z_TEXT);
inline constexpr auto value_Z_TREES = (Z_TREES);
using type_Z_U4 = Z_U4;
inline constexpr auto value_Z_UNKNOWN = (Z_UNKNOWN);
inline constexpr auto value_Z_VERSION_ERROR = (Z_VERSION_ERROR);
using type_z_off64_t = z_off64_t;
using type_z_off_t = z_off_t;
}
#undef MAX_MEM_LEVEL
#undef MAX_WBITS
#undef ZLIB_VERNUM
#undef ZLIB_VERSION
#undef ZLIB_VER_MAJOR
#undef ZLIB_VER_MINOR
#undef ZLIB_VER_REVISION
#undef ZLIB_VER_SUBREVISION
#undef Z_ASCII
#undef Z_BEST_COMPRESSION
#undef Z_BEST_SPEED
#undef Z_BINARY
#undef Z_BLOCK
#undef Z_BUF_ERROR
#undef Z_DATA_ERROR
#undef Z_DEFAULT_COMPRESSION
#undef Z_DEFAULT_STRATEGY
#undef Z_DEFLATED
#undef Z_ERRNO
#undef Z_FILTERED
#undef Z_FINISH
#undef Z_FIXED
#undef Z_FULL_FLUSH
#undef Z_HUFFMAN_ONLY
#undef Z_MEM_ERROR
#undef Z_NEED_DICT
#undef Z_NO_COMPRESSION
#undef Z_NO_FLUSH
#undef Z_NULL
#undef Z_OK
#undef Z_PARTIAL_FLUSH
#undef Z_RLE
#undef Z_STREAM_END
#undef Z_STREAM_ERROR
#undef Z_SYNC_FLUSH
#undef Z_TEXT
#undef Z_TREES
#undef Z_U4
#undef Z_UNKNOWN
#undef Z_VERSION_ERROR
#undef z_off64_t
#undef z_off_t

import std;
import mcpplibs.mwrap.zlib.macros;

namespace m = mcpplibs::mwrap::zlib::macros;

static_assert(std::is_same_v<m::Z_U4, header::type_Z_U4>, "Z_U4");
static_assert(std::is_same_v<m::z_off64_t, header::type_z_off64_t>, "z_off64_t");
static_assert(std::is_same_v<m::z_off_t, header::type_z_off_t>, "z_off_t");

template <class A, class B>
bool same(A a, B b)
{
    if constexpr (std::is_convertible_v<A, const char*> && std::is_convertible_v<B, const char*>)
        return std::string_view(a) == std::string_view(b);
    else
        return a == b;
}

int main()
{
    int differ = 0;
    if (!same(m::MAX_MEM_LEVEL, header::value_MAX_MEM_LEVEL)) { std::println("FAIL MAX_MEM_LEVEL"); ++differ; }
    if (!same(m::MAX_WBITS, header::value_MAX_WBITS)) { std::println("FAIL MAX_WBITS"); ++differ; }
    if (!same(m::ZLIB_VERNUM, header::value_ZLIB_VERNUM)) { std::println("FAIL ZLIB_VERNUM"); ++differ; }
    if (!same(m::ZLIB_VERSION, header::value_ZLIB_VERSION)) { std::println("FAIL ZLIB_VERSION"); ++differ; }
    if (!same(m::ZLIB_VER_MAJOR, header::value_ZLIB_VER_MAJOR)) { std::println("FAIL ZLIB_VER_MAJOR"); ++differ; }
    if (!same(m::ZLIB_VER_MINOR, header::value_ZLIB_VER_MINOR)) { std::println("FAIL ZLIB_VER_MINOR"); ++differ; }
    if (!same(m::ZLIB_VER_REVISION, header::value_ZLIB_VER_REVISION)) { std::println("FAIL ZLIB_VER_REVISION"); ++differ; }
    if (!same(m::ZLIB_VER_SUBREVISION, header::value_ZLIB_VER_SUBREVISION)) { std::println("FAIL ZLIB_VER_SUBREVISION"); ++differ; }
    if (!same(m::Z_ASCII, header::value_Z_ASCII)) { std::println("FAIL Z_ASCII"); ++differ; }
    if (!same(m::Z_BEST_COMPRESSION, header::value_Z_BEST_COMPRESSION)) { std::println("FAIL Z_BEST_COMPRESSION"); ++differ; }
    if (!same(m::Z_BEST_SPEED, header::value_Z_BEST_SPEED)) { std::println("FAIL Z_BEST_SPEED"); ++differ; }
    if (!same(m::Z_BINARY, header::value_Z_BINARY)) { std::println("FAIL Z_BINARY"); ++differ; }
    if (!same(m::Z_BLOCK, header::value_Z_BLOCK)) { std::println("FAIL Z_BLOCK"); ++differ; }
    if (!same(m::Z_BUF_ERROR, header::value_Z_BUF_ERROR)) { std::println("FAIL Z_BUF_ERROR"); ++differ; }
    if (!same(m::Z_DATA_ERROR, header::value_Z_DATA_ERROR)) { std::println("FAIL Z_DATA_ERROR"); ++differ; }
    if (!same(m::Z_DEFAULT_COMPRESSION, header::value_Z_DEFAULT_COMPRESSION)) { std::println("FAIL Z_DEFAULT_COMPRESSION"); ++differ; }
    if (!same(m::Z_DEFAULT_STRATEGY, header::value_Z_DEFAULT_STRATEGY)) { std::println("FAIL Z_DEFAULT_STRATEGY"); ++differ; }
    if (!same(m::Z_DEFLATED, header::value_Z_DEFLATED)) { std::println("FAIL Z_DEFLATED"); ++differ; }
    if (!same(m::Z_ERRNO, header::value_Z_ERRNO)) { std::println("FAIL Z_ERRNO"); ++differ; }
    if (!same(m::Z_FILTERED, header::value_Z_FILTERED)) { std::println("FAIL Z_FILTERED"); ++differ; }
    if (!same(m::Z_FINISH, header::value_Z_FINISH)) { std::println("FAIL Z_FINISH"); ++differ; }
    if (!same(m::Z_FIXED, header::value_Z_FIXED)) { std::println("FAIL Z_FIXED"); ++differ; }
    if (!same(m::Z_FULL_FLUSH, header::value_Z_FULL_FLUSH)) { std::println("FAIL Z_FULL_FLUSH"); ++differ; }
    if (!same(m::Z_HUFFMAN_ONLY, header::value_Z_HUFFMAN_ONLY)) { std::println("FAIL Z_HUFFMAN_ONLY"); ++differ; }
    if (!same(m::Z_MEM_ERROR, header::value_Z_MEM_ERROR)) { std::println("FAIL Z_MEM_ERROR"); ++differ; }
    if (!same(m::Z_NEED_DICT, header::value_Z_NEED_DICT)) { std::println("FAIL Z_NEED_DICT"); ++differ; }
    if (!same(m::Z_NO_COMPRESSION, header::value_Z_NO_COMPRESSION)) { std::println("FAIL Z_NO_COMPRESSION"); ++differ; }
    if (!same(m::Z_NO_FLUSH, header::value_Z_NO_FLUSH)) { std::println("FAIL Z_NO_FLUSH"); ++differ; }
    if (!same(m::Z_NULL, header::value_Z_NULL)) { std::println("FAIL Z_NULL"); ++differ; }
    if (!same(m::Z_OK, header::value_Z_OK)) { std::println("FAIL Z_OK"); ++differ; }
    if (!same(m::Z_PARTIAL_FLUSH, header::value_Z_PARTIAL_FLUSH)) { std::println("FAIL Z_PARTIAL_FLUSH"); ++differ; }
    if (!same(m::Z_RLE, header::value_Z_RLE)) { std::println("FAIL Z_RLE"); ++differ; }
    if (!same(m::Z_STREAM_END, header::value_Z_STREAM_END)) { std::println("FAIL Z_STREAM_END"); ++differ; }
    if (!same(m::Z_STREAM_ERROR, header::value_Z_STREAM_ERROR)) { std::println("FAIL Z_STREAM_ERROR"); ++differ; }
    if (!same(m::Z_SYNC_FLUSH, header::value_Z_SYNC_FLUSH)) { std::println("FAIL Z_SYNC_FLUSH"); ++differ; }
    if (!same(m::Z_TEXT, header::value_Z_TEXT)) { std::println("FAIL Z_TEXT"); ++differ; }
    if (!same(m::Z_TREES, header::value_Z_TREES)) { std::println("FAIL Z_TREES"); ++differ; }
    if (!same(m::Z_UNKNOWN, header::value_Z_UNKNOWN)) { std::println("FAIL Z_UNKNOWN"); ++differ; }
    if (!same(m::Z_VERSION_ERROR, header::value_Z_VERSION_ERROR)) { std::println("FAIL Z_VERSION_ERROR"); ++differ; }
    std::println("39 constants and 3 types compared, {} differ", differ);
    return differ != 0;
}
