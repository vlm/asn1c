#include <T.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sysexits.h>

#ifdef ASN1_TEXT
#define STRINGIFY(x)    #x
#define ASN1_STR    STRINGIFY(ASN1_TEXT)
#else
#define ASN1_STR    "T"
#endif

static const struct encoding_map {
    const char *name;
    const char *dir_name;
    enum asn_transfer_syntax syntax;
} encodings[] = {
    {"DER", "der", ATS_DER},
    {"OER", "oer", ATS_CANONICAL_OER},
    {"UPER", "uper", ATS_UNALIGNED_CANONICAL_PER},
    {"XER", "xer", ATS_CANONICAL_XER},
};

static enum asn_transfer_syntax
lookup_syntax(const char *name) {
    if(name) {
        for(size_t i = 0; i < sizeof(encodings) / sizeof(encodings[0]); i++) {
            struct encoding_map enc = encodings[i];
            if(strcasecmp(name, enc.name) == 0) {
                return enc.syntax;
            }
        }
    }
    return ATS_INVALID;
}


#ifdef  ENABLE_LIBFUZZER

static int initialized;
static enum asn_transfer_syntax syntax;
static void __attribute__((constructor)) initialize() {
    initialized = 1;
    const char *data_dir = getenv("ASN1_DATA_DIR");
    if(data_dir && strrchr(data_dir, '/')) {
        data_dir = strrchr(data_dir, '/') + 1;
    }
    syntax = lookup_syntax(data_dir);
    if(syntax == ATS_INVALID) {
        fprintf(stderr,
                "Expected ASN1_DATA_DIR={der,oer,uper,xer} environment "
                "variable.\n");
        exit(EX_UNAVAILABLE);
    }
}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size);

int
LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    if(!initialized) exit(0);

    /*
     * Try to decode whatever garbage that comes in Data/Size.
     * The idea is that we should not crash, and we should not leak memory,
     * no matter what garbage we're dealing with.
     */
    T_t *structure = 0;
    (void)asn_decode(0, syntax, &asn_DEF_T, (void **)&structure, Data, Size);
    ASN_STRUCT_FREE(asn_DEF_T, structure);

    return 0;
}

#else   /* The usual check */

static void
usage(const char *progname) {
    fprintf(stderr,
            "Usage: %s {-c|-g <dir>} [-n <number>] [-e <encoding> ...]\n"
            "OPTIONS:\n"
            "  -c               Check encode-decode round-trip on random data\n"
            "  -g <dir>         Generate random data for selected encodings\n"
            "  -s <size>        Approximate max random value size for -c and -g\n"
            "  -n <number>      Number of iterations for -c and -g\n"
            "  -e <encoding>    Encodings to test or generate random data for\n"
            "Encodings (ASN.1 Transfer Syntaxes):\n"
            "   DER             Distinguished Encoding Rules (compatible with "
            "BER)\n"
            "   OER             Canonical Octet Encoding Rules\n"
            "   UPER            Canonical Unaligned Packed Encoding Rules\n"
            "   XER             XML Encoding Rules\n",
            progname);
}

static int
file_write_cb(const void *data, size_t size, void *key) {
    return fwrite(data, 1, size, (FILE *)key) == size ? 0 : -1;
}

#ifndef PATH_MAX
#define PATH_MAX        255
#endif

static void
generate_random_data(enum asn_transfer_syntax syntax, const char *top_dirname, size_t max_random_value_size, int iterations, int debug) {
    char dirname[PATH_MAX];
    size_t dirname_len = 0;
    dirname[dirname_len] = '\0';

    for(size_t i = 0; i < sizeof(encodings)/sizeof(encodings[0]); i++) {
        struct encoding_map enc = encodings[i];
        if(enc.syntax == syntax) {
            int r = snprintf(dirname, sizeof(dirname), "%s/%s", top_dirname,
                             enc.dir_name);
            if(r < 0 || (size_t)r >= sizeof(dirname) - sizeof("filename.bin")) {
                fprintf(stderr, "Too long filenames\n");
                exit(EX_SOFTWARE);
            }
            dirname_len = r;
            fprintf(stderr, "Generating %d random %s values of %s into %s\n",
                    iterations, enc.name, asn_DEF_T.name, dirname);
            break;
        }
    }
    assert(dirname[0]);

    (void)mkdir(top_dirname, 0777);

    if(mkdir(dirname, 0777) == -1) {
        if(errno == EEXIST) {
            fprintf(stderr, "%s: is already present, remove.\n", dirname);
            fprintf(stderr, "%s: not overwriting potentially valuable data.\n",
                    dirname);
        }
        perror(dirname);
        exit(2);
    }

    size_t generated_ok = 0;
    for(int i = 0; i < iterations; i++) {
        T_t *structure = 0;
        FILE *f;
        snprintf(&dirname[dirname_len], sizeof(dirname) - dirname_len,
                 "/%03d.bin", i);

        if(asn_random_fill(&asn_DEF_T, (void **)&structure,
                           max_random_value_size)
           == -1) {
            assert(structure == 0);
            fprintf(stderr, "Can't generate %d'th value, skipping\n", i);
            continue;
        }
        assert(structure != 0);

        const char *filename = dirname;
        f = fopen(filename, "wb");
        if(!f) {
            perror(filename);
            assert(f);
            exit(EX_SOFTWARE);
        }
        asn_enc_rval_t rval =
            asn_encode(0, syntax, &asn_DEF_T, structure, file_write_cb, f);
        fclose(f);
        if(rval.encoded == -1) {
            fprintf(stderr, "Cannot encode a random value of T into %s:\n",
                    filename);
            if(rval.failed_type) {
                fprintf(stderr, "(Failed type: %s)\n", rval.failed_type->name);
            }
            asn_fprint(stderr, &asn_DEF_T, structure);
            exit(EX_SOFTWARE);
        }

        if(debug) {
            if(i < 5 || debug > 1) {
                fprintf(stderr, "[%s] ", &filename[dirname_len+1]);
                asn_fprint(stderr, &asn_DEF_T, structure);
            } else if(i == 5) {
                fprintf(stderr, "... and so on\n");
            }
        }

        ASN_STRUCT_FREE(asn_DEF_T, structure);
        generated_ok++;
    }

    if(!generated_ok) {
        fprintf(stderr, "Requested to generate %d values, but failed.\n",
                iterations);
        exit(EX_SOFTWARE);
    }

}

static void
check_random_roundtrip(enum asn_transfer_syntax syntax, size_t max_random_value_size, int iterations, int debug) {
    struct encoding_map enc;

    for(size_t i = 0; i < sizeof(encodings)/sizeof(encodings[0]); i++) {
        enc = encodings[i];
        if(enc.syntax == syntax) {
            fprintf(stderr, "Testing %d iterations of round-trip for %s\n",
                    iterations, enc.name);
            break;
        }
    }

    for(int i = 0; i < iterations; i++) {
        char tmp_buffer[512];
        char *buffer = tmp_buffer;
        size_t buffer_size = sizeof(tmp_buffer);
        T_t *structure = 0;
        T_t *decoded_structure = 0;

        if(asn_random_fill(&asn_DEF_T, (void **)&structure,
                           max_random_value_size)
           == -1) {
            assert(structure == 0);
            fprintf(stderr, "Can't generate %d'th value, skipping\n", i);
            continue;
        }
        assert(structure != 0);

        if(debug) {
            fprintf(stderr, "Random structure %s:\n",
                    sizeof(ASN1_STR) > 60 ? "T" : ASN1_STR);
            asn_fprint(stderr, &asn_DEF_T, structure);
            xer_fprint(stderr, &asn_DEF_T, structure);
        }

        asn_enc_rval_t er;
        for(;;) {
            er = asn_encode_to_buffer(
                0, syntax, &asn_DEF_T, structure, buffer, buffer_size);
            if(er.encoded < 0) {
                fprintf(stderr, "Encoded T into %zd bytes\n", er.encoded);
                fprintf(stderr, "Structure %s:\n",
                        sizeof(ASN1_STR) > 60 ? "T" : ASN1_STR);
                asn_fprint(stderr, &asn_DEF_T, structure);
                assert(er.encoded >= 0);
                exit(EX_SOFTWARE);
            }
            if((size_t)er.encoded > buffer_size && buffer == tmp_buffer) {
                if(debug) {
                    fprintf(
                        stderr,
                        "Reallocate output buffer %zu -> %zu (iteration %d)\n",
                        buffer_size, er.encoded, i);
                }
                buffer = malloc(er.encoded + 1);
                assert(buffer);
                buffer[er.encoded] = '\0';
                buffer_size = er.encoded;
                continue;
            }
            break;
        }
        if((size_t)er.encoded > buffer_size) {
            fprintf(stderr, "Data %zd does not fit into buffer %zu\n",
                    er.encoded, buffer_size);
            assert((size_t)er.encoded <= buffer_size);
        }

        asn_dec_rval_t rval =
            asn_decode(0, syntax, &asn_DEF_T, (void **)&decoded_structure,
                       buffer, er.encoded);
        if(rval.code == RC_OK) {
            /* Everything's cool... or is it? Expecting a proper consumed */
            if((ssize_t)rval.consumed != er.encoded) {
                fprintf(stderr, "Encoded into %zd, yet consumed %zu\n",
                        er.encoded, rval.consumed);
                fprintf(stderr, "Original random structure:\n");
                asn_fprint(stderr, &asn_DEF_T, structure);
                fprintf(stderr, "Partially decoded %s value:\n", ASN1_STR);
                asn_fprint(stderr, &asn_DEF_T, decoded_structure);
                assert((ssize_t)rval.consumed == er.encoded);
                exit(EX_SOFTWARE);
            }
        } else {
            fprintf(stderr,
                    "Decoding %zu bytes of T yielded %s after byte %zu\n",
                    er.encoded, rval.code == RC_FAIL ? "RC_FAIL" : "RC_WMORE",
                    rval.consumed);
            fprintf(stderr, "Original random structure:\n");
            asn_fprint(stderr, &asn_DEF_T, structure);
            exit(EX_SOFTWARE);
        }

        /*
         * Confirm that we decoded the same data.
         */
        int cmp = asn_DEF_T.op->compare_struct(&asn_DEF_T, structure,
                                               decoded_structure);
        if(cmp != 0 || debug) {
            fprintf(stderr, "Random %s value:\n", ASN1_STR);
            asn_fprint(stderr, &asn_DEF_T, structure);
            xer_fprint(stderr, &asn_DEF_T, structure);
            fprintf(stderr, "Decoded %s value:\n", ASN1_STR);
            asn_fprint(stderr, &asn_DEF_T, decoded_structure);
            xer_fprint(stderr, &asn_DEF_T, decoded_structure);
            assert(cmp == 0);
        }
        ASN_STRUCT_FREE(asn_DEF_T, structure);
        ASN_STRUCT_FREE(asn_DEF_T, decoded_structure);

        if(buffer != tmp_buffer) {
            free(buffer);
        }

        if(i < 5) {
            fprintf(stderr, "[%03d] round-trip in %zd bytes OK\n", i,
                    er.encoded);
        } else if(i == 5) {
            fprintf(stderr, "... and so on\n");
        }
    }

    fprintf(stderr, "OK %d iterations of round-trip for %s\n", iterations,
            enc.name);
}

int main(int argc, char **argv) {
    uint32_t enabled_encodings = 0;
    enum {
        MODE_UNKNOWN,
        MODE_GENERATE_RANDOM_DATA,
        MODE_CHECK_RANDOM_ROUNDTRIP
    } mode = MODE_UNKNOWN;
    const char *generate_into_dir = NULL;
    int iterations = 100;
    size_t max_random_value_size = 128;
    int debug = 0;
    int c;

    while((c = getopt(argc, argv, "cde:g:hn:s:")) != -1) {
        switch(c) {
        case 'c':
            mode = MODE_CHECK_RANDOM_ROUNDTRIP;
            break;
        case 'd':
            debug++;
            break;
        case 'e':
            enabled_encodings |= 1 << lookup_syntax(optarg);
            if(enabled_encodings & (1 << ATS_INVALID)) {
                fprintf(stderr, "-e %s: Unknown (unsupported?) encoding\n",
                        optarg);
                exit(EX_UNAVAILABLE);
            }
            break;
        case 'g':
            mode = MODE_GENERATE_RANDOM_DATA;
            generate_into_dir = optarg;
            break;
        case 'h':
            usage(argv[0]);
            exit(0);
        case 'n':
            iterations = atoi(optarg);
            if(iterations <= 0) {
                fprintf(stderr, "-n %s: positive value expected\n", optarg);
                exit(EX_DATAERR);
            }
            break;
        case 's':
            if(atoi(optarg) <= 0) {
                fprintf(stderr, "-s %s: positive value expected\n", optarg);
                exit(EX_DATAERR);
            }
            max_random_value_size = atoi(optarg);
            break;
        default:
            usage(argv[0]);
            exit(2);
        }
    }

    if(mode == MODE_UNKNOWN) {
        usage(argv[0]);
        exit(2);
    } else if(!enabled_encodings) {
        for(size_t i = 0; i < sizeof(encodings)/sizeof(encodings[0]); i++) {
            enabled_encodings |= 1 << encodings[i].syntax;
        }
    }

    /* Enumerate requested encodings (-e ...) */
    for(unsigned i = 0; i < 8*sizeof(enabled_encodings)-1; i++) {
        if(enabled_encodings & (1 << i)) {
            enum asn_transfer_syntax syntax = i;
            switch(mode) {
            case MODE_UNKNOWN:
                assert(mode != MODE_UNKNOWN);
                break;
            case MODE_GENERATE_RANDOM_DATA:
                generate_random_data(syntax, generate_into_dir,
                                     max_random_value_size, iterations, debug);
                break;
            case MODE_CHECK_RANDOM_ROUNDTRIP:
                check_random_roundtrip(syntax, max_random_value_size,
                                       iterations, debug);
                break;
            }
        }
    }

    return 0;
}

#endif
