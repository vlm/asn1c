/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_BIT_STRING_H_
#define	_BIT_STRING_H_

#include <OCTET_STRING.h>

typedef OCTET_STRING_t BIT_STRING_t; /* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t asn_DEF_BIT_STRING;

asn_struct_print_f BIT_STRING_print;	/* Human-readable output */
asn_constr_check_f BIT_STRING_constraint;
xer_type_encoder_f BIT_STRING_encode_xer;

#endif	/* _BIT_STRING_H_ */
