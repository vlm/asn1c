#include "asn1fix_internal.h"
#include "asn1fix_constraint.h"
#include "asn1fix_crange.h"

static void _remove_extensions(arg_t *arg, asn1p_constraint_t *ct, int flast);
static int constraint_type_resolve(arg_t *arg, asn1p_constraint_t *ct);
static int constraint_object_resolve(arg_t *arg, asn1p_value_t *value);
static int constraint_value_resolve(arg_t *arg, asn1p_value_t **value, enum asn1p_constraint_type_e real_ctype);

int
asn1constraint_pullup(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *top_parent;
	asn1p_constraint_t *ct_parent;
	asn1p_constraint_t *ct_expr;
	int ret;

	if(expr->combined_constraints)
		return 0;	/* Operation already performed earlier */

	switch(expr->meta_type) {
	case AMT_TYPE:
	case AMT_TYPEREF:
	case AMT_VALUESET:
		break;
	default:
		return 0;	/* Nothing to do */
	}

	if(expr->expr_type == A1TC_REFERENCE) {
		asn1p_ref_t *ref = expr->reference;
		asn1p_expr_t *parent_expr;

		assert(ref);
        parent_expr = asn1f_lookup_symbol(arg, expr->rhs_pspecs, ref);
        if(!parent_expr) {
			if(errno != EEXIST) {
				DEBUG("\tWhile fetching parent constraints: "
					"type \"%s\" not found: %s",
					asn1f_printable_reference(ref),
					strerror(errno));
				return -1;
			} else {
				/*
				 * -fknown-extern-type is given.
				 * Assume there are no constraints there.
				 */
				WARNING("External type \"%s\": "
					"assuming no constraints",
					asn1f_printable_reference(ref));
				ct_parent = 0;
			}
		} else {
			arg->expr = parent_expr;
			ret = asn1constraint_pullup(arg);
			arg->expr = expr;
			if(ret) return ret;

			ct_parent = parent_expr->combined_constraints;
		}
    } else {
		ct_parent = 0;
	}

	ct_expr = expr->constraints;

	if(!ct_parent && !ct_expr)
		return 0;	/* No constraints to consider */

	/*
	 * Resolve constraints, if not already resolved.
	 */
	top_parent = asn1f_find_terminal_type(arg, arg->expr);
    ret = asn1constraint_resolve(
        arg, ct_expr, top_parent ? top_parent->expr_type : A1TC_INVALID, 0);
    if(ret) return ret;

	/*
	 * Copy parent type constraints.
	 */
	if(ct_parent) {
		ct_parent = asn1p_constraint_clone(ct_parent);
		assert(ct_parent);
	}

	/*
	 * If the current type does not have constraints, it inherits
	 * the constraints of a parent.
	 */
	if(ct_parent && !ct_expr) {
		expr->combined_constraints = ct_parent;
		return 0;
	}

	ct_expr = asn1p_constraint_clone(ct_expr);
	assert(ct_expr);

	/*
	 * Now we have a set of current expression's constraints,
	 * and an optional set of the parent expression's constraints.
	 */

	if(ct_parent) {
		/*
		 * If we have a parent, remove all the extensions (46.4).
		 */
		_remove_extensions(arg, ct_parent, 0);

		expr->combined_constraints = ct_parent;
		if(ct_expr->type == ACT_CA_SET) {
			unsigned int i;
			for(i = 0; i < ct_expr->el_count; i++) {
				if(asn1p_constraint_insert(
					expr->combined_constraints,
						ct_expr->elements[i])) {
					expr->combined_constraints = 0;
					asn1p_constraint_free(ct_expr);
					asn1p_constraint_free(ct_parent);
					return -1;
				} else {
					ct_expr->elements[i] = 0;
				}
			}
			asn1p_constraint_free(ct_expr);
		} else {
			asn1p_constraint_insert(expr->combined_constraints,
				ct_expr);
		}
	} else {
		_remove_extensions(arg, ct_expr, 1);
		expr->combined_constraints = ct_expr;
	}

	return 0;
}

int
asn1constraint_resolve(arg_t *arg, asn1p_constraint_t *ct, asn1p_expr_type_e etype, enum asn1p_constraint_type_e effective_type) {
	enum asn1p_constraint_type_e real_constraint_type;
	unsigned int el;
	int rvalue = 0;
	int ret;

	DEBUG("(\"%s\")", arg->expr->Identifier);

	if(!ct) return 0;

	/* Don't touch information object classes */
	switch(ct->type) {
	case ACT_CT_SIZE:
	case ACT_CT_FROM:
		if(effective_type && effective_type != ct->type) {
			FATAL("%s at line %d: "
				"Incompatible nested %s within %s",
				arg->expr->Identifier, ct->_lineno,
				asn1p_constraint_type2str(ct->type),
				asn1p_constraint_type2str(effective_type)
			);
		}
		effective_type = ct->type;
		break;
	case ACT_CT_WCOMP:
	case ACT_CT_WCOMPS:
	case ACT_CA_CRC:
		return 0;
	default:
		break;
	}

	real_constraint_type = effective_type ? effective_type : ct->type;

	if(etype != A1TC_INVALID) {

		ret = asn1constraint_compatible(etype, real_constraint_type,
				arg->flags & A1F_EXTENDED_SizeConstraint);
		switch(ret) {
		case -1:	/* If unknown, assume OK. */
		case  1:
			break;
		case 0:
		default:
			FATAL("%s at line %d: "
				"Constraint type %s is not applicable to %s",
				arg->expr->Identifier, ct->_lineno,
				asn1p_constraint_type2str(real_constraint_type),
				ASN_EXPR_TYPE2STR(etype)
			);
			rvalue = -1;
			break;
		}
	} else {
		WARNING("%s at line %d: "
			"Constraints ignored: Unresolved parent type",
			arg->expr->Identifier, arg->expr->_lineno);
	}

	/*
	 * Resolve all possible references, wherever they occur.
	 */
	if(ct->containedSubtype) {
		ret = constraint_type_resolve(arg, ct);
		RET2RVAL(ret, rvalue);
	}
	if(ct->value && ct->value->type == ATV_REFERENCED) {
        ret = constraint_value_resolve(arg, &ct->value, real_constraint_type);
        RET2RVAL(ret, rvalue);
	}
	if(ct->range_start && ct->range_start->type == ATV_REFERENCED) {
        ret = constraint_value_resolve(arg, &ct->range_start,
                                       real_constraint_type);
        RET2RVAL(ret, rvalue);
	}
	if(ct->range_stop && ct->range_stop->type == ATV_REFERENCED) {
        ret = constraint_value_resolve(arg, &ct->range_stop,
                                       real_constraint_type);
        RET2RVAL(ret, rvalue);
	}
	if (ct->value && ct->value->type == ATV_UNPARSED && etype == A1TC_CLASSDEF) {
		ret = constraint_object_resolve(arg, ct->value);
		RET2RVAL(ret, rvalue);
	}

    /*
     * Proceed recursively.
     */
    for(el = 0; el < ct->el_count; el++) {
        ret = asn1constraint_resolve(arg, ct->elements[el], etype,
                                     effective_type);
        RET2RVAL(ret, rvalue);
    }

    return rvalue;
}

static void
_remove_extensions(arg_t *arg, asn1p_constraint_t *ct, int forgive_last) {
	unsigned int i;

	if(!ct) return;

	for(i = 0; i < ct->el_count; i++) {
		if(ct->elements[i]->type == ACT_EL_EXT)
			break;
		if(forgive_last && ct->type == ACT_CA_SET
			&& i + 1 == ct->el_count)
			return;
		_remove_extensions(arg, ct->elements[i], 0);
	}

	/* Remove the elements at and after the extensibility mark */
	for(; i < ct->el_count; ct->el_count--) {
		asn1p_constraint_t *rm;
		rm = ct->elements[ct->el_count-1];
		asn1p_constraint_free(rm);
	}

	if(i < ct->el_size)
		ct->elements[i] = 0;
}

static asn1p_ref_t *
get_reference_from(asn1p_constraint_t *ct) {
    if(ct->containedSubtype->type == ATV_REFERENCED) {
        return ct->containedSubtype->value.reference;
    } else if(ct->containedSubtype->type == ATV_TYPE) {
        if(ct->containedSubtype->value.v_type->expr_type == A1TC_REFERENCE) {
            return ct->containedSubtype->value.v_type->reference;
        }
    }
    return NULL;
}

static int
constraint_type_resolve(arg_t *arg, asn1p_constraint_t *ct) {
    asn1p_constraint_t *ct_expr;
    int ret;
    asn1p_expr_t *rtype = (asn1p_expr_t *)0;

    DEBUG("(\"%s\")", asn1f_printable_value(ct->containedSubtype));

    if(ct->containedSubtype->type == ATV_VALUESET) {
        ct_expr = ct->containedSubtype->value.constraint;
        DEBUG("Found %s in constraints", "ValueSet");
    } else if(get_reference_from(ct)) {
        arg_t tmparg;

        rtype = asn1f_lookup_symbol(arg, arg->expr->rhs_pspecs,
                                    get_reference_from(ct));
        if(!rtype) {
            FATAL(
                "Cannot find type \"%s\" in constraints "
                "at line %d",
                asn1f_printable_value(ct->containedSubtype), ct->_lineno);
            return -1;
        }

        tmparg = *arg;
        tmparg.expr = rtype;
        tmparg.mod = rtype->module;
        ret = asn1constraint_pullup(&tmparg);
        if(ret) return ret;

        if(rtype->ioc_table) {
            if(!arg->expr->ioc_table)
                arg->expr->ioc_table = asn1p_ioc_table_new();
            asn1p_ioc_table_append(arg->expr->ioc_table, rtype->ioc_table);
            asn1p_value_free(ct->containedSubtype);
            ct->containedSubtype = NULL;
        }

        ct_expr = rtype->combined_constraints;
        if(!ct_expr) return 0;
    } else {
        FATAL("Unsupported constraint kind %s at line %d",
              asn1f_printable_value(ct->containedSubtype), ct->_lineno);
        return -1;
    }

    ct_expr = asn1p_constraint_clone(ct_expr);
    assert(ct_expr);

    _remove_extensions(arg, ct_expr, 0);

    if(ct_expr->type == ACT_CA_SET) {
        unsigned int i;
        for(i = 0; i < ct_expr->el_count; i++) {
            if(asn1p_constraint_insert(
                ct, ct_expr->elements[i])) {
                asn1p_constraint_free(ct_expr);
                return -1;
            } else {
                ct_expr->elements[i] = 0;
            }
        }
        asn1p_constraint_free(ct_expr);
    } else {
        ret = asn1p_constraint_insert(ct, ct_expr);
        assert(ret == 0);
    }

    ct->type = ACT_CA_SET;

    /* keep constrainedSubtype field for future usage,
       if valueset has not been resolved yet. */
    if(rtype &&
        (rtype->meta_type == AMT_VALUESET) &&
        (!rtype->ioc_table))
        return 0;

    asn1p_value_free(ct->containedSubtype);
    ct->containedSubtype = NULL;

    return 0;
}

static int
constraint_value_resolve(arg_t *arg, asn1p_value_t **value,
                         enum asn1p_constraint_type_e real_ctype) {
    asn1p_expr_t static_expr;
	arg_t tmparg;
	int rvalue = 0;
	int ret;

	DEBUG("(\"%s\", within <%s>)",
		asn1f_printable_value(*value),
		asn1p_constraint_type2str(real_ctype));

	static_expr = *arg->expr;
	static_expr.value = *value;
	static_expr.meta_type = AMT_VALUE;
	tmparg = *arg;
	tmparg.mod = arg->expr->module;
	tmparg.expr = &static_expr;
	ret = asn1f_value_resolve(&tmparg, &static_expr, &real_ctype);
	RET2RVAL(ret, rvalue);
	assert(static_expr.value);
	*value = static_expr.value;

	return rvalue;
}

static int
constraint_object_resolve(arg_t *arg, asn1p_value_t *value) {
    asn1p_expr_t tmp_expr = *arg->expr;
	asn1p_expr_t *saved_expr = arg->expr;

	tmp_expr.meta_type = AMT_VALUESET;
	tmp_expr.expr_type = A1TC_REFERENCE;
	tmp_expr.value = value;
	arg->expr = &tmp_expr;

	if (asn1f_check_class_object(arg)) {
		arg->expr = saved_expr;
		FATAL("Parsing ObjectSet %s failed at %d", arg->expr->Identifier,
				arg->expr->_lineno);
		return -1;
	}

	arg->expr = saved_expr;
	return 0;
}

