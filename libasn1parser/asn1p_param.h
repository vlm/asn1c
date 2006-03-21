/*
 * Structures and prototypes related to parameterization
 */
#ifndef	ASN1_PARSER_PARAMETERIZATION_H
#define	ASN1_PARSER_PARAMETERIZATION_H

struct asn1p_expr_s;	/* Forward declaration */

typedef struct asn1p_paramlist_s {
	struct asn1p_param_s {
		/* Translated from */
		asn1p_ref_t	*governor;
		char		*argument;
	} *params;
	int params_count;
	int params_size;
	int _lineno;
} asn1p_paramlist_t;

/*
 * Constructor and destructor.
 */
asn1p_paramlist_t *asn1p_paramlist_new(int _lineno);
void asn1p_paramlist_free(asn1p_paramlist_t *);

asn1p_paramlist_t *asn1p_paramlist_clone(asn1p_paramlist_t *ref);

int asn1p_paramlist_add_param(asn1p_paramlist_t *,
		asn1p_ref_t *opt_gov, char *arg);


#endif	/* ASN1_PARSER_PARAMETERIZATION_H */
