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
check(T_t *tp, uint8_t *buf, size_t size, size_t consumed) {
	asn_dec_rval_t rval;

	tp = memset(tp, 0, sizeof(*tp));

	fprintf(stderr, "Buf %p (%zd)\n", buf, size);
	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %zd\n",
		(int)rval.code, rval.consumed);

	assert(rval.code == RC_OK);
	assert(rval.consumed == consumed);

	assert(strcmp((char *)tp->a.buf, "=<&>") == 0);
	assert(strcmp((char *)tp->b.choice.b1.buf, "z") == 0
		&& strcmp((char *)tp->b.choice.b2.buf, "z") == 0);

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
		fprintf(stderr, "%zd + %zd > %zd\n",
			buf_pos, size, buf_size);
		return -1;
	}

	memcpy(buf + buf_pos, buffer, size);
	buf_pos += size;
	fprintf(stderr, "   written %zd (%zd)\n", size, buf_pos);

	return 0;
}

static void
compare(T_t *tp, uint8_t *cmp_buf, size_t cmp_buf_size) {
	asn_enc_rval_t erval;
	size_t i;

	buf_size = cmp_buf_size + 100;
    uint8_t scratch[buf_size];
	buf = scratch;
	buf_pos = 0;

	/*
	 * Try to re-create using DER encoding.
	 */
	erval = der_encode(&asn_DEF_T, tp, buf_fill, 0);
	assert(erval.encoded != -1);
	if(erval.encoded != (ssize_t)cmp_buf_size) {
		printf("%zd != %zd\n", erval.encoded, cmp_buf_size);
	}
	assert(erval.encoded == (ssize_t)cmp_buf_size);
	for(i = 0; i < cmp_buf_size; i++) {
		if(buf[i] != cmp_buf[i]) {
			fprintf(stderr, "Recreated buffer content mismatch:\n");
			fprintf(stderr, "Byte %d, %x != %x (%d != %d)\n",
				(int)i,
				buf[i], cmp_buf[i],
				buf[i], cmp_buf[i]
			);
		}
		assert(buf[i] == cmp_buf[i]);
	}
}

static void
partial_read(uint8_t *data, size_t size) {
	T_t t, *tp;
	asn_dec_rval_t rval;
	size_t i1, i2;
	uint8_t data1[size];
	uint8_t data2[size];
	uint8_t data3[size];

	fprintf(stderr, "\nPartial read sequence...\n");

	/*
	 * Divide the space (size) into three blocks in various combinations:
	 *   |<----->i1<----->i2<----->|
	 *   ^ data                  ^ data+size
	 * Try to read block by block.
	 */
	for(i1 = 0; i1 < size; i1++) {
		for(i2 = i1; i2 < size; i2++) {
			uint8_t *chunk1 = data;
			size_t size1 = i1;
			uint8_t *chunk2 = data + size1;
			size_t size2 = i2 - i1;
			uint8_t *chunk3 = data + size1 + size2;
			size_t size3 = size - size1 - size2;

			fprintf(stderr, "\n%zd:{%zd, %zd, %zd}...\n",
				size, size1, size2, size3);

			memset(data1, 0, size);
			memset(data2, 0, size);
			memset(data3, 0, size);
			memcpy(data1, chunk1, size1);
			memcpy(data2, chunk2, size2);
			memcpy(data3, chunk3, size3);

			tp = memset(&t, 0, sizeof(t));

			fprintf(stderr, "=> Chunk 1 (%zd):\n", size1);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				data1, size1);
			assert(rval.code == RC_WMORE);
			assert(rval.consumed <= size1);
			if(rval.consumed < size1) {
				int leftover = size1 - rval.consumed;
				memcpy(data2, data1 + rval.consumed, leftover);
				memcpy(data2 + leftover, chunk2, size2);
				size2 += leftover;
			}

			fprintf(stderr, "=> Chunk 2 (%zd):\n", size2);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				data2, size2);
			assert(rval.code == RC_WMORE);
			assert(rval.consumed <= size2);
			if(rval.consumed < size2) {
				int leftover = size2 - rval.consumed;
				memcpy(data3, data2 + rval.consumed, leftover);
				memcpy(data3 + leftover, chunk3, size3);
				size3 += leftover;
			}

			fprintf(stderr, "=> Chunk 3 (%zd):\n", size3);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				data3, size3);
			assert(rval.code == RC_OK);
			assert(rval.consumed == size3);

			ASN_STRUCT_RESET(asn_DEF_T, &t);
		}
	}
}

static char xer_buf[128];
static size_t xer_off;

static int
xer_cb(const void *buffer, size_t size, void *key) {
	(void)key;
	assert(xer_off + size < sizeof(xer_buf));
	memcpy(xer_buf + xer_off, buffer, size);
	xer_off += size;
	return 0;
}

static void
check_xer(uint8_t *data, uint8_t size, char *xer_sample) {
	T_t *tp = 0;
	asn_dec_rval_t rval;
	asn_enc_rval_t er;
	size_t xer_sample_len = strlen(xer_sample);

	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, data, size);
	assert(rval.code == RC_OK);
	assert(rval.consumed == size);
	assert(tp);

	xer_off = 0;
	er = xer_encode(&asn_DEF_T, tp, XER_F_CANONICAL, xer_cb, 0);
	assert(xer_off);
	xer_buf[xer_off] = 0;
	printf("[%s] (%zd/%zd) vs [%s] (%zd)\n",
		xer_buf, er.encoded, xer_off, xer_sample, xer_sample_len);
	assert(er.encoded == (ssize_t)xer_off);
	assert(xer_off == xer_sample_len);
	assert(memcmp(xer_buf, xer_sample, xer_off) == 0);

	ASN_STRUCT_FREE(asn_DEF_T, tp);
}


int
main(int ac, char **av) {
	T_t t;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	check(&t, buf1, sizeof(buf1) + 10, sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	ASN_STRUCT_RESET(asn_DEF_T, &t);
	check_xer(buf1, sizeof(buf1), "<T><c><false/></c><b><b2>z</b2></b><a>=&lt;&amp;&gt;</a><d><r-oid>85.79</r-oid></d></T>");

	check(&t, buf2, sizeof(buf2) + 10, sizeof(buf2));
	compare(&t, buf2_reconstr, sizeof(buf2_reconstr));
	ASN_STRUCT_RESET(asn_DEF_T, &t);
	check_xer(buf2, sizeof(buf2), "<T><c><true/></c><b><b1>z</b1></b><a>=&lt;&amp;&gt;</a><d><oid>2.1</oid></d></T>");

	/* Split the buffer in parts and check decoder restartability */
	partial_read(buf1, sizeof(buf1));

	return 0;
}
