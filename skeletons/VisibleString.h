/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_VisibleString_H_
#define	_VisibleString_H_

#include <OCTET_STRING.h>

typedef OCTET_STRING_t VisibleString_t;  /* Implemented via OCTET STRING */

extern asn1_TYPE_descriptor_t asn1_DEF_VisibleString;

asn_constr_check_f VisibleString_constraint;

#endif	/* _VisibleString_H_ */
