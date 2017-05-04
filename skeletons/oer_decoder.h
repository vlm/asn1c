/*-
 * Copyright (c) 2005, 2007 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_OER_DECODER_H_
#define	_OER_DECODER_H_

#include <asn_application.h>
#include <per_support.h>

#ifdef __cplusplus
extern "C" {
#endif

struct asn_TYPE_descriptor_s;	/* Forward declaration */
struct asn_codec_ctx_s;		    /* Forward declaration */
/*
 * OER decoder of any ASN.1 type. May be invoked by the application.
 * This function may be invoked directly from the application.
 */
asn_dec_rval_t oer_decode(struct asn_codec_ctx_s *opt_codec_ctx,
	struct asn_TYPE_descriptor_s *type_descriptor,	/* Type to decode */
	void **struct_ptr,	/* Pointer to a target structure's pointer */
	const void *buffer,	/* Data to be decoded */
	size_t size		    /* Size of data buffer */
	);


/*
 * Type of the type-specific PER decoder function.
 */
typedef asn_dec_rval_t (oer_type_decoder_f)(asn_codec_ctx_t *opt_codec_ctx,
		struct asn_TYPE_descriptor_s *type_descriptor,
		asn_per_constraints_t *constraints,
		void **struct_ptr, const void *buf_ptr, size_t size);

#ifdef __cplusplus
}
#endif

#endif	/* _OER_DECODER_H_ */
