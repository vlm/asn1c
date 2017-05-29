/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_T61String_H_
#define	_T61String_H_

#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef OCTET_STRING_t T61String_t;	/* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t asn_DEF_T61String;
extern asn_TYPE_operation_t asn_OP_T61String;

#define T61String_constraint   asn_generic_unknown_constraint

#ifdef __cplusplus
}
#endif

#endif	/* _T61String_H_ */
