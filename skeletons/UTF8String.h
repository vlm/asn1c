/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_UTF8String_H_
#define	_UTF8String_H_

#include <constr_TYPE.h>
#include <OCTET_STRING.h>

typedef OCTET_STRING_t UTF8String_t;	/* Implemented in terms of OCTET STRING */

extern asn1_TYPE_descriptor_t asn1_DEF_UTF8String;

asn_constr_check_f UTF8String_constraint;
asn_struct_print_f UTF8String_print;

/* Returns length of UTF-8 string in characters or -1 if error. */
ssize_t UTF8String_length(const UTF8String_t *st, const char *opt_type_name,
	asn_app_consume_bytes_f *app_errlog, void *app_key);

#endif	/* _UTF8String_H_ */
