#include "asn1fix_internal.h"

typedef enum field_category {
	OFC_INVALID,		/* Invalid object field category */
	OFC_TYPE,
	OFC_FIXED_TYPE_VALUE,
	OFC_VARIABLE_TYPE_VALUE,
	OFC_FIXED_TYPE_VALUE_SET,
	OFC_VARIABLE_TYPE_VALUE_SET,
	OFC_INFORMATION_OBJECT,
	OFC_INFORMATION_OBJECT_SET,
} field_category_e;

typedef enum object_category {
	OC_INVALID,
	OC_OBJECT,
	OC_OBJECTSET,
} object_category_e;

static field_category_e  asn1f_class_field_category(asn1p_expr_t *ofield);
static object_category_e asn1f_class_object_category(asn1p_expr_t *expr);
static asn1p_expr_t *
asn1f_class_dot_lookup(arg_t *arg, asn1p_expr_t *obj, asn1p_ref_t *ref);

asn1p_expr_t *
asn1f_class_access(arg_t *arg, asn1p_module_t *mod, asn1p_ref_t *ref) {
	asn1p_expr_t *obj;		/* Information Object or Object Set */
	object_category_e obj_cat;	/* Object category */
	//field_category_e field_cat;	/* Field category */
	asn1p_expr_t *result;
	asn1p_ref_t tmpref;

	assert(ref->comp_count > 1);

	DEBUG("(%s) for line %d", asn1f_printable_reference(ref), ref->_lineno);

	/*
	 * Fetch the first part of the reference (OBJECT or ObjectSet).
	 * OBJECT.&<something>...
	 * ObjectSet.&<something>...
	 */
	assert(isupper(ref->components[0].name[0]));

	tmpref = *ref;
	tmpref.comp_count = 1;
	obj = asn1f_lookup_symbol(arg, mod, &tmpref);
	if(obj == NULL) {
		errno = ESRCH;
		return NULL;
	}

	/*
	 * Make sure the symbol lexical property (upper-case, lower-case)
	 * corresponds to the type of the expression returned by
	 * lookup_symbol().
	 */
	obj_cat = asn1f_class_object_category(obj);
	switch(obj_cat) {
	case OC_OBJECT:
	case OC_OBJECTSET:
		if(ref->components[0].lex_type
			== (obj_cat==OC_OBJECT)
				? RLT_CAPITALS
				: RLT_Uppercase)
			break;
		/* Fall through */
	case OC_INVALID:
		WARNING("Symbol \"%s\" is not compatible "
			"with referenced expression \"%s\" at line %d",
			ref->components[0].name,
			obj->Identifier, obj->_lineno);
		errno = EPERM;
		return NULL;
	}

	/*
	 * Find the specified field within the object.
	 */
	result = asn1f_class_dot_lookup(arg, obj, ref);
	if(result == NULL) {
		return NULL;
	}

	//field_cat = asn1f_class_field_category(result);

	DEBUG("FILLME: %s", result->Identifier);

	return result;
}

static object_category_e
asn1f_class_object_category(asn1p_expr_t *expr) {

	switch(expr->meta_type) {
	case AMT_OBJECT:
		return OC_OBJECT;
	case AMT_OBJECTSET:
		return OC_OBJECTSET;
	case AMT_VALUESET:
		if(expr->expr_type == A1TC_REFERENCE
		&& expr->reference
		&& expr->reference->comp_count == 1
		&& expr->reference->components[0].lex_type == RLT_CAPITALS)
		{
			/* FIXME: use find_terminal_type instead! */
			return OC_OBJECTSET;
		}
		break;
	default:
		break;
	}

	return OC_INVALID;
}

static field_category_e
asn1f_class_field_category(asn1p_expr_t *ofield) {

	assert(ofield);

	if(ofield->Identifier[0] != '&') {
		assert(ofield->Identifier[0] == '&');
		return OFC_INVALID;
	}

	if(isupper(ofield->Identifier[1])) {
		if(ofield->reference) {
			enum asn1p_ref_lex_type_e lex_type
				= ofield->reference->components[0].lex_type;

			switch(lex_type) {
			case RLT_CAPITALS:
				return OFC_INFORMATION_OBJECT_SET;
			case RLT_Uppercase:
				return OFC_FIXED_TYPE_VALUE_SET;
			case RLT_AmpUppercase:
				return OFC_VARIABLE_TYPE_VALUE_SET;
			default:
				break;
			}
		} else {
			if(ofield->expr_type == A1TC_CLASSFIELD)
				return OFC_TYPE;

			switch(ofield->meta_type) {
			case AMT_TYPE:
			case AMT_TYPEREF:
				return OFC_FIXED_TYPE_VALUE_SET;
			default:
				break;
			}

		}
	} else {
		if(ofield->reference) {
			enum asn1p_ref_lex_type_e lex_type
				= ofield->reference->components[0].lex_type;

			switch(lex_type) {
			case RLT_CAPITALS:
				return OFC_INFORMATION_OBJECT;
			case RLT_Uppercase:
				return OFC_FIXED_TYPE_VALUE;
			case RLT_AmpUppercase:
				return OFC_VARIABLE_TYPE_VALUE;
			default:
				break;
			}
		} else {
			switch(ofield->meta_type) {
			case AMT_TYPE:
			case AMT_TYPEREF:
				return OFC_FIXED_TYPE_VALUE;
			default:
				break;
			}
		}
	}

	return OFC_INVALID;
}


static asn1p_expr_t *
asn1f_class_dot_lookup(arg_t *arg, asn1p_expr_t *obj, asn1p_ref_t *ref) {
	asn1p_expr_t *ofield = NULL;	/* Information Object's Field */
	field_category_e field_cat;	/* Field category */
	int comp;

	assert(ref->comp_count >= 2);

	for(comp = 1 /* sic! */; comp < ref->comp_count; comp++) {
		int is_last_component = (comp + 1 == ref->comp_count);
		char *comp_name = ref->components[comp].name;

		ofield = asn1f_lookup_child(obj, comp_name);
		if(ofield == NULL) {
			DEBUG("Cannot find field \"%s\" in \"%s\" at line %d",
				ref->components[1].name,
				obj->Identifier,
				obj->_lineno);
			errno = EPERM;
			return NULL;
		}

		/*
		 * Compute the category of the field of
		 * the information object class.
		 */
		field_cat = asn1f_class_field_category(ofield);

		switch(field_cat) {
		case OFC_INVALID:
			WARNING("Invalid field category of \"%s\" at line %d",
				ofield->Identifier, ofield->_lineno);
			errno = EPERM;
			return NULL;
		case OFC_TYPE:
		case OFC_FIXED_TYPE_VALUE:
		case OFC_VARIABLE_TYPE_VALUE:
		case OFC_FIXED_TYPE_VALUE_SET:
		case OFC_VARIABLE_TYPE_VALUE_SET:
			if(!is_last_component) {
				FATAL("Field name component \"%s\" at line %d "
					"specifies non-dereferenceable thing",
					comp_name, ref->_lineno);
				errno = EPERM;
				return NULL;
			}
			break;
		case OFC_INFORMATION_OBJECT:
		case OFC_INFORMATION_OBJECT_SET:
			obj = ofield;
			break;
		}
	}

	assert(ofield);
	return ofield;
}
