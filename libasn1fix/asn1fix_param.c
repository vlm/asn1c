#include "asn1fix_internal.h"

static int asn1f_parametrize(arg_t *arg, asn1p_expr_t *ex, asn1p_expr_t *ptype);
static int asn1f_param_process_recursive(arg_t *arg, asn1p_expr_t *expr, asn1p_expr_t *ptype, asn1p_expr_t *actargs);
static int asn1f_param_process_constraints(arg_t *arg, asn1p_expr_t *expr, asn1p_expr_t *ptype, asn1p_expr_t *actargs);

static asn1p_expr_t *_referenced_argument(asn1p_ref_t *ref, asn1p_expr_t *ptype, asn1p_expr_t *actargs);
static int _process_constraints(arg_t *arg, asn1p_constraint_t *ct, asn1p_expr_t *ptype, asn1p_expr_t *actargs);

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

#define	SUBSTITUTE(to, from)	do {				\
		asn1p_expr_t tmp, *__v;				\
		tmp = *(to);					\
		*(to) = *(from);				\
		TQ_MOVE(&(to)->members, &(from)->members);	\
		*(from) = tmp;					\
		(to)->next = tmp.next;				\
		(to)->parent_expr = tmp.parent_expr;		\
		memset(&((from)->next), 0,			\
			sizeof((from)->next));			\
		memset(&((from)->members), 0,			\
			sizeof((from)->members));		\
		asn1p_expr_free(from);				\
		TQ_FOR(__v, &((to)->members), next) {		\
			assert(__v->parent_expr == (from));	\
			__v->parent_expr = (to);		\
		}						\
	} while(0)

static int
asn1f_parametrize(arg_t *arg, asn1p_expr_t *expr, asn1p_expr_t *ptype) {
	asn1p_expr_t *nex;
	void *p;
	int ret;

	DEBUG("asn1f_parametrize(%s <= %s)",
		expr->Identifier, ptype->Identifier);

	/*
	 * The algorithm goes like that:
	 * 1. Replace the expression's type with parametrized type.
	 * 2. For every child in the parametrized type, import it
	 * as a child of the expression, replacing all occurences of
	 * symbols which are defined as parametrized type arguments
	 * with the actual values.
	 * 3. Don't forget to parametrize the subtype constraints.
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
		asn1p_expr_t *ne;	/* new expression (clone) */

		if(asn1f_param_process_constraints(arg, child, ptype, actargs))
			return -1;

		ra = _referenced_argument(child->reference, ptype, actargs);
		if(ra) {
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
	}

	return 0;
}

/*
 * Check that the given ref looks like an argument of a parametrized type.
 */
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

/*
 * Search for parameters inside constraints.
 */
static int
asn1f_param_process_constraints(arg_t *arg, asn1p_expr_t *expr, asn1p_expr_t *ptype, asn1p_expr_t *actargs) {
	asn1p_constraint_t *cts;
	int ret;

	if(!expr->constraints) return 0;

	cts = asn1p_constraint_clone(expr->constraints);
	assert(cts);

	ret = _process_constraints(arg, cts, ptype, actargs);
	if(ret == 1) {
		asn1p_constraint_free(expr->constraints);
		expr->constraints = cts;
		ret = 0;
	} else {
		asn1p_constraint_free(cts);
	}

	return ret;
}

static int
_process_constraints(arg_t *arg, asn1p_constraint_t *ct, asn1p_expr_t *ptype, asn1p_expr_t *actargs) {
	asn1p_value_t *values[3];
	int rvalue = 0;
	size_t i;

	values[0] = ct->value;
	values[1] = ct->range_start;
	values[2] = ct->range_stop;

	for(i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
		asn1p_value_t *v = values[i];
		asn1p_expr_t *ra;
		asn1p_ref_t *ref;
		char *str;

		if(!v || v->type != ATV_REFERENCED) continue;

		ref = v->value.reference;
		ra = _referenced_argument(ref, ptype, actargs);
		if(!ra) continue;

		DEBUG("_process_constraints(%s), ra=%s",
			asn1f_printable_reference(ref), ra->Identifier);

		if(ra->expr_type == A1TC_PARAMETRIZED) {
			DEBUG("Double parametrization");
		}

		assert(ra->Identifier);
		str = strdup(ra->Identifier);
		if(!str) return -1;

		assert(ref->comp_count == 1);
		ref = asn1p_ref_new(ref->_lineno);
		if(!ref) { free(str); return -1; }

		if(asn1p_ref_add_component(ref, str, 0)) {
			free(str);
			return -1;
		}

		asn1p_ref_free(v->value.reference);
		v->value.reference = ref;
		rvalue = 1;
	}

	/* Process the rest of constraints recursively */
	for(i = 0; i < ct->el_count; i++) {
		int ret = _process_constraints(arg, ct->elements[i],
			ptype, actargs);
		if(ret == -1)
			rvalue = -1;
		else if(ret == 1 && rvalue != -1)
			rvalue = 1;
	}

	return rvalue;
}

