#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>

#include <T.h>

static void
verify(int testNo, T_t *ti) {
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	unsigned char buf[16];
	T_t *to = 0;

	fprintf(stderr, "%d IN: { %ld, %ld, %lu, %lu }\n", testNo,
		ti->small32range, ti->full32range,
		ti->unsigned32, ti->unsplit32);

	er = uper_encode_to_buffer(&asn_DEF_T, 0, ti, buf, sizeof buf);
	assert(er.encoded == 8 * sizeof(buf));

	rv = uper_decode(0, &asn_DEF_T, (void *)&to, buf, sizeof buf, 0, 0);
	assert(rv.code == RC_OK);

	fprintf(stderr, "%d ENC: %2x%2x%2x%2x %2x%2x%2x%2x\n", testNo,
		buf[0], buf[1], buf[2], buf[3],
		buf[4], buf[5], buf[6], buf[7]);
	fprintf(stderr, "%d OUT: { %ld, %ld, %lu, %lu } vs { %ld, %ld, %lu, %lu }\n",
		testNo,
		ti->small32range, ti->full32range,
			ti->unsigned32, ti->unsplit32,
		to->small32range, to->full32range,
			to->unsigned32, to->unsplit32);
	assert(ti->small32range == to->small32range);
	assert(ti->full32range == to->full32range);
	assert(ti->unsigned32 == to->unsigned32);
	assert(ti->unsplit32 == to->unsplit32);

	xer_fprint(stderr, &asn_DEF_T, ti);
	xer_fprint(stderr, &asn_DEF_T, to);

	ASN_STRUCT_FREE(asn_DEF_T, to);
}

int main() {
	T_t ti;

	ti.small32range = 0;
	ti.full32range = 0;
	ti.unsigned32 = 0;
	ti.unsplit32 = 5;
	verify(1, &ti);

	ti.small32range = -1;
	ti.full32range = -1;
	ti.unsigned32 = 1;
	ti.unsplit32 = 300;
	verify(2, &ti);

	ti.small32range = -2000000000;
	ti.full32range = (-2147483647L - 1);
	ti.unsigned32 = 4000000000;
	ti.unsplit32 = 500;
	verify(3, &ti);

	ti.small32range = -1999999999;
	ti.full32range = (-2147483647L);
	ti.unsigned32 = 4294967295UL;
	ti.unsplit32 = 600;
	verify(4, &ti);

	ti.small32range = 2000000000;
	ti.full32range = 2147483647;
	ti.unsigned32 = 4294967295UL - 100;
	ti.unsplit32 = 4294967290UL;
	verify(5, &ti);

	ti.small32range = 1999999999;
	ti.full32range = 2147483647 - 1;
	ti.unsigned32 = 4294967295UL - 1;
	ti.unsplit32 = 4294967290UL - 1;
	verify(6, &ti);

	return 0;
}
