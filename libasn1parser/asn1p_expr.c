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
asn1p_expr_clone(asn1p_expr_t *expr, int skip_extensions) {
	asn1p_expr_t *clone;
	asn1p_expr_t *tcmemb;	/* Child of tc */
	int hit_ext = 0;

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
	CLCOPY(marker.flags);		/* OPTIONAL/DEFAULT */
	CLCOPY(module);
	CLCOPY(_mark);

	clone->data = 0;	/* Do not clone this */
	clone->data_free = 0;	/* Do not clone this */

	/*
	 * Clone complex fields.
	 */
	CLCLONE(Identifier, strdup);
	CLCLONE(reference, asn1p_ref_clone);
	CLCLONE(constraints, asn1p_constraint_clone);
	CLCLONE(combined_constraints, asn1p_constraint_clone);
	CLCLONE(params, asn1p_paramlist_clone);
	CLCLONE(value, asn1p_value_clone);
	CLCLONE(marker.default_value, asn1p_value_clone);
	CLCLONE(with_syntax, asn1p_wsyntx_clone);

	/*
	 * Copy all the children of this expr.
	 */
	TQ_FOR(tcmemb, &(expr->members), next) {
		asn1p_expr_t *cmemb;

		if(skip_extensions
		&& tcmemb->expr_type == A1TC_EXTENSIBLE) {
			hit_ext++; /* Even if hit_ext wraps around, we're OK. */
			continue;
		}
		if(hit_ext == 1) continue;	/* Skip between ...'s */

		cmemb = asn1p_expr_clone(tcmemb, skip_extensions);
		if(cmemb == NULL) {
			asn1p_expr_free(clone);
			return NULL;
		}
		asn1p_expr_add(clone, cmemb);
	}

	return clone;
}

/*
 * Add expression as a member of another.
 */
void
asn1p_expr_add(asn1p_expr_t *to, asn1p_expr_t *what) {
	TQ_ADD(&(to->members), what, next);
	what->parent_expr = to;
}


/*
 * Destruct the types collection structure.
 */
void
asn1p_expr_free(asn1p_expr_t *expr) {
	if(expr) {
		asn1p_expr_t *tm;

		/* Remove all children */
		while((tm = TQ_REMOVE(&(expr->members), next))) {
			if(tm->parent_expr != expr)
				printf("<%s:%p !-> %s:%p>\n",
					tm->Identifier, tm->parent_expr,
					expr->Identifier, expr);
			assert(tm->parent_expr == expr);
			asn1p_expr_free(tm);
		}

		if(expr->Identifier)
			free(expr->Identifier);
		if(expr->reference)
			asn1p_ref_free(expr->reference);
		if(expr->constraints)
			asn1p_constraint_free(expr->constraints);
		if(expr->combined_constraints)
			asn1p_constraint_free(expr->combined_constraints);
		if(expr->params)
			asn1p_paramlist_free(expr->params);
		if(expr->value)
			asn1p_value_free(expr->value);
		if(expr->marker.default_value)
			asn1p_value_free(expr->marker.default_value);
		if(expr->with_syntax)
			asn1p_wsyntx_free(expr->with_syntax);

		if(expr->data && expr->data_free)
			expr->data_free(expr->data);

		memset(expr, 0, sizeof(*expr));
		free(expr);
	}
}

