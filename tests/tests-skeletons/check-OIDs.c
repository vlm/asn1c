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
	uint32_t arcs[10];
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
    alen =
        OBJECT_IDENTIFIER_get_arcs(oid, arcs, sizeof(arcs) / sizeof(arcs[0]));
    assert(alen > 0);

	printf("OBJECT_IDENTIFIER_get_arcs() => {");
	/*
	 * Make sure they are equivalent.
	 */
	for(i = 0; i < alen; i++) {
        printf(" %" PRIu32, arcs[i]);
        if(alen == ck_len) {
			assert(arcs[i] == ck_buf[i]);
		}
	}
	printf(" }\n");
	assert(alen == ck_len);

	ASN_STRUCT_FREE(asn_DEF_OBJECT_IDENTIFIER, oid);
}

static void
check_ROID(int lineno, uint8_t *buf, size_t len, unsigned *ck_buf,
           size_t ck_len) {
    RELATIVE_OID_t *oid;
	asn_dec_rval_t rval;
	uint32_t arcs[10];
	int alen;
	size_t i;

	printf("%03d: Checking {", lineno);
	for(i = 0; i < len; i++) { printf("%s%02x", i?" ":"", buf[i]); }
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
    alen = RELATIVE_OID_get_arcs(oid, arcs, sizeof(arcs) / sizeof(arcs[0]));
    assert(alen > 0);
	assert((size_t)alen == ck_len);

	/*
	 * Make sure they are equivalent.
	 */
	printf("RELATIVE_OID_get_arcs() => {");
	for(i = 0; i < (size_t)alen; i++) {
        printf(" %" PRIu32, arcs[i]);
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
	uint32_t value;
	int i;

    ret = OBJECT_IDENTIFIER_get_single_arc(buf, sizeof(buf), &value);
    assert(ret == 0);
	assert(value == 0x7040c20d);

	gettimeofday(&tv, 0);
	a = tv.tv_sec + tv.tv_usec / 1000000.0;
	for(i = 0; i < cycles; i++) {
		ret = OBJECT_IDENTIFIER_get_single_arc(buf, sizeof(buf), &value);
	}
	assert(ret == 0);
	assert(value == 0x7040c20d);
	gettimeofday(&tv, 0);
	b = tv.tv_sec + tv.tv_usec / 1000000.0;
	for(i = 0; i < cycles; i++) {
        ret = OBJECT_IDENTIFIER_get_single_arc(buf, sizeof(buf), &value);
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

#define CHECK_PARSE(a, b) check_parse(__LINE__, a, b)
static void check_parse(int lineno, const char *oid_txt, int retval) {
	int ret;
	uint32_t arcs[2];
	const char *p = oid_txt - 13;
	assert(p < oid_txt);

	ret = OBJECT_IDENTIFIER_parse_arcs(oid_txt, -1, arcs, 2, &p);
	printf("%03d: [%s] => %d == %d\n", lineno, oid_txt, ret, retval);
	assert(ret == retval);
	assert(p >= oid_txt);
}

static void
check_xer(int lineno, asn_TYPE_descriptor_t *td, ssize_t expect_arcs, char *xer,
          const asn_oid_arc_t *expected_arcs) {
    asn_dec_rval_t rc;
    void *st = 0;
    uint32_t arcs[10];
    ssize_t got_arcs;
    ssize_t i;

    printf("%03d: [%s] => ", lineno, xer);
    fflush(stdout);
    rc = td->op->xer_decoder(0, td, (void **)&st, "t", xer, strlen(xer));
    if(expect_arcs == -1) {
		if(rc.code != RC_OK) {
			printf("-1\n");
			ASN_STRUCT_FREE(*td, st);
			return;
		}
	}
	assert(rc.code == RC_OK);

    if(td == &asn_DEF_OBJECT_IDENTIFIER) {
        got_arcs = OBJECT_IDENTIFIER_get_arcs(st, arcs,
                                              sizeof(arcs) / sizeof(arcs[0]));
    } else if(td == &asn_DEF_RELATIVE_OID) {
        got_arcs =
            RELATIVE_OID_get_arcs(st, arcs, sizeof(arcs) / sizeof(arcs[0]));
    } else {
        assert(!"Unreachable");
    }
	assert(got_arcs < 10);
	if(expect_arcs == -1) {
		assert(got_arcs == -1);
		ASN_STRUCT_FREE(*td, st);
		return;
	}
	for(i = 0; i < got_arcs; i++) {
		if(i) printf(".");
        printf("%" PRIu32, arcs[i]);
        if(arcs[i] != expected_arcs[i]) {
            printf(" != %" PRIu32 "\n", expected_arcs[i]);
        }
        assert(arcs[i] == expected_arcs[i]);
	}
	printf(": %zd == %zd\n", got_arcs, expect_arcs);
	assert(got_arcs == expect_arcs);
	ASN_STRUCT_FREE(*td, st);
}

#define CHECK_OID(n)                                            \
    check_OID(__LINE__, buf##n, sizeof(buf##n), buf##n##_check, \
              sizeof(buf##n##_check) / sizeof(buf##n##_check[0]))
#define CHECK_ROID(n)                                            \
    check_ROID(__LINE__, buf##n, sizeof(buf##n), buf##n##_check, \
               sizeof(buf##n##_check) / sizeof(buf##n##_check[0]))

static void
check_binary_parsing() {

    /* {0 0} */
	uint8_t buf0[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x01,	/* Length */
		0x00
	};
	uint32_t buf0_check[] = { 0, 0 };

    /* {joint-iso-itu-t 230 3} */
	uint8_t buf1[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x82, 0x36, 0x03
	};
	uint32_t buf1_check[] = { 2, 230, 3 };

	/* {joint-iso-itu-t 42 } */
	uint8_t buf2[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x01,	/* Length */
		0x7A
	};
	uint32_t buf2_check[] = { 2, 42 };

	/* {joint-iso-itu-t 25957 } */
	uint8_t buf3[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x81, 0x80 + 0x4B, 0x35
	};
	uint32_t buf3_check[] = { 2, 25957 };

	/* { jounsigned-iso-itu-t 2 1 1 } */
	uint8_t buf4[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x52, 0x01, 0x01
	};
	uint32_t buf4_check[] = { 2, 2, 1, 1 };

	/* { jounsigned-iso-itu-t 2 1 0 1 } */
	uint8_t buf5[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x04,	/* Length */
		0x52, 0x01, 0x00, 0x01
	};
	uint32_t buf5_check[] = { 2, 2, 1, 0, 1 };

    /* {0 0} */
	uint8_t buf10[] = {
		0x0D,	/* RELATIVE-OID */
		0x01,	/* Length */
		0x00
	};
	uint32_t buf10_check[] = { 0 };

    /* {0 0} */
	uint8_t buf11[] = {
		0x0D,	/* RELATIVE-OID */
		0x02,	/* Length */
		0x00, 0x00
	};
	uint32_t buf11_check[] = { 0, 0 };

	/* {8571 3 2} */
	uint8_t buf12[] = {
		0x0D,	/* RELATIVE-OID */
		0x04,	/* Length */
		0xC2, 0x7B, 0x03, 0x02
	};
	uint32_t buf12_check[] = { 8571, 3, 2 };

	CHECK_OID(0);
	CHECK_OID(1);
	CHECK_OID(2);
	CHECK_OID(3);
	CHECK_OID(4);
	CHECK_OID(5);

	CHECK_ROID(10);
	CHECK_ROID(11);
	CHECK_ROID(12);
}

static void
check_text_parsing() {
    CHECK_PARSE("", 0);
    CHECK_PARSE(" ", 0);
	CHECK_PARSE(".", -1);
	CHECK_PARSE(" .", -1);
	CHECK_PARSE(".1", -1);
	CHECK_PARSE("1.", -1);
	CHECK_PARSE("1. ", -1);
	CHECK_PARSE(".1. ", -1);
	CHECK_PARSE(" .1. ", -1);
	CHECK_PARSE(" 1", 1);
	CHECK_PARSE(" 1.2", 2);
	CHECK_PARSE(" 1.", -1);
	CHECK_PARSE(" 1. ", -1);
	CHECK_PARSE("1. ", -1);
	CHECK_PARSE("1.2", 2);
	CHECK_PARSE("1.2 ", 2);
	CHECK_PARSE("1.2  ", 2);
	CHECK_PARSE("  1.2  ", 2);
	CHECK_PARSE("1. 2", -1);
	CHECK_PARSE("1 .2", -1);
	CHECK_PARSE(" 1 .2", -1);
	CHECK_PARSE(" 1 .2 ", -1);
	CHECK_PARSE("1 .2 ", -1);
	CHECK_PARSE("1.+1", -1);
	CHECK_PARSE("2.0", 2);
	CHECK_PARSE("2.1", 2);
	CHECK_PARSE("10.30.234.234", 4);
	CHECK_PARSE("10.30.234.234 ", 4);
	CHECK_PARSE("10.30.234. 234 ", -1);
	CHECK_PARSE("10.30.234.234.", -1);
	CHECK_PARSE("1.2000000000.3", 3);
	CHECK_PARSE("1.2147483647.3", 3);
    CHECK_PARSE("1.4294967295.3", 3);
    CHECK_PARSE("1.4294967296.3", -1); /* overflow on ILP32 */
    CHECK_PARSE("1.3000000000.3", 3);
    CHECK_PARSE("1.4000000000.3", 3);
    CHECK_PARSE("1.5000000000.3", -1);
    CHECK_PARSE("1.6000000000.3", -1);
    CHECK_PARSE("1.9000000000.3", -1);
	CHECK_PARSE("1.900a0000000.3", -1);
	CHECK_PARSE("1.900a.3", -1);
}

#define CHECK_XER(a, b, c, data) check_xer(__LINE__, &asn_DEF_##a, b, c, data)

static void
check_xer_parsing() {
    asn_oid_arc_t zero_zero[] = {0, 0};
    asn_oid_arc_t zero_one[] = {0, 1};
    asn_oid_arc_t one_zero[] = {1, 0};
    asn_oid_arc_t one_one[] = {1, 1};
    asn_oid_arc_t one_two[] = {1, 2};
    asn_oid_arc_t two_one[] = {2, 1};
    asn_oid_arc_t one_two_three[] = {1, 2,3};

    CHECK_XER(RELATIVE_OID, -1, "<t></t>", 0);
	CHECK_XER(RELATIVE_OID, -1, "<t>1.</t>", 0);
    CHECK_XER(RELATIVE_OID, -1, "<t>2.1.</t>", 0);
    CHECK_XER(RELATIVE_OID, 2, "<t>0.0</t>", zero_zero);
    CHECK_XER(RELATIVE_OID, 2, "<t>0.1</t>", zero_one);
    CHECK_XER(RELATIVE_OID, 2, "<t>1.0</t>", one_zero);
    CHECK_XER(RELATIVE_OID, 2, "<t>1.2</t>", one_two);
    CHECK_XER(RELATIVE_OID, -1, "<t>1.-2</t>", 0);
    CHECK_XER(RELATIVE_OID, -1, "<t>1.+2</t>", 0);
    CHECK_XER(RELATIVE_OID, 3, "<t>1.2.3</t>", one_two_three);
    CHECK_XER(RELATIVE_OID, 3, "<t> 1.2.3 </t>", one_two_three);
    CHECK_XER(RELATIVE_OID, -1, "<t>1.2.3 1</t>", 0);
	CHECK_XER(RELATIVE_OID, 2, "<t>2.1</t>", two_one);

	CHECK_XER(OBJECT_IDENTIFIER, -1, "<t></t>", 0);
	CHECK_XER(OBJECT_IDENTIFIER, -1, "<t>1</t>", 0);
	CHECK_XER(OBJECT_IDENTIFIER, -1, "<t>1.</t>", 0);
	CHECK_XER(OBJECT_IDENTIFIER, -1, "<t>2.1.</t>", 0);
    CHECK_XER(OBJECT_IDENTIFIER, 2, "<t>0.0</t>", zero_zero);
    CHECK_XER(OBJECT_IDENTIFIER, 2, "<t>0.1</t>", zero_one);
    CHECK_XER(OBJECT_IDENTIFIER, 2, "<t>1.0</t>", one_zero);
    CHECK_XER(OBJECT_IDENTIFIER, 2, "<t>1.1</t>", one_one);
    CHECK_XER(OBJECT_IDENTIFIER, 2, "<t>1.2</t>", one_two);
    CHECK_XER(OBJECT_IDENTIFIER, -1, "<t>1.-2</t>", 0);
    CHECK_XER(OBJECT_IDENTIFIER, -1, "<t>1.+2</t>", 0);
    CHECK_XER(OBJECT_IDENTIFIER, 3, "<t>1.2.3</t>", one_two_three);
    CHECK_XER(OBJECT_IDENTIFIER, 3, "<t> 1.2.3 </t>", one_two_three);
    CHECK_XER(OBJECT_IDENTIFIER, -1, "<t>1.2.3 1</t>", 0);
    CHECK_XER(OBJECT_IDENTIFIER, 2, "<t> 2.1 </t>", two_one);
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

