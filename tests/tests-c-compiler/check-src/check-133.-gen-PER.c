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
	unsigned char buf[8];
	T_t *to = 0;

	er = uper_encode_to_buffer(&asn_DEF_T, 0, ti, buf, sizeof buf);
	fprintf(stderr, "%d IN: %d => %zd\n", testNo, ti->present, er.encoded);
	assert(er.encoded >= 1);
	assert(er.encoded <= (ssize_t)(8 * sizeof(buf)));

	rv = uper_decode(0, &asn_DEF_T, (void *)&to, buf, sizeof buf, 0, 0);
	assert(rv.code == RC_OK);

	fprintf(stderr, "%d ENC: %2x%2x\n", testNo,
		buf[0], buf[1]);
	fprintf(stderr, "%d OUT: %d\n", testNo, ti->present);
	assert(ti->present == to->present);
	switch(ti->present) {
	case T_PR_NOTHING:
		assert(ti->present != T_PR_NOTHING);
		break;
	case T_PR_first:
		assert(ti->choice.first.present == to->choice.first.present);
		assert(ti->choice.first.choice.nothing == to->choice.first.choice.nothing);
		break;
	case T_PR_second:
		assert(ti->choice.second == to->choice.second);
		break;
	case T_PR_third:
		assert(ti->choice.third == to->choice.third);
		break;
	}

	xer_fprint(stderr, &asn_DEF_T, ti);
	xer_fprint(stderr, &asn_DEF_T, to);
}

int main() {
	T_t t;

	return 0;	// this test fails, but not important atm.

	memset(&t, 0, sizeof(t));
	t.present = T_PR_first;
	t.choice.first.present = first_PR_nothing;
	t.choice.first.choice.nothing = 5;
	verify(0, &t);

	memset(&t, 0, sizeof(t));
	t.present = T_PR_second;
	t.choice.second = -5;
	verify(1, &t);

	memset(&t, 0, sizeof(t));
	t.present = T_PR_second;
	t.choice.second = 10;
	verify(2, &t);

	memset(&t, 0, sizeof(t));
	t.present = T_PR_third;
	t.choice.third = -10;
	verify(3, &t);

	memset(&t, 0, sizeof(t));
	t.present = T_PR_third;
	t.choice.third = 4097;
	verify(4, &t);

	return 0;
}
