/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <INTEGER.h>
#include <assert.h>
#include <errno.h>

/*
 * INTEGER basic type description.
 */
static ber_tlv_tag_t asn1_DEF_INTEGER_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_INTEGER = {
	"INTEGER",
	INTEGER_free,
	INTEGER_print,
	asn_generic_no_constraint,
	INTEGER_decode_ber,
	INTEGER_encode_der,
	0,				/* Not implemented yet */
	INTEGER_encode_xer,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_INTEGER_tags,
	sizeof(asn1_DEF_INTEGER_tags) / sizeof(asn1_DEF_INTEGER_tags[0]),
	asn1_DEF_INTEGER_tags,	/* Same as above */
	sizeof(asn1_DEF_INTEGER_tags) / sizeof(asn1_DEF_INTEGER_tags[0]),
	0,	/* Always in primitive form */
	0, 0,	/* No members */
	0	/* No specifics */
};

/*
 * Decode INTEGER type.
 */
ber_dec_rval_t
INTEGER_decode_ber(asn1_TYPE_descriptor_t *td,
	void **int_structure, void *buf_ptr, size_t size, int tag_mode) {
	INTEGER_t *st = (INTEGER_t *)*int_structure;
	ber_dec_rval_t rval;
	ber_dec_ctx_t ctx = { 0, 0, 0, 0 };
	ber_tlv_len_t length;

	/*
	 * If the structure is not there, allocate it.
	 */
	if(st == NULL) {
		(void *)st = *int_structure = CALLOC(1, sizeof(*st));
		if(st == NULL) {
			rval.code = RC_FAIL;
			rval.consumed = 0;
			return rval;
		}
	}

	ASN_DEBUG("Decoding %s as INTEGER (tm=%d)",
		td->name, tag_mode);

	/*
	 * Check tags.
	 */
	rval = ber_check_tags(td, &ctx,
		buf_ptr, size, tag_mode, &length, 0);
	if(rval.code != RC_OK)
		return rval;

	ASN_DEBUG("%s length is %d bytes", td->name, (int)length);

	/*
	 * Make sure we have this length.
	 */
	buf_ptr = ((char *)buf_ptr) + rval.consumed;
	size -= rval.consumed;
	if(length > (ber_tlv_len_t)size) {
		rval.code = RC_WMORE;
		rval.consumed = 0;
		return rval;
	}

	st->buf = (uint8_t *)MALLOC(length);
	if(st->buf) {
		st->size = length;
	} else {
		rval.code = RC_FAIL;
		rval.consumed = 0;
		return rval;
	}

	memcpy(st->buf, buf_ptr, st->size);

	rval.code = RC_OK;
	rval.consumed += length;

	ASN_DEBUG("Took %ld/%ld bytes to encode %s",
		(long)rval.consumed,
		(long)length, td->name);

	return rval;
}

/*
 * Encode INTEGER type using DER.
 */
asn_enc_rval_t
INTEGER_encode_der(asn1_TYPE_descriptor_t *sd, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	asn_enc_rval_t erval;
	INTEGER_t *st = (INTEGER_t *)ptr;

	ASN_DEBUG("%s %s as INTEGER (tm=%d)",
		cb?"Encoding":"Estimating", sd->name, tag_mode);

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

	erval.encoded = der_write_tags(sd, st->size, tag_mode, tag,
		cb, app_key);
	ASN_DEBUG("INTEGER %s wrote tags %d", sd->name, (int)erval.encoded);
	if(erval.encoded == -1) {
		erval.failed_type = sd;
		erval.structure_ptr = ptr;
		return erval;
	}

	if(cb && st->buf) {
		ssize_t ret;

		ret = cb(st->buf, st->size, app_key);
		if(ret == -1) {
			erval.encoded = -1;
			erval.failed_type = sd;
			erval.structure_ptr = ptr;
			return erval;
		}
	} else {
		assert(st->buf || st->size == 0);
	}

	erval.encoded += st->size;

	return erval;
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
		*p++ = ':';
	}
	if(p != scratch)
		p--;	/* Remove the last ':' */

	wrote += p - scratch;
	return (cb(scratch, p - scratch, app_key) < 0) ? -1 : wrote;
}

/*
 * INTEGER specific human-readable output.
 */
int
INTEGER_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const INTEGER_t *st = (const INTEGER_t *)sptr;

	(void)td;
	(void)ilevel;

	if(!st && !st->buf) return cb("<absent>", 8, app_key);

	return (INTEGER__dump(st, cb, app_key) < 0) ? -1 : 0;
}

asn_enc_rval_t
INTEGER_encode_xer(asn1_TYPE_descriptor_t *td, void *sptr,
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

void
INTEGER_free(asn1_TYPE_descriptor_t *td, void *ptr, int contents_only) {
	INTEGER_t *st = (INTEGER_t *)ptr;

	if(!td || !st)
		return;

	ASN_DEBUG("Freeing %s as INTEGER (%d, %p, %p)",
		td->name, contents_only, st, st->buf);

	if(st->buf) {
		FREEMEM(st->buf);
	}

	if(!contents_only) {
		FREEMEM(st);
	}
}

int
asn1_INTEGER2long(const INTEGER_t *iptr, long *lptr) {
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
