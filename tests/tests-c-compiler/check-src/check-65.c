#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>
#include <T1.h>

uint8_t buf1[] = {
	32 | ((2 << 6) + 2),	/* [2], constructed */
	6,
	32 | ((2 << 6) + 3),	/* [3], constructed */
	4,
	32 | ((2 << 6) + 4),	/* [4], constructed */
	2,
	0  | ((2 << 6) + 6),	/* [6], primitive */
	0
};

uint8_t buf2[] = {

	32 | ((2 << 6) + 0),	/* [0], constructed */
	23,

	32 | ((2 << 6) + 1),	/* [1], constructed */
	6,
	32 | ((2 << 6) + 4),	/* [4], constructed */
	4,
	0  | ((2 << 6) + 6),	/* [6], primitive */
	2,
  0xC0,
  0x00,

	32 | ((2 << 6) + 2),	/* [2], constructed */
	6,
	32 | ((2 << 6) + 4),	/* [4], constructed */
	4,
	0  | ((2 << 6) + 6),	/* [6], primitive */
	2,
  0x80,
  0x00,

	32 | ((2 << 6) + 3),	/* [3], constructed */
	5,
	0  | ((2 << 6) + 6),	/* [6], primitive */
	3,
  0x80,
  0x01,
  0x02,
};

static void
check_1(int is_ok, uint8_t *buf, size_t size, size_t consumed) {
	asn_TYPE_descriptor_t *td = &asn_DEF_T1;
	asn_dec_rval_t rval;
	T1_t t, *tp;

	tp = memset(&t, 0, sizeof(t));

	fprintf(stderr, "Buf %p\n", buf);
	rval = ber_decode(0, td, (void **)&tp, buf, size);
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

static void
check_2(int is_ok, uint8_t *buf, size_t size, size_t consumed) {
	asn_TYPE_descriptor_t *td = &asn_DEF_T;
	asn_dec_rval_t rval;
	T_t t, *tp;

	tp = memset(&t, 0, sizeof(t));

	fprintf(stderr, "Buf %p\n", buf);
	rval = ber_decode(0, td, (void **)&tp, buf, size);
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
	ASN_STRUCT_RESET(*td, tp);
}

int
main(int ac, char **av) {

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	check_1(1, buf1, sizeof(buf1), sizeof(buf1));
	check_1(0, buf1, sizeof(buf1) - 1, sizeof(buf1) - 1);

	check_2(1, buf2, sizeof(buf2), sizeof(buf2));
	check_2(0, buf2, sizeof(buf2) - 1, sizeof(buf2) - 1);

	return 0;
}
