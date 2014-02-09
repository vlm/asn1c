/*
 * Verify INTEGER values with greater than 32 bits range.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>

#include <T.h>

#ifndef  _LP64
int main() {
    assert(sizeof(void *) < 8);
    return;
}
#else   /* 64-bit platform */

static unsigned long i2ul(const INTEGER_t *i) {
    unsigned long l;
    int ret = asn_INTEGER2ulong(i, &l);
    assert(ret == 0);
    return l;
}

static void ul2i(INTEGER_t *i, unsigned long l) {
    int ret = asn_ulong2INTEGER(i, l);
    assert(ret == 0);
}

static void
verify(int testNo, T_t *ti) {
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	unsigned char buf[16];
	T_t *to = 0;

	fprintf(stderr, "%d IN: { %lu, %lu }\n", testNo,
		i2ul(&ti->unsigned33), i2ul(&ti->unsigned42));

	er = uper_encode_to_buffer(&asn_DEF_T, ti, buf, sizeof buf);
	assert(er.encoded == 33 + 42);

	rv = uper_decode(0, &asn_DEF_T, (void *)&to, buf, sizeof buf, 0, 0);
	assert(rv.code == RC_OK);

	fprintf(stderr, "%d ENC: %2x%2x%2x%2x %2x%2x%2x%2x\n", testNo,
		buf[0], buf[1], buf[2], buf[3],
		buf[4], buf[5], buf[6], buf[7]);
	fprintf(stderr, "%d OUT: { %lu, %lu } vs { %lu, %lu }\n",
		testNo,
		i2ul(&ti->unsigned33), i2ul(&ti->unsigned42),
		i2ul(&to->unsigned33), i2ul(&to->unsigned42));
	assert(i2ul(&ti->unsigned33) == i2ul(&to->unsigned33));
	assert(i2ul(&ti->unsigned42) == i2ul(&to->unsigned42));

	xer_fprint(stderr, &asn_DEF_T, ti);
	xer_fprint(stderr, &asn_DEF_T, to);
}

static void
NO_encode(int testNo, T_t *ti) {
	asn_enc_rval_t er;
	unsigned char buf[16];

	fprintf(stderr, "%d IN: { %lu, %lu }\n", testNo,
		i2ul(&ti->unsigned33), i2ul(&ti->unsigned42));

	er = uper_encode_to_buffer(&asn_DEF_T, ti, buf, sizeof buf);
	assert(er.encoded == -1);
}

int main() {
	T_t ti;

    memset(&ti, 0, sizeof(ti));
    ul2i(&ti.unsigned33, 0);
    ul2i(&ti.unsigned42, 0);
	verify(1, &ti);

    ul2i(&ti.unsigned33, 1);
    ul2i(&ti.unsigned42, 1);
	verify(2, &ti);

    ul2i(&ti.unsigned33, 5000000000);
    ul2i(&ti.unsigned42, 3153600000000);
	verify(3, &ti);

    ul2i(&ti.unsigned33, -1);
    ul2i(&ti.unsigned42, 0);
	NO_encode(4, &ti);

    ul2i(&ti.unsigned33, 0);
    ul2i(&ti.unsigned42, -1);
	NO_encode(5, &ti);

    ul2i(&ti.unsigned33, 5000000000 + 1);
    ul2i(&ti.unsigned42, 0);
	NO_encode(6, &ti);

    ul2i(&ti.unsigned33, 0);
    ul2i(&ti.unsigned42, 3153600000000 + 1);
	NO_encode(7, &ti);

    ul2i(&ti.unsigned33, 5000000000 - 1);
    ul2i(&ti.unsigned42, 3153600000000 - 1);
	verify(8, &ti);

	return 0;
}

#endif  /* 64-bit platform */
