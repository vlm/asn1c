/*
 * Copyright (c) 2004-2017 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * This type differs from the standard ENUMERATED in that it is modelled using
 * the fixed machine type (long, int, short), so it can hold only values of
 * limited length. There is no type (i.e., NativeEnumerated_t, any integer type
 * will do).
 * This type may be used when integer range is limited by subtype constraints.
 */
#ifndef	_NativeEnumerated_H_
#define	_NativeEnumerated_H_

#include <NativeInteger.h>
#include <limits.h>	/* For LONG_MAX */

#ifdef __cplusplus
extern "C" {
#endif

extern asn_TYPE_descriptor_t asn_DEF_NativeEnumerated;
extern asn_TYPE_operation_t asn_OP_NativeEnumerated;

/*
 * UPER forward compatibility: an extensible ENUMERATED value added by a
 * newer version of the type is carried on the wire (X.691 #14) only as its
 * extension index -- the true abstract value is unknowable to an older
 * decoder (X.680 #20.1 NOTE: enumeration values are ordered but not
 * necessarily contiguous). X.680 #6 forbids failing on such a value, yet a
 * plain long has no out-of-band way to flag "unknown". Following a commercial
 * ASN.1 toolchain (the project's interoperability reference, which stores
 * INT_MAX - index), the UPER decoder stores the wire index enciphered as
 * LONG_MAX - index, i.e.
 * in the reserved region [LONG_MAX - 65535, LONG_MAX] (uper_get_nsnnwn caps
 * the index at two length octets, so 65535 is its widest possible value).
 *
 * Contract for such a stored value:
 *   - The application MUST NOT interpret it as a meaningful enumeration
 *     value; it is only a placeholder for "unknown extension index N".
 *   - It may be relayed as-is: NativeEnumerated_encode_uper recognises the
 *     region and re-emits the identical index, so an unknown value received
 *     from one peer can be forwarded byte-for-byte to another, provided the
 *     SAME PER transfer syntax is used (X.680 #6/#7.1). The extension index
 *     is version-stable (X.680 #20.4 forces additions to ascend), so relay
 *     stays correct across schema versions.
 *   - Transcoding it to a different transfer syntax (DER/OER/XER) is
 *     meaningless -- those codecs carry the abstract value, not the index --
 *     and rightly fails (map miss) or, for codecs without a map check
 *     (DER/OER integer), emits this conspicuous near-LONG_MAX garbage rather
 *     than a plausible-looking enumeration value.
 */
#define ASN_NATIVE_ENUMERATED_UNKNOWN_EXT_BASE  (LONG_MAX - 65535)
#define ASN_NATIVE_ENUMERATED_IS_UNKNOWN_EXT(v) \
	((v) >= ASN_NATIVE_ENUMERATED_UNKNOWN_EXT_BASE)

xer_type_encoder_f NativeEnumerated_encode_xer;
oer_type_decoder_f NativeEnumerated_decode_oer;
oer_type_encoder_f NativeEnumerated_encode_oer;
per_type_decoder_f NativeEnumerated_decode_uper;
per_type_encoder_f NativeEnumerated_encode_uper;

#define NativeEnumerated_free       NativeInteger_free
#define NativeEnumerated_print      NativeInteger_print
#define NativeEnumerated_compare    NativeInteger_compare
#define NativeEnumerated_random_fill NativeInteger_random_fill
#define NativeEnumerated_constraint asn_generic_no_constraint
#define NativeEnumerated_decode_ber NativeInteger_decode_ber
#define NativeEnumerated_encode_der NativeInteger_encode_der
#define NativeEnumerated_decode_xer NativeInteger_decode_xer

#ifdef __cplusplus
}
#endif

#endif	/* _NativeEnumerated_H_ */
