#include "asn1fix_internal.h"

int
asn1f_fetch_tag(asn1p_t *asn, asn1p_module_t *mod, asn1p_expr_t *expr, struct asn1p_type_tag_s *tag, int flags) {
	int ret;

	if(expr->tag.tag_class != TC_NOCLASS) {
		*tag = expr->tag;
		return 0;
	}

	if(expr->expr_type == A1TC_EXTENSIBLE) {
		memset(tag, 0, sizeof(*tag));
		tag->tag_class = -1;
		return 0;
	}

	if(expr->meta_type == AMT_TYPE) {
		memset(tag, 0, sizeof(*tag));
		tag->tag_class = TC_UNIVERSAL;
		tag->tag_value = expr_type2uclass_value[expr->expr_type];
		if(flags && expr->expr_type == ASN_TYPE_ANY) {
			assert(tag->tag_value == 0);
			tag->tag_value = -1;
			return 0;
		}
		return (tag->tag_value == 0) ? -1 : 0;
	}

	if(expr->meta_type == AMT_TYPEREF) {
		arg_t arg;

		memset(&arg, 0, sizeof(arg));
		arg.asn = asn;
		arg.mod = mod;
		arg.expr = expr;

		expr = asn1f_lookup_symbol(&arg, expr->module, expr->reference);
		if(expr == NULL) return -1;

		if(expr->_mark & TM_RECURSION)
			return -1;

		expr->_mark |= TM_RECURSION;
		ret = asn1f_fetch_tag(asn, expr->module, expr, tag,
			flags);
		expr->_mark &= ~TM_RECURSION;
		return ret;
	}

	return -1;
}

