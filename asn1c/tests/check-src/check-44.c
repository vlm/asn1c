#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>

uint8_t buf1[] = {
	32 | ((3 << 6) + 1),	/* [PRIVATE 1], constructed */
	4,	/* L */
	((3 << 6) + 2),		/* [PRIVATE 2], primitive */
	0,	/* L */
	((3 << 6) + 5),		/* [PRIVATE 5], primitive */
	0,	/* L */
};

uint8_t buf2[] = {
	32 | ((3 << 6) + 1),	/* [PRIVATE 1], constructed */
	6,	/* L */
	((3 << 6) + 2),		/* [PRIVATE 2], primitive */
	0,	/* L */
	32 | ((3 << 6) + 9),	/* [PRIVATE 9], constructed */
	2,
	((3 << 6) + 1),		/* [PRIVATE 1], primitive */
	0,	/* L */
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
		}
		assert(rval.consumed <= consumed);
	}
}

int
main(int ac, char **av) {

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	check(1, buf1, sizeof(buf1), sizeof(buf1));
	check(0, buf1, sizeof(buf1) - 1, sizeof(buf1) - 1);
	check(0, buf1, sizeof(buf1) - 2, sizeof(buf1) - 2);

	check(1, buf2, sizeof(buf2), sizeof(buf2));
	check(0, buf2, sizeof(buf2) - 1, sizeof(buf2));

	return 0;
}
