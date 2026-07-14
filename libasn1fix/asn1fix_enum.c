#include "asn1fix_internal.h"

/*
 * A growable set of enumeration values already in use.
 */
typedef struct used_vals_s {
	asn1c_integer_t *vals;
	int size;
	int next;
} used_vals_t;

static int
asn1f_enum_value_used(const used_vals_t *set, asn1c_integer_t val) {
	int i;
	for(i = 0; i < set->next; i++)
		if(set->vals[i] == val) return 1;
	return 0;
}

static int
asn1f_enum_value_add(used_vals_t *set, asn1c_integer_t val) {
	if(set->next >= set->size) {
		int new_sz = set->size + 50;
		asn1c_integer_t *temp = (asn1c_integer_t *)realloc(
			set->vals, sizeof(asn1c_integer_t) * new_sz);
		if(!temp) return -1;
		set->vals = temp;
		set->size = new_sz;
	}
	set->vals[set->next++] = val;
	return 0;
}

/*
 * Find the smallest non-negative integer value that is >= lower_bound
 * and does not already appear in the set of used values.
 *
 * Per X.680 (02/2021) 20.6, an ENUMERATED item without an explicit value
 * is assigned "the smallest available (unused) non-negative number as
 * enumeration value, respectively, in each case". "Unused" spans ALL
 * values of the enumeration, including explicit values declared AFTER
 * the item being numbered (the assignment is order-independent), which
 * is why the caller collects every explicit value in a first pass
 * before assigning automatic values in a second pass. Within the
 * extension root this scan simply starts at 0; among the extension
 * additions ("...") 20.4 also requires values to be strictly
 * increasing, which the caller enforces by passing a lower_bound
 * greater than the previous addition's value.
 */
static asn1c_integer_t
asn1f_enum_smallest_unused(asn1c_integer_t lower_bound,
		const used_vals_t *set) {
	asn1c_integer_t candidate = lower_bound < 0 ? 0 : lower_bound;

	while(asn1f_enum_value_used(set, candidate))
		candidate++;

	return candidate;
}

/*
 * Check the validity of an enumeration.
 */
int
asn1f_fix_enum(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *ev;
	asn1c_integer_t max_value_ext = -1;
	int rvalue = 0;
	asn1p_expr_t *ext_marker = NULL;	/* "..." position */
	int ret;

	/* Keep track of value collisions */
	used_vals_t used_vals;

	if(expr->expr_type != ASN_BASIC_ENUMERATED)
		return 0;	/* Just ignore it */

	DEBUG("(%s)", expr->Identifier);

	used_vals.size = 50;
	used_vals.next = 0;
	used_vals.vals = (asn1c_integer_t *)malloc(
		sizeof(asn1c_integer_t) * used_vals.size);
	if(!used_vals.vals) {
		FATAL("Out of memory");
		return -1;
	}

	/*
	 * 1. First pass: check the enumeration elements for consistency
	 * and collect the explicit values of the extension ROOT.
	 * X.680 (02/2021) 20.6 assigns each unnumbered root item the
	 * smallest unused non-negative value, where "unused" also covers
	 * root values declared later (e.g. in { a(5), b, c(0) } the
	 * value 0 is taken by c, so b gets 1) -- hence all explicit root
	 * values must be known before any automatic root value is
	 * assigned. Extension addition ("...") values are NOT collected
	 * here: the root is numbered as if the additions were absent,
	 * and an addition whose explicit value collides with a root
	 * value is an error, reported in the second pass. (the reference toolchain agrees:
	 * { red, green, ..., blue(1) } is rejected with green=1 taken,
	 * not silently renumbered to green=2.)
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
		 * 1.2 Check the type of the explicit value, if given.
		 * Unnumbered elements are handled in the second pass.
		 */
		if(!ev->value)
			continue;

		/*
		 * Extension addition values are collected in the second
		 * pass, after all automatic root values are assigned.
		 */
		if(ext_marker && ev->value->type == ATV_INTEGER)
			continue;

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

		/*
		 * 1.3 Check that all explicit values are unique.
		 */
		if(asn1f_enum_value_used(&used_vals, eval)) {
			FATAL(
				"Enumeration %s at line %d: "
				"Explicit value \"%s(%s)\" "
				"collides with previous values",
				expr->Identifier,
				ev->_lineno,
				ev->Identifier,
				asn1p_itoa(eval));
			rvalue = -1;
		} else if(asn1f_enum_value_add(&used_vals, eval)) {
			FATAL("Out of memory");
			free(used_vals.vals);
			return -1;
		}
	}

	/*
	 * 2. Second pass: assign automatic values to the unnumbered
	 * elements (in declaration order) and check value ordering
	 * after the extension marker.
	 */
	ext_marker = NULL;
	TQ_FOR(ev, &(expr->members), next) {
		asn1c_integer_t eval;

		if(ev->expr_type == A1TC_EXTENSIBLE) {
			if(!ext_marker) ext_marker = ev;
			continue;
		} else if(ev->Identifier == NULL
			|| ev->expr_type != A1TC_UNIVERVAL) {
			continue;	/* Already complained in pass 1 */
		}

		if(ev->value) {
			if(ev->value->type != ATV_INTEGER)
				continue;	/* Already complained */
			eval = ev->value->value.v_integer;
			if(ext_marker) {
				/*
				 * Extension addition with an explicit value:
				 * check it against the root values, the
				 * automatic values and the previous addition
				 * values, all of which are in the set by now.
				 */
				if(asn1f_enum_value_used(&used_vals, eval)) {
					FATAL(
						"Enumeration %s at line %d: "
						"Explicit value \"%s(%s)\" "
						"collides with previous values",
						expr->Identifier,
						ev->_lineno,
						ev->Identifier,
						asn1p_itoa(eval));
					rvalue = -1;
				} else if(asn1f_enum_value_add(&used_vals,
						eval)) {
					FATAL("Out of memory");
					free(used_vals.vals);
					return -1;
				}
			}
		} else {
			/*
			 * Automatic numbering: smallest unused non-negative
			 * value (X.680 20.6). After the extension marker,
			 * values must also be strictly greater than the
			 * previous enumeration item's value (20.4), so the
			 * search starts at max_value_ext + 1 in that case.
			 */
			asn1c_integer_t lower_bound =
				ext_marker ? (max_value_ext + 1) : 0;
			eval = asn1f_enum_smallest_unused(lower_bound,
				&used_vals);
			ev->value = asn1p_value_fromint(eval);
			if(ev->value == NULL) {
				rvalue = -1;
				continue;
			}
			if(asn1f_enum_value_add(&used_vals, eval)) {
				FATAL("Out of memory");
				free(used_vals.vals);
				return -1;
			}
		}

		/*
		 * 2.1 Enumeration is allowed to be unordered
		 * before the first marker, but after the marker
		 * the values must be ordered.
		 */
		if(ext_marker) {
			if(eval > max_value_ext) {
				max_value_ext = eval;
			} else {
				char max_value_buf[128];
				asn1p_itoa_s(max_value_buf,
					sizeof(max_value_buf),
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

		/*
		 * 2.2 Check that all identifiers before the current one
		 * differs from it.
		 */
		ret = asn1f_check_unique_expr_child(arg, ev, 0, "identifier");
		RET2RVAL(ret, rvalue);
	}

	free(used_vals.vals);

	/*
	 * 3. Reorder the first half (before optional "...") of the
	 * identifiers alphabetically.
	 */
	// TODO

	return rvalue;
}
