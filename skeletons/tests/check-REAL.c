#define	EMIT_ASN_DEBUG	1
#include <INTEGER.c>
#include <REAL.c>
#include <ber_decoder.c>
#include <ber_tlv_length.c>
#include <ber_tlv_tag.c>
#include <der_encoder.c>
#include <constraints.c>

static void
check(REAL_t *rn, double orig_dbl) {
	double val;
	uint8_t *p, *end;
	int ret;

	printf("double value %.12f [", orig_dbl);
	for(p = (uint8_t *)&orig_dbl, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("] (ilogb %d)\n", ilogb(orig_dbl));

	val = frexp(orig_dbl, &ret);
	printf("frexp(%f, %d): [", val, ret);
	for(p = (uint8_t *)&val, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("]\n");

	ret = asn1_double2REAL(rn, orig_dbl);
	assert(ret == 0);

	printf("converted into [");
	for(p = rn->buf, end = p + rn->size; p < end; p++)
		printf("%02x", *p);
	printf("]\n");

	ret = asn1_REAL2double(rn, &val);
	assert(ret == 0);

	printf("and back to double: [");
	for(p = (uint8_t *)&val, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("] (ilogb %d)\n", ilogb(val));

	printf("%.12f vs %.12f\n", orig_dbl, val);

	assert(orig_dbl == val);
	printf("OK\n");
}

uint8_t buf_1_0[]  = { 0x80, 0xcc, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t buf_1_1[]  = { 0x80, 0xcc, 0x11, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9a };
uint8_t buf_3_14[] = { 0x80, 0xcd, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f };
/* These ones are very interesting! It checks mantissa overflow! */
uint8_t buf_mo1[]  = { 0x80, 0xc5, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f,3};
uint8_t buf_mo2[]  = { 0x80, 0xbd, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f,3,2};

static void
check_buf(uint8_t *buf, size_t bufsize, double verify) {
	REAL_t rn;
	double val;
	uint8_t *p, *end;
	int ret;

	printf("verify double value %.12f [", verify);
	for(p = (uint8_t *)&verify, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("] (ilogb %d)\n", ilogb(verify));

	rn.buf = 0;
	rn.size = 0;

	ret = asn1_double2REAL(&rn, verify);
	assert(ret == 0);

	printf("canonical DER: [");
	for(p = rn.buf, end = p + rn.size; p < end; p++)
		printf("%02x", *p);
	printf("]\n");

	rn.buf = buf;
	rn.size = bufsize;

	printf("received as:   [");
	for(p = rn.buf, end = p + rn.size; p < end; p++)
		printf("%02x", *p);
	printf("]\n");

	ret = asn1_REAL2double(&rn, &val);
	assert(ret == 0);

	printf("%.12f vs %.12f\n", verify, val);

	assert(val == verify);
}

int
main() {
	REAL_t rn;

	memset(&rn, 0, sizeof(rn));

	check(&rn, 0.0);
	check(&rn, 1.0);
	check(&rn, -1.0);
	check(&rn, 1.5);
	check(&rn, 0.1);
	check(&rn, 0.33333);
	check(&rn, 2);
	check(&rn, 2.1);
	check(&rn, 3);
	check(&rn, 3.1);
	check(&rn, 3.14);
	check(&rn, 3.1415);
	check(&rn, 3.141592);
	check(&rn, 3.14159265);
	check(&rn, -3.14159265);
	check(&rn, 14159265.0);
	check(&rn, -123456789123456789.0);
	check(&rn, 0.00000000001);
	check(&rn, 0.00000000002);
	check(&rn, 0.00000000009);
	check(&rn, 0.0000000000000000000001);
	check(&rn, 0.000000000000000000000000000001); /* proved 2B a problem */
	check(&rn,-0.000000000000000000000000000001); /* proved 2B a problem */
	check(&rn, 0.0000000000010000000001000000000001);
	check(&rn, 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001);
	check(&rn, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001);
	check(&rn,-0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001);
	check(&rn,-3.33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333);
	check(&rn, 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000033333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333);
	check(&rn, -0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001);

	check_buf(buf_1_0, sizeof(buf_1_0),	1.0);
	check_buf(buf_1_1, sizeof(buf_1_1),	1.1);
	check_buf(buf_3_14, sizeof(buf_3_14),	3.14);
	check_buf(buf_mo1, sizeof(buf_mo1),	3.14);
	check_buf(buf_mo2, sizeof(buf_mo2),	3.14);

	return 0;
}
