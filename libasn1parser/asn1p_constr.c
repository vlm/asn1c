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
		clone->type = src->type;
		CLONE(value, asn1p_value_clone);
		CLONE(range_start, asn1p_value_clone);
		CLONE(range_stop, asn1p_value_clone);
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
		int newsize = into->el_size?into->el_size<<2:4;
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
