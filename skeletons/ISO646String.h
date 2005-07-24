/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_ISO646String_H_
#define	_ISO646String_H_

#include <asn_application.h>
#include <VisibleString.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef VisibleString_t ISO646String_t;	/* Implemented using VisibleString */

extern asn_TYPE_descriptor_t asn_DEF_ISO646String;

#ifdef __cplusplus
}
#endif

#endif	/* _ISO646String_H_ */
