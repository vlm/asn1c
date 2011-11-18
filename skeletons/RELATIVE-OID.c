/*-
 * Copyright (c) 2003, 2004, 2005 Lev Walkin <vlm@lionet.info>.
 * 	All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <RELATIVE-OID.h>
#include <OCTET_STRING.h>
#include <asn_codecs_prim.h>	/* Encoder and decoder of a primitive type */
#include <limits.h>	/* for CHAR_BIT */
#include <errno.h>

/*
 * RELATIVE-OID basic type description.
 */
static ber_tlv_tag_t asn_DEF_RELATIVE_OID_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (13 << 2))
};
asn_TYPE_descriptor_t asn_DEF_RELATIVE_OID = {
	"RELATIVE-OID",
	"RELATIVE_OID",
	ASN__PRIMITIVE_TYPE_free,
	RELATIVE_OID_print,
	asn_generic_no_constraint,
	ber_decode_primitive,
	der_encode_primitive,
	RELATIVE_OID_decode_xer,
	RELATIVE_OID_encode_xer,
	OCTET_STRING_decode_uper,
	OCTET_STRING_encode_uper,
	0, /* Use generic outmost tag fetcher */
	asn_DEF_RELATIVE_OID_tags,
	sizeof(asn_DEF_RELATIVE_OID_tags)
	    / sizeof(asn_DEF_RELATIVE_OID_tags[0]),
	asn_DEF_RELATIVE_OID_tags,	/* Same as above */
	sizeof(asn_DEF_RELATIVE_OID_tags)
	    / sizeof(asn_DEF_RELATIVE_OID_tags[0]),
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	0	/* No specifics */
};

static ssize_t
RELATIVE_OID__dump_body(const RELATIVE_OID_t *st, asn_app_consume_bytes_f *cb, void *app_key) {
	ssize_t wrote = 0;
	ssize_t ret;
	int startn;
	int i;

	for(i = 0, startn = 0; i < st->size; i++) {
		uint8_t b = st->buf[i];
		if((b & 0x80))			/* Continuation expected */
			continue;
		if(startn) {
			/* Separate arcs */
			if(cb(".", 1, app_key) < 0)
				return -1;
			wrote++;
		}

		ret = OBJECT_IDENTIFIER__dump_arc(&st->buf[startn],
			i - startn + 1, 0, cb, app_key);
		if(ret < 0) return -1;
		wrote += ret;

		startn = i + 1;
	}

	return wrote;
}

int
RELATIVE_OID_print(asn_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const RELATIVE_OID_t *st = (const RELATIVE_OID_t *)sptr;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(!st || !st->buf)
		return (cb("<absent>", 8, app_key) < 0) ? -1 : 0;

	/* Dump preamble */
	if(cb("{ ", 2, app_key) < 0)
		return -1;

	if(RELATIVE_OID__dump_body(st, cb, app_key) < 0)
		return -1;

	return (cb(" }", 2, app_key) < 0) ? -1 : 0;
}

static enum xer_pbd_rval
RELATIVE_OID__xer_body_decode(asn_TYPE_descriptor_t *td, void *sptr, const void *chunk_buf, size_t chunk_size) {
	RELATIVE_OID_t *st = (RELATIVE_OID_t *)sptr;
	const char *chunk_end = (const char *)chunk_buf + chunk_size;
	const char *endptr;
	long s_arcs[6];
	long *arcs = s_arcs;
	int arcs_count;
	int ret;

	(void)td;

	arcs_count = OBJECT_IDENTIFIER_parse_arcs(
		(const char *)chunk_buf, chunk_size,
		arcs, sizeof(s_arcs)/sizeof(s_arcs[0]), &endptr);
	if(arcs_count < 0) {
		/* Expecting at least zero arcs */
		return XPBD_BROKEN_ENCODING;
	}
	if(endptr < chunk_end) {
		/* We have a tail of unrecognized data. Check its safety. */
		if(!xer_is_whitespace(endptr, chunk_end - endptr))
			return XPBD_BROKEN_ENCODING;
	}

	if((size_t)arcs_count > sizeof(s_arcs)/sizeof(s_arcs[0])) {
		arcs = (long *)MALLOC(arcs_count * sizeof(long));
		if(!arcs) return XPBD_SYSTEM_FAILURE;
		ret = OBJECT_IDENTIFIER_parse_arcs(
			(const char *)chunk_buf, chunk_size,
			arcs, arcs_count, &endptr);
		if(ret != arcs_count)
			return XPBD_SYSTEM_FAILURE;	/* assert?.. */
	}

	/*
	 * Convert arcs into BER representation.
	 */
	ret = RELATIVE_OID_set_arcs(st, arcs, sizeof(*arcs), arcs_count);
	if(arcs != s_arcs) FREEMEM(arcs);

	return ret ? XPBD_SYSTEM_FAILURE : XPBD_BODY_CONSUMED;
}

asn_dec_rval_t
RELATIVE_OID_decode_xer(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *td, void **sptr, const char *opt_mname,
		const void *buf_ptr, size_t size) {

	return xer_decode_primitive(opt_codec_ctx, td,
		sptr, sizeof(RELATIVE_OID_t), opt_mname,
			buf_ptr, size, RELATIVE_OID__xer_body_decode);
}

asn_enc_rval_t
RELATIVE_OID_encode_xer(asn_TYPE_descriptor_t *td, void *sptr,
	int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	RELATIVE_OID_t *st = (RELATIVE_OID_t *)sptr;
	asn_enc_rval_t er;

	(void)ilevel;	/* Unused argument */
	(void)flags;	/* Unused argument */

	if(!st || !st->buf)
		_ASN_ENCODE_FAILED;

	er.encoded = RELATIVE_OID__dump_body(st, cb, app_key);
	if(er.encoded < 0) _ASN_ENCODE_FAILED;

	_ASN_ENCODED_OK(er);
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
			arcs = ((char *)arcs) + arc_type_size;
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
	for(i = 0; i < arcs_slots; i++, arcs = ((char *)arcs) + arc_type_size) {
		bp += OBJECT_IDENTIFIER_set_single_arc(bp,
			arcs, arc_type_size, 0);
	}

	assert((unsigned)(bp - buf) <= size);

	/*
	 * Replace buffer.
	 */
	roid->size = (int)(bp - buf);
	bp = roid->buf;
	roid->buf = buf;
	if(bp) FREEMEM(bp);

	return 0;
}

/* Contributed by Sean Leonard of SeanTek(R). */
/***** 2010-11-23 additions *****/

int RELATIVE_OID_cmp(const RELATIVE_OID_t *_roid1,
	const RELATIVE_OID_t *_roid2base, ...) {
	va_list roids;
	RELATIVE_OID_t *roid;
	size_t oid_full_len, oid_at_len;
	int memcmp_result;
	int i;
	
	if(!_roid1) return _roid2base ? -1 : 0;
	else if(!_roid2base) return 1;
	else if(_roid1->size < _roid2base->size) {
		memcmp_result = memcmp(_roid1->buf, _roid2base->buf, _roid1->size);
		if(memcmp_result != 0) return memcmp_result;
		else return -1; 
	}
	
	memcmp_result = memcmp(_roid1->buf, _roid2base->buf, _roid2base->size);
	if(memcmp_result != 0) return memcmp_result;
	
	oid_full_len = _roid1->size;
	oid_at_len = _roid2base->size;
	va_start(roids, _roid2base);
	while(NULL != (roid = va_arg(roids, RELATIVE_OID_t *))) {
		for(i = 0; i < roid->size; i++, oid_at_len++) {
			if(oid_at_len >= oid_full_len) {
				va_end(roids);
				return -1;
			}
			memcmp_result = _roid1->buf[oid_at_len] - roid->buf[i];
			if(memcmp_result != 0) {
				va_end(roids);
				return memcmp_result;
			}
		}
	}
	va_end(roids);
	assert(oid_at_len <= oid_full_len);
	return oid_at_len < oid_full_len;
}

int RELATIVE_OID_eq(const RELATIVE_OID_t *_roid1,
	const RELATIVE_OID_t *_roid2base, ...) {
	va_list roids;
	RELATIVE_OID_t *roid;
	size_t oid_full_len, oid_at_len;
	int i;
	
	if(!_roid1) return _roid2base ? 0 : 1;
	else if(!_roid2base) return 0;
	else if(_roid2base->size > _roid1->size) return 0;
	
	oid_full_len = _roid1->size;
	
	if(!!memcmp(_roid1->buf, _roid2base->buf, _roid2base->size))
		return 0;
	oid_at_len = _roid2base->size;
	va_start(roids, _roid2base);
	while(NULL != (roid = va_arg(roids, RELATIVE_OID_t *))) {
		for(i = 0; i < roid->size; i++, oid_at_len++) {
			if(oid_at_len >= oid_full_len ||
				_roid1->buf[oid_at_len] != roid->buf[i]) {
				va_end(roids);
				return 0;
			}
		}
	}
	va_end(roids);
	return oid_at_len == oid_full_len;
}

int RELATIVE_OID_fromOIDDiff(RELATIVE_OID_t *_roid, const OBJECT_IDENTIFIER_t *_oidbase,
	const OBJECT_IDENTIFIER_t *_fulloid) {
	size_t arcs_count = 1, arcs_len = 0, i;
	if(!_roid || !_oidbase || !_fulloid || !_oidbase->buf || !_fulloid->buf ||
		_oidbase->size < 0 || _fulloid->size < 0) {
		errno = EINVAL;
		return -1;
	}
	
	if(_oidbase->size == 0 || _oidbase->size > _fulloid->size) {
		errno = ERANGE;
		return -1;
	}
	
	for(i = 0; i < _oidbase->size; i++) {
		if(_oidbase->buf[i] != _fulloid->buf[i]) break;
		else if(!(_oidbase->buf[i] & 0x80)) {
			arcs_count++;
			arcs_len = i + 1;
		}
	}
	
	if(arcs_count < 2) {
		errno = ERANGE;
		return -1;
	}

	assert(_fulloid->size >= arcs_len);
	_roid->size = _fulloid->size - arcs_len; /* can be 0 length, on purpose */
	_roid->buf = (uint8_t*)MALLOC(_roid->size);
	if(!_roid->buf) {
		/* ENOMEM */
		_roid->size = 0;
		return -1;
	}
	
	memcpy(_roid->buf, _fulloid->buf + arcs_len, _roid->size);
	if(_roid->size > 0) {
		assert(!(_roid->buf[_roid->size - 1] & 0x80));
	}
	
	return 0;
}

RELATIVE_OID_t *RELATIVE_OID_new_fromOIDDiff(const OBJECT_IDENTIFIER_t *_oidbase,
	const OBJECT_IDENTIFIER_t *_fulloid) {
	RELATIVE_OID_t *roid;
	int result;
	
	roid = (RELATIVE_OID_t*)CALLOC(1, sizeof(*roid));
	if(!roid) {
		/* ENOMEM */
		return NULL;
	}
	result = RELATIVE_OID_fromOIDDiff(roid, _oidbase, _fulloid);
	if(result == 0) return roid;
	else {
		FREEMEM(roid);
		return NULL;
	}
}

int RELATIVE_OID_fromArcsCountDiff(RELATIVE_OID_t *_roid, size_t base_arcs_count,
	const OBJECT_IDENTIFIER_t *_fulloid) {
	size_t arcs_count = 1, arcs_len = 0, i;
	if(!_fulloid || !_fulloid->buf) {
		errno = EINVAL;
		return -1;
	}
	
	if(base_arcs_count < 2) {
		errno = ERANGE;
		return -1;
	}
	
	for(i = 0; i < _fulloid->size; i++) {
		if(!(_fulloid->buf[i] & 0x80)) {
			arcs_count++;
			arcs_len = i + 1;
			if (arcs_count == base_arcs_count) break;
		}
	}
	if(i == _fulloid->size) {
		errno = ERANGE;
		return -1;
	}
	
	assert(_fulloid->size >= arcs_len);
	_roid->size = _fulloid->size - arcs_len; /* can be 0 length, on purpose */
	_roid->buf = (uint8_t*)MALLOC(_roid->size);
	if(!_roid->buf) {
		/* ENOMEM */
		_roid->size = 0;
		return -1;
	}
	
	memcpy(_roid->buf, _fulloid->buf + arcs_len, _roid->size);
	if(_roid->size > 0) {
		assert(!(_roid->buf[_roid->size - 1] & 0x80));
	}
	
	return 0;
}

RELATIVE_OID_t *RELATIVE_OID_new_fromArcsCountDiff(size_t base_arcs_count,
	const OBJECT_IDENTIFIER_t *_fulloid) {
	RELATIVE_OID_t *roid;
	int result;
	
	roid = (RELATIVE_OID_t*)CALLOC(1, sizeof(*roid));
	if(!roid) {
		/* ENOMEM */
		return NULL;
	}
	result = RELATIVE_OID_fromArcsCountDiff(roid, base_arcs_count, _fulloid);
	if(result == 0) return roid;
	else {
		FREEMEM(roid);
		return NULL;
	}
}

int RELATIVE_OID_fromSizeDiff(RELATIVE_OID_t *_roid, size_t base_size,
	const OBJECT_IDENTIFIER_t *_fulloid) {
	if(!_fulloid || !_fulloid->buf) {
		errno = EINVAL;
		return -1;
	}
	
	if(_fulloid->size < base_size || base_size == 0) {
		errno = ERANGE;
		return -1;
	}
	
	if(_fulloid->buf[base_size-1] & 0x80) {
		/* base size must be arc-aligned */
		errno = EINVAL;
		return -1;
	}

	_roid->size = _fulloid->size - base_size; /* can be 0 length, on purpose */
	_roid->buf = (uint8_t*)MALLOC(_roid->size);
	if(!_roid->buf) {
		/* ENOMEM */
		_roid->size = 0;
		return -1;
	}
	
	memcpy(_roid->buf, _fulloid->buf + base_size, _roid->size);
	if(_roid->size > 0) {
		assert(!(_roid->buf[_roid->size - 1] & 0x80));
	}
	
	return 0;
}

RELATIVE_OID_t *RELATIVE_OID_new_fromSizeDiff(size_t base_size,
	const OBJECT_IDENTIFIER_t *_fulloid) {
	RELATIVE_OID_t *roid;
	int result;
	
	roid = (RELATIVE_OID_t*)CALLOC(1, sizeof(*roid));
	if(!roid) {
		/* ENOMEM */
		return NULL;
	}
	result = RELATIVE_OID_fromSizeDiff(roid, base_size, _fulloid);
	if(result == 0) return roid;
	else {
		FREEMEM(roid);
		return NULL;
	}
}

size_t RELATIVE_OID_get_arcs_count(const RELATIVE_OID_t *_roid) {
	size_t arcs_count = 0;
	int i;
	
	if(!_roid || !_roid->buf || _roid->size < 0) {
		errno = EINVAL;
		return 0;
	}
	
	if(_roid->size > 0) {
		/* The last byte must terminate the arc, with high-bit not set. */
		assert(!(_roid->buf[_roid->size-1] & 0x80));
	}
	
	for(i = 0; i < _roid->size; i++) {
		if(!(_roid->buf[i] & 0x80)) arcs_count++;
	}

	return arcs_count;
}
