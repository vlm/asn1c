/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_BOOLEAN_H_
#define	_BOOLEAN_H_

#include <constr_TYPE.h>

typedef struct BOOLEAN {
	int value;
} BOOLEAN_t;

extern asn1_TYPE_descriptor_t asn1_DEF_BOOLEAN;

ber_type_decoder_f BOOLEAN_decode_ber;
der_type_encoder_f BOOLEAN_encode_der;
asn_struct_print_f BOOLEAN_print;
asn_struct_free_f BOOLEAN_free;

#endif	/* _BOOLEAN_H_ */
