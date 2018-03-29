/*
 * Since working awk is not present on every supported platform
 * (notably Solaris), and nawk is not the same on Solaris and Linux,
 * this program is a replacement for it to extract test parameter from the.
 * string specified in the command line.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

static void
usage(const char *progname) {
    fprintf(stderr, "Search PARAM=VALUE pattern in the given string\n");
    fprintf(stderr, "Usage: %s <parameter-name> <default-value> <string>\n",
            progname);
}

static const char *
search(const char *param, const char *haystack) {

    const char *p = strstr(haystack, param);
    if(p && p[strlen(param)] == '=') {
        const char *param_begin = &p[strlen(param) + 1];
        const char *param_end = param_begin;
        for(param_end = param_begin; param_end; param_end++) {
            switch(*param_end) {
            case '0' ... '9':
                continue;
            default:
                break;
            }
            break;
        }

        static char static_buf[64];

        if((param_end - param_begin) <= 0) {
            fprintf(stderr, "Parameter %s is malformed after '='\n", param);
            return NULL;
        }

        if((param_end - param_begin) >= (ssize_t)sizeof(static_buf)) {
            fprintf(stderr, "Parameter %s value exceeds buffer size %zu\n",
                    param, sizeof(static_buf));
            return NULL;
        }

        memcpy(static_buf, param_begin, param_end - param_begin);
        static_buf[param_end - param_begin] = '\0';
        return static_buf;
    } else if(p) {
        fprintf(stderr, "Parameter %s should contain '='\n", param);
        return NULL;
    }

    return NULL;
}

int
main(int ac, char **av) {
    if(ac != 4) {
        usage(av[0]);
        exit(EX_USAGE);
    }

    const char *value = search(av[1], av[3]);
    if(value) {
        printf("%s\n", value);
    } else {
        printf("%s\n", av[2]);
    }
}
