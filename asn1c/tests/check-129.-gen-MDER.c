#undef	NDEBUG
#include <stdio.h>	/* for stdout */
#include <stdlib.h>	/* for malloc() */
#include <assert.h>	/* for run-time control */
#include <string.h>	/* for bcmp() */

#include "State.h"
#include "PowerStatus.h"
#include "SystemType.h"
#include "BadExample1.h"
#include "BadExample2.h"

#define BUFFER_SIZE	1024
#define BIT_STRING8	1
#define BIT_STRING16	2
#define BIT_STRING32	4

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
		printf("Warning. BIT STRING provided only need %d Bytes to be "
				"encoded. %d Bytes used.\n", size, ev.encoded);
		goto fail;
	}

	/*
	 * Decode value and compare it with original provided in this function
	 */
	printf("Decoding BITR STRING\n");
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

static void
print_buff(uint8_t *buf, size_t size) {
	int i;

	for (i = 0; i < size; i++)
		printf("%02x ", buf[i]);
}

static int
cmp_buff(void *a, void *b) {
	BIT_STRING_t *bs1 = a;
	BIT_STRING_t *bs2 = b;

	printf("BIT STRING cmp (");
	print_buff(bs1->buf, bs1->size);
	printf(" == ");
	print_buff(bs2->buf, bs2->size);
	printf(")\n");

	if (bs1->size != bs2->size)
		return 0;

	return (bcmp(bs1->buf, bs2->buf, bs1->size) == 0);
}

static void
check_bs_8() {
	State_t state;

	state.buf = calloc(BIT_STRING8, 1);
	assert(state.buf);
	state.size = BIT_STRING8;
	state.buf[0] |= 1 << (7 - State_close);
	mder_check(0, &asn_DEF_State, &state, BIT_STRING8, cmp_buff);

	state.buf[0] = 1 << (7 - State_open);
	mder_check(0, &asn_DEF_State, &state, BIT_STRING8, cmp_buff);

	state.buf[0] |= 1 << (7 - State_close);
	mder_check(0, &asn_DEF_State, &state, BIT_STRING8, cmp_buff);
}

static void
check_bs_16() {
	PowerStatus_t powstat;

	powstat.buf = calloc(BIT_STRING16, 1);
	assert(powstat.buf);
	powstat.size = BIT_STRING16;
	powstat.buf[0] |= 1 << (7 - PowerStatus_onMains);
	mder_check(0, &asn_DEF_PowerStatus, &powstat, BIT_STRING16, cmp_buff);

	powstat.buf[0] |= 1 << (7 - PowerStatus_onBattery);
	mder_check(0, &asn_DEF_PowerStatus, &powstat, BIT_STRING16, cmp_buff);

	powstat.buf[1] |= 1 << (7 - (PowerStatus_chargingTrickle % 8));
	mder_check(0, &asn_DEF_PowerStatus, &powstat, BIT_STRING16, cmp_buff);
}

static void
check_bs_32() {
	SystemType_t systype;

	systype.buf = calloc(BIT_STRING32, 1);
	assert(systype.buf);
	systype.size = BIT_STRING32;
	systype.buf[0] |= 1 << (7 - SystemType_sys_type_manager);
	mder_check(0, &asn_DEF_SystemType, &systype, BIT_STRING32, cmp_buff);

	systype.buf[0] = 0;
	systype.buf[1] |= 1 << (7 - SystemType_sys_type_agent % 8);
	mder_check(0, &asn_DEF_SystemType, &systype, BIT_STRING32, cmp_buff);
}

static void
check_invalid_examples() {
	BadExample1_t bad1;
	BadExample2_t bad2;

	bad1.buf = calloc(1, 1);
	assert(bad1.buf);
	bad1.size = 1;
	mder_check(1, &asn_DEF_BadExample1, &bad1, BIT_STRING8, cmp_buff);

	bad2.buf = calloc(7, 1);
	assert(bad2.buf);
	bad2.size = 7;
	mder_check(1, &asn_DEF_BadExample2, &bad2, 7, cmp_buff);
}

int
main() {
	check_bs_8();
	check_bs_16();
	check_bs_32();
	check_invalid_examples();
	return 0;
}