#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

/*
 * Construct a new empty types collection.
 */
asn1p_expr_t *
asn1p_expr_new(int _lineno) {
	asn1p_expr_t *expr;

	expr = calloc(1, sizeof *expr);
	if(expr) {
		TQ_INIT(&(expr->members));
		expr->_lineno = _lineno;
	}

	return expr;
}

asn1p_expr_t *
asn1p_expr_clone(asn1p_expr_t *expr) {
	asn1p_expr_t *clone;
	asn1p_expr_t *tcmemb;	/* Child of tc */

	clone = asn1p_expr_new(expr->_lineno);
	if(clone == NULL) return NULL;

#define	CLCOPY(field)	do { clone->field = expr->field; } while(0)
#define	CLCLONE(field, func)	do { if(expr->field) {		\
			clone->field = func(expr->field);	\
			if(clone->field == NULL) {		\
				asn1p_expr_free(clone);		\
				return NULL;			\
			}					\
		} } while(0)

	/*
	 * Copy simple fields.
	 */
	CLCOPY(meta_type);
	CLCOPY(expr_type);
	CLCOPY(tag);
	CLCOPY(marker);
	CLCOPY(_mark);

	clone->data = 0;	/* Do not clone this */
	clone->data_free = 0;	/* Do not clone this */

	/*
	 * Clone complex fields.
	 */
	CLCLONE(Identifier, strdup);
	CLCLONE(reference, asn1p_ref_clone);
	CLCLONE(constraints, asn1p_constraint_clone);
	CLCLONE(params, asn1p_paramlist_clone);
	CLCLONE(value, asn1p_value_clone);
	CLCLONE(with_syntax, asn1p_wsyntx_clone);

	/*
	 * Copy all the children of this expr.
	 */
	TQ_FOR(tcmemb, &(expr->members), next) {
		asn1p_expr_t *cmemb = asn1p_expr_clone(tcmemb);
		if(cmemb == NULL) {
			asn1p_expr_free(clone);
			return NULL;
		}
		TQ_ADD(&(clone->members), cmemb, next);
	}

	return clone;
}

/*
 * Destruct the types collection structure.
 */
void
asn1p_expr_free(asn1p_expr_t *expr) {
	if(expr) {
		asn1p_expr_t *tm;

		if(expr->Identifier)
			free(expr->Identifier);
		if(expr->reference)
			asn1p_ref_free(expr->reference);
		if(expr->constraints)
			asn1p_constraint_free(expr->constraints);
		if(expr->params)
			asn1p_paramlist_free(expr->params);
		if(expr->value)
			asn1p_value_free(expr->value);
		if(expr->with_syntax)
			asn1p_wsyntx_free(expr->with_syntax);

		/* Remove all children */
		while((tm = TQ_REMOVE(&(expr->members), next))) {
			asn1p_expr_free(tm);
		}

		if(expr->data && expr->data_free)
			expr->data_free(expr->data);

		memset(expr, 0, sizeof(*expr));
		free(expr);
	}
}

