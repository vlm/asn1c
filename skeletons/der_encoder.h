/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_DER_ENCODER_H_
#define	_DER_ENCODER_H_

#include <constr_TYPE.h>

struct asn1_TYPE_descriptor_s;	/* Forward declaration */

/*
 * Type of the return value of the der_encode function.
 */
typedef struct der_enc_rval_s {
	/*
	 * Number of bytes encoded.
	 * -1 indicates failure to encode the structure.
	 * In this case, the members below this one are meaningful.
	 */
	ssize_t encoded;

	/*
	 * Members meaningful when (encoded == -1), for post-mortem analysis.
	 */

	/* Type which cannot be encoded */
	struct asn1_TYPE_descriptor_s *failed_type;

	/* Pointer to the structure of that type */
	void *structure_ptr;
} der_enc_rval_t;


/*
 * The DER encoder of any type. May be invoked by the application.
 */
der_enc_rval_t der_encode(struct asn1_TYPE_descriptor_s *type_descriptor,
		void *struct_ptr,	/* Structure to be encoded */
		asn_app_consume_bytes_f *consume_bytes_cb,
		void *app_key		/* Arbitrary callback argument */
	);

/*
 * Type of the generic DER encoder.
 */
typedef der_enc_rval_t (der_type_encoder_f)(
		struct asn1_TYPE_descriptor_s *type_descriptor,
		void *struct_ptr,	/* Structure to be encoded */
		int tag_mode,		/* {-1,0,1}: IMPLICIT, no, EXPLICIT */
		ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *consume_bytes_cb,	/* Callback */
		void *app_key		/* Arbitrary callback argument */
	);


/*******************************
 * INTERNALLY USEFUL FUNCTIONS *
 *******************************/

/*
 * Write out leading TL[v] sequence according to the type definition.
 */
ssize_t der_write_tags(
		struct asn1_TYPE_descriptor_s *type_descriptor,
		size_t struct_length,
		int tag_mode,		/* {-1,0,1}: IMPLICIT, no, EXPLICIT */
		ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *consume_bytes_cb,
		void *app_key
	);

#endif	/* _DER_ENCODER_H_ */
