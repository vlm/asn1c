/*
 * Don't look into this file. First, because it's a mess, and second, because
 * it's a brain of the compiler, and you don't wanna mess with brains do you? ;)
 */
#include "asn1c_internal.h"
#include "asn1c_C.h"
#include "asn1c_constraint.h"
#include "asn1c_out.h"
#include "asn1c_misc.h"
#include "asn1c_ioc.h"
#include "asn1c_naming.h"
#include <asn1print.h>
#include <asn1fix_crange.h>	/* constraint groker from libasn1fix */
#include <asn1fix_export.h>	/* other exportables from libasn1fix */
#include <asn1parser.h>

typedef struct tag2el_s {
	struct asn1p_type_tag_s el_tag;
	int el_no;
	int toff_first;
	int toff_last;
	asn1p_expr_t *from_expr;
} tag2el_t;

typedef enum fte {
	FTE_ALLTAGS,
	FTE_CANONICAL_XER,
} fte_e;
static int _fill_tag2el_map(arg_t *arg, tag2el_t **tag2el, int *count, int el_no, fte_e flags);
static int _add_tag2el_member(arg_t *arg, tag2el_t **tag2el, int *count, int el_no, fte_e flags);

enum onc_flags {
	ONC_noflags		= 0x00,
	ONC_avoid_keywords	= 0x01,
	ONC_force_compound_name	= 0x02,
};
static int out_name_chain(arg_t *arg, enum onc_flags);
static int asn1c_lang_C_type_SEQUENCE_def(
    arg_t *arg, asn1c_ioc_table_and_objset_t *);
static int asn1c_lang_C_type_SET_def(arg_t *arg);
static int asn1c_lang_C_type_CHOICE_def(arg_t *arg);
static int asn1c_lang_C_type_SEx_OF_def(arg_t *arg, int seq_of);
static int asn1c_lang_C_OpenType(arg_t *arg, asn1c_ioc_table_and_objset_t *opt_ioc, const char *column_name);
static int _print_tag(arg_t *arg, struct asn1p_type_tag_s *tag_p);
static int compute_extensions_start(asn1p_expr_t *expr);
static int expr_break_recursion(arg_t *arg, asn1p_expr_t *expr);
static int expr_as_xmlvaluelist(arg_t *arg, asn1p_expr_t *expr);
static int expr_elements_count(arg_t *arg, asn1p_expr_t *expr);
static int emit_single_member_OER_constraint_value(arg_t *arg, asn1cnst_range_t *range);
static int emit_single_member_OER_constraint_size(arg_t *arg, asn1cnst_range_t *range);
static int emit_single_member_PER_constraint(arg_t *arg, asn1cnst_range_t *range, int juscountvalues, const char *type);
static int emit_member_OER_constraints(arg_t *arg, asn1p_expr_t *expr, const char *pfx);
static int emit_member_PER_constraints(arg_t *arg, asn1p_expr_t *expr, const char *pfx);
static int emit_member_table(arg_t *arg, asn1p_expr_t *expr,
                             asn1c_ioc_table_and_objset_t *);
static int emit_tag2member_map(arg_t *arg, tag2el_t *tag2el, int tag2el_count, const char *opt_modifier);
static int emit_include_dependencies(arg_t *arg);
static asn1p_expr_t *terminal_structable(arg_t *arg, asn1p_expr_t *expr);
static int expr_defined_recursively(arg_t *arg, asn1p_expr_t *expr);
static int asn1c_recurse(arg_t *arg, asn1p_expr_t *expr, int (*callback)(arg_t *arg, void *key), void *key);
static asn1p_expr_type_e expr_get_type(arg_t *arg, asn1p_expr_t *expr);
static int try_inline_default(arg_t *arg, asn1p_expr_t *expr, int out);
static int *compute_canonical_members_order(arg_t *arg, int el_count);

enum tvm_compat {
	_TVM_SAME	= 0,	/* tags and all_tags are same */
	_TVM_SUBSET	= 1,	/* tags are subset of all_tags */
	_TVM_DIFFERENT	= 2,	/* tags and all_tags are different */
};
static enum tvm_compat emit_tags_vectors(arg_t *arg, asn1p_expr_t *expr, int *tc, int *atc);

enum etd_spec {
	ETD_NO_SPECIFICS,
	ETD_HAS_SPECIFICS
};
static int emit_type_DEF(arg_t *arg, asn1p_expr_t *expr, enum tvm_compat tv_mode, int tags_count, int all_tags_count, int elements_count, enum etd_spec);

#define	C99_MODE	(!(arg->flags & A1C_NO_C99))
#define	UNNAMED_UNIONS	(arg->flags & A1C_UNNAMED_UNIONS)
#define	HIDE_INNER_DEFS	(arg->embed && !(arg->flags & A1C_ALL_DEFS_GLOBAL))

#define	PCTX_DEF INDENTED(		\
	OUT("\n");			\
	OUT("/* Context for parsing across buffer boundaries */\n");	\
	OUT("asn_struct_ctx_t _asn_ctx;\n"));


#define	DEPENDENCIES	do {						\
	emit_include_dependencies(arg);					\
	if(expr->expr_type == ASN_CONSTR_SET_OF)			\
		GEN_INCLUDE_STD("asn_SET_OF");				\
	if(expr->expr_type == ASN_CONSTR_SEQUENCE_OF)			\
		GEN_INCLUDE_STD("asn_SEQUENCE_OF");			\
} while(0)

/* MKID_safe() without checking for reserved keywords */
#define	MKID(expr)	(asn1c_make_identifier(0, expr, 0))
#define	MKID_safe(expr)	(asn1c_make_identifier(AMI_CHECK_RESERVED, expr, 0))

int
asn1c_lang_C_type_REAL(arg_t *arg) {
	return asn1c_lang_C_type_SIMPLE_TYPE(arg);
}

struct value2enum {
	asn1c_integer_t	 value;
	const char	*name;
	int		 idx;
};
static int compar_enumMap_byName(const void *ap, const void *bp) {
	const struct value2enum *a = (const struct value2enum *)ap;
	const struct value2enum *b = (const struct value2enum *)bp;
	return strcmp(a->name, b->name);
}
static int compar_enumMap_byValue(const void *ap, const void *bp) {
	const struct value2enum *a = (const struct value2enum *)ap;
	const struct value2enum *b = (const struct value2enum *)bp;
	if(a->value < b->value)
		return -1;
	else if(a->value == b->value)
		return 0;
	return 1;
}

int
asn1c_lang_C_type_common_INTEGER(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int el_count = expr_elements_count(arg, expr);
	struct value2enum *v2e;
	int map_extensions = (expr->expr_type == ASN_BASIC_INTEGER);
	int eidx;
	int saved_target = arg->target->target;

	v2e = calloc(el_count + 1, sizeof(*v2e));
	assert(v2e);

	/*
	 * For all ENUMERATED types and for those INTEGER types which
	 * have identifiers, print out an enumeration table.
	 */
	if(expr->expr_type == ASN_BASIC_ENUMERATED || el_count) {
		eidx = 0;
		REDIR(OT_DEPS);
		OUT("typedef %s {\n", c_name(arg).members_enum);
		TQ_FOR(v, &(expr->members), next) {
			switch(v->expr_type) {
			case A1TC_UNIVERVAL:
				OUT("\t");
				OUT("%s", c_member_name(arg, v));
				OUT("\t= %s%s\n",
					asn1p_itoa(v->value->value.v_integer),
					(eidx+1 < el_count) ? "," : "");
				v2e[eidx].name = v->Identifier;
				v2e[eidx].value = v->value->value.v_integer;
				eidx++;
				break;
			case A1TC_EXTENSIBLE:
				OUT("\t/*\n");
				OUT("\t * Enumeration is extensible\n");
				OUT("\t */\n");
				if(!map_extensions)
					map_extensions = eidx + 1;
				break;
			default:
				free(v2e);
				return -1;
			}
		}
		OUT("} %s;\n", c_name(arg).members_name);
		assert(eidx == el_count);
	}

	/*
	 * For all ENUMERATED types print out a mapping table
	 * between identifiers and associated values.
	 * This is prohibited for INTEGER types by by X.693:8.3.4.
	 */
	if(expr->expr_type == ASN_BASIC_ENUMERATED) {

		/*
		 * Generate a enumerationName<->value map for XER codec.
		 */
		REDIR(OT_STAT_DEFS);

		OUT("static const asn_INTEGER_enum_map_t asn_MAP_%s_value2enum_%d[] = {\n",
			MKID(expr), expr->_type_unique_index);
		qsort(v2e, el_count, sizeof(v2e[0]), compar_enumMap_byValue);
		for(eidx = 0; eidx < el_count; eidx++) {
			v2e[eidx].idx = eidx;
			OUT("\t{ %s,\t%ld,\t\"%s\" }%s\n",
				asn1p_itoa(v2e[eidx].value),
				(long)strlen(v2e[eidx].name), v2e[eidx].name,
				(eidx + 1 < el_count) ? "," : "");
		}
		if(map_extensions)
			OUT("\t/* This list is extensible */\n");
		OUT("};\n");

		OUT("static const unsigned int asn_MAP_%s_enum2value_%d[] = {\n",
			MKID(expr), expr->_type_unique_index);
		qsort(v2e, el_count, sizeof(v2e[0]), compar_enumMap_byName);
		for(eidx = 0; eidx < el_count; eidx++) {
			OUT("\t%d%s\t/* %s(%s) */\n",
				v2e[eidx].idx,
				(eidx + 1 < el_count) ? "," : "",
				v2e[eidx].name, asn1p_itoa(v2e[eidx].value));
		}
		if(map_extensions)
			OUT("\t/* This list is extensible */\n");
		OUT("};\n");

		if(!(expr->_type_referenced)) OUT("static ");
		OUT("const asn_INTEGER_specifics_t asn_SPC_%s_specs_%d = {\n",
			MKID(expr), expr->_type_unique_index);
		INDENT(+1);
		OUT("asn_MAP_%s_value2enum_%d,\t"
			"/* \"tag\" => N; sorted by tag */\n",
			MKID(expr),
			expr->_type_unique_index);
		OUT("asn_MAP_%s_enum2value_%d,\t"
			"/* N => \"tag\"; sorted by N */\n",
			MKID(expr),
			expr->_type_unique_index);
		OUT("%d,\t/* Number of elements in the maps */\n",
			el_count);
		if(map_extensions) {
			OUT("%d,\t/* Extensions before this member */\n",
				map_extensions);
		} else {
			OUT("0,\t/* Enumeration is not extensible */\n");
		}
		if(expr->expr_type == ASN_BASIC_ENUMERATED)
			OUT("1,\t/* Strict enumeration */\n");
		else
			OUT("0,\n");
		OUT("0,\t/* Native long size */\n");
		OUT("0\n");
		INDENT(-1);
		OUT("};\n");
	}

	if(expr->expr_type == ASN_BASIC_INTEGER
	&& asn1c_type_fits_long(arg, expr) == FL_FITS_UNSIGN) {
		REDIR(OT_STAT_DEFS);
		if(!(expr->_type_referenced)) OUT("static ");
		OUT("const asn_INTEGER_specifics_t asn_SPC_%s_specs_%d = {\n",
			MKID(expr), expr->_type_unique_index);
		INDENT(+1);
		OUT("0,\t");
		OUT("0,\t");
		OUT("0,\t");
		OUT("0,\t");
		OUT("0,\n");
		OUT("0,\t/* Native long size */\n");
		OUT("1\t/* Unsigned representation */\n");
		INDENT(-1);
		OUT("};\n");
	}

	REDIR(saved_target);

	free(v2e);
	return asn1c_lang_C_type_SIMPLE_TYPE(arg);
}

int
asn1c_lang_C_type_BIT_STRING(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int el_count = expr_elements_count(arg, expr);
	int saved_target = arg->target->target;

	if(el_count) {
		int eidx = 0;
		REDIR(OT_DEPS);
		OUT("typedef %s {\n", c_name(arg).members_enum);
		TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type != A1TC_UNIVERVAL) {
				OUT("/* Unexpected BIT STRING element: %s */\n",
				v->Identifier);
				continue;
			}
			eidx++;
			OUT("\t");
			OUT("%s", c_member_name(arg, v));
			OUT("\t= %s%s\n",
				asn1p_itoa(v->value->value.v_integer),
				(eidx < el_count) ? "," : "");
		}
		OUT("} %s;\n", c_name(arg).members_name);
		assert(eidx == el_count);
	}

	REDIR(saved_target);

	return asn1c_lang_C_type_SIMPLE_TYPE(arg);
}

/*
 * Check if it is a true open type. That is, type is taken from
 * the Information Object Set driven constraints.
 */
static int
is_open_type(arg_t *arg, asn1p_expr_t *expr, asn1c_ioc_table_and_objset_t *opt_ioc) {

    (void)arg;

    if(!opt_ioc) {
        return 0;
    }

    if(expr->meta_type == AMT_TYPEREF
       && expr->expr_type == A1TC_REFERENCE
       && expr->reference->comp_count == 2
       && expr->reference->components[1].lex_type
              == RLT_AmpUppercase) {
        DEBUG("%s is a true open type", MKID(expr));
        return 1;
    }

    return 0;
}

int
asn1c_lang_C_type_SEQUENCE(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int comp_mode = 0;	/* {root,ext=1,root,root,...} */
	int saved_target = arg->target->target;
    asn1c_ioc_table_and_objset_t ioc_tao;

	DEPENDENCIES;

    ioc_tao = asn1c_get_ioc_table(arg);
    if(ioc_tao.ioct) {
        if(emit_ioc_table(arg, expr, ioc_tao)) {
            return -1;
        }
    } else if(ioc_tao.fatal_error) {
        return -1;
    }

	if(arg->embed) {

		/* Use _anonymous_type field to indicate it's called from
		 * asn1c_lang_C_type_SEx_OF() */
		if (expr->_anonymous_type) {
			REDIR(OT_FWD_DEFS);
			OUT("typedef ");
		}
		OUT("%s {\n", c_name(arg).full_name);
	} else {
		REDIR(OT_TYPE_DECLS);
		OUT("typedef %s {\n", c_name(arg).full_name);
	}

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE)
			if(comp_mode < 3) comp_mode++;
		if(comp_mode == 1)
			v->marker.flags |= EM_OMITABLE | EM_INDIRECT;
		try_inline_default(arg, v, 1);
        if(is_open_type(arg, v, ioc_tao.ioct ? &ioc_tao : 0)) {
            arg_t tmp_arg = *arg;
            tmp_arg.embed++;
            INDENT(+1);
            tmp_arg.expr = v;
            const char *column_name = v->reference->components[1].name;
            if(asn1c_lang_C_OpenType(&tmp_arg, &ioc_tao, column_name)) {
                return -1;
            }
            INDENT(-1);
            tmp_arg.embed--;
            if(v->expr_type != A1TC_EXTENSIBLE) OUT(";\n");
        } else {
            EMBED_WITH_IOCT(v, ioc_tao);
        }
	}

	PCTX_DEF;

	if (arg->embed && expr->_anonymous_type) {
		OUT("} %s%s;\n", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).base_name);

		REDIR(saved_target);

		OUT("%s%s", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).base_name);
	} else {
		OUT("} %s%s", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).short_name);
	}

	return asn1c_lang_C_type_SEQUENCE_def(arg, ioc_tao.ioct ? &ioc_tao : 0);
}

static void
emit_tag2member_reference(arg_t *arg, asn1p_expr_t *expr,
                          unsigned tag2el_count) {
    if(tag2el_count) {
        if(C99_MODE) OUT(".tag2el = ");
        OUT("asn_MAP_%s_tag2el_%d,\n", MKID(expr), expr->_type_unique_index);
        if(C99_MODE) OUT(".tag2el_count = ");
        OUT("%d,\t/* Count of tags in the map */\n", tag2el_count);
    } else {
        OUT("0,\t/* No top level tags */\n");
        OUT("0,\t/* No tags in the map */\n");
    }
}

static int
asn1c_lang_C_type_SEQUENCE_def(arg_t *arg, asn1c_ioc_table_and_objset_t *opt_ioc) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int elements;	/* Number of elements */
	int first_extension = -1;
	tag2el_t *tag2el = NULL;
	int tag2el_count = 0;
	int tags_count;
	int all_tags_count;
	enum tvm_compat tv_mode;
	int roms_count;		/* Root optional members */
	int aoms_count;		/* Additions optional members */
	int saved_target = arg->target->target;

	/*
	 * Fetch every inner tag from the tag to elements map.
	 */
	if(_fill_tag2el_map(arg, &tag2el, &tag2el_count, -1, FTE_ALLTAGS)) {
		if(tag2el) free(tag2el);
		return -1;
	}

	GEN_INCLUDE_STD("constr_SEQUENCE");
	if(!arg->embed)
		GEN_DECLARE("SEQUENCE", expr);	/* asn_DEF_xxx */

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which parsing is performed.
	 */
	if(expr_elements_count(arg, expr)) {
		int comp_mode = 0;	/* {root,ext=1,root,root,...} */

		if(!(expr->_type_referenced)) OUT("static ");
		OUT("asn_TYPE_member_t asn_MBR_%s_%d[] = {\n",
			c_name(arg).part_name, expr->_type_unique_index);

		elements = 0;
		roms_count = 0;
		aoms_count = 0;
		INDENTED(TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) {
				if((++comp_mode) == 1)
					first_extension = elements;
				continue;
			}
			if(v->marker.flags & EM_OMITABLE)
			    comp_mode == 1 ? ++aoms_count : ++roms_count;
			if(emit_member_table(arg, v, opt_ioc) < 0)
				return -1;
			elements++;
		});
		OUT("};\n");

		if((roms_count + aoms_count) && (arg->flags & (A1C_GEN_OER|A1C_GEN_PER))) {
			int elm = 0;
			int comma = 0;
			comp_mode = 0;
			OUT("static const int asn_MAP_%s_oms_%d[] = {",
				MKID(expr),
				expr->_type_unique_index);
			TQ_FOR(v, &(expr->members), next) {
				if(v->expr_type == A1TC_EXTENSIBLE) {
					++comp_mode;
					continue;
				}
				if((v->marker.flags & EM_OMITABLE)
				&& comp_mode != 1) {
					if(!comma) comma++;
					else OUT(",");
					OUT(" %d", elm);
				}
				++elm;
			}
			elm = 0;
			comp_mode = 0;
			TQ_FOR(v, &(expr->members), next) {
				if(v->expr_type == A1TC_EXTENSIBLE) {
					++comp_mode;
					continue;
				}
				if((v->marker.flags & EM_OMITABLE)
				&& comp_mode == 1) {
					if(!comma) comma++;
					else OUT(",");
					OUT(" %d", elm);
				}
				++elm;
			}
			OUT(" };\n");
			if(roms_count > 65536) {
				FATAL("Too many optional elements in %s "
					"at line %d!",
					arg->expr->Identifier,
					arg->expr->_lineno);
                return -1;
            }
		} else {
			roms_count = 0;
			aoms_count = 0;
		}
	} else {
		elements = 0;
		roms_count = 0;
		aoms_count = 0;
	}

	/*
	 * Print out asn_DEF_<type>_[all_]tags[] vectors.
	 */
	tv_mode = emit_tags_vectors(arg, expr, &tags_count, &all_tags_count);

	/*
	 * Tags to elements map.
	 */
	emit_tag2member_map(arg, tag2el, tag2el_count, 0);

	if(!(expr->_type_referenced)) OUT("static ");
	OUT("asn_SEQUENCE_specifics_t asn_SPC_%s_specs_%d = {\n",
		MKID(expr), expr->_type_unique_index);
	INDENT(+1);
	OUT("sizeof(%s),\n", c_name(arg).full_name);
	OUT("offsetof(%s, _asn_ctx),\n", c_name(arg).full_name);
    emit_tag2member_reference(arg, expr, tag2el_count);
	if(roms_count + aoms_count) {
		OUT("asn_MAP_%s_oms_%d,\t/* Optional members */\n",
			MKID(expr), expr->_type_unique_index);
		OUT("%d, %d,\t/* Root/Additions */\n", roms_count, aoms_count);
	} else {
		OUT("0, 0, 0,\t/* Optional elements (not needed) */\n");
	}
	OUT("%d,\t/* First extension addition */\n", first_extension);
	INDENT(-1);
	OUT("};\n");

	/*
	 * Emit asn_DEF_xxx table.
	 */
	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, elements,
			ETD_HAS_SPECIFICS);

	REDIR(saved_target);

	if(tag2el) free(tag2el);

	return 0;
} /* _SEQUENCE_def() */

int
asn1c_lang_C_type_SET(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	long mcount;
	const char *id;
	int comp_mode = 0;	/* {root,ext=1,root,root,...} */
	int saved_target = arg->target->target;

	DEPENDENCIES;

	REDIR(OT_DEPS);

	OUT("\n");
	OUT("/*\n");
	OUT(" * Method of determining the components presence\n");
	OUT(" */\n");
	mcount = 0;
	OUT("typedef %s {\n", c_name(arg).presence_enum);
	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) continue;
		INDENTED(
			OUT("%s,", c_presence_name(arg, v));
			OUT("\t/* Member %s is present */\n", MKID(v));
		);
		mcount++;
	}
	OUT("} %s;\n", c_name(arg).presence_name);

	REDIR(saved_target);

	if(arg->embed) {
		if (expr->_anonymous_type) {
			REDIR(OT_FWD_DEFS);
			OUT("typedef ");
		}
		OUT("%s {\n", c_name(arg).full_name);
	} else {
		REDIR(OT_TYPE_DECLS);
		OUT("typedef %s {\n", c_name(arg).full_name);
	}

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE)
			if(comp_mode < 3) comp_mode++;
		if(comp_mode == 1)
			v->marker.flags |= EM_OMITABLE | EM_INDIRECT;
		try_inline_default(arg, v, 1);
		EMBED(v);
	}

	INDENTED(
		id = MKID(expr);
		OUT("\n");
		OUT("/* Presence bitmask: ASN_SET_ISPRESENT(p%s, %s_PR_x) */\n",
			id, id);
		OUT("unsigned int _presence_map\n");
		OUT("\t[((%ld+(8*sizeof(unsigned int))-1)/(8*sizeof(unsigned int)))];\n", mcount);
	);

	PCTX_DEF;

	if (arg->embed && expr->_anonymous_type) {
		OUT("} %s%s;\n", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).base_name);

		REDIR(saved_target);

		OUT("%s%s", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).base_name);
	} else {
		OUT("} %s%s", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).short_name);
	}

	return asn1c_lang_C_type_SET_def(arg);
}

static int
asn1c_lang_C_type_SET_def(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int elements;
	tag2el_t *tag2el = NULL;
	int tag2el_count = 0;
	tag2el_t *tag2el_cxer = NULL;
	int tag2el_cxer_count = 0;
	int tags_count;
	int all_tags_count;
	enum tvm_compat tv_mode;
	const char *p;
	int saved_target = arg->target->target;

	/*
	 * Fetch every inner tag from the tag to elements map.
	 */
	if(_fill_tag2el_map(arg, &tag2el, &tag2el_count, -1, FTE_ALLTAGS)) {
		if(tag2el) free(tag2el);
		return -1;
	}
	if(_fill_tag2el_map(arg, &tag2el_cxer, &tag2el_cxer_count, -1, FTE_CANONICAL_XER)) {
		if(tag2el) free(tag2el);
		if(tag2el_cxer) free(tag2el_cxer);
		return -1;
	}
	if(tag2el_cxer_count == tag2el_count
	&& memcmp(tag2el, tag2el_cxer, tag2el_count) == 0) {
		free(tag2el_cxer);
		tag2el_cxer = 0;
	}

	GEN_INCLUDE_STD("constr_SET");
	if(!arg->embed)
		GEN_DECLARE("SET", expr);	/* asn_DEF_xxx */

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which parsing is performed.
	 */
	if(expr_elements_count(arg, expr)) {
		int comp_mode = 0;	/* {root,ext=1,root,root,...} */

		if(!(expr->_type_referenced)) OUT("static ");
		OUT("asn_TYPE_member_t asn_MBR_%s_%d[] = {\n",
			c_name(arg).part_name, expr->_type_unique_index);

		elements = 0;
		INDENTED(TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) {
				if(comp_mode < 3) comp_mode++;
			} else {
				emit_member_table(arg, v, NULL);
				elements++;
			}
		});
		OUT("};\n");
	} else {
		elements = 0;
	}

	/*
	 * Print out asn_DEF_<type>_[all_]tags[] vectors.
	 */
	tv_mode = emit_tags_vectors(arg, expr, &tags_count, &all_tags_count);

	/*
	 * Tags to elements map.
	 */
	emit_tag2member_map(arg, tag2el, tag2el_count, 0);
	if(tag2el_cxer)
	emit_tag2member_map(arg, tag2el_cxer, tag2el_cxer_count, "_cxer");

	/*
	 * Emit a map of mandatory elements.
	 */
	OUT("static const uint8_t asn_MAP_%s_mmap_%d",
		MKID(expr), expr->_type_unique_index);
	p = MKID_safe(expr);
	OUT("[(%d + (8 * sizeof(unsigned int)) - 1) / 8]", elements);
	OUT(" = {\n");
	INDENTED(
	if(elements) {
		int el = 0;
		TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) continue;
			if(el) {
				if((el % 8) == 0)
					OUT(",\n");
				else
					OUT(" | ");
			}
			OUT("(%d << %d)",
				(v->marker.flags & EM_OMITABLE) != EM_OMITABLE,
				7 - (el % 8));
			el++;
		}
	} else {
		OUT("0");
	}
	);
	OUT("\n");
	OUT("};\n");

	if(!(expr->_type_referenced)) OUT("static \n");
	OUT("asn_SET_specifics_t asn_SPC_%s_specs_%d = {\n",
		MKID(expr), expr->_type_unique_index);
	INDENTED(
		OUT("sizeof(%s),\n", c_name(arg).full_name);
		OUT("offsetof(%s, _asn_ctx),\n", c_name(arg).full_name);
		OUT("offsetof(%s, _presence_map),\n", c_name(arg).full_name);
		emit_tag2member_reference(arg, expr, tag2el_count);
		p = MKID(expr);
		if(tag2el_cxer)
			OUT("asn_MAP_%s_tag2el_cxer_%d,\n",
				p, expr->_type_unique_index);
		else
			OUT("asn_MAP_%s_tag2el_%d,\t/* Same as above */\n",
				p, expr->_type_unique_index);
		OUT("%d,\t/* Count of tags in the CXER map */\n",
			tag2el_cxer_count);
		OUT("%d,\t/* Whether extensible */\n",
			compute_extensions_start(expr) == -1 ? 0 : 1);
		OUT("(const unsigned int *)asn_MAP_%s_mmap_%d\t/* Mandatory elements map */\n",
			p, expr->_type_unique_index);
	);
	OUT("};\n");

	/*
	 * Emit asn_DEF_xxx table.
	 */
	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, elements,
			ETD_HAS_SPECIFICS);

	REDIR(saved_target);

	if (tag2el) free(tag2el);
	if (tag2el_cxer) free(tag2el_cxer);

	return 0;
} /* _SET_def() */

int
asn1c_lang_C_type_SEx_OF(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *memb = TQ_FIRST(&expr->members);
	int saved_target = arg->target->target;

	DEPENDENCIES;

	if(arg->embed) {
		if (expr->_anonymous_type) {
			REDIR(OT_FWD_DEFS);
			OUT("typedef ");
		}
		OUT("%s {\n", c_name(arg).full_name);
	} else {
		OUT("typedef %s {\n", c_name(arg).full_name);
	}

	INDENT(+1);
	OUT("A_%s_OF(",
		(arg->expr->expr_type == ASN_CONSTR_SET_OF)
			? "SET" : "SEQUENCE");

	/*
	 * README README
	 * The implementation of the A_SET_OF() macro is already indirect.
	 */
	memb->marker.flags |= EM_INDIRECT;

	if(memb->expr_type & ASN_CONSTR_MASK
	|| ((memb->expr_type == ASN_BASIC_ENUMERATED
		|| (0 /* -- prohibited by X.693:8.3.4 */
			&& memb->expr_type == ASN_BASIC_INTEGER))
	    	&& expr_elements_count(arg, memb))) {
		arg_t tmp;
		asn1p_expr_t *tmp_memb = memb;
		enum asn1p_expr_marker_e flags = memb->marker.flags;
		arg->embed++;
			tmp = *arg;
			tmp.expr = tmp_memb;
			tmp_memb->marker.flags &= ~EM_INDIRECT;
			tmp_memb->_anonymous_type = 1;
			if(tmp_memb->Identifier == 0) {
				tmp_memb->Identifier = strdup("Member");
				if(0)
				tmp_memb->Identifier = strdup(
					asn1c_make_identifier(0,
						expr, "Member", 0));
				assert(tmp_memb->Identifier);
			}
			tmp.default_cb(&tmp, NULL);
			tmp_memb->marker.flags = flags;
		arg->embed--;
		assert(arg->target->target == OT_TYPE_DECLS ||
				arg->target->target == OT_FWD_DEFS);
	} else {
		OUT("%s", asn1c_type_name(arg, memb,
			(memb->marker.flags & EM_UNRECURSE)
				? TNF_RSAFE : TNF_CTYPE));
	}
	/* README README (above) */
	if(0 && (memb->marker.flags & EM_INDIRECT))
		OUT(" *");
	OUT(") list;\n");
	INDENT(-1);

	PCTX_DEF;

	if (arg->embed && expr->_anonymous_type) {
		OUT("} %s%s;\n", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).base_name);

		REDIR(saved_target);

		OUT("%s%s", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).base_name);
	} else {
		OUT("} %s%s", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).short_name);
	}

	/*
	 * SET OF/SEQUENCE OF definition
	 */
	return asn1c_lang_C_type_SEx_OF_def(arg,
		(arg->expr->expr_type == ASN_CONSTR_SEQUENCE_OF));
}

static int
asn1c_lang_C_type_SEx_OF_def(arg_t *arg, int seq_of) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int tags_count;
	int all_tags_count;
	enum tvm_compat tv_mode;
	int saved_target = arg->target->target;

	/*
	 * Print out the table according to which parsing is performed.
	 */
	if(seq_of) {
		GEN_INCLUDE_STD("constr_SEQUENCE_OF");
	} else {
		GEN_INCLUDE_STD("constr_SET_OF");
	}
	if(!arg->embed)
		GEN_DECLARE("SET_OF", expr);	/* asn_DEF_xxx */

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which parsing is performed.
	 */
	if(!(expr->_type_referenced)) OUT("static ");
	OUT("asn_TYPE_member_t asn_MBR_%s_%d[] = {\n",
		c_name(arg).part_name, expr->_type_unique_index);
	INDENT(+1);
		v = TQ_FIRST(&(expr->members));
		if(!v->Identifier) {
			v->Identifier = strdup("Member");
			assert(v->Identifier);
		}
		v->_anonymous_type = 1;
		arg->embed++;
		emit_member_table(arg, v, NULL);
		arg->embed--;
		free(v->Identifier);
		v->Identifier = (char *)NULL;
	INDENT(-1);
	OUT("};\n");

	/*
	 * Print out asn_DEF_<type>_[all_]tags[] vectors.
	 */
	tv_mode = emit_tags_vectors(arg, expr, &tags_count, &all_tags_count);

	if(!(expr->_type_referenced)) OUT("static ");
	OUT("asn_SET_OF_specifics_t asn_SPC_%s_specs_%d = {\n",
		MKID(expr), expr->_type_unique_index);
	INDENTED(
		OUT("sizeof(%s),\n", c_name(arg).full_name);
		OUT("offsetof(%s, _asn_ctx),\n", c_name(arg).full_name);
		{
		int as_xvl = expr_as_xmlvaluelist(arg, v);
		OUT("%d,\t/* XER encoding is %s */\n",
			as_xvl,
			as_xvl ? "XMLValueList" : "XMLDelimitedItemList");
		}
	);
	OUT("};\n");

	/*
	 * Emit asn_DEF_xxx table.
	 */
	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, 1,
			ETD_HAS_SPECIFICS);

	REDIR(saved_target);

	return 0;
} /* _SEx_OF_def() */

int
asn1c_lang_C_type_CHOICE(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int saved_target = arg->target->target;

	DEPENDENCIES;

	REDIR(OT_DEPS);

	OUT("typedef %s {\n", c_name(arg).presence_enum);
	INDENTED(
		int skipComma = 1;
        OUT("%s,\t/* No components present */\n", c_presence_name(arg, 0));
		TQ_FOR(v, &(expr->members), next) {
			if(skipComma) skipComma = 0;
			else if (v->expr_type == A1TC_EXTENSIBLE && !TQ_NEXT(v, next)) OUT("\n");
			else OUT(",\n");
			if(v->expr_type == A1TC_EXTENSIBLE) {
				OUT("/* Extensions may appear below */\n");
				skipComma = 1;
				continue;
			}
            OUT("%s", c_presence_name(arg, v));
		}
		OUT("\n");
	);
	OUT("} %s;\n", c_name(arg).presence_name);

	REDIR(saved_target);

	if(arg->embed) {
		if (expr->_anonymous_type) {
			REDIR(OT_FWD_DEFS);
			OUT("typedef ");
		}
		OUT("%s {\n", c_name(arg).full_name);
	} else {
		REDIR(OT_TYPE_DECLS);
		OUT("typedef %s {\n", c_name(arg).full_name);
	}

	INDENTED(
		OUT("%s present;\n", c_name(arg).presence_name);
		OUT("union ");
		if(UNNAMED_UNIONS == 0) {
			out_name_chain(arg, ONC_force_compound_name);
			OUT("_u ");
		}
		OUT("{\n");
		TQ_FOR(v, &(expr->members), next) {
			EMBED(v);
		}
		if(UNNAMED_UNIONS)	OUT("};\n");
		else			OUT("} choice;\n");
	);

	PCTX_DEF;

	if (arg->embed && expr->_anonymous_type) {
		OUT("} %s%s;\n", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).base_name);

		REDIR(saved_target);

		OUT("%s%s", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).base_name);
	} else {
		OUT("} %s%s", (expr->marker.flags & EM_INDIRECT)?"*":"",
			c_name(arg).short_name);
	}

	return asn1c_lang_C_type_CHOICE_def(arg);
}

static ssize_t
find_column_index(arg_t *arg, asn1c_ioc_table_and_objset_t *opt_ioc, const char *column_name) {
    (void)arg;

    if(!opt_ioc || !opt_ioc->ioct || !column_name) {
        return -1;
    }

    if(opt_ioc->ioct->rows == 0) {
        return 0;   /* No big deal. Just no data */
    } else {
        for(size_t clmn = 0; clmn < opt_ioc->ioct->row[0]->columns; clmn++) {
            if(strcmp(opt_ioc->ioct->row[0]->column[clmn].field->Identifier,
                      column_name) == 0) {
                return clmn;
            }
        }
        return -1;
    }

}

static int
asn1c_lang_C_OpenType(arg_t *arg, asn1c_ioc_table_and_objset_t *opt_ioc,
                      const char *column_name) {
    arg_t tmp_arg = *arg;

    ssize_t column_index = find_column_index(arg, opt_ioc, column_name);
    if(column_index < 0) {
        FATAL("Open type generation attempted for %s, incomplete", column_name);
        return -1;
    }

    asn1p_expr_t *open_type_choice =
        asn1p_expr_new(arg->expr->_lineno, arg->expr->module);

    open_type_choice->Identifier = strdup(arg->expr->Identifier);
    open_type_choice->meta_type = AMT_TYPE;
    open_type_choice->expr_type = ASN_CONSTR_OPEN_TYPE;
    open_type_choice->_type_unique_index = arg->expr->_type_unique_index;
    open_type_choice->parent_expr = arg->expr->parent_expr;

    for(size_t row = 0; row < opt_ioc->ioct->rows; row++) {
        struct asn1p_ioc_cell_s *cell =
            &opt_ioc->ioct->row[row]->column[column_index];

        if(!cell->value) continue;

        asn1p_expr_t *m = asn1p_expr_clone(cell->value, 0);
        if (asn1p_lookup_child(open_type_choice, m->Identifier))
            m->_mark |= TM_SKIPinUNION;
        asn1p_expr_add(open_type_choice, m);
    }

    tmp_arg.expr = open_type_choice;
    GEN_INCLUDE_STD("OPEN_TYPE");
    asn1c_lang_C_type_CHOICE(&tmp_arg);
    asn1p_expr_free(tmp_arg.expr);
    return 0;
}

static int
asn1c_lang_C_type_CHOICE_def(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int elements;	/* Number of elements */
	tag2el_t *tag2el = NULL;
	int tag2el_count = 0;
	int tags_count;
	int all_tags_count;
	enum tvm_compat tv_mode;
	int *cmap = 0;
	int saved_target = arg->target->target;

	/*
	 * Fetch every inner tag from the tag to elements map.
	 */
	if(_fill_tag2el_map(arg, &tag2el, &tag2el_count, -1, FTE_ALLTAGS)) {
		if(tag2el) free(tag2el);
		return -1;
	}

	GEN_INCLUDE_STD("constr_CHOICE");
	if(!arg->embed)
		GEN_DECLARE("CHOICE", expr);	/* asn_DEF_xxx */

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which parsing is performed.
	 */
	if(expr_elements_count(arg, expr)) {

		if(!(expr->_type_referenced)) OUT("static ");
		OUT("asn_TYPE_member_t asn_MBR_%s_%d[] = {\n",
			c_name(arg).part_name, expr->_type_unique_index);

		elements = 0;
		INDENTED(TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE)
				continue;
			emit_member_table(arg, v, NULL);
			elements++;
		});
		OUT("};\n");
	} else {
		elements = 0;
	}

    /* Create a canonical elements map */
    if(elements && (arg->flags & A1C_GEN_PER)) {
        cmap = compute_canonical_members_order(arg, elements);
        if(cmap) {
            OUT("static const unsigned asn_MAP_%s_to_canonical_%d[] = {",
                MKID(expr), expr->_type_unique_index);
            for(int i = 0; i < elements; i++) {
                if(i) OUT(",");
                OUT(" %d", cmap[i]);
            }
            OUT(" };\n");
            OUT("static const unsigned asn_MAP_%s_from_canonical_%d[] = {",
                MKID(expr), expr->_type_unique_index);
            for(int i = 0; i < elements; i++) {
                if(i) OUT(",");
                int j;
                for(j = 0; j < elements; j++) {
                    if(cmap[j] == i) {
                        OUT(" %d", j);
                        break;
                    }
                }
                assert(j < elements);
            }
            OUT(" };\n");
            free(cmap);
        }
    }

	if(arg->embed) {
		/*
		 * Our parent structure has already taken this into account.
		 */
		tv_mode = _TVM_SAME;
		tags_count = all_tags_count = 0;
	} else {
		tv_mode = emit_tags_vectors(arg, expr,
			&tags_count, &all_tags_count);
	}

	/*
	 * Tags to elements map.
	 */
	emit_tag2member_map(arg, tag2el, tag2el_count, 0);

    if(!(expr->_type_referenced)) OUT("static ");
    OUT("asn_CHOICE_specifics_t asn_SPC_%s_specs_%d = {\n", MKID(expr),
        expr->_type_unique_index);
    INDENTED(
        OUT("sizeof(%s),\n", c_name(arg).full_name);
        OUT("offsetof(%s, _asn_ctx),\n", c_name(arg).full_name);
        OUT("offsetof(%s, present),\n", c_name(arg).full_name);
        OUT("sizeof(((%s *)0)->present),\n", c_name(arg).full_name);
        emit_tag2member_reference(arg, expr, tag2el_count);
        if(cmap) {
            if(C99_MODE) OUT(".to_canonical_order = ");
            OUT("asn_MAP_%s_to_canonical_%d,\n", MKID(expr),
                expr->_type_unique_index);
            if(C99_MODE) OUT(".from_canonical_order = ");
            OUT("asn_MAP_%s_from_canonical_%d,\n", MKID(expr),
                expr->_type_unique_index);
        } else { OUT("0, 0,\n"); }
        if(C99_MODE) OUT(".first_extension = ");
        OUT("%d\t/* Extensions start */\n", compute_extensions_start(expr));
    );
    OUT("};\n");

	/*
	 * Emit asn_DEF_xxx table.
	 */
	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, elements,
			ETD_HAS_SPECIFICS);

	REDIR(saved_target);

	if (tag2el) free(tag2el);

	return 0;
} /* _CHOICE_def() */

int
asn1c_lang_C_type_REFERENCE(arg_t *arg) {
	asn1p_ref_t *ref;

	ref = arg->expr->reference;
	if(ref->components[ref->comp_count-1].name[0] == '&') {
		asn1p_expr_t *extract;
		arg_t tmp;
		int ret;

        extract = WITH_MODULE_NAMESPACE(
            arg->expr->module, expr_ns,
            asn1f_class_access_ex(arg->asn, arg->expr->module, expr_ns,
                                  arg->expr, arg->expr->rhs_pspecs, ref));
        if(extract == NULL)
			return -1;

		extract = asn1p_expr_clone(extract, 0);
		if(extract) {
			free(extract->Identifier);
			extract->Identifier = strdup(arg->expr->Identifier);
			if(extract->Identifier == NULL) {
				asn1p_expr_free(extract);
				return -1;
			}
		} else {
			return -1;
		}

		tmp = *arg;
		tmp.asn = arg->asn;
		tmp.expr = extract;

		ret = arg->default_cb(&tmp, NULL);

		asn1p_expr_free(extract);

		return ret;
	}


	return asn1c_lang_C_type_SIMPLE_TYPE(arg);
}

int
asn1c_lang_C_type_SIMPLE_TYPE(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	int tags_count;
	int all_tags_count;
	enum tvm_compat tv_mode;
	enum etd_spec etd_spec;
	const char *p;
	int saved_target = arg->target->target;

	if(arg->embed) {
		enum tnfmt tnfmt = TNF_CTYPE;

		/*
		 * If this is an optional compound type,
		 * refer it using "struct X" convention,
		 * as it may recursively include the current structure.
		 */
		if(expr->marker.flags & (EM_INDIRECT | EM_UNRECURSE)) {
			if(terminal_structable(arg, expr)) {
				tnfmt = TNF_RSAFE;
				if(saved_target != OT_FWD_DECLS) {
					REDIR(OT_FWD_DECLS);
					OUT("%s;\n",
						asn1c_type_name(arg, arg->expr, tnfmt));
				}
				REDIR(saved_target);
			}
		}

		if(!(expr->_mark & TM_SKIPinUNION))
			OUT("%s", asn1c_type_name(arg, arg->expr, tnfmt));

		if(!expr->_anonymous_type) {
			if(!(expr->_mark & TM_SKIPinUNION)) {
				OUT("%s", (expr->marker.flags&EM_INDIRECT)?"\t*":"\t ");
				OUT("%s", MKID_safe(expr));
			}
			if((expr->marker.flags & (EM_DEFAULT & ~EM_INDIRECT))
					== (EM_DEFAULT & ~EM_INDIRECT))
				OUT("\t/* DEFAULT %s */",
					asn1f_printable_value(
						expr->marker.default_value));
			else if((expr->marker.flags & EM_OPTIONAL)
					== EM_OPTIONAL)
				OUT("\t/* OPTIONAL */");
		}

	} else {
		GEN_INCLUDE(asn1c_type_name(arg, expr, TNF_INCLUDE));

		REDIR(OT_TYPE_DECLS);

		OUT("typedef %s\t",
			asn1c_type_name(arg, arg->expr, TNF_CTYPE));
		OUT("%s%s_t",
			(expr->marker.flags & EM_INDIRECT)?"*":" ",
			MKID(expr));
	}

	if((expr->expr_type == ASN_BASIC_ENUMERATED)
	|| (0 /* -- prohibited by X.693:8.3.4 */
		&& expr->expr_type == ASN_BASIC_INTEGER
		&& expr_elements_count(arg, expr))
	|| (expr->expr_type == ASN_BASIC_INTEGER
		&& asn1c_type_fits_long(arg, expr) == FL_FITS_UNSIGN)
	|| asn1c_REAL_fits(arg, expr) == RL_FITS_FLOAT32
	)
		etd_spec = ETD_HAS_SPECIFICS;
	else
		etd_spec = ETD_NO_SPECIFICS;

	/*
	 * If this type just blindly refers the other type, alias it.
	 * 	Type1 ::= Type2
	 */
	if(arg->embed && etd_spec == ETD_NO_SPECIFICS) {
		REDIR(saved_target);
		return 0;
	}

	REDIR(OT_CODE);

	/*
	 * Constraint checking.
	 */
	if(!(arg->flags & A1C_NO_CONSTRAINTS) && expr->combined_constraints) {
		p = MKID(expr);
		if(HIDE_INNER_DEFS) OUT("static ");
		OUT("int\n");
		OUT("%s", p);
		if(HIDE_INNER_DEFS) OUT("_%d", expr->_type_unique_index);
		OUT("_constraint(const asn_TYPE_descriptor_t *td, const void *sptr,\n");
		INDENT(+1);
		OUT("\t\tasn_app_constraint_failed_f *ctfailcb, void *app_key) {");
		OUT("\n");
		DEBUG("expr constraint checking code for %s", p);
		if(asn1c_emit_constraint_checking_code(arg) == 1) {
			OUT("return td->encoding_constraints.general_constraints"
				"(td, sptr, ctfailcb, app_key);\n");
		}
		INDENT(-1);
		OUT("}\n");
		OUT("\n");
	}

	REDIR(OT_STAT_DEFS);

    /*
     * By default, NativeReal is double. We only override this if
     * (OER) constraints suggested that we may use float.
     */
	if(asn1c_REAL_fits(arg, expr) == RL_FITS_FLOAT32) {
		if(!(expr->_type_referenced)) OUT("static ");
		OUT("const asn_NativeReal_specifics_t asn_SPC_%s_specs_%d = {\n",
			MKID(expr), expr->_type_unique_index);
		INDENT(+1);
		OUT("4\t/* Use 'float' type. */\n");
		INDENT(-1);
		OUT("};\n");
	}

	/*
	 * Print out asn_DEF_<type>_[all_]tags[] vectors.
	 */
	tv_mode = emit_tags_vectors(arg, expr, &tags_count, &all_tags_count);
	DEBUG("emit tag vectors for %s %d, %d, %d", expr->Identifier,
		tv_mode, tags_count, all_tags_count);

	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count,
		0, etd_spec);

	REDIR(OT_CODE);

	/*
	 * Emit suicidal functions.
	 */

	/*
	 * This function replaces certain fields from the definition
	 * of a type with the corresponding fields from the basic type
	 * (from which the current type is inherited).
	 */
	OUT("/*\n");
	OUT(" * This type is implemented using %s,\n", c_name(arg).type.base_name);
	OUT(" * so here we adjust the DEF accordingly.\n");
	OUT(" */\n");

	REDIR(OT_FUNC_DECLS);

	p = MKID(expr);
	if(HIDE_INNER_DEFS) {
		OUT("/* extern asn_TYPE_descriptor_t asn_DEF_%s_%d;"
			"\t// (Use -fall-defs-global to expose) */\n",
			p, expr->_type_unique_index);
	} else {
		OUT("extern asn_TYPE_descriptor_t asn_DEF_%s;\n", p);
        if(etd_spec == ETD_HAS_SPECIFICS && expr->_type_referenced) {
            if((expr->expr_type == ASN_BASIC_ENUMERATED)
               || (expr->expr_type == ASN_BASIC_INTEGER)) {
                OUT("extern const asn_INTEGER_specifics_t "
                    "asn_SPC_%s_specs_%d;\n",
                    c_name(arg).base_name, expr->_type_unique_index);
            } else {
                asn1p_expr_t *terminal = WITH_MODULE_NAMESPACE(
                    expr->module, expr_ns,
                    asn1f_find_terminal_type_ex(arg->asn, expr_ns, expr));
                OUT("extern const asn_%s_specifics_t ",
                    asn1c_type_name(arg, terminal, TNF_SAFE));
                OUT("asn_SPC_%s_specs_%d;\n", MKID(expr),
                    expr->_type_unique_index);
            }
        }
		OUT("asn_struct_free_f %s_free;\n", p);
		OUT("asn_struct_print_f %s_print;\n", p);
		OUT("asn_constr_check_f %s_constraint;\n", p);
		OUT("ber_type_decoder_f %s_decode_ber;\n", p);
		OUT("der_type_encoder_f %s_encode_der;\n", p);
		OUT("xer_type_decoder_f %s_decode_xer;\n", p);
		OUT("xer_type_encoder_f %s_encode_xer;\n", p);
		if(arg->flags & A1C_GEN_OER) {
		OUT("oer_type_decoder_f %s_decode_oer;\n", p);
		OUT("oer_type_encoder_f %s_encode_oer;\n", p);
		}
		if(arg->flags & A1C_GEN_PER) {
		OUT("per_type_decoder_f %s_decode_uper;\n", p);
		OUT("per_type_encoder_f %s_encode_uper;\n", p);
		}
	}

	REDIR(saved_target);

	return 0;
}

int
asn1c_lang_C_type_EXTENSIBLE(arg_t *arg) {

	OUT("/*\n");
	OUT(" * This type is extensible,\n");
	OUT(" * possible extensions are below.\n");
	OUT(" */\n");

	return 0;
}

static int
compute_extensions_start(asn1p_expr_t *expr) {
	asn1p_expr_t *v;
	int eidx = 0;
	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE)
			return eidx;
		eidx++;
	}
	return -1;
}

static int
_print_tag(arg_t *arg, struct asn1p_type_tag_s *tag) {

	OUT("(");
	switch(tag->tag_class) {
	case TC_UNIVERSAL:		OUT("ASN_TAG_CLASS_UNIVERSAL"); break;
	case TC_APPLICATION:		OUT("ASN_TAG_CLASS_APPLICATION"); break;
	case TC_CONTEXT_SPECIFIC:	OUT("ASN_TAG_CLASS_CONTEXT"); break;
	case TC_PRIVATE:		OUT("ASN_TAG_CLASS_PRIVATE"); break;
	case TC_NOCLASS:
		break;
	}
	OUT(" | (%s << 2))", asn1p_itoa(tag->tag_value));

	return 0;
}


static int
_tag2el_cmp(const void *ap, const void *bp) {
	const tag2el_t *a = ap;
	const tag2el_t *b = bp;
	const struct asn1p_type_tag_s *ta = &a->el_tag;
	const struct asn1p_type_tag_s *tb = &b->el_tag;

	if(ta->tag_class == tb->tag_class) {
		if(ta->tag_value == tb->tag_value) {
			/*
			 * Sort by their respective positions.
			 */
			if(a->el_no < b->el_no)
				return -1;
			else if(a->el_no > b->el_no)
				return 1;
			return 0;
		} else if(ta->tag_value < tb->tag_value)
			return -1;
		else
			return 1;
	} else if(ta->tag_class < tb->tag_class) {
		return -1;
	} else {
		return 1;
	}
}

/*
 * For constructed types, number of external tags may be greater than
 * number of elements in the type because of CHOICE type.
 * T ::= SET {		-- Three possible tags:
 *     a INTEGER,	-- One tag is here...
 *     b Choice1	-- ... and two more tags are there.
 * }
 * Choice1 ::= CHOICE {
 *     s1 IA5String,
 *     s2 ObjectDescriptor
 * }
 */
static int
_fill_tag2el_map(arg_t *arg, tag2el_t **tag2el, int *count, int el_no, fte_e flags) {
	asn1p_expr_t *expr = arg->expr;
	arg_t tmparg = *arg;
	asn1p_expr_t *v;
	int element = 0;
	int original_count = *count;
	int sort_until = -1;

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			/*
			 * CXER mandates sorting
			 * only for the root part.
			 */
			if(flags == FTE_CANONICAL_XER
			&& sort_until == -1)
				sort_until = *count;
			continue;
		}

		tmparg.expr = v;

		if(_add_tag2el_member(&tmparg, tag2el, count,
				(el_no==-1)?element:el_no, flags)) {
			return -1;
		}

		element++;
	}


	if(flags == FTE_CANONICAL_XER) {
		if(sort_until == -1) sort_until = *count;
		qsort((*tag2el) + original_count,
			sort_until - original_count,
				sizeof(**tag2el), _tag2el_cmp);
		if(arg->expr->expr_type == ASN_CONSTR_CHOICE
		&& (sort_until - original_count) >= 1) {
			/* Only take in account the root component */
			*count = original_count + 1;
		}
	} else {
		/*
		 * Sort the map according to canonical order of their
		 * tags and element numbers.
		 */
		qsort(*tag2el, *count, sizeof(**tag2el), _tag2el_cmp);
	}

	/*
	 * Initialize .toff_{first|last} members.
	 */
	if(*count) {
		struct asn1p_type_tag_s *cur_tag = 0;
		tag2el_t *cur = *tag2el;
		tag2el_t *end = cur + *count;
		int occur, i;
		for(occur = 0; cur < end; cur++) {
			if(cur_tag == 0
			|| cur_tag->tag_value != cur->el_tag.tag_value
			|| cur_tag->tag_class != cur->el_tag.tag_class) {
				cur_tag = &cur->el_tag;
				occur = 0;
			} else {
				occur++;
			}
			cur->toff_first = -occur;
			for(i = 0; i >= -occur; i--)
				cur[i].toff_last = -i;
		}
	}

	return 0;
}

static int
_add_tag2el_member(arg_t *arg, tag2el_t **tag2el, int *count, int el_no, fte_e flags) {
	struct asn1p_type_tag_s tag;
	int ret;

	assert(el_no >= 0);

    ret = WITH_MODULE_NAMESPACE(
        arg->expr->module, expr_ns,
        asn1f_fetch_outmost_tag(arg->asn, expr_ns, arg->expr->module, arg->expr,
                                &tag, AFT_IMAGINARY_ANY));
    if(ret == 0) {
		tag2el_t *te;
		int new_count = (*count) + 1;
		void *p;

		if(tag.tag_value == -1) {
			/*
			 * This is an untagged ANY type,
			 * proceed without adding a tag
			 */
			return 0;
		}

		p = realloc(*tag2el, new_count * sizeof(tag2el_t));
		if(p)	*tag2el = p;
		else	return -1;

		if(0) DEBUG("Found tag for %s: %ld",
			arg->expr->Identifier,
			(long)tag.tag_value);

		te = &((*tag2el)[*count]);
		te->el_tag = tag;
		te->el_no = el_no;
		te->from_expr = arg->expr;
		*count = new_count;
		return 0;
	}

	DEBUG("Searching tag in complex expression %s:%x at line %d",
		arg->expr->Identifier,
		arg->expr->expr_type,
		arg->expr->_lineno);

	/*
	 * Iterate over members of CHOICE type.
	 */
	if(arg->expr->expr_type == ASN_CONSTR_CHOICE) {
		return _fill_tag2el_map(arg, tag2el, count, el_no, flags);
	}

	if(arg->expr->expr_type == A1TC_REFERENCE) {
		arg_t tmp = *arg;
		asn1p_expr_t *expr;
        expr = WITH_MODULE_NAMESPACE(
            tmp.expr->module, expr_ns,
            asn1f_lookup_symbol_ex(tmp.asn, expr_ns, tmp.expr,
                                   arg->expr->reference));
        if(expr) {
			tmp.expr = expr;
			return _add_tag2el_member(&tmp, tag2el, count, el_no, flags);
		} else {
			FATAL("Cannot dereference %s at line %d",
				arg->expr->Identifier,
				arg->expr->_lineno);
			return -1;
		}
	}

	DEBUG("No tag for %s at line %d",
		arg->expr->Identifier,
		arg->expr->_lineno);

	return -1;
}

static int
emit_tag2member_map(arg_t *arg, tag2el_t *tag2el, int tag2el_count, const char *opt_modifier) {
	asn1p_expr_t *expr = arg->expr;
	int i;

	if(!tag2el_count) return 0;	/* No top level tags */

	OUT("static const asn_TYPE_tag2member_t asn_MAP_%s_tag2el%s_%d[] = {\n",
		MKID(expr), opt_modifier?opt_modifier:"",
		expr->_type_unique_index);
	for(i = 0; i < tag2el_count; i++) {
		OUT("    { ");
		_print_tag(arg, &tag2el[i].el_tag);
		OUT(", ");
		OUT("%d, ", tag2el[i].el_no);
		OUT("%d, ", tag2el[i].toff_first);
		OUT("%d ", tag2el[i].toff_last);
		OUT("}%s /* %s",
			(i + 1 < tag2el_count) ? "," : "",
			tag2el[i].from_expr->Identifier);
        if(arg->flags & A1C_LINE_REFS)
            OUT("at %d", tag2el[i].from_expr->_lineno);
        OUT(" */\n");
	}
	OUT("};\n");

	return 0;
}

static enum tvm_compat
emit_tags_vectors(arg_t *arg, asn1p_expr_t *expr, int *tags_count_r, int *all_tags_count_r) {
	struct asn1p_type_tag_s *tags = 0;	/* Effective tags */
	struct asn1p_type_tag_s *all_tags = 0;	/* The full array */
	int tags_count = 0;
	int all_tags_count = 0;
	enum tvm_compat tv_mode = _TVM_SAME;
	int i;

	/* Cleanup before proceeding. */
	*tags_count_r = 0;
	*all_tags_count_r = 0;

	/* Fetch a chain of tags */
    tags_count = WITH_MODULE_NAMESPACE(
        expr->module, expr_ns,
        asn1f_fetch_tags(arg->asn, expr_ns, expr->module, expr, &tags, 0));
    if(tags_count < 0) {
		DEBUG("fail to fetch tags for %s", expr->Identifier);
		return -1;
	}

	/* Fetch a chain of tags */
    all_tags_count = WITH_MODULE_NAMESPACE(
        expr->module, expr_ns,
        asn1f_fetch_tags(arg->asn, expr_ns, expr->module, expr, &all_tags,
                         AFT_FULL_COLLECT));
    if(all_tags_count < 0) {
		free(tags);
		DEBUG("fail to fetch tags chain for %s", expr->Identifier);
		return -1;
	}

	assert(tags_count <= all_tags_count);
	assert((tags_count?0:1) == (all_tags_count?0:1));

	if(tags_count <= all_tags_count) {
		for(i = 0; i < tags_count; i++) {
			if(tags[i].tag_value != all_tags[i].tag_value
			|| tags[i].tag_class != all_tags[i].tag_class) {
				tv_mode = _TVM_DIFFERENT;
				break;
			}
		}
		if(i == tags_count && tags_count < all_tags_count)
			tv_mode = _TVM_SUBSET;
	} else {
		tv_mode = _TVM_DIFFERENT;
	}

#define	EMIT_TAGS_TABLE(name, tags, tags_count)	do {			\
		OUT("static const ber_tlv_tag_t asn_DEF_%s%s_tags_%d[] = {\n",\
			MKID(expr), name,			\
			expr->_type_unique_index);			\
		INDENT(+1);						\
		/* Print the array of collected tags */			\
		for(i = 0; i < tags_count; i++) {			\
			if(i) OUT(",\n");				\
			_print_tag(arg, &tags[i]);			\
		}							\
		OUT("\n");						\
		INDENT(-1);						\
		OUT("};\n");						\
	} while(0)

	if(tags_count) {
		if(tv_mode == _TVM_SUBSET)
			EMIT_TAGS_TABLE("", all_tags, all_tags_count);
		else
			EMIT_TAGS_TABLE("", tags, tags_count);
	}

	if(all_tags_count) {
		if(tv_mode == _TVM_DIFFERENT)
			EMIT_TAGS_TABLE("_all", all_tags, all_tags_count);
	}

	free(tags);
	free(all_tags);

	*tags_count_r = tags_count;
	*all_tags_count_r = all_tags_count;

	return tv_mode;
}

static int
expr_elements_count(arg_t *arg, asn1p_expr_t *expr) {
	asn1p_expr_t *topmost_parent;
	asn1p_expr_t *v;
	int elements = 0;

    topmost_parent = WITH_MODULE_NAMESPACE(
        expr->module, expr_ns,
        asn1f_find_terminal_type_ex(arg->asn, expr_ns, expr));
    if(!topmost_parent) return 0;

	if(!(topmost_parent->expr_type & ASN_CONSTR_MASK)
	&& !(topmost_parent->expr_type == ASN_BASIC_INTEGER)
	&& !(topmost_parent->expr_type == ASN_BASIC_ENUMERATED)
	&& !(topmost_parent->expr_type == ASN_BASIC_BIT_STRING))
		return 0;

	TQ_FOR(v, &(topmost_parent->members), next) {
		if(v->expr_type != A1TC_EXTENSIBLE)
			elements++;
	}

	return elements;
}

static asn1p_expr_type_e
expr_get_type(arg_t *arg, asn1p_expr_t *expr) {
	asn1p_expr_t *terminal;
	terminal = asn1f_find_terminal_type_ex(arg->asn, arg->ns, expr);
	if(terminal) return terminal->expr_type;
	return A1TC_INVALID;
}

static asn1c_integer_t
PER_FROM_alphabet_characters(asn1cnst_range_t *range) {
	asn1c_integer_t numchars = 0;
	if(range->el_count) {
		int i;
		for(i = 0; i < range->el_count; i++)
			numchars
			+= PER_FROM_alphabet_characters(range->elements[i]);
	} else {
		assert(range->left.type == ARE_VALUE);
		assert(range->right.type == ARE_VALUE);
		numchars = 1 + (range->right.value - range->left.value);
	}
	return numchars;
}

static void
emit_single_member_OER_constraint_comment(arg_t *arg, asn1cnst_range_t *range, char *type) {

	/*
	 * Print some courtesy debug information.
	 */
    if(range
       && (range->left.type == ARE_VALUE || range->right.type == ARE_VALUE)) {
        OUT("\t/* ");
		if(type) OUT("(%s", type);
		OUT("(");
		if(range->left.type == ARE_VALUE)
			OUT("%s", asn1p_itoa(range->left.value));
		else
			OUT("MIN");
		OUT("..");
		if(range->right.type == ARE_VALUE)
			OUT("%s", asn1p_itoa(range->right.value));
		else
			OUT("MAX");
		if(range->extensible) OUT(",...");
		if(type) OUT(")");
		OUT(") */");
	}
}

static int
emit_single_member_OER_constraint_value(arg_t *arg, asn1cnst_range_t *range) {
    if(!range) {
        /* oer_support.h: asn_oer_constraint_s */
        OUT("{ 0, 0 }");
        return 0;
    }

	if(range->incompatible || range->not_OER_visible) {
		OUT("{ 0, 0 }");
    } else if(expr_get_type(arg, arg->expr) == ASN_BASIC_REAL) {
        if(range->narrowing == NARROW_FLOAT32) {
            OUT("{ sizeof(float), 0 }");
        } else if(range->narrowing == NARROW_DOUBLE64) {
            OUT("{ sizeof(double), 0 }");
        } else {
            OUT("{ 0, 0 }");
        }
    } else if(range->left.type == ARE_VALUE && range->left.value >= 0
              && range->right.type == ARE_MAX) {
        OUT("{ 0, 1 }");
	} else if(range->left.type == ARE_VALUE &&
            range->right.type == ARE_VALUE) {
        asn1c_integer_t lb = range->left.value;
        asn1c_integer_t ub = range->right.value;
        unsigned width = 0;
        unsigned positive = 0;


        if(lb >= 0) {
            /* X.969 08/2015 10.2(a) */
            if(ub <= 255) {
                width = 1;
            } else if(ub <= 65535) {
                width = 2;
            } else if((unsigned long long)ub <= 4294967295UL) {
                width = 4;
            } else if((unsigned long long)ub <= 18446744073709551615ULL) {
                width = 8;
            }
            positive = 1;
        } else {
            positive = 0;
            /* X.969 08/2015 10.2(b) - no lower bound or negative lower bound */
            if(lb >= -128 && ub <= 127) {
                width = 1;
            } else if(lb >= -32768 && ub <= 32767) {
                width = 2;
            } else if(lb >= -2147483648L && ub <= 2147483647L) {
                width = 4;
            } else if(lb >= (-9223372036854775807LL-1)
                      && ub <= 9223372036854775807LL) {
                width = 8;
            }
        }
        OUT("{ %u, %u }", width, positive);
    } else {
        OUT("{ 0, 0 }");
    }

    return 0;
}

static int
emit_single_member_OER_constraint_size(arg_t *arg, asn1cnst_range_t *range) {
    if(!range) {
        /* oer_support.h: asn_oer_constraint_s */
		OUT("-1");
		return 0;
    }

    if(range->incompatible || range->not_OER_visible) {
        OUT("-1");
    } else {
        if(range->left.type == ARE_VALUE && range->right.type == ARE_VALUE
           && range->left.value == range->right.value
           && range->left.value >= 0) {
            OUT("%s", asn1p_itoa(range->left.value));
        } else {
            OUT("-1");
        }
    }

	return 0;
}

static int
emit_single_member_PER_constraint(arg_t *arg, asn1cnst_range_t *range, int alphabetsize, const char *type) {
    if(!range || range->incompatible || range->not_PER_visible) {
        OUT("{ APC_UNCONSTRAINED,\t-1, -1,  0,  0 }");
		return 0;
    }

    if(expr_get_type(arg, arg->expr) == ASN_BASIC_REAL) {
        /* Unsupported */
        OUT("{ APC_UNCONSTRAINED,\t-1, -1,  0,  0 }");
        return 0;
    }

    if(range->left.type == ARE_VALUE) {
		if(range->right.type == ARE_VALUE) {
			asn1c_integer_t cover = 1;
			asn1c_integer_t r = 1 + range->right.value
					      - range->left.value;
			size_t rbits;	/* Value range bits */
			ssize_t ebits;	/* Value effective range bits */

			if(range->empty_constraint)
				r = 0;

			if(alphabetsize) {
				/* X.691: 27.5.2 */
				r = PER_FROM_alphabet_characters(range);
			}

			/* Compute real constraint */
			for(rbits = 0; rbits < (8 * sizeof(r)); rbits++) {
				if(r <= cover)
					break;
				cover *= 2;	/* Can't do shifting */
				if(cover < 0) {
					FATAL("Constraint at line %d too wide "
						"for %d-bits integer type",
						arg->expr->_lineno,
						sizeof(r) * 8);
					rbits = sizeof(r);
					break;
				}
			}

			if(alphabetsize) {
				ebits = rbits;
			} else {
				/* X.691, #10.9.4.1 */
				for(ebits = 0; ebits <= 16; ebits++)
					if(r <= 1 << ebits) break;
				if(ebits == 17
				|| range->right.value >= 65536)
					ebits = -1;
			if(0) {
				/* X.691, #10.5.7.1 */
				for(ebits = 0; ebits <= 8; ebits++)
					if(r <= 1 << ebits) break;
				if(ebits == 9) {
					if(r <= 65536)
						ebits = 16;
					else
						ebits = -1;
				}
			}
			}

			OUT("{ APC_CONSTRAINED%s,%s% d, % d, ",
				range->extensible
					? " | APC_EXTENSIBLE" : "",
				range->extensible ? " " : "\t", (int)rbits, (int)ebits);

			if(alphabetsize) {
				asn1c_integer_t lv = range->left.value;
				asn1c_integer_t rv = range->right.value;
				int gcmt = 0;
				if(lv > 0x7fffffff) { lv = 0x7fffffff; gcmt++; }
				if(rv > 0x7fffffff) { rv = 0x7fffffff; gcmt++; }
				if(gcmt) {
					OINTS(lv); OUT(", "); OINTS(rv); OUT(" }");
					goto pcmt;
				}
			}
		} else {
			if(range->extensible) {
				OUT("{ APC_SEMI_CONSTRAINED | APC_EXTENSIBLE, "
					"-1, -1, ");
			} else {
				OUT("{ APC_SEMI_CONSTRAINED,\t-1, -1, ");
			}
		}
		OINTS(range->left.value); OUT(", ");
		OINTS(range->right.value); OUT(" }");
	} else {
		OUT("{ APC_UNCONSTRAINED,\t-1, -1,  0,  0 }");
	}

  pcmt:

	/*
	 * Print some courtesy debug information.
	 */
	if(range->left.type == ARE_VALUE
	|| range->right.type == ARE_VALUE) {
		OUT("\t/* ");
		if(type) OUT("(%s", type);
		OUT("(");
		if(range->left.type == ARE_VALUE)
			OUT("%s", asn1p_itoa(range->left.value));
		else
			OUT("MIN");
		OUT("..");
		if(range->right.type == ARE_VALUE)
			OUT("%s", asn1p_itoa(range->right.value));
		else
			OUT("MAX");
		if(range->extensible) OUT(",...");
		if(type) OUT(")");
		OUT(") */");
	}

	return 0;
}

static int
emit_member_OER_constraints(arg_t *arg, asn1p_expr_t *expr, const char *pfx) {
    int save_target = arg->target->target;
    asn1cnst_range_t *range;
	asn1p_expr_type_e etype;

    etype = expr_get_type(arg, expr);

    if((arg->flags & A1C_GEN_OER)
       && (expr->combined_constraints || etype == ASN_BASIC_ENUMERATED
           || etype == ASN_CONSTR_CHOICE)) {
        /* Fall through */
    } else {
        return 0;
    }

    REDIR(OT_CTDEFS);

    OUT("static asn_oer_constraints_t "
        "asn_OER_%s_%s_constr_%d CC_NOTUSED = {\n",
        pfx, MKID(expr), expr->_type_unique_index);

    INDENT(+1);

    /* .value{.width,.positive} */
    range = asn1constraint_compute_OER_range(expr->Identifier, etype,
                                             expr->combined_constraints,
                                             ACT_EL_RANGE, 0, 0, 0);
    if(emit_single_member_OER_constraint_value(arg, range)) {
        return -1;
    }
    emit_single_member_OER_constraint_comment(arg, range, 0);
    asn1constraint_range_free(range);

	OUT(",\n");

    /* .size */
    range = asn1constraint_compute_OER_range(expr->Identifier, etype,
                                             expr->combined_constraints,
                                             ACT_CT_SIZE, 0, 0, 0);
    if(emit_single_member_OER_constraint_size(arg, range)) {
        return -1;
    }
    emit_single_member_OER_constraint_comment(arg, range, "SIZE");
    asn1constraint_range_free(range);

    INDENT(-1);

    OUT("};\n");

    REDIR(save_target);

    return 0;
}

static int
emit_member_PER_constraints(arg_t *arg, asn1p_expr_t *expr, const char *pfx) {
	int save_target = arg->target->target;
	asn1cnst_range_t *range;
	asn1p_expr_type_e etype;

	etype = expr_get_type(arg, expr);

	if((arg->flags & A1C_GEN_PER)
	&& (expr->combined_constraints
		|| etype == ASN_BASIC_ENUMERATED
		|| etype == ASN_CONSTR_CHOICE
		|| (etype & ASN_STRING_KM_MASK)
        )
	) {
		/* Fall through */
	} else {
		return 0;
	}

	if(expr->_type_referenced) {
		REDIR(OT_FUNC_DECLS);

		OUT("extern asn_per_constraints_t "
			"asn_PER_%s_%s_constr_%d;\n",
			pfx, MKID(expr), expr->_type_unique_index);
	}

	REDIR(OT_CTDEFS);

	if(!(expr->_type_referenced)) OUT("static ");
	OUT("asn_per_constraints_t "
		"asn_PER_%s_%s_constr_%d CC_NOTUSED = {\n",
		pfx, MKID(expr), expr->_type_unique_index);

	INDENT(+1);

	/*
	 * ENUMERATED and CHOICE are special.
	 */
	if(etype == ASN_BASIC_ENUMERATED
	|| etype == ASN_CONSTR_CHOICE) {
		asn1cnst_range_t tmprng;
		asn1p_expr_t *v;
		int extensible = 0;
		int eidx = -1;

		expr = asn1f_find_terminal_type_ex(arg->asn, arg->ns, expr);
		assert(expr);

		TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) {
				extensible++;
				break;
			}
			eidx++;
		}

		memset(&tmprng, 0, sizeof (tmprng));
		tmprng.extensible = extensible;
		if(eidx < 0) tmprng.empty_constraint = 1;
		tmprng.left.type = ARE_VALUE;
		tmprng.left.value = 0;
		tmprng.right.type = ARE_VALUE;
		tmprng.right.value = eidx < 0 ? 0 : eidx;
		if(emit_single_member_PER_constraint(arg, &tmprng, 0, 0))
			return -1;
	} else if(etype & ASN_STRING_KM_MASK) {
		range = asn1constraint_compute_PER_range(expr->Identifier, etype,
				expr->combined_constraints, ACT_CT_FROM,
				0, 0, 0);
		DEBUG("Emitting FROM constraint for %s", expr->Identifier);

		if((range->left.type == ARE_MIN && range->right.type == ARE_MAX)
		|| range->not_PER_visible) {
			switch(etype) {
			case ASN_STRING_BMPString:
				range->left.type = ARE_VALUE;
				range->left.value = 0;
				range->right.type = ARE_VALUE;
				range->right.value = 65535;
				range->not_PER_visible = 0;
				range->extensible = 0;
				break;
			case ASN_STRING_UniversalString:
				OUT("{ APC_CONSTRAINED,\t32, 32,"
					" 0, 2147483647 }"
					" /* special case 1 */\n");
				goto avoid;
			default:
				break;
			}
		}
		if(emit_single_member_PER_constraint(arg, range, 1, 0))
			return -1;
		avoid:
		asn1constraint_range_free(range);
	} else {
		range = asn1constraint_compute_PER_range(expr->Identifier, etype,
				expr->combined_constraints, ACT_EL_RANGE,
				0, 0, 0);
		if(emit_single_member_PER_constraint(arg, range, 0, 0))
			return -1;
		asn1constraint_range_free(range);
	}
	OUT(",\n");

	range = asn1constraint_compute_PER_range(expr->Identifier, etype,
			expr->combined_constraints, ACT_CT_SIZE, 0, 0, 0);
	if(emit_single_member_PER_constraint(arg, range, 0, "SIZE"))
		return -1;
	asn1constraint_range_free(range);
	OUT(",\n");

	if((etype & ASN_STRING_KM_MASK) && (expr->_mark & TM_PERFROMCT)) {
		int old_target = arg->target->target;
		REDIR(OT_CODE);

		OUT("static int asn_PER_MAP_%s_%d_v2c(unsigned int value) {\n",
			MKID(expr), expr->_type_unique_index);
		OUT("\tif(value >= sizeof(permitted_alphabet_table_%d)/"
			"sizeof(permitted_alphabet_table_%d[0]))\n",
			expr->_type_unique_index,
			expr->_type_unique_index);
		OUT("\t\treturn -1;\n");
		OUT("\treturn permitted_alphabet_table_%d[value] - 1;\n",
			expr->_type_unique_index);
		OUT("}\n");

		OUT("static int asn_PER_MAP_%s_%d_c2v(unsigned int code) {\n",
			MKID(expr), expr->_type_unique_index);
		OUT("\tif(code >= sizeof(permitted_alphabet_code2value_%d)/"
			"sizeof(permitted_alphabet_code2value_%d[0]))\n",
			expr->_type_unique_index,
			expr->_type_unique_index);
		OUT("\t\treturn -1;\n");
		OUT("\treturn permitted_alphabet_code2value_%d[code];\n",
			expr->_type_unique_index);
		OUT("}\n");

		REDIR(old_target);

		OUT("asn_PER_MAP_%s_%d_v2c,\t/* Value to PER code map */\n",
			MKID(expr), expr->_type_unique_index);
		OUT("asn_PER_MAP_%s_%d_c2v\t/* PER code to value map */\n",
			MKID(expr), expr->_type_unique_index);
	} else if(etype & ASN_STRING_KM_MASK) {
		DEBUG("No PER value map necessary for %s", MKID(expr));
		OUT("0, 0\t/* No PER character map necessary */\n");
	} else {
		OUT("0, 0\t/* No PER value map */\n");
	}

	INDENT(-1);

	OUT("};\n");

	REDIR(save_target);

	return 0;
}

static int
safe_string(const uint8_t *buf, int size) {
	const uint8_t *end = buf + size;
	for(; buf < end; buf++) {
		int ch = *buf;
		if((ch < 0x20 || ch > 0x7e) || ch == '"')
			return 0;
	}
	return 1;
}

static void
emit_default_string_value(arg_t *arg, asn1p_value_t *v) {

	OUT("static const uint8_t defv[] = ");
	assert(v->type == ATV_STRING);

	if(safe_string(v->value.string.buf, v->value.string.size)) {
		OUT("\"%s\";\n", v->value.string.buf);
	} else {
		uint8_t *b = v->value.string.buf;
		uint8_t *e = v->value.string.size + b;
		OUT("{ ");
		for(;b < e; b++)
			OUT("0x%02x, ", *b);
		OUT("0 };\n");
	}
}

static int
try_inline_default(arg_t *arg, asn1p_expr_t *expr, int out) {
	int save_target = arg->target->target;
	asn1p_expr_type_e etype = expr_get_type(arg, expr);
	int fits_long = 0;

	switch(etype) {
	case ASN_BASIC_BOOLEAN:
		fits_long = 1;
        /* Fall through */
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
		if(expr->marker.default_value == NULL
		|| (expr->marker.default_value->type != ATV_INTEGER &&
		    expr->marker.default_value->type != ATV_TRUE &&
		    expr->marker.default_value->type != ATV_FALSE))
			break;
		if(!fits_long)
			fits_long = asn1c_type_fits_long(arg, expr)!=FL_NOTFIT;
		if(fits_long && !expr->marker.default_value->value.v_integer)
			expr->marker.flags &= ~EM_INDIRECT;
		if(!out) {
            if(C99_MODE) OUT(".default_value_cmp = ");
			OUT("&asn_DFL_%d_cmp_%s,",
				expr->_type_unique_index,
				asn1p_itoa(expr->marker.default_value->value.v_integer));
            OUT("\t/* Compare DEFAULT %s */\n",
				asn1p_itoa(expr->marker.default_value->value.v_integer));
            if(C99_MODE) OUT(".default_value_set = ");
			OUT("&asn_DFL_%d_set_%s,",
				expr->_type_unique_index,
				asn1p_itoa(expr->marker.default_value->value.v_integer));
            OUT("\t/* Set DEFAULT %s */\n",
				asn1p_itoa(expr->marker.default_value->value.v_integer));
			return 1;
		}
		REDIR(OT_STAT_DEFS);

		OUT("static int asn_DFL_%d_cmp_%s(const void *sptr) {\n",
			expr->_type_unique_index,
			asn1p_itoa(expr->marker.default_value->value.v_integer));
		INDENT(+1);
		OUT("const %s *st = sptr;\n", asn1c_type_name(arg, expr, TNF_CTYPE));
		OUT("\n");
		OUT("if(!st) {\n");
        OUT("\treturn -1; /* No value is not a default value */\n");
		OUT("}\n");
		OUT("\n");
		OUT("/* Test default value %s */\n",
			asn1p_itoa(expr->marker.default_value->value.v_integer));
		if(fits_long) {
			OUT("return (*st != %s);\n",
				asn1p_itoa(expr->marker.default_value->value.v_integer));
		} else {
			OUT("long value;\n");
			OUT("if(asn_INTEGER2long(st, &value))\n");
			OUT("\treturn -1;\n");
			OUT("return (value != %s);\n",
				asn1p_itoa(expr->marker.default_value->value.v_integer));
		}
		INDENT(-1);
		OUT("}\n");

		OUT("static int asn_DFL_%d_set_%s(void **sptr) {\n",
			expr->_type_unique_index,
			asn1p_itoa(expr->marker.default_value->value.v_integer));
		INDENT(+1);
		OUT("%s *st = *sptr;\n", asn1c_type_name(arg, expr, TNF_CTYPE));
		OUT("\n");
		OUT("if(!st) {\n");
		OUT("\tst = (*sptr = CALLOC(1, sizeof(*st)));\n");
		OUT("\tif(!st) return -1;\n");
		OUT("}\n");
		OUT("\n");
		OUT("/* Install default value %s */\n",
			asn1p_itoa(expr->marker.default_value->value.v_integer));
		if(fits_long) {
			OUT("*st = ");
			OINT(expr->marker.default_value->value.v_integer);
			OUT(";\n");
			OUT("return 0;\n");
		} else {
			OUT("return asn_long2INTEGER(st, ");
			OINT(expr->marker.default_value->value.v_integer);
			OUT(");\n");
		}
		INDENT(-1);
		OUT("}\n");

		REDIR(save_target);
		return 1;
	case ASN_BASIC_NULL:
		//expr->marker.flags &= ~EM_INDIRECT;
		return 0;
	default:
	  if(etype & ASN_STRING_KM_MASK) {
		if(expr->marker.default_value == NULL
		|| expr->marker.default_value->type != ATV_STRING)
			break;
		if(!out) {
            if(C99_MODE) OUT(".default_value_cmp = ");
			OUT("&asn_DFL_%d_cmp,\t/* Compare DEFAULT \"%s\" */\n",
				expr->_type_unique_index,
				expr->marker.default_value->value.string.buf);
            if(C99_MODE) OUT(".default_value_set = ");
			OUT("&asn_DFL_%d_set,\t/* Set DEFAULT \"%s\" */\n",
				expr->_type_unique_index,
				expr->marker.default_value->value.string.buf);
			return 1;
		}
		REDIR(OT_STAT_DEFS);

        OUT("static int asn_DFL_%d_cmp(const void *sptr) {\n",
            expr->_type_unique_index);
        INDENT(+1);
        emit_default_string_value(arg, expr->marker.default_value);
        OUT("const %s *st = sptr;\n", asn1c_type_name(arg, expr, TNF_CTYPE));
        OUT("\n");
        OUT("if(!st) {\n");
        OUT("\treturn -1; /* No value is not a default value */\n");
        OUT("}\n");
		OUT("\n");
        OUT("if(st->size == (sizeof(defv) - 1)\n");
        OUT("&& memcmp(st->buf, &defv, sizeof(defv) - 1) == 0)\n");
        OUT("\treturn 0;\n");
        OUT("return 1;\n");
		INDENT(-1);
		OUT("}\n");

        OUT("static int asn_DFL_%d_set(void **sptr) {\n",
            expr->_type_unique_index);
        INDENT(+1);
		emit_default_string_value(arg, expr->marker.default_value);
		OUT("%s *st = *sptr;\n", asn1c_type_name(arg, expr, TNF_CTYPE));
        OUT("uint8_t *nstr = MALLOC(sizeof(defv));\n");
		OUT("\n");
        OUT("if(!nstr) return -1;\n");
        OUT("memcpy(nstr, defv, sizeof(defv));\n");
        OUT("\n");
		OUT("if(st) {\n");
		OUT("\tFREEMEM(st->buf);\n");
		OUT("} else {\n");
		OUT("\tst = (*sptr = CALLOC(1, sizeof(*st)));\n");
		OUT("\tif(!st) { FREEMEM(nstr); return -1; }\n");
		OUT("}\n");
		OUT("st->buf = nstr;\n");
        OUT("st->size = sizeof(defv) - 1;\n");
		OUT("\n");
		OUT("return 0;\n");
		INDENT(-1);
		OUT("}\n");

		REDIR(save_target);
		return 1;
	  }
	  break;
	}
	return 0;
}

static int
emit_member_type_selector(arg_t *arg, asn1p_expr_t *expr, asn1c_ioc_table_and_objset_t *opt_ioc) {
	int save_target = arg->target->target;
    asn1p_expr_t *parent_expr = arg->expr;

    const asn1p_constraint_t *crc =
        asn1p_get_component_relation_constraint(expr->combined_constraints);
    if(!crc || crc->el_count <= 1) {
        /* Not an Open Type, it seems. */
        OUT("0");
        return 0;
    }

    const asn1p_ref_t *objset_ref =
        asn1c_get_information_object_set_reference_from_constraint(arg, crc);

    if(!objset_ref) {
        FATAL("Constraint %s does not look like it referst to a set type %s",
              asn1p_constraint_string(crc),
              opt_ioc->objset->Identifier);
        return -1;
    }

    const char *objset_name;
    if(objset_ref->comp_count == 1) {
        objset_name = objset_ref->components[0].name;
    } else if(objset_ref->comp_count == 2) {
        if(strcmp(objset_ref->components[0].name,
                  opt_ioc->objset->module->ModuleName)
           != 0) {
            FATAL(
                "Composite reference %s (from %s) does not look like it refers "
                "to the same module as %s from an object set type %s",
                asn1p_ref_string(objset_ref), asn1p_constraint_string(crc),
                opt_ioc->objset->module->ModuleName,
                opt_ioc->objset->Identifier);
            return -1;
        }
        objset_name = objset_ref->components[1].name;
    } else {
        FATAL("Reference %s (from %s) does not look like an object set type %s",
              asn1p_ref_string(objset_ref), asn1p_constraint_string(crc),
              opt_ioc->objset->Identifier);
        return -1;
    }
    if(strcmp(objset_name, opt_ioc->objset->Identifier) != 0) {
        FATAL("Object Set references do not match: %s != %s", objset_name,
              opt_ioc->objset->Identifier);
        return -1;
    }

    if(crc->el_count != 2 || crc->elements[1]->type != ACT_EL_VALUE
       || crc->elements[1]->value->type != ATV_REFERENCED
       || crc->elements[1]->value->value.reference->comp_count != 1) {
        FATAL(
            "Do not know how to handle complex IoS constraints (%d components "
            "of constraint, %d components of reference %s) for %s at line "
            "%d",
            crc->el_count,
            crc->el_count >= 2 && crc->elements[1]->type == ACT_EL_VALUE
                    && crc->elements[1]->value->type == ATV_REFERENCED
                ? (signed)crc->elements[1]->value->value.reference->comp_count
                : -1,
            crc->el_count >= 2 && crc->elements[1]->type == ACT_EL_VALUE
                    && crc->elements[1]->value->type == ATV_REFERENCED
                ? asn1p_ref_string(crc->elements[1]->value->value.reference)
                : "?",
            MKID(parent_expr), parent_expr->_lineno);
        OUT("0");
        return -1;
    }

    const asn1p_ref_t *cref = crc->elements[1]->value->value.reference;
    const char *cname = cref->components[0].name;
    if(cname[0] == '@' && cname[1] != '.') {
        cname += 1;
    } else if(cname[0] == '@' && cname[1] == '.' && cname[2] != '.') {
        cname += 2;
    } else {
        FATAL("Complex IoS reference %s can not be processed",
              asn1p_ref_string(cref));
        OUT("0");
        return -1;
    }

    assert(opt_ioc != NULL);

    asn1p_expr_t *constraining_memb = NULL;
    TQ_FOR(constraining_memb, &(parent_expr->members), next) {
        if(strcmp(constraining_memb->Identifier, cname) == 0) {
            break;
        }
    }
    if(!constraining_memb) {
        FATAL("Can not find \"%s\" in %s at line %d", cname, MKID(parent_expr),
              parent_expr->_lineno);
        return -1;
    }

    if(constraining_memb->meta_type != AMT_TYPEREF
       || constraining_memb->expr_type != A1TC_REFERENCE
       || constraining_memb->reference->comp_count != 2
       || constraining_memb->reference->components[1].lex_type
              != RLT_Amplowercase) {
        FATAL(
            "Does not look like %s is a CLASS field reference (%s) on line "
            "%d",
            MKID(constraining_memb),
            constraining_memb->reference
                ? asn1p_ref_string(constraining_memb->reference)
                : "<no reference>",
            constraining_memb->_lineno);
        return -1;
    }
    const char *cfield = constraining_memb->reference->components[1].name;

    ssize_t constraining_column = -1;
    for(size_t cn = 0; cn < opt_ioc->ioct->rows ? opt_ioc->ioct->row[0]->columns : 0;
        cn++) {
        if(strcmp(cfield, opt_ioc->ioct->row[0]->column[cn].field->Identifier)
           == 0) {
            constraining_column = cn;
            break;
        }
    }
    if(constraining_column < 0) {
        if(opt_ioc->ioct->rows == 0) {
            OUT("0");
            return 0;
        } else {
            FATAL("Can not find referenced object class %s column %s\n",
                  asn1p_ref_string(objset_ref), cfield);
            return -1;
        }
    }

    if(expr->meta_type != AMT_TYPEREF
       || expr->expr_type != A1TC_REFERENCE
       || expr->reference->comp_count != 2
       || ((expr->reference->components[1].lex_type
              != RLT_AmpUppercase)
            && (expr->reference->components[1].lex_type
                   != RLT_Amplowercase))) {
        FATAL(
            "Does not look like %s is a CLASS field reference (%s) denoting a type on line "
            "%d",
            MKID(expr),
            expr->reference
                ? asn1p_ref_string(expr->reference)
                : "<no reference>",
            expr->_lineno);
        return -1;
    }
    const char *for_field = expr->reference->components[1].name;

    ssize_t for_column = -1;
    for(size_t cn = 0; cn < (opt_ioc->ioct->rows ? opt_ioc->ioct->row[0]->columns : 0);
        cn++) {
        if(strcmp(for_field,
                  opt_ioc->ioct->row[0]->column[cn].field->Identifier)
           == 0) {
            for_column = cn;
            break;
        }
    }
    if(for_column < 0) {
        FATAL("Can not find referenced object class column %s\n", for_field);
        return -1;
    }

    REDIR(OT_CODE);
    OUT("static asn_type_selector_result_t\n");
    OUT("select_%s_", c_name(arg).compound_name);
    OUT("%s_type(const asn_TYPE_descriptor_t *parent_type, const void *parent_sptr) {\n", MKID(expr));
    INDENT(+1);

    OUT("asn_type_selector_result_t result = {0, 0};\n");
    OUT("const asn_ioc_set_t *itable = asn_IOS_%s_%d;\n", MKID(opt_ioc->objset),
        opt_ioc->objset->_type_unique_index);
    OUT("size_t constraining_column = %zu; /* %s */\n", constraining_column, cfield);
    OUT("size_t for_column = %zu; /* %s */\n", for_column, for_field);
    OUT("size_t row;\n");

    const char *tname = asn1c_type_name(arg, constraining_memb, TNF_SAFE);
    if(constraining_memb->marker.flags & EM_INDIRECT) {
        OUT("const void *memb_ptr = *(const void **)");
        OUT("((const char *)parent_sptr + offsetof(%s", c_name(arg).full_name);
        OUT(", %s));", MKID_safe(constraining_memb));
        OUT("if(!memb_ptr) return result;\n");
        OUT("\n");
    }

    switch(asn1c_type_fits_long(arg, constraining_memb)) {
    case FL_NOTFIT:
        OUT("const %s_t *constraining_value = (const %s_t *)", tname, tname);
        break;
    case FL_PRESUMED:
    case FL_FITS_SIGNED:
        OUT("const long *constraining_value = (const long *)");
        break;
    case FL_FITS_UNSIGN:
        OUT("const unsigned long *constraining_value = (const unsigned long *)");
        break;
    }
    if(constraining_memb->marker.flags & EM_INDIRECT) {
        OUT("memb_ptr;\n");
    } else {
        OUT("((const char *)parent_sptr + offsetof(%s", c_name(arg).full_name);
        OUT(", %s));\n", MKID_safe(constraining_memb));
    }
    OUT("\n");

    OUT("for(row=0; row < itable->rows_count; row++) {\n");
    OUT("    const asn_ioc_cell_t *constraining_cell = &itable->rows[row * itable->columns_count + constraining_column];\n");
    OUT("    const asn_ioc_cell_t *type_cell = &itable->rows[row * itable->columns_count + for_column];\n");
    OUT("\n");
    OUT("    if(constraining_cell->type_descriptor->op->compare_struct(constraining_cell->type_descriptor, constraining_value, constraining_cell->value_sptr) == 0) {\n");
    OUT("        result.type_descriptor = type_cell->type_descriptor;\n");
    OUT("        result.presence_index = row + 1;\n");
    OUT("        break;\n");
    OUT("    }\n");
    OUT("}\n");


    OUT("\n");
    OUT("return result;\n");
    INDENT(-1);
    OUT("}\n");
    OUT("\n");

    REDIR(save_target);
    OUT("select_%s_", c_name(arg).compound_name);
    OUT("%s_type", MKID(expr));

    return 0;
}

static int
emit_member_table(arg_t *arg, asn1p_expr_t *expr, asn1c_ioc_table_and_objset_t *opt_ioc) {
	int save_target;
	arg_t tmp_arg;
	struct asn1p_type_tag_s outmost_tag_s;
	struct asn1p_type_tag_s *outmost_tag;
	int complex_contents;
	const char *p;

    if(WITH_MODULE_NAMESPACE(
           expr->module, expr_ns,
           asn1f_fetch_outmost_tag(arg->asn, expr_ns, expr->module, expr,
                                   &outmost_tag_s, AFT_IMAGINARY_ANY))) {
        outmost_tag = 0;
	} else {
		outmost_tag = &outmost_tag_s;
	}

	OUT("{ ");

    if(is_open_type(arg, expr, opt_ioc)) {
        OUT("ATF_OPEN_TYPE | ");
    } else if(outmost_tag && outmost_tag->tag_value == -1) {
        OUT("ATF_ANY_TYPE | ");
    }
    OUT("%s, ",
		(expr->marker.flags & EM_INDIRECT)?"ATF_POINTER":"ATF_NOFLAGS");
	if((expr->marker.flags & EM_OMITABLE) == EM_OMITABLE) {
		asn1p_expr_t *tv;
		int opts = 0;
		for(tv = expr;
			tv && (tv->marker.flags & EM_OMITABLE) == EM_OMITABLE;
			tv = TQ_NEXT(tv, next), opts++) {
			if(tv->expr_type == A1TC_EXTENSIBLE)
				opts--;
		}
		OUT("%d, ", opts);
	} else {
		OUT("0, ");
	}
    if(expr->_anonymous_type) {
        assert(arg->expr->expr_type == ASN_CONSTR_SET_OF
               || arg->expr->expr_type == ASN_CONSTR_SEQUENCE_OF);
        OUT("0,\n");
    } else {
        OUT("offsetof(%s, ", c_name(arg).full_name);
        if((arg->expr->expr_type == ASN_CONSTR_CHOICE
            || arg->expr->expr_type == ASN_CONSTR_OPEN_TYPE)
           && (!UNNAMED_UNIONS))
            OUT("choice.");
        OUT("%s),\n", MKID_safe(expr));
    }

    INDENT(+1);
	if(C99_MODE) OUT(".tag = ");
	if(outmost_tag) {
		if(outmost_tag->tag_value == -1)
			OUT("-1 /* Ambiguous tag (ANY?) */");
		else
			_print_tag(arg, outmost_tag);
	} else {
		OUT("-1 /* Ambiguous tag (CHOICE?) */");
	}

	OUT(",\n");
	if(C99_MODE) OUT(".tag_mode = ");
	if((!(expr->expr_type &  ASN_CONSTR_MASK)
	   || expr->expr_type == ASN_CONSTR_CHOICE)
	&& expr->tag.tag_class) {
		if(expr->tag.tag_mode == TM_IMPLICIT)
		OUT("-1,\t/* IMPLICIT tag at current level */\n");
		else
		OUT("+1,\t/* EXPLICIT tag at current level */\n");
	} else {
		OUT("0,\n");
	}

	complex_contents =
		is_open_type(arg, expr, opt_ioc)
		|| (expr->expr_type & ASN_CONSTR_MASK)
		|| expr->expr_type == ASN_BASIC_ENUMERATED
		|| (0 /* -- prohibited by X.693:8.3.4 */
			&& expr->expr_type == ASN_BASIC_INTEGER
			&& expr_elements_count(arg, expr))
		|| (expr->expr_type == ASN_BASIC_INTEGER
			&& asn1c_type_fits_long(arg, expr) == FL_FITS_UNSIGN);
	if(C99_MODE) OUT(".type = ");

    OUT("&asn_DEF_");
    if(complex_contents) {
        OUT("%s", MKID(expr));
        if(!(arg->flags & A1C_ALL_DEFS_GLOBAL))
            OUT("_%d", expr->_type_unique_index);
    } else {
        OUT("%s", asn1c_type_name(arg, expr, TNF_SAFE));
    }
    OUT(",\n");


    if(C99_MODE) OUT(".type_selector = ");
    if(opt_ioc) {
        if(emit_member_type_selector(arg, expr, opt_ioc) < 0)
            return -1;
    } else {
        OUT("0");
    }
	OUT(",\n");

    OUT("{ ");
	if(C99_MODE) OUT(".oer_constraints = ");
	if(arg->flags & A1C_GEN_OER) {
		if(expr->constraints) {
			OUT("&asn_OER_memb_%s_constr_%d",
				MKID(expr),
				expr->_type_unique_index);
		} else {
			OUT("0");
		}
	} else {
        OUT("0");
	}
    OUT(", ");
	if(C99_MODE) OUT(".per_constraints = ");
	if(arg->flags & A1C_GEN_PER) {
		if(expr->constraints) {
			OUT("&asn_PER_memb_%s_constr_%d",
				MKID(expr),
				expr->_type_unique_index);
		} else {
			OUT("0");
		}
	} else {
		OUT("0");
	}
    OUT(", ");
	if(C99_MODE) OUT(".general_constraints = ");
	if(expr->constraints) {
		if(arg->flags & A1C_NO_CONSTRAINTS) {
			OUT("0");
		} else {
			const char *id = MKID(expr);
			if(expr->_anonymous_type
					&& !strcmp(expr->Identifier, "Member"))
				id = asn1c_type_name(arg, expr, TNF_SAFE);
			OUT(" memb_%s_constraint_%d", id,
				arg->expr->_type_unique_index);
		}
	} else {
		OUT("0");
	}
    OUT(" },\n");

	if(try_inline_default(arg, expr, 0)) {
	} else {
		OUT("0, 0, /* No default value */\n");
	}
	if(C99_MODE) OUT(".name = ");
	if(expr->_anonymous_type && !strcmp(expr->Identifier, "Member")) {
		OUT("\"\"\n");
	} else {
		OUT("\"%s\"\n", expr->Identifier);
	}
	OUT("},\n");
	INDENT(-1);

	if(!expr->constraints || (arg->flags & A1C_NO_CONSTRAINTS))
		return 0;

	save_target = arg->target->target;
	REDIR(OT_CODE);

	if(expr->_anonymous_type && !strcmp(expr->Identifier, "Member"))
		p = asn1c_type_name(arg, expr, TNF_SAFE);
	else
		p = MKID(expr);
	OUT("static int\n");
	OUT("memb_%s_constraint_%d(const asn_TYPE_descriptor_t *td, const void *sptr,\n", p, arg->expr->_type_unique_index);
	INDENT(+1);
	OUT("\t\tasn_app_constraint_failed_f *ctfailcb, void *app_key) {\n");
	tmp_arg = *arg;
	tmp_arg.expr = expr;
	DEBUG("member constraint checking code for %s", p);
	if(asn1c_emit_constraint_checking_code(&tmp_arg) == 1) {
		OUT("return td->encoding_constraints.general_constraints"
			"(td, sptr, ctfailcb, app_key);\n");
	}
	INDENT(-1);
	OUT("}\n");
	OUT("\n");

	if(emit_member_OER_constraints(arg, expr, "memb"))
		return -1;

	if(emit_member_PER_constraints(arg, expr, "memb"))
		return -1;

	REDIR(save_target);

	return 0;
}

/*
 * Generate "asn_DEF_XXX" type definition.
 */
static int
emit_type_DEF(arg_t *arg, asn1p_expr_t *expr, enum tvm_compat tv_mode, int tags_count, int all_tags_count, int elements_count, enum etd_spec spec) {
	asn1p_expr_t *terminal;
	int using_type_name = 0;
	char *expr_id = strdup(MKID(expr));
	char *p = expr_id;
	char *p2 = (char *)0;

	terminal = asn1f_find_terminal_type_ex(arg->asn, arg->ns, expr);

	if(emit_member_OER_constraints(arg, expr, "type"))
		return -1;

	if(emit_member_PER_constraints(arg, expr, "type"))
		return -1;

	if(HIDE_INNER_DEFS)
		OUT("static /* Use -fall-defs-global to expose */\n");
	OUT("asn_TYPE_descriptor_t asn_DEF_%s", p);
    if(HIDE_INNER_DEFS || (arg->flags & A1C_ALL_DEFS_GLOBAL))
        OUT("_%d", expr->_type_unique_index);
    OUT(" = {\n");
	INDENT(+1);

		if(expr->_anonymous_type) {
			p = strdup(ASN_EXPR_TYPE2STR(expr->expr_type));
			OUT("\"%s\",\n", p?p:"");
			OUT("\"%s\",\n",
				p ? asn1c_make_identifier(AMI_CHECK_RESERVED,
					0, p, 0) : "");
		} else {
			OUT("\"%s\",\n", expr->Identifier);
			OUT("\"%s\",\n", expr->Identifier);
		}

		if(expr->expr_type & ASN_CONSTR_MASK) {
			using_type_name = 1;
			p = strdup(asn1c_type_name(arg, arg->expr, TNF_SAFE));
		} else {
			if (expr->expr_type == A1TC_REFERENCE) {
				p2 = strdup(asn1c_type_name(arg, terminal, TNF_SAFE));
			} else {
				p2 = strdup(asn1c_type_name(arg, expr, TNF_SAFE));
			}
			p = strdup(expr_id);
		}
		if (!p2)
			p2 = strdup(p);

        OUT("&asn_OP_%s,\n", p2);

		if(tags_count) {
			OUT("asn_DEF_%s_tags_%d,\n",
				expr_id, expr->_type_unique_index);
			OUT("sizeof(asn_DEF_%s_tags_%d)\n",
				expr_id, expr->_type_unique_index);
			OUT("\t/sizeof(asn_DEF_%s_tags_%d[0])",
				expr_id, expr->_type_unique_index);
			if(tv_mode == _TVM_SUBSET
			&& tags_count != all_tags_count)
				OUT(" - %d", all_tags_count - tags_count);
			OUT(", /* %d */\n", tags_count);
		} else {
			OUT("0,\t/* No effective tags (pointer) */\n");
			OUT("0,\t/* No effective tags (count) */\n");
		}

		if(all_tags_count && tv_mode == _TVM_DIFFERENT) {
			OUT("asn_DEF_%s_all_tags_%d,\n",
				expr_id, expr->_type_unique_index);
			OUT("sizeof(asn_DEF_%s_all_tags_%d)\n",
				expr_id, expr->_type_unique_index);
			OUT("\t/sizeof(asn_DEF_%s_all_tags_%d[0]), /* %d */\n",
				expr_id, expr->_type_unique_index, all_tags_count);
		} else if(all_tags_count) {
			OUT("asn_DEF_%s_tags_%d,\t/* Same as above */\n",
				expr_id, expr->_type_unique_index);
			OUT("sizeof(asn_DEF_%s_tags_%d)\n",
				expr_id, expr->_type_unique_index);
			OUT("\t/sizeof(asn_DEF_%s_tags_%d[0]), /* %d */\n",
				expr_id, expr->_type_unique_index, all_tags_count);
		} else {
			OUT("0,\t/* No tags (pointer) */\n");
			OUT("0,\t/* No tags (count) */\n");
		}

		OUT("{ ");
		if(arg->flags & A1C_GEN_OER) {
			if(expr->combined_constraints
			|| expr->expr_type == ASN_BASIC_ENUMERATED
			|| expr->expr_type == ASN_CONSTR_CHOICE) {
				OUT("&asn_OER_type_%s_constr_%d",
					expr_id, expr->_type_unique_index);
			} else {
				OUT("0");
			}
		} else {
			OUT("0");
		}
        OUT(", ");

		if(arg->flags & A1C_GEN_PER) {
            if(expr->combined_constraints
               || expr->expr_type == ASN_BASIC_ENUMERATED
               || expr->expr_type == ASN_CONSTR_CHOICE
               || (expr->expr_type & ASN_STRING_KM_MASK)) {
                OUT("&asn_PER_type_%s_constr_%d",
					expr_id, expr->_type_unique_index);
			} else {
				OUT("0");
			}
		} else {
			OUT("0");
		}
		OUT(", ");
#define FUNCREF(foo)                              \
    do {                                          \
        OUT("%s", p);                             \
        if(HIDE_INNER_DEFS && !using_type_name)   \
            OUT("_%d", expr->_type_unique_index); \
        OUT("_" #foo "");                         \
    } while(0)

#define FUNCREF2(foo)  \
    do {               \
        OUT("%s", p2); \
        OUT("_" #foo); \
    } while(0)

        if (arg->flags & A1C_NO_CONSTRAINTS) {
			OUT("0");
		} else {
			if (!expr->combined_constraints)
				FUNCREF2(constraint);
			else
				FUNCREF(constraint);
		}
        OUT(" },\n");

        free(p);
        p = NULL;
        free(p2);
        p2 = NULL;
        free(expr_id);
        expr_id = NULL;

		if(elements_count ||
			((expr->expr_type == A1TC_REFERENCE) &&
				(terminal->expr_type & ASN_CONSTR_MASK) &&
				expr_elements_count(arg, terminal))) {

			if (expr->expr_type == A1TC_REFERENCE) {
				OUT("asn_MBR_%s_%d,\n", MKID(terminal), terminal->_type_unique_index);

				if(terminal->expr_type == ASN_CONSTR_SEQUENCE_OF
				|| terminal->expr_type == ASN_CONSTR_SET_OF) {
					OUT("%d,\t/* Single element */\n",
						expr_elements_count(arg, terminal));
					assert(expr_elements_count(arg, terminal) == 1);
				} else {
					OUT("%d,\t/* Elements count */\n",
						expr_elements_count(arg, terminal));
				}
			} else {
                OUT("asn_MBR_%s_%d,\n", c_name(arg).part_name,
                    expr->_type_unique_index);

                if(expr->expr_type == ASN_CONSTR_SEQUENCE_OF
				|| expr->expr_type == ASN_CONSTR_SET_OF) {
					OUT("%d,\t/* Single element */\n",
						elements_count);
					assert(elements_count == 1);
				} else {
					OUT("%d,\t/* Elements count */\n",
						elements_count);
				}
			}
		} else {
			if(expr_elements_count(arg, expr))
				OUT("0, 0,\t/* Defined elsewhere */\n");
			else
				OUT("0, 0,\t/* No members */\n");
		}

		switch(spec) {
		case ETD_NO_SPECIFICS:
			if ((expr->expr_type == A1TC_REFERENCE) &&
				((terminal->expr_type & ASN_CONSTR_MASK) ||
				(terminal->expr_type == ASN_BASIC_ENUMERATED) ||
				((terminal->expr_type == ASN_BASIC_INTEGER) &&
				(asn1c_type_fits_long(arg, terminal) == FL_FITS_UNSIGN)))) {
                OUT("&asn_SPC_%s_specs_%d\t/* Additional specs */\n",
                    c_expr_name(arg, terminal).part_name,
                    terminal->_type_unique_index);
            } else if ((expr->expr_type == ASN_TYPE_ANY) ||
					(expr->expr_type == ASN_BASIC_BIT_STRING) ||
					(expr->expr_type == ASN_STRING_BMPString) ||
					(expr->expr_type == ASN_BASIC_OCTET_STRING) ||
					(expr->expr_type == ASN_STRING_UniversalString)) {
                OUT("&asn_SPC_%s_specs\t/* Additional specs */\n",
                    c_name(arg).type.part_name);
            } else if ((expr->expr_type == A1TC_REFERENCE) &&
					((terminal->expr_type == ASN_TYPE_ANY) ||
					(terminal->expr_type == ASN_BASIC_BIT_STRING) ||
					(terminal->expr_type == ASN_STRING_BMPString) ||
					(terminal->expr_type == ASN_BASIC_OCTET_STRING) ||
					(terminal->expr_type == ASN_STRING_UniversalString))) {
                OUT("&asn_SPC_%s_specs\t/* Additional specs */\n",
                    c_expr_name(arg, terminal).type.part_name);
            } else {
				OUT("0\t/* No specifics */\n");
			}
			break;
		case ETD_HAS_SPECIFICS:
			OUT("&asn_SPC_%s_specs_%d\t/* Additional specs */\n",
				c_name(arg).part_name, expr->_type_unique_index);
		}
	INDENT(-1);
	OUT("};\n");
	OUT("\n");

	return 0;
}

static int
expr_as_xmlvaluelist(arg_t *arg, asn1p_expr_t *expr) {
	/*
	 * X.680, 25.5, Table 5
	 */
	switch(expr_get_type(arg, expr)) {
	case ASN_BASIC_BOOLEAN:
	case ASN_BASIC_ENUMERATED:
	case ASN_BASIC_NULL:
		return 1;
	case ASN_CONSTR_CHOICE:
		return 2;
	default:
		return 0;
	}
}

static int
out_name_chain(arg_t *arg, enum onc_flags onc_flags) {
	asn1p_expr_t *expr = arg->expr;
	const char *id;

	if((arg->flags & A1C_COMPOUND_NAMES
	   || onc_flags & ONC_force_compound_name
	   || (0 && arg->embed /* Not yet */))
	&& ((expr->expr_type & ASN_CONSTR_MASK)
	   || expr->expr_type == ASN_BASIC_ENUMERATED
	   || ((expr->expr_type == ASN_BASIC_INTEGER
	   	|| expr->expr_type == ASN_BASIC_BIT_STRING)
		&& expr_elements_count(arg, expr))
	   )
	&& expr->parent_expr) {

		arg_t tmparg = *arg;

		tmparg.expr = expr->parent_expr;
		if(0) tmparg.flags &= ~A1C_COMPOUND_NAMES;

		out_name_chain(&tmparg, onc_flags);

		if(expr->parent_expr->Identifier) OUT("__");	/* a separator between id components */

		/* Fall through */
	}

	if(onc_flags & ONC_avoid_keywords)
		id = MKID_safe(expr);
	else
		id = MKID(expr);
	OUT("%s", id);

	return 0;
}

static int
emit_include_dependencies(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *memb;

	/* Avoid recursive definitions. */
	TQ_FOR(memb, &(expr->members), next) {
		expr_break_recursion(arg, memb);
	}

	TQ_FOR(memb, &(expr->members), next) {

		if(memb->marker.flags & (EM_INDIRECT | EM_UNRECURSE)) {
			if(terminal_structable(arg, memb)) {
				int saved_target = arg->target->target;
				if(saved_target != OT_FWD_DECLS) {
					REDIR(OT_FWD_DECLS);
					OUT("%s;\n",
						asn1c_type_name(arg, memb, TNF_RSAFE));
				}
				REDIR(saved_target);
			}
		}

		if((!(memb->expr_type & ASN_CONSTR_MASK)
			&& memb->expr_type > ASN_CONSTR_MASK)
		|| memb->meta_type == AMT_TYPEREF) {
			if(memb->marker.flags & EM_UNRECURSE) {
				GEN_POSTINCLUDE(asn1c_type_name(arg,
					memb, TNF_INCLUDE));
			} else {
				GEN_INCLUDE(asn1c_type_name(arg,
					memb, TNF_INCLUDE));
			}
		}
	}

	return 0;
}

/*
 * Check if it is better to make this type indirectly accessed via
 * a pointer.
 * This may be the case for the following recursive definition:
 * Type ::= CHOICE { member Type };
 */
static int
expr_break_recursion(arg_t *arg, asn1p_expr_t *expr) {
	int ret;

	if(expr->marker.flags & EM_UNRECURSE)
		return 1;	/* Already broken */

	/* -findirect-choice compiles members of CHOICE as indirect pointers */
	if((arg->flags & A1C_INDIRECT_CHOICE)
	 && arg->expr->expr_type == ASN_CONSTR_CHOICE
	 && (expr_get_type(arg, expr) & ASN_CONSTR_MASK)
	) {
		/* Break cross-reference */
		expr->marker.flags |= EM_INDIRECT | EM_UNRECURSE;
		return 1;
	}

	if((expr->marker.flags & EM_INDIRECT)
	|| arg->expr->expr_type == ASN_CONSTR_SET_OF
	|| arg->expr->expr_type == ASN_CONSTR_SEQUENCE_OF) {
		if(terminal_structable(arg, expr)) {
			expr->marker.flags |= EM_UNRECURSE;

			if(arg->expr->expr_type == ASN_CONSTR_SET_OF
			|| arg->expr->expr_type == ASN_CONSTR_SEQUENCE_OF) {
				/* Don't put EM_INDIRECT even if recursion */
				return 1;
			}

			/* Fall through */
		}
	}

	/* Look for recursive back-references */
	ret = expr_defined_recursively(arg, expr);
	switch(ret) {
	case 2: /* Explicitly break the recursion */
	case 1: /* Use safer typing */
		expr->marker.flags |= EM_INDIRECT;
		expr->marker.flags |= EM_UNRECURSE;
		break;
	}

	return 0;
}

/*
 * Check if the type can be represented using simple `struct TYPE`.
 */
static asn1p_expr_t *
terminal_structable(arg_t *arg, asn1p_expr_t *expr) {
    asn1p_expr_t *terminal =
        asn1f_find_terminal_type_ex(arg->asn, arg->ns, expr);
    if(terminal
	&& !terminal->parent_expr
	&& (terminal->expr_type & ASN_CONSTR_MASK)) {
		return terminal;
	}
	return 0;
}

static int
asn1c_recurse(arg_t *arg, asn1p_expr_t *expr, int (*callback)(arg_t *arg, void *key), void *key) {
	arg_t tmp = *arg;
	int maxret = 0;
	int ret;

	if(expr->_mark & TM_RECURSION) return 0;
	expr->_mark |= TM_RECURSION;

	/* Invoke callback for every type going into recursion */
	tmp.expr = expr;
	maxret = callback(&tmp, key);
	if(maxret <= 1) {
		/*
		 * Recursively invoke myself and the callbacks.
		 */
		TQ_FOR(tmp.expr, &(expr->members), next) {
			ret = asn1c_recurse(&tmp, tmp.expr, callback, key);
			if(ret > maxret)
				maxret = ret;
			if(maxret > 1) break;
		}
	}

	expr->_mark &= ~TM_RECURSION;
	return maxret;
}

static int
check_is_refer_to(arg_t *arg, void *key) {
	asn1p_expr_t *terminal = terminal_structable(arg, arg->expr);
	if(terminal == key) {
		if(arg->expr->marker.flags & EM_INDIRECT)
			return 1; /* This is almost safe indirection */
		return 2;
	} else if(terminal) {
		/* This might be N-step circular loop. Dive into it. */
		return asn1c_recurse(arg, terminal, check_is_refer_to, key);
	}
	return 0;
}

/*
 * Check if the possibly inner expression defined recursively.
 */
static int
expr_defined_recursively(arg_t *arg, asn1p_expr_t *expr) {
	asn1p_expr_t *terminal;
	asn1p_expr_t *topmost;

	/* If expression is top-level, there's no way it can be recursive. */
	if(expr->parent_expr == 0) return 0;
	if(expr->expr_type != A1TC_REFERENCE)
		return 0;	/* Basic types are never recursive */

	terminal = terminal_structable(arg, expr);
	if(!terminal) return 0;	/* Terminal cannot be indirected */

	/* Search for the parent container for the given expression */
	topmost = expr;
	while(topmost->parent_expr)
		topmost = topmost->parent_expr;

	/* Look inside the terminal type if it mentions the parent expression */
	return asn1c_recurse(arg, terminal, check_is_refer_to, topmost);
}

struct canonical_map_element {
	int eidx;
	asn1p_expr_t *expr;
};
static int compar_cameo(const void *ap, const void *bp);
static arg_t *cameo_arg;
static int *
compute_canonical_members_order(arg_t *arg, int el_count) {
	struct canonical_map_element *cmap;
	int *rmap;
	asn1p_expr_t *v;
	int eidx = 0;
	int first_extension = -1;
	int nextmax = -1;
	int already_sorted = 1;

	cmap = calloc(el_count, sizeof *cmap);
	assert(cmap);

	TQ_FOR(v, &(arg->expr->members), next) {
		if(v->expr_type != A1TC_EXTENSIBLE) {
			cmap[eidx].eidx = eidx;
			cmap[eidx].expr = v;
			eidx++;
		} else if(first_extension == -1)
			first_extension = eidx;
	}

	cameo_arg = arg;
	if(first_extension == -1) {
		/* Sort the whole thing */
		qsort(cmap, el_count, sizeof(*cmap), compar_cameo);
	} else {
		/* Sort root and extensions independently */
		qsort(cmap, first_extension, sizeof(*cmap), compar_cameo);
		qsort(cmap + first_extension, el_count - first_extension,
			sizeof(*cmap), compar_cameo);
	}

	/* move data back to a simpler map */
	rmap = calloc(el_count, sizeof *rmap);
	assert(rmap);
	for(eidx = 0; eidx < el_count; eidx++) {
		rmap[eidx] = cmap[eidx].eidx;
		if(rmap[eidx] <= nextmax)
			already_sorted = 0;
		else
			nextmax = rmap[eidx];
	}
	free(cmap);

	if(already_sorted) { free(rmap); rmap = 0; }
	return rmap;
}
static int compar_cameo(const void *ap, const void *bp) {
	const struct canonical_map_element *a = (const void *)ap;
	const struct canonical_map_element *b = (const void *)bp;
	struct asn1p_type_tag_s atag, btag;
	arg_t *arg = cameo_arg;

    if(WITH_MODULE_NAMESPACE(a->expr->module, expr_ns,
                             asn1f_fetch_outmost_tag(
                                 arg->asn, expr_ns, a->expr->module, a->expr,
                                 &atag, AFT_IMAGINARY_ANY | AFT_CANON_CHOICE)))
        return 1;

    if(WITH_MODULE_NAMESPACE(
           b->expr->module, expr_ns,
           asn1f_fetch_outmost_tag(arg->asn, expr_ns, b->expr->module, b->expr,
                                   &btag,
                                   AFT_IMAGINARY_ANY | AFT_CANON_CHOICE))) {
        return -1;
    }

    if(atag.tag_class < btag.tag_class)
		return -1;
	if(atag.tag_class > btag.tag_class)
		return 1;
	if(atag.tag_value < btag.tag_value)
		return -1;
	if(atag.tag_value > btag.tag_value)
		return 1;
	return 0;

}
