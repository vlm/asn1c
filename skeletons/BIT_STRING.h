/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_BIT_STRING_H_
#define	_BIT_STRING_H_

#include <constr_TYPE.h>
#include <OCTET_STRING.h>

typedef OCTET_STRING_t BIT_STRING_t; /* Implemented in terms of OCTET STRING */

extern asn1_TYPE_descriptor_t asn1_DEF_BIT_STRING;

asn_struct_print_f BIT_STRING_print;	/* Human-readable output */
asn_constr_check_f BIT_STRING_constraint;

#endif	/* _BIT_STRING_H_ */
