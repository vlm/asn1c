/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_UTF8String_H_
#define	_UTF8String_H_

#include <OCTET_STRING.h>

typedef OCTET_STRING_t UTF8String_t;	/* Implemented via OCTET STRING */

extern asn_TYPE_descriptor_t asn_DEF_UTF8String;

asn_struct_print_f UTF8String_print;
asn_constr_check_f UTF8String_constraint;

/*
 * Returns length of the given UTF-8 string in characters,
 * or a negative error code:
 * -1:	UTF-8 sequence truncated 
 * -2:	Illegal UTF-8 sequence start
 * -3:	Continuation expectation failed
 * -4:	Not minimal length encoding
 * -5:	Invalid arguments
 */
ssize_t UTF8String_length(const UTF8String_t *st);

#endif	/* _UTF8String_H_ */
