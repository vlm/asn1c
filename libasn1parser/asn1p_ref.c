#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

/*
 * Construct a new empty reference.
 */
asn1p_ref_t *
asn1p_ref_new(int _lineno) {
	asn1p_ref_t *ref;

	ref = calloc(1, sizeof *ref);
	if(ref) {
		ref->_lineno = _lineno;
	}

	return ref;
}

void
asn1p_ref_free(asn1p_ref_t *ref) {
	if(ref) {
		if(ref->components) {
			int i = ref->comp_count;
			while(i--) {
				if(ref->components[i].name)
				free(ref->components[i].name);
				ref->components[i].name = 0;
			}
			free(ref->components);
			ref->components = 0;
		}

		free(ref);
	}
}

static enum asn1p_ref_lex_type_e
asn1p_ref_name2lextype(char *name) {
	enum asn1p_ref_lex_type_e lex_type;
	int has_lowercase = 0;

	if(*name == '&') {
		if(name[1] >= 'A' && name[1] <= 'Z') {
			lex_type = RLT_AmpUppercase;
		} else {
			lex_type = RLT_Amplowercase;
		}
	} else if(*name >= 'A' && *name <= 'Z') {
		char *p;

		for(p = name; *p; p++) {
			if(*p >= 'a' && *p <= 'z') {
				has_lowercase = 1;
				break;
			}
		}

		if(has_lowercase) {
			lex_type = RLT_Uppercase;
		} else {
			lex_type = RLT_CAPITALS;
		}
	} else if(*name == '@') {
		if(name[1] == '.')
			lex_type = RLT_AtDotlowercase;
		else
			lex_type = RLT_Atlowercase;
	} else {
		lex_type = RLT_lowercase;
	}

	return lex_type;
}

int
asn1p_ref_add_component(asn1p_ref_t *ref, char *name, enum asn1p_ref_lex_type_e lex_type) {

	if(!ref || !name
	|| (int)lex_type < RLT_UNKNOWN || lex_type >= RLT_MAX) {
		errno = EINVAL;
		return -1;
	}

	if(ref->comp_count == ref->comp_size) {
		int newsize = ref->comp_size?(ref->comp_size<<2):4;
		void *p = realloc(ref->components,
			newsize * sizeof(ref->components[0]));
		if(p) {
			ref->components = p;
			ref->comp_size = newsize;
		} else {
			return -1;
		}

	}

	if(lex_type == RLT_UNKNOWN) {
		lex_type = asn1p_ref_name2lextype(name);
	} else {
		assert(lex_type == asn1p_ref_name2lextype(name));
	}

	ref->components[ref->comp_count].name = strdup(name);
	ref->components[ref->comp_count].lex_type = lex_type;
	if(ref->components[ref->comp_count].name) {
		ref->comp_count++;
		return 0;
	} else {
		return -1;
	}
}

asn1p_ref_t *
asn1p_ref_clone(asn1p_ref_t *ref) {
	asn1p_ref_t *newref;

	newref = asn1p_ref_new(ref->_lineno);
	if(newref) {
		int i;
		for(i = 0; i < ref->comp_count; i++) {
			if(asn1p_ref_add_component(newref,
				ref->components[i].name,
				ref->components[i].lex_type
			)) {
				asn1p_ref_free(newref);
				newref = NULL;
				break;
			}
		}
	}

	return newref;
}
