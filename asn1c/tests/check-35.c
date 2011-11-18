#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>

uint8_t buf1[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	15,	/* L */

	/* b CHOICE { b2 ObjectDescriptor }*/
	7,			/* [UNIVERSAL 7] */
	1,	/* L */
  'z',

	/* c BOOLEAN */
	1,			/* [UNIVERSAL 1] */
	0,	/* L */

	/* a NumericString */
	18,			/* [UNIVERSAL 18] */
	4,	/* L */
  '=',
  '<',
  '&',
  '>',

	/* d.r-oid RELATIVE-OID */
	13,			/* [UNIVERSAL 13] */
	2,	/* L */
  85,
  79,

};

uint8_t buf1_reconstr[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	16,	/* L */

	/* c BOOLEAN */
	1,			/* [UNIVERSAL 1] */
	1,	/* L */
	0,

	/* b CHOICE { b2 ObjectDescriptor }*/
	7,			/* [UNIVERSAL 7] */
	1,	/* L */
  'z',

	/* d.r-oid RELATIVE-OID */
	13,			/* [UNIVERSAL 1] */
	2,	/* L */
  85,
  79,

	/* a NumericString */
	18,			/* [UNIVERSAL 18] */
	4,	/* L */
  '=',
  '<',
  '&',
  '>',
};

uint8_t buf2[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	15,	/* L */

	/* a NumericString */
	18,			/* [UNIVERSAL 18] */
	4,	/* L */
  '=',
  '<',
  '&',
  '>',

	/* c BOOLEAN */
	1,			/* [UNIVERSAL 1] */
	1,	/* L */
	2,	/* True */

	/* b CHOICE { b1 IA5String }*/
	22,			/* [UNIVERSAL 22] */
	1,	/* L */
  'z',

	/* d.oid RELATIVE-OID */
	6,			/* [UNIVERSAL 6] */
	1,	/* L */
  81,

};

uint8_t buf2_reconstr[] = {
	32 | 17,		/* [UNIVERSAL 17], constructed */
	15,	/* L */

	/* c BOOLEAN */
	1,			/* [UNIVERSAL 1] */
	1,	/* L */
	0xff,	/* Canonical True */

	/* d.oid RELATIVE-OID */
	6,			/* [UNIVERSAL 6] */
	1,	/* L */
  81,

	/* a NumericString */
	18,			/* [UNIVERSAL 18] */
	4,	/* L */
  '=',
  '<',
  '&',
  '>',

	/* b CHOICE { b1 IA5String }*/
	22,			/* [UNIVERSAL 22] */
	1,	/* L */
  'z'
};

static void
check(T_t *tp, uint8_t *checkbuf, int size, size_t consumed) {
	asn_dec_rval_t rval;

	tp = memset(tp, 0, sizeof(*tp));

	fprintf(stderr, "Buf %p (%d)\n", checkbuf, (int)size);
	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, checkbuf, size);
	fprintf(stderr, "Returned code %d, consumed %d\n",
		(int)rval.code, (int)rval.consumed);

	assert(rval.code == RC_OK);
	assert(rval.consumed == consumed);

	assert(strcmp((char*)tp->a.buf, "=<&>") == 0);
	assert(strcmp((char*)tp->b.choice.b1.buf, "z") == 0
		&& strcmp((char*)tp->b.choice.b2.buf, "z") == 0);

	asn_fprint(stderr, &asn_DEF_T, tp);
	xer_fprint(stderr, &asn_DEF_T, tp);
}

size_t buf_pos;
size_t buf_size;
uint8_t *buf;

static int
buf_fill(const void *buffer, size_t size, void *app_key) {

	(void)app_key;

	if(buf_pos + size > buf_size) {
		fprintf(stderr, "%d + %d > %d\n",
			(int)buf_pos, (int)size, (int)buf_size);
		return -1;
	}

	memcpy(buf + buf_pos, buffer, size);
	buf_pos += size;
	fprintf(stderr, "   written %d (%d)\n", (int)size, (int)buf_pos);

	return 0;
}

static void
compare(T_t *tp, uint8_t *cmp_buf, int cmp_buf_size) {
	asn_enc_rval_t erval;
	int i;

	buf_size = cmp_buf_size + 100;
	buf = alloca(buf_size);
	buf_pos = 0;

	/*
	 * Try to re-create using DER encoding.
	 */
	erval = der_encode(&asn_DEF_T, tp, buf_fill, 0);
	assert(erval.encoded != -1);
	if(erval.encoded != cmp_buf_size) {
		printf("%lld != %d\n", (long long)erval.encoded, cmp_buf_size);
	}
	assert(erval.encoded == cmp_buf_size);
	for(i = 0; i < cmp_buf_size; i++) {
		if(buf[i] != cmp_buf[i]) {
			fprintf(stderr, "Recreated buffer content mismatch:\n");
			fprintf(stderr, "Byte %d, %x != %x (%d != %d)\n",
				i,
				buf[i], cmp_buf[i],
				buf[i], cmp_buf[i]
			);
		}
		assert(buf[i] == cmp_buf[i]);
	}
}

static void
partial_read(uint8_t *mybuf, size_t size) {
	T_t t, *tp;
	asn_dec_rval_t rval;
	size_t i1, i2;
	uint8_t *partialbuf1 = alloca(size);
	uint8_t *partialbuf2 = alloca(size);
	uint8_t *partialbuf3 = alloca(size);

	fprintf(stderr, "\nPartial read sequence...\n");

	/*
	 * Divide the space (size) into three blocks in various combinations:
	 *   |<----->i1<----->i2<----->|
	 *   ^ mybuf		     ^ mybuf+size
	 * Try to read block by block.
	 */
	for(i1 = 0; i1 < size; i1++) {
		for(i2 = i1; i2 < size; i2++) {
			uint8_t *chunk1 = mybuf;
			size_t size1 = i1;
			uint8_t *chunk2 = mybuf + size1;
			size_t size2 = i2 - i1;
			uint8_t *chunk3 = mybuf + size1 + size2;
			size_t size3 = size - size1 - size2;

			fprintf(stderr, "\n%d:{%d, %d, %d}...\n",
				(int)size, (int)size1, (int)size2, (int)size3);

			memset(partialbuf1, 0, size);
			memset(partialbuf2, 0, size);
			memset(partialbuf3, 0, size);
			memcpy(partialbuf1, chunk1, size1);
			memcpy(partialbuf2, chunk2, size2);
			memcpy(partialbuf3, chunk3, size3);

			tp = memset(&t, 0, sizeof(t));

			fprintf(stderr, "=> Chunk 1 (%d):\n", (int)size1);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				partialbuf1, size1);
			assert(rval.code == RC_WMORE);
			assert(rval.consumed <= size1);
			if(rval.consumed < size1) {
				int leftover = size1 - rval.consumed;
				memcpy(partialbuf2, partialbuf1 + rval.consumed, leftover);
				memcpy(partialbuf2 + leftover, chunk2, size2);
				size2 += leftover;
			}

			fprintf(stderr, "=> Chunk 2 (%d):\n", (int)size2);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				partialbuf2, size2);
			assert(rval.code == RC_WMORE);
			assert(rval.consumed <= size2);
			if(rval.consumed < size2) {
				int leftover = size2 - rval.consumed;
				memcpy(partialbuf3, partialbuf2 + rval.consumed, leftover);
				memcpy(partialbuf3 + leftover, chunk3, size3);
				size3 += leftover;
			}

			fprintf(stderr, "=> Chunk 3 (%d):\n", (int)size3);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				partialbuf3, size3);
			assert(rval.code == RC_OK);
			assert(rval.consumed == size3);

			asn_DEF_T.free_struct(&asn_DEF_T, &t, 1);
		}
	}
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
check_xer(uint8_t *mybuf, uint8_t size, char *xer_sample) {
	T_t *tp = 0;
	asn_dec_rval_t rval;
	asn_enc_rval_t er;
	int xer_sample_len = strlen(xer_sample);

	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, mybuf, size);
	assert(rval.code == RC_OK);
	assert(rval.consumed == size);
	assert(tp);

	xer_off = 0;
	er = xer_encode(&asn_DEF_T, tp, XER_F_CANONICAL, xer_cb, 0);
	assert(xer_off);
	xer_buf[xer_off] = 0;
	printf("[%s] (%lld/%d) vs [%s] (%d)\n",
		xer_buf, (long long)er.encoded, xer_off, xer_sample, xer_sample_len);
	assert(er.encoded == xer_off);
	assert(xer_off == xer_sample_len);
	assert(memcmp(xer_buf, xer_sample, xer_off) == 0);
}


int
main(int ac, char **av) {
	T_t t;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	check(&t, buf1, sizeof(buf1) + 10, sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	asn_DEF_T.free_struct(&asn_DEF_T, &t, 1);
	check_xer(buf1, sizeof(buf1), "<T><c><false/></c><b><b2>z</b2></b><a>=&lt;&amp;&gt;</a><d><r-oid>85.79</r-oid></d></T>");

	check(&t, buf2, sizeof(buf2) + 10, sizeof(buf2));
	compare(&t, buf2_reconstr, sizeof(buf2_reconstr));
	asn_DEF_T.free_struct(&asn_DEF_T, &t, 1);
	check_xer(buf2, sizeof(buf2), "<T><c><true/></c><b><b1>z</b1></b><a>=&lt;&amp;&gt;</a><d><oid>2.1</oid></d></T>");

	/* Split the buffer in parts and check decoder restartability */
	partial_read(buf1, sizeof(buf1));

	return 0;
}
