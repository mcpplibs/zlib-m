// mcpplibs.mwrap.zlib.macros --- the macros of the headers that are a constant or a
// type, under their original names in mcpplibs::mwrap::zlib::macros, each equal to
// the macro where the module is built (a named module cannot export a macro). The
// other macros are in <mwrap/zlib/macros.hpp>. Written by tools/generate.py.
module;
#include <zlib.h>

// The values, taken under other names while the macros are defined.
namespace mwrap_zlib_capture {
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

export module mcpplibs.mwrap.zlib.macros;

export namespace mcpplibs::mwrap::zlib::macros {
inline constexpr auto MAX_MEM_LEVEL = mwrap_zlib_capture::value_MAX_MEM_LEVEL;
inline constexpr auto MAX_WBITS = mwrap_zlib_capture::value_MAX_WBITS;
inline constexpr auto ZLIB_VERNUM = mwrap_zlib_capture::value_ZLIB_VERNUM;
inline constexpr auto ZLIB_VERSION = mwrap_zlib_capture::value_ZLIB_VERSION;
inline constexpr auto ZLIB_VER_MAJOR = mwrap_zlib_capture::value_ZLIB_VER_MAJOR;
inline constexpr auto ZLIB_VER_MINOR = mwrap_zlib_capture::value_ZLIB_VER_MINOR;
inline constexpr auto ZLIB_VER_REVISION = mwrap_zlib_capture::value_ZLIB_VER_REVISION;
inline constexpr auto ZLIB_VER_SUBREVISION = mwrap_zlib_capture::value_ZLIB_VER_SUBREVISION;
inline constexpr auto Z_ASCII = mwrap_zlib_capture::value_Z_ASCII;
inline constexpr auto Z_BEST_COMPRESSION = mwrap_zlib_capture::value_Z_BEST_COMPRESSION;
inline constexpr auto Z_BEST_SPEED = mwrap_zlib_capture::value_Z_BEST_SPEED;
inline constexpr auto Z_BINARY = mwrap_zlib_capture::value_Z_BINARY;
inline constexpr auto Z_BLOCK = mwrap_zlib_capture::value_Z_BLOCK;
inline constexpr auto Z_BUF_ERROR = mwrap_zlib_capture::value_Z_BUF_ERROR;
inline constexpr auto Z_DATA_ERROR = mwrap_zlib_capture::value_Z_DATA_ERROR;
inline constexpr auto Z_DEFAULT_COMPRESSION = mwrap_zlib_capture::value_Z_DEFAULT_COMPRESSION;
inline constexpr auto Z_DEFAULT_STRATEGY = mwrap_zlib_capture::value_Z_DEFAULT_STRATEGY;
inline constexpr auto Z_DEFLATED = mwrap_zlib_capture::value_Z_DEFLATED;
inline constexpr auto Z_ERRNO = mwrap_zlib_capture::value_Z_ERRNO;
inline constexpr auto Z_FILTERED = mwrap_zlib_capture::value_Z_FILTERED;
inline constexpr auto Z_FINISH = mwrap_zlib_capture::value_Z_FINISH;
inline constexpr auto Z_FIXED = mwrap_zlib_capture::value_Z_FIXED;
inline constexpr auto Z_FULL_FLUSH = mwrap_zlib_capture::value_Z_FULL_FLUSH;
inline constexpr auto Z_HUFFMAN_ONLY = mwrap_zlib_capture::value_Z_HUFFMAN_ONLY;
inline constexpr auto Z_MEM_ERROR = mwrap_zlib_capture::value_Z_MEM_ERROR;
inline constexpr auto Z_NEED_DICT = mwrap_zlib_capture::value_Z_NEED_DICT;
inline constexpr auto Z_NO_COMPRESSION = mwrap_zlib_capture::value_Z_NO_COMPRESSION;
inline constexpr auto Z_NO_FLUSH = mwrap_zlib_capture::value_Z_NO_FLUSH;
inline constexpr auto Z_NULL = mwrap_zlib_capture::value_Z_NULL;
inline constexpr auto Z_OK = mwrap_zlib_capture::value_Z_OK;
inline constexpr auto Z_PARTIAL_FLUSH = mwrap_zlib_capture::value_Z_PARTIAL_FLUSH;
inline constexpr auto Z_RLE = mwrap_zlib_capture::value_Z_RLE;
inline constexpr auto Z_STREAM_END = mwrap_zlib_capture::value_Z_STREAM_END;
inline constexpr auto Z_STREAM_ERROR = mwrap_zlib_capture::value_Z_STREAM_ERROR;
inline constexpr auto Z_SYNC_FLUSH = mwrap_zlib_capture::value_Z_SYNC_FLUSH;
inline constexpr auto Z_TEXT = mwrap_zlib_capture::value_Z_TEXT;
inline constexpr auto Z_TREES = mwrap_zlib_capture::value_Z_TREES;
using Z_U4 = mwrap_zlib_capture::type_Z_U4;
inline constexpr auto Z_UNKNOWN = mwrap_zlib_capture::value_Z_UNKNOWN;
inline constexpr auto Z_VERSION_ERROR = mwrap_zlib_capture::value_Z_VERSION_ERROR;
using z_off64_t = mwrap_zlib_capture::type_z_off64_t;
using z_off_t = mwrap_zlib_capture::type_z_off_t;
}
