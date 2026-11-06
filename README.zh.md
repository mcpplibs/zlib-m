# zlib

> zlib——deflate 与 gzip 压缩库，以 C++23 模块提供。

[English](README.md) · **简体中文** · [上游](https://github.com/madler/zlib) · [发布](https://github.com/mcpplibs/zlib-m/releases) · [mcpp](https://github.com/mcpp-community/mcpp) · [索引](https://github.com/mcpplibs/mcpp-index)

[![C++23](https://img.shields.io/badge/C%2B%2B-23-blue.svg)](https://en.cppreference.com/w/cpp/23)
[![License](https://img.shields.io/badge/license-Apache--2.0-blue.svg)](LICENSE)
[![mcpp-community](https://img.shields.io/badge/mcpp--community-mwrap-blue)](https://github.com/mcpp-community)
[![CI](https://github.com/mcpplibs/zlib-m/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/mcpplibs/zlib-m/actions/workflows/ci.yml)

上游 API 不变：`compress2`、`deflate`、`inflate`、`gzopen`、`crc32`、`z_stream` 等函数与类型都是 `<zlib.h>` 中的上游实体，
位于上游声明它们的全局命名空间。库本身是 `compat.zlib` 1.3.2。常量宏与类型宏映射为 C++ 常量与别名，带参数的宏保留在一个
头文件中。每次 CI 都在同一份库上运行上游自己的 `test/example.c`。

## 模块

- `import mcpplibs.mwrap.zlib;`：`<zlib.h>` 与 `<zconf.h>` 的函数与类型，并重新导出宏模块
- `import mcpplibs.mwrap.zlib.macros;`：`Z_OK`、`Z_FINISH`、`Z_BEST_COMPRESSION`、`MAX_WBITS`、`ZLIB_VERSION`、`z_off_t` 等，位于 `mcpplibs::mwrap::zlib::macros`
- `#include <mwrap/zlib/macros.hpp>`：`deflateInit`、`inflateInit`、`deflateInit2`、`inflateInit2`、`inflateBackInit`、`gzgetc`、`zlib_version`

> 更多模块 API -> [用法与 API](docs/usage.md)

## 快速开始

```sh
mcpp new compress --template mcpplibs.mwrap.zlib@1.3.2
cd compress
mcpp run
```

默认模板一次调用压缩一段文本，再经 inflate 流还原，打印两个大小与 CRC-32。

```toml
[dependencies]
"mcpplibs.mwrap.zlib" = "1.3.2"
```

```cpp
#include <mwrap/zlib/macros.hpp>      // deflateInit、inflateInit 等
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

## 宏

命名模块不能导出宏。zlib 的宏分三组：

- **常量与类型**（`Z_OK`、`Z_NO_FLUSH`、`Z_DEFLATED`、`MAX_MEM_LEVEL`、`ZLIB_VERNUM`、`z_off_t`、`z_off64_t` 等）映射为
  `mcpplibs::mwrap::zlib::macros` 中同名的 `inline constexpr` 常量与类型别名。
- **带参数的宏**（`deflateInit(strm, level)` 等 `*Init` 形式，它们把 `ZLIB_VERSION` 与 `sizeof(z_stream)` 传给库；以及
  `gzgetc`）是上游的定义，位于 `<mwrap/zlib/macros.hpp>`，在 import 之前包含。
- **声明语法与配置**（`ZEXTERN`、`ZEXPORT`、`OF`、`Z_LARGE64` 等）描述 `<zconf.h>` 在各目标上怎样书写声明，其效果已经
  体现在导出中。

宏在限定名中也会展开。同时包含 `<zlib.h>` 的翻译单元经头文件的宏读取常量（[docs/usage.md](docs/usage.md)）。

## 构建与测试

Linux、macOS、Windows 的 CI 用 GCC 与 LLVM 构建模块并运行测试：一次调用的往返、分段输入的 raw deflate 流及其还原、
`123456789` 的 CRC-32 与 Adler-32 公布值、经 `gzgetc` 读回的 gzip 文件、每个常量与类型同其宏相等、头文件混用。CI 还运行：

- 导出审计（[tools/generate.py](tools/generate.py) `--check`）：按 clang 读到的头文件重新生成模块、宏映射、宏头文件与
  常量测试并逐字节比较；在 macOS 与 Windows 上检查头文件在该平台声明的每个名字都已导出；
- 在同一份库上运行上游的 `test/example.c`（[tools/run_conformance.py](tools/run_conformance.py)）。

另一个作业把默认模板当作已安装的包生成项目并运行。

## 许可

包装部分为 [Apache-2.0](LICENSE)，作者 mcpp-community（[NOTICE](NOTICE)）。zlib 仍遵循 zlib 许可
（[upstream/zlib/LICENSE](upstream/zlib/LICENSE)、[README](upstream/zlib/README)）。
