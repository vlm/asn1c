/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <OBJECT_IDENTIFIER.h>
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
OBJECT_IDENTIFIER_get_arc_l(uint8_t *arcbuf, int arclen, int add, unsigned long *rvalue) {
	unsigned long accum;
	uint8_t *arcend = arcbuf + arclen;

	if((size_t)arclen * 7 > 8 * sizeof(accum)) {
		if((size_t)arclen * 7 <= 8 * (sizeof(accum) + 1)) {
			if((*arcbuf & ~0x8f)) {
				errno = ERANGE;	/* Overflow */
				return -1;
			}
		} else {
			errno = ERANGE;	/* Overflow */
			return -1;
		}
	}

	/* Gather all bits into the accumulator */
	for(accum = 0; arcbuf < arcend; arcbuf++)
		accum = (accum << 7) | (*arcbuf & ~0x80);

	assert(accum >= (unsigned long)-add);
	accum += add;	/* Actually, a negative value */

	*rvalue = accum;

	return 0;
}

int
OBJECT_IDENTIFIER_print_arc(uint8_t *arcbuf, int arclen, int add,
		asn_app_consume_bytes_f *cb, void *app_key) {
	char scratch[64];	/* Conservative estimate */
	unsigned long accum;	/* Bits accumulator */
	char *p;		/* Position in the scratch buffer */

	if(OBJECT_IDENTIFIER_get_arc_l(arcbuf, arclen, add, &accum))
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
OBJECT_IDENTIFIER_get_arcs_l(OBJECT_IDENTIFIER_t *oid,
	unsigned long *arcs, int arcs_slots) {
	unsigned long arc_value;
	int cur_arc = 0;
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

		if(startn == 0) {
			/*
			 * First two arcs are encoded through the backdoor.
			 */
			if(i) {
				add = -80;
				if(cur_arc < arcs_slots) arcs[cur_arc] = 2;
				cur_arc++;
			} else if(b <= 39) {
				add = 0;
				if(cur_arc < arcs_slots) arcs[cur_arc] = 0;
				cur_arc++;
			} else if(b < 79) {
				add = -40;
				if(cur_arc < arcs_slots) arcs[cur_arc] = 1;
				cur_arc++;
			} else {
				add = -80;
				if(cur_arc < arcs_slots) arcs[cur_arc] = 2;
				cur_arc++;
			}
		}

		/* Do not fill */
		if(cur_arc >= arcs_slots) {
			startn = i + 1;
			continue;
		}

		if(OBJECT_IDENTIFIER_get_arc_l(&oid->buf[startn],
				i - startn + 1,
				add, &arc_value))
			return -1;
		arcs[cur_arc++] = arc_value;
		startn = i + 1;
		add = 0;
	}

	return cur_arc;
}

int
OBJECT_IDENTIFIER_set_arcs_l(OBJECT_IDENTIFIER_t *oid, unsigned long *arcs, int arcs_slots) {
	uint8_t *buf;
	uint8_t *bp;
	unsigned long long first_value;
	int size;
	int i;

	if(oid == NULL || arcs == NULL || arcs_slots < 2) {
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
	size = ((sizeof(arcs[0]) + 1) * 8 / 7) * arcs_slots;
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

	for(i = 2; i < arcs_slots; i++) {
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
