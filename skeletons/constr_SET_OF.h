/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_CONSTR_SET_OF_H_
#define	_CONSTR_SET_OF_H_

#include <constr_TYPE.h>

typedef struct asn1_SET_OF_element_s {
	ber_tlv_tag_t tag;		/* Outmost (most immediate) tag */
	asn1_TYPE_descriptor_t
		*type;			/* Member type descriptor */
} asn1_SET_OF_element_t;

typedef struct asn1_SET_OF_specifics_s {
	/*
	 * Target structure description.
	 */
	int struct_size;	/* Size of the target structure. */
	int ctx_offset;		/* Offset of the ber_dec_ctx_t member */

	/*
	 * Members of the SET OF list.
	 */
	asn1_SET_OF_element_t *element;
} asn1_SET_OF_specifics_t;

/*
 * A set specialized functions dealing with the SET OF type.
 */
asn_constr_check_f SET_OF_constraint;
ber_type_decoder_f SET_OF_decode_ber;
der_type_encoder_f SET_OF_encode_der;
asn_struct_print_f SET_OF_print;
asn_struct_free_f SET_OF_free;

#endif	/* _CONSTR_SET_OF_H_ */
