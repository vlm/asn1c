/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_GeneralString_H_
#define	_GeneralString_H_

#include <constr_TYPE.h>
#include <OCTET_STRING.h>

typedef OCTET_STRING_t GeneralString_t;	/* Implemented in terms of OCTET STRING */

extern asn1_TYPE_descriptor_t asn1_DEF_GeneralString;

#endif	/* _GeneralString_H_ */
