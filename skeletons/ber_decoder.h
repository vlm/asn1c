/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_BER_DECODER_H_
#define	_BER_DECODER_H_

#include <asn_application.h>

struct asn_TYPE_descriptor_s;	/* Forward declaration */
struct asn_codec_ctx_s;		/* Forward declaration */

/*
 * This structure describes the return value common across the
 * various BER decoders.
 * 
 * Please note that the number of consumed bytes is ALWAYS meaningful,
 * even if code!=RC_OK. This is so to indicate the number of successfully
 * decoded bytes, hence provide a possibility, to fail with more diagnostics
 * (i.e., print the offending remainder of the buffer).
 */
  enum ber_dec_rval_code_e {
	RC_OK,		/* Decoded successfully */
	RC_WMORE,	/* More data expected, call again */
	RC_FAIL		/* Failure to decode data */
  };
typedef struct ber_dec_rval_s {
	enum ber_dec_rval_code_e code;	/* Result code */
	size_t consumed;		/* Number of bytes consumed */
} ber_dec_rval_t;

/*
 * The BER decoder of any type.
 * This function may be invoked directly from the application.
 */
ber_dec_rval_t ber_decode(struct asn_codec_ctx_s *opt_codec_ctx,
	struct asn_TYPE_descriptor_s *type_descriptor,
	void **struct_ptr,	/* Pointer to a target structure's pointer */
	void *buffer,		/* Data to be decoded */
	size_t size		/* Size of that buffer */
	);

/*
 * Type of generic function which decodes the byte stream into the structure.
 */
typedef ber_dec_rval_t (ber_type_decoder_f)(
		struct asn_codec_ctx_s *opt_codec_ctx,
		struct asn_TYPE_descriptor_s *type_descriptor,
		void **type_structure, void *buf_ptr, size_t size,
		int tag_mode);

/*******************************
 * INTERNALLY USEFUL FUNCTIONS *
 *******************************/

/*
 * Check that all tags correspond to the type definition (as given in head).
 * On return, last_length would contain either a non-negative length of the
 * value part of the last TLV, or the negative number of expected
 * "end of content" sequences. The number may only be negative if the
 * head->last_tag_form is non-zero.
 */
ber_dec_rval_t ber_check_tags(
		struct asn_codec_ctx_s *opt_codec_ctx,	/* optional context */
		struct asn_TYPE_descriptor_s *type_dsc,
		asn_struct_ctx_t *opt_ctx,	/* saved decoding context */
		void *ptr, size_t size,
		int tag_mode,		/* {-1,0,1}: IMPLICIT, no, EXPLICIT */
		int last_tag_form,	/* {-1,0:1}: any, primitive, constr */
		ber_tlv_len_t *last_length,
		int *opt_tlv_form	/* optional tag form */
	);

#endif	/* _BER_DECODER_H_ */
