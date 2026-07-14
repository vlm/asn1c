/*
 * Regression test for uper_open_type_skip() (per_opentype.c).
 * An unrecognized extension's open type content is an integral number
 * of octets; skipping it must consume exactly the length determinant
 * plus the content, for every content length, leaving subsequent
 * fields decodable.
 */
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include <asn_application.h>
#include <per_support.h>
#include <per_opentype.h>

static void
check_skip(size_t content_bytes, int fill) {
    uint8_t buf[16];
    asn_per_data_t pd;
    int ret;
    int32_t next;

    assert(content_bytes + 2 <= sizeof(buf));

    /* [length determinant][content x N][next field sentinel] */
    buf[0] = (uint8_t)content_bytes; /* X.691 #11.9 short form */
    memset(&buf[1], fill, content_bytes);
    buf[1 + content_bytes] = 0x5A;

    memset(&pd, 0, sizeof(pd));
    pd.buffer = buf;
    pd.nboff = 0;
    pd.nbits = 8 * (2 + content_bytes);

    ret = uper_open_type_skip(NULL, &pd);
    fprintf(stderr, "Skip open type of %zu bytes of 0x%02x => %d, moved %zu\n",
            content_bytes, fill, ret, pd.moved);
    assert(ret == 0);

    /* Exactly the open type was consumed... */
    assert(pd.moved == 8 * (1 + content_bytes));

    /* ...so the next field is still decodable. */
    next = per_get_few_bits(&pd, 8);
    assert(next == 0x5A);
}

int
main(void) {
    size_t n;

    for(n = 0; n <= 10; n++) {
        check_skip(n, 0xAA); /* Non-zero contents */
        check_skip(n, 0x00); /* All-zeros contents */
    }

    return 0;
}
