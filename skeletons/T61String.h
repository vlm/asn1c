/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_T61String_H_
#define	_T61String_H_

#include <constr_TYPE.h>
#include <OCTET_STRING.h>

typedef OCTET_STRING_t T61String_t;	/* Implemented in terms of OCTET STRING */

extern asn1_TYPE_descriptor_t asn1_DEF_T61String;

#endif	/* _T61String_H_ */
