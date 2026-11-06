#!/usr/bin/env python3
"""Run zlib's own test/example.c (of the release) against compat.zlib 1.3.2,
the library this wrapper exports.

The release tarball is downloaded once into target/upstream and checked
against upstream/documents.json. The test is copied unchanged into
target/conformance/test, and a project there builds it as C over compat.zlib
(a C program includes <zlib.h>; the module's own tests are tests/*.cpp). It
compresses and inflates in every mode the library offers --- one call, small
buffers, large buffers, flushes, a preset dictionary --- writes and reads a
gzip file, and must end with status 0.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile
import urllib.request

MANIFEST = '''[package]
name        = "zlib-conformance"
version     = "1.3.2"
description = "zlib 1.3.2's test/example.c over compat.zlib (tools/run_conformance.py)"

[targets.example]
kind = "bin"
main = "test/example.c"

[build]
c_standard = "c11"
sources    = []

[dependencies]
compat.zlib = "1.3.2"
'''


def fetch(root: Path) -> Path:
    pins = json.loads((root / 'upstream/documents.json').read_text(encoding='utf-8'))
    cache = root / 'target/upstream'
    cache.mkdir(parents=True, exist_ok=True)
    archive = cache / 'zlib-release.tar.gz'
    if not archive.exists() or hashlib.sha256(archive.read_bytes()).hexdigest() != pins['upstream_sha256']:
        print('+ fetch', pins['upstream'], flush=True)
        with urllib.request.urlopen(pins['upstream'], timeout=120) as response:
            archive.write_bytes(response.read())
    digest = hashlib.sha256(archive.read_bytes()).hexdigest()
    if digest != pins['upstream_sha256']:
        sys.exit(f'upstream archive checksum {digest} != {pins["upstream_sha256"]}')
    with tarfile.open(archive) as tar:
        top = tar.getmembers()[0].name.split('/')[0]
        if not (cache / top).exists():
            tar.extractall(cache, filter='data')
    return cache / top


def run(command, cwd):
    print('+', ' '.join(map(str, command)), flush=True)
    return subprocess.run(command, cwd=cwd, check=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--mcpp', default='mcpp')
    parser.add_argument('--toolchain')
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    upstream = fetch(root)
    work = root / 'target/conformance'
    shutil.rmtree(work, ignore_errors=True)
    (work / 'test').mkdir(parents=True)
    shutil.copyfile(upstream / 'test/example.c', work / 'test/example.c')
    (work / 'mcpp.toml').write_text(MANIFEST, encoding='utf-8')
    build = [args.mcpp, 'build', '--release']
    if args.toolchain:
        build += ['--toolchain', args.toolchain]
    run(build, work)
    example = [p for p in (work / 'target').rglob('example*') if p.is_file() and p.suffix in ('', '.exe')]
    if not example:
        sys.exit('example did not build')
    # example writes and reads foo.gz in its working directory.
    run([example[0], str(work / 'foo.gz')], work)
    print('zlib 1.3.2: test/example.c passed over compat.zlib', flush=True)


if __name__ == '__main__':
    main()
