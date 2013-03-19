#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include "asn1parser.h"

static asn1p_expr_t *asn1p_expr_clone_impl(asn1p_expr_t *expr, int skip_extensions, asn1p_expr_t *(*)(asn1p_expr_t *, void *), void *);
static asn1p_value_t *value_resolver(asn1p_value_t *, void *arg);

/*
 * Construct a new empty types collection.
 */
asn1p_expr_t *
asn1p_expr_new(int _lineno, asn1p_module_t *mod) {
	asn1p_expr_t *expr;

	expr = calloc(1, sizeof *expr);
	if(expr) {
		TQ_INIT(&(expr->members));
		expr->spec_index = -1;
		expr->module = mod;
		expr->_lineno = _lineno;
	}

	return expr;
}

asn1p_expr_t *
asn1p_expr_clone(asn1p_expr_t *expr, int skip_extensions) {
	return asn1p_expr_clone_impl(expr, skip_extensions, 0, 0);
}

asn1p_expr_t *
asn1p_expr_clone_with_resolver(asn1p_expr_t *expr, asn1p_expr_t *(*r)(asn1p_expr_t *, void *), void *rarg) {
	return asn1p_expr_clone_impl(expr, 0, r, rarg);
}

static asn1p_expr_t *
asn1p_expr_clone_impl(asn1p_expr_t *expr, int skip_extensions, asn1p_expr_t *(*r)(asn1p_expr_t *, void *), void *rarg) {
	asn1p_value_t *(*vr)(asn1p_value_t *, void *) = 0;
	asn1p_expr_t *clone = 0;
	asn1p_expr_t *tcmemb;	/* Child of tc */
	int hit_ext = 0;

#define	CLCOPY(field)	do { clone->field = expr->field; } while(0)
#define	CLCLONE(field, func)	do { if(expr->field) {			\
			clone->field = func(expr->field);		\
			if(clone->field == NULL) {			\
				asn1p_expr_free(clone);			\
				return NULL;				\
			}						\
		} } while(0)
#define	CLVRCLONE(field, func)	do { if(expr->field) {			\
			clone->field = func(expr->field, vr, rarg);	\
			if(clone->field == NULL) {			\
				asn1p_expr_free(clone);			\
				return NULL;				\
			}						\
		} } while(0)

	if(r) {
		vr = value_resolver;
		clone = r(expr, rarg);
		if(clone) {
			/* Merge constraints */
			if(expr->constraints) {
				asn1p_constraint_t *tmpct = asn1p_constraint_clone_with_resolver(expr->constraints, vr, rarg);
				if(clone->constraints) {
					if(asn1p_constraint_insert(clone->constraints, tmpct)) {
						asn1p_constraint_free(tmpct);
						asn1p_expr_free(clone);
						return NULL;
					}
				} else {
					clone->constraints = tmpct;
				}
				assert(expr->combined_constraints == 0);
			}
			/* Merge defaults */
			CLCOPY(marker.flags);
			CLVRCLONE(marker.default_value,
				asn1p_value_clone_with_resolver);
			if(clone->tag.tag_class == TC_NOCLASS) {
				CLCOPY(tag);
			} else if(expr->tag.tag_class != TC_NOCLASS) {
				fprintf(stderr, "asn1c does not support "
					"nested tagging in parameterization, "
					"necessary at line %d\n",
					expr->_lineno);
				asn1p_expr_free(clone);
				return NULL;
			}
			return clone;
		} else if(errno != ESRCH) {
			return NULL;	/* Hard error */
		}
	}
	if(!clone) clone = asn1p_expr_new(expr->_lineno, expr->module);
	if(!clone) return NULL;

	/*
	 * Copy simple fields.
	 */
	CLCOPY(meta_type);
	CLCOPY(expr_type);
	CLCOPY(tag);
	CLCOPY(marker.flags);		/* OPTIONAL/DEFAULT */
	CLCOPY(_mark);

	clone->data = 0;	/* Do not clone this */
	clone->data_free = 0;	/* Do not clone this */

	/*
	 * Clone complex fields.
	 */
	CLCLONE(Identifier, strdup);
	CLCLONE(reference, asn1p_ref_clone);
	CLVRCLONE(constraints, asn1p_constraint_clone_with_resolver);
	CLVRCLONE(combined_constraints, asn1p_constraint_clone_with_resolver);
	CLCLONE(lhs_params, asn1p_paramlist_clone);
	CLVRCLONE(value, asn1p_value_clone_with_resolver);
	CLVRCLONE(marker.default_value, asn1p_value_clone_with_resolver);
	CLCLONE(with_syntax, asn1p_wsyntx_clone);

	/*
	 * Copy all the children of this expr.
	 */
	TQ_FOR(tcmemb, &(expr->members), next) {
		asn1p_expr_t *cmemb;

		if(skip_extensions
		&& tcmemb->expr_type == A1TC_EXTENSIBLE) {
			hit_ext++; /* Even if hit_ext wraps around, we're OK. */
			continue;
		}
		if(hit_ext == 1) continue;	/* Skip between ...'s */

		cmemb = asn1p_expr_clone_impl(tcmemb, skip_extensions, r, rarg);
		if(cmemb == NULL) {
			asn1p_expr_free(clone);
			return NULL;
		}
		asn1p_expr_add(clone, cmemb);
	}

	return clone;
}


static asn1p_value_t *
value_resolver(asn1p_value_t *value, void *rarg) {
	asn1p_value_t *cval;
	asn1p_expr_t *tmpexpr;
	asn1p_expr_t *target;
	asn1p_ref_t *ref;
	struct {
		asn1p_expr_t *(*expr_resolve)(asn1p_expr_t *, void *arg);
	} *varg = rarg;

	if(!value || value->type != ATV_REFERENCED) {
		errno = ESRCH;
		return NULL;
	}

	ref = value->value.reference;
	tmpexpr = asn1p_expr_new(ref->_lineno, 0);
	tmpexpr->meta_type = AMT_TYPEREF;
	tmpexpr->expr_type = A1TC_REFERENCE;
	tmpexpr->reference = ref;
	target = varg->expr_resolve(tmpexpr, rarg);
	tmpexpr->reference = 0;
	asn1p_expr_free(tmpexpr);

	if(!target)
		return NULL;	/* errno's are compatible */

	if(target->meta_type == AMT_VALUE) {
		if(!target->value) {
			fprintf(stderr,
			"FATAL: Parameterization did not resolve "
			"value reference at line %d\n", ref->_lineno);
			asn1p_expr_free(target);
			errno = EPERM;
			return NULL;
		}
		cval = asn1p_value_clone(target->value);
	} else if(target->meta_type == AMT_VALUESET) {
		if(!target->constraints) {
			fprintf(stderr,
			"FATAL: Parameterization did not resolve "
			"value set reference at line %d\n", ref->_lineno);
			asn1p_expr_free(target);
			errno = EPERM;
			return NULL;
		}
		cval = asn1p_value_fromconstr(target->constraints, 1);
	} else {
		errno = EPERM;
		cval = NULL;
	}

	asn1p_expr_free(target);
	return cval;
}

/*
 * Add expression as a member of another.
 */
void
asn1p_expr_add(asn1p_expr_t *to, asn1p_expr_t *what) {
	TQ_ADD(&(to->members), what, next);
	what->parent_expr = to;
}

/*
 * Add inner expressions as members of another.
 */
void
asn1p_expr_add_many(asn1p_expr_t *to, asn1p_expr_t *from_what) {
	asn1p_expr_t *expr;
	TQ_FOR(expr, &(from_what->members), next) {
        expr->parent_expr = to;
    }
	TQ_CONCAT(&(to->members), &(from_what->members), next);
}


/*
 * Destruct the types collection structure.
 */
void
asn1p_expr_free(asn1p_expr_t *expr) {
	if(expr) {
		asn1p_expr_t *tm;

		/* Remove all children */
		while((tm = TQ_REMOVE(&(expr->members), next))) {
			if(tm->parent_expr != expr)
				printf("<%s:%p !-> %s:%p>\n",
					tm->Identifier, tm->parent_expr,
					expr->Identifier, expr);
			assert(tm->parent_expr == expr);
			asn1p_expr_free(tm);
		}

		if(expr->Identifier)
			free(expr->Identifier);
		if(expr->reference)
			asn1p_ref_free(expr->reference);
		if(expr->constraints)
			asn1p_constraint_free(expr->constraints);
		if(expr->combined_constraints)
			asn1p_constraint_free(expr->combined_constraints);
		if(expr->lhs_params)
			asn1p_paramlist_free(expr->lhs_params);
		if(expr->value)
			asn1p_value_free(expr->value);
		if(expr->marker.default_value)
			asn1p_value_free(expr->marker.default_value);
		if(expr->with_syntax)
			asn1p_wsyntx_free(expr->with_syntax);

		if(expr->data && expr->data_free)
			expr->data_free(expr->data);

		memset(expr, 0, sizeof(*expr));
		free(expr);
	}
}


char *asn1p_tag2string(struct asn1p_type_tag_s *tag, char *buf) {
	static char buf_stat[TAG2STRING_BUFFER_SIZE];
	char *start;
	char *end;

	if(!buf) buf = buf_stat;
	start = buf;
	end = buf + TAG2STRING_BUFFER_SIZE;

	if(tag->tag_class == TC_NOCLASS) {
		*buf = 0;
		return buf;
	}

	strcpy(buf, "[");
	switch(tag->tag_class) {
	case TC_NOCLASS:
		assert(tag->tag_class != TC_NOCLASS);
		break;
	case TC_UNIVERSAL:	strcat(buf, "UNIVERSAL ");	break;
	case TC_PRIVATE:	strcat(buf, "PRIVATE ");	break;
	case TC_APPLICATION:	strcat(buf, "APPLICATION ");	break;
	case TC_CONTEXT_SPECIFIC:
		break;
	}
	buf += snprintf(buf + strlen(buf), end - buf,
		"%" PRIdASN "]", tag->tag_value);
	assert((unsigned int)(buf - end) > sizeof(" IMPLICIT "));

	switch(tag->tag_mode) {
	case TM_DEFAULT: break;
	case TM_IMPLICIT: strcat(buf, " IMPLICIT"); break;
	case TM_EXPLICIT: strcat(buf, " EXPLICIT"); break;
	}

	return start;
}
