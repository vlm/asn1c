/*-
 * Copyright (c) 2004, 2007 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * Read the NativeInteger.h for the explanation wrt. differences between
 * INTEGER and NativeInteger.
 * Basically, both are decoders and encoders of ASN.1 INTEGER type, but this
 * implementation deals with the standard (machine-specific) representation
 * of them instead of using the platform-independent buffer.
 */
#include <asn_internal.h>
#include <NativeEnumerated.h>

/*
 * NativeEnumerated basic type description.
 */
static const ber_tlv_tag_t asn_DEF_NativeEnumerated_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_operation_t asn_OP_NativeEnumerated = {
	NativeInteger_free,
	NativeInteger_print,
	NativeInteger_compare,
	NativeInteger_decode_ber,
	NativeInteger_encode_der,
	NativeInteger_decode_xer,
	NativeEnumerated_encode_xer,
#ifdef	ASN_DISABLE_OER_SUPPORT
	0,
	0,
#else
	NativeEnumerated_decode_oer,
	NativeEnumerated_encode_oer,
#endif  /* ASN_DISABLE_OER_SUPPORT */
#ifdef	ASN_DISABLE_PER_SUPPORT
	0,
	0,
#else
	NativeEnumerated_decode_uper,
	NativeEnumerated_encode_uper,
#endif	/* ASN_DISABLE_PER_SUPPORT */
	NativeEnumerated_random_fill,
	0	/* Use generic outmost tag fetcher */
};
asn_TYPE_descriptor_t asn_DEF_NativeEnumerated = {
	"ENUMERATED",			/* The ASN.1 type is still ENUMERATED */
	"ENUMERATED",
	&asn_OP_NativeEnumerated,
	asn_DEF_NativeEnumerated_tags,
	sizeof(asn_DEF_NativeEnumerated_tags) / sizeof(asn_DEF_NativeEnumerated_tags[0]),
	asn_DEF_NativeEnumerated_tags,	/* Same as above */
	sizeof(asn_DEF_NativeEnumerated_tags) / sizeof(asn_DEF_NativeEnumerated_tags[0]),
	{ 0, 0, asn_generic_no_constraint },
	0, 0,	/* No members */
	0	/* No specifics */
};

asn_enc_rval_t
NativeEnumerated_encode_xer(const asn_TYPE_descriptor_t *td, const void *sptr,
                            int ilevel, enum xer_encoder_flags_e flags,
                            asn_app_consume_bytes_f *cb, void *app_key) {
    const asn_INTEGER_specifics_t *specs =
        (const asn_INTEGER_specifics_t *)td->specifics;
    asn_enc_rval_t er;
    const long *native = (const long *)sptr;
    const asn_INTEGER_enum_map_t *el;

    (void)ilevel;
    (void)flags;

    if(!native) ASN__ENCODE_FAILED;

    el = INTEGER_map_value2enum(specs, *native);
    if(el) {
        er.encoded =
            asn__format_to_callback(cb, app_key, "<%s/>", el->enum_name);
        if(er.encoded < 0) ASN__ENCODE_FAILED;
        ASN__ENCODED_OK(er);
    } else {
        ASN_DEBUG(
            "ASN.1 forbids dealing with "
            "unknown value of ENUMERATED type");
        ASN__ENCODE_FAILED;
    }
}

asn_dec_rval_t
NativeEnumerated_decode_uper(const asn_codec_ctx_t *opt_codec_ctx,
                             const asn_TYPE_descriptor_t *td,
                             const asn_per_constraints_t *constraints,
                             void **sptr, asn_per_data_t *pd) {
    const asn_INTEGER_specifics_t *specs = td->specifics;
    asn_dec_rval_t rval = { RC_OK, 0 };
	long *native = (long *)*sptr;
	const asn_per_constraint_t *ct;
	long value;

	(void)opt_codec_ctx;

	if(constraints) ct = &constraints->value;
	else if(td->encoding_constraints.per_constraints)
		ct = &td->encoding_constraints.per_constraints->value;
	else ASN__DECODE_FAILED;	/* Mandatory! */
	if(!specs) ASN__DECODE_FAILED;

	if(!native) {
		native = (long *)(*sptr = CALLOC(1, sizeof(*native)));
		if(!native) ASN__DECODE_FAILED;
	}

	ASN_DEBUG("Decoding %s as NativeEnumerated", td->name);

	if(ct->flags & APC_EXTENSIBLE) {
		int inext = per_get_few_bits(pd, 1);
		if(inext < 0) ASN__DECODE_STARVED;
		if(inext) ct = 0;
	}

	if(ct && ct->range_bits >= 0) {
		value = per_get_few_bits(pd, ct->range_bits);
		if(value < 0) ASN__DECODE_STARVED;
		if(value >= (specs->extension
			? specs->extension - 1 : specs->map_count))
			ASN__DECODE_FAILED;
	} else {
		if(!specs->extension)
			ASN__DECODE_FAILED;
		/*
		 * X.691, #10.6: normally small non-negative whole number;
		 */
		value = uper_get_nsnnwn(pd);
		if(value < 0) ASN__DECODE_STARVED;
		if(value + specs->extension - 1 >= specs->map_count) {
			/*
			 * Unknown extension value: the peer used an enumeration value
			 * added in a newer version of the type. Such a value is carried
			 * (X.691 #14) only as its extension index -- there is no open
			 * type to skip and the index has already been consumed. X.680 #6
			 * forbids treating this as an error, so accept it: an enclosing
			 * type can then keep decoding its following fields (forward
			 * compatibility).
			 *
			 * The true abstract value is unknowable to this older decoder,
			 * and a plain long has no out-of-band way to flag "unknown". So,
			 * like a commercial ASN.1 toolchain (the project's interoperability
			 * reference, which stores INT_MAX - index), store the wire index enciphered as
			 * LONG_MAX - index -- `value` still holds the raw index here.
			 * NativeEnumerated_encode_uper recognises this reserved region
			 * and re-emits the identical index, so the value can be relayed
			 * byte-for-byte under the same PER transfer syntax. See the
			 * contract in NativeEnumerated.h.
			 *
			 * uper_get_nsnnwn caps the index at two length octets (<=65535);
			 * guard the reserved region against anything wider.
			 */
			if(value > 65535)
				ASN__DECODE_FAILED;
#ifdef ASN_REJECT_UNKNOWN_EXTENSIONS
			/*
			 * Strict mode: restore the pre-fix behavior of cleanly failing
			 * on an unknown extension value instead of storing it as
			 * LONG_MAX - index for later relay. Escape hatch for callers
			 * not yet prepared to see values outside the known enumeration
			 * (see ASN_REJECT_UNKNOWN_EXTENSIONS in asn_internal.h).
			 */
			ASN__DECODE_FAILED;
#else
			*native = LONG_MAX - value;
			ASN_DEBUG("Decoded %s = unknown extension index %ld"
				" (stored as LONG_MAX-%ld)", td->name, value, value);
			return rval;
#endif	/* ASN_REJECT_UNKNOWN_EXTENSIONS */
		}
		value += specs->extension - 1;
	}

	*native = specs->value2enum[value].nat_value;
	ASN_DEBUG("Decoded %s = %ld", td->name, *native);

	return rval;
}

static int
NativeEnumerated__compar_value2enum(const void *ap, const void *bp) {
	const asn_INTEGER_enum_map_t *a = ap;
	const asn_INTEGER_enum_map_t *b = bp;
	if(a->nat_value == b->nat_value)
		return 0;
	if(a->nat_value < b->nat_value)
		return -1;
	return 1;
}

asn_enc_rval_t
NativeEnumerated_encode_uper(const asn_TYPE_descriptor_t *td,
                             const asn_per_constraints_t *constraints,
                             const void *sptr, asn_per_outp_t *po) {
    const asn_INTEGER_specifics_t *specs =
        (const asn_INTEGER_specifics_t *)td->specifics;
    asn_enc_rval_t er;
	long native, value;
	const asn_per_constraint_t *ct;
	int inext = 0;
	asn_INTEGER_enum_map_t key;
	const asn_INTEGER_enum_map_t *kf;

	if(!sptr) ASN__ENCODE_FAILED;
	if(!specs) ASN__ENCODE_FAILED;

	if(constraints) ct = &constraints->value;
	else if(td->encoding_constraints.per_constraints)
		ct = &td->encoding_constraints.per_constraints->value;
	else ASN__ENCODE_FAILED;	/* Mandatory! */

	ASN_DEBUG("Encoding %s as NativeEnumerated", td->name);

	er.encoded = 0;

	native = *(const long *)sptr;

	key.nat_value = native;
	if(specs->extension) {
		/*
		 * value2enum is laid out as two independently-sorted
		 * segments: root members [0, extension-1) and extension
		 * additions [extension-1, map_count), each sorted by
		 * nat_value on its own (see asn1c_lang_C_type_common_INTEGER
		 * in the compiler). A single bsearch() over the whole array
		 * requires the entire array to be monotonically sorted,
		 * which no longer holds when an extension addition's value
		 * is numerically smaller than a root value (X.691 #14.1
		 * indexes root and extension additions independently of
		 * each other's numeric values). Search each segment in turn.
		 */
		int root_count = specs->extension - 1;
		kf = bsearch(&key, specs->value2enum, root_count,
			sizeof(key), NativeEnumerated__compar_value2enum);
		if(!kf)
			kf = bsearch(&key, specs->value2enum + root_count,
				specs->map_count - root_count,
				sizeof(key), NativeEnumerated__compar_value2enum);
	} else {
		kf = bsearch(&key, specs->value2enum, specs->map_count,
			sizeof(key), NativeEnumerated__compar_value2enum);
	}
	if(!kf) {
		/*
		 * No known enumeration maps to this value. If it is an unknown
		 * extension value that a previous UPER decode stored enciphered as
		 * LONG_MAX - wire_index (see NativeEnumerated.h), and this
		 * enumeration is extensible, relay it: recover the index and
		 * re-emit it exactly as received (extension bit + nsnnwn index).
		 * This mirrors the reference toolchain and yields a byte-for-byte
		 * identical relay under the same PER transfer syntax. A value the
		 * application fabricated inside the reserved region is passed
		 * through as an index too (garbage in, garbage out, as with the
		 * reference toolchain); a
		 * reserved-region value handed to a non-extensible enumeration
		 * still fails below.
		 *
		 * This relay branch is intentionally left enabled even when
		 * ASN_REJECT_UNKNOWN_EXTENSIONS is defined: with that macro set,
		 * NativeEnumerated_decode_uper() never produces a LONG_MAX-index
		 * value (it fails cleanly instead), so this code simply never
		 * triggers in strict builds. It is not itself part of the "unknown
		 * extension" decode contract the macro governs.
		 */
		if((ct->flags & APC_EXTENSIBLE) && specs->extension
		&& ASN_NATIVE_ENUMERATED_IS_UNKNOWN_EXT(native)) {
			long ext_index = LONG_MAX - native;
			ASN_DEBUG("Relaying %s unknown extension index %ld",
				td->name, ext_index);
			if(per_put_few_bits(po, 1, 1))	/* extension present bit */
				ASN__ENCODE_FAILED;
			if(uper_put_nsnnwn(po, ext_index))
				ASN__ENCODE_FAILED;
			ASN__ENCODED_OK(er);
		}
		ASN_DEBUG("No element corresponds to %ld", native);
		ASN__ENCODE_FAILED;
	}
	value = kf - specs->value2enum;

	if(ct->range_bits >= 0) {
		int cmpWith = specs->extension
				? specs->extension - 1 : specs->map_count;
		if(value >= cmpWith)
			inext = 1;
	}
	if(ct->flags & APC_EXTENSIBLE) {
		if(per_put_few_bits(po, inext, 1))
			ASN__ENCODE_FAILED;
		if(inext) ct = 0;
	} else if(inext) {
		ASN__ENCODE_FAILED;
	}

	if(ct && ct->range_bits >= 0) {
		if(per_put_few_bits(po, value, ct->range_bits))
			ASN__ENCODE_FAILED;
		ASN__ENCODED_OK(er);
	}

	if(!specs->extension)
		ASN__ENCODE_FAILED;

	/*
	 * X.691, #10.6: normally small non-negative whole number;
	 */
	ASN_DEBUG("value = %ld, ext = %d, inext = %d, res = %ld",
		value, specs->extension, inext,
		value - (inext ? (specs->extension - 1) : 0));
	if(uper_put_nsnnwn(po, value - (inext ? (specs->extension - 1) : 0)))
		ASN__ENCODE_FAILED;

	ASN__ENCODED_OK(er);
}

