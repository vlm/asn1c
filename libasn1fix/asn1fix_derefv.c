#include "asn1fix_internal.h"

/*
 * Dereference DefinedValues:
 */
int
asn1f_fix_dereference_values(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	int r_value = 0;

	if(expr->value && expr->meta_type == AMT_VALUE) {
		if(asn1f_value_resolve(arg, expr, 0)) {
			/* This function will emit messages */
			r_value = -1;
		}
	}

	return r_value;
}


/*
 * Dereference DEFAULT values
 */
int
asn1f_fix_dereference_defaults(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	int r_value = 0;

	if(expr->marker.default_value) {
		arg_t tmparg = *arg;
		asn1p_expr_t tmpexpr = *expr;

		switch(expr->marker.default_value->type) {
		default:
			return r_value;
		case ATV_REFERENCED:
			break;
		}


		if(expr->expr_type == A1TC_CLASSFIELD_FTVFS) {
			asn1p_expr_t *child = TQ_FIRST(&expr->members);
			int ret;
			assert(child);
			assert(child->marker.default_value == 0);
			tmparg.expr = child;
			child->marker.default_value=expr->marker.default_value;
			ret = asn1f_fix_dereference_defaults(&tmparg);
			expr->marker.default_value = child->marker.default_value;
			child->marker.default_value = 0; /* ULB: trying to ensure there isn't another pointer to the same value object */
			if(ret == 0) return 0;	/* Finished */
		}

		tmparg.expr = &tmpexpr;
		tmpexpr.meta_type = AMT_VALUE;
		tmpexpr.marker.default_value = 0;
		tmpexpr.value = expr->marker.default_value;
		if(asn1f_value_resolve(&tmparg, &tmpexpr, 0))
			r_value = -1;
		expr->marker.default_value = tmpexpr.value;
	}

	return r_value;
}

