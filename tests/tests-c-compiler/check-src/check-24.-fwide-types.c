#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>

uint8_t buf1[] = {
	32 | ((2 << 6) + 5),	/* [5], constructed */
	17,	/* L */
	32 | 16,		/* [UNIVERSAL 16], constructed */
	15,	/* L */
	/* INTEGER a */
	2,			/* [UNIVERSAL 2] */
	2,	/* L */
  150,
  70,
	/* INTEGER b */
	((2 << 6) + 0),		/* [0] */
	1,	/* L */
  123,
	/* INTEGER c */
	((2 << 6) + 1),		/* [1] */
	1,	/* L */
  123,
	/* INTEGER d */
	32 | ((2 << 6) + 5),	/* [5], constructed */
	3,
	2,
	1,	/* L */
  123,
};

static void
check(int is_ok, uint8_t *buf, size_t size, size_t consumed) {
	T_t t, *tp;
	asn_dec_rval_t rval;

	tp = memset(&t, 0, sizeof(t));

	fprintf(stderr, "Buf %p\n", buf);
	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %zd\n",
		(int)rval.code, rval.consumed);

	if(is_ok) {
		assert(rval.code == RC_OK);
		assert(rval.consumed == consumed);
	} else {
		if(rval.code == RC_OK) {
			assert(t.a.size != 2
				|| (!t.b || t.b->size != 1)
				|| (!t.c || t.c->size != 1)
				|| t.d.size != 1
			);
		}
		assert(rval.consumed <= consumed);
	}

	ASN_STRUCT_RESET(asn_DEF_T, tp);
}

static void
try_corrupt(uint8_t *buf, size_t size) {
	uint8_t tmp[size];

	fprintf(stderr, "\nCorrupting...\n");

	for(int i = 0; i < 1000; i++) {
		int loc;
		memcpy(tmp, buf, size);

		/* Corrupt random _non-value_ location. */
		do { loc = random() % size; } while(tmp[loc] >= 70);
		do { tmp[loc] ^= random(); } while(tmp[loc] == buf[loc]);

		fprintf(stderr, "\nTry %d: corrupting byte %d (%d->%d)\n",
			i, loc, buf[loc], tmp[loc]);

		check(0, tmp, size, size);
	}
}

int
main(int ac, char **av) {

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	check(1, buf1, sizeof(buf1), sizeof(buf1));
	try_corrupt(buf1, sizeof(buf1));

	return 0;
}
