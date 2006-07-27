#define	EMIT_ASN_DEBUG	1
#include <REAL.c>
#include <asn_codecs_prim.c>
#include <ber_decoder.c>
#include <ber_tlv_length.c>
#include <ber_tlv_tag.c>
#include <der_encoder.c>
#include <xer_decoder.c>
#include <xer_support.c>
#include <xer_encoder.c>
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
		printf("Checking %f->[%s] against [%s]%s\n",
			d, reconstructed[0], sample,
			canonical_sample ? " (canonical follows...)" : ""
		);
		assert(!strcmp(reconstructed[0], sample));
	}
	if(canonical_sample) {
		printf("Checking %f->[%s] against [%s] (canonical)\n",
			d, reconstructed[1], canonical_sample);
		assert(!strcmp(reconstructed[1], canonical_sample));
	}
}

static void
check_impl(REAL_t *rn, double orig_dbl, const char *sample, const char *canonical_sample, int line) {
	double val;
	uint8_t *p, *end;
	int ret;

	printf("Line %d: double value %.12f [", line, orig_dbl);
	for(p = (uint8_t *)&orig_dbl, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("] (ilogb %d)\n", ilogb(orig_dbl));

	val = frexp(orig_dbl, &ret);
	printf("frexp(%f, %d): [", val, ret);
	for(p = (uint8_t *)&val, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("]\n");

	ret = asn_double2REAL(rn, orig_dbl);
	assert(ret == 0);

	printf("converted into [");
	for(p = rn->buf, end = p + rn->size; p < end; p++)
		printf("%02x", *p);
	printf("]: %d\n", rn->size);

	ret = asn_REAL2double(rn, &val);
	assert(ret == 0);

	printf("and back to double: [");
	for(p = (uint8_t *)&val, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("] (ilogb %d)\n", ilogb(val));

	printf("%.12f vs %.12f\n", val, orig_dbl);
	assert((isnan(orig_dbl) && isnan(val)) || val == orig_dbl);
	printf("OK\n");

	check_str_repr(val, sample, canonical_sample);
}

uint8_t buf_1_0[]  = { 0x80, 0xcc, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
uint8_t buf_1_1[]  = { 0x80, 0xcc, 0x11, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9a };
uint8_t buf_3_14[] = { 0x80, 0xcd, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f };
/* These ones are very interesting! They check mantissa overflow! */
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

	ret = asn_double2REAL(&rn, verify);
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

	ret = asn_REAL2double(&rn, &val);
	assert(ret == 0);

	printf("%.12f vs %.12f\n", verify, val);

	assert(val == verify);

	check_str_repr(val, sample, canonical_sample);
}

static void
check_xer(int fuzzy, double orig_value) {
	asn_enc_rval_t er;
	asn_dec_rval_t rc;
	REAL_t st;
	REAL_t *newst0 = 0;
	REAL_t *newst1 = 0;
	REAL_t **newst0p = &newst0;
	REAL_t **newst1p = &newst1;
	double value0, value1;
	int ret;

	memset(&st, 0, sizeof(st));
	ret = asn_double2REAL(&st, orig_value);
	assert(ret == 0);

	reconstr_lens[0] = 0;
	reconstr_lens[1] = 0;
	er = xer_encode(&asn_DEF_REAL, &st,
		XER_F_BASIC, callback, 0);
	assert(er.encoded == reconstr_lens[0]);
	er = xer_encode(&asn_DEF_REAL, &st,
		XER_F_CANONICAL, callback, (void *)1);
	assert(er.encoded == reconstr_lens[1]);
	reconstructed[0][reconstr_lens[0]] = 0;
	reconstructed[1][reconstr_lens[1]] = 0;

	printf("%f vs (%d)[%s] & (%d)%s",
		orig_value,
		reconstr_lens[1], reconstructed[1],
		reconstr_lens[0], reconstructed[0]
	);

	rc = xer_decode(0, &asn_DEF_REAL, (void **)newst0p,
		reconstructed[0], reconstr_lens[0]);
	assert(rc.code == RC_OK);
	assert(rc.consumed < reconstr_lens[0]);

	rc = xer_decode(0, &asn_DEF_REAL, (void **)newst1p,
		reconstructed[1], reconstr_lens[1]);
	assert(rc.code == RC_OK);
	assert(rc.consumed == reconstr_lens[1]);

	ret = asn_REAL2double(newst0, &value0);
	assert(ret == 0);
	ret = asn_REAL2double(newst1, &value1);
	assert(ret == 0);

	assert((isnan(value0) && isnan(orig_value))
		|| value0 == orig_value
		|| fuzzy);
	assert((isnan(value1) && isnan(orig_value))
		|| value1 == orig_value);

	assert(newst0->size == st.size || fuzzy);
	assert(newst1->size == st.size);
	assert(fuzzy || memcmp(newst0->buf, st.buf, st.size) == 0);
	assert(memcmp(newst1->buf, st.buf, st.size) == 0);
}

#define	check(rn, d, str1, str2)	\
	check_impl(rn, d, str1, str2, __LINE__)

int
main() {
	REAL_t rn;
	static const double zero = 0.0;

	memset(&rn, 0, sizeof(rn));

	check(&rn, 0.0, "0", "0");
	check(&rn, -0.0, "-0", "-0");	/* minus-zero */
	check(&rn, zero/zero, "<NOT-A-NUMBER/>", "<NOT-A-NUMBER/>");
	check(&rn, 1.0/zero, "<PLUS-INFINITY/>", "<PLUS-INFINITY/>");
	check(&rn, -1.0/zero, "<MINUS-INFINITY/>", "<MINUS-INFINITY/>");
	check(&rn, 1.0, "1.0", "1.0E0");
	check(&rn, -1.0, "-1.0", "-1.0E0");
	check(&rn, 0.1, "0.1", "1.0E-1");
	check(&rn, 0.01, "0.01", "1.0E-2");
	check(&rn, 0.02, "0.02", "2.0E-2");
	check(&rn, 0.09, "0.09", "9.0E-2");
	check(&rn, 1.5, "1.5", "1.5E0");
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
	check(&rn, 0.00000000001, "0.00000000001", "9.999999999999999E-12");
	check(&rn, 0.00000000002, "0.00000000002", "2.0E-11");
	check(&rn, 0.00000000009, "0.00000000009", "9.0E-11");
	check(&rn, 0.000000000002, "0.000000000002", "2.0E-12");
	check(&rn, 0.0000000000002, "0.0000000000002", "2.0E-13");
	check(&rn, 0.00000000000002, "0.00000000000002", "2.0E-14");
	check(&rn, 0.000000000000002, "0.000000000000002", "2.0E-15");
	check(&rn, 0.0000000000000002, "0.0", "2.0E-16");
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


#ifdef	NAN
	check_xer(0, NAN);	/* "<NOT-A-NUMBER/>" */
#else
	check_xer(0, zero/zero);	/* "<NOT-A-NUMBER/>" */
#endif
#ifdef	INFINITY
	check_xer(0, INFINITY);		/* "<PLUS-INFINITY/>" */
	check_xer(0, -INFINITY);	/* "<MINUS-INFINITY/>" */
#else
	check_xer(0, 1.0/zero);		/* "<PLUS-INFINITY/>" */
	check_xer(0, -1.0/zero);	/* "<MINUS-INFINITY/>" */
#endif
	check_xer(0, 1.0);
	check_xer(0, -1.0);
	check_xer(0, 1.5);
	check_xer(0, 123);
	check_xer(1, 0.0000000000000000000001);
	check_xer(1, -0.0000000000000000000001);

	return 0;
}
