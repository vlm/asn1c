/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	ASN_CODECS_PRIM_H
#define	ASN_CODECS_PRIM_H

#include <asn_application.h>

typedef struct ASN__PRIMITIVE_TYPE_s {
	uint8_t *buf;	/* Buffer with consecutive primitive encoding bytes */
	int size;	/* Size of the buffer */
} ASN__PRIMITIVE_TYPE_t;	/* Do not use this type directly! */

asn_struct_free_f ASN__PRIMITIVE_TYPE_free;
ber_type_decoder_f ber_decode_primitive;
der_type_encoder_f der_encode_primitive;

/*
 * Specific function to decode simple primitive types.
 * Also see xer_decode_general() in xer_decoder.h
 */
asn_dec_rval_t xer_decode_primitive(asn_codec_ctx_t *opt_codec_ctx,
	asn_TYPE_descriptor_t *type_descriptor,
	void **struct_ptr, size_t struct_size,
	const char *opt_mname,
	void *buf_ptr, size_t size,
	ssize_t (*prim_body_decode)(void *struct_ptr,
		void *chunk_buf, size_t chunk_size)
	);

#endif	/* ASN_CODECS_PRIM_H */
