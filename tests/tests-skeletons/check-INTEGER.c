#include <stdio.h>
#include <assert.h>

#include <asn_application.h>
#include <INTEGER.h>

#define CHECK_XER(a,b,c)        check_xer(__LINE__, a, b, c)

static char *shared_scratch_start;

static int _print2buf(const void *buf, size_t size, void *key) {
	(void)key;
	memcpy(shared_scratch_start, buf, size);
	shared_scratch_start += size;
	*shared_scratch_start = '\0';	/* 0-termination */
	return 0;
}

static void
check(uint8_t *buf, size_t size, long check_long, int check_ret) {
	char scratch[128];
	char verify[32];
	INTEGER_t val;
	uint8_t *buf_end = buf + size;
	int ret;
	long rlong = 123;

	assert(buf);
	assert(size > 0);

	val.buf = buf;
	val.size = size;

	printf("Testing: [");
	for(; buf < buf_end; buf++) {
		if(buf != val.buf) printf(":");
		printf("%02x", *buf);
	}
	printf("]: ");

	ret = asn_INTEGER2long(&val, &rlong);
	printf(" (%ld, %d) vs (%ld, %d)\n",
		rlong, ret, check_long, check_ret);
	assert(ret == check_ret);
	printf("%ld %ld\n", rlong, check_long);
	assert(rlong == check_long);

	if(check_ret == 0) {
		INTEGER_t val2;
		long rlong2;
		val2.buf = 0;
		val2.size = 0;
		ret = asn_long2INTEGER(&val2, rlong);
		assert(ret == 0);
		assert(val2.buf);
		assert(val2.size <= val.size);	/* At least as compact */
		ret = asn_INTEGER2long(&val, &rlong2);
		assert(ret == 0);
		assert(rlong == rlong2);
		ASN_STRUCT_RESET(asn_DEF_INTEGER, &val2);
	}

	shared_scratch_start = scratch;
	ret = INTEGER_print(&asn_DEF_INTEGER, &val, 0, _print2buf, scratch);
	assert(shared_scratch_start < scratch + sizeof(scratch));
	assert(ret == 0);
	ret = snprintf(verify, sizeof(verify), "%ld", check_long);
	assert(ret < 0 || (size_t)ret < sizeof(verify));
	ret = strcmp(scratch, verify);
	printf("         [%s] vs [%s]: %d%s\n",
		scratch, verify, ret,
		(check_ret == -1)?" (expected to fail)":""
		);
	if(check_ret == -1) {
		assert(strcmp(scratch, verify));
	} else {
		assert(strcmp(scratch, verify) == 0);
	}
}

static void
check_unsigned(uint8_t *buf, int size, unsigned long check_long, int check_ret) {
	char scratch[128];
	char verify[32];
	INTEGER_t val;
	uint8_t *buf_end = buf + size;
	int ret;
	unsigned long rlong = 123;

	assert(buf);
	assert(size >= 0);

	val.buf = buf;
	val.size = size;

	printf("Testing: [");
	for(; buf < buf_end; buf++) {
		if(buf != val.buf) printf(":");
		printf("%02x", *buf);
	}
	printf("]: ");

	ret = asn_INTEGER2ulong(&val, &rlong);
	printf(" (%lu, %d) vs (%lu, %d)\n",
		rlong, ret, check_long, check_ret);
	assert(ret == check_ret);
	assert(rlong == check_long);

	if(check_ret == 0) {
		INTEGER_t val2;
		unsigned long rlong2;
		val2.buf = 0;
		val2.size = 0;
		ret = asn_ulong2INTEGER(&val2, rlong);
		assert(ret == 0);
		assert(val2.buf);
		if(val2.size > val.size) {
			/* At least as compact */
			printf("val2.size=%d, val.size=%d\n",
				(int)val2.size, (int)val.size);
			assert(val2.size <= val.size);
		}
		ret = asn_INTEGER2ulong(&val, &rlong2);
		assert(ret == 0);
		assert(rlong == rlong2);
		ASN_STRUCT_RESET(asn_DEF_INTEGER, &val2);
	}

	return;

	shared_scratch_start = scratch;
	ret = INTEGER_print(&asn_DEF_INTEGER, &val, 0, _print2buf, scratch);
	assert(shared_scratch_start < scratch + sizeof(scratch));
	assert(ret == 0);
	ret = snprintf(verify, sizeof(verify), "%lu", check_long);
	assert(ret < (int)sizeof(verify));
	ret = strcmp(scratch, verify);
	printf("         [%s] vs [%s]: %d%s\n",
		scratch, verify, ret,
		(check_ret == -1)?" (expected to fail)":""
		);
	if(check_ret == -1) {
		assert(strcmp(scratch, verify));
	} else {
		assert(strcmp(scratch, verify) == 0);
	}
}

static void
check_xer(int lineno, int tofail, char *xmldata, long orig_value) {
	INTEGER_t *st = 0;
	asn_dec_rval_t rc;
	long value;
	int ret;

	printf("%03d: [%s] vs %ld: ", lineno, xmldata, orig_value);

	rc = xer_decode(0, &asn_DEF_INTEGER, (void *)&st,
		xmldata, strlen(xmldata));
	if(rc.code != RC_OK) {
		assert(tofail);
		printf("\tfailed, as expected\n");
		ASN_STRUCT_FREE(asn_DEF_INTEGER, st);
		return;
	}
        if(tofail) {
                printf("\tnot failed, as expected!\n");
	        assert(!tofail);
        }

	ret = asn_INTEGER2long(st, &value);
	assert(ret == 0);

	printf("\t%ld\n", value);

	assert(value == orig_value);

	ASN_STRUCT_FREE(asn_DEF_INTEGER, st);
}

int
main() {
	uint8_t buf1[] = { 1 };
	uint8_t buf2[] = { 0xff };
	uint8_t buf3[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
	uint8_t buf4[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0 };
	uint8_t buf5[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
	uint8_t buf6[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	uint8_t buf7[] = { 0xff, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	uint8_t buf8[] = { 0x7f, 0x7e, 0x7d, 0x7c };
	uint8_t buf9[] = { 0, 0x7f, 0x7e, 0x7d, 0x7c };
	uint8_t buf10[] = { 0, 0, 0, 0, 0, 0, 0x7f, 0x7e, 0x7d, 0x7c };
	uint8_t buf11[] = { 0x80, 0, 0, 0 };
	uint8_t buf12[] = { 0x80, 0 };
	uint8_t buf13[] = { 0x80 };
	uint8_t buf14[] = { 0x00, 0x80, 0x00, 0x00 };
	uint8_t buf15[] = { 0x00, 0x80, 0x00, 0x00, 0x00 };
	uint8_t buf16[] = { 0x00, 0xff, 0xff, 0x00, 0x00 };

#define	UCHECK(buf, val, ret)	check_unsigned(buf, sizeof(buf), val, ret)

#define	CHECK(buf, val, ret)	check(buf, sizeof(buf), val, ret)

	CHECK(buf1, 1, 0);
	CHECK(buf2, -1, 0);
	CHECK(buf3, -1, 0);
	CHECK(buf4, -16, 0);
	CHECK(buf5, 257, 0);
	CHECK(buf6, 123, -1);
	CHECK(buf7, 123, -1);
	CHECK(buf8, 0x7F7E7D7C, 0);
	CHECK(buf9, 0x7F7E7D7C, 0);
	CHECK(buf10, 0x7F7E7D7C, 0);
	UCHECK(buf10, 0x7F7E7D7C, 0);
	CHECK(buf11, -2147483647-1, 0);	/* 0x80000000 */
	CHECK(buf12, -32768, 0);
	CHECK(buf13, -128, 0);
	UCHECK(buf14, 0x800000, 0);
	UCHECK(buf15, 0x80000000UL, 0);
	UCHECK(buf16, 0xffff0000UL, 0);

	CHECK_XER(-1, "", 0);
	CHECK_XER(-1, "<INTEGER></INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER> </INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>-</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>+</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>+-</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER> -</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER> +</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER> +-</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>- </INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>+ </INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>+- </INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER> - </INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER> + </INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER> +- </INTEGER>", 0);
	CHECK_XER(0, "<INTEGER>+0</INTEGER>", 0);
	CHECK_XER(0, "<INTEGER>-0</INTEGER>", 0);
	CHECK_XER(0, "<INTEGER>+1</INTEGER>", 1);
	CHECK_XER(0, "<INTEGER>-1</INTEGER>", -1);
	CHECK_XER(0, "<INTEGER>1</INTEGER>", 1);
	CHECK_XER(0, "<INTEGER>-15</INTEGER>", -15);
	CHECK_XER(0, "<INTEGER>+15</INTEGER>", 15);
	CHECK_XER(0, "<INTEGER>15</INTEGER>", 15);
	CHECK_XER(0, "<INTEGER> 15</INTEGER>", 15);
	CHECK_XER(0, "<INTEGER> 15 </INTEGER>", 15);
	CHECK_XER(0, "<INTEGER>15 </INTEGER>", 15);
	CHECK_XER(0, "<INTEGER> +15 </INTEGER>", 15);
	CHECK_XER(-1, "<INTEGER> +15 -</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER> +15 1</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>+ 15</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>12<z>34</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>12 <z>34</INTEGER>", 0);
	CHECK_XER(-1, "<INTEGER>12 <z></INTEGER>", 0);
	CHECK_XER(0, "<INTEGER>1234</INTEGER>", 1234);
	CHECK_XER(-1, "<INTEGER>1234 5678</INTEGER>", 0);
	CHECK_XER(0, "<INTEGER>-2147483647</INTEGER>", -2147483647);
	CHECK_XER(0, "<INTEGER>-2147483648</INTEGER>", -2147483647-1);
	CHECK_XER(0, "<INTEGER>+2147483647</INTEGER>", 2147483647);
	CHECK_XER(0, "<INTEGER>2147483647</INTEGER>", 2147483647);
	if(sizeof(long) == 4) {
		CHECK_XER( 0, "<INTEGER>-2147483648</INTEGER>", -2147483648);
		CHECK_XER(-1, "<INTEGER>-2147483649</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>2147483648</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>2147483649</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>3147483649</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>4147483649</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>5147483649</INTEGER>", 0); /* special */
		CHECK_XER(-1, "<INTEGER>9147483649</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>9999999999</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>-5147483649</INTEGER>", 0);/* special */
		CHECK_XER(-1, "<INTEGER>-9147483649</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>-9999999999</INTEGER>", 0);
	}
#ifdef  TEST_64BIT
	if(sizeof(long) == 8) {
		CHECK_XER(0, "<INTEGER>2147483648</INTEGER>", 2147483648);
		CHECK_XER(0, "<INTEGER>2147483649</INTEGER>", 2147483649);
		CHECK_XER(0, "<INTEGER>3147483649</INTEGER>", 3147483649);
		CHECK_XER(0, "<INTEGER>4147483649</INTEGER>", 4147483649);
		CHECK_XER(0, "<INTEGER>5147483649</INTEGER>", 5147483649);
		CHECK_XER(0, "<INTEGER>9147483649</INTEGER>", 9147483649);
		CHECK_XER(0, "<INTEGER>9999999999</INTEGER>", 9999999999);
		CHECK_XER(0, "<INTEGER>9223372036854775807</INTEGER>", 9223372036854775807);
		CHECK_XER(-1, "<INTEGER>9223372036854775808</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>10223372036854775807</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>50223372036854775807</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>100223372036854775807</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>500223372036854775807</INTEGER>", 0);
		CHECK_XER(0, "<INTEGER>-9223372036854775808</INTEGER>", -9223372036854775807-1);
		CHECK_XER(-1, "<INTEGER>-9223372036854775809</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>-10223372036854775807</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>-50223372036854775807</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>-100223372036854775807</INTEGER>", 0);
		CHECK_XER(-1, "<INTEGER>-500223372036854775807</INTEGER>", 0);
	} else {
                assert(sizeof(long) == 8);
        }
#endif

	return 0;
}
