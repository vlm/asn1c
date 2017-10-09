#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <Forest.h>

uint8_t buf1[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	128,	/* L, indefinite */

	32 | 16,		/* [UNIVERSAL 16], constructed */
	6,	/* L */

	/* height INTEGER */
	2,			/* [UNIVERSAL 2] */
	1,	/* L */
  100,
	/* width INTEGER */
	2,			/* [UNIVERSAL 2] */
	1,	/* L */
  80,

	32 | 16,		/* [UNIVERSAL 16], constructed */
	6,	/* L */

	/* height INTEGER */
	2,			/* [UNIVERSAL 2] */
	1,	/* L */
  110,
	/* width INTEGER */
	2,			/* [UNIVERSAL 2] */
	1,	/* L */
  82,

	0,	/* End of forest */
	0
};

uint8_t buf1_reconstr[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	16,	/* L */

	32 | 16,		/* [UNIVERSAL 16], constructed */
	6,	/* L */

	/* height INTEGER */
	2,			/* [UNIVERSAL 2] */
	1,	/* L */
  100,
	/* width INTEGER */
	2,			/* [UNIVERSAL 2] */
	1,	/* L */
  80,

	32 | 16,		/* [UNIVERSAL 16], constructed */
	6,	/* L */

	/* height INTEGER */
	2,			/* [UNIVERSAL 2] */
	1,	/* L */
  110,
	/* width INTEGER */
	2,			/* [UNIVERSAL 2] */
	1,	/* L */
  82

};

size_t buf_pos;
static int bytes_compare(const void *bufferp, size_t size, void *key) {
	const uint8_t *buffer = bufferp;
	assert(buf_pos + size <= sizeof(buf1_reconstr));

	(void)key;	/* Unused argument */

	fprintf(stderr,  "  writing %zd (%zd)\n", size, buf_pos + size);

	for(; size; buf_pos++, size--, buffer++) {
		if(buf1_reconstr[buf_pos] != *buffer) {
			fprintf(stderr,
				"Byte %zd is different: %d != %d (%x != %x)\n",
				buf_pos,
				*buffer, buf1_reconstr[buf_pos],
				*buffer, buf1_reconstr[buf_pos]
			);
			assert(buf1_reconstr[buf_pos] == *buffer);
		}
	}

	return 0;
}

static void
check(int is_ok, uint8_t *buf, size_t size, size_t consumed) {
	Forest_t t, *tp;
	asn_dec_rval_t rval;

	tp = memset(&t, 0, sizeof(t));

	fprintf(stderr, "Buf %p\n", buf);
	rval = ber_decode(0, &asn_DEF_Forest, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %d\n",
		(int)rval.code, (int)rval.consumed);

	if(is_ok) {
		assert(rval.code == RC_OK);
		assert(rval.consumed == consumed);

		assert(t.list.count == 2);
		assert(t.list.array[0]->height.size == 1);
		assert(t.list.array[0]->width.size == 1);
		assert(t.list.array[1]->height.size == 1);
		assert(t.list.array[1]->width.size == 1);
	} else {
		if(rval.code == RC_OK) {
			assert(t.list.count != 2
			|| t.list.array[0]->height.size != 1
			|| t.list.array[0]->width.size != 1
			|| t.list.array[1]->height.size != 1
			|| t.list.array[1]->width.size != 1
			);
		}
		assert(rval.consumed <= consumed);
		ASN_STRUCT_RESET(asn_DEF_Forest, &t);
		return;
	}

	/*
	 * Try to re-create the buffer.
	 */
	buf_pos = 0;
	der_encode(&asn_DEF_Forest, &t,
		bytes_compare, buf1_reconstr);
	assert(buf_pos == (ssize_t)sizeof(buf1_reconstr));

	asn_fprint(stderr, &asn_DEF_Forest, &t);
	xer_fprint(stderr, &asn_DEF_Forest, &t);

	ASN_STRUCT_RESET(asn_DEF_Forest, &t);
}

static char xer_buf[512];
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
	Forest_t *tp = 0;
	asn_dec_rval_t rval;
	asn_enc_rval_t er;
	int xer_sample_len = strlen(xer_sample);

	rval = ber_decode(0, &asn_DEF_Forest, (void **)&tp, buf, size);
	assert(rval.code == RC_OK);
	assert(rval.consumed == size);
	assert(tp);

	xer_off = 0;
	er = xer_encode(&asn_DEF_Forest, tp, XER_F_CANONICAL, xer_cb, 0);
	assert(er.encoded == xer_off);
	assert(xer_off);
	xer_buf[xer_off] = 0;
	printf("[%s] vs [%s]\n", xer_buf, xer_sample);
	assert(xer_off == xer_sample_len);
	assert(memcmp(xer_buf, xer_sample, xer_off) == 0);

	ASN_STRUCT_FREE(asn_DEF_Forest, tp);
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

	check(1, buf1, sizeof(buf1), sizeof(buf1));
	check_xer(buf1, sizeof(buf1), "<Forest><Tree><height>100</height><width>80</width></Tree><Tree><height>110</height><width>82</width></Tree></Forest>");
	try_corrupt(buf1, sizeof(buf1));
	check(1, buf1, sizeof(buf1) + 20, sizeof(buf1));

	return 0;
}
