#include "../RELATIVE-OID.c"
#include "../OBJECT_IDENTIFIER.c"
#include "../INTEGER.c"
#include "../ber_decoder.c"
#include "../ber_tlv_length.c"
#include "../ber_tlv_tag.c"
#include "../der_encoder.c"
#include "../constraints.c"

static int
_print(const void *buffer, size_t size, void *app_key) {
	fwrite(buffer, size, 1, stdout);
	return 0;
}

static void
check_OID(uint8_t *buf, size_t len, int *ck_buf, int ck_len) {
	OBJECT_IDENTIFIER_t *oid;
	ber_dec_rval_t rval;
	unsigned long arcs[10];
	int alen;
	int i;

	printf("Checking {");
	for(i = 0; i < len; i++) { printf("%s%02x", i?" ":"", buf[i]); }
	printf("} against {");
	for(i = 0; i < ck_len; i++) { printf("%s%d", i?" ":"", ck_buf[i]); }
	printf("}\n");

	oid = NULL;
	rval = ber_decode(&asn1_DEF_OBJECT_IDENTIFIER, (void *)&oid, buf, len);
	assert(rval.code == RC_OK);

	assert(oid->size == len - 2);

	/*
	 * Print the contents for visual debugging.
	 */
	printf("OBJECT_IDENTIFIER_print() => ");
	OBJECT_IDENTIFIER_print(&asn1_DEF_OBJECT_IDENTIFIER, oid, 0, _print, 0);
	printf("\n");

	alen = OBJECT_IDENTIFIER_get_arcs_l(oid,
		arcs, sizeof(arcs)/sizeof(arcs[0]));
	assert(alen > 0);
	assert(alen == ck_len);

	/*
	 * Make sure they are equivalent.
	 */
	printf("OBJECT_IDENTIFIER_get_arcs() => {");
	for(i = 0; i < alen; i++) {
		printf(" %lu", arcs[i]);
		assert(arcs[i] == ck_buf[i]);
	}
	printf(" }\n");
}

static void
check_ROID(uint8_t *buf, size_t len, int *ck_buf, int ck_len) {
	RELATIVE_OID_t *oid;
	ber_dec_rval_t rval;
	unsigned long arcs[10];
	int alen;
	int i;

	printf("Checking {");
	for(i = 0; i < len; i++) { printf("%s%02x", i?" ":"", buf[i]); }
	printf("} against {");
	for(i = 0; i < ck_len; i++) { printf("%s%d", i?" ":"", ck_buf[i]); }
	printf("}\n");

	oid = NULL;
	rval = ber_decode(&asn1_DEF_RELATIVE_OID, (void *)&oid, buf, len);
	assert(rval.code == RC_OK);

	assert(oid->size == len - 2);

	/*
	 * Print the contents for visual debugging.
	 */
	printf("RELATIVE_OID_print() => ");
	RELATIVE_OID_print(&asn1_DEF_RELATIVE_OID, oid, 0, _print, 0);
	printf("\n");

	alen = RELATIVE_OID_get_arcs_l(oid,
		arcs, sizeof(arcs)/sizeof(arcs[0]));
	assert(alen > 0);
	assert(alen == ck_len);

	/*
	 * Make sure they are equivalent.
	 */
	printf("RELATIVE_OID_get_arcs() => {");
	for(i = 0; i < alen; i++) {
		printf(" %lu", (unsigned long)arcs[i]);
		assert(arcs[i] == ck_buf[i]);
	}
	printf(" }\n");
}

/*
 * Encode the specified array of arcs as RELATIVE-OID, decode it and compare.
 */
static void
check_REGEN(int *arcs, int acount) {
	static RELATIVE_OID_t oid;
	unsigned long tmp_arcs[10];
	int tmp_alen = 10;
	int alen;
	int ret;
	int i;

	printf("Encoding {");
	for(i = 0; i < acount; i++) {
		printf(" %u", arcs[i]);
	}
	printf(" }\n");

	ret = RELATIVE_OID_set_arcs_l(&oid, (unsigned long *)arcs, acount);
	assert(ret == 0);

	alen = RELATIVE_OID_get_arcs_l(&oid, tmp_arcs, tmp_alen);
	assert(alen >= 0);
	assert(alen < tmp_alen);

	printf("Encoded {");
	for(i = 0; i < alen; i++) {
		printf(" %lu", tmp_arcs[i]);
		assert(arcs[i] == tmp_arcs[i]);
	}
	printf(" }\n");
}

/*
 * Encode the specified array of arcs as OBJECT IDENTIFIER,
 * decode it and compare.
 */
static void
check_REGEN_OID(int *arcs, int acount) {
	static OBJECT_IDENTIFIER_t oid;
	unsigned long tmp_arcs[10];
	int tmp_alen = 10;
	int alen;
	int ret;
	int i;

	printf("Encoding {");
	for(i = 0; i < acount; i++) {
		printf(" %u", arcs[i]);
	}
	printf(" }\n");

	ret = OBJECT_IDENTIFIER_set_arcs_l(&oid, (unsigned long *)arcs, acount);
	assert(ret == 0);

	alen = OBJECT_IDENTIFIER_get_arcs_l(&oid, tmp_arcs, tmp_alen);
	assert(alen >= 0);
	assert(alen < tmp_alen);

	printf("Encoded {");
	for(i = 0; i < alen; i++) {
		printf(" %lu", tmp_arcs[i]);
		assert(arcs[i] == tmp_arcs[i]);
	}
	printf(" }\n");
}

#define	CHECK_OID(n)	check_OID(buf ## n, sizeof(buf ## n),		\
		buf ## n ## _check,					\
		sizeof(buf ## n ## _check)/sizeof(buf ## n ## _check[0]))
#define	CHECK_ROID(n)	check_ROID(buf ## n, sizeof(buf ## n),		\
		buf ## n ## _check,					\
		sizeof(buf ## n ## _check)/sizeof(buf ## n ## _check[0]))
#define	CHECK_REGEN(n) check_REGEN(buf ## n ## _check,			\
		sizeof(buf ## n ## _check)/sizeof(buf ## n ## _check[0]))
#define	CHECK_REGEN_OID(n) check_REGEN_OID(buf ## n ## _check,		\
		sizeof(buf ## n ## _check)/sizeof(buf ## n ## _check[0]))

int
main(int ac, char **av) {
	/* {joint-iso-itu-t 100 3} */
	uint8_t buf1[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x81, 0x34, 0x03
	};
	int buf1_check[] = { 2, 100, 3 };

	/* {8571 3 2} */
	uint8_t buf2[] = {
		0x0D,	/* RELATIVE-OID */
		0x04,	/* Length */
		0xC2, 0x7B, 0x03, 0x02
	};
	int buf2_check[] = { 8571, 3, 2 };

	int buf3_check[] = { 0 };
	int buf4_check[] = { 1 };
	int buf5_check[] = { 80, 40 };
	int buf6_check[] = { 127 };
	int buf7_check[] = { 128 };
	int buf8_check[] = { 65535, 65536 };
	int buf9_check[] = { 100000, 0x20000, 1234, 256, 127, 128 };
	int buf10_check[] = { 0, 0xffffffff, 0xff00ff00, 0 };
	int buf11_check[] = { 0, 1, 2 };
	int buf12_check[] = { 1, 38, 3 };
	int buf13_check[] = { 0, 0, 0xf000 };


	CHECK_OID(1);	/* buf1, buf1_check */
	CHECK_ROID(2);	/* buf2, buf2_check */

	CHECK_REGEN(3);	/* Regenerate RELATIVE-OID */
	CHECK_REGEN(4);
	CHECK_REGEN(5);
	CHECK_REGEN(6);
	CHECK_REGEN(7);
	CHECK_REGEN(8);
	CHECK_REGEN(9);
	CHECK_REGEN(10);
	CHECK_REGEN_OID(1);	/* Regenerate OBJECT IDENTIFIER */
	CHECK_REGEN_OID(11);
	CHECK_REGEN_OID(12);
	CHECK_REGEN_OID(13);

	return 0;
}
