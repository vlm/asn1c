/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_NULL_H_
#define	_NULL_H_

#include <constr_TYPE.h>

typedef struct NULL_s {
	int value;
} NULL_t;

extern asn1_TYPE_descriptor_t asn1_DEF_NULL;

der_type_encoder_f NULL_encode_der;
asn_struct_print_f NULL_print;

#endif	/* _NULL_H_ */
