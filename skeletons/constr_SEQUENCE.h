/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_CONSTR_SEQUENCE_H_
#define	_CONSTR_SEQUENCE_H_

#include <constr_TYPE.h>

/*
 * A single element of the SEQUENCE type.
 */
typedef struct asn1_SEQUENCE_element_s {
	int memb_offset;		/* Offset of the element */
	int optional;			/* Whether the element is optional */
	ber_tlv_tag_t tag;		/* Outmost (most immediate) tag */
	int tag_mode;		/* IMPLICIT/no/EXPLICIT tag at current level */
	asn1_TYPE_descriptor_t
		*type;			/* Member type descriptor */
	char *name;			/* ASN.1 identifier of the element */
} asn1_SEQUENCE_element_t;

typedef struct asn1_SEQUENCE_specifics_s {
	/*
	 * Target structure description.
	 */
	int struct_size;	/* Size of the target structure. */
	int ctx_offset;		/* Offset of the ber_dec_ctx_t member */

	/*
	 * Members of the SEQUENCE structure.
	 */
	asn1_SEQUENCE_element_t *elements;
	int elements_count;

	/*
	 * Description of an extensions group.
	 */
	int ext_after;	/* Extensions start after this member */
	int ext_before;	/* Extensions stop before this member */
} asn1_SEQUENCE_specifics_t;


/*
 * A set specialized functions dealing with the SEQUENCE type.
 */
asn_constr_check_f SEQUENCE_constraint;
ber_type_decoder_f SEQUENCE_decode_ber;
der_type_encoder_f SEQUENCE_encode_der;
asn_struct_print_f SEQUENCE_print;
asn_struct_free_f SEQUENCE_free;

#endif	/* _CONSTR_SEQUENCE_H_ */
