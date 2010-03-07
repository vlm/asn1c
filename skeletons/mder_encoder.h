/*-
 * Copyright (c) 2010 Santiago Carot-Nemesio <sancane@gmail.com>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_MDER_ENCODER_H_
#define	_MDER_ENCODER_H_

#include <asn_application.h>

#ifdef __cplusplus
extern "C" {
#endif

struct asn_TYPE_descriptor_s;	/* Forward declaration */

/*
 * The MDER encoder of any type. May be invoked by the application.
 * The ber_decode() function (ber_decoder.h) is an opposite of der_encode().
 */
asn_enc_rval_t mder_encode(struct asn_TYPE_descriptor_s *type_descriptor,
		void *struct_ptr,	/* Structure to be encoded */
		asn_app_consume_bytes_f *consume_bytes_cb,
		void *app_key		/* Arbitrary callback argument */
	);

/* A variant of mder_encode() which encodes data into the pre-allocated buffer */
asn_enc_rval_t mder_encode_to_buffer(
		struct asn_TYPE_descriptor_s *type_descriptor,
		void *struct_ptr,	/* Structure to be encoded */
		void *buffer,		/* Pre-allocated buffer */
		size_t buffer_size	/* Initial buffer size (maximum) */
	);

/*
 * Type of the generic MDER encoder.
 */
typedef asn_enc_rval_t (mder_type_encoder_f)(
		struct asn_TYPE_descriptor_s *type_descriptor,
		void *struct_ptr,	/* Structure to be encoded */
		int tag_mode,		/* {-1,0,1}: IMPLICIT, no, EXPLICIT */
		ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *consume_bytes_cb,	/* Callback */
		void *app_key		/* Arbitrary callback argument */
	);

#ifdef __cplusplus
}
#endif

#endif	/* _MDER_ENCODER_H_ */
