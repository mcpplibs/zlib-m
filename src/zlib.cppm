// mcpplibs.mwrap.zlib --- zlib 1.3.2 as a C++ module. Every exported name is
// the upstream entity of the headers below, unchanged, in the global namespace where
// upstream declares it; the root also re-exports the macro mapping. The implementation
// is compat.zlib 1.3.2. Written by tools/generate.py from the headers.
module;
#include <zlib.h>

export module mcpplibs.mwrap.zlib;

export import mcpplibs.mwrap.zlib.macros;

export {
using ::Byte;
using ::Bytef;
using ::adler32;
using ::adler32_combine;
using ::adler32_z;
using ::alloc_func;
using ::charf;
using ::compress;
using ::compress2;
using ::compress2_z;
using ::compressBound;
using ::compressBound_z;
using ::compress_z;
using ::crc32;
using ::crc32_combine;
using ::crc32_combine_gen;
using ::crc32_combine_op;
using ::crc32_z;
using ::deflate;
using ::deflateBound;
using ::deflateBound_z;
using ::deflateCopy;
using ::deflateEnd;
using ::deflateGetDictionary;
using ::deflateInit2_;
using ::deflateInit_;
using ::deflateParams;
using ::deflatePending;
using ::deflatePrime;
using ::deflateReset;
using ::deflateResetKeep;
using ::deflateSetDictionary;
using ::deflateSetHeader;
using ::deflateTune;
using ::deflateUsed;
using ::free_func;
using ::get_crc_table;
using ::gzFile;
using ::gzFile_s;
using ::gz_header;
using ::gz_header_s;
using ::gz_headerp;
using ::gzbuffer;
using ::gzclearerr;
using ::gzclose;
using ::gzclose_r;
using ::gzclose_w;
using ::gzdirect;
using ::gzdopen;
using ::gzeof;
using ::gzerror;
using ::gzflush;
using ::gzfread;
using ::gzfwrite;
using ::gzgetc;
using ::gzgetc_;
using ::gzgets;
using ::gzoffset;
using ::gzopen;
using ::gzprintf;
using ::gzputc;
using ::gzputs;
using ::gzread;
using ::gzrewind;
using ::gzseek;
using ::gzsetparams;
using ::gztell;
using ::gzungetc;
using ::gzvprintf;
using ::gzwrite;
using ::in_func;
using ::inflate;
using ::inflateBack;
using ::inflateBackEnd;
using ::inflateBackInit_;
using ::inflateCodesUsed;
using ::inflateCopy;
using ::inflateEnd;
using ::inflateGetDictionary;
using ::inflateGetHeader;
using ::inflateInit2_;
using ::inflateInit_;
using ::inflateMark;
using ::inflatePrime;
using ::inflateReset;
using ::inflateReset2;
using ::inflateResetKeep;
using ::inflateSetDictionary;
using ::inflateSync;
using ::inflateSyncPoint;
using ::inflateUndermine;
using ::inflateValidate;
using ::internal_state;
using ::intf;
using ::out_func;
using ::uInt;
using ::uIntf;
using ::uLong;
using ::uLongf;
using ::uncompress;
using ::uncompress2;
using ::uncompress2_z;
using ::uncompress_z;
using ::voidp;
using ::voidpc;
using ::voidpf;
using ::zError;
using ::z_crc_t;
using ::z_size_t;
using ::z_stream;
using ::z_stream_s;
using ::z_streamp;
using ::zlibCompileFlags;
using ::zlibVersion;
}

#if defined(Z_LARGE64) || defined(Z_WANT64)
export {
using ::adler32_combine64;
using ::crc32_combine64;
using ::crc32_combine_gen64;
using ::gzoffset64;
using ::gzopen64;
using ::gzseek64;
using ::gztell64;
}
#endif

#if defined(_WIN32)
export {
using ::gzopen_w;
}
#endif
