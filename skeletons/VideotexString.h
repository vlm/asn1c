/*-
 * Copyright (c) 2003 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_VideotexString_H_
#define	_VideotexString_H_

#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef OCTET_STRING_t VideotexString_t;  /* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t asn_DEF_VideotexString;
extern asn_TYPE_operation_t asn_OP_VideotexString;

#define VideotexString_constraint   asn_generic_unknown_constraint

#ifdef __cplusplus
}
#endif

#endif	/* _VideotexString_H_ */
