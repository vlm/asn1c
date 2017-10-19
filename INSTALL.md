
## Compiling From Sources

### Configure

See [REQUIREMENTS.md](REQUIREMENTS.md) for the complete list of dependencies.

Configure with the default settings:

    test -f configure || autoreconf -iv
    ./configure
    make

Configure with non-standard settings:

asn1c-specific ./configure options include:

  Option                 | Description
------------------------ | ---------------------------------------------------
  --enable-ASN_DEBUG     | produce debug log during `make check` testing
  --enable-code-coverage | whether to enable code coverage support
  --enable-Werror        | abort compilation after any C compiler warning
  --enable-test-Werror   | abort compiling tests after any C compiler warning
  --enable-test-32bit    | enable tests for 32-bit compatibility
  --disable-test-ubsan   | disable Undefined Behavior Sanitizer for tests
  --disable-test-asan    | disable Address Sanitizer for tests
  --enable-test-fuzzer   | enable LLVM LibFuzzer for randomized testing

invoke `./configure --help` for details.

### Build

Build the libraries and the compiler:

    make

Ensure asn1c is still behaving well after compiling on your platform:

    make check

### Install

Install the compiler into a standard location:

    make install
    # Use ./configure --prefix to override install location.

Display the `asn1c` manual page:

    man asn1c

## Quick Usage Guide

For a usage guide and more information please refer to:

 * the [README.md](README.md) file
 * the asn1c manual page `man asn1c`
 * the included quick start PDF [doc/asn1c-quick.pdf](doc/asn1c-quick.pdf)
 * the comprehensive usage documentation [doc/asn1c-usage.pdf](doc/asn1c-usage.pdf)

In case of any difficulties with installing the compiler, consider using
the Online ASN.1 Compiler at http://lionet.info/asn1c.

-- 
Lev Walkin
vlm@lionet.info
