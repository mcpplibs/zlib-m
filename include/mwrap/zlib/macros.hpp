// <mwrap/zlib/macros.hpp> --- the macros of the headers that are neither a constant
// nor a type: they take arguments, or call a function. A named module cannot export a
// macro: include this header before `import mcpplibs.mwrap.zlib;`. Each definition is
// upstream's (zlib 1.3.2, zlib license), made only where the upstream header has
// not defined it, with the constants it names read from mcpplibs::mwrap::zlib::macros.
// The upstream header included after this one redefines these macros.
// Written by tools/generate.py.
#ifndef MWRAP_ZLIB_MACROS_HPP
#define MWRAP_ZLIB_MACROS_HPP

#ifndef deflateInit
#define deflateInit(strm,level) deflateInit_((strm), (level), ::mcpplibs::mwrap::zlib::macros::ZLIB_VERSION, (int)sizeof(z_stream))
#endif

#ifndef deflateInit2
#define deflateInit2(strm,level,method,windowBits,memLevel,strategy) deflateInit2_((strm),(level),(method),(windowBits),(memLevel), (strategy), ::mcpplibs::mwrap::zlib::macros::ZLIB_VERSION, (int)sizeof(z_stream))
#endif

#ifndef gzgetc
#define gzgetc(g) ((g)->have ? ((g)->have--, (g)->pos++, *((g)->next)++) : (gzgetc)(g))
#endif

#ifndef inflateBackInit
#define inflateBackInit(strm,windowBits,window) inflateBackInit_((strm), (windowBits), (window), ::mcpplibs::mwrap::zlib::macros::ZLIB_VERSION, (int)sizeof(z_stream))
#endif

#ifndef inflateInit
#define inflateInit(strm) inflateInit_((strm), ::mcpplibs::mwrap::zlib::macros::ZLIB_VERSION, (int)sizeof(z_stream))
#endif

#ifndef inflateInit2
#define inflateInit2(strm,windowBits) inflateInit2_((strm), (windowBits), ::mcpplibs::mwrap::zlib::macros::ZLIB_VERSION, (int)sizeof(z_stream))
#endif

#ifndef zlib_version
#define zlib_version zlibVersion()
#endif

#endif  // MWRAP_ZLIB_MACROS_HPP
