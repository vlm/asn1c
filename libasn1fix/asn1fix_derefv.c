#include "asn1fix_internal.h"

/*
 * Dereference DefinedValues:
 */
int
asn1f_fix_dereference_values(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	int r_value = 0;

	if(expr->meta_type != AMT_VALUE)
		return 0;	/* Just ignore it */

	if(expr->value == NULL)
		return 0;	/* Just ignore it */

	if(expr->value && expr->value->type != ATV_REFERENCED)
		return 0;	/* Not a reference */

	DEBUG("%s(%s %x ::= %s) for line %d", __func__,
		expr->Identifier, expr->expr_type,
		asn1f_printable_value(expr->value), expr->_lineno);

	/*
	 * If this integer has a value, check that this value
	 * is an integer. If it is a reference, resolve it.
	 */
	if(expr->value) {

		if(asn1f_value_resolve(arg, expr)) {
			/* This function will emit messages */
			r_value = -1;
		}

		if(0 && expr->value->type != ATV_INTEGER) {
			FATAL(
				"INTEGER value %s at line %d: "
				"Incompatible value specified: %s",
				expr->Identifier,
				expr->_lineno,
				asn1f_printable_value(expr->value)
			);
			r_value = -1;
		}
	} else {
		FATAL("Value of \"%s\" at line %d: "
			"Incompatible value specified",
			expr->Identifier,
			expr->_lineno
		);
		r_value = -1;
	}

	return r_value;
}

