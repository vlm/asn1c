/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_RELATIVE_OID_H_
#define	_RELATIVE_OID_H_

#include <OBJECT_IDENTIFIER.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Implemented with the same layout as ASN__PRIMITIVE_TYPE_t */
/* typedef OBJECT_IDENTIFIER_t RELATIVE_OID_t; */
struct RELATIVE_OID {
	uint8_t *buf; /* Buffer with consecutive primitive encoding types */
	int size; /* Size of the buffer */
};

extern asn_TYPE_descriptor_t asn_DEF_RELATIVE_OID;

asn_struct_print_f RELATIVE_OID_print;
xer_type_decoder_f RELATIVE_OID_decode_xer;
xer_type_encoder_f RELATIVE_OID_encode_xer;

/**********************************
 * Some handy conversion routines *
 **********************************/

/* See OBJECT_IDENTIFIER_get_arcs() function in OBJECT_IDENTIFIER.h */
int RELATIVE_OID_get_arcs(RELATIVE_OID_t *_roid,
	void *arcs, unsigned int arc_type_size, unsigned int arc_slots);

/* See OBJECT_IDENTIFIER_set_arcs() function in OBJECT_IDENTIFIER.h */
int RELATIVE_OID_set_arcs(RELATIVE_OID_t *_roid,
	void *arcs, unsigned int arc_type_size, unsigned int arcs_slots);


int RELATIVE_OID_cmp(const RELATIVE_OID_t *_roid1,
	const RELATIVE_OID_t *_roid2base, ...);

int RELATIVE_OID_eq(const RELATIVE_OID_t *_roid1,
	const RELATIVE_OID_t *_roid2base, ...);

static inline int RELATIVE_OID_cmp0(const RELATIVE_OID_t *_roid1,
	const RELATIVE_OID_t *_roid2) {
	if(!_roid1) return _roid2 ? -1 : 0;
	else if(!_roid2) return 1;
	else {
		ssize_t min_size = _roid1->size < _roid2->size ? _roid1->size : _roid2->size;
		int memcmp_result = memcmp(_roid1->buf, _roid2->buf, min_size);
		if(memcmp_result != 0) return memcmp_result;
		else return (unsigned int)_roid1->size - (unsigned int)_roid2->size;
	}
}

static inline int RELATIVE_OID_eq0(const RELATIVE_OID_t *_roid1,
	const RELATIVE_OID_t *_roid2) {
	if(!_roid1) return _roid2 ? 0 : 1;
	else if(!_roid2) return 0;
	else if(_roid1->size != _roid2->size) return 0;
	else return !memcmp(_roid1->buf, _roid2->buf, _roid1->size);
}

/*
 * Constructor utilities to make new RELATIVE_OIDs from the differential
 * between a base OID and a full OID.
 * base OID: 1 2 3 
 * full OID: 1 2 3 4 5
 * new ROID:       4 5
 * The intended use case is when serializing out protocol elements
 * where there is a base OID and a series of relative OIDs that combine
 * with the base, as in X.680 (2002) E.2.19.1.
 * If there is no commonality, an error is returned and (in the case of _fromDiff)
 * _roid is not modified.
 */

int RELATIVE_OID_fromDiff(RELATIVE_OID_t *_roid, const OBJECT_IDENTIFIER_t *_oidbase,
	const OBJECT_IDENTIFIER_t *_fulloid);

RELATIVE_OID_t *RELATIVE_OID_new_fromDiff(const OBJECT_IDENTIFIER_t *_oidbase,
	const OBJECT_IDENTIFIER_t *_fulloid);

/*
 * See OBJECT_IDENTIFIER_get_arcs_count. Unlike that function, this function
 * does not treat the first BER encoded group as 2 arcs.
 */
size_t RELATIVE_OID_get_arcs_count(const RELATIVE_OID_t *_roid);

#ifdef __cplusplus
}
#endif

#endif	/* _RELATIVE_OID_H_ */
