# Usage and API

`mcpplibs.mwrap.zlib` 1.3.2 exports zlib's public API, upstream's names
unchanged. This page lists what each module holds and the places where a module
and a header differ. [tools/generate.py](../tools/generate.py) writes the lists
from the headers, and CI checks them on every target.

## Modules

| Module | Holds |
|---|---|
| `mcpplibs.mwrap.zlib` | the functions of `<zlib.h>`: one-call `compress`, `compress2`, `uncompress`, `uncompress2` and their `_z` forms; streams (`deflate*`, `inflate*`, `inflateBack*`); gzip files (`gzopen`, `gzdopen`, `gzread`, `gzwrite`, `gzprintf`, `gzgets`, `gzseek` …); checksums (`adler32*`, `crc32*`, `get_crc_table`); `zlibVersion`, `zlibCompileFlags`, `zError`. The types `z_stream`, `gz_header`, `gzFile`, `alloc_func`, `free_func`, `in_func`, `out_func`, `Bytef`, `uInt`, `uLong`, `uLongf`, `voidpf`, `z_size_t`, `z_crc_t` and the others of `<zconf.h>`. Re-exports the macros module |
| `mcpplibs.mwrap.zlib.macros` | in `mcpplibs::mwrap::zlib::macros`: the flush values (`Z_NO_FLUSH` … `Z_TREES`), the return codes (`Z_OK` … `Z_VERSION_ERROR`), the levels and strategies (`Z_BEST_SPEED`, `Z_DEFAULT_COMPRESSION`, `Z_FILTERED`, `Z_RLE` …), the data types (`Z_BINARY`, `Z_TEXT`), `Z_DEFLATED`, `Z_NULL`, `MAX_WBITS`, `MAX_MEM_LEVEL`, the version (`ZLIB_VERSION`, `ZLIB_VERNUM`, `ZLIB_VER_*`); the type aliases `z_off_t`, `z_off64_t`, `Z_U4` |

The 64-bit offset functions (`gzopen64`, `gzseek64`, `gztell64`, `gzoffset64`,
`adler32_combine64`, `crc32_combine64`, `crc32_combine_gen64`) are exported
where `<zconf.h>` declares them: Linux, where the C library provides 64-bit
offsets. `gzopen_w` is exported on Windows.

## What a module cannot export, and what stands in for it

- **Macros with arguments.** `deflateInit(strm, level)`, `deflateInit2(…)`,
  `inflateInit(strm)`, `inflateInit2(strm, windowBits)` and
  `inflateBackInit(strm, windowBits, window)` call the exported `*_` functions
  with `ZLIB_VERSION` and `sizeof(z_stream)`, which let the library check that
  the caller was compiled against the same zlib. `gzgetc(file)` reads from the
  file's buffer and calls the function `gzgetc` when it is empty;
  `zlib_version` is `zlibVersion()`. All are upstream's definitions in
  `<mwrap/zlib/macros.hpp>`, with `ZLIB_VERSION` read from the macros module.
  Include the header before the imports. Calling `deflateInit_` with
  `mcpplibs::mwrap::zlib::macros::ZLIB_VERSION` directly is equivalent.
- **Constants and types.** Each object-like macro whose expansion is a constant
  expression is an `inline constexpr` of the same name and value; each whose
  expansion is a type is an alias. tests/macros.cpp compares every one with its
  macro.
- **Declaration syntax.** `ZEXTERN`, `ZEXPORT`, `ZEXPORTVA`, `FAR`, `OF`,
  `z_const` and the configuration that `<zconf.h>` derives for itself (`STDC`,
  `Z_HAVE_UNISTD_H`, `Z_HAVE_STDARG_H`, `Z_LFS64`, `Z_LARGE64`, `Z_WANT64`) are
  not offered: they spell the declarations, and their values differ by target.
  tools/surface.toml lists them.

## A header beside the module

`#include <zlib.h>` and `import mcpplibs.mwrap.zlib;` may appear in one unit:
they declare the same entities. A macro expands even inside a qualified name,
so `mcpplibs::mwrap::zlib::macros::Z_OK` written after the header is
`...::macros::0`. In such a unit use the header's macros, or read their values
under other names and `#undef` the macros before naming the constants
(tests/macros.cpp does this). Include `<zlib.h>` before
`<mwrap/zlib/macros.hpp>`, if both: the upstream header defines the same macros
with its own constants and would redefine them.

## Linking

The package depends on `compat.zlib` 1.3.2, which builds zlib from the
release sources with the target's toolchain. A program that imports the module
links that library; it does not look for a system zlib.
