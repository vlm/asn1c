
## To compile asn1c compiler itself

A 64-bit build system is strongly recommended for asn1c operation.

A working C99 compiler is required to compile asn1c itself,
such as gcc-4.x or clang-3.4. The asn1c compiler produces C90-compatible code,
which is also upward compatible with C++.

### Packages

This notation specifies a minimum required package version (-ver)
or an exact version (=ver). For example, bison=2.x requires the 2.x branch
of bison, not 3.x.

 * automake-1.15
 * libtool
 * bison=2.x
 * flex

## To compile asn1c-generated code

C:
As a minimum, a compiler supporting the C90. Pretty much any modern C compiler
will do, but gcc or clang is recommended. Note that MSVC++ is not a C compiler.

C++:
A C++11 compliant compiler is recommended.

