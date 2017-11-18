#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>

#include "asn1p_integer.h"

#define ASN_INTEGER_MAX    \
    (~((asn1c_integer_t)0) \
     & ~((asn1c_integer_t)1 << (8 * sizeof(asn1c_integer_t) - 1)))
#define ASN_INTEGER_MIN (-(ASN_INTEGER_MAX)-1)

/*
 * Parse the number in the given string until the given *end position,
 * returning the position after the last parsed character back using the
 * same (*end) pointer.
 * WARNING: This behavior is different from the standard strtol/strtoimax(3).
 */
enum strtox_result_e {
    STRTOX_ERROR_RANGE = -3, /* Input outside of supported numeric range */
    STRTOX_ERROR_INVAL = -2, /* Invalid data encountered (e.g., "+-") */
    STRTOX_EXPECT_MORE = -1, /* More data expected (e.g. "+") */
    STRTOX_OK = 0,           /* Conversion succeded, number ends at (*end) */
    STRTOX_EXTRA_DATA =
        1 /* Conversion succeded, but the string has extra stuff */
};

static enum strtox_result_e
strtoaint_lim(const char *str, const char **end, asn1c_integer_t *intp) {
	const asn1c_integer_t upper_boundary = ASN_INTEGER_MAX / 10;
	int last_digit_max = ASN_INTEGER_MAX % 10;
	int sign = 1;
	asn1c_integer_t value;

	if(str >= *end) return STRTOX_ERROR_INVAL;

	switch(*str) {
	case '-':
		last_digit_max++;
		sign = -1;
		/* FALL THROUGH */
	case '+':
		str++;
		if(str >= *end) {
			*end = str;
			return STRTOX_EXPECT_MORE;
		}
	}

	for(value = 0; str < (*end); str++) {
		switch(*str) {
		case 0x30: case 0x31: case 0x32: case 0x33: case 0x34:
		case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: {
			int d = *str - '0';
			if(value < upper_boundary) {
				value = value * 10 + d;
			} else if(value == upper_boundary) {
				if(d <= last_digit_max) {
					if(sign > 0) {
						value = value * 10 + d;
					} else {
						sign = 1;
						value = -value * 10 - d;
					}
				} else {
					*end = str;
					return STRTOX_ERROR_RANGE;
				}
			} else {
				*end = str;
				return STRTOX_ERROR_RANGE;
			}
		    }
		    continue;
		default:
		    *end = str;
		    *intp = sign * value;
		    return STRTOX_EXTRA_DATA;
		}
	}

	*end = str;
	*intp = sign * value;
	return STRTOX_OK;
}

int
asn1p_atoi(const char *ptr, asn1c_integer_t *value) {
    const char *end = ptr + strlen(ptr);
    if(strtoaint_lim(ptr, &end, value) == STRTOX_OK) {
        return 0;
    } else {
        return -1;
    }
}

const char *asn1p_itoa(asn1c_integer_t v) {
    static char static_buf[128];
    int ret = asn1p_itoa_s(static_buf, sizeof(static_buf), v);
    if(ret > 0) {
        assert((size_t)ret < sizeof(static_buf));
        return static_buf;
    } else {
        return NULL;
    }
}

int asn1p_itoa_s(char *buf, size_t size, asn1c_integer_t v) {
    char tmp_buf[128];

    if(v >= LONG_MIN && v < LONG_MAX) {
        int ret = snprintf(buf, size, "%ld", (long)v);
        if(ret < 0 || (size_t)ret >= size) {
            return -1;
        }
        return ret;
    }

    int sign = 0;
    if(v < 0) {
        if(v == ASN_INTEGER_MIN) {
            switch(sizeof(v)) {
            case 16:
                if(size < 41)
                    return -1;
                memcpy(buf, "-170141183460469231731687303715884105729", 41);
                return 41;
            case 8:
                if(size < 21)
                    return -1;
                memcpy(buf, "-9223372036854775809", 21);
                return 21;
            default:
                assert(!"unreachable");
            }
        }

        sign = -1;
        v = -v; /* Ditch the sign */
    }

    assert(v > 1000000000L);
    char restbuf[10] = "000000000\0";
    const char *rest = asn1p_itoa((long)(v % 1000000000L));
    size_t restlen = strlen(rest);
    assert(restlen <= 9);
    memcpy(restbuf + (9 - restlen), rest, restlen);
    rest = restbuf;

    const char *head = asn1p_itoa(v / 1000000000L);
    assert(head);
    int ret = snprintf(tmp_buf, sizeof(tmp_buf), "%s%s%s", sign ? "-" : "",
                       head, rest);
    if(ret < 0 || (size_t)ret >= size) {
        assert(ret > 0 && (size_t)ret < sizeof(tmp_buf));
        return -1;
    }
    memcpy(buf, tmp_buf, ret);
    buf[ret] = '\0';
    return ret;
}

abuf *
asn1p_integer_as_INTEGER(asn1c_integer_t value) {
    abuf *ab = abuf_new();
    uint8_t buf[sizeof(value) + 1];
    uint8_t *bp = buf;

    do {
        *bp++ = value;
        value >>= 8;
    } while(!((value == 0 && !(bp[-1] & 0x80))
              || (value == -1 && (bp[-1] & 0x80))));

    abuf_printf(ab, "{ (uint8_t *)\"");

    for(const uint8_t *p = bp-1; p >= buf; p--) {
        abuf_printf(ab, "\\x%02x", *p);
    }

    abuf_printf(ab, "\\0\", %zu }", bp - buf);

    return ab;
}
