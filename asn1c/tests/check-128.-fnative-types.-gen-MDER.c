#undef	NDEBUG
#include <stdio.h>	/* for stdout */
#include <stdlib.h>	/* for malloc() */
#include <assert.h>	/* for run-time control */

#include "INT-U8.h"
#include "INT-U16.h"
#include "INT-U32.h"
#include "INT-I8.h"
#include "INT-I16.h"
#include "INT-I32.h"
#include "INT-GOOD.h"
#include "INT-BAD1.h"
#include "INT-BAD2.h"
#include "INT-BAD3.h"

#define BUFFER_SIZE	1024
#define BIT8_LENGTH	1
#define BIT16_LENGTH	2
#define BIT32_LENGTH	4

typedef int (compare_func)(void *a, void *b);

static void
mder_check(int tofail, struct asn_TYPE_descriptor_s *type_descriptor,
			void *struct_ptr, size_t size, compare_func cmp_func) {
	char buffer[BUFFER_SIZE];
	asn_enc_rval_t ev;
	asn_dec_rval_t dv;
	void *aux = NULL;

	ev = mder_encode_to_buffer(type_descriptor, struct_ptr, buffer,
								BUFFER_SIZE);
	if(ev.encoded < 0)
		goto fail;

	if(ev.encoded != size) {
		printf("Warning. Integer provided only need %d Bytes to be "
				"encoded. %d Bytes used.\n", size, ev.encoded);
		goto fail;
	}

	/*
	 * Decode value and compare it with original provided in this function
	 */
	printf("Decoding INTEGER\n");
	dv = mder_decode(0, type_descriptor, &aux, buffer, BUFFER_SIZE);
	assert(dv.code == RC_OK);

	if (cmp_func(struct_ptr, aux) != 0) {
		type_descriptor->free_struct(type_descriptor, aux, 0);
		assert(tofail != 1);
		return;
	}

	printf("Warning. Decoded valued isn't equal to encoded one.\n");
	type_descriptor->free_struct(type_descriptor, aux, 0);

fail:
	assert(tofail);
	printf("Don't worry. Error was expected.\n");
}

static int
cmp_long(void *a, void *b) {
	long *cmp1 = a;
	long *cmp2 = b;

	printf("Comparing values %d == %d ?\n", *cmp1, *cmp2);
	return (*cmp1 == *cmp2);
}

static int
cmp_ulong(void *a, void *b) {
	unsigned long *cmp1 = a;
	unsigned long *cmp2 = b;

	printf("Comparing values %lu == %lu ?\n", *cmp1, *cmp2);
	return (*cmp1 == *cmp2);
}

static void
check_uint8() {
	INT_U8_t val;
	INT_GOOD_t val2;

	/* Check values in range [0..255] */
	val = 0;
	mder_check(0, &asn_DEF_INT_U8, &val, BIT8_LENGTH, cmp_long);
	val = 127;
	mder_check(0, &asn_DEF_INT_U8, &val, BIT8_LENGTH, cmp_long);
	val = 255;
	mder_check(0, &asn_DEF_INT_U8, &val, BIT8_LENGTH, cmp_long);
	val2 = 200;
	mder_check(0, &asn_DEF_INT_GOOD, &val2, BIT8_LENGTH, cmp_long);

	/* Checking integer value out of range [0..255] */
	val = 256;
	mder_check(1, &asn_DEF_INT_U8, &val, BIT8_LENGTH, cmp_long);
	val2 = -1;
	mder_check(1, &asn_DEF_INT_GOOD, &val2, BIT8_LENGTH, cmp_long);
}

static void
check_uint16() {
	INT_U16_t val;

	/* Check values in range [0..65535] */
	val = 0;
	mder_check(0, &asn_DEF_INT_U16, &val, BIT16_LENGTH, cmp_long);
	val = 256;
	mder_check(0, &asn_DEF_INT_U16, &val, BIT16_LENGTH, cmp_long);
	val = 65535;
	mder_check(0, &asn_DEF_INT_U16, &val, BIT16_LENGTH, cmp_long);

	/* Check values out of range [0..65535] */
	val = -1;
	mder_check(1, &asn_DEF_INT_U16, &val, BIT16_LENGTH, cmp_long);
	val = 65536;
	mder_check(1, &asn_DEF_INT_U16, &val, BIT16_LENGTH, cmp_long);
}

static void
check_uint32() {
	INT_U32_t val;

	/* Check values in range [0..4294967295] */
	val = 0;
	mder_check(0, &asn_DEF_INT_U32, &val, BIT32_LENGTH, cmp_ulong);
	val = 65536;
	mder_check(0, &asn_DEF_INT_U32, &val, BIT32_LENGTH, cmp_ulong);
	val = 4294967295UL;
	mder_check(0, &asn_DEF_INT_U32, &val, BIT32_LENGTH, cmp_ulong);

	/* unsigned long are in range [0..4294967295] */
	/* we can't check values out of that range */
}

static void
check_iint8() {
	INT_I8_t val;

	/* Check values in range [-128..127] */
	val = -128;
	mder_check(0, &asn_DEF_INT_I8, &val, BIT8_LENGTH, cmp_long);
	val = -98;
	mder_check(0, &asn_DEF_INT_I8, &val, BIT8_LENGTH, cmp_long);
	val = 0;
	mder_check(0, &asn_DEF_INT_I8, &val, BIT8_LENGTH, cmp_long);
	val = 118;
	mder_check(0, &asn_DEF_INT_I8, &val, BIT8_LENGTH, cmp_long);
	val = 127;
	mder_check(0, &asn_DEF_INT_I8, &val, BIT8_LENGTH, cmp_long);

	/* Check values out of range [-128..127] */
	val = -129;
	mder_check(1, &asn_DEF_INT_I8, &val, BIT8_LENGTH, cmp_long);
	val = 128;
	mder_check(1, &asn_DEF_INT_I8, &val, BIT8_LENGTH, cmp_long);
}

static void
check_iint16() {
	INT_I16_t val;

	/* Check values in range [-32768..32767] */
	val = -32768;
	mder_check(0, &asn_DEF_INT_I16, &val, BIT16_LENGTH, cmp_long);
	val = -129;
	mder_check(0, &asn_DEF_INT_I16, &val, BIT16_LENGTH, cmp_long);
	val = 0;
	mder_check(0, &asn_DEF_INT_I16, &val, BIT16_LENGTH, cmp_long);
	val = 128;
	mder_check(0, &asn_DEF_INT_I16, &val, BIT16_LENGTH, cmp_long);
	val = 32767;
	mder_check(0, &asn_DEF_INT_I16, &val, BIT16_LENGTH, cmp_long);

	/* Check values out of range [-32768..32767] */
	val = -32769;
	mder_check(1, &asn_DEF_INT_I16, &val, BIT16_LENGTH, cmp_long);
	val = 32768;
	mder_check(1, &asn_DEF_INT_I16, &val, BIT16_LENGTH, cmp_long);
}

static void
check_iint32() {
	INT_I32_t val;

	/* Check values in range [-2147483648..2147483647] */
	val = -2147483648L;
	mder_check(0, &asn_DEF_INT_I32, &val, BIT32_LENGTH, cmp_long);
	val = -32769;
	mder_check(0, &asn_DEF_INT_I32, &val, BIT32_LENGTH, cmp_long);
	val = 0;
	mder_check(0, &asn_DEF_INT_I32, &val, BIT32_LENGTH, cmp_long);
	val = 32768;
	mder_check(0, &asn_DEF_INT_I32, &val, BIT32_LENGTH, cmp_long);
	val = 2147483647L;
	mder_check(0, &asn_DEF_INT_I32, &val, BIT32_LENGTH, cmp_long);

	/* longs are in range [-2147483648..2147483647] */
	/* we can't check values out of that range */
}

static void
check_erroneus_integers() {
	INT_BAD1_t bad1;
	INT_BAD1_t bad2;
	INT_BAD1_t bad3;

	bad1 = 15;
	mder_check(1, &asn_DEF_INT_BAD1, &bad1, BIT8_LENGTH, cmp_long);
	bad2 = -2;
	mder_check(1, &asn_DEF_INT_BAD1, &bad1, BIT8_LENGTH, cmp_long);
	bad3 = 30;
	mder_check(1, &asn_DEF_INT_BAD1, &bad1, BIT8_LENGTH, cmp_long);
}

int
main() {
	check_uint8();
	check_iint8();
	check_uint16();
	check_iint16();
	check_uint32();
	check_iint32();
	check_erroneus_integers();
	return 0;
}