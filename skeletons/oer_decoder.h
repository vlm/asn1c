/*
 * Copyright (c) 2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_OER_DECODER_H_
#define	_OER_DECODER_H_

#include <asn_application.h>
#include <oer_support.h>

#ifdef __cplusplus
extern "C" {
#endif

struct asn_TYPE_descriptor_s;	/* Forward declaration */
struct asn_codec_ctx_s;		/* Forward declaration */

/*
 * The Octet Encoding Rules (OER, X.696 08/2015) decoder for any given type.
 * This function may be invoked directly by the application.
 */
asn_dec_rval_t oer_decode(struct asn_codec_ctx_s *opt_codec_ctx,
	struct asn_TYPE_descriptor_s *type_descriptor,
	void **struct_ptr,	/* Pointer to a target structure's pointer */
	const void *buffer,	/* Data to be decoded */
	size_t size		/* Size of that buffer */
	);

/*
 * Type of generic function which decodes the byte stream into the structure.
 */
typedef asn_dec_rval_t(oer_type_decoder_f)(
    struct asn_codec_ctx_s *opt_codec_ctx,
    struct asn_TYPE_descriptor_s *type_descriptor,
    asn_oer_constraint_t *constraints,
    void **struct_ptr,
    const void *buf_ptr,
    size_t size);

#ifdef __cplusplus
}
#endif

#endif	/* _OER_DECODER_H_ */
