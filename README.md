# zlib

> zlib, the deflate and gzip compression library, through C++23 modules.

**English** · [简体中文](README.zh.md) · [Upstream](https://github.com/madler/zlib) · [Releases](https://github.com/mcpplibs/zlib-m/releases) · [mcpp](https://github.com/mcpp-community/mcpp) · [Index](https://github.com/mcpplibs/mcpp-index)

[![C++23](https://img.shields.io/badge/C%2B%2B-23-blue.svg)](https://en.cppreference.com/w/cpp/23)
[![License](https://img.shields.io/badge/license-Apache--2.0-blue.svg)](LICENSE)
[![mcpp-community](https://img.shields.io/badge/mcpp--community-mwrap-blue)](https://github.com/mcpp-community)
[![CI](https://github.com/mcpplibs/zlib-m/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/mcpplibs/zlib-m/actions/workflows/ci.yml)

The upstream API is unchanged. `compress2`, `deflate`, `inflate`, `gzopen`,
`crc32`, `z_stream` and the other functions and types are the upstream
entities of `<zlib.h>`, in the global namespace where upstream declares them.
The library is `compat.zlib` 1.3.2. The constant and type macros are C++
constants and aliases. The macros that take arguments stay macros in one
header. Upstream's own `test/example.c` passes on every CI run over the same
library.

## Modules

- `import mcpplibs.mwrap.zlib;`: the functions and types of `<zlib.h>` and `<zconf.h>`, re-exporting the macros module
- `import mcpplibs.mwrap.zlib.macros;`: `Z_OK`, `Z_FINISH`, `Z_BEST_COMPRESSION`, `MAX_WBITS`, `ZLIB_VERSION`, `z_off_t` … in `mcpplibs::mwrap::zlib::macros`
- `#include <mwrap/zlib/macros.hpp>`: `deflateInit`, `inflateInit`, `deflateInit2`, `inflateInit2`, `inflateBackInit`, `gzgetc`, `zlib_version`

> More Modules API -> [Usage and API](docs/usage.md)

## Getting started

```sh
mcpp new compress --template mcpplibs.mwrap.zlib@1.3.2
cd compress
mcpp run
```

The default template compresses a text in one call, restores it through an
inflate stream, and prints both sizes and the CRC-32.

```toml
[dependencies]
"mcpplibs.mwrap.zlib" = "1.3.2"
```

```cpp
#include <mwrap/zlib/macros.hpp>      // deflateInit, inflateInit …
import std;
import mcpplibs.mwrap.zlib;

namespace z = mcpplibs::mwrap::zlib::macros;

int main() {
    std::string text(1000, 'a');
    std::vector<Bytef> out(compressBound(text.size()));
    uLongf size = out.size();
    compress2(out.data(), &size, reinterpret_cast<const Bytef*>(text.data()), text.size(), z::Z_BEST_COMPRESSION);
    std::println("{} -> {} bytes", text.size(), size);
}
```

## Macros

A named module cannot export a macro. zlib's macros fall into three groups:

- **Constants and types** (`Z_OK`, `Z_NO_FLUSH`, `Z_DEFLATED`, `MAX_MEM_LEVEL`,
  `ZLIB_VERNUM`, `z_off_t`, `z_off64_t` …) are `inline constexpr` constants and
  type aliases of the same names in `mcpplibs::mwrap::zlib::macros`.
- **Macros with arguments** (`deflateInit(strm, level)` and the other `*Init`
  forms, which pass `ZLIB_VERSION` and `sizeof(z_stream)` to the library, and
  `gzgetc`) are upstream's definitions in `<mwrap/zlib/macros.hpp>`, included
  before the imports.
- **Declaration syntax and configuration** (`ZEXTERN`, `ZEXPORT`, `OF`,
  `Z_LARGE64` …) describe how `<zconf.h>` writes the declarations on each
  target; the exports carry their effect.

A macro expands even in a qualified name. A unit that includes `<zlib.h>`
beside the module reads the constants through the header's macros
([docs/usage.md](docs/usage.md)).

## Build and testing

Linux, macOS and Windows CI build the modules with GCC and LLVM and run the
tests: a one-call round trip, a raw deflate stream fed in pieces and inflated,
the published CRC-32 and Adler-32 of `123456789`, a gzip file written and read
back through `gzgetc`, every constant and type against its macro, and header
mixing. CI also runs:

- the export audit ([tools/generate.py](tools/generate.py) `--check`): the
  module, the macro mapping, the macro header and the constant test are
  regenerated from the headers as clang reads them and compared, and on macOS
  and Windows every name the headers declare there is exported;
- upstream's `test/example.c` over the same library
  ([tools/run_conformance.py](tools/run_conformance.py)).

A separate job scaffolds the default template as an installed package and runs
it.

## License

[Apache-2.0](LICENSE) for the wrapper, by mcpp-community ([NOTICE](NOTICE)).
zlib remains under the zlib license
([upstream/zlib/LICENSE](upstream/zlib/LICENSE),
[README](upstream/zlib/README)).
