#include "asn1c_internal.h"
#include "asn1c_C.h"

asn1_language_map_t asn1_lang_map[AMT_EXPR_META_MAX][ASN_EXPR_TYPE_MAX];

int
asn1c_with_language(asn1c_target_language_e lang) {
	asn1_language_map_t *lptr;
	int lsize;
	if(lang != ASN1C_LANGUAGE_C) {
		errno = EINVAL;
		return -1;
	}

	lptr = asn1_lang_C;
	lsize = sizeof(asn1_lang_C)/sizeof(asn1_lang_C[0]);

	memset(asn1_lang_map, 0, sizeof(asn1_lang_map));

	for(; lsize && lptr->expr_match; lsize--, lptr++) {
		assert(lptr->meta_match > 0);
		assert(lptr->meta_match < AMT_EXPR_META_MAX);
		assert(lptr->expr_match > 0);
		assert(lptr->expr_match < ASN_EXPR_TYPE_MAX);

		asn1_lang_map[lptr->meta_match][lptr->expr_match]
			= *lptr;
	}

	return 0;
}

