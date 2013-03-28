#include "asn1fix_internal.h"
#include "asn1fix_constraint.h"
#include "asn1fix_crange.h"

#undef	FATAL
#define	FATAL(fmt, args...)	do {			\
		fprintf(stderr, "FATAL: ");		\
		fprintf(stderr, fmt, ##args);		\
		fprintf(stderr, "\n");			\
	} while(0)

void
asn1constraint_range_free(asn1cnst_range_t *cr) {
	if(cr) {
		int i;
		if(cr->elements) {
			for(i = 0; i < cr->el_count; i++)
				asn1constraint_range_free(cr->elements[i]);
			free(cr->elements);
		}
		free(cr);
	}
}
#define	_range_free(foo)	asn1constraint_range_free(foo)

static asn1cnst_range_t *_range_new() {
	asn1cnst_range_t *r;
	r = calloc(1, sizeof(*r));
	if(r) {
		r->left.type = ARE_MIN;
		r->right.type = ARE_MAX;
	}
	return r;
}

static void _range_remove_element(asn1cnst_range_t *range, int idx) {
	assert(idx >= 0 && idx < range->el_count);

	assert(!range->elements[idx]->elements);

	_range_free(range->elements[idx]);

	memmove(&range->elements[idx],
		&range->elements[idx + 1],
		(range->el_count - idx - 1)
			* sizeof(range->elements[0])
	);
	range->el_count--;
	range->elements[range->el_count] = 0;	/* JIC */

	if(range->el_count == 0) {
		range->el_size = 0;
		free(range->elements);
		range->elements = 0;
	}
}

static int _range_insert(asn1cnst_range_t *into, asn1cnst_range_t *cr) {

	assert(!cr->elements);

	if(into->el_count == into->el_size) {
		void *p;
		int n = into->el_size?(into->el_size << 1):4;
		p = realloc(into->elements, n * sizeof(into->elements[0]));
		if(p) {
			into->el_size = n;
			into->elements = p;
		} else {
			assert(p);
			return -1;
		}
	}

	into->elements[into->el_count++] = cr;
	return 0;
}

static asn1cnst_range_t *_range_clone(const asn1cnst_range_t *range) {
	asn1cnst_range_t *clone;
	int i;

	clone = _range_new();
	if(!clone) return NULL;

	*clone = *range;
	clone->elements = 0;
	clone->el_count = 0;
	clone->el_size = 0;

	for(i = 0; i < range->el_count; i++) {
		asn1cnst_range_t *r = _range_clone(range->elements[i]);
		if(!r || _range_insert(clone, r)) {
			_range_free(clone);
			_range_free(r);
			return NULL;
		}
	}

	return clone;
}

static int
_edge_compare(const asn1cnst_edge_t *el, const asn1cnst_edge_t *er) {

	switch(el->type) {
	case ARE_MIN:
		switch(er->type) {
		case ARE_MIN: return 0;
		case ARE_MAX: return -1;
		case ARE_VALUE: return -1;
		}
		break;
	case ARE_MAX:
		switch(er->type) {
		case ARE_MIN: return 1;
		case ARE_MAX: return 0;
		case ARE_VALUE: return 1;
		}
		break;
	case ARE_VALUE:
		switch(er->type) {
		case ARE_MIN: return 1;
		case ARE_MAX: return -1;
		case ARE_VALUE:
			if(el->value < er->value)
				return -1;
			if(el->value > er->value)
				return 1;
			return 0;
		}
		break;
	}

	return 0;
}

static int
_range_compare(const void *a, const void *b) {
	const asn1cnst_range_t *ra = *(const asn1cnst_range_t * const *)a;
	const asn1cnst_range_t *rb = *(const asn1cnst_range_t * const *)b;
	int ret;

	ret = _edge_compare(&ra->left, &rb->left);
	if(!ret) {
		ret = _edge_compare(&ra->right, &rb->right);
	}

	return ret;
}

static char *
_edge_value(const asn1cnst_edge_t *edge) {
	static char buf[128];
	*buf = '\0';
	switch(edge->type) {
	case ARE_MIN:	strcpy(buf, "MIN"); break;
	case ARE_MAX:	strcpy(buf, "MAX"); break;
	case ARE_VALUE:
		snprintf(buf, sizeof(buf), "%" PRIdASN, edge->value);
	}
	return buf;
}

static int
_edge_is_within(const asn1cnst_range_t *range, const asn1cnst_edge_t *edge) {
	int i;

	for(i = -1; i < range->el_count; i++) {
		const asn1cnst_range_t *r;
		if(i == -1) {
			if(range->el_count) continue;
			r = range;
		} else {
			r = range->elements[i];
		}
		if(_edge_compare(&r->left, edge) <= 0
		&& _edge_compare(&r->right, edge) >= 0)
			return 1;
	}

	return 0;
}

static int
_check_edges_within(const asn1cnst_range_t *range, const asn1cnst_range_t *r) {

	if(!_edge_is_within(range, &r->left)) {
		FATAL("Constraint value %s at line %d "
			"is not within "
			"a parent constraint range",
			_edge_value(&r->left),
			r->left.lineno
		);
		return -1;
	}

	if(!_edge_is_within(range, &r->right)) {
		FATAL("Constraint value %s at line %d "
			"is not within "
			"a parent constraint range",
			_edge_value(&r->right),
			r->right.lineno
		);
		return -1;
	}

	return 0;
}

static int _range_merge_in(asn1cnst_range_t *into, asn1cnst_range_t *cr) {
	asn1cnst_range_t *r;
	int prev_count = into->el_count;
	int i;

	into->not_PER_visible |= cr->not_PER_visible;
	into->extensible |= cr->extensible;

	/*
	 * Add the element OR all its children "into".
	 */
	for(i = -1; i < cr->el_count; i++) {

		if(i == -1) {
			if(cr->el_count) continue;
			r = cr;
		} else {
			r = cr->elements[i];
		}

		if(_range_insert(into, r)) {
			into->el_count = prev_count;	/* Undo */
			return -1;
		}
	}

	if(cr->el_count) {
		cr->el_count = 0;
		_range_free(cr);
	} else {
		/* This range is linked into "into". */
	}

	return 0;
}

static int _range_fill(asn1p_value_t *val, const asn1cnst_range_t *minmax, asn1cnst_edge_t *edge, asn1cnst_range_t *range, enum asn1p_constraint_type_e type, int lineno) {
	unsigned char *p, *pend;

	edge->lineno = lineno;

	switch(val->type) {
	case ATV_INTEGER:
		if(type != ACT_EL_RANGE && type != ACT_CT_SIZE) {
			FATAL("Integer %" PRIdASN " value invalid "
				"for %s constraint at line %d",
				val->value.v_integer,
				asn1p_constraint_type2str(type), lineno);
			return -1;
		}
		edge->type = ARE_VALUE;
		edge->value = val->value.v_integer;
		return 0;
	case ATV_MIN:
		if(type != ACT_EL_RANGE && type != ACT_CT_SIZE) {
			FATAL("MIN invalid for %s constraint at line %d",
				asn1p_constraint_type2str(type), lineno);
			return -1;
		}
		edge->type = ARE_MIN;
		if(minmax) *edge = minmax->left;
		edge->lineno = lineno;	/* Restore lineno */
		return 0;
	case ATV_MAX:
		if(type != ACT_EL_RANGE && type != ACT_CT_SIZE) {
			FATAL("MAX invalid for %s constraint at line %d",
				asn1p_constraint_type2str(type), lineno);
			return -1;
		}
		edge->type = ARE_MAX;
		if(minmax) *edge = minmax->right;
		edge->lineno = lineno;	/* Restore lineno */
		return 0;
	case ATV_FALSE:
	case ATV_TRUE:
		if(type != ACT_EL_RANGE) {
			FATAL("%s is invalid for %s constraint at line %d",
				val->type==ATV_TRUE?"TRUE":"FALSE",
				asn1p_constraint_type2str(type),
				lineno);
			return -1;
		}
		edge->type = ARE_VALUE;
		edge->value = (val->type==ATV_TRUE);
		return 0;
	case ATV_TUPLE:
	case ATV_QUADRUPLE:
		edge->type = ARE_VALUE;
		edge->value = val->value.v_integer;
		return 0;
	case ATV_STRING:
		if(type != ACT_CT_FROM)
			return 0;
		break;
	case ATV_REFERENCED:
		FATAL("Unresolved constraint element \"%s\" at line %d",
			asn1f_printable_reference(val->value.reference),
			lineno);
		return -1;
	default:
		FATAL("Unrecognized constraint element at line %d",
			lineno);
		return -1;
	}

	assert(val->type == ATV_STRING);

	p = val->value.string.buf;
	pend = p + val->value.string.size;
	if(p == pend) return 0;

	edge->type = ARE_VALUE;
	if(val->value.string.size == 1) {
		edge->value = *p;
	} else {
		/*
		 * Else this is a set:
		 * (FROM("abcdef"))
		 * However, (FROM("abc".."def")) is forbidden.
		 * See also 47.4.4.
		 */
		asn1c_integer_t vmin, vmax;
		vmin = vmax = *p;
		for(; p < pend; p++) {
			asn1cnst_range_t *nr = _range_new();
			int ret;
			assert(nr);

			if(*p < vmin) vmin = *p;
			if(*p > vmax) vmax = *p;

			ret = _range_insert(range, nr);
			assert(ret == 0);

			nr->left.type = ARE_VALUE;
			nr->left.value = *p;
			nr->left.lineno = lineno;
			nr->right = nr->left;
		}
		edge->value = (edge == &range->right) ? vmin : vmax;
	}

	return 0;
}

/*
 * Check if ranges contain common elements.
 */
static int
_range_overlap(const asn1cnst_range_t *ra, const asn1cnst_range_t *rb) {
	int lr, rl;
	const asn1cnst_edge_t *ra_l = &ra->left;
	const asn1cnst_edge_t *ra_r = &ra->right;
	const asn1cnst_edge_t *rb_l = &rb->left;
	const asn1cnst_edge_t *rb_r = &rb->right;

	assert(_edge_compare(ra_l, ra_r) <= 0);
	assert(_edge_compare(rb_l, rb_r) <= 0);

	lr = _edge_compare(ra_l, rb_r);
	rl = _edge_compare(ra_r, rb_l);

	/*
	 * L:       |---|
	 * R: |---|
	 */
	if(lr > 0) return 0;

	/*
	 * L: |---|
	 * R:       |---|
	 */
	if(rl < 0) return 0;

	return 1;
}

/*
 * (MIN..20) x (10..15) = (MIN..9,10..15,16..20)
 */
static asn1cnst_range_t *
_range_split(asn1cnst_range_t *ra, const asn1cnst_range_t *rb) {
	asn1cnst_range_t *range, *nr;
	int ll, rr;

	assert(ra);
	assert(rb);
	assert(!ra->el_count);
	assert(!rb->el_count);

	if(!_range_overlap(ra, rb)) {
		errno = 0;
		return 0;
	}

	ll = _edge_compare(&ra->left, &rb->left);
	rr = _edge_compare(&ra->right, &rb->right);

	/*
	 * L:   |---|
	 * R: |-------|
	 */
	if(ll >= 0 && rr <= 0) {
		errno = 0;
		return 0;
	}

	range = _range_new();
	assert(range);

	nr = _range_new();
	assert(nr);

	/*
	 * L: |---...
	 * R:   |--..
	 */
	while(ll < 0) {
		nr->left = ra->left;
		nr->right = rb->left;
		if(nr->right.type == ARE_VALUE) {
			if(nr->right.value - 1 >= nr->right.value) {
				/* We've hit the limit here. */
				break;
			}
			nr->right.value--;
		}
		_range_insert(range, nr);
		nr = _range_new();
		assert(nr);
		break;
	}

	/*
	 * L: ...---|
	 * R: ..--|
	 */
	while(rr > 0) {
		nr->left = rb->right;
		nr->right = ra->right;
		if(nr->left.type == ARE_VALUE) {
			if(nr->left.value + 1 <= nr->left.value) {
				/* We've hit the limit here. */
				break;
			}
			nr->left.value++;
		}
		_range_insert(range, nr);
		nr = _range_new();
		assert(nr);
		break;
	}

	/*
	 * L:  |---|
	 * R: |-----|
	 */
	nr->left = ra->left;
	nr->right = ra->right;
	if(_edge_compare(&ra->left, &rb->left) < 0)
		nr->left = rb->left;
	if(_edge_compare(&ra->right, &rb->right) > 0)
		nr->right = rb->right;

	_range_insert(range, nr);

	return range;
}

static int
_range_intersection(asn1cnst_range_t *range, const asn1cnst_range_t *with, int strict_edge_check) {
	int ret;
	int i, j;

	assert(!range->incompatible);

	/* Propagate errors */
	range->extensible |= with->extensible;
	range->not_PER_visible |= with->not_PER_visible;
	range->empty_constraint |= with->empty_constraint;

	if(range->empty_constraint) {
		/* No use in intersecting empty constraints */
		return 0;
	}

	/*
	 * This is an AND operation.
	 */

	/* If this is the only element, insert it into itself as a child */
	if(range->el_count == 0) {
		asn1cnst_range_t *r = _range_new();
		r->left = range->left;
		r->right = range->right;
		_range_insert(range, r);
		assert(range->el_count == 1);
	}

	/*
	 * Make sure we're dealing with sane data.
	 * G.4.2.3
	 */
	if(strict_edge_check) {
		for(j = -1; j < with->el_count; j++) {

			if(j == -1) {
				if(with->el_count) continue;
				if(_check_edges_within(range, with))
					return -1;
			} else {
				if(_check_edges_within(range,
						with->elements[j]))
					return -1;
			}
		}
	}

	/*
	 * Split range in pieces.
	 */

	for(i = 0; i < range->el_count; i++) {
	  for(j = -1; j < with->el_count; j++) {
		const asn1cnst_range_t *wel;
		asn1cnst_range_t *r;

		if(j == -1) {
			if(with->el_count) continue;
			wel = with;
		} else {
			wel = with->elements[j];
			assert(!wel->el_count);	/* non-compound item! */
		}

		r = _range_split(range->elements[i], wel);
		if(r) {
			int ec;
			/* Substitute the current element with a split */
			_range_remove_element(range, i);
			assert(r->el_count);
			for(ec = 0; ec < r->el_count; ec++) {
				ret = _range_insert(range, r->elements[ec]);
				assert(ret == 0);
			}
			r->el_count = 0;
			_range_free(r);
			i--;
			break;	/* Try again from this point */
		}
	  }
	}

	assert(range->el_count);

	/*
	 * Remove pieces which aren't AND-compatible "with" range.
	 */

	for(i = 0; i < range->el_count; i++) {
		for(j = -1; j < with->el_count; j++) {
			const asn1cnst_range_t *wel;
	
			if(j == -1) {
				if(with->el_count) continue;
				wel = with;
			} else {
				wel = with->elements[j];
			}

			if(_range_overlap(range->elements[i], wel))
				break;
		}
		if(j == with->el_count) {
			_range_remove_element(range, i);
			i--;
		}
	}

	if(range->el_count == 0)
		range->empty_constraint = 1;

	return 0;
}

static int
_range_union(asn1cnst_range_t *range) {
	int i;

	qsort(range->elements, range->el_count, sizeof(range->elements[0]),
		_range_compare);

	/*
	 * The range is sorted by the start values.
	 */
	for(i = 1; i < range->el_count; i++) {
		asn1cnst_range_t *ra = range->elements[i - 1];
		asn1cnst_range_t *rb = range->elements[i];

		if(_range_overlap(ra, rb)) {
			if(_edge_compare(&ra->left, &rb->left) < 0)
				rb->left = ra->left;

			if(_edge_compare(&ra->right, &rb->right) > 0)
				rb->right = ra->right;
		} else {
			/*
			 * Still, range may be joined: (1..4)(5..10).
			 * This logic is valid only for whole numbers
			 * (i.e., not REAL type, but REAL constraints
			 * are not PER-visible (X.691, #9.3.12).
			 */
			if(ra->right.type == ARE_VALUE
			&& rb->left.type == ARE_VALUE
			&& (rb->left.value - ra->right.value) == 1) {
				/* (1..10) */
				rb->left = ra->left;
			} else {
				continue;
			}
		}

		/*
		 * Squeeze the array by removing the ra.
		 */
		_range_remove_element(range, i - 1);

		i--;	/* Retry from the current point */
	}

	return 0;
}

static int
_range_canonicalize(asn1cnst_range_t *range) {

	if(range->el_count == 0) {
		/*
		 * Switch left and right edges, make them sorted.
		 * It might be a mild warning though.
		 */
		if(_edge_compare(&range->left, &range->right) > 0) {
			asn1cnst_edge_t tmp = range->left;
			range->left = range->right;
			range->right = tmp;
		}

		if(range->elements) {
			free(range->elements);
			range->elements = 0;
		}
		range->el_size = 0;
		return 0;
	}

	/*
	 * Remove duplicates and overlaps by merging them in.
	 */
	_range_union(range);

	/* Refine the left edge of a parent */
	range->left = range->elements[0]->left;

	/* Refine the right edge of a parent */
	range->right = range->elements[range->el_count - 1]->right;

	/* Remove the child, if it's a single one */
	if(range->el_count == 1) {
		_range_remove_element(range, 0);
	}

	return 0;
}

asn1cnst_range_t *
asn1constraint_compute_PER_range(asn1p_expr_type_e expr_type, const asn1p_constraint_t *ct, enum asn1p_constraint_type_e type, const asn1cnst_range_t *minmax, int *exmet, enum cpr_flags cpr_flags) {
	asn1cnst_range_t *range;
	asn1cnst_range_t *tmp;
	asn1p_value_t *vmin;
	asn1p_value_t *vmax;
	int expectation_met;
	unsigned int i;
	int ret;

	if(!exmet) {
		exmet = &expectation_met;
		*exmet = 0;
	}

	/*
	 * Check if the requested constraint is theoretically compatible
	 * with the given expression type.
	 */
	if(asn1constraint_compatible(expr_type, type,
			cpr_flags & CPR_simulate_fbless_SIZE) != 1) {
		errno = EINVAL;
		return 0;
	}

	/* Check arguments' validity. */
	switch(type) {
	case ACT_EL_RANGE:
		if(exmet == &expectation_met)
			*exmet = 1;
		break;
	case ACT_CT_FROM:
		if(!minmax) {
			minmax = asn1constraint_default_alphabet(expr_type);
			if(minmax) {
				break;
			}
		}
		/* Fall through */
	case ACT_CT_SIZE:
		if(!minmax) {
			static asn1cnst_range_t mm;
			mm.left.type = ARE_VALUE;
			mm.left.value = 0;
			mm.right.type = ARE_MAX;
			minmax = &mm;
		}
		break;
	default:
		errno = EINVAL;
		return 0;
	}

	if(minmax) {
		range = _range_clone(minmax);
	} else {
		range = _range_new();
	}

	/*
	 * X.691, #9.3.6
	 * Constraints on restricter character string types
	 * which are not known-multiplier are not PER-visible.
	 */
	if((expr_type & ASN_STRING_NKM_MASK))
		range->not_PER_visible = 1;

	if(!ct
	|| (range->not_PER_visible && (cpr_flags & CPR_strict_PER_visibility)))
		return range;

	switch(ct->type) {
	case ACT_EL_VALUE:
		vmin = vmax = ct->value;
		break;
	case ACT_EL_RANGE:
	case ACT_EL_LLRANGE:
	case ACT_EL_RLRANGE:
	case ACT_EL_ULRANGE:
		vmin = ct->range_start;
		vmax = ct->range_stop;
		break;
	case ACT_EL_EXT:
		if(!*exmet) {
			range->incompatible = 1;
		} else {
			_range_free(range);
			errno = ERANGE;
			range = 0;
		}
		return range;
	case ACT_CT_SIZE:
	case ACT_CT_FROM:
		if(type == ct->type) {
			*exmet = 1;
		} else {
			range->incompatible = 1;
			return range;
		}
		assert(ct->el_count == 1);
		tmp = asn1constraint_compute_PER_range(expr_type,
			ct->elements[0], type, minmax, exmet, cpr_flags);
		if(tmp) {
			_range_free(range);
		} else {
			if(errno == ERANGE) {
				range->empty_constraint = 1;
				range->extensible = 1;
				tmp = range;
			} else {
				_range_free(range);
			}
		}
		return tmp;
	case ACT_CA_SET:	/* (10..20)(15..17) */
	case ACT_CA_INT:	/* SIZE(1..2) ^ FROM("ABCD") */

		/* AND constraints, one after another. */
		for(i = 0; i < ct->el_count; i++) {
			tmp = asn1constraint_compute_PER_range(expr_type,
				ct->elements[i], type,
				ct->type==ACT_CA_SET?range:minmax, exmet,
				cpr_flags);
			if(!tmp) {
				if(errno == ERANGE) {
					continue;
				} else {
					_range_free(range);
					return NULL;
				}
			}

			if(tmp->incompatible) {
				/*
				 * Ignore constraints
				 * incompatible with arguments:
				 * 	SIZE(1..2) ^ FROM("ABCD")
				 * either SIZE or FROM will be ignored.
				 */
				_range_free(tmp);
				continue;
			}

			if(tmp->not_PER_visible
			&& (cpr_flags & CPR_strict_PER_visibility)) {
				if(ct->type == ACT_CA_SET) {
					/*
					 * X.691, #9.3.18:
					 * Ignore this separate component.
					 */
				} else {
					/*
					 * X.691, #9.3.19:
					 * Ignore not PER-visible INTERSECTION
					 */
				}
				_range_free(tmp);
				continue;
			}

			ret = _range_intersection(range, tmp,
				ct->type == ACT_CA_SET);
			_range_free(tmp);
			if(ret) {
				_range_free(range);
				errno = EPERM;
				return NULL;
			}
			_range_canonicalize(range);
		}

		return range;
	case ACT_CA_CSV:	/* SIZE(1..2, 3..4) */
	case ACT_CA_UNI:	/* SIZE(1..2) | FROM("ABCD") */

		/*
		 * Grab the first valid constraint.
		 */
		tmp = 0;
		for(i = 0; i < ct->el_count; i++) {
			tmp = asn1constraint_compute_PER_range(expr_type,
				ct->elements[i], type, minmax, exmet,
				cpr_flags);
			if(!tmp) {
				if(errno == ERANGE) {
					range->extensible = 1;
					continue;
				} else {
					_range_free(range);
					return NULL;
				}
			}
			if(tmp->incompatible) {
				_range_free(tmp);
				tmp = 0;
			}
			break;
		}
		if(tmp) {
			tmp->extensible |= range->extensible;
			tmp->empty_constraint |= range->empty_constraint;
			_range_free(range);
			range = tmp;
		} else {
			range->incompatible = 1;
			return range;
		}

		/*
		 * Merge with the rest of them.
		 * Canonicalizator will do the union magic.
		 */
		for(; i < ct->el_count; i++) {
			tmp = asn1constraint_compute_PER_range(expr_type,
				ct->elements[i], type, minmax, exmet,
				cpr_flags);
			if(!tmp) {
				if(errno == ERANGE) {
					range->extensible = 1;
					continue;
				} else {
					_range_free(range);
					return NULL;
				}
			}

			if(tmp->incompatible) {
				_range_free(tmp);
				_range_canonicalize(range);
				range->incompatible = 1;
				return range;
			}

			if(tmp->empty_constraint) {
				/*
				 * Ignore empty constraints in OR logic.
				 */
				range->extensible |= tmp->extensible;
				_range_free(tmp);
				continue;
			}

			_range_merge_in(range, tmp);
		}

		_range_canonicalize(range);

		if(range->extensible && type == ACT_CT_FROM) {
			/*
			 * X.691, #9.3.10:
			 * Extensible permitted alphabet constraints
			 * are not PER-visible.
			 */
			range->not_PER_visible = 1;
		}

		if(range->not_PER_visible
		&& (cpr_flags & CPR_strict_PER_visibility)) {
			/*
			 * X.691, #9.3.19:
			 * If not PER-visible constraint is part of UNION,
			 * the whole resulting constraint is not PER-visible.
			 */
			_range_free(range);
			if(minmax)
				range = _range_clone(minmax);
			else
				range = _range_new();
			range->not_PER_visible = 1;
			range->incompatible = 1;
		}

		return range;
	case ACT_CA_EXC:	/* FROM("ABCD") EXCEPT FROM("AB") */
		/*
		 * X.691, #9.3.19:
		 * EXCEPT and the following value set is completely ignored.
		 */
		assert(ct->el_count >= 1);
		_range_free(range);
		range = asn1constraint_compute_PER_range(expr_type,
			ct->elements[0], type, minmax, exmet, cpr_flags);
		return range;
	default:
		range->incompatible = 1;
		return range;
	}


	if(!*exmet) {
		/*
		 * Expectation is not met. Return the default range.
		 */
		range->incompatible = 1;
		return range;
	}

	_range_free(range);
	range = _range_new();

	ret  = _range_fill(vmin, minmax, &range->left,
				range, type, ct->_lineno);
	if(!ret)
	ret = _range_fill(vmax, minmax, &range->right,
				range, type, ct->_lineno);
	if(ret) {
		_range_free(range);
		errno = EPERM;
		return NULL;
	}

	if(minmax) {
		asn1cnst_range_t *clone;

		clone = _range_clone(minmax);

		/* Constrain parent type with given data. */
		ret = _range_intersection(clone, range, 1);
		_range_free(range);
		if(ret) {
			_range_free(clone);
			errno = EPERM;
			return NULL;
		}
		range = clone;
	}

	/*
	 * Recompute elements's min/max, remove duplicates, etc.
	 */
	_range_canonicalize(range);

	return range;
}

