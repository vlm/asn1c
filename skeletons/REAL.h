/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	ASN_TYPE_REAL_H
#define	ASN_TYPE_REAL_H

#include <asn_application.h>
#include <asn_codecs_prim.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef ASN__PRIMITIVE_TYPE_t REAL_t;

extern asn_TYPE_descriptor_t asn_DEF_REAL;

asn_struct_print_f REAL_print;
xer_type_decoder_f REAL_decode_xer;
xer_type_encoder_f REAL_encode_xer;
per_type_decoder_f REAL_decode_uper;
per_type_encoder_f REAL_encode_uper;

/***********************************
 * Some handy conversion routines. *
 ***********************************/

ssize_t REAL__dump(double d, int canonical, asn_app_consume_bytes_f *cb, void *app_key);

/*
 * Convert between native double type and REAL representation (DER).
 * RETURN VALUES:
 *  0: Value converted successfully
 * -1: An error occured while converting the value: invalid format.
 */
int asn_REAL2double(const REAL_t *real_ptr, double *d);
int asn_double2REAL(REAL_t *real_ptr, double d);

#ifdef __cplusplus
}
#endif

#endif	/* ASN_TYPE_REAL_H */
