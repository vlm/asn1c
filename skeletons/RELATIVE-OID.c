/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <RELATIVE-OID.h>
#include <assert.h>
#include <errno.h>

/*
 * RELATIVE-OID basic type description.
 */
static ber_tlv_tag_t asn1_DEF_RELATIVE_OID_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (13 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_RELATIVE_OID = {
	"RELATIVE-OID",
	asn_generic_no_constraint,
	INTEGER_decode_ber,	/* Implemented in terms of INTEGER type */
	OBJECT_IDENTIFIER_encode_der,
	RELATIVE_OID_print,
	INTEGER_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_RELATIVE_OID_tags,
	sizeof(asn1_DEF_RELATIVE_OID_tags)
	    / sizeof(asn1_DEF_RELATIVE_OID_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	0,	/* Always in primitive form */
	0	/* No specifics */
};

int
RELATIVE_OID_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const RELATIVE_OID_t *st = sptr;
	int startn;
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
		if(startn && cb(" ", 1, app_key))	/* Separate arcs */
			return -1;
		if(OBJECT_IDENTIFIER_print_arc(&st->buf[startn],
			i - startn + 1, 0, cb, app_key))
			return -1;
		startn = i + 1;
	}

	return cb(" }", 2, app_key);
}


int
RELATIVE_OID_get_arcs(RELATIVE_OID_t *roid,
	void *arcs, unsigned int arc_type_size, unsigned int arc_slots) {
	void *arcs_end = arcs + (arc_slots * arc_type_size);
	int num_arcs = 0;
	int startn = 0;
	int i;

	if(!roid || !roid->buf) {
		errno = EINVAL;
		return -1;
	}

	for(i = 0; i < roid->size; i++) {
		uint8_t b = roid->buf[i];
		if((b & 0x80))			/* Continuation expected */
			continue;

		if(arcs < arcs_end) {
			if(OBJECT_IDENTIFIER_get_single_arc(
				&roid->buf[startn],
					i - startn + 1, 0,
					arcs, arc_type_size))
				return -1;
			arcs += arc_type_size;
			num_arcs++;
		}

		startn = i + 1;
	}

	return num_arcs;
}

int
RELATIVE_OID_set_arcs_l(RELATIVE_OID_t *roid, unsigned long *arcs, int arcs_slots) {
	uint8_t *buf;
	uint8_t *bp;
	int size;
	int i;

	if(roid == NULL || arcs == NULL || arcs_slots < 0) {
		errno = EINVAL;
		return -1;
	}

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
	for(i = 0; i < arcs_slots; i++) {
		unsigned long value = arcs[i];
		uint8_t tbuf[sizeof(value) * 2];  /* Conservatively sized */
		uint8_t *tp = tbuf;
		int arc_len = 0;
		int add;

		for(add = 1; value; value >>= 7, add++) {
			unsigned int b7 = value & 0x7F;
			*tp++ = 0x80 | b7;
			if(b7) {
				arc_len += add;
				add = 0;
			}
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
	roid->size = size;
	bp = roid->buf;
	roid->buf = buf;
	if(bp) FREEMEM(bp);

	return 0;
}
