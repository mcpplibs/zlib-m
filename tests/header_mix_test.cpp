// The header and the module in one translation unit: the same entities, so a
// stream initialised through one spelling is ended through the other.
#include <zlib.h>
import std;
import mcpplibs.mwrap.zlib;

int main()
{
    z_stream s{};
    const bool init = ::deflateInit(&s, Z_BEST_SPEED) == Z_OK;  // the header's macro and constant
    const bool end = deflateEnd(&s) == Z_OK;                     // the module's function
    const bool same = &::crc32 == &crc32;
    std::println("{}", init && end && same ? "header and module agree" : "FAIL");
    return init && end && same ? 0 : 1;
}
