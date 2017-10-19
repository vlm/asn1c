#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>


uint8_t buf1[] = {
	32 | (2 << 6),		/* [0], constructed */
	25,	/* L */

	/* string   [0] IMPLICIT UTF8String, */
	(2 << 6),			/* [0] */
	16,	/* L */
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',

	/* beta    [2] IMPLICIT INTEGER OPTIONAL */
	(2 << 6) + 2,			/* [2] */
	5,	/* L */
  0,
  75,
  0x4b,
  75,
  75,
};

uint8_t buf1_reconstr[] = {
	32 | (2 << 6),		/* [0], constructed */
	24,	/* L */

	/* string   [0] IMPLICIT UTF8String, */
	(2 << 6),			/* [0] */
	16,	/* L */
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',

	/* beta    [2] IMPLICIT INTEGER OPTIONAL */
	(2 << 6) + 2,			/* [2] */
	4,	/* L */
  75,
  75,
  75,
  0x4b,
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

	assert(tp->choice.seq.string.size == 16);
	assert(strcmp((char *)tp->choice.seq.string.buf, "zzzzzzzzzzzzzzzz") == 0);
	assert(tp->choice.seq.alpha == NULL);
	assert(tp->choice.seq.beta);
	assert(*tp->choice.seq.beta == 0x4b4b4b4b);
}

size_t buf_pos;
size_t buf_size;
uint8_t *buf;

static int
buf_fill(const void *buffer, size_t size, void *app_key) {

	(void)app_key;	/* Unused argument */

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

	buf_size = cmp_buf_size + 100;
    uint8_t scratch[buf_size];
	buf = scratch;
	buf_pos = 0;

	/*
	 * Try to re-create using DER encoding.
	 */
	erval = der_encode(&asn_DEF_T, tp, buf_fill, 0);
	assert(erval.encoded != -1);
	if((size_t)erval.encoded != cmp_buf_size) {
		printf("%zd != %zd\n", erval.encoded, cmp_buf_size);
        assert((size_t)erval.encoded == cmp_buf_size);
    }
	for(size_t i = 0; i < cmp_buf_size; i++) {
		if(buf[i] != cmp_buf[i]) {
			fprintf(stderr, "Recreated buffer content mismatch:\n");
			fprintf(stderr, "Byte %zd, %x != %x (%d != %d)\n",
				i,
				buf[i], cmp_buf[i],
				buf[i], cmp_buf[i]
			);
		}
		assert(buf[i] == cmp_buf[i]);
	}

    buf = 0;
}

static void
partial_read(uint8_t *buf_0, size_t size) {
	T_t t, *tp;
	asn_dec_rval_t rval;
	uint8_t buf_1[size];
	uint8_t buf_2[size];
	uint8_t buf_3[size];

	fprintf(stderr, "\nPartial read sequence...\n");

	/*
	 * Divide the space (size) into three blocks in various combinations:
	 *   |<----->i1<----->i2<----->|
	 *   ^ buf_0                    ^ buf_0+size
	 * Try to read block by block.
	 */
	for(size_t i1 = 0; i1 < size; i1++) {
		for(size_t i2 = i1; i2 < size; i2++) {
			uint8_t *chunk1 = buf_0;
			size_t size1 = i1;
			uint8_t *chunk2 = buf_0 + size1;
			size_t size2 = i2 - i1;
			uint8_t *chunk3 = buf_0 + size1 + size2;
			size_t size3 = size - size1 - size2;

			fprintf(stderr, "\n%zd:{%zd, %zd, %zd}...\n",
				size, size1, size2, size3);

			memset(buf_1, 0, size);
			memset(buf_2, 0, size);
			memset(buf_3, 0, size);
			memcpy(buf_1, chunk1, size1);
			memcpy(buf_2, chunk2, size2);
			memcpy(buf_3, chunk3, size3);

			tp = memset(&t, 0, sizeof(t));

			fprintf(stderr, "=> Chunk 1 (%zd):\n", size1);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				buf_1, size1);
			assert(rval.code == RC_WMORE);
			assert(rval.consumed <= size1);
			if(rval.consumed < size1) {
				int leftover = size1 - rval.consumed;
				memcpy(buf_2, buf_1 + rval.consumed, leftover);
				memcpy(buf_2 + leftover, chunk2, size2);
				size2 += leftover;
			}

			fprintf(stderr, "=> Chunk 2 (%zd):\n", size2);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				buf_2, size2);
			assert(rval.code == RC_WMORE);
			assert(rval.consumed <= size2);
			if(rval.consumed < size2) {
				int leftover = size2 - rval.consumed;
				memcpy(buf_3, buf_2 + rval.consumed, leftover);
				memcpy(buf_3 + leftover, chunk3, size3);
				size3 += leftover;
			}

			fprintf(stderr, "=> Chunk 3 (%zd):\n", size3);
			rval = ber_decode(0, &asn_DEF_T, (void **)&tp,
				buf_3, size3);
			assert(rval.code == RC_OK);
			assert(rval.consumed == size3);

			ASN_STRUCT_RESET(asn_DEF_T, &t);
		}
	}
}

int
main(int ac, char **av) {
	T_t t;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	/* Check exact buf1 */
	check(&t, buf1, sizeof(buf1), sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	asn_fprint(stderr, &asn_DEF_T, &t);
	ASN_STRUCT_RESET(asn_DEF_T, &t);

	/* Check slightly more than buf1 */
	check(&t, buf1, sizeof(buf1) + 10, sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	asn_fprint(stderr, &asn_DEF_T, &t);
	ASN_STRUCT_RESET(asn_DEF_T, &t);

	/* Split the buffer in parts and check decoder restartability */
	partial_read(buf1, sizeof(buf1));

	return 0;
}
