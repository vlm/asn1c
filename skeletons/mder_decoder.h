/*-
 * Copyright (c) 2010 Santiago Carot-Nemesio <sancane@gmail.com>
 * Copyright (c) 2010 Jose Antonio Santos-Cadenas <santoscadenas@gmail.com>
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_MDER_DECODER_H_
#define	_MDER_DECODER_H_

#include <asn_application.h>
#include <mder_support.h>

#ifdef __cplusplus
extern "C" {
#endif

struct asn_TYPE_descriptor_s;	/* Forward declaration */
struct asn_codec_ctx_s;		/* Forward declaration */

/*
 * The MDER decoder of any type.
 * This function may be invoked directly from the application.
 * The mder_encode() function (mder_encoder.h) is an opposite to mder_decode().
 */
asn_dec_rval_t mder_decode(struct asn_codec_ctx_s *opt_codec_ctx,
	struct asn_TYPE_descriptor_s *type_descriptor,
	void **struct_ptr,	/* Pointer to a target structure's pointer */
	const void *buffer,	/* Data to be decoded */
	size_t size		/* Size of that buffer */
	);

/*
 * Type of generic function which decodes the byte stream into the structure.
 */
typedef asn_dec_rval_t (mder_type_decoder_f)(
		struct asn_codec_ctx_s *opt_codec_ctx,
		struct asn_TYPE_descriptor_s *type_descriptor,
		void **struct_ptr, const void *buf_ptr, size_t size,
		asn_mder_contraints_t constr);

mder_type_decoder_f NON_SUP_decode_mder;

#ifdef __cplusplus
}
#endif

#endif	/* _MDER_DECODER_H_ */
