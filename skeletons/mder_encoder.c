/*-
 * Copyright (c) 2010 Santiago Carot-Nemesio <sancane@gmail.com>.
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
		0, 0,
		consume_bytes_cb, app_key);
}

asn_enc_rval_t mder_encode_to_buffer(
		struct asn_TYPE_descriptor_s *type_descriptor, void *struct_ptr,
		void *buffer, size_t buffer_size)
{
	asn_enc_rval_t t;
	return t;
}
