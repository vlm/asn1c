/*-
 * Copyright (c) 2003-2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_NumericString_H_
#define	_NumericString_H_

#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef OCTET_STRING_t NumericString_t;	/* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t asn_DEF_NumericString;
extern asn_TYPE_operation_t asn_OP_NumericString;

asn_constr_check_f NumericString_constraint;

#define NumericString_free          OCTET_STRING_free
#define NumericString_print         OCTET_STRING_print_utf8
#define NumericString_compare       OCTET_STRING_compare
#define NumericString_decode_ber    OCTET_STRING_decode_ber
#define NumericString_encode_der    OCTET_STRING_encode_der
#define NumericString_decode_xer    OCTET_STRING_decode_xer_utf8
#define NumericString_encode_xer    OCTET_STRING_encode_xer_utf8
#define NumericString_decode_uper   OCTET_STRING_decode_uper
#define NumericString_encode_uper   OCTET_STRING_encode_uper
#define NumericString_decode_aper   OCTET_STRING_decode_aper
#define NumericString_encode_aper   OCTET_STRING_encode_aper

#ifdef __cplusplus
}
#endif

#endif	/* _NumericString_H_ */
