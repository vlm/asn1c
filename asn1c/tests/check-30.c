#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>

uint8_t buf1[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	8,	/* L */

	/* a INTEGER */
	64 | 3,			/* [APPLICATION 3] */
	1,	/* L */
  96,

	/* b IA5String */
	22,			/* [UNIVERSAL 22] */
	3,	/* L */
	'x',
	'y',
	'z'
};

/*
 * This buffer aims at checking the duplication.
 */
uint8_t buf2[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	8,	/* L */

	/* a INTEGER */
	64 | 3,			/* [APPLICATION 3] */
	1,	/* L */
  96,

	/* a INTEGER _again_ */
	64 | 3,			/* [APPLICATION 3] */
	1,	/* L */
  97,
};

static void
check(int is_ok, uint8_t *buf, int size, int consumed) {
	T_t t, *tp;
	ber_dec_rval_t rval;

	tp = memset(&t, 0, sizeof(t));

	fprintf(stderr, "Buf %p\n", buf);
	rval = ber_decode(&asn1_DEF_T, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %d\n",
		(int)rval.code, (int)rval.consumed);

	if(is_ok) {
		assert(rval.code == RC_OK);
		assert(rval.consumed == consumed);

		assert(t.a.size == 1);
		assert(t.a.buf[0] == 96);
		assert(t.b.size == 3);
		assert(t.c == 0);
		assert(strcmp(t.b.buf, "xyz") == 0);
	} else {
		if(rval.code == RC_OK) {
			assert(t.a.size != 1
			|| t.b.size != 3
			|| !t.c
			);
		}
		assert(rval.consumed <= consumed);
	}
}

static void
try_corrupt(uint8_t *buf, int size) {
	uint8_t *tmp;
	int i;

	fprintf(stderr, "\nCorrupting...\n");

	tmp = alloca(size);

	for(i = 0; i < 1000; i++) {
		int loc;
		memcpy(tmp, buf, size);

		/* Corrupt random _non-value_ location. */
		do { loc = random() % size; } while(tmp[loc] >= 70);
		do { tmp[loc] = buf[loc] ^ random(); } while(
			(tmp[loc] == buf[loc])
			|| (buf[loc] == 0 && tmp[loc] == 0x80));

		fprintf(stderr, "\nTry %d: corrupting byte %d (%d->%d)\n",
			i, loc, buf[loc], tmp[loc]);

		check(0, tmp, size, size);
	}
}

int
main(int ac, char **av) {

	fprintf(stderr, "Must succeed:\n");
	check(1, buf1, sizeof(buf1) + 20, sizeof(buf1));

	fprintf(stderr, "\nMust fail:\n");
	check(0, buf2, sizeof(buf2) + 1, 5);

	fprintf(stderr, "\nPseudo-random buffer corruptions must fail\n");
	try_corrupt(buf1, sizeof(buf1));

	return 0;
}
