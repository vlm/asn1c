#include "asn1fix_internal.h"

static int asn1f_check_same_children(arg_t *arg, asn1p_expr_t *a, asn1p_expr_t *b);

/*
 * Check that the expressions given are compatible in their type.
 * ORDER DOES MATTER! (See .h).
 */
int
asn1f_check_type_compatibility(arg_t *arg, asn1p_expr_t *a, asn1p_expr_t *b) {
	asn1p_expr_type_e atype, btype;

	atype = a->expr_type;
	btype = b->expr_type;

	DEBUG("(%s:%x@%d, %s:%x@%d)",
		a->Identifier, atype, a->_lineno,
		b->Identifier, btype, b->_lineno);

	/*
	 * Expected terminal type!
	 */
	assert(atype != A1TC_REFERENCE);
	assert(btype != A1TC_REFERENCE);

	if(a == b)
		return 0;	/* Fairly obviously */

	if(atype != btype) {
		/*
		 * Limited cross-compatibility of integer types.
		 */
		if((atype == A1TC_UNIVERVAL && btype == ASN_BASIC_INTEGER)
		|| (atype == A1TC_UNIVERVAL && btype == ASN_BASIC_ENUMERATED)
		)
			return 0;

		/* Limited cross-compatibility of string types */
		if((atype & ASN_STRING_MASK)
		&& (btype & ASN_STRING_MASK)) {
			/* X.680, B.5 */
			int akm = (atype & ASN_STRING_KM_MASK)
				|| atype == ASN_STRING_UTF8String;
			int bkm = (btype & ASN_STRING_KM_MASK)
				|| btype == ASN_STRING_UTF8String;
			return (akm == bkm) ? 0 : -1;
		}

		DEBUG("\t%s and %s are not compatible",
			a->Identifier, b->Identifier);
		return -1;	/* Fairly obviously */
	}

	switch(atype) {
	case ASN_BASIC_INTEGER:
		/* All integers are compatible, X.680, B.4.5 */
		return 0;
	case ASN_BASIC_ENUMERATED:
		/*
		 * Enumerations are not compatible
		 * unless their definitions are the same.
		 */
		if(asn1f_check_same_children(arg, a, b)) {
			DEBUG("\tEnumerations are different %s and %s",
				a->Identifier, b->Identifier);
			return -1;
		}
		return 0;
	default:
		if((atype & ASN_STRING_MASK)
		&& (btype & ASN_STRING_MASK)) {
			/* String type is compatible with the same type */
			return 0;
		}
		/* Compatibility is not defined yet */
		DEBUG("\tCompatibility rule is not defined for %s and %s",
			a->Identifier, b->Identifier);
		return -1;
	}

	return 0;
}

/*
 * Check that the children are exactly same.
 */
static int
asn1f_check_same_children(arg_t *arg, asn1p_expr_t *a, asn1p_expr_t *b) {
	asn1p_expr_t *achild;
	asn1p_expr_t *bchild;

	achild = TQ_FIRST(&(a->members));
	bchild = TQ_FIRST(&(b->members));

	while(1) {
		if(achild->expr_type != bchild->expr_type)
			return -1;

		if(achild->Identifier && bchild->Identifier) {
			if(strcmp(achild->Identifier, bchild->Identifier))
				return -1;
		} else if(!(!achild->Identifier && !bchild->Identifier)) {
			return -1;
		}

		if(achild->value && bchild->value) {
			if(achild->value->type != bchild->value->type)
				return -1;
			switch(achild->value->type) {
			case ATV_INTEGER:
				if(achild->value->value.v_integer
				!= bchild->value->value.v_integer)
					return -1;
				break;
			case ATV_REFERENCED:
			default:
				DEBUG("Value %s at lines %d and "
					"%d cannot be used in "
					"semantical equality check",
					asn1f_printable_value(achild->value),
					achild->value->value.reference->_lineno,
					bchild->value->value.reference->_lineno
				);
				return -1;
			}
		} else if(!(!achild->value && !bchild->value)) {
			/* One of values is defined, and another is not */
			return -1;
		}

		achild = TQ_NEXT(achild, next);
		bchild = TQ_NEXT(bchild, next);

		if(achild && bchild)
			continue;
		else if(!achild && !bchild)
			break;
		else
			return -1;
	}

	DEBUG("\t%s:%x@%d and %s:%x@%d are semantically equivalent",
		a->Identifier, a->expr_type, a->_lineno,
		b->Identifier, b->expr_type, b->_lineno);

	return 0;
}


