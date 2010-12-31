/*-
 * Copyright (c) 2010 Santiago Carot-Nemesio <sancane@gmail.com>
 * Copyright (c) 2010 Jose Antonio Santos-Cadenas <santoscadenas@gmail.com>
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <errno.h>

static asn_enc_rval_t
mder_encode_internal(asn_TYPE_descriptor_t *td, void *sptr,
				asn_app_consume_bytes_f *cb, void *app_key) {
	if(!td || !td->mder_encoder)
		_ASN_ENCODE_FAILED;	/* MDER is not compiled in */

	/*
	 * Invoke type-specific encoder.
	 */
	return td->mder_encoder(td,
		sptr,		/* Pointer to the destination structure */
		0,		/* No specifics constraints */
		cb, app_key);
}

asn_enc_rval_t
mder_encode(struct asn_TYPE_descriptor_s *td, void *sptr,
				asn_app_consume_bytes_f *cb, void *app_key) {
	return mder_encode_internal(td, sptr, cb, app_key);
}

/*
* Argument type and callback necessary for mder_encode_to_buffer().
*/
typedef struct enc_to_buf_arg {
	void *buffer;
	size_t left;
} enc_to_buf_arg;

static int
encode_to_buffer_cb(const void *buffer, size_t size, void *key) {
	enc_to_buf_arg *arg = (enc_to_buf_arg *)key;

	if(arg->left < size)
		return -1;	/* Data exceeds the available buffer size */

	memcpy(arg->buffer, buffer, size);
	arg->buffer = ((char *)arg->buffer) + size;
	arg->left -= size;

	return 0;
}

asn_enc_rval_t
mder_encode_to_buffer(struct asn_TYPE_descriptor_s *td, void *sptr,
					void *buffer, size_t buffer_size)
{
	enc_to_buf_arg arg;

	arg.buffer = buffer;
	arg.left = buffer_size;

	return mder_encode_internal(td,
		sptr,	/* Pointer to the destination structure */
		encode_to_buffer_cb, &arg);
}

asn_enc_rval_t
NON_SUP_encode_mder(struct asn_TYPE_descriptor_s *td, void *sptr,
						asn_mder_contraints_t constr,
						asn_app_consume_bytes_f *cb,
						void *app_key) {
	_ASN_ENCODE_FAILED;
}
