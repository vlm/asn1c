/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_CONSTR_SET_H_
#define	_CONSTR_SET_H_

#include <constr_TYPE.h>

/*
 * Description of a single element of the SET type.
 */
typedef struct asn1_SET_element_s {
	int memb_offset;		/* Offset of the element */
	int optional;			/* Whether the element is optional */
	ber_tlv_tag_t tag;		/* Outmost (most immediate) tag */
	int tag_mode;		/* IMPLICIT/no/EXPLICIT tag at current level */
	asn1_TYPE_descriptor_t *type;	/* Member type descriptor */
	char *name;			/* ASN.1 identifier of the element */
} asn1_SET_element_t;


typedef struct asn1_SET_specifics_s {
	/*
	 * Target structure description.
	 */
	int struct_size;	/* Size of the target structure. */
	int ctx_offset;		/* Offset of the ber_dec_ctx_t member */
	int pres_offset;	/* Offset of _presence_map member */

	/*
	 * Members of the SET structure.
	 */
	asn1_SET_element_t *elements;
	int elements_count;

	/*
	 * Tags to members mapping table (sorted).
	 */
	asn1_TYPE_tag2member_t *tag2el;
	int tag2el_count;

	/*
	 * Extensions-related stuff.
	 */
	int extensible;				/* Whether SET is extensible */
	unsigned int *_mandatory_elements;	/* Bitmask of mandatory ones */
} asn1_SET_specifics_t;

/*
 * A set specialized functions dealing with the SET type.
 */
asn_constr_check_f SET_constraint;
ber_type_decoder_f SET_decode_ber;
der_type_encoder_f SET_encode_der;
asn_struct_print_f SET_print;
asn_struct_free_f SET_free;

/***********************
 * Some handy helpers. *
 ***********************/

/*
 * Figure out whether the SET member indicated by PR_x has already been decoded.
 * It is very simple bitfield test, despite its visual complexity.
 */
#define	ASN_SET_ISPRESENT(set_ptr, PR_x)				\
	ASN_SET_ISPRESENT2(&((set_ptr)->_presence_map))
#define	ASN_SET_ISPRESENT2(map_ptr, PR_x)				\
	(((unsigned int *)(map_ptr))					\
		[(PR_x)	/ (8 * sizeof(unsigned int))]			\
		& (1 << ((8 * sizeof(unsigned int)) - 1			\
		- ((PR_x) % (8 * sizeof(unsigned int))))))

#define	ASN_SET_MKPRESENT(map_ptr, PR_x)				\
	(((unsigned int *)(map_ptr))					\
		[(PR_x)	/ (8 * sizeof(unsigned int))]			\
		|= (1 << ((8 * sizeof(unsigned int)) - 1		\
		- ((PR_x) % (8 * sizeof(unsigned int))))))

#endif	/* _CONSTR_SET_H_ */
