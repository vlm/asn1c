/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <REAL.h>
#include <stdlib.h>	/* for strtod(3) */
#include <math.h>
#include <errno.h>
#include <assert.h>

#undef	INT_MAX
#define	INT_MAX	((int)(((unsigned int)-1) >> 1))

#ifndef	INFINITY
#define	INFINITY	HUGE_VAL
#endif

#ifndef	NAN
static const double real_nan0;
#define	NAN	(real_nan0/real_nan0)
#endif

/*
 * REAL basic type description.
 */
static ber_tlv_tag_t asn1_DEF_REAL_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (9 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_REAL = {
	"REAL",
	ASN__PRIMITIVE_TYPE_free,
	REAL_print,
	asn_generic_no_constraint,
	ber_decode_primitive,
	der_encode_primitive,
	0,				/* Not implemented yet */
	REAL_encode_xer,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_REAL_tags,
	sizeof(asn1_DEF_REAL_tags) / sizeof(asn1_DEF_REAL_tags[0]),
	asn1_DEF_REAL_tags,	/* Same as above */
	sizeof(asn1_DEF_REAL_tags) / sizeof(asn1_DEF_REAL_tags[0]),
	0, 0,	/* No members */
	0	/* No specifics */
};

ssize_t
REAL__dump(double d, int canonical, asn_app_consume_bytes_f *cb, void *app_key) {
	char local_buf[64];
	char *buf = local_buf;
	ssize_t buflen = sizeof(local_buf);
	const char *fmt = canonical?"%.15E":"%.15f";
	ssize_t ret;
	int expval;

	/*
	 * Check whether it is a special value.
	 */
	/*
	 * ilogb(+-0) returns -INT_MAX or INT_MIN (platform-dependent)
	 * ilogb(+-inf) returns INT_MAX
	 * ilogb(NaN) returns INT_MIN or INT_MAX (platform-dependent)
	 */
	expval = ilogb(d);
	if(expval <= -INT_MAX	/* Also catches +-0 and maybe isnan() */
	|| expval == INT_MAX	/* catches isfin() and maybe isnan() */
	) {
		/* fpclassify(3) is not portable yet */
		if(isnan(d)) {
			buf = "<NOT-A-NUMBER/>";
			buflen = 15;
		} else if(expval <= -INT_MAX) {
			if(copysign(1.0, d) < 0.0) {
				buf = "-0";
				buflen = 2;
			} else {
				buf = "0";
				buflen = 1;
			}
		} else {	/* isinf() */
                        if(copysign(1.0, d) < 0.0) {
				buf = "<MINUS-INFINITY/>";
				buflen = 17;
                        } else {
				buf = "<PLUS-INFINITY/>";
				buflen = 16;
                        }
		}
		return (cb(buf, buflen, app_key) < 0) ? -1 : buflen;
	}

	/*
	 * Use the libc's double printing, hopefully they got it right.
	 */
	do {
		ret = snprintf(buf, buflen, fmt, d);
		if(ret < 0) {
			buflen <<= 1;
		} else if(ret >= buflen) {
			buflen = ret + 1;
		} else {
			buflen = ret;
			break;
		}
		if(buf != local_buf) free(buf);
		buf = (char *)MALLOC(buflen);
		if(!buf) return -1;
	} while(1);

	if(canonical) {
		/*
		 * Transform the "[-]d.dddE+-dd" output into "[-]d.dddE[-]d"
		 */
		char *dot, *E;
		char *end = buf + buflen;
		char *last_zero;

		dot = (buf[0] == '-') ? (buf + 2) : (buf + 1);
		if(*dot >= 0x30) {
			errno = EINVAL;
			return -1;	/* Not a dot, really */
		}
		*dot = 0x2e;		/* Replace possible comma */

		for(last_zero = dot + 2, E = dot; dot < end; E++) {
			if(*E == 0x45) {
				char *expptr = ++E;
				char *s = expptr;
				int sign;
				if(*expptr == '+') {
					/* Skip the "+" */
					buflen -= 1;
					sign = 0;
				} else {
					sign = 1;
					s++;
				}
				expptr++;
				if(expptr > end) {
					errno = EINVAL;
					return -1;
				}
				if(*expptr == 0x30) {
					buflen--;
					expptr++;
				}
				if(*last_zero == 0x30) {
					*last_zero = 0x45;	/* E */
					s = last_zero + 1;
					if(sign) *s++ = '-';
				}
				for(; expptr <= end; s++, expptr++)
					*s = *expptr;
				break;
			} else if(*E == 0x30) {
				if(*last_zero != 0x30)
					last_zero = E;
			}
		}
		if(E == end) {
			errno = EINVAL;
			return -1;		/* No promised E */
		}
	} else {
		/*
		 * Remove trailing zeros.
		 */
		char *end = buf + buflen;
		char *last_zero = end;
		char *z;
		for(z = end - 1; z > buf; z--) {
			switch(*z) {
			case 0x030:
				last_zero = z;
			case 0x31: case 0x32: case 0x33: case 0x34:
			case 0x35: case 0x36: case 0x37: case 0x38: case 0x39:
				continue;
			default:	/* Catch dot and other separators */
				*z = 0x2e;	/* Replace possible comma */
				if(last_zero == z + 1) {	/* leave x.0 */
					last_zero++;
				}
				buflen = last_zero - buf;
				*last_zero = '\0';
				break;
			}
			break;
		}
	}

	ret = cb(buf, buflen, app_key);
	if(buf != local_buf) free(buf);
	return (ret < 0) ? -1 : buflen;
}

int
REAL_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const REAL_t *st = (const REAL_t *)sptr;
	ssize_t ret;
	double d;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(!st || !st->buf)
		ret = cb("<absent>", 8, app_key);
	else if(asn1_REAL2double(st, &d))
		ret = cb("<error>", 7, app_key);
	else
		ret = REAL__dump(d, 0, cb, app_key);

	return (ret < 0) ? -1 : 0;
}

asn_enc_rval_t
REAL_encode_xer(asn1_TYPE_descriptor_t *td, void *sptr,
	int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	REAL_t *st = (REAL_t *)sptr;
	asn_enc_rval_t er;
	double d;

	(void)ilevel;

	if(!st || !st->buf || asn1_REAL2double(st, &d))
		_ASN_ENCODE_FAILED;

	er.encoded = REAL__dump(d, flags & XER_F_CANONICAL, cb, app_key);
	if(er.encoded < 0) _ASN_ENCODE_FAILED;

	return er;
}

int
asn1_REAL2double(const REAL_t *st, double *dbl_value) {
	unsigned int octv;

	if(!st || !st->buf) {
		errno = EINVAL;
		return -1;
	}

	if(st->size == 0) {
		*dbl_value = 0;
		return 0;
	}

	octv = st->buf[0];	/* unsigned byte */

	switch(octv & 0xC0) {
	case 0x40:	/* X.690: 8.5.8 */
		/* "SpecialRealValue" */

		/* Be liberal in what you accept...
		if(st->size != 1) ...
		*/

		switch(st->buf[0]) {
		case 0x40:	/* 01000000: PLUS-INFINITY */
			*dbl_value = INFINITY;
			return 0;
		case 0x41:	/* 01000001: MINUS-INFINITY */
			*dbl_value = -INFINITY;
			return 0;
			/*
			 * The following cases are defined by
			 * X.690 Amendment 1 (10/03)
			 */
		case 0x42:	/* 01000010: NOT-A-NUMBER */
			*dbl_value = NAN;
			return 0;
		case 0x43:	/* 01000011: minus zero */
			*dbl_value = -0.0;
			return 0;
		}

		errno = EINVAL;
		return -1;
	case 0x00: {	/* X.690: 8.5.6 */
		/*
		 * Decimal. NR{1,2,3} format.
		 */
		double d;

		assert(st->buf[st->size - 1] == 0); /* Security, vashu mat' */

		d = strtod((char *)st->buf, 0);
		if(finite(d)) {
			*dbl_value = d;
			return 0;
		} else {
			errno = ERANGE;
			return 0;
		}
	  }
	}

	/*
	 * Binary representation.
	 */
    {
	double m;
	int expval;		/* exponent value */
	unsigned int elen;	/* exponent value length, in octets */
	unsigned int scaleF;
	unsigned int baseF;
	uint8_t *ptr;
	uint8_t *end;
	int sign;

	switch((octv & 0x30) >> 4) {
	case 0x00: baseF = 1; break;	/* base 2 */
	case 0x01: baseF = 3; break;	/* base 8 */
	case 0x02: baseF = 4; break;	/* base 16 */
	default:
		/* Reserved field, can't parse now. */
		errno = EINVAL;
		return -1;
	}

	sign = (octv & 0x40);	/* bit 7 */
	scaleF = (octv & 0x0C) >> 2;	/* bits 4 to 3 */

	if(st->size <= (int)(1 + (octv & 0x03))) {
		errno = EINVAL;
		return -1;
	}

	if((octv & 0x03) == 0x11) {
		/* 8.5.6.4, case d) */
		elen = st->buf[1];	/* unsigned binary number */
		if(elen == 0 || st->size <= (int)(2 + elen)) {
			errno = EINVAL;
			return -1;
		}
		ptr = &st->buf[2];
	} else {
		elen = (octv & 0x03);
		ptr = &st->buf[1];
	}

	/* Fetch the multibyte exponent */
	expval = (int)(*(int8_t *)ptr);
	end = ptr + elen + 1;
	for(ptr++; ptr < end; ptr++)
		expval = (expval * 256) + *ptr;

	m = 0.0;	/* Initial mantissa value */

	/* Okay, the exponent is here. Now, what about mantissa? */
	end = st->buf + st->size;
	if(ptr < end) {
		for(; ptr < end; ptr++)
			m = scalbn(m, 8) + *ptr;
	}

	ASN_DEBUG("m=%.10f, scF=%d, bF=%d, expval=%d, ldexp()=%f, scalbn()=%f",
		m, scaleF, baseF, expval,
		ldexp(m, expval * baseF + scaleF),
		scalbn(m, scaleF) * pow(pow(2, baseF), expval)
	);

	/*
	 * (S * N * 2^F) * B^E
	 * Essentially:
	m = scalbn(m, scaleF) * pow(pow(2, base), expval);
	 */
	m = ldexp(m, expval * baseF + scaleF);
	if(finite(m)) {
		*dbl_value = sign ? -m : m;
	} else {
		errno = ERANGE;
		return -1;
	}

    } /* if(binary_format) */

	return 0;
}

/*
 * Assume IEEE 754 floating point: standard 64 bit double.
 * [1 bit sign]  [11 bits exponent]  [52 bits mantissa]
 */
int
asn1_double2REAL(REAL_t *st, double dbl_value) {
#ifdef	WORDS_BIGENDIAN		/* Known to be big-endian */
	int littleEndian = 0;
#else				/* need to test: have no explicit information */
	unsigned int LE = 1;
	int littleEndian = *(unsigned char *)&LE;
#endif
	uint8_t buf[16];	/* More than enough for 8-byte dbl_value */
	uint8_t dscr[sizeof(dbl_value)];	/* double value scratch pad */
	/* Assertion guards: won't even compile, if unexpected double size */
	char assertion_buffer1[9 - sizeof(dbl_value)] __attribute__((unused));
	char assertion_buffer2[sizeof(dbl_value) - 7] __attribute__((unused));
	uint8_t *ptr = buf;
	uint8_t *mstop;		/* Last byte of mantissa */
	unsigned int mval;	/* Value of the last byte of mantissa */
	unsigned int bmsign;	/* binary mask with sign */
	unsigned int buflen;
	unsigned int accum;
	int expval;

	if(!st) {
		errno = EINVAL;
		return -1;
	}

	/*
	 * ilogb(+-0) returns -INT_MAX or INT_MIN (platform-dependent)
	 * ilogb(+-inf) returns INT_MAX
	 * ilogb(NaN) returns INT_MIN or INT_MAX (platform-dependent)
	 */
	expval = ilogb(dbl_value);
	if(expval <= -INT_MAX	/* Also catches +-0 and maybe isnan() */
	|| expval == INT_MAX	/* catches isfin() and maybe isnan() */
	) {
		if(!st->buf || st->size < 2) {
			ptr = (uint8_t *)MALLOC(2);
			if(!ptr) return -1;
			st->buf = ptr;
		}
		/* fpclassify(3) is not portable yet */
		if(isnan(dbl_value)) {
			st->buf[0] = 0x42;	/* NaN */
			st->buf[1] = 0;
			st->size = 1;
		} else if(expval <= -INT_MAX) {
			if(copysign(1.0, dbl_value) < 0.0) {
				st->buf[0] = 0x80 | 0x40;
				st->buf[1] = 0;
				st->size = 2;
			} else {
				st->buf[0] = 0;	/* JIC */
				st->size = 0;
			}
		} else {	/* isinf() */
			if(copysign(1.0, dbl_value) < 0.0) {
				st->buf[0] = 0x41;	/* MINUS-INFINITY */
			} else {
				st->buf[0] = 0x40;	/* PLUS-INFINITY */
			}
			st->buf[1] = 0;
			st->size = 1;
		}
		return 0;
	}

	if(littleEndian) {
		uint8_t *s = ((uint8_t *)&dbl_value) + sizeof(dbl_value) - 2;
		uint8_t *start = ((uint8_t *)&dbl_value);
		uint8_t *d;

		bmsign = 0x80 | ((s[1] >> 1) & 0x40);	/* binary mask & - */
		for(mstop = d = dscr; s >= start; d++, s--) {
			*d = *s;
			if(*d) mstop = d;
		}
	} else {
		uint8_t *s = ((uint8_t *)&dbl_value) + 1;
		uint8_t *end = ((uint8_t *)&dbl_value) + sizeof(double);
		uint8_t *d;

		bmsign = 0x80 | ((s[-1] >> 1) & 0x40);	/* binary mask & - */
		for(mstop = d = dscr; s < end; d++, s++) {
			*d = *s;
			if(*d) mstop = d;
		}
	}

	/* Remove parts of the exponent, leave mantissa and explicit 1. */
	dscr[0] = 0x10 | (dscr[0] & 0x0f);

	/* Adjust exponent in a very unobvious way */
	expval -= 8 * ((mstop - dscr) + 1) - 4;

	/* This loop ensures DER conformance by forcing mantissa odd: 11.3.1 */
	mval = *mstop;
	if(mval && !(mval & 1)) {
		unsigned int shift_count = 1;
		unsigned int ishift;
		uint8_t *mptr;

		/*
		 * Figure out what needs to be done to make mantissa odd.
		 */
		if(!(mval & 0x0f))	/* Speed-up a little */
			shift_count = 4;
		while(((mval >> shift_count) & 1) == 0)
			shift_count++;

		ishift = 8 - shift_count;
		accum = 0;

		/* Go over the buffer, shifting it shift_count bits right. */
		for(mptr = dscr; mptr <= mstop; mptr++) {
			mval = *mptr;
			*mptr = accum | (mval >> shift_count);
			accum = mval << ishift;
		}

		/* Adjust mantissa appropriately. */
		expval += shift_count;
	}

	if(expval < 0) {
		if((expval >> 7) == -1) {
			*ptr++ = bmsign | 0x00;
			*ptr++ = expval;
		} else if((expval >> 15) == -1) {
			*ptr++ = bmsign | 0x01;
			*ptr++ = expval >> 8;
			*ptr++ = expval;
		} else {
			*ptr++ = bmsign | 0x02;
			*ptr++ = expval >> 16;
			*ptr++ = expval >> 8;
			*ptr++ = expval;
		}
	} else if(expval <= 0x7f) {
		*ptr++ = bmsign | 0x00;
		*ptr++ = expval;
	} else if(expval <= 0x7fff) {
		*ptr++ = bmsign | 0x01;
		*ptr++ = expval >> 8;
		*ptr++ = expval;
	} else {
		assert(expval <= 0x7fffff);
		*ptr++ = bmsign | 0x02;
		*ptr++ = expval >> 16;
		*ptr++ = expval >> 8;
		*ptr++ = expval;
	}

	buflen = (mstop - dscr) + 1;
	memcpy(ptr, dscr, buflen);
	ptr += buflen;
	buflen = ptr - buf;

	(void *)ptr = MALLOC(buflen + 1);
	if(!ptr) return -1;

	memcpy(ptr, buf, buflen);
	buf[buflen] = 0;	/* JIC */

	if(st->buf) FREEMEM(st->buf);
	st->buf = ptr;
	st->size = buflen;

	return 0;
}
