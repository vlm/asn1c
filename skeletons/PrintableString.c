/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <PrintableString.h>

/*
 * PrintableString basic type description.
 */
static ber_tlv_tag_t asn_DEF_PrintableString_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (19 << 2)),	/* [UNIVERSAL 19] IMPLICIT ...*/
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2))	/* ... OCTET STRING */
};
asn_TYPE_descriptor_t asn_DEF_PrintableString = {
	"PrintableString",
	"PrintableString",
	OCTET_STRING_free,
	OCTET_STRING_print_utf8,	/* ASCII subset */
	PrintableString_constraint,
	OCTET_STRING_decode_ber,      /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,
	OCTET_STRING_decode_xer_utf8,
	OCTET_STRING_encode_xer_utf8,
	0, 0,
	0, /* Use generic outmost tag fetcher */
	asn_DEF_PrintableString_tags,
	sizeof(asn_DEF_PrintableString_tags)
	  / sizeof(asn_DEF_PrintableString_tags[0]) - 1,
	asn_DEF_PrintableString_tags,
	sizeof(asn_DEF_PrintableString_tags)
	  / sizeof(asn_DEF_PrintableString_tags[0]),
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	0	/* No specifics */
};


/*
 * ASN.1:1984 (X.409)
 */
static int _PrintableString_alphabet[256] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 	/*               ' */
0x41, 0x42, 0x00, 0x43, 0x44, 0x45, 0x46, 0x47, 	/* ( )   + , - . / */
0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 	/* 0 1 2 3 4 5 6 7 */
0x3d, 0x3e, 0x48, 0x00, 0x00, 0x49, 0x00, 0x4a, 	/* 8 9 :     =   ? */
0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 	/*   A B C D E F G */
0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 	/* H I J K L M N O */
0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 	/* P Q R S T U V W */
0x18, 0x19, 0x1a, 0x00, 0x00, 0x00, 0x00, 0x00, 	/* X Y Z           */
0x00, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 	/*   a b c d e f g */
0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 	/* h i j k l m n o */
0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 	/* p q r s t u v w */
0x32, 0x33, 0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 	/* x y z           */
};

int
PrintableString_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
		asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const PrintableString_t *st = (const PrintableString_t *)sptr;

	if(st && st->buf) {
		uint8_t *buf = st->buf;
		uint8_t *end = buf + st->size;

		/*
		 * Check the alphabet of the PrintableString.
		 * ASN.1:1984 (X.409)
		 */
		for(; buf < end; buf++) {
			if(!_PrintableString_alphabet[*buf]) {
				_ASN_CTFAIL(app_key, td,
					"%s: value byte %ld (%d) "
					"not in PrintableString alphabet "
					"(%s:%d)",
					td->name,
					(long)((buf - st->buf) + 1),
					*buf,
					__FILE__, __LINE__);
				return -1;
			}
		}
	} else {
		_ASN_CTFAIL(app_key, td,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}

	return 0;
}
