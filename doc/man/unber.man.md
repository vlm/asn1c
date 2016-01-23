% unber(1) ASN.1 BER Decoder
% Lev Walkin <vlm@lionet.info>
% 2016-01-23

# NAME

unber -- the ASN.1 BER Decoder

# SYNOPSIS

unber [**-1**] [**-i***indent*] [**-m**] [**-p**] [**-s***skip*] [**-t***hex-string*] [**-**] [*input-filenames*...]

# DESCRIPTION

unber presents the internal structure of BER-encoded files as a human readable text.
A single dash denotes the standard input.

(The DER and CER formats are subsets of the BER and are also supported.)

# OPTIONS

-1
:   Do *not* attempt to read the next BER structure after the first one.
    This may be useful if the input contains garbage past the single BER sequence.
    By default, unber continues decoding until the end of file (input stream).

-i *indent*
:   Use the specified number of spaces for output indentation.
    Default is 4 spaces.

-m
:   Generate shorter output while still preserving BER encoding information.

-p
:   Do *not* attempt to pretty-print known ASN.1 types (`BOOLEAN`, `INTEGER`, `OBJECT IDENTIFIER`, etc).
    By default, some ASN.1 types are converted into the text representation.

    This option is required if the `unber`(1) output is used as an input to `enber`(1).

-s *skip*
:   Ignore the first *skip* bytes in the input stream;
    useful for stripping off lower level protocol framing data.

-t *hex-string*
:   Interpret the hex-string as a sequence of hexadecimal values representing
    the start of BER TLV encoding.
    Print the human readable explanation.

# XML FORMAT
unber dumps the output in the regular XML format which preserves most of the
information from the underlying binary encoding.

The XML opening tag format is as follows:

<**tform** O="**off**" T="**tag**" TL="**t_len**" V="{Indefinite|**v_len**}" [A="**type**"] [**F**]>

Where:

**tform**
:   Encoding form the value is in: primitive ("P") or constructed ("C") or constructed with indefinite length ("I")

**off**
:   Offset of the encoded element in the unber input stream.

**tag**
:   The tag class and value in human readable form.

**t_len**
:   The length of the TL (BER Tag and Length) encoding.

**v_len**
:   The length of the value (V, encoded by the L), may be "Indefinite".

**type**
:   Likely name of the underlying ASN.1 type (for UNIVERSAL tags).

[**F**]
:   Indicates that the value was reformatted (pretty-printed).
This will never appear in the output produced using the **-p**
command line option.

## Example XML output:

| \<I O="0" T="[UNIVERSAL 16]" TL="2" V="Indefinite" A="SEQUENCE">
|  \<P O="2" T="[UNIVERSAL 19]" TL="2" V="2" A="PrintableString">US\</P>
|   \<C O="6" T="[UNIVERSAL 16]" TL="2" V="6" A="SEQUENCE">
|     \<P O="8" T="[UNIVERSAL 2]" TL="2" V="4" A="INTEGER" F>832970823\</P>
|   \</C O="14" T="[UNIVERSAL 16]" A="SEQUENCE" L="8">
| \</I O="14" T="[UNIVERSAL 0]" TL="2" L="16">

# EXAMPLES

Decode the given Tag/Length sequence specified in hexadecimal form:

> unber\  **-t** "*bf 20*"

Decode the DER file using two-spaces indentation:

> unber\  **-i** *2*\   *filename.der*

Decode the binary stream taken from the standard input:

> cat *filename.der* | unber **-**

Decode the binary stream and encode it back into an identical stream (see `enber`(1)):

> cat *filename.der* | unber **-p** **-** | enber **-** > *filename.ber*

# FOOTNOTES
The constructed XML output is not necessarily well-formed.

When indefinite length encoding is being used, the BER sequence which is not
terminated with the end-of-content octets will cause the terminating **\</I>**
XML tag to disappear.
Thus, invalid BER framing directly causes invalid XML output.

The `enber`(1) utility understands such XML correctly.

# SEE ALSO

`enber`(1), `asn1c`(1).
