#include "asn1fix_internal.h"

static int asn1f_parametrize(arg_t *arg, asn1p_expr_t *ex, asn1p_expr_t *ptype);
static int asn1f_param_process_recursive(arg_t *arg, asn1p_expr_t *expr, asn1p_expr_t *ptype, asn1p_expr_t *actargs);
static asn1p_expr_t *_referenced_argument(asn1p_ref_t *ref, asn1p_expr_t *ptype, asn1p_expr_t *actargs);

int
asn1f_fix_parametrized_assignment(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *ptype;

	assert(expr->expr_type == A1TC_PARAMETRIZED);
	assert(expr->reference);

	DEBUG("%s(\"%s\" ::= \"%s\" { %s }) for line %d",
		__func__, expr->Identifier,
		asn1f_printable_reference(expr->reference),
		asn1f_printable_value(expr->value),
		expr->_lineno);

	/*
	 * Find the corresponding parametrized type definition.
	 */
	DEBUG("Looking for parametrized type definition \"%s\"",
		asn1f_printable_reference(expr->reference));
	ptype = asn1f_lookup_symbol(arg, expr->module, expr->reference);
	if(ptype == NULL) {
		DEBUG("%s: missing parametrized type declaration",
			asn1f_printable_reference(expr->reference));
		return -1;
	}

	/*
	 * Check that the number of arguments which are expected by
	 * the parametrized type declaration is consistent with the
	 * number of arguments supplied by the parametrized assignment.
	 */
	if(asn1f_count_children(expr) != ptype->params->params_count) {
		FATAL("Number of actual arguments %d in %s at line %d "
			"is not equal to number of expected arguments "
			"%d in %s at line %d",
			asn1f_count_children(expr),
			asn1f_printable_reference(expr->reference),
			expr->_lineno,
			ptype->params->params_count,
			ptype->Identifier,
			ptype->_lineno
		);
		return -1;
	}

	/*
	 * Perform an expansion of a parametrized assignment.
	 */
	return asn1f_parametrize(arg, expr, ptype);
}

#define	SUBSTITUTE(to, from)	do {		\
		asn1p_expr_t tmp;		\
		tmp = *(to);			\
		*(to) = *(from);		\
		*(from) = tmp;			\
		(to)->next = tmp.next;		\
		memset(&((from)->next), 0,	\
			sizeof((from)->next));	\
		asn1p_expr_free(from);		\
	} while(0)

static int
asn1f_parametrize(arg_t *arg, asn1p_expr_t *expr, asn1p_expr_t *ptype) {
	asn1p_expr_t *nex;
	void *p;
	int ret;

	/*
	 * The algorithm goes like that:
	 * 1. Replace the expression's type with parametrized type.
	 * 2. For every child in the parametrized type, import it
	 * as a child of the expression, replacing all occurences of
	 * symbols which are defined as parametrized type arguments
	 * with the actual values.
	 */

	nex = asn1p_expr_clone(ptype, 0);
	if(nex == NULL) return -1;

	/*
	 * Cleanup the new expression so there is no ptype-related
	 * stuff hanging around.
	 */
	p = strdup(expr->Identifier);
	if(p) {
		free(nex->Identifier);
		nex->Identifier = p;
	} else {
		asn1p_expr_free(nex);
		return -1;
	}
	asn1p_paramlist_free(nex->params);
	nex->params = NULL;
	nex->meta_type = expr->meta_type;

	ret = asn1f_param_process_recursive(arg, nex, ptype, expr);
	if(ret != 0) {
		asn1p_expr_free(nex);
		return ret;
	}

	SUBSTITUTE(expr, nex);

	return ret;
}

static int
asn1f_param_process_recursive(arg_t *arg, asn1p_expr_t *expr, asn1p_expr_t *ptype, asn1p_expr_t *actargs) {
	asn1p_expr_t *child;

	TQ_FOR(child, &(expr->members), next) {
		asn1p_expr_t *ra;
		asn1p_expr_t *ne;

		ra = _referenced_argument(child->reference, ptype, actargs);
		if(ra == NULL) continue;

		DEBUG("Substituting parameter for %s %s at line %d",
			child->Identifier,
			asn1f_printable_reference(child->reference),
			child->_lineno
		);

		assert(child->meta_type == AMT_TYPEREF);
		assert(child->expr_type == A1TC_REFERENCE);

		ne = asn1p_expr_clone(ra, 0);
		if(ne == NULL) return -1;
		assert(ne->Identifier == 0);
		ne->Identifier = strdup(child->Identifier);
		if(ne->Identifier == 0) {
			asn1p_expr_free(ne);
			return -1;
		}
		SUBSTITUTE(child, ne);
	}

	return 0;
}

static asn1p_expr_t *
_referenced_argument(asn1p_ref_t *ref, asn1p_expr_t *ptype, asn1p_expr_t *actargs) {
	asn1p_expr_t *aa;
	int i;

	if(ref == NULL || ref->comp_count != 1)
		return NULL;

	aa = TQ_FIRST(&(actargs->members));
	for(i = 0; i < ptype->params->params_count;
				i++, aa = TQ_NEXT(aa, next)) {
		if(strcmp(ref->components[0].name,
			ptype->params->params[i].argument) == 0)
			return aa;
	}

	return NULL;
}
