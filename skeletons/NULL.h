/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	ASN_TYPE_NULL_H
#define	ASN_TYPE_NULL_H

#include <constr_TYPE.h>

/*
 * The value of the NULL type is meaningless: see BOOLEAN if you want to
 * carry true/false semantics.
 */
typedef int NULL_t;

extern asn1_TYPE_descriptor_t asn1_DEF_NULL;

der_type_encoder_f NULL_encode_der;
asn_struct_print_f NULL_print;

#endif	/* NULL_H */
