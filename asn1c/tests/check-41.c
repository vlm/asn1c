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
check(T_t *tp, uint8_t *buf, int size, size_t consumed) {
	ber_dec_rval_t rval;

	tp = memset(tp, 0, sizeof(*tp));

	fprintf(stderr, "Buf %p (%d)\n", buf, size);
	rval = ber_decode(&asn1_DEF_T, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %d\n",
		(int)rval.code, (int)rval.consumed);

	assert(rval.code == RC_OK);
	assert(rval.consumed == consumed);

	/*
	assert(tp->string.size == 128);
	assert(strncmp(tp->string.buf, "zz") == 0);
	assert(strcmp(tp->b.choice.b1.buf, "z") == 0
		&& strcmp(tp->b.choice.b2.buf, "z") == 0);
	*/
}

int buf_pos;
int buf_size;
uint8_t *buf;

static int
buf_fill(const void *buffer, size_t size, void *app_key) {

	if(buf_pos + size > buf_size) {
		fprintf(stderr, "%d + %d > %d\n", buf_pos, (int)size, buf_size);
		return -1;
	}

	memcpy(buf + buf_pos, buffer, size);
	buf_pos += size;
	fprintf(stderr, "   written %d (%d)\n", (int)size, buf_pos);

	return 0;
}

void
compare(T_t *tp, uint8_t *cmp_buf, int cmp_buf_size) {
	der_enc_rval_t erval;
	int i;

	buf_size = cmp_buf_size + 100;
	buf = alloca(buf_size);
	buf_pos = 0;

	/*
	 * Try to re-create using DER encoding.
	 */
	erval = der_encode(&asn1_DEF_T, tp, buf_fill, 0);
	assert(erval.encoded != -1);
	if(erval.encoded != cmp_buf_size) {
		printf("%d != %d\n", erval.encoded, cmp_buf_size);
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
partial_read(uint8_t *buf, int size) {
	T_t t, *tp;
	ber_dec_rval_t rval;
	int i1, i2;
	uint8_t *buf1 = alloca(size);
	uint8_t *buf2 = alloca(size);
	uint8_t *buf3 = alloca(size);

	fprintf(stderr, "\nPartial read sequence...\n");

	/*
	 * Divide the space (size) into three blocks in various combinations:
	 *   |<----->i1<----->i2<----->|
	 *   ^ buf                     ^ buf+size
	 * Try to read block by block.
	 */
	for(i1 = 0; i1 < size; i1++) {
		for(i2 = i1; i2 < size; i2++) {
			uint8_t *chunk1 = buf;
			int size1 = i1;
			uint8_t *chunk2 = buf + size1;
			int size2 = i2 - i1;
			uint8_t *chunk3 = buf + size1 + size2;
			int size3 = size - size1 - size2;

			fprintf(stderr, "\n%d:{%d, %d, %d}...\n",
				size, size1, size2, size3);

			memset(buf1, 0, size);
			memset(buf2, 0, size);
			memset(buf3, 0, size);
			memcpy(buf1, chunk1, size1);
			memcpy(buf2, chunk2, size2);
			memcpy(buf3, chunk3, size3);

			tp = memset(&t, 0, sizeof(t));

			fprintf(stderr, "=> Chunk 1 (%d):\n", size1);
			rval = ber_decode(&asn1_DEF_T, (void **)&tp,
				buf1, size1);
			assert(rval.code == RC_WMORE);
			assert(rval.consumed <= size1);
			if(rval.consumed < size1) {
				int leftover = size1 - rval.consumed;
				memcpy(buf2, buf1 + rval.consumed, leftover);
				memcpy(buf2 + leftover, chunk2, size2);
				size2 += leftover;
			}

			fprintf(stderr, "=> Chunk 2 (%d):\n", size2);
			rval = ber_decode(&asn1_DEF_T, (void **)&tp,
				buf2, size2);
			assert(rval.code == RC_WMORE);
			assert(rval.consumed <= size2);
			if(rval.consumed < size2) {
				int leftover = size2 - rval.consumed;
				memcpy(buf3, buf2 + rval.consumed, leftover);
				memcpy(buf3 + leftover, chunk3, size3);
				size3 += leftover;
			}

			fprintf(stderr, "=> Chunk 3 (%d):\n", size3);
			rval = ber_decode(&asn1_DEF_T, (void **)&tp,
				buf3, size3);
			assert(rval.code == RC_OK);
			assert(rval.consumed == size3);

			asn1_DEF_T.free_struct(&asn1_DEF_T, &t, 1);
		}
	}
}

int
main(int ac, char **av) {
	T_t t;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	/* Check exact buf0 */
	check(&t, buf0, sizeof(buf0), sizeof(buf0));
	compare(&t, buf0_reconstr, sizeof(buf0_reconstr));
	asn_fprint(stderr, &asn1_DEF_T, &t);
	asn1_DEF_T.free_struct(&asn1_DEF_T, &t, 1);

	/* Check exact buf1 */
	check(&t, buf1, sizeof(buf1), sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	asn_fprint(stderr, &asn1_DEF_T, &t);
	asn1_DEF_T.free_struct(&asn1_DEF_T, &t, 1);

	/* Check slightly more than buf1 */
	check(&t, buf1, sizeof(buf1) + 10, sizeof(buf1));
	compare(&t, buf1_reconstr, sizeof(buf1_reconstr));
	asn_fprint(stderr, &asn1_DEF_T, &t);
	asn1_DEF_T.free_struct(&asn1_DEF_T, &t, 1);

	/* Check exact buf2 */
	check(&t, buf2, sizeof(buf2), sizeof(buf2));
	compare(&t, buf2_reconstr, sizeof(buf2_reconstr));
	asn_fprint(stderr, &asn1_DEF_T, &t);
	asn1_DEF_T.free_struct(&asn1_DEF_T, &t, 1);

	/* Check slightly more than buf2 */
	check(&t, buf2, sizeof(buf2) + 10, sizeof(buf2));
	compare(&t, buf2_reconstr, sizeof(buf2_reconstr));
	asn_fprint(stderr, &asn1_DEF_T, &t);
	asn1_DEF_T.free_struct(&asn1_DEF_T, &t, 1);

	/* Split the buffer in parts and check decoder restartability */
	partial_read(buf0, sizeof(buf0));

	return 0;
}
