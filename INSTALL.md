
## Compiling From Sources

### Requirements

For Ubuntu 16.04

      apt install autoconf libtool-bin

For Fedora 24 and Centos 7.2

      yum install autoconf libtool automake make

### Configure


Configure with the default settings:

    test -f configure || autoreconf -iv
    ./configure

Configure with non-standard settings:

asn1c specific ./configure options include:

    --enable-Werror
    --enable-ASN_DEBUG

invoke `./configure --help` for details.

### Build

Build the libraries and the compiler:

    make

Ensure asn1c is still behaving well after compiling on your platform:

    make check

### Install

Install the compiler into a standard location:

    make install
    # Use ./configure --prefix /new/path to override install location.

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
