/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_CONSTR_CHOICE_H_
#define	_CONSTR_CHOICE_H_

#include <asn_application.h>

typedef struct asn_CHOICE_specifics_s {
	/*
	 * Target structure description.
	 */
	int struct_size;	/* Size of the target structure. */
	int ctx_offset;		/* Offset of the ber_dec_ctx_t member */
	int pres_offset;	/* Identifier of the present member */
	int pres_size;		/* Size of the identifier (enum) */

	/*
	 * Tags to members mapping table.
	 */
	asn_TYPE_tag2member_t *tag2el;
	int tag2el_count;

	/*
	 * Extensions-related stuff.
	 */
	int extensible;			/* Whether CHOICE is extensible */
} asn_CHOICE_specifics_t;

/*
 * A set specialized functions dealing with the CHOICE type.
 */
asn_struct_free_f CHOICE_free;
asn_struct_print_f CHOICE_print;
asn_constr_check_f CHOICE_constraint;
ber_type_decoder_f CHOICE_decode_ber;
der_type_encoder_f CHOICE_encode_der;
xer_type_encoder_f CHOICE_encode_xer;
asn_outmost_tag_f CHOICE_outmost_tag;

#endif	/* _CONSTR_CHOICE_H_ */
