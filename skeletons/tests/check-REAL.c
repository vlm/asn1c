#define	EMIT_ASN_DEBUG	1
#include <REAL.c>
#include <ber_codec_prim.c>
#include <ber_decoder.c>
#include <ber_tlv_length.c>
#include <ber_tlv_tag.c>
#include <der_encoder.c>
#include <constraints.c>

static char reconstructed[2][512];
static int reconstr_lens[2];

static int
callback(const void *buffer, size_t size, void *app_key) {
	char *buf = reconstructed[app_key ? 1 : 0];
	int *len = &reconstr_lens[app_key ? 1 : 0];

	if(*len + size >= sizeof(reconstructed[0]))
		return -1;

	memcpy(buf + *len, buffer, size);
	*len += size;

	return 0;
}

static void
check_str_repr(double d, const char *sample, const char *canonical_sample) {
	ssize_t s1, s2;

	reconstr_lens[1] = reconstr_lens[0] = 0;

	s1 = REAL__dump(d, 0, callback, 0);
	assert(s1 < sizeof(reconstructed[0]));
	assert(s1 == reconstr_lens[0]);
	reconstructed[0][s1] = '\0';

	s2 = REAL__dump(d, 1, callback, (void *)1);
	assert(s2 < sizeof(reconstructed[1]));
	assert(s2 == reconstr_lens[1]);
	reconstructed[1][s2] = '\0';

	if(sample) {
		printf("Checking [%s] against [%s]\n",
			reconstructed[0], sample);
		assert(!strcmp(reconstructed[0], sample));
	}
	if(canonical_sample) {
		printf("Checking [%s] against [%s] (canonical)\n",
			reconstructed[1], canonical_sample);
		assert(!strcmp(reconstructed[1], canonical_sample));
	}
}

static void
check(REAL_t *rn, double orig_dbl, const char *sample, const char *canonical_sample) {
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
	printf("]: %d\n", rn->size);

	ret = asn1_REAL2double(rn, &val);
	assert(ret == 0);

	printf("and back to double: [");
	for(p = (uint8_t *)&val, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("] (ilogb %d)\n", ilogb(val));

	printf("%.12f vs %.12f\n", orig_dbl, val);
	assert(orig_dbl == val || (isnan(orig_dbl) && isnan(val)));
	printf("OK\n");

	check_str_repr(val, sample, canonical_sample);
}

uint8_t buf_1_0[]  = { 0x80, 0xcc, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t buf_1_1[]  = { 0x80, 0xcc, 0x11, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9a };
uint8_t buf_3_14[] = { 0x80, 0xcd, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f };
/* These ones are very interesting! It checks mantissa overflow! */
uint8_t buf_mo1[]  = { 0xC0, 0xc5, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f,3};
uint8_t buf_mo2[]  = { 0x80, 0xbd, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f,3,2};

static void
check_buf(uint8_t *buf, size_t bufsize, double verify, const char *sample, const char *canonical_sample) {
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

	check_str_repr(val, sample, canonical_sample);
}

int
main() {
	REAL_t rn;
	static const double c_NaN = 0.0;

	memset(&rn, 0, sizeof(rn));

	check(&rn, c_NaN/c_NaN, "<NOT-A-NUMBER/>", "<NOT-A-NUMBER/>");
	check(&rn, 0.0, "0", "0");
	check(&rn, -0.0, "-0", "-0");	/* minus-zero */
	check(&rn, 1.0, "1.0", "1.0E0");
	check(&rn, -1.0, "-1.0", "-1.0E0");
	check(&rn, 1.5, "1.5", "1.5E0");
	check(&rn, 0.1, "0.1", "1.0E-1");
	check(&rn, 0.33333, "0.33333", "3.3333E-1");
	check(&rn, 2, "2.0", "2.0E0");
	check(&rn, 2.1, "2.1", "2.1E0");
	check(&rn, 3, "3.0", "3.0E0");
	check(&rn, 3.1, "3.1", "3.1E0");
	check(&rn, 3.14, "3.14", "3.14E0");
	check(&rn, 3.1415, "3.1415", "3.1415E0");
	check(&rn, 3.141592, "3.141592", "3.141592E0");
	check(&rn, 3.14159265, "3.14159265", "3.14159265E0");
	check(&rn, -3.14159265, "-3.14159265", "-3.14159265E0");
	check(&rn, 14159265.0, "14159265.0", "1.4159265E7");
	check(&rn, -123456789123456789.0, "-123456789123456784.0", "-1.234567891234568E17");
	check(&rn, 0.00000000001, "0.0", "9.999999999999999E-12");
	check(&rn, 0.00000000002, "0.0", "2.0E-11");
	check(&rn, 0.00000000009, "0.0", "9.0E-11");
	check(&rn, 0.0000000000000000000001, "0.0", "1.0E-22");
	check(&rn, 0.000000000000000000000000000001, "0.0", "1.0E-30"); /* proved 2B a problem */
	check(&rn,-0.000000000000000000000000000001, "-0.0", "-1.0E-30"); /* proved 2B a problem */
	check(&rn, 0.0000000000010000000001000000000001, 0, 0);
	check(&rn, 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001, 0, 0);
	check(&rn, 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001, 0, 0);
	check(&rn,-0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001, 0, 0);
	check(&rn,-3.33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333, 0, 0);
	check(&rn, 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000033333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333, 0, 0);
	check(&rn, -0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001, 0, 0);

	check_buf(buf_1_0, sizeof(buf_1_0),	1.0, "1.0", "1.0E0");
	check_buf(buf_1_1, sizeof(buf_1_1),	1.1, "1.1", "1.1E0");
	check_buf(buf_3_14, sizeof(buf_3_14),	3.14, "3.14", "3.14E0");
	check_buf(buf_mo1, sizeof(buf_mo1),	-3.14, "-3.14", "-3.14E0");
	check_buf(buf_mo2, sizeof(buf_mo2),	3.14, "3.14", "3.14E0");

	return 0;
}
