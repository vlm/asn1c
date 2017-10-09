#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>


/*
 * Test that the optional member (c) is really optional.
 */
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

/*
 * This buffer checks that an unexpected member may be properly ignored.
 */
uint8_t buf3[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	14,	/* L */

	/* INTEGER */
	64 | 3,			/* [APPLICATION 3] */
	1,	/* L */
  96,

	/* IA5String */
	22,			/* [UNIVERSAL 22] */
	3,	/* L */
	'x',
	'y',
	'z',

	/* unexpected INTEGER */
	64 | 4,			/* [APPLICATION 4] */
	1,	/* L */
  96,

	/* [2] BOOLEAN */
	((2 << 6) + 2),			/* [2] */
	1,	/* L */
	0xff
};

/*
 * This buffer checks that an unexpected member may be properly ignored.
 * This time, with indefinite length encoding.
 */
uint8_t buf4[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	16,	/* L */

	/* a INTEGER */
	64 | 3,			/* [APPLICATION 3] */
	1,	/* L */
  96,

	/* b IA5String */
	22,			/* [UNIVERSAL 22] */
	3,	/* L */
	'x',
	'y',
	'z',

	/* unexpected data structure */
	32 | 64 | 4,			/* [APPLICATION 4] */
	0x80,	/* indefinite L */
	64 | 1,			/* [APPLICATION 1] */
	2,	/* L */
	'a', 'b',

	0x00,
	0x00
};

/*
 * This buffer checks that an unexpected member may be properly ignored.
 * This time, with indefinite length encoding at the outer level too.
 */
uint8_t buf5[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	0x80,	/* indefinite L */

	/* INTEGER */
	64 | 3,			/* [APPLICATION 3] */
	1,	/* L */
  96,

	/* IA5String */
	22,			/* [UNIVERSAL 22] */
	3,	/* L */
	'x',
	'y',
	'z',

	/* unexpected data structure */
	32 | 64 | 4,			/* [APPLICATION 4] */
	0x80,	/* indefinite L */
	64 | 1,			/* [APPLICATION 1] */
	2,	/* L */
	'a', 'b',

	0x00,
	0x00,

	0x00,
	0x00
};

static void
check(int is_ok, uint8_t *buf, size_t size, size_t consumed) {
	T_t t, *tp;
	asn_dec_rval_t rval;

	fprintf(stderr, "\nMust %s:\n", is_ok?"suceed":"fail");

	tp = memset(&t, 0, sizeof(t));

	fprintf(stderr, "Buf %p\n", buf);
	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %zd (out of %zd)\n",
		(int)rval.code, rval.consumed, size);

	if(is_ok) {
		assert(rval.code == RC_OK);
		assert(rval.consumed == consumed);

		assert(t.i.size == 1);
		assert(t.i.buf[0] == 96);
		assert(t.s.size == 3);
		assert(strcmp((char *)t.s.buf, "xyz") == 0);
		if(buf == buf3) {
			assert(t.b);
		} else {
			assert(t.b == 0);
		}
	} else {
		if(rval.code == RC_OK) {
			assert(t.i.size != 1
			|| t.s.size != 3
			|| !t.b
			);
		}
		assert(rval.consumed <= consumed);
	}
	ASN_STRUCT_RESET(asn_DEF_T, tp);
}


static char xer_buf[128];
static int xer_off;

static int
xer_cb(const void *buffer, size_t size, void *key) {
	(void)key;
	assert(xer_off + size < sizeof(xer_buf));
	memcpy(xer_buf + xer_off, buffer, size);
	xer_off += size;
	return 0;
}

static void
check_xer(uint8_t *buf, uint8_t size, char *xer_sample) {
	T_t *tp = 0;
	asn_dec_rval_t rval;
	asn_enc_rval_t er;
	int xer_sample_len = strlen(xer_sample);

	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, buf, size);
	assert(rval.code == RC_OK);
	assert(rval.consumed == size);
	assert(tp);

	xer_off = 0;
	er = xer_encode(&asn_DEF_T, tp, XER_F_CANONICAL, xer_cb, 0);
	assert(er.encoded == xer_off);
	assert(xer_off);
	xer_buf[xer_off] = 0;
	printf("[%s] vs [%s]\n", xer_buf, xer_sample);
	assert(xer_off == xer_sample_len);
	assert(memcmp(xer_buf, xer_sample, xer_off) == 0);

	ASN_STRUCT_FREE(asn_DEF_T, tp);
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

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	check(1, buf1, sizeof(buf1) + 20, sizeof(buf1));
	check(0, buf2, sizeof(buf2) + 1, 5);
	check(1, buf3, sizeof(buf3) + 1, sizeof(buf3));
	check(1, buf4, sizeof(buf4), sizeof(buf4));
	check(1, buf5, sizeof(buf5), sizeof(buf5));
	check(1, buf5, sizeof(buf5) + 1, sizeof(buf5));
	check(0, buf5, sizeof(buf5) - 1, sizeof(buf5));

	check_xer(buf1, sizeof(buf1), "<T><s>xyz</s><i>96</i></T>");
	check_xer(buf3, sizeof(buf3), "<T><s>xyz</s><i>96</i><b><true/></b></T>");

	fprintf(stderr, "\nPseudo-random buffer corruptions must fail\n");
	try_corrupt(buf1, sizeof(buf1));

	return 0;
}
