/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_OBJECT_IDENTIFIER_H_
#define	_OBJECT_IDENTIFIER_H_

#include <constr_TYPE.h>
#include <INTEGER.h>

typedef INTEGER_t OBJECT_IDENTIFIER_t; /* Implemented in terms of INTEGER */

extern asn1_TYPE_descriptor_t asn1_DEF_OBJECT_IDENTIFIER;

der_type_encoder_f OBJECT_IDENTIFIER_encode_der;
asn_constr_check_f OBJECT_IDENTIFIER_constraint;
asn_struct_print_f OBJECT_IDENTIFIER_print;

/**********************************
 * Some handy conversion routines *
 **********************************/

/*
 * Print the specified OBJECT IDENTIFIER arc.
 */
int OBJECT_IDENTIFIER_print_arc(uint8_t *arcbuf, int arclen,
	int add, /* Arbitrary offset, required to process the first two arcs */
	asn_app_consume_bytes_f *cb, void *app_key);

/*
 * This function fills an (_arcs) array with OBJECT IDENTIFIER arcs
 * up to specified (_arcs_slots) elements.
 * The function always returns the real number of arcs, even if there is no
 * sufficient (_arcs_slots) provided.
 * 
 * EXAMPLE:
 * 	void print_arcs(OBJECT_IDENTIFIER_t *oid) {
 * 		unsigned long fixed_arcs[10];	// Try with fixed space first
 * 		unsigned long *arcs = fixed_arcs;
 * 		int arcs_slots = sizeof(fixed_arcs)/sizeof(fixed_arcs[0]); // 10
 * 		int count;	// Real number of arcs.
 * 		int i;
 * 
 * 		count = OBJECT_IDENTIFIER_get_arcs_l(oid, arcs, arcs_slots);
 * 		// If necessary, reallocate arcs array and try again.
 * 		if(count > arcs_slots) {
 * 			arcs_slots = count;
 * 			arcs = malloc(arcs_slots * sizeof(arcs[0]));
 * 			if(!arcs) return;
 * 			count = OBJECT_IDENTIFIER_get_arcs_l(oid,
 * 				arcs, arcs_slots);
 * 			assert(count == arcs_slots);
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
 */
int OBJECT_IDENTIFIER_get_arcs_l(OBJECT_IDENTIFIER_t *_oid,
	unsigned long *_arcs, int _arcs_slots);
/*
int OBJECT_IDENTIFIER_get_arcs_im(OBJECT_IDENTIFIER_t *_oid,
	uintmax_t *_arcs, int _arcs_slots);
 */


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
int OBJECT_IDENTIFIER_set_arcs_l(OBJECT_IDENTIFIER_t *_oid,
	unsigned long *arcs, int arcs_slots);

/*
 * Internal functions.
 */
int OBJECT_IDENTIFIER_get_arc_l(uint8_t *arcbuf, int arclen,
	int add, unsigned long *value);

#endif	/* _OBJECT_IDENTIFIER_H_ */
