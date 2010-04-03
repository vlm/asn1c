/*-
 * Copyright (c) 2010 Santiago Carot-Nemesio <sancane@gmail.com>
 * Copyright (c) 2010 Jose Antonio Santos-Cadenas <santoscadenas@gmail.com>
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <errno.h>

asn_enc_rval_t mder_encode(struct asn_TYPE_descriptor_s *type_descriptor,
		void *struct_ptr, asn_app_consume_bytes_f *consume_bytes_cb,
		void *app_key)
{
	/*
	 * Invoke type-specific encoder.
	 */
	return type_descriptor->mder_encoder(type_descriptor,
		struct_ptr,	/* Pointer to the destination structure */
		0,		/* No specifics constraints */
		consume_bytes_cb, app_key);
}

/*
* Argument type and callback necessary for mder_encode_to_buffer().
*/
typedef struct enc_to_buf_arg {
	void *buffer;
	size_t left;
} enc_to_buf_arg;

static int encode_to_buffer_cb(const void *buffer, size_t size, void *key) {
	enc_to_buf_arg *arg = (enc_to_buf_arg *)key;

	if(arg->left < size)
		return -1;	/* Data exceeds the available buffer size */

	memcpy(arg->buffer, buffer, size);
	arg->buffer = ((char *)arg->buffer) + size;
	arg->left -= size;

	return 0;
}

asn_enc_rval_t mder_encode_to_buffer(
		struct asn_TYPE_descriptor_s *type_descriptor, void *struct_ptr,
		void *buffer, size_t buffer_size)
{
	enc_to_buf_arg arg;
	asn_enc_rval_t ec;

	arg.buffer = buffer;
	arg.left = buffer_size;

	ec = type_descriptor->mder_encoder(type_descriptor,
		struct_ptr,	/* Pointer to the destination structure */
		0, 0, encode_to_buffer_cb, &arg);
	if(ec.encoded != -1) {
		assert(ec.encoded == (ssize_t)(buffer_size - arg.left));
		/* Return the encoded contents size */
	}
	return ec;
}
