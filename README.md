# About

ASN.1 to C compiler takes the ASN.1 module files (example) and generates
the C++ compatible C source code. That code can be used to serialize
the native C structures into compact and unambiguous BER/XER/PER-based
data files, and deserialize the files back.

Various ASN.1 based formats are widely used in the industry,
such as to encode the X.509 certificates employed in the HTTPS handshake,
to exchange control data between mobile phones and cellular networks,
to car-to-car communication in intelligent transportation networks.

The ASN.1 standard is large and complex and no open source compiler supports
it in its entirety. The asn1c is arguably the most evolved open source
ASN.1 compiler.

# Build and Install

If you haven't installed the asn1c yet, read the [INSTALL.md](INSTALL.md) file
for a short installation guide.

[![Build Status](https://travis-ci.org/vlm/asn1c.svg?branch=master)](https://travis-ci.org/vlm/asn1c)

# Documentation

For the list of asn1c command line options, see `asn1c -h` or `man asn1c`.

The comprehensive documentation on this compiler is in [doc/asn1c-usage.pdf](doc/asn1c-usage.pdf).

Please also read the [FAQ](FAQ) file.

An excellent book on ASN.1 is written by Olivier Dubuisson:
"ASN.1 Communication between heterogeneous systems", ISBN:0-12-6333361-0.

# Quick start

(also check out [doc/asn1c-quick.pdf](doc/asn1c-quick.pdf))

After installing the compiler (see [INSTALL.md](INSTALL.md)), you may use
the asn1c command to compile the ASN.1 specification:

    asn1c <module.asn1>                         # Compile module

If several specifications contain interdependencies, all of them must be
specified at the same time:

    asn1c <module1.asn1> <module2.asn1> ...     # Compile interdependent modules

The asn1c source tarball contains the [examples/](examples/) directory
with several ASN.1 modules and a [script](examples/crfc2asn1.pl)
to extract the ASN.1 modules from RFC documents.
Refer to the [examples/README](examples/README) file in that directory.

To compile the X.509 PKI module:

    ./asn1c/asn1c -P ./examples/rfc3280-*.asn1  # Compile-n-print

In this example, the **-P** option is to print the compiled text on the
standard output. The default behavior is that asn1c compiler creates
multiple .c and .h files for every ASN.1 type found inside the specified
ASN.1 modules.

The compiler's **-E** and **-EF** options are used for testing the parser and
the semantic fixer, respectively. These options will instruct the compiler
to dump out the parsed (and fixed) ASN.1 specification as it was
"understood" by the compiler. It might be useful for checking
whether a particular syntactic construction is properly supported
by the compiler.

    asn1c -EF <module-to-test.asn1>             # Check semantic validity

# Model of operation

The asn1c compiler works by processing the ASN.1 module specifications
in several stages:

1. During the first stage, the ASN.1 file is parsed.
   (Parsing produces an ASN.1 syntax tree for the subsequent levels)
2. During the second stage, the syntax tree is "fixed".
   (Fixing is a process of checking the tree for semantic errors,
   accompanied by the tree transformation into the canonical form)
3. During the third stage, the syntax tree is compiled into the target language.

There are several command-line options reserved for printing the results
after each stage of operation:

    <parser> => print                                       (-E)
    <parser> => <fixer> => print                            (-E -F)
    <parser> => <fixer> => <compiler> => print              (-P)
    <parser> => <fixer> => <compiler> => save-compiled      [default]


-- 
Lev Walkin
vlm@lionet.info
