/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * This type differs from the standard REAL in that it is modelled using
 * the fixed machine type (double), so it can hold only values of
 * limited precision. There is no explicit type (i.e., NativeReal_t).
 * Use of this type is normally enabled by -fnative-types.
 */
#ifndef	ASN_TYPE_NativeReal_H
#define	ASN_TYPE_NativeReal_H

#include <asn_application.h>

#ifdef __cplusplus
extern "C" {
#endif

extern asn_TYPE_descriptor_t asn_DEF_NativeReal;
extern asn_TYPE_operation_t asn_OP_NativeReal;

asn_struct_free_f  NativeReal_free;
asn_struct_print_f NativeReal_print;
ber_type_decoder_f NativeReal_decode_ber;
der_type_encoder_f NativeReal_encode_der;
xer_type_decoder_f NativeReal_decode_xer;
xer_type_encoder_f NativeReal_encode_xer;
per_type_decoder_f NativeReal_decode_uper;
per_type_encoder_f NativeReal_encode_uper;

#define NativeReal_constraint  asn_generic_no_constraint

#ifdef __cplusplus
}
#endif

#endif	/* ASN_TYPE_NativeReal_H */
