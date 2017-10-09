#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>

uint8_t buf0[] = {
	32 | ((2 << 6) + 1),		/* [1], constructed */
	18,

	/* string   [0] IMPLICIT UTF8String, */
	(2 << 6),			/* [0] */
	16,	/* L */
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
};

uint8_t buf0_reconstr[] = {
	32 | ((2 << 6) + 1),		/* [1], constructed */
	18,

	/* string   [0] IMPLICIT UTF8String, */
	(2 << 6),			/* [0] */
	16,	/* L */
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
};



uint8_t buf1[] = {
	32 | (2 << 6),		/* [0], constructed */
	0x80 | 1,	/* L */
	134,

	/* string   [0] IMPLICIT UTF8String, */
	(2 << 6),			/* [0] */
	0x80 | 1,	/* L */
	128,
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',

	/* alpha    [1] IMPLICIT INTEGER OPTIONAL */
	(2 << 6) + 1,			/* [1] */
	1,	/* L */
  75,
};

uint8_t buf1_reconstr[] = {
        32 | (2 << 6),          /* [0], constructed */
	0x80 | 1,	/* L */
	134,

        /* string   [0] IMPLICIT UTF8String, */
        (2 << 6),                       /* [0] */
        0x80 | 1,       /* L */
        128,
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',

        /* alpha    [1] IMPLICIT INTEGER OPTIONAL */
        (2 << 6) + 1,                   /* [1] */
        1,      /* L */
  75,
};

uint8_t buf2[] = {
	32 | ((2 << 6) + 1),		/* [1], constructed */
	0x80 | 1,	/* L */
	134,

	/* string   [0] IMPLICIT UTF8String, */
	(2 << 6),			/* [0] */
	0x80 | 1,	/* L */
	128,
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',

	/* beta    [2] IMPLICIT INTEGER OPTIONAL */
	(2 << 6) + 2,			/* [2] */
	1,	/* L */
  75,
};

uint8_t buf2_reconstr[] = {
        32 | ((2 << 6) + 1),          /* [1], constructed */
	0x80 | 1,	/* L */
	134,

        /* string   [0] IMPLICIT UTF8String, */
        (2 << 6),                       /* [0] */
        0x80 | 1,       /* L */
        128,
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',
 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z',

        /* beta    [2] IMPLICIT INTEGER OPTIONAL */
        (2 << 6) + 2,                   /* [2] */
        1,      /* L */
  75,
};





static void
check(T_t *tp, uint8_t *buf, size_t size, size_t consumed) {
	asn_dec_rval_t rval;
	int ret;

	tp = memset(tp, 0, sizeof(*tp));

	fprintf(stderr, "Buf %p (%zd)\n", buf, size);
	rval = ber_decode(0, &asn_DEF_T, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %zd\n",
		(int)rval.code, rval.consumed);

	assert(rval.code == RC_OK);
	assert(rval.consumed == consumed);

	fprintf(stderr, "=== asn_fprint() ===\n");
	ret = asn_fprint(stderr, &asn_DEF_T, tp);
	assert(ret == 0);
	fprintf(stderr, "=== xer_fprint() ===\n");
	ret = xer_fprint(stderr, &asn_DEF_T, tp);
	fprintf(stderr, "=== END ===\n");
	assert(ret == 0);

	/*
	assert(tp->string.size == 128);
	assert(strncmp(tp->string.buf, "zz") == 0);
	assert(strcmp((char *)tp->b.choice.b1.buf, "z") == 0
		&& strcmp((char *)tp->b.choice.b2.buf, "z") == 0);
	*/
}

size_t buf_pos;
size_t buf_size;
uint8_t *buffer;

static int
buf_fill(const void *bufp, size_t size, void *app_key) {

	(void)app_key;	/* Unused argument */

	if(buf_pos + size > buf_size) {
		fprintf(stderr, "%zd + %zd > %zd\n",
			buf_pos, size, buf_size);
		return -1;
	}

	memcpy(buffer + buf_pos, bufp, size);
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
	buffer = scratch;
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
		if(buffer[i] != cmp_buf[i]) {
			fprintf(stderr, "Recreated buffer content mismatch:\n");
			fprintf(stderr, "Byte %d, %x != %x (%d != %d)\n",
				(int)i,
				buffer[i], cmp_buf[i],
				buffer[i], cmp_buf[i]
			);
		}
		assert(buffer[i] == cmp_buf[i]);
	}

    buffer = 0;
}

static void
partial_read(uint8_t *data, size_t size) {
	T_t t, *tp;
	asn_dec_rval_t rval;
	uint8_t data1[size];
	uint8_t data2[size];
	uint8_t data3[size];

	fprintf(stderr, "\nPartial read sequence...\n");

	/*
	 * Divide the space (size) into three blocks in various combinations:
	 *   |<----->i1<----->i2<----->|
	 *   ^ data                    ^ data+size
	 * Try to read block by block.
	 */
	for(size_t i1 = 0; i1 < size; i1++) {
		for(size_t i2 = i1; i2 < size; i2++) {
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

int
main() {
	T_t t;

	/* Check exact buf0 */
	check(&t, buf0, sizeof(buf0), sizeof(buf0));
	compare(&t, buf0_reconstr, sizeof(buf0_reconstr));
	ASN_STRUCT_RESET(asn_DEF_T, &t);

	/* Check exact buf1 */
	check(&t, buf1, sizeof(buf1), sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	ASN_STRUCT_RESET(asn_DEF_T, &t);

	/* Check slightly more than buf1 */
	check(&t, buf1, sizeof(buf1) + 10, sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	ASN_STRUCT_RESET(asn_DEF_T, &t);

	/* Check exact buf2 */
	check(&t, buf2, sizeof(buf2), sizeof(buf2));
	compare(&t, buf2_reconstr, sizeof(buf2_reconstr));
	ASN_STRUCT_RESET(asn_DEF_T, &t);

	/* Check slightly more than buf2 */
	check(&t, buf2, sizeof(buf2) + 10, sizeof(buf2));
	compare(&t, buf2_reconstr, sizeof(buf2_reconstr));
	ASN_STRUCT_RESET(asn_DEF_T, &t);

	/* Split the buffer in parts and check decoder restartability */
	partial_read(buf0, sizeof(buf0));

	return 0;
}
