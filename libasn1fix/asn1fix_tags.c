#include "asn1fix_internal.h"

#define	ADD_TAG(skip, newtag)	do {					\
	void *__p;							\
	if(skip && !(flags & AFT_FULL_COLLECT)) {			\
		if(newtag.tag_mode != TM_IMPLICIT)			\
			skip--;						\
		break;							\
	} else {							\
		if(newtag.tag_mode == TM_IMPLICIT)			\
			skip++;						\
	}								\
	__p = realloc((*tags),						\
		sizeof(struct asn1p_type_tag_s) * (count + 1));		\
	if(!__p) return -1;						\
	*tags = __p;							\
	(*tags)[count++] = newtag;					\
	if((flags & AFT_FETCH_OUTMOST)) return count;			\
} while(0)

static int
asn1f_fetch_tags_impl(arg_t *arg, struct asn1p_type_tag_s **tags, int count, int skip, enum asn1f_aft_flags_e flags) {
	asn1p_expr_t *expr = arg->expr;

	/* If this type is tagged, add this tag first */
	if(expr->tag.tag_class != TC_NOCLASS)
		ADD_TAG(skip, expr->tag);

	/* REMOVE ME */
	if(expr->expr_type == A1TC_EXTENSIBLE) {
		struct asn1p_type_tag_s tt;
		memset(&tt, 0, sizeof(tt));
		tt.tag_class = -1;
		ADD_TAG(skip, tt);
		return count;
	}

	if(expr->meta_type == AMT_TYPE) {
		struct asn1p_type_tag_s tt;
		memset(&tt, 0, sizeof(tt));
		tt.tag_class = TC_UNIVERSAL;
		tt.tag_value = expr_type2uclass_value[expr->expr_type];
		if(tt.tag_value == 0) {
			if(expr->expr_type == ASN_TYPE_ANY
				&& (flags & AFT_IMAGINARY_ANY))
				tt.tag_value = -1;
			else
				return -1;
		}
		ADD_TAG(skip, tt);
		return count;
	}

	if(expr->meta_type == AMT_TYPEREF) {
		asn1p_expr_t *nexpr;
		nexpr = asn1f_lookup_symbol(arg, expr->module, expr->reference);
		if(nexpr == NULL) {
			if(errno != EEXIST)	/* -fknown-extern-type */
				return -1;
			if(!count)
				return 0;	/* OK */
			if((*tags)[count-1].tag_mode == TM_IMPLICIT) {
				WARNING("Tagging mode for %s "
					"is IMPLICIT, assuming %s "
					"has exactly one tag",
					expr->Identifier,
					asn1f_printable_reference(expr->reference)
				);
				return count;
			}
			FATAL("Tagging mode %s -> %s "
				"dangerously incompatible",
				expr->Identifier,
				asn1f_printable_reference(expr->reference)
			);
			return -1;
		} else {
			arg->expr = nexpr;
		}
		if(expr->_mark & TM_RECURSION)
			return -1;
		expr->_mark |= TM_RECURSION;
		count = asn1f_fetch_tags_impl(arg, tags, count, skip, flags);
		expr->_mark &= ~TM_RECURSION;
		return count;
	}

	return -1;
}


int
asn1f_fetch_outmost_tag(asn1p_t *asn, asn1p_module_t *mod, asn1p_expr_t *expr, struct asn1p_type_tag_s *tag, int _aft_imaginary_any) {
	struct asn1p_type_tag_s *tags;
	enum asn1f_aft_flags_e flags;
	int count;

	flags = AFT_FETCH_OUTMOST;
	flags |= AFT_IMAGINARY_ANY * _aft_imaginary_any;

	count = asn1f_fetch_tags(asn, mod, expr, &tags, flags);
	if(count <= 0) return count;

	*tag = tags[0];
	free(tags);

	return 0;
}

int
asn1f_fetch_tags(asn1p_t *asn, asn1p_module_t *mod, asn1p_expr_t *expr, struct asn1p_type_tag_s **tags_r, enum asn1f_aft_flags_e flags) {
	arg_t arg;
	struct asn1p_type_tag_s *tags = 0;
	int count;

	memset(&arg, 0, sizeof(arg));
	arg.asn = asn;
	arg.mod = mod;
	arg.expr = expr;

	count = asn1f_fetch_tags_impl(&arg, &tags, 0, 0, flags);
	if(count <= 0 && tags) {
		free(tags);
		tags = 0;
	}
	*tags_r = tags;
	return count;
}
