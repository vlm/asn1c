#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

void
asn1p_constraint_set_source(asn1p_constraint_t *ct,
                            struct asn1p_module_s *module, int lineno) {
    if(ct) {
        ct->module = module;
        ct->_lineno = lineno;
        asn1p_value_set_source(ct->containedSubtype,module,lineno);
        asn1p_value_set_source(ct->value,module,lineno);
        asn1p_value_set_source(ct->range_start,module,lineno);
        asn1p_value_set_source(ct->range_stop,module,lineno);
        for(size_t i = 0; i < ct->el_count; i++) {
            asn1p_constraint_set_source(ct->elements[i], module, lineno);
        }
    }
}

/*
 * Safely extract the reference that an ACT_EL_TYPE (contained subtype)
 * constraint points to, e.g. the VALUESET reference in (VALUE-SET-A).
 * Returns NULL if the constraint does not carry such a reference, guarding
 * against the various intermediate NULL pointers so the comparison never
 * dereferences uninitialized constraint shapes.
 */
static const asn1p_ref_t *
constraint_ref(const asn1p_constraint_t *ct) {
    const asn1p_value_t *cs = ct->containedSubtype;
    if(cs && cs->type == ATV_REFERENCED)
        return cs->value.reference;
    if(cs && cs->type == ATV_TYPE && cs->value.v_type)
        return cs->value.v_type->reference;
    return NULL;
}

int asn1p_constraint_compare(const asn1p_constraint_t *a,
                             const asn1p_constraint_t *b) {
    assert((a && b));

    if(a->type != b->type)
        return -1;

    /*
     * Currently we only distinguish VALUESET expressed as a reference to
     * a contained subtype, e.g. (VALUE-SET-A) vs (VALUE-SET-B). This is
     * enough to make asn1f_parameterization_fork() fork parameterizations
     * that differ only by their VALUESET reference (CVE-2025-32893),
     * so the associated information object tables are generated for each
     * distinct value set instead of being silently deduplicated.
     */
    if(a->type == ACT_EL_TYPE) {
        const asn1p_ref_t *ra = constraint_ref(a);
        const asn1p_ref_t *rb = constraint_ref(b);

        /*
         * If either side is not a plain reference (or the reference does
         * not carry a comparable component name), fall back to treating
         * the constraints as comparable-equal rather than dereferencing a
         * NULL pointer or asserting. We only special-case the shape we
         * positively recognize.
         */
        if(ra && rb) {
            if(ra->comp_count == 0 || rb->comp_count == 0
               || !ra->components[0].name || !rb->components[0].name)
                return 0;
            return strcmp(ra->components[0].name, rb->components[0].name);
        }
        /* One has a reference and the other does not -> different. */
        if(ra || rb)
            return -1;
        return 0;
    }

    return 0;
}

asn1p_constraint_t *
asn1p_constraint_new(int _lineno, asn1p_module_t *mod) {
	asn1p_constraint_t *ct;

	ct = calloc(1, sizeof(*ct));
	if(ct) {
		ct->_lineno = _lineno;
		ct->module = mod;
	}

	return ct;
}


void
asn1p_constraint_free(asn1p_constraint_t *ct) {
	if(ct) {

		asn1p_value_free(ct->containedSubtype);
		asn1p_value_free(ct->value);
		asn1p_value_free(ct->range_start);
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
	return asn1p_constraint_clone_with_resolver(src, 0, 0);
}

asn1p_constraint_t *
asn1p_constraint_clone_with_resolver(asn1p_constraint_t *src,
		asn1p_value_t *(*vr)(asn1p_value_t *, void *varg), void *varg) {
	asn1p_constraint_t *clone;

#define	CLONE(field, func)	do { if(src->field) {			\
			clone->field = func(src->field, vr, varg);	\
			if(clone->field == NULL) {			\
				asn1p_constraint_free(clone);		\
				return NULL;				\
			}						\
		} } while(0)

	clone = asn1p_constraint_new(src->_lineno, src->module);
	if(clone) {
		unsigned int i;

		clone->type = src->type;
		clone->presence = src->presence;
		CLONE(containedSubtype,	asn1p_value_clone_with_resolver);
		CLONE(value,		asn1p_value_clone_with_resolver);
		CLONE(range_start,	asn1p_value_clone_with_resolver);
		CLONE(range_stop,	asn1p_value_clone_with_resolver);

		for(i = 0; i < src->el_count; i++) {
			asn1p_constraint_t *t;
			t = asn1p_constraint_clone_with_resolver(src->elements[i], vr, varg);
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

/*
 * Make sure there's enough space to add an element.
 */
static int
asn1p_constraint_make_memory(asn1p_constraint_t *ct) {
	if(ct->el_count == ct->el_size) {
		unsigned int newsize = ct->el_size ? ct->el_size << 2 : 4;
		void *p;
		p = realloc(ct->elements, newsize * sizeof(ct->elements[0]));
		if(p) {
			ct->elements = p;
			ct->el_size = newsize;
		} else {
			return -1;
		}
	}
	return 0;
}

int
asn1p_constraint_insert(asn1p_constraint_t *into, asn1p_constraint_t *what) {
	assert(into);
	assert(what);

	if(asn1p_constraint_make_memory(into))
		return -1;

	into->elements[into->el_count++] = what;
	what->parent_ct = into;

	return 0;
}

int
asn1p_constraint_prepend(asn1p_constraint_t *before, asn1p_constraint_t *what) {
	assert(before);
	assert(what);

	if(asn1p_constraint_make_memory(before))
		return -1;

	memmove(&before->elements[1], &before->elements[0],
		before->el_count * sizeof(before->elements[0]));

	before->elements[0] = what;
	before->el_count++;
	what->parent_ct = before;

	return 0;
}


const char *
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
	case ACT_CT_CTNG:
		return "ContentsConstraint";
	case ACT_CT_PATTERN:
		return "PatternConstraint";
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

const asn1p_constraint_t *
asn1p_get_component_relation_constraint(asn1p_constraint_t *ct) {
    if(ct) {
        if(ct->type == ACT_CA_CRC)
            return ct;
        if(ct->type == ACT_CA_SET) {
            for(size_t i = 0; i < ct->el_count; i++) {
                const asn1p_constraint_t *tmp =
                    asn1p_get_component_relation_constraint(ct->elements[i]);
                if(tmp) return tmp;
            }
        }
    }
    return NULL;
}

