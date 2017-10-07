#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <sys/time.h>

#include <OBJECT_IDENTIFIER.h>
#include <RELATIVE-OID.h>

static int
_print(const void *buffer, size_t size, void *app_key) {
	(void)app_key;
	fwrite(buffer, size, 1, stdout);
	return 0;
}

static void
check_OID(int lineno, uint8_t *buf, size_t len, unsigned *ck_buf, int ck_len) {
	OBJECT_IDENTIFIER_t *oid;
	asn_dec_rval_t rval;
	unsigned long arcs[10];
	int alen;
	int i;

	printf("%03d: Checking {", lineno);
	for(i = 0; i < (int)len; i++) { printf("%s%02x", i?" ":"", buf[i]); }
	printf("} against {");
	for(i = 0; i < ck_len; i++) { printf("%s%u", i?" ":"", ck_buf[i]); }
	printf("}\n");

	oid = NULL;
	rval = ber_decode(0, &asn_DEF_OBJECT_IDENTIFIER, (void *)&oid, buf, len);
	assert(rval.code == RC_OK);

	assert((ssize_t)oid->size == (ssize_t)len - 2);

	/*
	 * Print the contents for visual debugging.
	 */
	printf("OBJECT_IDENTIFIER_print() => ");
	OBJECT_IDENTIFIER_print(&asn_DEF_OBJECT_IDENTIFIER, oid, 0, _print, 0);
	printf("\n");

	memset(arcs, 'A', sizeof(arcs));
	alen = OBJECT_IDENTIFIER_get_arcs(oid,
		arcs, sizeof(arcs[0]), sizeof(arcs)/sizeof(arcs[0]));
	assert(alen > 0);

	printf("OBJECT_IDENTIFIER_get_arcs() => {");
	/*
	 * Make sure they are equivalent.
	 */
	for(i = 0; i < alen; i++) {
		printf(" %lu", arcs[i]);
		if(alen == ck_len) {
			assert(arcs[i] == ck_buf[i]);
		}
	}
	printf(" }\n");
	assert(alen == ck_len);

	ASN_STRUCT_FREE(asn_DEF_OBJECT_IDENTIFIER, oid);
}

static void
check_ROID(int lineno, uint8_t *buf, size_t len, unsigned *ck_buf, int ck_len) {
	RELATIVE_OID_t *oid;
	asn_dec_rval_t rval;
	unsigned long arcs[10];
	int alen;
	int i;

	printf("%03d: Checking {", lineno);
	for(i = 0; i < (ssize_t)len; i++) { printf("%s%02x", i?" ":"", buf[i]); }
	printf("} against {");
	for(i = 0; i < ck_len; i++) { printf("%s%u", i?" ":"", ck_buf[i]); }
	printf("}\n");

	oid = NULL;
	rval = ber_decode(0, &asn_DEF_RELATIVE_OID, (void *)&oid, buf, len);
	assert(rval.code == RC_OK);

	assert((ssize_t)oid->size == (ssize_t)len - 2);

	/*
	 * Print the contents for visual debugging.
	 */
	printf("RELATIVE_OID_print() => ");
	RELATIVE_OID_print(&asn_DEF_RELATIVE_OID, oid, 0, _print, 0);
	printf("\n");

	memset(arcs, 'A', sizeof(arcs));
	alen = RELATIVE_OID_get_arcs(oid,
		arcs, sizeof(arcs[0]), sizeof(arcs)/sizeof(arcs[0]));
	assert(alen > 0);
	assert(alen == ck_len);

	/*
	 * Make sure they are equivalent.
	 */
	printf("RELATIVE_OID_get_arcs() => {");
	for(i = 0; i < alen; i++) {
		printf(" %lu", arcs[i]);
		assert(arcs[i] == ck_buf[i]);
	}
	printf(" }\n");
	ASN_STRUCT_FREE(asn_DEF_RELATIVE_OID, oid);
}

static int
check_speed() {
	uint8_t buf[] = { 0x80 | 7, 0x80 | 2, 0x80 | 3, 0x80 | 4, 13 };
	int ret = 0;
	int cycles = 100000000;
	double a, b, c;
	struct timeval tv;
	unsigned long value;
	int i;

	ret = OBJECT_IDENTIFIER_get_single_arc(buf, sizeof(buf), 0, &value, sizeof(value));
	assert(ret == 0);
	assert(value == 0x7040c20d);

	gettimeofday(&tv, 0);
	a = tv.tv_sec + tv.tv_usec / 1000000.0;
	for(i = 0; i < cycles; i++) {
		ret = OBJECT_IDENTIFIER_get_single_arc(buf, sizeof(buf), 0,
			&value, sizeof(value));
	}
	assert(ret == 0);
	assert(value == 0x7040c20d);
	gettimeofday(&tv, 0);
	b = tv.tv_sec + tv.tv_usec / 1000000.0;
	for(i = 0; i < cycles; i++) {
		ret = OBJECT_IDENTIFIER_get_single_arc(buf, sizeof(buf), 0,
			&value, sizeof(value));
	}
	assert(ret == 0);
	assert(value == 0x7040c20d);
	gettimeofday(&tv, 0);
	c = tv.tv_sec + tv.tv_usec / 1000000.0;

	a = b - a;
	b = c - b;
	printf("Time for single_arc(): %f\n", a);
	printf("Time for  get_arc_l(): %f\n", b);

	return 0;
}

static void check_parse(const char *oid_txt, int retval) {
	int ret;
	long l[2];
	const char *p = oid_txt - 13;
	assert(p < oid_txt);

	ret = OBJECT_IDENTIFIER_parse_arcs(oid_txt, -1, l, 2, &p);
	printf("[%s] => %d == %d\n", oid_txt, ret, retval);
	assert(ret == retval);
	assert(p >= oid_txt);
}

static void check_xer(int expect_arcs, char *xer) {
	asn_dec_rval_t rc;
	RELATIVE_OID_t *st = 0;
	long arcs[10];
	int ret;
	int i;

	printf("[%s] => ", xer); fflush(stdout);
	rc = asn_DEF_RELATIVE_OID.op->xer_decoder(0,
		&asn_DEF_RELATIVE_OID, (void **)&st, "t",
			xer, strlen(xer));
	if(expect_arcs == -1) {
		if(rc.code != RC_OK) {
			printf("-1\n");
			ASN_STRUCT_FREE(asn_DEF_RELATIVE_OID, st);
			return;
		}
	}
	assert(rc.code == RC_OK);

	ret = RELATIVE_OID_get_arcs(st, arcs, sizeof(arcs[0]),
			sizeof(arcs)/sizeof(arcs[0]));
	assert(ret < 10);
	if(expect_arcs == -1) {
		assert(ret == -1);
		ASN_STRUCT_FREE(asn_DEF_RELATIVE_OID, st);
		return;
	}
	for(i = 0; i < ret; i++) {
		if(i) printf(".");
		printf("%ld", arcs[i]);
		if(arcs[i] != i + 1) printf(" != %d\n", i + 1);
		assert(arcs[i] == i + 1);
	}
	printf(": %d == %d\n", ret, expect_arcs);
	assert(ret == expect_arcs);
	ASN_STRUCT_FREE(asn_DEF_RELATIVE_OID, st);
}

#define CHECK_OID(n)                                            \
    check_OID(__LINE__, buf##n, sizeof(buf##n), buf##n##_check, \
              sizeof(buf##n##_check) / sizeof(buf##n##_check[0]))
#define CHECK_ROID(n)                                            \
    check_ROID(__LINE__, buf##n, sizeof(buf##n), buf##n##_check, \
               sizeof(buf##n##_check) / sizeof(buf##n##_check[0]))

static void
check_binary_parsing() {

    /* {joint-iso-itu-t 230 3} */
	uint8_t buf1[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x82, 0x36, 0x03
	};
	unsigned buf1_check[] = { 2, 230, 3 };

	/* {8571 3 2} */
	uint8_t buf2[] = {
		0x0D,	/* RELATIVE-OID */
		0x04,	/* Length */
		0xC2, 0x7B, 0x03, 0x02
	};
	unsigned buf2_check[] = { 8571, 3, 2 };

	/* {joint-iso-itu-t 42 } */
	uint8_t buf3[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x01,	/* Length */
		0x7A
	};
	unsigned buf3_check[] = { 2, 42 };

	/* {joint-iso-itu-t 25957 } */
	uint8_t buf4[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x81, 0x80 + 0x4B, 0x35
	};
	unsigned buf4_check[] = { 2, 25957 };

	/* { jounsigned-iso-itu-t 2 1 1 } */
	uint8_t buf5[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x52, 0x01, 0x01
	};
	unsigned buf5_check[] = { 2, 2, 1, 1 };

	/* { jounsigned-iso-itu-t 2 1 0 1 } */
	uint8_t buf6[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x04,	/* Length */
		0x52, 0x01, 0x00, 0x01
	};
	unsigned buf6_check[] = { 2, 2, 1, 0, 1 };

	CHECK_OID(1);
	CHECK_ROID(2);
	CHECK_OID(3);
	CHECK_OID(4);
	CHECK_OID(5);
	CHECK_OID(6);
}

static void
check_text_parsing() {
    check_parse("", 0);
    check_parse(" ", 0);
	check_parse(".", -1);
	check_parse(" .", -1);
	check_parse(".1", -1);
	check_parse("1.", -1);
	check_parse("1. ", -1);
	check_parse(".1. ", -1);
	check_parse(" .1. ", -1);
	check_parse(" 1", 1);
	check_parse(" 1.2", 2);
	check_parse(" 1.", -1);
	check_parse(" 1. ", -1);
	check_parse("1. ", -1);
	check_parse("1.2", 2);
	check_parse("1.2 ", 2);
	check_parse("1.2  ", 2);
	check_parse("  1.2  ", 2);
	check_parse("1. 2", -1);
	check_parse("1 .2", -1);
	check_parse(" 1 .2", -1);
	check_parse(" 1 .2 ", -1);
	check_parse("1 .2 ", -1);
	check_parse("1.+1", -1);
	check_parse("10.30.234.234", 4);
	check_parse("10.30.234.234 ", 4);
	check_parse("10.30.234. 234 ", -1);
	check_parse("10.30.234.234.", -1);
	check_parse("1.2000000000.3", 3);
	check_parse("1.2147483647.3", 3);
	if(sizeof(long) == 4) {
		check_parse("1.2147483648.3", -1);	/* overflow on ILP32 */
		check_parse("1.2147483649.3", -1);	/* overflow on ILP32 */
		check_parse("1.3000000000.3", -1);
		check_parse("1.4000000000.3", -1);
		check_parse("1.5000000000.3", -1);
		check_parse("1.6000000000.3", -1);
		check_parse("1.9000000000.3", -1);
	} else if(sizeof(long) == 8) {
		check_parse("1.2147483648.3", 3);
		check_parse("1.9223372036854775807.3", 3);
		check_parse("1.9223372036854775808.3", -1);
	}
	check_parse("1.900a0000000.3", -1);
	check_parse("1.900a.3", -1);
}

static void
check_xer_parsing() {
	check_xer(-1, "<t></t>");
	check_xer(2, "<t>1.2</t>");
	check_xer(3, "<t>1.2.3</t>");
	check_xer(3, "<t> 1.2.3 </t>");
	check_xer(-1, "<t>1.2.3 1</t>");
}

int
main() {
    check_binary_parsing();
    check_text_parsing();
    check_xer_parsing();

	if(getenv("CHECK_SPEED")) {
		/* Useful for developers only */
		check_speed();
	}

	return 0;
}

