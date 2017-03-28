% enber(1) unber(1) counterpart
% Lev Walkin <vlm@lionet.info>
% 2016-01-23

# NAME

enber -- Convert the unber XML output back into BER

# SYNOPSIS

enber [**-n**] [**-**] [*input-filenames*...]

# DESCRIPTION

enber converts the XML-formatted files produced by `unber`(1) back into the BER format.
A single dash denotes the standard input.

# OPTIONS

-n
:   Disable input validation.
By default, enber performs some basic validity checks
against XML input.

# EXAMPLES

Decode a BER sequence and immediately encode it back

> unber **-p** *filename.ber* | enber **-** > *reconstructed.ber*

# FOOTNOTES

This program does not attempt to perform full-fledged XML parsing.
It is merely compatible with `unber`(1)'s output.
In particular, the XML style comments are not supported.
A hash "**#**" or two dashes "**--**" following a whitespace is treated as a beginning of a comment line, which is ignored completely.
Empty lines are ignored as well.

The following example `enber`(1) input demonstrates the use of comments:

| \<C O="0" T="[1]" TL="2" V="2">
|     \<I O="2" T="[1]" TL="2" V="Indefinite">
|     **--** \</I O="4" T="[UNIVERSAL 0]" L="4">
|     **#** Do not terminate:
|     **#** the absence of end-of-content octets is intentional!
| \</C O="6" T="[1]" L="6">

# SEE ALSO

`unber`(1), `asn1c`(1).
