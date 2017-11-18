#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>

#include "asn1p_integer.h"

static void check(int lineno, asn1c_integer_t value, const char *expected);

struct {
    uint8_t *buf; size_t size;
} ff = {
    (uint8_t *)"sdf", 3
};

int main() {

    check(__LINE__, 0, "{ (uint8_t *)\"\\x00\\0\", 1 }");
    check(__LINE__, 1, "{ (uint8_t *)\"\\x01\\0\", 1 }");
    check(__LINE__, 127, "{ (uint8_t *)\"\\x7f\\0\", 1 }");
    check(__LINE__, 128, "{ (uint8_t *)\"\\x00\\x80\\0\", 2 }");
    check(__LINE__, 129, "{ (uint8_t *)\"\\x00\\x81\\0\", 2 }");

    check(__LINE__, -1, "{ (uint8_t *)\"\\xff\\0\", 1 }");
    check(__LINE__, -2, "{ (uint8_t *)\"\\xfe\\0\", 1 }");
    check(__LINE__, -127, "{ (uint8_t *)\"\\x81\\0\", 1 }");
    check(__LINE__, -128, "{ (uint8_t *)\"\\x80\\0\", 1 }");
    check(__LINE__, -129, "{ (uint8_t *)\"\\xff\\x7f\\0\", 2 }");
    check(__LINE__, -254, "{ (uint8_t *)\"\\xff\\x02\\0\", 2 }");
    check(__LINE__, -255, "{ (uint8_t *)\"\\xff\\x01\\0\", 2 }");
    check(__LINE__, -256, "{ (uint8_t *)\"\\xff\\x00\\0\", 2 }");
    check(__LINE__, -257, "{ (uint8_t *)\"\\xfe\\xff\\0\", 2 }");

    check(__LINE__, ~(asn1c_integer_t)0, "{ (uint8_t *)\"\\xff\\0\", 1 }");

    switch(sizeof(asn1c_integer_t)) {
    case 4:
        check(__LINE__,
              ~(asn1c_integer_t)0
                  & ~((asn1c_integer_t)1 << (8 * sizeof(asn1c_integer_t) - 1)),
              "{ (uint8_t *)\""
              "\\x7f\\xff\\xff\\xff"
              "\\0\", 4 }");
        break;
    case 8:
        check(__LINE__,
              ~(asn1c_integer_t)0
                  & ~((asn1c_integer_t)1 << (8 * sizeof(asn1c_integer_t) - 1)),
              "{ (uint8_t *)\""
              "\\x7f\\xff\\xff\\xff\\xff\\xff\\xff\\xff"
              "\\0\", 8 }");
        break;
    case 16:
        check(__LINE__,
              ~(asn1c_integer_t)0
                  & ~((asn1c_integer_t)1 << (8 * sizeof(asn1c_integer_t) - 1)),
              "{ (uint8_t *)\""
              "\\x7f\\xff\\xff\\xff\\xff\\xff\\xff\\xff"
              "\\xff\\xff\\xff\\xff\\xff\\xff\\xff\\xff"
              "\\0\", 16 }");

        break;
    default:
        assert(!"Unreachable");
    }

    return 0;
}

static void check(int lineno, asn1c_integer_t value, const char *expected) {
    abuf *ab;
    ab = asn1p_integer_as_INTEGER(value);
    assert(ab);
    if(strcmp(ab->buffer, expected)) {
        fprintf(stderr, "%02d: %s -> [%s], expected [%s]\n", lineno,
                asn1p_itoa(value), ab->buffer, expected);
        assert(strcmp(ab->buffer, expected) == 0);
    }
    printf("%02d: %s -> %s\n", lineno, asn1p_itoa(value), ab->buffer);
    abuf_free(ab);
}
