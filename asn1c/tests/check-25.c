#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <T.h>

uint8_t buf1[] = {
	32 | 16,		/* [UNIVERSAL 16], constructed */
	128,	/* L */
	/* a INTEGER */
	2,			/* [UNIVERSAL 2] */
	2,	/* L */
  150,
  70,
	/* b BOOLEAN */
	128 | 2,		/* [2] */
	1,	/* L */
  0xff,
	/* c NULL */
	5,			/* [UNIVERSAL 5] */
	0,	/* L */
	/* d ENUMERATED */
	10,			/* [UNIVERSAL 10] */
	1,	/* L */
  222,
	4,			/* [UNIVERSAL 4] */
	3,	/* L */
	'x',
	'y',
	'z',
	/* f OCTET STRING */
	32 | 4,			/* [UNIVERSAL 4], constructed */
	128,	/* L indefinite */
		4,		/* [UNIVERSAL 4], primitive */
		2,
  'l',
  'o',
		32 | 4,		/* [UNIVERSAL 4], recursively constructed */
		128,
			4,
			1,
  'v',
			4,
			2,
  'e',
  '_',
		0,
		0,
		4,		/* [UNIVERSAL 4], primitive */
		2,
  'i',
  't',
	0,
	0,
	/* g BIT STRING */
	3,			/* [UNIVERSAL 3], primitive */
	3,	/* L */
	2,	/* Skip 2 bits */
	147,
	150,	/* => 148 */
	/* h BIT STRING */
	32 | 3,			/* [UNIVERSAL 3], constructed */
	128,	/* L indefinite */
		3,			/* [UNIVERSAL 3], primitive */
		3,	/* L */
		0,	/* Skip 0 bits */
		140,
		141,
		3,			/* [UNIVERSAL 3], primitive */
		2,	/* L */
		1,	/* Skip 1 bit */
		143,	/* => 142 */
	0,	/* End of f */
	0,
	0,	/* End of the whole structure */
	0,
	/* Three bytes of planned leftover */
	111, 222, 223
};

static void
check(int is_ok, uint8_t *buf, int size, int consumed) {
	T_t t, *tp;
	ber_dec_rval_t rval;

	tp = memset(&t, 0, sizeof(t));

	fprintf(stderr, "Buf %p (%d)\n", buf, (int)size);
	rval = ber_decode(&asn1_DEF_T, (void **)&tp, buf, size);
	fprintf(stderr, "Returned code %d, consumed %d, expected %d\n",
		(int)rval.code, (int)rval.consumed, (int)consumed);

	if(is_ok) {
		assert(rval.code == RC_OK);
		assert(rval.consumed == consumed);

		assert(strcmp(t.e->buf, "xyz") == 0);
		assert(strcmp(t.f->buf, "love_it") == 0);

		assert(t.g->size == 3);
		assert(t.g->buf[0] == 2);
		assert(t.g->buf[1] == 147);
		assert(t.g->buf[2] == 148);

		printf("%d\n", t.h->buf[3]);
		assert(t.h->size == 4);
		assert(t.h->buf[0] == 1);
		assert(t.h->buf[1] == 140);
		assert(t.h->buf[2] == 141);
		assert(t.h->buf[3] == 142);
	} else {
		if(rval.code == RC_OK) {
			assert(t.a.size != 2
			|| !t.d
			|| t.d->size != 1
			|| !t.e
			|| t.e->size != 3
			|| !t.f
			|| t.f->size != 7
			|| !t.g
			|| t.g->size != 3
			|| !t.h
			|| t.h->size != 4
			);
		}
		fprintf(stderr, "%d %d\n", (int)rval.consumed, (int)consumed);
		assert(rval.consumed <= consumed);
	}

	asn1_DEF_T.free_struct(&asn1_DEF_T, &t, 1);
}

static void
try_corrupt(uint8_t *buf, int size, int allow_consume) {
	uint8_t *tmp;
	int i;

	fprintf(stderr, "\nCorrupting...\n");

	tmp = alloca(size);

	for(i = 0; i < 1000; i++) {
		int loc;
		memcpy(tmp, buf, size);

		/* Corrupt random _non-value_ location. */
		do { loc = random() % size; } while(
			loc == 44	/* bit skips */
			|| loc == 51	/* bit skips */
			|| loc == 56	/* bit skips */
			|| tmp[loc] >= 70);
		do { tmp[loc] = buf[loc] ^ random(); } while(
			(tmp[loc] == buf[loc])
			|| (buf[loc] == 0 && tmp[loc] == 0x80));

		fprintf(stderr, "\nTry %d: corrupting byte %d (%d->%d)\n",
			i, loc, buf[loc], tmp[loc]);

		check(0, tmp, size, allow_consume);
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

	/* Check that the full buffer may be decoded normally */
	check(1, buf1, sizeof(buf1), sizeof(buf1) - 3);

	/* Check that some types of buffer corruptions will lead to failure */
	try_corrupt(buf1, sizeof(buf1) - 3, sizeof(buf1) - 3);

	/* Split the buffer in parts and check decoder restartability */
	partial_read(buf1, sizeof(buf1) - 3);

	return 0;
}
