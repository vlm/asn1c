#include "asn1fix_internal.h"

asn1p_expr_t *
asn1f_class_access(arg_t *arg, asn1p_module_t *mod, asn1p_ref_t *ref) {
	asn1p_expr_t *ioclass;
	asn1p_expr_t *classfield;
	asn1p_expr_t *expr;
	asn1p_ref_t tmpref;

	assert(ref->comp_count > 1);

	DEBUG("ClassAccess lookup (%s) for line %d", asn1f_printable_reference(ref), ref->_lineno);

	/*
	 * Fetch the first part of the reference (OBJECT or ObjectSet).
	 * OBJECT.&<something>...
	 * ObjectSet.&<something>...
	 */
	assert(isupper(ref->components[0].name[0]));

	tmpref = *ref;
	tmpref.comp_count = 1;
	ioclass = asn1f_lookup_symbol(arg, mod, &tmpref);
	if(ioclass == NULL) {
		errno = ESRCH;
		return NULL;
	}

	classfield = asn1f_lookup_child(ioclass, ref->components[1].name);
	if(classfield == NULL) {
		DEBUG("CLASS %s does not contain field %s",
			ioclass->Identifier, ref->components[1].name);
		errno = ESRCH;
		return NULL;
	}

	assert(classfield->meta_type == AMT_OBJECTFIELD);

	DEBUG("CLASS %s -> %s (%d)", ioclass->Identifier,
		classfield->Identifier, classfield->expr_type);

	switch(classfield->expr_type) {
	case A1TC_CLASSFIELD_TFS:
		if(TQ_FIRST(&classfield->members)) {
			/* Already have something */
		} else {
			expr = asn1p_expr_new(classfield->_lineno);
			expr->expr_type = ASN_TYPE_ANY;
			expr->meta_type = AMT_TYPE;
			asn1p_expr_add(classfield, expr);
		}
		/* Fall through */
	case A1TC_CLASSFIELD_FTVFS:
		expr = TQ_FIRST(&classfield->members);
		assert(expr);
		return expr;
		break;
	default:
		FATAL("%s.%s: field type not yet supported. "
			"Consider donation to the asn1c author.",
			ioclass->Identifier, classfield->Identifier);
		return NULL;
	}

	return NULL;
}


int
asn1f_parse_class_with_syntax(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;

	if(expr->expr_type != A1TC_CLASSDEF
	|| expr->with_syntax == NULL)
		return 0;

	DEBUG("Class %s: checking WITH SYNTAX", expr->Identifier);

	return 0;
}
