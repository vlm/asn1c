/*
 * Copyright (c) 2004, 2005, 2006 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
#include "asn1_common.h"
#include "libasn1_unber_tool.h"

#undef COPYRIGHT
#define COPYRIGHT "Copyright (c) 2004-2019 Lev Walkin <vlm@lionet.info>\n"

static void usage(const char *av0);    /* Print the Usage screen and exit */

int
main(int ac, char **av) {
    int ch; /* Command line character */

    /*
     * Process command-line options.
     */
    while((ch = getopt(ac, av, "1hi:mps:t:v")) != -1) {
      switch(ch) {
        case '1':
            set_single_type_decoding(1);
            break;
        case 'i':
            if(set_indent_size(atoi(optarg)) != 0) { 
                fprintf(stderr, "-i %s: Invalid indent value\n", optarg);
                exit(EX_USAGE);
            }
            break;
        case 'm':
            set_minimalistic_output(1);
            break;
        case 'p':
            set_pretty_printing(0);
            break;
        case 's':
            if(set_skip_bytes(atol(optarg)) != 0) {
                fprintf(stderr, "-s %s: positive value expected\n", optarg);
                exit(EX_USAGE);
            }
            break;
        case 't':
            if(decode_tlv_from_hex_string(optarg)) exit(EX_DATAERR);
            exit(0);
        case 'v':
            fprintf(stderr, "ASN.1 BER Decoder, v" VERSION "\n" COPYRIGHT);
            exit(0);
            break;
        case 'h':
        default:
            usage(av[0]);
        }
    }

    /*
     * Ensure that there are some input files present.
     */
    if(ac > optind) {
        ac -= optind;
        av += optind;
    } else {
        fprintf(stderr, "%s: No input files specified\n", av[0]);
        exit(1);
    }

    setvbuf(stdout, 0, _IOLBF, 0);

    /*
     * Iterate over input files and parse each.
     * All syntax trees from all files will be bundled together.
     */
    for(int i = 0; i < ac; i++) {
        if(unber_file(av[i])) exit(EX_DATAERR);
    }

    return 0;
}

/*
 * Print the usage screen and exit(EX_USAGE).
 */
static void
usage(const char *av0) {
    /* clang-format off */
	fprintf(stderr,
"ASN.1 BER Decoder, v" VERSION "\n" COPYRIGHT
"Usage: %s [options] [-] [file ...]\n"
"Options:\n"
"  -1                Decode only the first BER structure (otherwise, until EOF)\n"
"  -i <indent>       Amount of spaces for output indentation (default is 4)\n"
"  -m                Minimalistic mode: print as little as possible\n"
"  -p                Do not attempt pretty-printing of known ASN.1 types\n"
"  -s <skip>         Ignore first <skip> bytes of input\n"
"  -t <hex-string>   Decode the given tag[/length] sequence (e.g. -t \"bf20\")\n"
"\n"
"The XML opening tag format is as follows:\n"
"  <tform O=\"off\" T=\"tag\" TL=\"tl_len\" V=\"{Indefinite|v_len}\" [A=\"type\"] [F]>\n"
"Where:\n"
"  tform    Which form the value is in: constructed (\"C\", \"I\") or primitive (\"P\")\n"
"  off      Offset of the encoded element in the unber input stream\n"
"  tag      The tag class and value in human readable form\n"
"  tl_len   The length of the TL (BER Tag and Length) encoding\n"
"  v_len    The length of the value (V, encoded by the L), may be \"Indefinite\"\n"
"  type     Likely name of the underlying ASN.1 type (for [UNIVERSAL n] tags)\n"
"  [F]      Indicates that the value was reformatted (pretty-printed)\n"
"See the manual page for details\n"
	, av0);
    /* clang-format on */
    exit(EX_USAGE);
}

