/*-
 * Copyright (c) 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_XER_DECODER_H_
#define	_XER_DECODER_H_

#include <asn_application.h>

struct asn_TYPE_descriptor_s;	/* Forward declaration */

/*
 * The XER decoder of any type. May be invoked by the application.
 */
asn_dec_rval_t xer_decode(struct asn_codec_ctx_s *opt_codec_ctx,
	struct asn_TYPE_descriptor_s *type_descriptor,
	void **struct_ptr,	/* Pointer to a target structure's pointer */
	void *buffer,		/* Data to be decoded */
	size_t size		/* Size of that buffer */
	);

/*
 * Type of the type-specific XER decoder function.
 */
typedef asn_dec_rval_t (xer_type_decoder_f)(asn_codec_ctx_t *opt_codec_ctx,
		struct asn_TYPE_descriptor_s *type_descriptor,
		void **struct_ptr,
		const char *opt_mname,	/* Member name */
		void *buf_ptr, size_t size
	);

/*******************************
 * INTERNALLY USEFUL FUNCTIONS *
 *******************************/

/*
 * Generalized function for decoding the primitive values.
 * Used by more specialized functions, such as OCTET_STRING_decode_xer_utf8
 * and others. This function should not be used by applications, as its API
 * is subject to changes.
 */
asn_dec_rval_t xer_decode_general(asn_codec_ctx_t *opt_codec_ctx,
	asn_struct_ctx_t *ctx,	/* Type decoder context */
	void *struct_ptr,	/* The structure must be already allocated */
	const char *xml_tag,	/* Expected XML tag name */
	void *buf_ptr, size_t size,
	int (*opt_unexpected_tag_decoder)
		(void *struct_ptr, void *chunk_buf, size_t chunk_size),
	ssize_t (*body_receiver)
		(void *struct_ptr, void *chunk_buf, size_t chunk_size,
			int have_more)
	);


/*
 * Fetch the next XER (XML) token from the stream.
 * The function returns the number of bytes occupied by the chunk type,
 * returned in the _ch_type. The _ch_type is only set (and valid) when
 * the return value is greater than 0.
 */
  typedef enum pxer_chunk_type {
	PXER_TAG,	/* Complete XER tag */
	PXER_TEXT,	/* Plain text between XER tags */
	PXER_COMMENT,	/* A comment, may be part of */
  } pxer_chunk_type_e;
ssize_t xer_next_token(int *stateContext, void *buffer, size_t size,
	pxer_chunk_type_e *_ch_type);

/*
 * This function checks the buffer against the tag name is expected to occur.
 */
  typedef enum xer_check_tag {
	XCT_BROKEN,	/* The tag is broken */
	XCT_UNEXPECTED,	/* The tag is fine, but unexpected */
	XCT_OPENING,	/* This is the opening <tag> */
	XCT_CLOSING,	/* This is the closing </tag> */
	XCT_BOTH,	/* This is the opening and closing tag <tag/> */
  } xer_check_tag_e;
xer_check_tag_e xer_check_tag(const void *buf_ptr, int size,
		const char *need_tag);

#endif	/* _XER_DECODER_H_ */
