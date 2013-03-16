#include <stdio.h>
#include <assert.h>
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
check_OID(uint8_t *buf, size_t len, int *ck_buf, int ck_len) {
	OBJECT_IDENTIFIER_t *oid;
	asn_dec_rval_t rval;
	unsigned long arcs[10];
	int alen;
	int i;

	printf("Checking {");
	for(i = 0; i < (int)len; i++) { printf("%s%02x", i?" ":"", buf[i]); }
	printf("} against {");
	for(i = 0; i < ck_len; i++) { printf("%s%d", i?" ":"", ck_buf[i]); }
	printf("}\n");

	oid = NULL;
	rval = ber_decode(0, &asn_DEF_OBJECT_IDENTIFIER, (void *)&oid, buf, len);
	assert(rval.code == RC_OK);

	assert(oid->size == (ssize_t)len - 2);

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
			assert(arcs[i] == (unsigned long)ck_buf[i]);
		}
	}
	printf(" }\n");
	assert(alen == ck_len);

}

static void
check_ROID(uint8_t *buf, size_t len, int *ck_buf, int ck_len) {
	RELATIVE_OID_t *oid;
	asn_dec_rval_t rval;
	unsigned long arcs[10];
	int alen;
	int i;

	printf("Checking {");
	for(i = 0; i < (ssize_t)len; i++) { printf("%s%02x", i?" ":"", buf[i]); }
	printf("} against {");
	for(i = 0; i < ck_len; i++) { printf("%s%d", i?" ":"", ck_buf[i]); }
	printf("}\n");

	oid = NULL;
	rval = ber_decode(0, &asn_DEF_RELATIVE_OID, (void *)&oid, buf, len);
	assert(rval.code == RC_OK);

	assert(oid->size == (ssize_t)len - 2);

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
		printf(" %lu", (unsigned long)arcs[i]);
		assert(arcs[i] == (unsigned long)ck_buf[i]);
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

	if(0) {
		fprintf(stderr, "Encoding (R) {");
		for(i = 0; i < acount; i++) {
			fprintf(stderr, " %u", arcs[i]);
		}
		fprintf(stderr, " }\n");
	}

	ret = RELATIVE_OID_set_arcs(&oid, arcs, sizeof(arcs[0]), acount);
	assert(ret == 0);

	memset(tmp_arcs, 'A', sizeof(tmp_arcs));
	alen = RELATIVE_OID_get_arcs(&oid, tmp_arcs,
		sizeof(tmp_arcs[0]), tmp_alen);
	assert(alen >= 0);
	assert(alen <= tmp_alen);
	assert(alen == acount);

	if(0) {
		fprintf(stderr, "Encoded  (R) { ");
		for(i = 0; i < alen; i++) {
			fprintf(stderr, "%lu ", tmp_arcs[i]); fflush(stdout);
			assert(arcs[i] == (int)tmp_arcs[i]);
		}
		fprintf(stderr, "}\n");
	}

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

	if(0) {
		fprintf(stderr, "Encoding (O) {");
		for(i = 0; i < acount; i++) {
			fprintf(stderr, " %u", arcs[i]);
		}
		fprintf(stderr, " }\n");
	}

	ret = OBJECT_IDENTIFIER_set_arcs(&oid, arcs, sizeof(arcs[0]), acount);
	assert(ret == 0);

	memset(tmp_arcs, 'A', sizeof(tmp_arcs));
	alen = OBJECT_IDENTIFIER_get_arcs(&oid,
		tmp_arcs, sizeof(tmp_arcs[0]), tmp_alen);
	assert(alen >= 0);
	assert(alen <= tmp_alen);
	assert(alen == acount);

	if(0) {
		fprintf(stderr, "Encoded  (O) { ");
		for(i = 0; i < alen; i++) {
			fprintf(stderr, "%lu ", tmp_arcs[i]); fflush(stdout);
			assert(arcs[i] == (int)tmp_arcs[i]);
		}
		fprintf(stderr, "}\n");
	}
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
	RELATIVE_OID_t **stp = &st;
	long arcs[10];
	int ret;
	int i;

	printf("[%s] => ", xer); fflush(stdout);
	rc = asn_DEF_RELATIVE_OID.xer_decoder(0,
		&asn_DEF_RELATIVE_OID, (void **)stp, "t",
			xer, strlen(xer));
	if(expect_arcs == -1) {
		if(rc.code != RC_OK) {
			printf("-1\n");
			return;
		}
	}
	assert(rc.code == RC_OK);

	ret = RELATIVE_OID_get_arcs(st, arcs, sizeof(arcs[0]),
			sizeof(arcs)/sizeof(arcs[0]));
	assert(ret < 10);
	if(expect_arcs == -1) {
		assert(ret == -1);
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
main() {
	int i;

	/* {joint-iso-itu-t 230 3} */
	uint8_t buf1[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x82, 0x36, 0x03
	};
	int buf1_check[] = { 2, 230, 3 };

	/* {8571 3 2} */
	uint8_t buf2[] = {
		0x0D,	/* RELATIVE-OID */
		0x04,	/* Length */
		0xC2, 0x7B, 0x03, 0x02
	};
	int buf2_check[] = { 8571, 3, 2 };

	/* {joint-iso-itu-t 42 } */
	uint8_t buf3[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x01,	/* Length */
		0x7A
	};
	int buf3_check[] = { 2, 42 };

	/* {joint-iso-itu-t 25957 } */
	uint8_t buf4[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x81, 0x80 + 0x4B, 0x35
	};
	int buf4_check[] = { 2, 25957 };

	int buf5_check[] = { 0 };
	int buf6_check[] = { 1 };
	int buf7_check[] = { 80, 40 };
	int buf8_check[] = { 127 };
	int buf9_check[] = { 128 };
	int buf10_check[] = { 65535, 65536 };
	int buf11_check[] = { 100000, 0x20000, 1234, 256, 127, 128 };
	int buf12_check[] = { 0, 0xffffffff, 0xff00ff00, 0 };
	int buf13_check[] = { 0, 1, 2 };
	int buf14_check[] = { 1, 38, 3 };
	int buf15_check[] = { 0, 0, 0xf000 };
	int buf16_check[] = { 0, 0, 0, 1, 0 };
	int buf17_check[] = { 2, 0xffffffAf, 0xff00ff00, 0 };
	int buf18_check[] = { 2, 2, 1, 1 };

	/* { joint-iso-itu-t 2 1 1 } */
	uint8_t buf19[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x03,	/* Length */
		0x52, 0x01, 0x01
	};
	int buf19_check[] = { 2, 2, 1, 1 };

	/* { joint-iso-itu-t 2 1 0 1 } */
	uint8_t buf20[] = {
		0x06,	/* OBJECT IDENTIFIER */
		0x04,	/* Length */
		0x52, 0x01, 0x00, 0x01
	};
	int buf20_check[] = { 2, 2, 1, 0, 1 };


	CHECK_OID(1);	/* buf1, buf1_check */
	CHECK_ROID(2);	/* buf2, buf2_check */
	CHECK_OID(3);	/* buf3, buf3_check */
	CHECK_OID(4);	/* buf4, buf4_check */
	CHECK_OID(19);	/* buf19, buf19_check */
	CHECK_OID(20);	/* buf20, buf20_check */

	CHECK_REGEN(5);	/* Regenerate RELATIVE-OID */
	CHECK_REGEN(6);
	CHECK_REGEN(7);
	CHECK_REGEN(8);
	CHECK_REGEN(9);
	CHECK_REGEN(10);
	CHECK_REGEN(11);
	CHECK_REGEN(12);
	CHECK_REGEN(13);
	CHECK_REGEN(14);
	CHECK_REGEN(15);
	CHECK_REGEN(16);
	CHECK_REGEN(17);
	CHECK_REGEN_OID(1);	/* Regenerate OBJECT IDENTIFIER */
	CHECK_REGEN_OID(3);	/* Regenerate OBJECT IDENTIFIER */
	CHECK_REGEN_OID(4);	/* Regenerate OBJECT IDENTIFIER */
	CHECK_REGEN_OID(13);
	CHECK_REGEN_OID(14);
	CHECK_REGEN_OID(15);
	CHECK_REGEN_OID(16);
	CHECK_REGEN_OID(17);
	CHECK_REGEN_OID(18);
	CHECK_REGEN_OID(19);
	CHECK_REGEN_OID(20);

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

	check_xer(-1, "<t></t>");
	check_xer(2, "<t>1.2</t>");
	check_xer(3, "<t>1.2.3</t>");
	check_xer(3, "<t> 1.2.3 </t>");
	check_xer(-1, "<t>1.2.3 1</t>");

	for(i = 0; i < 100000; i++) {
		int bufA_check[3] = { 2, i, rand() };
		int bufB_check[2] = { rand(), i * 121 };
		CHECK_REGEN(A);
		CHECK_REGEN_OID(A);
		CHECK_REGEN(B);
		if(i > 100) i++;
		if(i > 500) i++;
		if(i > 1000) i += 3;
		if(i > 5000) i += 151;
	}

	if(getenv("CHECK_SPEED")) {
		/* Useful for developers only */
		check_speed();
	}

	return 0;
}

