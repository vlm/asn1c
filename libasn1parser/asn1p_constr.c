#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

asn1p_constraint_t *
asn1p_constraint_new(int _lineno) {
	asn1p_constraint_t *ct;

	ct = calloc(1, sizeof(*ct));
	if(ct) {
		ct->_lineno = _lineno;
	}

	return ct;
}


void
asn1p_constraint_free(asn1p_constraint_t *ct) {
	if(ct) {

		if(ct->containedSubtype)
			asn1p_value_free(ct->containedSubtype);
		if(ct->value)
			asn1p_value_free(ct->value);
		if(ct->range_start)
			asn1p_value_free(ct->range_start);
		if(ct->range_stop)
			asn1p_value_free(ct->range_stop);

		if(ct->elements) {
			while(ct->el_count--) {
				asn1p_constraint_free(
					ct->elements[ct->el_count]);
			}
			free(ct->elements);
		}

		free(ct);
	}
}

asn1p_constraint_t *
asn1p_constraint_clone(asn1p_constraint_t *src) {
	asn1p_constraint_t *clone;

#define	CLONE(field, func)	do { if(src->field) {		\
			clone->field = func(src->field);	\
			if(clone->field == NULL) {		\
				asn1p_constraint_free(clone);	\
				return NULL;			\
			}					\
		} } while(0)

	clone = asn1p_constraint_new(src->_lineno);
	if(clone) {
		unsigned int i;

		clone->type = src->type;
		clone->presence = src->presence;
		CLONE(containedSubtype,	asn1p_value_clone);
		CLONE(value,		asn1p_value_clone);
		CLONE(range_start,	asn1p_value_clone);
		CLONE(range_stop,	asn1p_value_clone);

		for(i = 0; i < src->el_count; i++) {
			asn1p_constraint_t *t;
			t = asn1p_constraint_clone(src->elements[i]);
			if(!t) {
				asn1p_constraint_free(clone);
				return NULL;
			}
			if(asn1p_constraint_insert(clone, t)) {
				asn1p_constraint_free(clone);
				asn1p_constraint_free(t);
				return NULL;
			}
		}
		assert(clone->el_count == src->el_count);
		clone->_lineno = src->_lineno;
	}

	return clone;
}

int
asn1p_constraint_insert(asn1p_constraint_t *into, asn1p_constraint_t *what) {
	assert(into);
	assert(what);

	/*
	 * Make sure there's enough space to add an element.
	 */
	if(into->el_count == into->el_size) {
		unsigned int newsize = into->el_size?into->el_size<<2:4;
		void *p;
		p = realloc(into->elements,
			newsize * sizeof(into->elements[0]));
		if(p) {
			into->elements = p;
			into->el_size = newsize;
		} else {
			return -1;
		}
	}

	into->elements[into->el_count++] = what;

	return 0;
}


char *
asn1p_constraint_type2str(enum asn1p_constraint_type_e type) {
	switch(type) {
	case ACT_INVALID:
		return "INVALID";
	case ACT_EL_TYPE:
		return "ContainedSubtype";
	case ACT_EL_VALUE:
		return "SingleValue";
	case ACT_EL_RANGE:
	case ACT_EL_LLRANGE:
	case ACT_EL_RLRANGE:
	case ACT_EL_ULRANGE:
		return "ValueRange";
	case ACT_EL_EXT:
		return "...";
	case ACT_CT_SIZE:
		return "SizeConstraint";
	case ACT_CT_FROM:
		return "PermittedAlphabet";
	case ACT_CT_WCOMP:
		return "SingleTypeConstraint";
	case ACT_CT_WCOMPS:
		return "MultipleTypeConstraints";
	case ACT_CT_CTDBY:
		return "UserDefinedConstraint";
	case ACT_CA_SET:
		return "SET";
	case ACT_CA_CRC:
		return "ComponentRelationConstraint";
	case ACT_CA_CSV:
		return "CSV";
	case ACT_CA_UNI:
		return "UNION";
	case ACT_CA_INT:
		return "INTERSECTION";
	case ACT_CA_EXC:
		return "EXCEPT";
	case ACT_CA_AEX:
		return "ALL EXCEPT";
	}
	return "UNKNOWN";
}
