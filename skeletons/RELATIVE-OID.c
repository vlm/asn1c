/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <RELATIVE-OID.h>
#include <limits.h>	/* for CHAR_BIT */
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
	const RELATIVE_OID_t *st = (const RELATIVE_OID_t *)sptr;
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
	void *arcs_end = (char *)arcs + (arc_slots * arc_type_size);
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
			(char *)arcs += arc_type_size;
			num_arcs++;
		}

		startn = i + 1;
	}

	return num_arcs;
}

int
RELATIVE_OID_set_arcs(RELATIVE_OID_t *roid, void *arcs, unsigned int arc_type_size, unsigned int arcs_slots) {
	uint8_t *buf;
	uint8_t *bp;
	unsigned int size;
	unsigned int i;

	if(roid == NULL || arcs == NULL || arc_type_size < 1) {
		errno = EINVAL;
		return -1;
	}

	/*
	 * Roughly estimate the maximum size necessary to encode these arcs.
	 */
	size = ((arc_type_size * CHAR_BIT + 6) / 7) * arcs_slots;
	bp = buf = (uint8_t *)MALLOC(size + 1);
	if(!buf) {
		/* ENOMEM */
		return -1;
	}

	/*
	 * Encode the arcs.
	 */
	for(i = 0; i < arcs_slots; i++, (char *)arcs += arc_type_size) {
		bp += OBJECT_IDENTIFIER_set_single_arc(bp,
			arcs, arc_type_size, 0);
	}

	assert((unsigned)(bp - buf) <= size);

	/*
	 * Replace buffer.
	 */
	roid->size = bp - buf;
	bp = roid->buf;
	roid->buf = buf;
	if(bp) FREEMEM(bp);

	return 0;
}

