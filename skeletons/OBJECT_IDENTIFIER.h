/*-
 * Copyright (c) 2003, 2004, 2005 Lev Walkin <vlm@lionet.info>.
 * Copyright (c) 2010, 2011 Sean Leonard of SeanTek(R) <dev+asn1c@seantek.com>.
 * 	All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_OBJECT_IDENTIFIER_H_
#define	_OBJECT_IDENTIFIER_H_

#include <asn_application.h>
#include <asn_codecs_prim.h>

#ifdef __cplusplus
extern "C" {
#endif

/* typedef ASN__PRIMITIVE_TYPE_t OBJECT_IDENTIFIER_t; */
typedef struct OBJECT_IDENTIFIER {
	uint8_t *buf; /* Buffer with consecutive primitive encoding types */
	int size; /* Size of the buffer */
} OBJECT_IDENTIFIER_t;

extern asn_TYPE_descriptor_t asn_DEF_OBJECT_IDENTIFIER;

asn_struct_print_f OBJECT_IDENTIFIER_print;
asn_constr_check_f OBJECT_IDENTIFIER_constraint;
der_type_encoder_f OBJECT_IDENTIFIER_encode_der;
xer_type_decoder_f OBJECT_IDENTIFIER_decode_xer;
xer_type_encoder_f OBJECT_IDENTIFIER_encode_xer;

/* Implemented with the same layout as ASN__PRIMITIVE_TYPE_t */
/* typedef OBJECT_IDENTIFIER_t RELATIVE_OID_t; */
typedef struct RELATIVE_OID {
	uint8_t *buf; /* Buffer with consecutive primitive encoding types */
	int size; /* Size of the buffer */
} RELATIVE_OID_t;

/**********************************
 * Some handy conversion routines *
 **********************************/

/*
 * This function fills an (_arcs) array with OBJECT IDENTIFIER arcs
 * up to specified (_arc_slots) elements.
 * 
 * EXAMPLE:
 * 	void print_arcs(OBJECT_IDENTIFIER_t *oid) {
 * 		unsigned long fixed_arcs[10];	// Try with fixed space first
 * 		unsigned long *arcs = fixed_arcs;
 * 		int arc_type_size = sizeof(fixed_arcs[0]);	// sizeof(long)
 * 		int arc_slots = sizeof(fixed_arcs)/sizeof(fixed_arcs[0]); // 10
 * 		int count;	// Real number of arcs.
 * 		int i;
 * 
 * 		count = OBJECT_IDENTIFIER_get_arcs(oid, arcs,
 * 			arc_type_size, arc_slots);
 * 		// If necessary, reallocate arcs array and try again.
 * 		if(count > arc_slots) {
 * 			arc_slots = count;
 * 			arcs = malloc(arc_type_size * arc_slots);
 * 			if(!arcs) return;
 * 			count = OBJECT_IDENTIFIER_get_arcs(oid, arcs,
 * 				arc_type_size, arc_slots);
 * 			assert(count == arc_slots);
 * 		}
 * 
 * 		// Print the contents of the arcs array.
 * 		for(i = 0; i < count; i++)
 * 			printf("%d\n", arcs[i]);
 * 
 * 		// Avoid memory leak.
 * 		if(arcs != fixed_arcs) free(arcs);
 * 	}
 * 
 * RETURN VALUES:
 * -1/EINVAL:	Invalid arguments (oid is missing)
 * -1/ERANGE:	One or more arcs have value out of array cell type range.
 * >=0:		Number of arcs contained in the OBJECT IDENTIFIER
 * 
 * WARNING: The function always returns the real number of arcs,
 * even if there is no sufficient (_arc_slots) provided.
 */
int OBJECT_IDENTIFIER_get_arcs(OBJECT_IDENTIFIER_t *_oid,
	void *_arcs,			/* e.g., unsigned int arcs[N] */
	unsigned int _arc_type_size,	/* e.g., sizeof(arcs[0]) */
	unsigned int _arc_slots		/* e.g., N */);

/*
 * This functions initializes the OBJECT IDENTIFIER object with
 * the given set of arcs.
 * The minimum of two arcs must be present; some restrictions apply.
 * RETURN VALUES:
 * -1/EINVAL:	Invalid arguments
 * -1/ERANGE:	The first two arcs do not conform to ASN.1 restrictions.
 * -1/ENOMEM:	Memory allocation failed
 * 0:		The object was initialized with new arcs.
 */
int OBJECT_IDENTIFIER_set_arcs(OBJECT_IDENTIFIER_t *_oid,
	const void *_arcs,		/* e.g., unsigned int arcs[N] */
	unsigned int _arc_type_size,	/* e.g., sizeof(arcs[0]) */
	unsigned int _arc_slots		/* e.g., N */);

/*
 * Print the specified OBJECT IDENTIFIER arc.
 */
int OBJECT_IDENTIFIER_print_arc(uint8_t *arcbuf, int arclen,
	int add, /* Arbitrary offset, required to process the first two arcs */
	asn_app_consume_bytes_f *cb, void *app_key);

/* Same as above, but returns the number of written digits, instead of 0 */
ssize_t OBJECT_IDENTIFIER__dump_arc(uint8_t *arcbuf, int arclen, int add,
	asn_app_consume_bytes_f *cb, void *app_key);

/*
 * Parse the OBJECT IDENTIFIER dot notation ("1.3.6.1.4.1.9363").
 * No arc can exceed the (0..signed_long_max) range (typically, 0..2G if L32).
 * This function is not specific to OBJECT IDENTIFIER, it may be used to parse
 * the RELATIVE-OID data, or any other data consisting of dot-separated
 * series of numeric values.
 *
 * If (oid_txt_length == -1), the strlen() will be invoked to determine the
 * size of the (oid_text) string.
 * 
 * After return, the optional (opt_oid_text_end) is set to the character after
 * the last parsed one. (opt_oid_text_end) is never less than (oid_text).
 * 
 * RETURN VALUES:
 *   -1:	Parse error.
 * >= 0:	Number of arcs contained in the OBJECT IDENTIFIER.
 * 
 * WARNING: The function always returns the real number of arcs,
 * even if there is no sufficient (_arc_slots) provided.
 * This is useful for (_arc_slots) value estimation.
 */
int OBJECT_IDENTIFIER_parse_arcs(const char *oid_text, ssize_t oid_txt_length,
	long arcs[], unsigned int arcs_slots, const char **opt_oid_text_end);

/*
 * Internal functions.
 * Used by RELATIVE-OID implementation in particular.
 */
int OBJECT_IDENTIFIER_get_single_arc(uint8_t *arcbuf, unsigned int arclen,
	signed int add, void *value, unsigned int value_size);
int OBJECT_IDENTIFIER_set_single_arc(uint8_t *arcbuf,
	const void *arcval, unsigned int arcval_size, int _prepared_order);

/* OID utility functions contributed by Sean Leonard of SeanTek(R). */

/*
 * Constructor utilities to make new OBJECT_IDENTIFIERs.
 */

int OBJECT_IDENTIFIER_fromIdentifiers(OBJECT_IDENTIFIER_t *_oid,
	const OBJECT_IDENTIFIER_t *_oidbase, ...);

OBJECT_IDENTIFIER_t *OBJECT_IDENTIFIER_new_fromIdentifiers(
	const OBJECT_IDENTIFIER_t *_oidbase, ...);

int OBJECT_IDENTIFIER_fromDotNotation(OBJECT_IDENTIFIER_t *_oid,
	const char *oid_text, ssize_t oid_text_length);

OBJECT_IDENTIFIER_t *OBJECT_IDENTIFIER_new_fromDotNotation(
	const char *oid_text, ssize_t oid_text_length);

/*
 * General-purpose functions to compare an OID with arbitrary
 * RELATIVE-OIDs afterwards. cmp returns >0, 0, <0 depending
 * on value (like strcmp or memcmp); eq returns zero (false) if unequal,
 * and nonzero (true) if equal. eq is faster than cmp.
 */

int OBJECT_IDENTIFIER_cmp(const OBJECT_IDENTIFIER_t *_oid1,
	const OBJECT_IDENTIFIER_t *_oid2base, ...);

int OBJECT_IDENTIFIER_eq(const OBJECT_IDENTIFIER_t *_oid1,
	const OBJECT_IDENTIFIER_t *_oid2base, ...);

/*
 * Fast, inline functions to compare two OIDs
 * without arbitrary RELATIVE-OIDs afterwards.
 */

static inline int OBJECT_IDENTIFIER_cmp0(const OBJECT_IDENTIFIER_t *_oid1,
	const OBJECT_IDENTIFIER_t *_oid2) {
	if(!_oid1) return _oid2 ? -1 : 0;
	else if(!_oid2) return 1;
	else {
		ssize_t min_size = _oid1->size < _oid2->size ? _oid1->size : _oid2->size;
		int memcmp_result = memcmp(_oid1->buf, _oid2->buf, min_size);
		if(memcmp_result != 0) return memcmp_result;
		else return (unsigned int)_oid1->size - (unsigned int)_oid2->size;
	}
}

static inline int OBJECT_IDENTIFIER_eq0(const OBJECT_IDENTIFIER_t *_oid1,
	const OBJECT_IDENTIFIER_t *_oid2) {
	if(!_oid1) return !_oid2;
	else if(!_oid2) return 0;
	else if(_oid1->size != _oid2->size) return 0;
	else return !memcmp(_oid1->buf, _oid2->buf, _oid1->size);
}

/*
 * Specialized functions to compare when a RELATIVE-OID
 * is present on one or both sides. Slightly faster than the general
 * algorithm. Unlike the prior functions, these functions assume
 * (assert) that all arguments are non-null.
 */

int OBJECT_IDENTIFIER_eq1(const OBJECT_IDENTIFIER_t *_oid1,
	const OBJECT_IDENTIFIER_t *_oid2base, const RELATIVE_OID_t *_roid2);

int OBJECT_IDENTIFIER_1eq1(const OBJECT_IDENTIFIER_t *_oid1base,
	const RELATIVE_OID_t *_roid1, const OBJECT_IDENTIFIER_t *_oid2base,
	const RELATIVE_OID_t *_roid2);

/*
 * Useful functions to find the greatest common arc.
 * In all cases, _oid0->size is reduced to the length of the common arc,
 * but the buf is not reallocated.
 * min_arcs is the minimum number of arcs that must be common in order
 * for there to be a success. Due to BER encoding rules, min_arcs = 1 has
 * the same behavior as min_arcs = 2.
 * The return value is the number of arcs that are common.
 * On failure, 0 is returned, and errno is set.
 */

size_t OBJECT_IDENTIFIER_common(size_t min_arcs, OBJECT_IDENTIFIER_t *_oid0, ...);
size_t OBJECT_IDENTIFIER_common1(size_t min_arcs, OBJECT_IDENTIFIER_t *_oid0,
	const OBJECT_IDENTIFIER_t *_oid1);
size_t OBJECT_IDENTIFIER_common2(size_t min_arcs, OBJECT_IDENTIFIER_t *_oid0,
	const OBJECT_IDENTIFIER_t *_oid1, const OBJECT_IDENTIFIER_t *_oid2);

size_t OBJECT_IDENTIFIER_common1r(size_t min_arcs, OBJECT_IDENTIFIER_t *_oid0,
	const OBJECT_IDENTIFIER_t *_oid1base, ...);
size_t OBJECT_IDENTIFIER_common1r1(size_t min_arcs, OBJECT_IDENTIFIER_t *_oid0,
	const OBJECT_IDENTIFIER_t *_oid1base, const RELATIVE_OID_t *_roid1);

/*
 * Similar to get_arcs, but without the attempt to actually allocate or write
 * any arcs.
 * This function is fast and returns the number of arcs in the OID.
 * The first BER encoded group is treated as 2 arcs, per X.680.
 * In cases of failure, 0 is returned and errno is set.
 */
size_t OBJECT_IDENTIFIER_get_arcs_count(const OBJECT_IDENTIFIER_t *_oid);

#ifdef __cplusplus
}
#endif

#endif	/* _OBJECT_IDENTIFIER_H_ */
