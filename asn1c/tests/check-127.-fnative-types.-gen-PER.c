#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>

#include <T.h>

void
verify(T_t *ti) {
	asn_enc_rval_t er;
	asn_dec_rval_t rv;
	unsigned char buf[8];
	T_t *to = 0;

	fprintf(stderr, "IN: { %ld, %ld }\n",
		ti->small32range, ti->full32range);

	er = uper_encode_to_buffer(&asn_DEF_T, ti, buf, sizeof buf);
	assert(er.encoded == 64);

	rv = uper_decode(0, &asn_DEF_T, (void *)&to, buf, sizeof buf, 0, 0);
	assert(rv.code == RC_OK);

	fprintf(stderr, "ENC: %2x%2x%2x%2x %2x%2x%2x%2x\n",
		buf[0], buf[1], buf[2], buf[3],
		buf[4], buf[5], buf[6], buf[7]);
	fprintf(stderr, "OUT: { %ld, %ld } vs { %ld, %ld }\n",
		ti->small32range, ti->full32range,
		to->small32range, to->full32range);
	assert(ti->small32range == to->small32range);
	assert(ti->full32range == to->full32range);

	xer_fprint(stderr, &asn_DEF_T, ti);
	xer_fprint(stderr, &asn_DEF_T, to);
}

int main() {
	T_t ti;

	ti.small32range = 0;
	ti.full32range = 0;
	verify(&ti);

	ti.small32range = -1;
	ti.full32range = -1;
	verify(&ti);

	ti.small32range = -2000000000;
	ti.full32range = (-2147483647L - 1);
	verify(&ti);

	ti.small32range = -1999999999;
	ti.full32range = (-2147483647L);
	verify(&ti);

	ti.small32range = 2000000000;
	ti.full32range = 2147483647;
	verify(&ti);

	ti.small32range = 1999999999;
	ti.full32range = 2147483647 - 1;
	verify(&ti);

	return 0;
}
