/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <ANY.h>
#include <assert.h>
#include <errno.h>

asn1_TYPE_descriptor_t asn1_DEF_ANY = {
	"ANY",
	asn_generic_no_constraint,
	OCTET_STRING_decode_ber,
	OCTET_STRING_encode_der,
	OCTET_STRING_print,
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	0,
	0,
	0,	/* No tags may be overridden */
	-1,	/* Both ways are fine (primitive and constructed) */
	0, 0,	/* No members */
	(void *)1	/* Special indicator that this is an ANY type */
};
