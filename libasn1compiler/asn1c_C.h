#ifndef	ASN1_COMPILER_LANGUAGE_C_H
#define	ASN1_COMPILER_LANGUAGE_C_H

#include "asn1c_lang.h"

int asn1c_lang_C_type_REFERENCE(arg_t *);
int asn1c_lang_C_type_EXTENSIBLE(arg_t *);

int asn1c_lang_C_type_SEQUENCE(arg_t *);
int asn1c_lang_C_type_SET(arg_t *);
int asn1c_lang_C_type_SEx_OF(arg_t *);	/* SET OF or  SEQUENCE OF */
int asn1c_lang_C_type_CHOICE(arg_t *);

int asn1c_lang_C_type_common_INTEGER(arg_t *);
int asn1c_lang_C_type_BIT_STRING(arg_t *);
int asn1c_lang_C_type_REAL(arg_t *);
int asn1c_lang_C_type_SIMPLE_TYPE(arg_t *);

static asn1_language_map_t asn1_lang_C[] __attribute__ ((unused)) = {
	{ AMT_TYPE, A1TC_REFERENCE,	asn1c_lang_C_type_REFERENCE },
	{ AMT_TYPEREF, A1TC_REFERENCE,	asn1c_lang_C_type_REFERENCE },
	{ AMT_TYPE, A1TC_EXTENSIBLE,	asn1c_lang_C_type_EXTENSIBLE },
	/*
	 * Constructed types
	 */
	{ AMT_TYPE, ASN_CONSTR_SEQUENCE,	asn1c_lang_C_type_SEQUENCE },
	{ AMT_TYPE, ASN_CONSTR_SEQUENCE_OF,	asn1c_lang_C_type_SEx_OF, },
	{ AMT_TYPEREF, ASN_CONSTR_SEQUENCE_OF,	asn1c_lang_C_type_SEx_OF },
	{ AMT_TYPE, ASN_CONSTR_SET,		asn1c_lang_C_type_SET },
	{ AMT_TYPE, ASN_CONSTR_SET_OF,		asn1c_lang_C_type_SEx_OF },
	{ AMT_TYPEREF, ASN_CONSTR_SET_OF,	asn1c_lang_C_type_SEx_OF },
	{ AMT_TYPE, ASN_CONSTR_CHOICE,		asn1c_lang_C_type_CHOICE },
	/*
	 * ANY type (deprecated)
	 */
        { AMT_TYPE, ASN_TYPE_ANY,	asn1c_lang_C_type_SIMPLE_TYPE },
	/*
	 * Basic types
	 */
	{ AMT_TYPE, ASN_BASIC_BOOLEAN,	asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_BASIC_NULL,	asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_BASIC_INTEGER,	asn1c_lang_C_type_common_INTEGER },
	{ AMT_TYPE, ASN_BASIC_REAL,	asn1c_lang_C_type_REAL },
	{ AMT_TYPE, ASN_BASIC_ENUMERATED,  asn1c_lang_C_type_common_INTEGER },
	{ AMT_TYPE, ASN_BASIC_BIT_STRING,	asn1c_lang_C_type_BIT_STRING },
	{ AMT_TYPE, ASN_BASIC_OCTET_STRING,	asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_BASIC_OBJECT_IDENTIFIER,asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_BASIC_RELATIVE_OID,	asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_BASIC_CHARACTER_STRING,	asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_BASIC_UTCTime,		asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_BASIC_GeneralizedTime,	asn1c_lang_C_type_SIMPLE_TYPE },
	/*
	 * String types
	 */
	{ AMT_TYPE, ASN_STRING_BMPString,     asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_GeneralString, asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_GraphicString, asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_IA5String,     asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_ISO646String,  asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_NumericString, asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_PrintableString,asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_TeletexString, asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_T61String,     asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_UniversalString,asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_UTF8String,    asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_VideotexString,asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_VisibleString, asn1c_lang_C_type_SIMPLE_TYPE },
	{ AMT_TYPE, ASN_STRING_ObjectDescriptor,asn1c_lang_C_type_SIMPLE_TYPE },
	{ 0, 0, 0 }
};


#endif	/* ASN1_COMPILER_LANGUAGE_C_H */
