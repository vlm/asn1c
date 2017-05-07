#include "asn1fix_internal.h"

static int _asn1f_copy_value(arg_t *arg, asn1p_expr_t *to,asn1p_expr_t *from);

int
asn1f_value_resolve(arg_t *arg, asn1p_expr_t *expr, const enum asn1p_constraint_type_e *opt_constr_type) {
	asn1p_expr_t *val_type_expr;
	asn1p_expr_t *value_expr;
	asn1p_expr_t *type_expr;
	int ret;

	/* Make sure this IS a value assignment */
	assert(expr->meta_type == AMT_VALUE);
	assert(expr->value);

	if(expr->value->type != ATV_REFERENCED)
		return 0;

	DEBUG("(=\"%s\", %x%s%s)",
		asn1f_printable_value(expr->value), expr->expr_type,
		opt_constr_type ? ", " : "",
		opt_constr_type
			? asn1p_constraint_type2str(*opt_constr_type) : ""
	);

	/*
	 * 1. Find the terminal type for this assignment.
	 */
	type_expr = asn1f_find_terminal_type(arg, expr);
	if(type_expr == 0) {
		if(errno == EEXIST) {
			DEBUG("External type for %s at line %d",
				expr->Identifier, expr->_lineno);
			return 0;
		} else {
			FATAL("Terminal type for %s at line %d not found",
				expr->Identifier, expr->_lineno);
			return -1;
		}
	}

	if(asn1f_look_value_in_type(arg, type_expr, expr) == -1) {
		FATAL("Value not found in type for %s at line %d",
			expr->Identifier, expr->_lineno);
		return -1;
	}

	/*
	 * 2. Find the terminal value also.
	 */
	value_expr = asn1f_find_terminal_value(arg, expr);
	if(value_expr) {
		DEBUG("Terminal value for %s->%s is %s at line %d",
			expr->Identifier, asn1f_printable_value(expr->value),
			value_expr->Identifier, value_expr->_lineno);
	} else {
		FATAL("Terminal value for %s->%s not found",
			expr->Identifier, asn1f_printable_value(expr->value));
		return -1;
	}

	/*
	 * 3. Find the _type_ of a _terminal value_.
	 */
	WITH_MODULE(value_expr->module,
		val_type_expr = asn1f_find_terminal_type(arg, value_expr));
	if(val_type_expr) {
		DEBUG("Terminal type of value %s->%s is %s at line %d",
			expr->Identifier, asn1f_printable_value(expr->value),
			val_type_expr->Identifier, val_type_expr->_lineno);
	} else {
		FATAL("Terminal type of value %s->%s not found",
			expr->Identifier, asn1f_printable_value(expr->value));
		return -1;
	}

	/*
	 * 4. Check compatibility between the type of the current expression
	 * and the type of the discovered value.
	 */
	if(opt_constr_type)
		ret = asn1constraint_compatible(val_type_expr->expr_type,
			*opt_constr_type, 0 /* must not matter here */);
	else
		ret = asn1f_check_type_compatibility(arg,
			type_expr, val_type_expr);
	if(ret == -1) {
		switch(type_expr->expr_type) {
		default:
			if(!(type_expr->expr_type & ASN_STRING_MASK))
				break;
			/* Compatibility rules are not defined */
			/* Fall through */
		case ASN_BASIC_INTEGER:
		case ASN_BASIC_ENUMERATED:
			FATAL("Incompatible type of \"%s\" (%s) at line %d "
			"with \"%s\" (%s) at line %d",
			type_expr->Identifier,
				ASN_EXPR_TYPE2STR(type_expr->expr_type),
				type_expr->_lineno,
			val_type_expr->Identifier,
				ASN_EXPR_TYPE2STR(val_type_expr->expr_type),
				val_type_expr->_lineno);
			return -1;
		case ASN_BASIC_OBJECT_IDENTIFIER:
			/*
			 * Ignore this for now.
			 * We can't deal with OIDs inheritance properly yet.
			 */
			return 0;
		}
		WARNING("Possibly incompatible type of \"%s\" (%s) at line %d "
			"with \"%s\" (%s) at line %d",
			type_expr->Identifier,
				ASN_EXPR_TYPE2STR(type_expr->expr_type),
				type_expr->_lineno,
			val_type_expr->Identifier,
				ASN_EXPR_TYPE2STR(val_type_expr->expr_type),
				val_type_expr->_lineno);
		return 1;
	}

	if(asn1f_look_value_in_type(arg, val_type_expr, expr) == -1)
		return -1;

	/*
	 * 5. Copy value from the terminal value into the current expression.
	 */
	ret = _asn1f_copy_value(arg, expr, value_expr);
	if(ret == -1) {
		FATAL("Value %s cannot be copied from line %d to line %d",
			asn1f_printable_value(value_expr->value),
			value_expr->_lineno, expr->_lineno);
		return -1;
	}

	DEBUG("Final value for \"%s\" at line %d is %s",
		expr->Identifier, expr->_lineno,
		asn1f_printable_value(expr->value));

	return 0;
}

static int
_asn1f_copy_value(arg_t *arg, asn1p_expr_t *to, asn1p_expr_t *from) {
	asn1p_value_t *v;

	v = asn1p_value_clone(from->value);
	if(v) {
		asn1p_value_free(to->value);
		to->value = v;
		DEBUG("Copied value %s from \"%s\" on line %d "
			"to \"%s\" on line %d",
			asn1f_printable_value(v),
			from->Identifier,
			from->_lineno,
			to->Identifier,
			to->_lineno
		);
		return 0;
	} else {
		return -1;
	}
}

int
asn1f_look_value_in_type(arg_t *arg,
		asn1p_expr_t *type_expr,
		asn1p_expr_t *value_expr) {
	asn1p_expr_t *child_expr;
	char *identifier;

	if(value_expr->value->type != ATV_REFERENCED
	|| value_expr->value->value.reference->comp_count != 1)
		return 0;
	if(type_expr->expr_type != ASN_BASIC_INTEGER
	&& type_expr->expr_type != ASN_BASIC_ENUMERATED)
		return 0;

	DEBUG("(for %s in %s %x) for line %d",
		asn1f_printable_value(value_expr->value),
		type_expr->Identifier,
		type_expr->expr_type,
		value_expr->_lineno);

	/*
	 * Look into the definitions of the type itself:
	 * Type1 ::= INTEGER { a(1), b(2) }
	 * value Type1 = b	-- will assign 2
	 */
	identifier = value_expr->value->value.reference->components[0].name;

	child_expr = asn1f_lookup_child(type_expr, identifier);
	DEBUG("Looking into a type %s at line %d for %s at line %d: %s",
		type_expr->Identifier, type_expr->_lineno,
		identifier, value_expr->_lineno,
		child_expr
			? asn1f_printable_value(child_expr->value)
			: "<not found>"
		);

	if(child_expr) {
		/* Maybe hasn't been fixed yet. */
		if (!child_expr->value) {
			asn1p_expr_t *saved_expr = arg->expr;
			arg->expr = type_expr;
			switch (type_expr->expr_type) {
			case ASN_BASIC_INTEGER:
				asn1f_fix_integer(arg);
				break;
			case ASN_BASIC_ENUMERATED:
				asn1f_fix_enum(arg);
				break;
			default:
				WARNING("Unexpected type %s for %s",
						type_expr->expr_type,
						type_expr->Identifier);
				return -1;
			}
			arg->expr = saved_expr;
		}
		if(child_expr->value && _asn1f_copy_value(arg,
				value_expr, child_expr))
			return -1;
		/* Fall through */
	}

	return 0;
}
