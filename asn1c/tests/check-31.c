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

int buf_pos;
int bytes_compare(const void *bufferp, size_t size, void *key) {
	const uint8_t *buffer = bufferp;
	assert(buf_pos + size <= sizeof(buf1_reconstr));

	fprintf(stderr,  "  writing %d (%d)\n", (int)size, buf_pos + (int)size);

	for(; size; buf_pos++, size--, buffer++) {
		if(buf1_reconstr[buf_pos] != *buffer) {
			fprintf(stderr,
				"Byte %d is different: %d != %d (%x != %x)\n",
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
check(int is_ok, uint8_t *buf, int size, int consumed) {
	Forest_t t, *tp;
	ber_dec_rval_t rval;

	tp = memset(&t, 0, sizeof(t));

	fprintf(stderr, "Buf %p\n", buf);
	rval = ber_decode(&asn1_DEF_Forest, (void **)&tp, buf, size);
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
		return;
	}

	/*
	 * Try to re-create the buffer.
	 */
	buf_pos = 0;
	der_encode(&asn1_DEF_Forest, &t,
		bytes_compare, buf1_reconstr);
	assert(buf_pos == sizeof(buf1_reconstr));

	asn_fprint(stderr, &asn1_DEF_Forest, &t);

	asn1_DEF_Forest.free_struct(&asn1_DEF_Forest, &t, 1);
}

static void
try_corrupt(uint8_t *buf, int size) {
	uint8_t *tmp;
	int i;

	fprintf(stderr, "\nCorrupting...\n");

	tmp = alloca(size);

	for(i = 0; i < 1000; i++) {
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

	check(1, buf1, sizeof(buf1), sizeof(buf1));
	try_corrupt(buf1, sizeof(buf1));
	check(1, buf1, sizeof(buf1) + 20, sizeof(buf1));

	return 0;
}
