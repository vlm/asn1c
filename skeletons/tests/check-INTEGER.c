#include "../INTEGER.c"
#include "../ber_decoder.c"
#include "../ber_tlv_length.c"
#include "../ber_tlv_tag.c"
#include "../der_encoder.c"
#include "../constraints.c"

static void
check(uint8_t *buf, int size, long check_long, int check_ret) {
	INTEGER_t val;
	int ret;
	long rlong = 123;

	assert(buf);
	assert(size >= 0);

	val.buf = buf;
	val.size = size;


	ret = asn1_INTEGER2long(&val, &rlong);
	printf("Testing (%ld, %d) vs (%ld, %d)\n",
		rlong, ret, check_long, check_ret);
	assert(ret == check_ret);
	if(ret == -1) return;
	assert(rlong == check_long);
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

	return 0;
}
