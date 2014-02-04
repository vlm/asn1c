#undef	NDEBUG
#include <stdio.h>	/* for stdout */
#include <stdlib.h>	/* for malloc() */
#include <assert.h>	/* for run-time control */
#include <strings.h>	/* for bcmp */

#include "T1.h"
#include "T2.h"
#include "T4.h"
#include "T6.h"

#define BUFFER_SIZE	1024

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
		printf("Warning. SEQUENCE OF provided only need %d Bytes to be "
				"encoded. %d Bytes used.\n", size, ev.encoded);
		goto fail;
	}

	/*
	 * Decode value and compare it with original provided in this function
	 */
	printf("Decoding SEQUENCE OF\n");
	dv = mder_decode(0, type_descriptor, &aux, buffer, BUFFER_SIZE);
	if (dv.code != RC_OK) {
		printf("Can't decode the SEQUENCE OF\n");
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
	T1_t *ta = a;
	T1_t *tb = b;
	int i;

	if (ta->list.count != tb->list.count)
		return 0;

	for (i = 0; i < ta->list.count; i++)
		if (*ta->list.array[i] != *tb->list.array[i])
			return 0;
	
	return 1;
}

static int
cmp_T2(void *a, void *b) {
	T2_t *ta = a;
	T2_t *tb = b;
	int i;

	if (ta->list.count != tb->list.count)
		return 0;

	for (i = 0; i < ta->list.count; i++) {
		if (ta->list.array[i]->present != tb->list.array[i]->present)
			return 0;

		switch (ta->list.array[i]->present) {
		case T3_PR_a:
			if (ta->list.array[i]->choice.a !=
						tb->list.array[i]->choice.a)
				return 0;
			break;
		case T3_PR_b:
			if (ta->list.array[i]->choice.b !=
						tb->list.array[i]->choice.b)
				return 0;
			break;
		case T3_PR_c:
			if (ta->list.array[i]->choice.c.size !=
					tb->list.array[i]->choice.c.size)
				return 0;

			if (bcmp(ta->list.array[i]->choice.c.buf,
					tb->list.array[i]->choice.c.buf,
					ta->list.array[i]->choice.c.size) != 0)
				return 0;
			break;
		default:
			return 0;
		}
	}

	return 1;
}

static int
cmp_T6(void *a, void *b) {
	T6_t *ta = a;
	T6_t *tb = b;
	int i;

	if (ta->list.count != tb->list.count)
		return 0;

	for (i = 0; i < ta->list.count; i++) {
		if (ta->list.array[i]->a != tb->list.array[i]->a)
			return 0;

		if (ta->list.array[i]->b != tb->list.array[i]->b)
			return 0;

		if (ta->list.array[i]->c.size != tb->list.array[i]->c.size)
			return 0;

		if (bcmp(ta->list.array[i]->c.buf, tb->list.array[i]->c.buf,
						ta->list.array[i]->c.size) != 0)
			return 0;

		if (ta->list.array[i]->d.present !=
						tb->list.array[i]->d.present)
			return 0;

		switch (ta->list.array[i]->d.present) {
		case d_PR_b:
			if (ta->list.array[i]->d.choice.b !=
						tb->list.array[i]->d.choice.b)
				return 0;
			break;
		case d_PR_c:
			if (ta->list.array[i]->d.choice.c.size !=
					tb->list.array[i]->d.choice.c.size)
				return 0;

			if (bcmp(ta->list.array[i]->d.choice.c.buf,
				tb->list.array[i]->d.choice.c.buf,
				ta->list.array[i]->d.choice.c.size) != 0)
					return 0;
			break;
		default:
			return 0;
		}
	}

	return 1;
}

static void
check_T1() {
	T1_t *t1;
	INT_U16_t *i;
	int ret;

	/* Testing empty SEQUENCE_OF */
	t1 = calloc(1, sizeof *t1);
	assert(t1);
	mder_check(0, &asn_DEF_T1, t1, 4, cmp_T1);

	i = calloc(1, sizeof *i);
	assert(i);
	*i = 1;
	ret = ASN_SEQUENCE_ADD(t1, i);
	assert(ret == 0);
	mder_check(0, &asn_DEF_T1, t1, 6, cmp_T1);

	i = calloc(1, sizeof *i);
	assert(i);
	*i = 2;
	ret = ASN_SEQUENCE_ADD(t1, i);
	assert(ret == 0);
	mder_check(0, &asn_DEF_T1, t1, 8, cmp_T1);

	i = calloc(1, sizeof *i);
	assert(i);
	*i = 3;
	ret = ASN_SEQUENCE_ADD(t1, i);
	assert(ret == 0);
	mder_check(0, &asn_DEF_T1, t1, 10, cmp_T1);

	i = calloc(1, sizeof *i);
	assert(i);
	*i = -1 /* value out of range */;
	ret = ASN_SEQUENCE_ADD(t1, i);
	assert(ret == 0);
	mder_check(1, &asn_DEF_T1, t1, 12, cmp_T1);

	asn_DEF_T1.free_struct(&asn_DEF_T1, t1, 0);
}

static void
check_T2() {
	T2_t *t2;
	T3_t *t3;
	int ret;

	/* Testing empty SEQUENCE_OF */
	t2 = calloc(1, sizeof *t2);
	assert(t2);
	mder_check(0, &asn_DEF_T2, t2, 4, cmp_T2);

	t3 = calloc(1, sizeof *t3);
	assert(t3);
	t3->present = T3_PR_NOTHING;
	ret = ASN_SEQUENCE_ADD(t2, t3);
	assert(ret == 0);
	mder_check(1, &asn_DEF_T2, t2, 9, cmp_T2);

	t3->present = T3_PR_a;
	t3->choice.a = 4;
	mder_check(0, &asn_DEF_T2, t2, 9, cmp_T2);

	t3 = calloc(1, sizeof *t3);
	assert(t3);
	t3->present = T3_PR_b;
	t3->choice.b = 100;
	ret = ASN_SEQUENCE_ADD(t2, t3);
	assert(ret == 0);
	mder_check(0, &asn_DEF_T2, t2, 14, cmp_T2);

	t3 = calloc(1, sizeof *t3);
	assert(t3);
	t3->present = T3_PR_c;
	t3->choice.c.size = 5;
	t3->choice.c.buf = malloc(t3->choice.c.size);
	assert(t3->choice.c.buf);
	t3->choice.c.buf[0] = 'h';
	t3->choice.c.buf[1] = 'e';
	t3->choice.c.buf[2] = 'l';
	t3->choice.c.buf[3] = 'l';
	t3->choice.c.buf[4] = 'o';
	ret = ASN_SEQUENCE_ADD(t2, t3);
	assert(ret == 0);
	mder_check(0, &asn_DEF_T2, t2, 25, cmp_T2);

	asn_DEF_T2.free_struct(&asn_DEF_T2, t2, 0);
}

static void
check_T4() {
	T4_t *t4;
	T5_t *t5;
	int ret;

	t4 = calloc(1, sizeof *t4);
	assert(t4);

	/* SEQUENCE types can't contain optional types. */
	/* Next example is expected to fail. */
	t5 = calloc(1, sizeof *t5);
	assert(t5);
	t5->a = 23;
	ret = ASN_SEQUENCE_ADD(t4, t5);
	assert(ret == 0);
	mder_check(1, &asn_DEF_T4, t4, 13, NULL);

	asn_DEF_T4.free_struct(&asn_DEF_T4, t4, 0);
}

static void
check_T6() {
	T6_t *t6;
	T7_t *t7;
	int ret;

	/* Testing with empty SEQUENCE_OF */
	t6 = calloc(1, sizeof *t6);
	assert(t6);
	mder_check(0, &asn_DEF_T6, t6, 4, cmp_T6);

	t7 = calloc(1, sizeof *t7);
	assert(t7);
	t7->a = 6;
	t7->b = 23;
	t7->d.present = d_PR_b;
	t7->d.choice.b = 123;
	ret = ASN_SEQUENCE_ADD(t6, t7);
	assert(ret == 0);
	mder_check(0, &asn_DEF_T6, t6, 14, cmp_T6);

	t7 = calloc(1, sizeof *t7);
	assert(t7);
	t7->a = 63;
	t7->b = 231;
	t7->c.size = 5;
	t7->c.buf = malloc(t7->c.size);
	assert(t7->c.buf);
	t7->c.buf[0] = 'h';
	t7->c.buf[1] = 'e';
	t7->c.buf[2] = 'l';
	t7->c.buf[3] = 'l';
	t7->c.buf[4] = 'o';
	t7->d.present = d_PR_b;
	t7->d.choice.b = 173;
	ret = ASN_SEQUENCE_ADD(t6, t7);
	assert(ret == 0);
	mder_check(0, &asn_DEF_T6, t6, 29, cmp_T6);

	t7 = calloc(1, sizeof *t7);
	assert(t7);
	t7->a = 6;
	t7->b = 23;
	t7->d.present = d_PR_c;
	t7->d.choice.c.size = 5;
	t7->d.choice.c.buf = malloc(t7->d.choice.c.size);
	t7->d.choice.c.buf[0] = 'h';
	t7->d.choice.c.buf[1] = 'e';
	t7->d.choice.c.buf[2] = 'l';
	t7->d.choice.c.buf[3] = 'l';
	t7->d.choice.c.buf[4] = 'o';
	ret = ASN_SEQUENCE_ADD(t6, t7);
	assert(ret == 0);
	mder_check(0, &asn_DEF_T6, t6, 45, cmp_T6);

	asn_DEF_T6.free_struct(&asn_DEF_T6, t6, 0);
}

int
main() {
	check_T1();
	check_T2();
	check_T4();
	check_T6();
	return 0;
}