/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <OBJECT_IDENTIFIER.h>
#include <limits.h>	/* for CHAR_BIT */
#include <assert.h>
#include <errno.h>

/*
 * OBJECT IDENTIFIER basic type description.
 */
static ber_tlv_tag_t asn1_DEF_OBJECT_IDENTIFIER_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (6 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_OBJECT_IDENTIFIER = {
	"OBJECT IDENTIFIER",
	OBJECT_IDENTIFIER_constraint,
	INTEGER_decode_ber,	/* Implemented in terms of INTEGER type */
	OBJECT_IDENTIFIER_encode_der,
	OBJECT_IDENTIFIER_print,
	INTEGER_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_OBJECT_IDENTIFIER_tags,
	sizeof(asn1_DEF_OBJECT_IDENTIFIER_tags)
	    / sizeof(asn1_DEF_OBJECT_IDENTIFIER_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	0,	/* Always in primitive form */
	0	/* No specifics */
};


/*
 * Encode OBJECT IDENTIFIER type using DER.
 */
der_enc_rval_t
OBJECT_IDENTIFIER_encode_der(asn1_TYPE_descriptor_t *sd, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	der_enc_rval_t erval;
	OBJECT_IDENTIFIER_t *st = ptr;

	ASN_DEBUG("%s %s as OBJECT IDENTIFIER (tm=%d)",
		cb?"Encoding":"Estimating", sd->name, tag_mode);

	erval.encoded = der_write_tags(sd, st->size, tag_mode, tag,
		cb, app_key);
	ASN_DEBUG("OBJECT IDENTIFIER %s wrote tags %d",
		sd->name, (int)erval.encoded);
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

int
OBJECT_IDENTIFIER_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	const OBJECT_IDENTIFIER_t *st = sptr;

	if(st && st->buf) {
		if(st->size < 1) {
			_ASN_ERRLOG("%s: at least one numerical value expected",
				td->name);
			return -1;
		}
	} else {
		_ASN_ERRLOG("%s: value not given", td->name);
		return -1;
	}

	return 0;
}

int
OBJECT_IDENTIFIER_get_single_arc(uint8_t *arcbuf, unsigned int arclen, signed int add, void *rvbuf, unsigned int rvsize) {
	unsigned LE = 1;	/* Little endian (x86) */
	uint8_t *arcend = arcbuf + arclen;	/* End of arc */
	void *rvstart = rvbuf;	/* Original start of the value buffer */
	unsigned int cache = 0;	/* No more than 14 significant bits */
	int inc;	/* Return value growth direction */

	rvsize *= CHAR_BIT;	/* bytes to bits */
	arclen *= 7;		/* bytes to bits */

	/*
	 * The arc has the number of bits
	 * cannot be represented using supplied return value type.
	 */
	if(arclen > rvsize) {
		if(arclen > (rvsize + CHAR_BIT)) {
			errno = ERANGE;	/* Overflow */
			return -1;
		} else {
			/*
			 * Even if the number of bits in the arc representation
			 * is higher than the width of supplied * return value
			 * type, there is still possible to fit it when there
			 * are few unused high bits in the arc value
			 * representaion.
			 */
			uint8_t mask = (0xff << (7-(arclen - rvsize))) & 0x7f;
			if((*arcbuf & mask)) {
				errno = ERANGE;	/* Overflow */
				return -1;
			}
			/* Fool the routine computing unused bits */
			arclen -= 7;
			cache = *arcbuf & 0x7f;
			arcbuf++;
		}
	}

#ifndef	WORDS_BIGENDIAN
	if(*(unsigned char *)&LE) {	/* Little endian (x86) */
		/* "Convert" to big endian */
		rvbuf += rvsize / CHAR_BIT;
		inc = -1;	/* Descending */
	} else {
		inc = +1;	/* Ascending */
	}
#endif	/* !WORDS_BIGENDIAN */

	{	/* Native big endian (Sparc, PPC) */
		unsigned int bits;	/* typically no more than 3-4 bits */
		/* Clear the high unused bits */
		for(bits = rvsize - arclen;
			bits > CHAR_BIT;
				rvbuf += inc, bits -= CHAR_BIT)
				*(unsigned char *)rvbuf = 0;
		/* Fill the body of a value */
		for(; arcbuf < arcend; arcbuf++) {
			cache = (cache << 7) | (*arcbuf & 0x7f);
			bits += 7;
			if(bits >= CHAR_BIT) {
				bits -= CHAR_BIT;
				*(unsigned char *)rvbuf = (cache >> bits);
				rvbuf += inc;
			}
		}
		if(bits) {
			*(unsigned char *)rvbuf = cache;
			rvbuf += inc;
		}
	}

	if(add) {
		for(rvbuf -= inc; rvbuf != rvstart; rvbuf -= inc) {
			int v = add + *(unsigned char *)rvbuf;
			if(v & (-1 << CHAR_BIT)) {
				*(unsigned char *)rvbuf
					= v + (1 << CHAR_BIT);
				add = -1;
			} else {
				*(unsigned char *)rvbuf = v;
				break;
			}
		}
		if(rvbuf == rvstart) {
			/* No space to carry over */
			errno = ERANGE;	/* Overflow */
			return -1;
		}
	}

	return 0;
}


int
OBJECT_IDENTIFIER_print_arc(uint8_t *arcbuf, int arclen, int add,
		asn_app_consume_bytes_f *cb, void *app_key) {
	char scratch[64];	/* Conservative estimate */
	unsigned long accum;	/* Bits accumulator */
	char *p;		/* Position in the scratch buffer */

	if(OBJECT_IDENTIFIER_get_single_arc(arcbuf, arclen, add,
			&accum, sizeof(accum)))
		return -1;

	/* Fill the scratch buffer in reverse. */
	p = scratch + sizeof(scratch);
	for(; accum; accum /= 10)
		*(--p) = (accum % 10) + 0x30;

	return cb(p, sizeof(scratch) - (p - scratch), app_key);
}

int
OBJECT_IDENTIFIER_print(asn1_TYPE_descriptor_t *td, const void *sptr,
	int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	const OBJECT_IDENTIFIER_t *st = sptr;
	int startn;
	int add = 0;
	int i;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(!st || !st->buf)
		return cb("<absent>", 8, app_key);

	/* Dump preamble */
	if(cb("{ ", 2, app_key))
		return -1;

	for(i = 0, startn = 0; i < st->size; i++) {
		uint8_t b = st->buf[i];
		if((b & 0x80))			/* Continuation expected */
			continue;

		if(startn == 0) {
			/*
			 * First two arcs are encoded through the backdoor.
			 */
			if(i) {
				add = -80;
				if(cb("2", 1, app_key)) return -1;
			} else if(b <= 39) {
				add = 0;
				if(cb("0", 1, app_key)) return -1;
			} else if(b < 79) {
				add = -40;
				if(cb("1", 1, app_key)) return -1;
			} else {
				add = -80;
				if(cb("2", 1, app_key)) return -1;
			}
		}

		if(cb(" ", 1, app_key))	/* Separate arcs */
			return -1;

		if(OBJECT_IDENTIFIER_print_arc(&st->buf[startn],
				i - startn + 1, add,
				cb, app_key))
			return -1;
		startn = i + 1;
		add = 0;
	}

	return cb(" }", 2, app_key);
}

int
OBJECT_IDENTIFIER_get_arcs(OBJECT_IDENTIFIER_t *oid, void *arcs,
		unsigned int arc_type_size, unsigned int arc_slots) {
	void *arcs_end = arcs + (arc_type_size * arc_slots);
	int num_arcs = 0;
	int startn = 0;
	int add = 0;
	int i;

	if(!oid || !oid->buf) {
		errno = EINVAL;
		return -1;
	}

	for(i = 0; i < oid->size; i++) {
		uint8_t b = oid->buf[i];
		if((b & 0x80))			/* Continuation expected */
			continue;

		if(num_arcs == 0) {
			/*
			 * First two arcs are encoded through the backdoor.
			 */
			unsigned LE = 1;	/* Little endian */
			int first_arc;
			num_arcs++;
			if(!arc_slots) { num_arcs++; continue; }

			if(i) first_arc = 2;
			else if(b <= 39) first_arc = 0;
			else if(b < 79)	first_arc = 1;
			else first_arc = 2;

			add = -40 * first_arc;
			memset(arcs, 0, arc_type_size);
			*(unsigned char *)(arcs
				+ ((*(char *)&LE)?0:(arc_type_size - 1)))
					= first_arc;
			arcs += arc_type_size;
		}

		/* Decode, if has space */
		if(arcs < arcs_end) {
			if(OBJECT_IDENTIFIER_get_single_arc(&oid->buf[startn],
				i - startn + 1, add,
					arcs, arc_type_size))
				return -1;
			startn = i + 1;
			arcs += arc_type_size;
			add = 0;
		}
		num_arcs++;
	}

	return num_arcs;
}

int
OBJECT_IDENTIFIER_set_arcs_l(OBJECT_IDENTIFIER_t *oid, unsigned long *arcs, unsigned int arc_slots) {
	uint8_t *buf;
	uint8_t *bp;
	unsigned long long first_value;
	int size;
	int i;

	if(oid == NULL || arcs == NULL || arc_slots < 2) {
		errno = EINVAL;
		return -1;
	}

	if(arcs[0] <= 1) {
		if(arcs[1] >= 39) {
			/* 8.19.4: At most 39 subsequent values (including 0) */
			errno = ERANGE;
			return -1;
		}
	} else if(arcs[0] > 2) {
		/* 8.19.4: Only three values are allocated from the root node */
		errno = ERANGE;
		return -1;
	}

	first_value = arcs[0] * 40 + arcs[1];

	/*
	 * Roughly estimate the maximum size necessary to encode these arcs.
	 */
	size = ((sizeof(arcs[0]) + 1) * 8 / 7) * arc_slots;
	bp = buf = MALLOC(size + 1);
	if(!buf) {
		/* ENOMEM */
		return -1;
	}

	/*
	 * Encode the arcs and refine the encoding size.
	 */
	size = 0;

	{
		uint8_t tbuf[sizeof(first_value) * 2];
		uint8_t *tp = tbuf;
		int arc_len = 0;
		int add = 0;

		for(; first_value; first_value >>= 7) {
			unsigned int b7 = first_value & 0x7f;
			*tp++ = 0x80 | b7;
			add++;
			if(b7) { arc_len += add; add = 0; }
		}

		if(arc_len) {
			tp = &tbuf[arc_len - 1];
			/* The last octet does not have bit 8 set. */
			*tbuf &= 0x7f;
			for(; tp >= tbuf; tp--)
				*bp++ = *tp;
			size += arc_len;
		} else {
			*bp++ = 0;
			size++;
		}
	}

	for(i = 2; i < arc_slots; i++) {
		unsigned long value = arcs[i];
		uint8_t tbuf[sizeof(value) * 2];  /* Conservatively sized */
		uint8_t *tp = tbuf;
		int arc_len = 0;
		int add = 0;

		for(; value; value >>= 7) {
			unsigned int b7 = value & 0x7F;
			*tp++ = 0x80 | b7;
			add++;
			if(b7) { arc_len += add; add = 0; }
		}

		if(arc_len) {
			tp = &tbuf[arc_len - 1];
			/* The last octet does not have bit 8 set. */
			*tbuf &= 0x7f;
			for(; tp >= tbuf; tp--)
				*bp++ = *tp;
			size += arc_len;
		} else {
			*bp++ = 0;
			size++;
		}
	}

	/*
	 * Replace buffer.
	 */
	oid->size = size;
	bp = oid->buf;
	oid->buf = buf;
	if(bp) FREEMEM(bp);

	return 0;
}
