/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_GraphicString_H_
#define	_GraphicString_H_

#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef OCTET_STRING_t GraphicString_t;	/* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t asn_DEF_GraphicString;
extern asn_TYPE_operation_t asn_OP_GraphicString;

#define GraphicString_constraint  asn_generic_unknown_constraint

#ifdef __cplusplus
}
#endif

#endif	/* _GraphicString_H_ */
