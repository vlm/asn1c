#ifndef	ASN1_COMPILER_LANGUAGE_H
#define	ASN1_COMPILER_LANGUAGE_H

struct arg_s;

typedef struct asn1_language_map_s {
	asn1p_expr_meta_e meta_match;		/* meta_type */
	asn1p_expr_type_e expr_match;		/* expr_type */
	/*
	 * A callback that would create a language-specific type declaration.
	 */
	int (*type_cb)(struct arg_s *arg);
} asn1_language_map_t;


extern asn1_language_map_t asn1_lang_map[AMT_EXPR_META_MAX][ASN_EXPR_TYPE_MAX];


typedef enum asn1c_target_language {
	ASN1C_LANGUAGE_C,
} asn1c_target_language_e;

/*
 * Initialize the compiler to generate specified target language.
 */
int asn1c_with_language(asn1c_target_language_e lang);

#endif	/* ASN1_COMPILER_LANGUAGE_H */
