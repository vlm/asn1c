/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_UniversalString_H_
#define	_UniversalString_H_

#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef OCTET_STRING_t UniversalString_t;  /* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t asn_DEF_UniversalString;

asn_struct_print_f UniversalString_print;	/* Human-readable output */
xer_type_decoder_f UniversalString_decode_xer;
xer_type_encoder_f UniversalString_encode_xer;

#ifdef __cplusplus
}
#endif

#endif	/* _UniversalString_H_ */
