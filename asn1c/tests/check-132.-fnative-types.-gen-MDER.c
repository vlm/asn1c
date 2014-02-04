#undef	NDEBUG
#include <stdio.h>	/* for stdout */
#include <stdlib.h>	/* for malloc() */
#include <assert.h>	/* for run-time control */
#include <strings.h>	/* for bcmp */

#include "T1.h"
#include "T2.h"
#include "T3.h"
#include "T4.h"
#include "T5.h"

#define BUFFER_SIZE	1024

typedef int (compare_func)(void *a, void *b);

static uint8_t msg[4] = {'t', 'e', 's', 't'};

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
		printf("Warning. Sequence provided only need %d Bytes to be "
				"encoded. %d Bytes used.\n", size, ev.encoded);
		goto fail;
	}

	/*
	 * Decode value and compare it with original provided in this function
	 */
	printf("Decoding SEQUENCE\n");
	dv = mder_decode(0, type_descriptor, &aux, buffer, BUFFER_SIZE);
	if (dv.code != RC_OK) {
		printf("Can't decode the sequence\n");
	}

	assert(dv.code == RC_OK);

	if (cmp_func && cmp_func(struct_ptr, aux) != 0) {
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
cmp_T1(void *a, void *b) {
	T1_t *t1 = a;
	T1_t *t2 = b;

	if (t1->present != t2->present)
		return 0;

	switch (t1->present) {
	case T1_PR_a:
		return (t1->choice.a == t2->choice.a);
	case T1_PR_b:
		return (t1->choice.b == t2->choice.b);
	case T1_PR_c:
		if (t1->choice.c.size != t2->choice.c.size)
			return 0;
	
		return (bcmp(t1->choice.c.buf, t2->choice.c.buf,
						t1->choice.c.size) == 0);
	default:
		printf("Warning: Nothing was selected\n");
		return 0;
	}
}

static int
cmp_T2(void *a, void *b) {
	T2_t *t1 = a;
	T2_t *t2 = b;

	if (t1->present != t2->present)
		return 0;

	switch (t1->present) {
	case T2_PR_a:
		return (t1->choice.a == t2->choice.a);
	case T2_PR_b:
		if (t1->choice.b.size != t2->choice.b.size)
			return 0;

		return (bcmp(t1->choice.b.buf, t2->choice.b.buf,
						t1->choice.b.size) == 0);
	default:
		printf("Warning: Nothing was selected\n");
		return 0;
	}
}

static int
cmp_T4(void *a, void *b) {
	T4_t *t1 = a;
	T4_t *t2 = b;

	if (t1->present != t2->present)
		return 0;

	switch (t1->present) {
	case T4_PR_a:
		return (t1->choice.a == t2->choice.a);
	case T4_PR_b:
		return (t1->choice.b == t2->choice.b);
	case T4_PR_c:
		return cmp_T2(&t1->choice.c, &t2->choice.c);
	case T4_PR_d:
		if (t1->choice.d.size != t2->choice.d.size)
			return 0;

		return (bcmp(t1->choice.d.buf, t2->choice.d.buf,
						t1->choice.d.size) == 0);
	}
}

static int
cmp_T5(void *a, void *b) {
	T5_t *t1 = a;
	T5_t *t2 = b;

	if (t1->present != t2->present)
		return 0;

	switch (t1->present) {
	case T5_PR_a:
		return (t1->choice.a == t2->choice.a);
	case T5_PR_b:
		printf("Warning: B parameter should not be coded\n");
		return 0;
	case T4_PR_c:
		if (t1->choice.c.size != t2->choice.c.size)
			return 0;

		return (bcmp(t1->choice.c.buf, t2->choice.c.buf,
						t1->choice.c.size) == 0);
	}
}

static void
check_T1() {
	T1_t t1;

	t1.present = T1_PR_NOTHING;
	mder_check(1, &asn_DEF_T1, &t1, 4, cmp_T1);

	t1.present = T1_PR_a;
	t1.choice.a = 2;
	mder_check(0, &asn_DEF_T1, &t1, 5, cmp_T1);

	t1.present = T1_PR_b;
	t1.choice.b = 17;
	mder_check(0, &asn_DEF_T1, &t1, 5, cmp_T1);

	t1.present = T1_PR_c;
	t1.choice.c.buf = msg;
	t1.choice.c.size = 4;
	mder_check(0, &asn_DEF_T1, &t1, 10, cmp_T1);
}

static void
check_T2() {
	T2_t t2;

	t2.present = T2_PR_NOTHING;
	mder_check(1, &asn_DEF_T2, &t2, 4, cmp_T2);

	t2.present = T2_PR_a;
	t2.choice.a = 2;
	mder_check(0, &asn_DEF_T2, &t2, 5, cmp_T2);

	t2.present = T2_PR_a;
	t2.choice.a = 455; /* out of INT-U8 range */
	mder_check(1, &asn_DEF_T2, &t2, 5, cmp_T2);

	t2.present = T2_PR_b;
	t2.choice.b.buf = msg;
	t2.choice.b.size = 4;
	mder_check(0, &asn_DEF_T2, &t2, 10, cmp_T2);
}

static void
check_T3() {
	T3_t t3;

	t3.present = T3_PR_NOTHING;
	mder_check(1, &asn_DEF_T3, &t3, 4, NULL);

	t3.present = T3_PR_a;
	t3.choice.a = 2;
	mder_check(1, &asn_DEF_T3, &t3, 5, NULL);
}

static void
check_T4() {
	T4_t t4;

	t4.present = T4_PR_NOTHING;
	mder_check(1, &asn_DEF_T4, &t4, 4, NULL);

	t4.present = T4_PR_a;
	t4.choice.a = 67;
	mder_check(0, &asn_DEF_T4, &t4, 5, cmp_T4);

	t4.present = T4_PR_b;
	t4.choice.b = 123;
	mder_check(0, &asn_DEF_T4, &t4, 5, cmp_T4);

	t4.present = T4_PR_c;
	t4.choice.c.present = T2_PR_a;
	t4.choice.c.choice.a = 123;
	mder_check(0, &asn_DEF_T4, &t4, 9, cmp_T4);

	t4.present = T4_PR_d;
	t4.choice.d.buf = msg;
	t4.choice.d.size = 4;
	mder_check(0, &asn_DEF_T4, &t4, 10, cmp_T4);
}

static void
check_T5() {
	T5_t t5;

	t5.present = T5_PR_NOTHING;
	mder_check(1, &asn_DEF_T5, &t5, 4, NULL);

	t5.present = T5_PR_a;
	t5.choice.a = 212;
	mder_check(0, &asn_DEF_T5, &t5, 5, cmp_T5);

	t5.present = T5_PR_b;
	t5.choice.b.present = T3_PR_a;
	t5.choice.b.choice.a = 211;
	mder_check(1, &asn_DEF_T5, &t5, 9, cmp_T5);

	t5.present = T5_PR_c;
	t5.choice.c.buf = msg;
	t5.choice.c.size = 4;
	mder_check(0, &asn_DEF_T5, &t5, 10, cmp_T5);
}

int
main() {
	check_T1();
	check_T2();
	check_T3();
	check_T4();
	check_T5();
	return 0;
}