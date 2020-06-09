#include "asn1fix_internal.h"

/*
 * Check the validity of an enumeration.
 */
int
asn1f_fix_enum(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *ev;
	asn1c_integer_t max_value = -1;
	asn1c_integer_t max_value_ext = -1;
	int rvalue = 0;
	asn1p_expr_t *ext_marker = NULL;	/* "..." position */
	int ret;

	/* Keep track of value collisions */
	asn1c_integer_t *used_vals;
	int used_vals_sz = 50;
	int used_vals_next = 0;

	if(expr->expr_type != ASN_BASIC_ENUMERATED)
		return 0;	/* Just ignore it */

	DEBUG("(%s)", expr->Identifier);

	used_vals = (asn1c_integer_t *) malloc(sizeof(asn1c_integer_t) * used_vals_sz);
	if (!used_vals) {
		FATAL("Out of memory");
		return -1;
	}

	/*
	 * 1. Scan the enumeration values in search for inconsistencies.
	 */
	TQ_FOR(ev, &(expr->members), next) {
		asn1c_integer_t eval;

		if(ev->value)
			DEBUG("\tItem %s(%s)", ev->Identifier,
				asn1f_printable_value(ev->value));
		else
			DEBUG("\tItem %s", ev->Identifier);

		/*
		 * 1.1 Found an extension mark "...", check correctness.
		 */
		if(ev->expr_type == A1TC_EXTENSIBLE) {
			if(ext_marker) {
				FATAL("Enumeration %s at line %d: "
				"Second extension marker is not allowed",
				expr->Identifier,
				ev->_lineno);
				rvalue = -1;
			} else {
				/*
				 * Remember the marker's position.
				 */
				ext_marker = ev;
			}
			continue;
		} else if(ev->Identifier == NULL
			|| ev->expr_type != A1TC_UNIVERVAL) {
			FATAL(
				"Enumeration %s at line %d: "
				"Unsupported enumeration element %s",
				expr->Identifier,
				ev->_lineno,
				ev->Identifier?ev->Identifier:"<anonymous>");
			rvalue = -1;
			continue;
		}

		/*
		 * 1.2 Compute the value of the enumeration element.
		 */
		if(ev->value) {
			switch(ev->value->type) {
			case ATV_INTEGER:
				eval = ev->value->value.v_integer;
				break;
			case ATV_REFERENCED:
				FATAL("HERE HERE HERE", 1);
				rvalue = -1;
				continue;
				break;
			default:
				FATAL("ENUMERATED type %s at line %d "
					"contain element %s(%s) at line %d",
					expr->Identifier, expr->_lineno,
					ev->Identifier,
					asn1f_printable_value(ev->value),
					ev->_lineno);
				rvalue = -1;
				continue;
			}
		} else {
			eval = max_value + 1;
			ev->value = asn1p_value_fromint(eval);
			if(ev->value == NULL) {
				rvalue = -1;
				continue;
			}
		}

		/*
		 * 1.3 Check the applicability of this value.
		 */

		/*
		 * Enumeration is allowed to be unordered
		 * before the first marker, but after the marker
		 * the values must be ordered.
		 */
		if (ext_marker) {
			if (eval > max_value_ext) {
				max_value_ext = eval;
			} else {
                char max_value_buf[128];
                asn1p_itoa_s(max_value_buf, sizeof(max_value_buf),
                             max_value_ext);
                FATAL(
					"Enumeration %s at line %d: "
					"Explicit value \"%s(%s)\" "
					"is not greater "
					"than previous values (max %s)",
					expr->Identifier,
					ev->_lineno,
					ev->Identifier,
					asn1p_itoa(eval),
					max_value_buf);
				rvalue = -1;
			}
		}

		if (eval > max_value) {
			max_value = eval;
		}


		/*
		 * 1.4 Check that all identifiers are unique
		 */
		int unique = 1;
		int uv_idx;
		for (uv_idx = 0; uv_idx < used_vals_next; uv_idx++) {
			if (used_vals[uv_idx] == eval) {
				FATAL(
					"Enumeration %s at line %d: "
					"Explicit value \"%s(%s)\" "
					"collides with previous values",
					expr->Identifier,
					ev->_lineno,
					ev->Identifier,
					asn1p_itoa(eval));
				rvalue = -1;
				unique = 0;
			}
		}

		if (unique) {
			/* Grow the array if needed */
			if (used_vals_next >= used_vals_sz) {
				asn1c_integer_t *temp;
				int new_sz = used_vals_sz + 50;
				temp = (asn1c_integer_t *) realloc(used_vals,
							sizeof(asn1c_integer_t) * new_sz);
				if (!temp) return -1;
				used_vals = temp;
				used_vals_sz = new_sz;
			}
			used_vals[used_vals_next++] = eval;
		}

		/*
		 * 1.5 Check that all identifiers before the current one
		 * differs from it.
		 */
		ret = asn1f_check_unique_expr_child(arg, ev, 0, "identifier");
		RET2RVAL(ret, rvalue);
	}

	free(used_vals);

	/*
	 * 2. Reorder the first half (before optional "...") of the
	 * identifiers alphabetically.
	 */
	// TODO

	return rvalue;
}

