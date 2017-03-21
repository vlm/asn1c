/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	ASN_TYPE_NULL_H
#define	ASN_TYPE_NULL_H

#include <asn_application.h>
#include <BOOLEAN.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The value of the NULL type is meaningless: see BOOLEAN if you want to
 * carry true/false semantics.
 */
typedef int NULL_t;

extern asn_TYPE_descriptor_t asn_DEF_NULL;
extern asn_TYPE_operation_t asn_OP_NULL;

asn_struct_print_f NULL_print;
der_type_encoder_f NULL_encode_der;
xer_type_decoder_f NULL_decode_xer;
xer_type_encoder_f NULL_encode_xer;
per_type_decoder_f NULL_decode_uper;
per_type_encoder_f NULL_encode_uper;

#define NULL_constraint  asn_generic_no_constraint

#ifdef __cplusplus
}
#endif

#endif	/* NULL_H */
