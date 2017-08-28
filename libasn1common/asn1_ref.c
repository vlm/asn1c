#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1_ref.h"

/*
 * Construct a new empty reference.
 */
asn1p_ref_t *
asn1p_ref_new(int _lineno, struct asn1p_module_s *mod) {
	asn1p_ref_t *ref;

    ref = calloc(1, sizeof *ref);
    assert(ref);
    asn1p_ref_set_source(ref, mod, _lineno);

    return ref;
}

void
asn1p_ref_free(asn1p_ref_t *ref) {
	if(ref) {
		if(ref->components) {
			size_t i = ref->comp_count;
			while(i--) {
				free(ref->components[i].name);
				ref->components[i].name = 0;
			}
			free(ref->components);
			ref->components = 0;
		}

		free(ref);
	}
}

void
asn1p_ref_set_source(asn1p_ref_t *ref, struct asn1p_module_s *module,
                     int lineno) {
    if(ref) {
        ref->module = module;
        ref->_lineno = lineno;
    }
}

static enum asn1p_ref_lex_type_e
asn1p_ref_name2lextype(const char *name) {
	enum asn1p_ref_lex_type_e lex_type;
	int has_lowercase = 0;

	if(*name == '&') {
		if(name[1] >= 'A' && name[1] <= 'Z') {
			lex_type = RLT_AmpUppercase;
		} else {
			lex_type = RLT_Amplowercase;
		}
	} else if(*name >= 'A' && *name <= 'Z') {
		const char *p;

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
asn1p_ref_add_component(asn1p_ref_t *ref, const char *name, enum asn1p_ref_lex_type_e lex_type) {

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

	newref = asn1p_ref_new(ref->_lineno, ref->module);
	if(newref) {
		for(size_t i = 0; i < ref->comp_count; i++) {
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

int
asn1p_ref_compare(const asn1p_ref_t *a, const asn1p_ref_t *b) {
    if(a->comp_count != b->comp_count)
        return -1;
    if(a->module != b->module)
        return -1;

    for(size_t i = 0; i < a->comp_count; i++) {
        if(a->components[i].lex_type != b->components[i].lex_type
           || strcmp(a->components[i].name, b->components[i].name) != 0) {
            return -1;
        }
    }

    return 0;
}

const char *
asn1p_ref_string(const asn1p_ref_t *ref) {
    static char static_buf[32];
    static char *buf = static_buf;
    static size_t buf_size = sizeof(static_buf);
    char *p = buf;

    if(!ref) return "<no-ref>";

    for(size_t i = 0; i < ref->comp_count; i++) {
        size_t space = buf_size - (p - buf);
        int ret =
            snprintf(p, space, "%s%s", i ? "." : "", ref->components[i].name);
        if(ret < 0 || (size_t)ret >= space) {
            i--;
            char *tmp = malloc(buf_size * 2 + 1);
            assert(tmp);
            size_t p_offset = p - buf;
            memcpy(tmp, buf, (p - buf));
            if(buf != static_buf) free(buf);
            buf_size *= 2;
            buf = tmp;
            p = tmp + p_offset;
        } else {
            p += ret;
        }
    }

    *p = '\0';
    return buf;
}

