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

static unsigned long i2ul(const INTEGER_t *i) {
    unsigned long l;
    int ret = asn_INTEGER2ulong(i, &l);
    assert(ret == 0);
    return l;
}

static long i2l(const INTEGER_t *i) {
    long l;
    int ret = asn_INTEGER2long(i, &l);
    assert(ret == 0);
    return l;
}

static void ul2i(INTEGER_t *i, unsigned long l) {
    int ret = asn_ulong2INTEGER(i, l);
    assert(ret == 0);
}

static void l2i(INTEGER_t *i, long l) {
    int ret = asn_long2INTEGER(i, l);
    assert(ret == 0);
}

static void
verify(int testNo, T_t *ti) {
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	unsigned char buf[20];
	T_t *to = 0;

	fprintf(stderr, "%d IN: { %lu, %lu, %ld, %ld }\n", testNo,
		i2ul(&ti->unsigned33), i2ul(&ti->unsigned42),
		i2l(&ti->signed33), i2l(&ti->signed33ext)
    );

	er = uper_encode_to_buffer(&asn_DEF_T, 0, ti, buf, sizeof buf);
	assert(er.encoded >= 33 + 42 + 33 + 1 + 33);

	rv = uper_decode(0, &asn_DEF_T, (void *)&to, buf, sizeof buf, 0, 0);
	assert(rv.code == RC_OK);

	fprintf(stderr, "%d ENC: %2x%2x%2x%2x %2x%2x%2x%2x\n", testNo,
		buf[0], buf[1], buf[2], buf[3],
		buf[4], buf[5], buf[6], buf[7]);
	fprintf(stderr, "%d OUT: { %lu, %lu, %ld, %ld } vs { %lu, %lu, %ld, %ld }\n",
		testNo,
		i2ul(&ti->unsigned33), i2ul(&ti->unsigned42),
		i2l(&ti->signed33), i2l(&ti->signed33ext),
		i2ul(&to->unsigned33), i2ul(&to->unsigned42),
		i2l(&to->signed33), i2l(&to->signed33ext));
	assert(i2ul(&ti->unsigned33) == i2ul(&to->unsigned33));
	assert(i2ul(&ti->unsigned42) == i2ul(&to->unsigned42));
	assert(i2l(&ti->signed33) == i2l(&to->signed33));
	assert(i2l(&ti->signed33ext) == i2l(&to->signed33ext));

	xer_fprint(stderr, &asn_DEF_T, ti);
	xer_fprint(stderr, &asn_DEF_T, to);
	ASN_STRUCT_FREE(asn_DEF_T, to);
}

static void
NO_encode(int testNo, T_t *ti) {
	asn_enc_rval_t er;
	unsigned char buf[16];

	fprintf(stderr, "%d IN: { %lu, %lu, %ld, %ld }\n", testNo,
		i2ul(&ti->unsigned33), i2ul(&ti->unsigned42),
		i2l(&ti->signed33), i2l(&ti->signed33ext)
    );

	er = uper_encode_to_buffer(&asn_DEF_T, 0, ti, buf, sizeof buf);
	assert(er.encoded == -1);
}

int main() {
	T_t ti;

    memset(&ti, 0, sizeof(ti));
    ul2i(&ti.unsigned33,  0);
    ul2i(&ti.unsigned42,  0);
    l2i(&ti.signed33,    0);
    l2i(&ti.signed33ext, 0);
	verify(1, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  1);
    ul2i(&ti.unsigned42,  1);
    l2i(&ti.signed33,    1);
    l2i(&ti.signed33ext, 1);
	verify(2, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  5000000000);
    ul2i(&ti.unsigned42,  3153600000000);
    l2i(&ti.signed33,    4000000000);
    l2i(&ti.signed33ext, 4000000000);
	verify(3, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33, -1);
    ul2i(&ti.unsigned42,  0);
    l2i(&ti.signed33,    0);
    l2i(&ti.signed33ext, 0);
	NO_encode(4, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  0);
    ul2i(&ti.unsigned42, -1);
    l2i(&ti.signed33,    0);
    l2i(&ti.signed33ext, 0);
	NO_encode(5, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  0);
    ul2i(&ti.unsigned42,  0);
    l2i(&ti.signed33,    -4000000000-1);
    l2i(&ti.signed33ext, 0);
	NO_encode(6, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  0);
    ul2i(&ti.unsigned42,  0);
    l2i(&ti.signed33,    0);
    l2i(&ti.signed33ext, -4000000000-1);
    assert(ti.signed33ext.size == 5);
	verify(7, &ti); /* signed33ext is extensible */
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  5000000000 + 1);
    ul2i(&ti.unsigned42,  0);
    l2i(&ti.signed33,    0);
    l2i(&ti.signed33ext, 0);
	NO_encode(8, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  0);
    ul2i(&ti.unsigned42,  3153600000000 + 1);
    l2i(&ti.signed33,    0);
    l2i(&ti.signed33ext, 0);
	NO_encode(9, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  5000000000 - 1);
    ul2i(&ti.unsigned42,  3153600000000 - 1);
    l2i(&ti.signed33,    4000000000 - 1);
    l2i(&ti.signed33ext, 4000000000 - 1);
	verify(10, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

    ul2i(&ti.unsigned33,  0);
    ul2i(&ti.unsigned42,  0);
    l2i(&ti.signed33,    0);
    l2i(&ti.signed33ext, 4000000000 + 1);
	verify(11, &ti);
	ASN_STRUCT_RESET(asn_DEF_T, &ti);

	return 0;
}

