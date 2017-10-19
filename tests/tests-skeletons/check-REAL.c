#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <float.h>

/* C11 specifies DBL_TRUE_MIN, might not be immediately available. */
#ifndef DBL_TRUE_MIN
#define DBL_TRUE_MIN    4.9406564584124654E-324
#endif

#include <REAL.h>

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

static char *
d2s(double d, int canonical) {
	ssize_t s;

	reconstr_lens[canonical] = 0;
	s = REAL__dump(d, canonical, callback, (void *)(ptrdiff_t)canonical);
	assert(s > 0 && (size_t)s < sizeof(reconstructed[canonical]));
	assert(s == reconstr_lens[canonical]);
	reconstructed[canonical][s] = '\0';	// ASCIIZ
	return reconstructed[canonical];
}

/*
 * Verify that a string representation of a given floating point value
 * is as given in the (sample) and (canonical_sample) arguments.
 */
static void
check_str_representation(double d, const char *sample,
                         const char *canonical_sample, int lineno) {
    char *s0, *s1;

    s0 = d2s(d, 0);
    s1 = d2s(d, 1);

    if(sample) {
        printf("%03d: Checking %g->[\"%s\"] against [\"%s\"]%s\n", lineno, d,
               s0, sample, canonical_sample ? " (canonical follows...)" : "");
        assert(!strcmp(s0, sample));
    }
    if(canonical_sample) {
        if(*s1 == '<') {
            printf(
                "%03d: Checking %g->[\"%s\"] against [\"%s\"] "
                "(canonical)\n",
                lineno, d, s1, canonical_sample);
            assert(!strcmp(s1, canonical_sample));
        } else {
            double reconstructed = strtod(s1, 0);
            printf(
                "%03d: Checking %g->[\"%s\"] against [\"%s\"]->%g "
                "(canonical, 𝟄=%.17g %g)\n",
                lineno, d, s1, canonical_sample, reconstructed,
                fabs(reconstructed - d), 1e-52);
            if(d != reconstructed) {
                printf(
                    "WARNING: Difference in a small epsilon (given "
                    "%%.15g=%.15g, %%.17g=%.17g, %%.20g=%.20g, "
                    "reconstructed %%.15g=%.15g, %%.17g=%.17g, "
                    "%%.20g=%.20g)!\n",
                    d, d, d, reconstructed, reconstructed, reconstructed);
            }
            assert(fabs(d - reconstructed) < 1e-52);
        }
    }
}

#define	check(rn, d, str1, str2)	\
	check_impl(rn, d, str1, str2, __LINE__)

static void
check_impl(REAL_t *rn, double orig_dbl, const char *sample, const char *canonical_sample, int lineno) {
	double val;
	uint8_t *p, *end;
	int ret;

	printf("Line %d: double value %.12f [", lineno, orig_dbl);
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
	printf("]: %zu\n", rn->size);

	ret = asn_REAL2double(rn, &val);
	assert(ret == 0);

	printf("and back to double: [");
	for(p = (uint8_t *)&val, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("] (ilogb %d)\n", ilogb(val));

	printf("%.12f vs %.12f\n", val, orig_dbl);
	assert((isnan(orig_dbl) && isnan(val)) || val == orig_dbl);
	printf("OK\n");

	check_str_representation(val, sample, canonical_sample, lineno);
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
	er = xer_encode(&asn_DEF_REAL, &st, XER_F_BASIC, callback, 0);
	assert(er.encoded == reconstr_lens[0]);
	er = xer_encode(&asn_DEF_REAL, &st, XER_F_CANONICAL, callback, (void *)1);
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
	assert(reconstr_lens[0] > 0 && rc.consumed < (size_t)reconstr_lens[0]);

	rc = xer_decode(0, &asn_DEF_REAL, (void **)newst1p,
		reconstructed[1], reconstr_lens[1]);
	assert(rc.code == RC_OK);
	assert(rc.consumed == (size_t)reconstr_lens[1]);

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
	ASN_STRUCT_RESET(asn_DEF_REAL, &st);
	ASN_STRUCT_FREE(asn_DEF_REAL, newst0);
	ASN_STRUCT_FREE(asn_DEF_REAL, newst1);
}

static void
check_ber_buffer_twoway(double d, const char *sample, const char *canonical_sample, const uint8_t *inbuf, size_t insize, uint8_t *outbuf, size_t outsize, int lineno) {
	REAL_t rn;
	double val;
	int ret;

	/*
	 * Decode our expected buffer and check that it matches the given (d).
	 */
	rn.buf = calloc(1, insize + 1); /* By convention, buffers have extra \0 */
	assert(rn.buf);
	memcpy(rn.buf, inbuf, insize);
	rn.size = insize;
	asn_REAL2double(&rn, &val);
	if(isnan(val)) assert(isnan(d));
	if(isnan(d)) assert(isnan(val));
	if(!isnan(val) && !isnan(d)) {
		assert(copysign(1.0, d) == copysign(1.0, val));
		assert(d == val);
	}

	/*
	 * Encode value and check that it matches our expected buffer.
	 */
	free(rn.buf);
	memset(&rn, 0, sizeof(rn));
	ret = asn_double2REAL(&rn, d);
	assert(ret == 0);
	if((size_t)rn.size != outsize) {
		printf("Encoded %f into %d expected %zd\n",
			d, (int)rn.size, outsize);
		assert((size_t)rn.size == outsize);
	}
	assert(memcmp(rn.buf, outbuf, rn.size) == 0);
	ASN_STRUCT_RESET(asn_DEF_REAL, &rn);

	check_str_representation(d, sample, canonical_sample, lineno);
}

static void
check_ber_buffer_oneway(double d, const char *sample, const char *canonical_sample, uint8_t *buf, size_t bufsize, int lineno) {
	REAL_t rn0;
	REAL_t rn1;
	double val0;
	double val1;
	uint8_t *p, *end;
	int ret;

	memset(&rn0, 0, sizeof(rn0));
	memset(&rn1, 0, sizeof(rn1));

	printf("verify double value %.12f [", d);
	for(p = (uint8_t *)&d, end = p + sizeof(double); p < end ; p++)
		printf("%02x", *p);
	printf("] (ilogb %d)\n", ilogb(d));

	ret = asn_double2REAL(&rn0, d);
	assert(ret == 0);

	printf("canonical DER: [");
	for(p = rn0.buf, end = p + rn0.size; p < end; p++)
		printf("%02x", *p);
	ret = asn_REAL2double(&rn0, &val0);
	assert(ret == 0);
	printf("] => %f\n", val0);

	rn1.buf = buf;
	rn1.size = bufsize;

	printf("received as:   [");
	for(p = rn1.buf, end = p + rn1.size; p < end; p++)
		printf("%02x", *p);
	ret = asn_REAL2double(&rn1, &val1);
	assert(ret == 0);
	printf("] => %f\n", val1);

	printf("%.12f vs %.12f vs %.12f\n", d, val0, val1);

	assert(val0 == d);
	assert(val1 == d);

	ASN_STRUCT_RESET(asn_DEF_REAL, &rn0);

	check_str_representation(val1, sample, canonical_sample, lineno);
}

/*
 * 8.5.7 Verify binary encoding, two-way.
 */
static void
check_ber_857_encoding(int base, int sign, int scaling_factor, int exponent, int mantissa) {
	uint8_t buf[100];
	uint8_t *b = buf;
	int explen, mantlen;
	REAL_t rn;
	static REAL_t rn_check;
	double d;
	double verify;
	int baseF = 0;
	int ret;

#define	BIT(b)	(1<<(b - 1))

	switch(base) {
	case 0: baseF = 1; break;
	case 1: baseF = 3; break;
	case 2: baseF = 4; break;
	default: assert(base >= 0 && base <= 2);
	}

	if(exponent >= -128 && exponent <= 127) {
		explen = 1;
	} else {
		assert(exponent > -60000 && exponent < 60000);
		explen = 2;
	}

	if(mantissa == 0) {
		mantlen = 0;
	} else if(mantissa >= 0 && mantissa <= 255) {
		mantlen = 1;
	} else if(mantissa >= 0 && mantissa <= 65535) {
		mantlen = 2;
	} else {
		assert(mantissa >= 0 && mantissa <= 256 * 65536);
		mantlen = 3;
	}

	*b = BIT(8) | (sign ? BIT(7) : 0);
	*b |= (base & 0x03) << 4;	/* 8.5.7.2 */
	*b |= (scaling_factor & 0x03) << 2;	/* 8.5.7.3 */
	*b |= ((explen - 1) & 0x03);	/* 8.5.7.4 */
	b++;
	switch(explen) {
	case 2: *b++ = (int8_t)(exponent >> 8); /* Fall through */
	case 1: *b++ = (int8_t)exponent;    /* Fall through */
	}
	switch(mantlen) {
	case 3: *b++ = (mantissa >> 16) & 0xff; /* Fall through */
	case 2: *b++ = (mantissa >> 8) & 0xff;  /* Fall through */
	case 1: *b++ = (mantissa & 0xff);   /* Fall through */
	}

	verify = (sign ? -1.0 : 1.0) * ldexp(mantissa, exponent * baseF + scaling_factor);

	/* Verify than encoding of this double value round-trips */
	if(!isinf(verify)) {
		d = verify;
		verify = 0.0;
		ret = asn_double2REAL(&rn_check, d);
		assert(ret == 0);
		ret = asn_REAL2double(&rn_check, &verify);
		assert(ret == 0);
		assert(d == verify);

		/* Verify with a slight non-friendly offset. Not too easy. */
		d = verify - 0.13;
		verify = 0.0;
		ret = asn_double2REAL(&rn_check, d);
		assert(ret == 0);
		ret = asn_REAL2double(&rn_check, &verify);
		assert(ret == 0);
		assert(ret == 0);
		assert(d == verify);
	}

	verify = (sign ? -1.0 : 1.0) * ldexp(mantissa, exponent * baseF + scaling_factor);

	rn.buf = buf;
	rn.size = b - buf;
	ret = asn_REAL2double(&rn, &d);
	if(!isinf(verify) && (ret != 0 || d != verify)) {
		printf("Converting B=%d, S=%d, F=%d, E=%d/%d, M=%d/%d\n", (1 << baseF), sign, scaling_factor, exponent, explen, mantissa, mantlen);
		printf("Verify: %e\n", verify);
		uint8_t *p;
		printf("received as:   [");
		for(p = buf; p < b; p++) printf("%02x", *p);
		printf("]\n");
		assert(ret == 0);
		printf("Converted: %e\n", d);
		assert(d == verify);
	}
}

static void
check_ber_encoding() {
#define CHECK_BER_STRICT(v, nocan, can, inbuf, outbuf)			\
	check_ber_buffer_twoway(v, nocan, can, inbuf, sizeof(inbuf),	\
				outbuf, sizeof(outbuf), __LINE__)

#define CHECK_BER_NONSTRICT(v, nocan, can, buf)	\
	check_ber_buffer_oneway(v, nocan, can, buf, sizeof(buf), __LINE__)

	/*
	 * X.690 8.4 Encoding of an enumerated value.
	 */

	/* 8.5.2 If the real value is the value plus zero,
	 * there shall be no contents octet in the encoding */
	{ uint8_t b_0[] = {};
	  CHECK_BER_STRICT(0.0, "0", "0", b_0, b_0); }

	/* 8.5.3 When -0 is to be encoded, there shall be only one contents octet */
	{ uint8_t b_m0[] = { 0x43 };
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0, b_m0); }

    /* Old way of encoding -0.0: 8.5.6 a) */
	{ uint8_t b_m0[] = { 0x43 };
	  uint8_t b_m0_856a[]   = { 0xC0, 0x00 };  /* #8.5.6 a) */
	  uint8_t b_m0_856a_1[] = { 0xC0, 0x00, 0x00 };
	  uint8_t b_m0_856a_2[] = { 0xC0, 0x00, 0x00, 0x00 };
	  uint8_t b_m0_856a_3[] = { 0xC0, 0x00, 0x00, 0x00, 0x00 };
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_856a, b_m0);
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_856a_1, b_m0);
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_856a_2, b_m0);
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_856a_3, b_m0); }

	/* 8.5.6 c) => 8.5.9 SpecialRealValue */
	{ uint8_t b_pinf[] = { 0x40 };
	  uint8_t b_minf[] = { 0x41 };
	  uint8_t b_nan[]  = { 0x42 };
	  CHECK_BER_STRICT(INFINITY, "<PLUS-INFINITY/>", "<PLUS-INFINITY/>", b_pinf, b_pinf);
	  CHECK_BER_STRICT(-INFINITY, "<MINUS-INFINITY/>", "<MINUS-INFINITY/>", b_minf, b_minf);
	  CHECK_BER_STRICT(NAN, "<NOT-A-NUMBER/>", "<NOT-A-NUMBER/>", b_nan, b_nan); }

	/* 8.5.6 b) => 8.5.8 Decimal encoding is used; NR1 form */
	{ uint8_t b_0_nr1[] = { 0x01, '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr1, b_0); }
	{ uint8_t b_0_nr1[] = { 0x01, '0', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr1, b_0); }
	{ uint8_t b_0_nr1[] = { 0x01, ' ', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr1, b_0); }
	{ uint8_t b_p0_nr1[] = { 0x01, '+', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_p0_nr1, b_0); }
	{ uint8_t b_p0_nr1[] = { 0x01, ' ', '+', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_p0_nr1, b_0); }
	{ uint8_t b_m0_nr1[] = { 0x01, '-', '0' };
	  uint8_t b_m0[] = { 0x43 };
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_nr1, b_m0); }
	{ uint8_t b_m0_nr1[] = { 0x01, ' ', '-', '0' };
	  uint8_t b_m0[] = { 0x43 };
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_nr1, b_m0); }

	{ uint8_t b_1_nr1[] = { 0x01, '1' };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_1_nr1, b_1); }
	{ uint8_t b_1_nr1[] = { 0x01, '0', '1' };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_1_nr1, b_1); }
	{ uint8_t b_1_nr1[] = { 0x01, ' ', '1' };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_1_nr1, b_1); }
	{ uint8_t b_p1_nr1[] = { 0x01, '+', '1' };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_p1_nr1, b_1); }
	{ uint8_t b_p1_nr1[] = { 0x01, ' ', '+', '1' };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_p1_nr1, b_1); }
	{ uint8_t b_m1_nr1[] = { 0x01, '-', '1' };
	  uint8_t b_m1[] = { 0xC0, 0x00, 0x01 };
	  CHECK_BER_STRICT(-1.0, "-1.0", "-1.0E0", b_m1_nr1, b_m1); }
	{ uint8_t b_m1_nr1[] = { 0x01, ' ', '-', '1' };
	  uint8_t b_m1[] = { 0xC0, 0x00, 0x01 };
	  CHECK_BER_STRICT(-1.0, "-1.0", "-1.0E0", b_m1_nr1, b_m1); }

 {
  uint8_t comma_symbol[] = { '.', ',' };
  int csi;
  for(csi = 0; csi < 2; csi++) {
	uint8_t CS = comma_symbol[csi];

	/* 8.5.6 b) => 8.5.8 Decimal encoding is used; NR2 form */
	{ uint8_t b_0_nr2[] = { 0x02, '0', CS, '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr2, b_0); }
	{ uint8_t b_0_nr2[] = { 0x02, '0', '0', CS, '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr2, b_0); }
	{ uint8_t b_0_nr2[] = { 0x02, ' ', '0', CS, '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr2, b_0); }
	{ uint8_t b_p0_nr2[] = { 0x02, '+', '0', CS, '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_p0_nr2, b_0); }
	{ uint8_t b_p0_nr2[] = { 0x02, ' ', '+', '0', CS, '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_p0_nr2, b_0); }
	{ uint8_t b_m0_nr2[] = { 0x02, '-', '0', CS, '0' };
	  uint8_t b_m0[] = { 0x43 };
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_nr2, b_m0); }
	{ uint8_t b_m0_nr2[] = { 0x02, ' ', '-', '0', CS, '0' };
	  uint8_t b_m0[] = { 0x43 };
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_nr2, b_m0); }

	/* 8.5.6 b) => 8.5.8 NR2 "1." */
	{ uint8_t b_1_nr2[] = { 0x02, '1', CS };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_1_nr2, b_1); }
	{ uint8_t b_1_nr2[] = { 0x02, '0', '1', CS };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_1_nr2, b_1); }
	{ uint8_t b_1_nr2[] = { 0x02, ' ', '1', CS };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_1_nr2, b_1); }
	{ uint8_t b_p1_nr2[] = { 0x02, '+', '1', CS };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_p1_nr2, b_1); }
	{ uint8_t b_p1_nr2[] = { 0x02, ' ', '+', '1', CS };
	  uint8_t b_1[] = { 0x80, 0x00, 0x01 };
	  CHECK_BER_STRICT(1.0, "1.0", "1.0E0", b_p1_nr2, b_1); }
	{ uint8_t b_m1_nr2[] = { 0x02, '-', '1', CS };
	  uint8_t b_m1[] = { 0xC0, 0x00, 0x01 };
	  CHECK_BER_STRICT(-1.0, "-1.0", "-1.0E0", b_m1_nr2, b_m1); }
	{ uint8_t b_m1_nr2[] = { 0x02, ' ', '-', '1', CS };
	  uint8_t b_m1[] = { 0xC0, 0x00, 0x01 };
	  CHECK_BER_STRICT(-1.0, "-1.0", "-1.0E0", b_m1_nr2, b_m1); }

	/* 8.5.6 b) => 8.5.8 NR2 ".5" */
	{ uint8_t b_05_nr2[] = { 0x02, CS, '5' };
	  uint8_t b_05[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_05_nr2, b_05); }
	{ uint8_t b_05_nr2[] = { 0x02, '0', CS, '5' };
	  uint8_t b_05[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_05_nr2, b_05); }
	{ uint8_t b_05_nr2[] = { 0x02, ' ', CS, '5' };
	  uint8_t b_05[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_05_nr2, b_05); }
	{ uint8_t b_p1_nr2[] = { 0x02, '+', CS, '5' };
	  uint8_t b_05[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_p1_nr2, b_05); }
	{ uint8_t b_p1_nr2[] = { 0x02, ' ', '+', CS, '5' };
	  uint8_t b_05[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_p1_nr2, b_05); }
	{ uint8_t b_m05_nr2[] = { 0x02, '-', CS, '5' };
	  uint8_t b_m05[] = { 0xC0, 0xff, 0x01 };
	  CHECK_BER_STRICT(-0.5, "-0.5", "-5.0E-1", b_m05_nr2, b_m05); }
	{ uint8_t b_m05_nr2[] = { 0x02, ' ', '-', CS, '5' };
	  uint8_t b_m05[] = { 0xC0, 0xff, 0x01 };
	  CHECK_BER_STRICT(-0.5, "-0.5", "-5.0E-1", b_m05_nr2, b_m05); }

	/* 8.5.6 b) => 8.5.8 Decimal encoding is used; NR3 form */
	{ uint8_t b_0_nr3[] = { 0x03, '0', CS, '0', 'e', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr3, b_0); }
	{ uint8_t b_0_nr3[] = { 0x03, '0', '0', CS, '0', 'E', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr3, b_0); }
	{ uint8_t b_0_nr3[] = { 0x03, ' ', '0', CS, '0', 'e', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_0_nr3, b_0); }
	{ uint8_t b_p0_nr3[] = { 0x03, '+', '0', CS, '0', 'E', '+', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_p0_nr3, b_0); }
	{ uint8_t b_p0_nr3[] = { 0x03, ' ', '+', '0', CS, '0', 'e', '+', '0' };
	  uint8_t b_0[] = { };
	  CHECK_BER_STRICT(0.0, "0", "0", b_p0_nr3, b_0); }
	{ uint8_t b_m0_nr3[] = { 0x03, '-', '0', CS, '0', 'E', '-', '0' };
	  uint8_t b_m0[] = { 0x43 };
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_nr3, b_m0); }
	{ uint8_t b_m0_nr3[] = { 0x03, ' ', '-', '0', CS, '0', 'e', '-', '0' };
	  uint8_t b_m0[] = { 0x43 };
	  CHECK_BER_STRICT(-0.0, "-0", "-0", b_m0_nr3, b_m0); }

	/* 8.5.6 b) => 8.5.8 NR3 "5.e-1" */
	{ uint8_t b_5_nr3[] = { 0x03, '5', CS, 'e', '-', '1' };
	  uint8_t b_5[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_5_nr3, b_5); }
	{ uint8_t b_5_nr3[] = { 0x03, '0', '5', CS, 'E', '-', '1' };
	  uint8_t b_5[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_5_nr3, b_5); }
	{ uint8_t b_5_nr3[] = { 0x03, ' ', '5', CS, 'e', '-', '1' };
	  uint8_t b_5[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_5_nr3, b_5); }
	{ uint8_t b_p5_nr3[] = { 0x03, '+', '5', CS, 'E', '-', '1' };
	  uint8_t b_5[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_p5_nr3, b_5); }
	{ uint8_t b_p5_nr3[] = { 0x03, ' ', '+', '5', CS, 'e', '-', '1' };
	  uint8_t b_5[] = { 0x80, 0xff, 0x01 };
	  CHECK_BER_STRICT(0.5, "0.5", "5.0E-1", b_p5_nr3, b_5); }
	{ uint8_t b_m5_nr3[] = { 0x03, '-', '5', CS, 'E', '-', '1' };
	  uint8_t b_m5[] = { 0xC0, 0xff, 0x01 };
	  CHECK_BER_STRICT(-0.5, "-0.5", "-5.0E-1", b_m5_nr3, b_m5); }
	{ uint8_t b_m5_nr3[] = { 0x03, ' ', '-', '5', CS, 'e', '-', '1' };
	  uint8_t b_m5[] = { 0xC0, 0xff, 0x01 };
	  CHECK_BER_STRICT(-0.5, "-0.5", "-5.0E-1", b_m5_nr3, b_m5); }

	/* 8.5.6 b) => 8.5.8 NR3 ".5e1" */
	{ uint8_t b_05_nr3[] = { 0x03, CS, '5', 'e', '+', '1' };
	  uint8_t b_05[] = { 0x80, 0x00, 0x05 };
	  CHECK_BER_STRICT(5.0, "5.0", "5.0E0", b_05_nr3, b_05); }
	{ uint8_t b_05_nr3[] = { 0x03, '0', CS, '5', 'E', '+', '1'};
	  uint8_t b_05[] = { 0x80, 0x00, 0x05 };
	  CHECK_BER_STRICT(5.0, "5.0", "5.0E0", b_05_nr3, b_05); }
	{ uint8_t b_05_nr3[] = { 0x03, ' ', CS, '5', 'e', '1'};
	  uint8_t b_05[] = { 0x80, 0x00, 0x05 };
	  CHECK_BER_STRICT(5.0, "5.0", "5.0E0", b_05_nr3, b_05); }
	{ uint8_t b_p1_nr3[] = { 0x03, '+', CS, '5', 'E', '1' };
	  uint8_t b_05[] = { 0x80, 0x00, 0x05 };
	  CHECK_BER_STRICT(5.0, "5.0", "5.0E0", b_p1_nr3, b_05); }
	{ uint8_t b_p1_nr3[] = { 0x03, ' ', '+', CS, '5', 'e', '+', '1' };
	  uint8_t b_05[] = { 0x80, 0x00, 0x05 };
	  CHECK_BER_STRICT(5.0, "5.0", "5.0E0", b_p1_nr3, b_05); }
	{ uint8_t b_m05_nr3[] = { 0x03, '-', CS, '5', 'E', '+', '1' };
	  uint8_t b_m05[] = { 0xC0, 0x00, 0x05 };
	  CHECK_BER_STRICT(-5.0, "-5.0", "-5.0E0", b_m05_nr3, b_m05); }
	{ uint8_t b_m05_nr3[] = { 0x03, ' ', '-', CS, '5', 'e', '1' };
	  uint8_t b_m05[] = { 0xC0, 0x00, 0x05 };
	  CHECK_BER_STRICT(-5.0, "-5.0", "-5.0E0", b_m05_nr3, b_m05); }
  } /* for(comma symbol) */
 }

  /* Scan through the range of bits, construct the valid base-2 numbers, and
   * try two-way conversion with them */
 {
  int base, sign, scaling_factor, exponent, mantissa;
  for(base = 0; base <= 2; base++) {
    for(sign = 0; sign <= 1; sign++) {
      for(scaling_factor = 0; scaling_factor <= 3; scaling_factor++) {
        for(exponent = -1000; exponent < 1000; exponent += (exponent > -990 && exponent < 990) ? 100 : 1) {
          for(mantissa = 0; mantissa < 66000; mantissa += (mantissa > 300 && mantissa < 65400) ? 100 : 1) {
            check_ber_857_encoding(base, sign, scaling_factor, exponent, mantissa);
          }
	}
      }
    }
  }
 }

	{
	uint8_t b_1_0[] =
		{ 0x80, 0xcc, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint8_t b_1_1[] =
		{ 0x80, 0xcc, 0x11, 0x99, 0x99, 0x99, 0x99, 0x99, 0x9a };
	uint8_t b_3_14[] =
		{ 0x80, 0xcd, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f };
	uint8_t b_3_14_mo1[] =
		{ 0xC0, 0xc5, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f,3};
	uint8_t b_3_14_mo2[] =
		{ 0x80, 0xbd, 0x19, 0x1e, 0xb8, 0x51, 0xeb, 0x85, 0x1f,3,2};

	CHECK_BER_NONSTRICT(1.0, "1.0", "1.0E0", b_1_0);
	CHECK_BER_NONSTRICT(1.1, "1.1", "1.1E0", b_1_1);
	CHECK_BER_NONSTRICT(3.14, "3.14", "3.14E0", b_3_14);
	/* These two are very interesting! They check mantissa overflow! */
	CHECK_BER_NONSTRICT(-3.14, "-3.14", "-3.14E0", b_3_14_mo1);
	CHECK_BER_NONSTRICT(3.14, "3.14", "3.14E0", b_3_14_mo2);
	}
}

int
main() {
	REAL_t rn;
	memset(&rn, 0, sizeof(rn));

	check_ber_encoding();

	check(&rn, 0.0, "0", "0");
	check(&rn, -0.0, "-0", "-0");	/* minus-zero */
	check(&rn, NAN, "<NOT-A-NUMBER/>", "<NOT-A-NUMBER/>");
	check(&rn, INFINITY, "<PLUS-INFINITY/>", "<PLUS-INFINITY/>");
	check(&rn, -INFINITY, "<MINUS-INFINITY/>", "<MINUS-INFINITY/>");
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
	check(&rn, 0.25, "0.25", "2.5E-1");
	check(&rn, -0.25, "-0.25", "-2.5E-1");
	check(&rn, 0.03, "0.03", "3.0E-2");
	check(&rn, -0.03, "-0.03", "-3.0E-2");

	check(&rn, 4.01E-50, "0.0", "4.01E-50");
	check(&rn, -4.01E-50, "-0.0", "-4.01E-50");
	check(&rn, -4.9406564584124654E-324, "-0.0", "-4.940656458412465E-324"); /* MIN */
	check(&rn, DBL_MIN, "0.0", "2.225073858507201E-308"); /* MIN */
	check(&rn, -DBL_MIN, "-0.0", "-2.225073858507201E-308"); /* -MIN */
	check(&rn, DBL_MAX, "179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", "1.797693134862316E308"); /* MAX */
	check(&rn, -DBL_MAX, "-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0", "-1.797693134862316E308"); /* MAX */
	check(&rn, -DBL_TRUE_MIN, "-0.0", "-4.940656458412465E-324"); /* subnorm */
	check(&rn, DBL_TRUE_MIN, "0.0",    "4.940656458412465E-324"); /* subnorm */


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

	ASN_STRUCT_RESET(asn_DEF_REAL, &rn);
	return 0;
}
