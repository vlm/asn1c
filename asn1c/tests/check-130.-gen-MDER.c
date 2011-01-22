#undef	NDEBUG
#include <stdio.h>	/* for stdout */
#include <stdlib.h>	/* for malloc() */
#include <assert.h>	/* for run-time control */
#include <string.h>	/* for bcmp() */

#include "Fixed-sized-label.h"
#include "Fixed-sized-label2.h"
#include "Fixed-sized-label3.h"
#include "Variable-label.h"

#define BUFFER_SIZE	1024

typedef int (compare_func)(void *a, void *b);

static uint8_t msg1[12] = {'t', 'e', 's', 't', ' ', 'm', 'e', 's', 's', 'a',
								'g', 'e'};
static uint8_t msg2[4] = {'t', 'e', 's', 't'};

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
		printf("Warning. Octet String provided only need %d Bytes to be "
				"encoded. %d Bytes used.\n", size, ev.encoded);
		goto fail;
	}

	/*
	 * Decode value and compare it with original provided in this function
	 */
	printf("Decoding Octet String\n");
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
		printf("%c", (char) buf[i]);
}

static int
cmp_buff(void *a, void *b) {
	OCTET_STRING_t *os1 = a;
	OCTET_STRING_t *os2 = b;

	printf("Octet String cmp (\"");
	print_buff(os1->buf, os1->size);
	printf("\" == \"");
	print_buff(os2->buf, os2->size);
	printf("\")\n");

	if (os1->size != os2->size)
		return 0;

	return (bcmp(os1->buf, os2->buf, os1->size) == 0);
}

static void
check_fixed_os() {
	Fixed_sized_label_t fixed;
	Fixed_sized_label2_t fixed2;
	Fixed_sized_label3_t fixed3;

	fixed.buf = msg1;
	fixed.size = 12;
	mder_check(0, &asn_DEF_Fixed_sized_label, &fixed, 12, cmp_buff);

	fixed2.buf = msg2;
	fixed2.size = 4;
	mder_check(0, &asn_DEF_Fixed_sized_label2, &fixed2, 4, cmp_buff);

	fixed3.size = 0;
	mder_check(0, &asn_DEF_Fixed_sized_label3, &fixed3, 0, cmp_buff);

	/* We can't change length of fixed octet strings. */
	/* Next test is expected to fail. */
	fixed.size = 11;
	mder_check(1, &asn_DEF_Fixed_sized_label, &fixed, 12, cmp_buff);
}

static void
check_variable_os() {
	Variable_label_t var;

	var.buf = msg1;
	var.size = 12;
	mder_check(0, &asn_DEF_Variable_label, &var, 12 + 2, cmp_buff);

	var.buf = msg2;
	var.size = 4;
	mder_check(0, &asn_DEF_Variable_label, &var, 4 + 2, cmp_buff);

	/* Variable octet string can be NULL. The coded value for an empty
	 * string results in an unsigned 16 bits integer containig a 0 value
	 * that represents the length of the full string */
	var.buf = 0;
	var.size = 0;
	mder_check(0, &asn_DEF_Variable_label, &var, 2, cmp_buff);
}

int
main() {
	check_fixed_os();
	check_variable_os();
	return 0;
}