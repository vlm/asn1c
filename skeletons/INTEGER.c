/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <INTEGER.h>
#include <asn_codecs_prim.h>	/* Encoder and decoder of a primitive type */
#include <assert.h>
#include <errno.h>

/*
 * INTEGER basic type description.
 */
static ber_tlv_tag_t asn_DEF_INTEGER_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn_TYPE_descriptor_t asn_DEF_INTEGER = {
	"INTEGER",
	"INTEGER",
	ASN__PRIMITIVE_TYPE_free,
	INTEGER_print,
	asn_generic_no_constraint,
	ber_decode_primitive,
	INTEGER_encode_der,
	INTEGER_decode_xer,
	INTEGER_encode_xer,
	0, /* Use generic outmost tag fetcher */
	asn_DEF_INTEGER_tags,
	sizeof(asn_DEF_INTEGER_tags) / sizeof(asn_DEF_INTEGER_tags[0]),
	asn_DEF_INTEGER_tags,	/* Same as above */
	sizeof(asn_DEF_INTEGER_tags) / sizeof(asn_DEF_INTEGER_tags[0]),
	0, 0,	/* No members */
	0	/* No specifics */
};

/*
 * Encode INTEGER type using DER.
 */
asn_enc_rval_t
INTEGER_encode_der(asn_TYPE_descriptor_t *td, void *sptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	INTEGER_t *st = (INTEGER_t *)sptr;

	ASN_DEBUG("%s %s as INTEGER (tm=%d)",
		cb?"Encoding":"Estimating", td->name, tag_mode);

	/*
	 * Canonicalize integer in the buffer.
	 * (Remove too long sign extension, remove some first 0x00 bytes)
	 */
	if(st->buf) {
		uint8_t *buf = st->buf;
		uint8_t *end1 = buf + st->size - 1;
		int shift;

		/* Compute the number of superfluous leading bytes */
		for(; buf < end1; buf++) {
			/*
			 * If the contents octets of an integer value encoding
			 * consist of more than one octet, then the bits of the
			 * first octet and bit 8 of the second octet:
			 * a) shall not all be ones; and
			 * b) shall not all be zero.
			 */
			switch(*buf) {
			case 0x00: if((buf[1] & 0x80) == 0)
					continue;
				break;
			case 0xff: if((buf[1] & 0x80))
					continue;
				break;
			}
			break;
		}

		/* Remove leading superfluous bytes from the integer */
		shift = buf - st->buf;
		if(shift) {
			uint8_t *nb = st->buf;
			uint8_t *end;

			st->size -= shift;	/* New size, minus bad bytes */
			end = nb + st->size;

			for(; nb < end; nb++, buf++)
				*nb = *buf;
		}

	} /* if(1) */

	return der_encode_primitive(td, sptr, tag_mode, tag, cb, app_key);
}

/*
 * INTEGER specific human-readable output.
 */
static ssize_t
INTEGER__dump(const INTEGER_t *st, asn_app_consume_bytes_f *cb, void *app_key) {
	char scratch[32];	/* Enough for 64-bit integer */
	uint8_t *buf = st->buf;
	uint8_t *buf_end = st->buf + st->size;
	signed long accum;
	ssize_t wrote = 0;
	char *p;
	int ret;

	if(st->size == 0) {
		return (cb("0", 1, app_key) < 0) ? -1 : 1;
	}

	/*
	 * Advance buf pointer until the start of the value's body.
	 * This will make us able to process large integers using simple case,
	 * when the actual value is small
	 * (0x0000000000abcdef would yield a fine 0x00abcdef)
	 */
	/* Skip the insignificant leading bytes */
	for(; buf < buf_end-1; buf++) {
		switch(*buf) {
		case 0x00: if((buf[1] & 0x80) == 0) continue; break;
		case 0xff: if((buf[1] & 0x80) != 0) continue; break;
		}
		break;
	}

	/* Simple case: the integer size is small */
	if((size_t)(buf_end - buf) <= sizeof(accum)) {
		accum = (*buf & 0x80) ? -1 : 0;
		for(; buf < buf_end; buf++)
			accum = (accum << 8) | *buf;
		ret = snprintf(scratch, sizeof(scratch), "%ld", accum);
		assert(ret > 0 && ret < (int)sizeof(scratch));
		return (cb(scratch, ret, app_key) < 0) ? -1 : ret;
	}

	/* Output in the long xx:yy:zz... format */
	/* TODO: replace with generic algorithm (Knuth TAOCP Vol 2, 4.3.1) */
	for(p = scratch; buf < buf_end; buf++) {
		static const char *h2c = "0123456789ABCDEF";
		if((p - scratch) >= (ssize_t)(sizeof(scratch) - 4)) {
			/* Flush buffer */
			if(cb(scratch, p - scratch, app_key) < 0)
				return -1;
			wrote += p - scratch;
			p = scratch;
		}
		*p++ = h2c[*buf >> 4];
		*p++ = h2c[*buf & 0x0F];
		*p++ = 0x3a;	/* ":" */
	}
	if(p != scratch)
		p--;	/* Remove the last ":" */

	wrote += p - scratch;
	return (cb(scratch, p - scratch, app_key) < 0) ? -1 : wrote;
}

/*
 * INTEGER specific human-readable output.
 */
int
INTEGER_print(asn_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const INTEGER_t *st = (const INTEGER_t *)sptr;
	ssize_t ret;

	(void)td;
	(void)ilevel;

	if(!st && !st->buf)
		ret = cb("<absent>", 8, app_key);
	else
		ret = INTEGER__dump(st, cb, app_key);

	return (ret < 0) ? -1 : 0;
}

/*
 * Decode the chunk of XML text encoding INTEGER.
 */
static ssize_t
INTEGER__xer_body_decode(INTEGER_t *st, void *chunk_buf, size_t chunk_size) {
	long sign = 1;
	long value;
	char *lp;
	char *lstart = (char *)chunk_buf;
	char *lstop = chunk_buf + chunk_size;
	enum {
		ST_SKIPSPACE,
		ST_WAITDIGITS,
		ST_DIGITS,
	} state = ST_SKIPSPACE;

	/*
	 * We may receive a tag here. But we aren't ready to deal with it yet.
	 * So, just use stroul()-like code and serialize the result.
	 */
	for(value = 0, lp = lstart; lp < lstop; lp++) {
		int lv = *lp;
		switch(lv) {
		case 0x09: case 0x0a: case 0x0d: case 0x20:
			if(state == ST_SKIPSPACE) continue;
			break;
		case 0x2d:	/* '-' */
			if(state == ST_SKIPSPACE) {
				sign = -1;
				state = ST_WAITDIGITS;
				continue;
			}
			break;
		case 0x2b:	/* '+' */
			if(state == ST_SKIPSPACE) {
				state = ST_WAITDIGITS;
				continue;
			}
			break;
		case 0x30: case 0x31: case 0x32: case 0x33: case 0x34:
		case 0x35: case 0x36: case 0x37: case 0x38: case 0x39:
			if(state != ST_DIGITS) state = ST_DIGITS;

		    {
			long new_value = value * 10;

			if(new_value / 10 != value)
				/* Overflow */
				return -1;

			value = new_value + (lv - 0x30);
			/* Check for two's complement overflow */
			if(value < 0) {
				/* Check whether it is a LONG_MIN */
				if(sign == -1
				&& value == ~((unsigned long)-1 >> 1)) {
					sign = 1;
				} else {
					/* Overflow */
					return -1;
				}
			}
		    }
			continue;
		}
		break;
	}

	if(state != ST_DIGITS)
		return -1;	/* No digits */

	value *= sign;	/* Change sign, if needed */

	if(asn_long2INTEGER(st, value))
		return -1;

	return lp - lstart;
}

asn_dec_rval_t
INTEGER_decode_xer(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *td, void **sptr, const char *opt_mname,
		void *buf_ptr, size_t size) {

	return xer_decode_primitive(opt_codec_ctx, td,
		(ASN__PRIMITIVE_TYPE_t **)sptr, opt_mname,
		buf_ptr, size, INTEGER__xer_body_decode);
}

asn_enc_rval_t
INTEGER_encode_xer(asn_TYPE_descriptor_t *td, void *sptr,
	int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	const INTEGER_t *st = (const INTEGER_t *)sptr;
	asn_enc_rval_t er;

	(void)ilevel;
	(void)flags;
	
	if(!st && !st->buf)
		_ASN_ENCODE_FAILED;

	er.encoded = INTEGER__dump(st, cb, app_key);
	if(er.encoded < 0) _ASN_ENCODE_FAILED;

	return er;
}

int
asn_INTEGER2long(const INTEGER_t *iptr, long *lptr) {
	uint8_t *b, *end;
	size_t size;
	long l;

	/* Sanity checking */
	if(!iptr || !iptr->buf || !lptr) {
		errno = EINVAL;
		return -1;
	}

	/* Cache the begin/end of the buffer */
	b = iptr->buf;	/* Start of the INTEGER buffer */
	size = iptr->size;
	end = b + size;	/* Where to stop */

	if(size > sizeof(long)) {
		uint8_t *end1 = end - 1;
		/*
		 * Slightly more advanced processing,
		 * able to >sizeof(long) bytes,
		 * when the actual value is small
		 * (0x0000000000abcdef would yield a fine 0x00abcdef)
		 */
		/* Skip out the insignificant leading bytes */
		for(; b < end1; b++) {
			switch(*b) {
			case 0x00: if((b[1] & 0x80) == 0) continue; break;
			case 0xff: if((b[1] & 0x80) != 0) continue; break;
			}
			break;
		}

		size = end - b;
		if(size > sizeof(long)) {
			/* Still cannot fit the long */
			errno = ERANGE;
			return -1;
		}
	}

	/* Shortcut processing of a corner case */
	if(end == b) {
		*lptr = 0;
		return 0;
	}

	/* Perform the sign initialization */
	/* Actually l = -(*b >> 7); gains nothing, yet unreadable! */
	if((*b >> 7)) l = -1; else l = 0;

	/* Conversion engine */
	for(; b < end; b++)
		l = (l << 8) | *b;

	*lptr = l;
	return 0;
}

int
asn_long2INTEGER(INTEGER_t *st, long value) {
	uint8_t *buf, *bp;
	uint8_t *p;
	uint8_t *pstart;
	uint8_t *pend1;

	if(!st) {
		errno = EINVAL;
		return -1;
	}

	buf = MALLOC(sizeof(value));
	if(!buf) return -1;

	pstart = (uint8_t *)&value;
	pend1 = pstart + sizeof(value) - 1;
	/*
	 * If the contents octet consists of more than one octet,
	 * then bits of the first octet and bit 8 of the second octet:
	 * a) shall not all be ones; and
	 * b) shall not all be zero.
	 */
	for(p = pstart; p < pend1; p++) {
		switch(*p) {
		case 0x00: if((p[1] & 0x80) == 0)
				continue;
			break;
		case 0xff: if((p[1] & 0x80))
				continue;
			break;
		}
		break;
	}
	/* Copy the integer body */
	for(pstart = p, bp = buf; p <= pend1;)
		*bp++ = *p++;

	if(st->buf) FREEMEM(st->buf);
	st->buf = buf;
	st->size = p - pstart;

	return 0;
}
