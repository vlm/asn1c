/*
 * Don't look into this file. First, because it's a mess, and second, because
 * it's a brain of the compiler, and you don't wanna mess with brains do you? ;)
 */
#include "asn1c_internal.h"
#include "asn1c_C.h"
#include "asn1c_constraint.h"
#include "asn1c_out.h"
#include "asn1c_misc.h"
#include <asn1fix_export.h>	/* Stuff exported by libasn1fix */

typedef struct tag2el_s {
	struct asn1p_type_tag_s el_tag;
	int el_no;
	int toff_first;
	int toff_last;
	asn1p_expr_t *from_expr;
} tag2el_t;

static int _fill_tag2el_map(arg_t *arg, tag2el_t **tag2el, int *count, int el_no);
static int _add_tag2el_member(arg_t *arg, tag2el_t **tag2el, int *count, int el_no);

static int asn1c_lang_C_type_SEQUENCE_def(arg_t *arg);
static int asn1c_lang_C_type_SET_def(arg_t *arg);
static int asn1c_lang_C_type_CHOICE_def(arg_t *arg);
static int asn1c_lang_C_type_SEx_OF_def(arg_t *arg, int seq_of);
static int _print_tag(arg_t *arg, struct asn1p_type_tag_s *tag_p);
static int check_if_extensible(asn1p_expr_t *expr);
static int expr_better_indirect(arg_t *arg, asn1p_expr_t *expr);
static int expr_as_xmlvaluelist(arg_t *arg, asn1p_expr_t *expr);
static int expr_elements_count(arg_t *arg, asn1p_expr_t *expr);
static int emit_member_table(arg_t *arg, asn1p_expr_t *expr);
static int emit_tag2member_map(arg_t *arg, tag2el_t *tag2el, int tag2el_count);

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
	asn1p_expr_t *__m;						\
	TQ_FOR(__m, &(expr->members), next) {				\
		if((!(__m->expr_type & ASN_CONSTR_MASK)			\
		&& __m->expr_type > ASN_CONSTR_MASK)			\
		|| __m->meta_type == AMT_TYPEREF) {			\
			GEN_INCLUDE(asn1c_type_name(arg,		\
				__m, TNF_INCLUDE));			\
		}							\
	}								\
	if(expr->expr_type == ASN_CONSTR_SET_OF)			\
		GEN_INCLUDE("asn_SET_OF");				\
	if(expr->expr_type == ASN_CONSTR_SEQUENCE_OF)			\
		GEN_INCLUDE("asn_SEQUENCE_OF");				\
} while(0)

#define	MKID(id)	asn1c_make_identifier(0, (id), 0)

int
asn1c_lang_C_type_REAL(arg_t *arg) {
	REDIR(OT_DEPS);
	return asn1c_lang_C_type_SIMPLE_TYPE(arg);
}

int
asn1c_lang_C_type_common_INTEGER(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;

	REDIR(OT_DEPS);

	if(expr->expr_type == ASN_BASIC_ENUMERATED
	|| TQ_FIRST(&(expr->members))
	) {
		OUT("typedef enum %s {\n", MKID(expr->Identifier));
		TQ_FOR(v, &(expr->members), next) {
			switch(v->expr_type) {
			case A1TC_UNIVERVAL:
				OUT("\t%s\t= %" PRIdASN ",\n",
					asn1c_make_identifier(0,
						expr->Identifier,
						v->Identifier, 0),
					v->value->value.v_integer);
				break;
			case A1TC_EXTENSIBLE:
				OUT("\t/*\n");
				OUT("\t * Enumeration is extensible\n");
				OUT("\t */\n");
				break;
			default:
				return -1;
			}
		}
		OUT("} %s_e;\n", MKID(expr->Identifier));
	}

	return asn1c_lang_C_type_SIMPLE_TYPE(arg);
}

int
asn1c_lang_C_type_SEQUENCE(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int comp_mode = 0;	/* {root,ext=1,root,root,...} */

	DEPENDENCIES;

	if(arg->embed) {
		OUT("struct %s {\n", MKID(expr->Identifier));
	} else {
		OUT("typedef struct %s {\n",
			MKID(expr->Identifier));
	}

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			if(comp_mode < 3) comp_mode++;
		}
		if(comp_mode == 1
		|| expr_better_indirect(arg, v))
			v->marker.flags |= EM_INDIRECT;
		EMBED(v);
	}

	PCTX_DEF;
	OUT("} %s%s%s", expr->marker.flags?"*":"",
		expr->_anonymous_type ? "" : MKID(expr->Identifier),
		arg->embed ? "" : "_t");

	return asn1c_lang_C_type_SEQUENCE_def(arg);
}

static int
asn1c_lang_C_type_SEQUENCE_def(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int elements;	/* Number of elements */
	int ext_start = -1;
	int ext_stop = -1;
	tag2el_t *tag2el = NULL;
	int tag2el_count = 0;
	int tags_count;
	int all_tags_count;
	enum tvm_compat tv_mode;
	char *p;

	/*
	 * Fetch every inner tag from the tag to elements map.
	 */
	if(_fill_tag2el_map(arg, &tag2el, &tag2el_count, -1)) {
		if(tag2el) free(tag2el);
		return -1;
	}

	GEN_INCLUDE("constr_SEQUENCE");
	if(!arg->embed)
		GEN_DECLARE(expr);	/* asn_DEF_xxx */

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	if(expr_elements_count(arg, expr)) {
		int comp_mode = 0;	/* {root,ext=1,root,root,...} */

		p = MKID(expr->Identifier);
		OUT("static asn_TYPE_member_t asn_MBR_%s[] = {\n", p);

		elements = 0;
		INDENTED(TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) {
				if((++comp_mode) == 1)
					ext_start = elements - 1;
				else
					ext_stop = elements - 1;
				continue;
			}
			elements++;
			emit_member_table(arg, v);
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
	emit_tag2member_map(arg, tag2el, tag2el_count);

	p = MKID(expr->Identifier);
	OUT("static asn_SEQUENCE_specifics_t asn_DEF_%s_specs = {\n", p);
	INDENTED(
		OUT("sizeof(struct %s),\n", p);
		OUT("offsetof(struct %s, _asn_ctx),\n", p);
		OUT("asn_DEF_%s_tag2el,\n", p);
		OUT("%d,\t/* Count of tags in the map */\n", tag2el_count);
		OUT("%d,\t/* Start extensions */\n",
			ext_start);
		OUT("%d\t/* Stop extensions */\n",
			(ext_stop<ext_start)?elements+1:ext_stop, ext_stop);
	);
	OUT("};\n");

	/*
	 * Emit asn_DEF_xxx table.
	 */
	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, elements,
			ETD_HAS_SPECIFICS);

	REDIR(OT_TYPE_DECLS);

	return 0;
}

int
asn1c_lang_C_type_SET(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	long mcount;
	char *id;
	int comp_mode = 0;	/* {root,ext=1,root,root,...} */

	DEPENDENCIES;

	REDIR(OT_DEPS);

	OUT("\n");
	OUT("/*\n");
	OUT(" * Method of determining the components presence\n");
	OUT(" */\n");
	mcount = 0;
	OUT("typedef enum %s_PR {\n", MKID(expr->Identifier));
	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) continue;
		INDENTED(
			id = MKID(expr->Identifier);
			OUT("%s_PR_", id);
			id = MKID(v->Identifier);
			OUT("%s,\t/* Member %s is present */\n",
				id, id)
		);
		mcount++;
	}
	id = MKID(expr->Identifier);
	OUT("} %s_PR;\n", id);

	REDIR(OT_TYPE_DECLS);

	if(arg->embed) {
		OUT("struct %s {\n", id);
	} else {
		OUT("typedef struct %s {\n", id);
	}

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			if(comp_mode < 3) comp_mode++;
		}
		if(comp_mode == 1
		|| expr_better_indirect(arg, v))
			v->marker.flags |= EM_INDIRECT;
		EMBED(v);
	}

	INDENTED(
		id = MKID(expr->Identifier);
		OUT("\n");
		OUT("/* Presence bitmask: ASN_SET_ISPRESENT(p%s, %s_PR_x) */\n",
			id, id);
		OUT("unsigned int _presence_map\n");
		OUT("\t[((%ld+(8*sizeof(unsigned int))-1)/(8*sizeof(unsigned int)))];\n", mcount);
	);

	PCTX_DEF;
	OUT("} %s%s%s", expr->marker.flags?"*":"",
		expr->_anonymous_type ? "" : MKID(expr->Identifier),
		arg->embed ? "" : "_t");

	return asn1c_lang_C_type_SET_def(arg);
}

static int
asn1c_lang_C_type_SET_def(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int elements;
	tag2el_t *tag2el = NULL;
	int tag2el_count = 0;
	int tags_count;
	int all_tags_count;
	enum tvm_compat tv_mode;
	char *p;

	/*
	 * Fetch every inner tag from the tag to elements map.
	 */
	if(_fill_tag2el_map(arg, &tag2el, &tag2el_count, -1)) {
		if(tag2el) free(tag2el);
		return -1;
	}

	GEN_INCLUDE("constr_SET");
	if(!arg->embed)
		GEN_DECLARE(expr);	/* asn_DEF_xxx */

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	if(expr_elements_count(arg, expr)) {
		int comp_mode = 0;	/* {root,ext=1,root,root,...} */

		p = MKID(expr->Identifier);
		OUT("static asn_TYPE_member_t asn_MBR_%s[] = {\n", p);
	
		elements = 0;
		INDENTED(TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) {
				if(comp_mode < 3) comp_mode++;
			} else {
				if(comp_mode == 1
				|| expr_better_indirect(arg, v))
					v->marker.flags |= EM_INDIRECT;
				elements++;
				emit_member_table(arg, v);
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
	emit_tag2member_map(arg, tag2el, tag2el_count);

	/*
	 * Emit a map of mandatory elements.
	 */
	p = MKID(expr->Identifier);
	OUT("static uint8_t asn_DEF_%s_mmap", p);
	OUT("[(%d + (8 * sizeof(unsigned int)) - 1) / 8]", elements);
	OUT(" = {\n", p);
	INDENTED(
	if(elements) {
		int delimit = 0;
		int el = 0;
		TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) continue;
			if(delimit) {
				OUT(",\n");
				delimit = 0;
			} else if(el) {
				OUT(" | ");
			}
			OUT("(%d << %d)",
				v->marker.flags?0:1,
				7 - (el % 8));
			if(el && (el % 8) == 0)
				delimit = 1;
			el++;
		}
	} else {
		OUT("0");
	}
	);
	OUT("\n");
	OUT("};\n");

	OUT("static asn_SET_specifics_t asn_DEF_%s_specs = {\n", p);
	INDENTED(
		OUT("sizeof(struct %s),\n", p);
		OUT("offsetof(struct %s, _asn_ctx),\n", p);
		OUT("offsetof(struct %s, _presence_map),\n", p);
		OUT("asn_DEF_%s_tag2el,\n", p);
		OUT("%d,\t/* Count of tags in the map */\n", tag2el_count);
		OUT("%d,\t/* Whether extensible */\n",
			check_if_extensible(expr));
		OUT("(unsigned int *)asn_DEF_%s_mmap\t/* Mandatory elements map */\n", p);
	);
	OUT("};\n");

	/*
	 * Emit asn_DEF_xxx table.
	 */
	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, elements,
			ETD_HAS_SPECIFICS);

	REDIR(OT_TYPE_DECLS);

	return 0;
}

int
asn1c_lang_C_type_SEx_OF(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *memb;

	DEPENDENCIES;

	if(arg->embed) {
		OUT("struct %s {\n", MKID(expr->Identifier));
	} else {
		OUT("typedef struct %s {\n", MKID(expr->Identifier));
	}

	memb = TQ_FIRST(&expr->members);

	INDENT(+1);
	OUT("A_%s_OF(",
		(arg->expr->expr_type == ASN_CONSTR_SET_OF)
			? "SET" : "SEQUENCE");
	if(memb->expr_type & ASN_CONSTR_MASK) {
		arg_t tmp;
		asn1p_expr_t tmp_memb;
		arg->embed++;
			tmp = *arg;
			tmp.expr = &tmp_memb;
			tmp_memb = *memb;
			tmp_memb._anonymous_type = 1;
			if(tmp_memb.Identifier == 0) {
				tmp_memb.Identifier = strdup(
					asn1c_make_identifier(0,
						expr->Identifier, "member", 0));
				assert(tmp_memb.Identifier);
			}
			tmp.default_cb(&tmp);
			if(tmp_memb.Identifier != memb->Identifier)
				free(tmp_memb.Identifier);
		arg->embed--;
		assert(arg->target->target == OT_TYPE_DECLS);
	} else {
		OUT("%s", asn1c_type_name(arg, memb, TNF_CTYPE));
	}
	OUT(") list;\n");
	INDENT(-1);

	PCTX_DEF;
	OUT("} %s%s%s", expr->marker.flags?"*":"",
		expr->_anonymous_type ? "" : MKID(expr->Identifier),
		arg->embed ? "" : "_t");

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
	char *p;

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	if(seq_of) {
		GEN_INCLUDE("constr_SEQUENCE_OF");
	} else {
		GEN_INCLUDE("constr_SET_OF");
	}
	if(!arg->embed)
		GEN_DECLARE(expr);	/* asn_DEF_xxx */

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	p = MKID(expr->Identifier);
	OUT("static asn_TYPE_member_t asn_MBR_%s[] = {\n", p);
	INDENT(+1);
		v = TQ_FIRST(&(expr->members));
		if(!v->Identifier) {
			v->Identifier = strdup("member");
			assert(v->Identifier);
		}
		v->_anonymous_type = 1;
		arg->embed++;
		emit_member_table(arg, v);
		arg->embed--;
	INDENT(-1);
	OUT("};\n");

	/*
	 * Print out asn_DEF_<type>_[all_]tags[] vectors.
	 */
	tv_mode = emit_tags_vectors(arg, expr, &tags_count, &all_tags_count);

	p = MKID(expr->Identifier);
	OUT("static asn_SET_OF_specifics_t asn_DEF_%s_specs = {\n", p);
	INDENTED(
		OUT("sizeof(struct %s),\n", p);
		OUT("offsetof(struct %s, _asn_ctx),\n", p);
		if(expr_as_xmlvaluelist(arg, v))
			OUT("1,\t/* XER encoding is XMLValueList */\n");
		else
			OUT("0,\t/* XER encoding is XMLDelimitedItemList */\n");
	);
	OUT("};\n");

	/*
	 * Emit asn_DEF_xxx table.
	 */
	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, 1,
			ETD_HAS_SPECIFICS);

	REDIR(OT_TYPE_DECLS);

	return 0;
}

int
asn1c_lang_C_type_CHOICE(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	char *id;

	DEPENDENCIES;

	REDIR(OT_DEPS);

	id = MKID(expr->Identifier);
	OUT("typedef enum %s_PR {\n", id);
	INDENTED(
		OUT("%s_PR_NOTHING,\t"
			"/* No components present */\n", id);
		TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) {
				OUT("/* Extensions may appear below */\n");
				continue;
			}
			id = MKID(expr->Identifier);
			OUT("%s_PR_", id);
			id = MKID(v->Identifier);
			OUT("%s,\n", id, id);
		}
	);
	id = MKID(expr->Identifier);
	OUT("} %s_PR;\n", id);

	REDIR(OT_TYPE_DECLS);

	if(arg->embed) {
		OUT("struct %s {\n", id);
	} else {
		OUT("typedef struct %s {\n", id);
	}

	INDENTED(
		OUT("%s_PR present;\n", id);
		OUT("union {\n", id);
		TQ_FOR(v, &(expr->members), next) {
			if(expr_better_indirect(arg, v))
				v->marker.flags |= EM_INDIRECT;
			EMBED(v);
		}
		if(UNNAMED_UNIONS)	OUT("};\n");
		else			OUT("} choice;\n");
	);

	PCTX_DEF;
	OUT("} %s%s%s", expr->marker.flags?"*":"",
		expr->_anonymous_type ? "" : MKID(expr->Identifier),
		arg->embed ? "" : "_t");

	return asn1c_lang_C_type_CHOICE_def(arg);
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
	char *p;

	/*
	 * Fetch every inner tag from the tag to elements map.
	 */
	if(_fill_tag2el_map(arg, &tag2el, &tag2el_count, -1)) {
		if(tag2el) free(tag2el);
		return -1;
	}

	GEN_INCLUDE("constr_CHOICE");
	if(!arg->embed)
		GEN_DECLARE(expr);	/* asn_DEF_xxx */

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	if(expr_elements_count(arg, expr)) {
		int comp_mode = 0;	/* {root,ext=1,root,root,...} */

		p = MKID(expr->Identifier);
		OUT("static asn_TYPE_member_t asn_MBR_%s[] = {\n", p);

		elements = 0;
		INDENTED(TQ_FOR(v, &(expr->members), next) {
			if(v->expr_type == A1TC_EXTENSIBLE) {
				if(comp_mode < 3) comp_mode++;
			} else {
				if(comp_mode == 1
				|| expr_better_indirect(arg, v))
					v->marker.flags |= EM_INDIRECT;
				elements++;
				emit_member_table(arg, v);
			}
		});
		OUT("};\n");
	} else {
		elements = 0;
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
	emit_tag2member_map(arg, tag2el, tag2el_count);

	p = MKID(expr->Identifier);
	OUT("static asn_CHOICE_specifics_t asn_DEF_%s_specs = {\n", p);
	INDENTED(
		OUT("sizeof(struct %s),\n", p);
		OUT("offsetof(struct %s, _asn_ctx),\n", p);
		OUT("offsetof(struct %s, present),\n", p);
		OUT("sizeof(((struct %s *)0)->present),\n", p);
		OUT("asn_DEF_%s_tag2el,\n", p);
		OUT("%d,\t/* Count of tags in the map */\n", tag2el_count);
		OUT("%d\t/* Whether extensible */\n",
			check_if_extensible(expr));
	);
	OUT("};\n");

	/*
	 * Emit asn_DEF_xxx table.
	 */
	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, elements,
			ETD_HAS_SPECIFICS);

	REDIR(OT_TYPE_DECLS);

	return 0;
}

int
asn1c_lang_C_type_REFERENCE(arg_t *arg) {
	asn1p_ref_t *ref;

	ref = arg->expr->reference;
	if(ref->components[ref->comp_count-1].name[0] == '&') {
		asn1p_expr_t *extract;
		arg_t tmp;
		int ret;

		extract = asn1f_class_access_ex(arg->asn, arg->expr->module,
			arg->expr, ref);
		if(extract == NULL)
			return -1;

		extract = asn1p_expr_clone(extract, 0);
		if(extract) {
			if(extract->Identifier)
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
		tmp.mod = extract->module;
		tmp.expr = extract;

		ret = arg->default_cb(&tmp);

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
	char *p;

	if(arg->embed) {
		enum tnfmt tnfmt = TNF_CTYPE;

		/*
		 * If this is an optional compound type,
		 * refer it using "struct X" convention,
		 * as it may recursively include the current structure.
		 */
		if(expr->marker.flags) {
			asn1p_expr_t *terminal;
			terminal = asn1f_find_terminal_type_ex(arg->asn, expr);
			if(terminal
			&& (terminal->expr_type & ASN_CONSTR_MASK)) {
				REDIR(OT_DEPS);
			 	tnfmt = TNF_RSAFE;
				OUT("\n");
				OUT("%s;\t/* Forward declaration */\n",
					asn1c_type_name(arg, arg->expr, tnfmt));
			}
		}

		REDIR(OT_TYPE_DECLS);

		OUT("%s\t", asn1c_type_name(arg, arg->expr, tnfmt));
		OUT("%s", expr->marker.flags?"*":" ");
		OUT("%s", MKID(expr->Identifier));
		if((expr->marker.flags & EM_DEFAULT) == EM_DEFAULT)
			OUT("\t/* DEFAULT %s */",
			    asn1f_printable_value(expr->marker.default_value));
		else if((expr->marker.flags & EM_OPTIONAL) == EM_OPTIONAL)
			OUT("\t/* OPTIONAL */");

		REDIR(OT_TYPE_DECLS);
		return 0;
	}


	GEN_INCLUDE(asn1c_type_name(arg, expr, TNF_INCLUDE));

	REDIR(OT_TYPE_DECLS);

	OUT("typedef %s\t", asn1c_type_name(arg, arg->expr, TNF_CTYPE));
	OUT("%s", expr->marker.flags?"*":" ");
	OUT("%s_t", MKID(expr->Identifier));

	/*
	 * If this type just blindly refers the other type, alias it.
	 * 	Type1 ::= Type2
	 */
	if((!expr->constraints || (arg->flags & A1C_NO_CONSTRAINTS))
		&& expr->tag.tag_class == TC_NOCLASS
		&& !TQ_FIRST(&(expr->members))
	) {
		char *type_name;
		REDIR(OT_FUNC_DECLS);
		type_name = asn1c_type_name(arg, expr, TNF_SAFE);
		OUT("/* This type is equivalent to %s */\n", type_name);
		p = MKID(expr->Identifier);
		if(HIDE_INNER_DEFS) OUT("/* ");
		OUT("#define\tasn_DEF_%s\t", p);
		type_name = asn1c_type_name(arg, expr, TNF_SAFE);
		OUT("asn_DEF_%s\n", type_name);
		if(HIDE_INNER_DEFS)
			OUT(" // (Use -fall-defs-global to expose) */");
		REDIR(OT_CODE);
		OUT("/* This type is equivalent to %s */\n", type_name);
		OUT("\n");
		REDIR(OT_TYPE_DECLS);
		return 0;
	}

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out asn_DEF_<type>_[all_]tags[] vectors.
	 */
	tv_mode = emit_tags_vectors(arg, expr, &tags_count, &all_tags_count);

	emit_type_DEF(arg, expr, tv_mode, tags_count, all_tags_count, 0,
			ETD_NO_SPECIFICS);

	REDIR(OT_CODE);

	/*
	 * Constraint checking.
	 */
	if(!(arg->flags & A1C_NO_CONSTRAINTS)) {
		p = MKID(expr->Identifier);
		OUT("int\n");
		OUT("%s_constraint("
			"asn_TYPE_descriptor_t *td, const void *sptr,\n", p);
		INDENT(+1);
		OUT("\t\tasn_app_consume_bytes_f *app_errlog, void *app_key) {");
		OUT("\n");
		if(asn1c_emit_constraint_checking_code(arg) == 1) {
			OUT("/* Replace with underlying type checker */\n");
			OUT("td->check_constraints "
				"= asn_DEF_%s.check_constraints;\n",
				asn1c_type_name(arg, expr, TNF_SAFE));
			OUT("return td->check_constraints"
				"(td, sptr, app_errlog, app_key);\n");
		}
		INDENT(-1);
		OUT("}\n");
		OUT("\n");
	}

	/*
	 * Emit suicidal functions.
	 */

	/*
	 * This function replaces certain fields from the definition
	 * of a type with the corresponding fields from the basic type
	 * (from which the current type is inherited).
	 */
	OUT("/*\n");
	OUT(" * This type is implemented using %s,\n",
		asn1c_type_name(arg, expr, TNF_SAFE));
	OUT(" * so here we adjust the DEF accordingly.\n");
	OUT(" */\n");
	OUT("static void\n");
	p = MKID(expr->Identifier);
	OUT("%s_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {\n", p);
	INDENT(+1);
	{
	asn1p_expr_t *terminal = asn1f_find_terminal_type_ex(arg->asn, expr);
	char *type_name = asn1c_type_name(arg, expr, TNF_SAFE);
	OUT("td->free_struct    = asn_DEF_%s.free_struct;\n",    type_name);
	OUT("td->print_struct   = asn_DEF_%s.print_struct;\n",   type_name);
	OUT("td->ber_decoder    = asn_DEF_%s.ber_decoder;\n",    type_name);
	OUT("td->der_encoder    = asn_DEF_%s.der_encoder;\n",    type_name);
	OUT("td->xer_decoder    = asn_DEF_%s.xer_decoder;\n",    type_name);
	OUT("td->xer_encoder    = asn_DEF_%s.xer_encoder;\n",    type_name);
	if(!terminal && !tags_count) {
	  OUT("/* The next four lines are here because of -fknown-extern-type */\n");
	  OUT("td->tags           = asn_DEF_%s.tags;\n",         type_name);
	  OUT("td->tags_count     = asn_DEF_%s.tags_count;\n",   type_name);
	  OUT("td->all_tags       = asn_DEF_%s.all_tags;\n",     type_name);
	  OUT("td->all_tags_count = asn_DEF_%s.all_tags_count;\n",type_name);
	  OUT("/* End of these lines */\n");
	}
	OUT("td->elements       = asn_DEF_%s.elements;\n",       type_name);
	OUT("td->elements_count = asn_DEF_%s.elements_count;\n", type_name);
	OUT("td->specifics      = asn_DEF_%s.specifics;\n",      type_name);
	}
	INDENT(-1);
	OUT("}\n");
	OUT("\n");

	p = MKID(expr->Identifier);
	OUT("void\n");
	OUT("%s_free(asn_TYPE_descriptor_t *td,\n", p);
	INDENTED(
	OUT("\tvoid *struct_ptr, int contents_only) {\n");
	OUT("%s_inherit_TYPE_descriptor(td);\n", p);
	OUT("td->free_struct(td, struct_ptr, contents_only);\n");
	);
	OUT("}\n");
	OUT("\n");

	p = MKID(expr->Identifier);
	OUT("int\n");
	OUT("%s_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,\n", p);
	INDENTED(
	OUT("\tint ilevel, asn_app_consume_bytes_f *cb, void *app_key) {\n");
	OUT("%s_inherit_TYPE_descriptor(td);\n", p);
	OUT("return td->print_struct(td, struct_ptr, ilevel, cb, app_key);\n");
	);
	OUT("}\n");
	OUT("\n");

	p = MKID(expr->Identifier);
	OUT("ber_dec_rval_t\n");
	OUT("%s_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,\n", p);
	INDENTED(
	OUT("\tvoid **structure, void *bufptr, size_t size, int tag_mode) {\n");
	OUT("%s_inherit_TYPE_descriptor(td);\n", p);
	OUT("return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);\n");
	);
	OUT("}\n");
	OUT("\n");

	p = MKID(expr->Identifier);
	OUT("asn_enc_rval_t\n");
	OUT("%s_encode_der(asn_TYPE_descriptor_t *td,\n", p);
	INDENTED(
	OUT("\tvoid *structure, int tag_mode, ber_tlv_tag_t tag,\n");
	OUT("\tasn_app_consume_bytes_f *cb, void *app_key) {\n");
	OUT("%s_inherit_TYPE_descriptor(td);\n", p);
	OUT("return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);\n");
	);
	OUT("}\n");
	OUT("\n");

	p = MKID(expr->Identifier);
	OUT("asn_enc_rval_t\n");
	OUT("%s_encode_xer(asn_TYPE_descriptor_t *td, void *structure,\n", p);
	INDENTED(
	OUT("\tint ilevel, enum xer_encoder_flags_e flags,\n");
	OUT("\tasn_app_consume_bytes_f *cb, void *app_key) {\n");
	OUT("%s_inherit_TYPE_descriptor(td);\n", p);
	OUT("return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);\n");
	);
	OUT("}\n");
	OUT("\n");

	REDIR(OT_FUNC_DECLS);

	p = MKID(expr->Identifier);
	if(HIDE_INNER_DEFS) OUT("/* ");
	OUT("extern asn_TYPE_descriptor_t asn_DEF_%s;", p);
	if(HIDE_INNER_DEFS) OUT(" // (Use -fall-defs-global to expose) */");
	OUT("\n");
	OUT("asn_struct_free_f %s_free;\n", p);
	OUT("asn_struct_print_f %s_print;\n", p);
	OUT("asn_constr_check_f %s_constraint;\n", p);
	OUT("ber_type_decoder_f %s_decode_ber;\n", p);
	OUT("der_type_encoder_f %s_encode_der;\n", p);
	OUT("xer_type_encoder_f %s_encode_xer;\n", p);

	REDIR(OT_TYPE_DECLS);

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

static int check_if_extensible(asn1p_expr_t *expr) {
	asn1p_expr_t *v;
	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) return 1;
	}
	return 0;
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
	OUT(" | (%" PRIdASN " << 2))", tag->tag_value);

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
_fill_tag2el_map(arg_t *arg, tag2el_t **tag2el, int *count, int el_no) {
	asn1p_expr_t *expr = arg->expr;
	arg_t tmparg = *arg;
	asn1p_expr_t *v;
	int element = 0;

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE)
			continue;

		tmparg.expr = v;

		if(_add_tag2el_member(&tmparg, tag2el, count,
				(el_no==-1)?element:el_no)) {
			return -1;
		}

		element++;
	}

	/*
	 * Sort the map according to canonical order of their tags
	 * and element numbers.
	 */
	qsort(*tag2el, *count, sizeof(**tag2el), _tag2el_cmp);

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
_add_tag2el_member(arg_t *arg, tag2el_t **tag2el, int *count, int el_no) {
	struct asn1p_type_tag_s tag;
	int ret;

	assert(el_no >= 0);

	ret = asn1f_fetch_outmost_tag(arg->asn, arg->expr->module,
			arg->expr, &tag, 1);
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

		DEBUG("Found tag for %s: %ld",
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
		return _fill_tag2el_map(arg, tag2el, count, el_no);
	}

	if(arg->expr->expr_type == A1TC_REFERENCE) {
		arg_t tmp = *arg;
		asn1p_expr_t *expr;
		expr = asn1f_lookup_symbol_ex(tmp.asn, tmp.mod, tmp.expr,
			arg->expr->reference);
		if(expr) {
			tmp.mod = expr->module;
			tmp.expr = expr;
			return _add_tag2el_member(&tmp, tag2el, count, el_no);
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
emit_tag2member_map(arg_t *arg, tag2el_t *tag2el, int tag2el_count) {
	asn1p_expr_t *expr = arg->expr;

	OUT("static asn_TYPE_tag2member_t asn_DEF_%s_tag2el[] = {\n",
		MKID(expr->Identifier));
	if(tag2el_count) {
		int i;
		for(i = 0; i < tag2el_count; i++) {
			OUT("    { ");
			_print_tag(arg, &tag2el[i].el_tag);
			OUT(", ");
			OUT("%d, ", tag2el[i].el_no);
			OUT("%d, ", tag2el[i].toff_first);
			OUT("%d ", tag2el[i].toff_last);
			OUT("}, /* %s at %d */\n",
				tag2el[i].from_expr->Identifier,
				tag2el[i].from_expr->_lineno
			);
		}
	}
	OUT("};\n");

	return 0;;
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
	tags_count = asn1f_fetch_tags(arg->asn, expr->module, expr, &tags, 0);
	if(tags_count < 0)
		return -1;

	/* Fetch a chain of tags */
	all_tags_count = asn1f_fetch_tags(arg->asn, expr->module, expr,
		&all_tags, AFT_FULL_COLLECT);
	if(all_tags_count < 0) {
		if(tags) free(tags);
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
		OUT("static ber_tlv_tag_t asn_DEF_%s%s_tags[] = {\n",	\
			MKID(expr->Identifier), name);			\
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

	if(tags) free(tags);
	if(all_tags) free(all_tags);

	*tags_count_r = tags_count;
	*all_tags_count_r = all_tags_count;

	return tv_mode;
}

static int
expr_elements_count(arg_t *arg, asn1p_expr_t *expr) {
	asn1p_expr_t *topmost_parent;
	asn1p_expr_t *v;
	int elements = 0;

	topmost_parent = asn1f_find_terminal_type_ex(arg->asn, expr);
	if(!topmost_parent) return 0;

	if(!(topmost_parent->expr_type & ASN_CONSTR_MASK))
		return 0;

	TQ_FOR(v, &(topmost_parent->members), next) {
		if(v->expr_type != A1TC_EXTENSIBLE)
			elements++;
	}

	return elements;
}

static int
emit_member_table(arg_t *arg, asn1p_expr_t *expr) {
	static int global_memb_unique;
	int save_target;
	arg_t tmp_arg;
	struct asn1p_type_tag_s outmost_tag_s;
	struct asn1p_type_tag_s *outmost_tag;
	char *p;

	if(asn1f_fetch_outmost_tag(arg->asn,
			expr->module, expr, &outmost_tag_s, 1)) {
		outmost_tag = 0;
	} else {
		outmost_tag = &outmost_tag_s;
	}

	OUT("{ ");

	if(outmost_tag && outmost_tag->tag_value == -1)
		OUT("ATF_OPEN_TYPE | ");
	OUT("%s, ", expr->marker.flags?"ATF_POINTER":"ATF_NOFLAGS");
	if((expr->marker.flags & EM_OPTIONAL) == EM_OPTIONAL) {
		asn1p_expr_t *tv;
		int opts = 0;
		for(tv = expr; tv && tv->marker.flags;
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
		OUT("offsetof(struct %s, ", MKID(arg->expr->Identifier));
		if(arg->expr->expr_type == ASN_CONSTR_CHOICE
			&& (!UNNAMED_UNIONS)) OUT("choice.");
		OUT("%s),\n", MKID(expr->Identifier));
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
	if(expr->tag.tag_class) {
		if(expr->tag.tag_mode == TM_IMPLICIT)
		OUT("-1,\t/* IMPLICIT tag at current level */\n");
		else
		OUT("+1,\t/* EXPLICIT tag at current level */\n");
	} else {
		OUT("0,\n");
	}
	if(C99_MODE) OUT(".type = ");
	if(expr->_anonymous_type && (expr->expr_type & ASN_CONSTR_MASK)) {
		OUT("(void *)&asn_DEF_%s_member,\n",
			MKID(arg->expr->Identifier));
	} else if(expr->expr_type & ASN_CONSTR_MASK) {
		OUT("(void *)&asn_DEF_%s,\n",
			MKID(expr->Identifier));
	} else {
		OUT("(void *)&asn_DEF_%s,\n",
			asn1c_type_name(arg, expr, TNF_SAFE));
	}
	if(C99_MODE) OUT(".memb_constraints = ");
	if(expr->constraints) {
		if(arg->flags & A1C_NO_CONSTRAINTS) {
			OUT("0,\t/* No check because of -fno-constraints */\n");
		} else {
			char *id = MKID(expr->Identifier);
			if(expr->_anonymous_type
					&& !strcmp(expr->Identifier, "member"))
				id = asn1c_type_name(arg, expr, TNF_SAFE);
			OUT("memb_%s_%d_constraint,\n", id,
				++global_memb_unique);
		}
	} else {
		OUT("0,\t/* Defer to actual type */\n");
	}
	if(C99_MODE) OUT(".name = ");
	OUT("\"%s\"\n", expr->_anonymous_type ? "" : expr->Identifier);
	OUT("},\n");
	INDENT(-1);

	if(!expr->constraints || (arg->flags & A1C_NO_CONSTRAINTS))
		return 0;

	save_target = arg->target->target;
	REDIR(OT_CODE);

	if(expr->_anonymous_type && !strcmp(expr->Identifier, "member"))
		p = asn1c_type_name(arg, expr, TNF_SAFE);
	else
		p = MKID(expr->Identifier);
	OUT("static int\n");
	OUT("memb_%s_%d_constraint(asn_TYPE_descriptor_t *td, const void *sptr,\n", p, global_memb_unique);
	INDENT(+1);
	OUT("\t\tasn_app_consume_bytes_f *app_errlog, void *app_key) {\n");
	tmp_arg = *arg;
	tmp_arg.expr = expr;
	if(asn1c_emit_constraint_checking_code(&tmp_arg) == 1) {
		OUT("return td->check_constraints"
			"(td, sptr, app_errlog, app_key);\n");
	}
	INDENT(-1);
	OUT("}\n");
	OUT("\n");

	REDIR(save_target);

	return 0;
}

static int
emit_type_DEF(arg_t *arg, asn1p_expr_t *expr, enum tvm_compat tv_mode, int tags_count, int all_tags_count, int elements_count, enum etd_spec spec) {
	char *p;

	p = MKID(expr->Identifier);
	if(HIDE_INNER_DEFS)
		OUT("static /* Use -fall-defs-global to expose */\n");
	OUT("asn_TYPE_descriptor_t asn_DEF_%s = {\n", p);
	INDENT(+1);
		OUT("\"%s\",\n", expr->_anonymous_type?"":expr->Identifier);

		if(expr->expr_type & ASN_CONSTR_MASK) {
			p = asn1c_type_name(arg, arg->expr, TNF_SAFE);
		}

		OUT("%s_free,\n", p);
		OUT("%s_print,\n", p);
		OUT("%s_constraint,\n", p);
		OUT("%s_decode_ber,\n", p);
		OUT("%s_encode_der,\n", p);
		OUT("0,				/* Not implemented yet */\n");
		OUT("%s_encode_xer,\n", p);

		p = MKID(expr->Identifier);

		if(expr->expr_type == ASN_CONSTR_CHOICE) {
			OUT("CHOICE_outmost_tag,\n");
		} else {
			OUT("0,\t/* Use generic outmost tag fetcher */\n");
		}

		if(tags_count) {
			OUT("asn_DEF_%s_tags,\n", p);
			OUT("sizeof(asn_DEF_%s_tags)\n", p);
			OUT("\t/sizeof(asn_DEF_%s_tags[0])", p);
			if(tv_mode == _TVM_SUBSET
			&& tags_count != all_tags_count)
				OUT(" - %d", all_tags_count - tags_count);
			OUT(", /* %d */\n", tags_count);
		} else {
			OUT("0,\t/* No effective tags (pointer) */\n");
			OUT("0,\t/* No effective tags (count) */\n");
		}

		if(all_tags_count && tv_mode == _TVM_DIFFERENT) {
			OUT("asn_DEF_%s_all_tags,\n", p);
			OUT("sizeof(asn_DEF_%s_all_tags)\n", p);
			OUT("\t/sizeof(asn_DEF_%s_all_tags[0]), /* %d */\n",
				p, all_tags_count);
		} else if(all_tags_count) {
			OUT("asn_DEF_%s_tags,\t/* Same as above */\n", p);
			OUT("sizeof(asn_DEF_%s_tags)\n", p);
			OUT("\t/sizeof(asn_DEF_%s_tags[0]), /* %d */\n",
				p, all_tags_count);
		} else {
			OUT("0,\t/* No tags (pointer) */\n");
			OUT("0,\t/* No tags (count) */\n");
		}

		if(elements_count) {
			OUT("asn_MBR_%s,\n", p);
			if(expr->expr_type == ASN_CONSTR_SEQUENCE_OF
			|| expr->expr_type == ASN_CONSTR_SET_OF) {
				OUT("%d,\t/* Single element */\n",
					elements_count);
				assert(elements_count == 1);
			} else {
				OUT("%d,\t/* Elements count */\n",
					elements_count);
			}
		} else {
			//if(expr->meta_type == AMT_TYPEREF)
			if(expr_elements_count(arg, expr))
				OUT("0, 0,\t/* Defined elsewhere */\n");
			else
				OUT("0, 0,\t/* No members */\n");
		}

		switch(spec) {
		case ETD_NO_SPECIFICS:
			OUT("0\t/* No specifics */\n");
			break;
		case ETD_HAS_SPECIFICS:
			OUT("&asn_DEF_%s_specs\t/* Additional specs */\n", p);
		}
	INDENT(-1);
	OUT("};\n");
	OUT("\n");

	return 0;
}

/*
 * Check if it is better to make this type indirectly accessed via
 * a pointer.
 * This may be the case for the following recursive definition:
 * Type ::= CHOICE { member Type };
 */
static int
expr_better_indirect(arg_t *arg, asn1p_expr_t *expr) {
	asn1p_expr_t *top_parent;
	asn1p_expr_t *terminal;

	if(expr->expr_type != A1TC_REFERENCE)
		return 0;

	/* Rewind to the topmost parent expression */
	if((top_parent = expr->parent_expr)) {
		while(top_parent->parent_expr)
			top_parent = top_parent->parent_expr;
	} else {
		return 0;
	}

	terminal = asn1f_find_terminal_type_ex(arg->asn, expr);

	return (terminal == top_parent);
}

static int
expr_as_xmlvaluelist(arg_t *arg, asn1p_expr_t *expr) {
	expr = asn1f_find_terminal_type_ex(arg->asn, expr);
	if(!expr) return 0;

	/* X.680, 25.5, Table 5 */
	switch(expr->expr_type) {
	case ASN_CONSTR_CHOICE:
	case ASN_BASIC_BOOLEAN:
	case ASN_BASIC_ENUMERATED:
	case ASN_BASIC_NULL:
		return 1;
	default:
		return 0;
	}
}
