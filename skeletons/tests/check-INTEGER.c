#include <INTEGER.c>
#include <asn_codecs_prim.c>
#include <ber_decoder.c>
#include <ber_tlv_length.c>
#include <ber_tlv_tag.c>
#include <der_encoder.c>
#include <xer_decoder.c>
#include <xer_support.c>
#include <constraints.c>

static char *shared_scratch_start;

static int _print2buf(const void *buf, size_t size, void *key) {
	(void)key;
	memcpy(shared_scratch_start, buf, size);
	shared_scratch_start += size;
	*shared_scratch_start = '\0';	/* 0-termination */
	return 0;
}

static void
check(uint8_t *buf, int size, long check_long, int check_ret) {
	char scratch[128];
	char verify[32];
	INTEGER_t val;
	uint8_t *buf_end = buf + size;
	int ret;
	long rlong = 123;

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

	ret = asn_INTEGER2long(&val, &rlong);
	printf(" (%ld, %d) vs (%ld, %d)\n",
		rlong, ret, check_long, check_ret);
	assert(ret == check_ret);
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
	}

	shared_scratch_start = scratch;
	ret = INTEGER_print(&asn_DEF_INTEGER, &val, 0, _print2buf, scratch);
	assert(shared_scratch_start < scratch + sizeof(scratch));
	assert(ret == 0);
	ret = snprintf(verify, sizeof(verify), "%ld", check_long);
	assert(ret < sizeof(verify));
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

int
main(int ac, char **av) {
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
	CHECK(buf11, 0x80000000, 0);
	CHECK(buf12, -32768, 0);
	CHECK(buf13, -128, 0);

	return 0;
}
