#undef	NDEBUG
#include <stdio.h>	/* for stdout */
#include <stdlib.h>	/* for malloc() */
#include <assert.h>	/* for run-time control */
#include <strings.h>	/* for bcmp */

#define BUFFER_SIZE	1024

#include "IdentType.h"
#include "T1.h"
#include "T2.h"
#include "T3.h"

typedef int (compare_func)(void *a, void *b);

static uint8_t msg[10] = {'t', 'e', 's', 't', 's', 't', 'r', 'i', 'n', 'g'};
static uint8_t msg2[4] = {'0', '1', '2', '3'};

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
cmp_IdenType(void *a, void *b) {
	IdentType_t *idType1 = a;
	IdentType_t *idType2 = b;

	if (idType1->name.size != idType2->name.size)
		return 0;

	if (bcmp(idType1->name.buf, idType2->name.buf, idType1->name.size) != 0)
		return 0;

	if (idType1->oid.size != idType2->oid.size)
		return 0;

	if (bcmp(idType1->oid.buf, idType2->oid.buf, idType1->oid.size) != 0)
		return 0;

	return (idType1->id == idType2->id) &&
				(idType1->instance == idType2->instance);
}


static void
check_IdenType() {
	IdentType_t idType;
	asn_enc_rval_t ev;
	char buffer[BUFFER_SIZE];

	idType.id = 5;
	idType.name.buf = NULL;
	idType.name.size = 0; /* Empty OCTET STRING */
	idType.instance = 2343;
	idType.oid.buf = msg2;
	idType.oid.size = 4;

	mder_check(0, &asn_DEF_IdentType, &idType, 9, cmp_IdenType);

	idType.id = 255;
	idType.name.buf = msg;
	idType.name.size = 10;
	idType.instance = 23456;
	idType.oid.buf = msg2;
	idType.oid.size = 4;

	mder_check(0, &asn_DEF_IdentType, &idType, 19, cmp_IdenType);

	idType.id = 257; /* value out of range */
	idType.name.buf = msg;
	idType.name.size = 10;
	idType.instance = 23456;
	idType.oid.buf = msg2;
	idType.oid.size = 4;

	mder_check(1, &asn_DEF_IdentType, &idType, 19, cmp_IdenType);
}

static void
check_optional() {
	T1_t t1;

	t1.a = 23;
	t1.b = NULL;
	t1.c.buf = NULL;
	t1.c.size = 0; /* Empty OCTET STRING */

	mder_check(1, &asn_DEF_T1, &t1, 5, NULL);

	t1.a = 1;
	t1.b = calloc(1, sizeof(INT_U16_t));
	*t1.b = 6;
	t1.c.buf = msg;
	t1.c.size = 10;

	mder_check(1, &asn_DEF_T1, &t1, 15, NULL);

	free(t1.b);
}

static void
check_default() {
	T2_t t2;
	T3_t t3;

	t2.a = 3;
	t2.b = NULL;

	mder_check(1, &asn_DEF_T2, &t2, 3, NULL);

	t2.a = 23;
	t2.b = calloc(1, sizeof(INT_U16_t));
	*t2.b = 6;

	mder_check(1, &asn_DEF_T2, &t2, 3, NULL);
	free(t2.b);

	t3.a.buf = msg;
	t3.a.size = 10;
	t3.b.a = 44;
	t3.b.b = calloc(1, sizeof(INT_U16_t));
	*t3.b.b = 9;

	mder_check(1, &asn_DEF_T3, &t3, 3, NULL);
	free(t3.b.b);
}

int
main() {
	check_IdenType();
	check_optional();
	check_default();
	return 0;
}