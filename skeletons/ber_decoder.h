/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_BER_DECODER_H_
#define	_BER_DECODER_H_

#include <constr_TYPE.h>

struct asn1_TYPE_descriptor_s;	/* Forward declaration */

/*
 * This structure describes the return value common across the
 * various BER decoders.
 * 
 * Please note that the number of consumed bytes is ALWAYS meaningful,
 * even if code!=RC_OK. This is so to indicate the number of successfully
 * decoded bytes, hence provide a possibility, to fail with more diagnostics
 * (i.e., print the offending remainder of the buffer).
 */
typedef struct ber_dec_rval_s {
	enum {
		RC_OK,		/* Decoded successfully */
		RC_WMORE,	/* More data expected, call again */
		RC_FAIL,	/* Failure to decode data */
	} code;

	size_t consumed;	/* Number of bytes consumed */
} ber_dec_rval_t;

/*
 * A context for decoding BER across buffer boundaries.
 */
typedef struct ber_dec_ctx_s {
	int phase;	/* Decoding phase */
	int step;	/* Elementary step of a phase */
	ber_tlv_len_t left;	/* Number of bytes left, -1 for indefinite */
	void *ptr;	/* Decoder-specific stuff */
} ber_dec_ctx_t;

/*
 * The BER decoder of any type.
 * This function may be invoked directly from the application.
 */
ber_dec_rval_t ber_decode(struct asn1_TYPE_descriptor_s *type_descriptor,
	void **struct_ptr,	/* Pointer to a target structure's pointer */
	void *buffer,		/* Data to be decoded */
	size_t size		/* Size of that buffer */
	);

/*
 * Type of generic function which decodes the byte stream into the structure.
 */
typedef ber_dec_rval_t (ber_type_decoder_f)(
		struct asn1_TYPE_descriptor_s *type_descriptor,
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
ber_dec_rval_t ber_check_tags(struct asn1_TYPE_descriptor_s *type_dsc,
		ber_dec_ctx_t *ctx,	/* saved context */
		void *ptr, size_t size,
		int tag_mode,		/* {-1,0,1}: IMPLICIT, no, EXPLICIT */
		ber_tlv_len_t *last_length,
		int *opt_tlv_form);

#endif	/* _BER_DECODER_H_ */
