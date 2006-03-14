#ifndef	_ASN1FIX_CLASS_WITH_SYNTAX_H_
#define	_ASN1FIX_CLASS_WITH_SYNTAX_H_

/*
 * This structure describes the "WITH SYNTAX" clause of a CLASS.
 */
typedef struct asn1f_cws_syntax_list_s {
	struct asn1f_cws_spec **cwspecs;
	int cwcount;	/* Number of pieces of CWS information */
} asn1f_cws_syntax_list_t;

struct asn1f_cws_spec {
	enum {
		CWS_LITERAL,
		CWS_FIELD,
		CWS_OPTIONALGROUP
	} type;
	union {
		char *token;	/* For CWSB_LITERAL & CWSB_FIELD */
		asn1f_cws_syntax_list_t *syntax;
	} content;
};

#endif	/* _ASN1FIX_CLASS_WITH_SYNTAX_H_ */
