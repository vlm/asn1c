/*
 * Don't look into this file. First, because it's a mess, and second, because
 * it's a brain of the compiler, and you don't wanna mess with brains do you? ;)
 */
#include "asn1c_internal.h"
#include "asn1c_C.h"
#include <asn1fix_export.h>	/* exportable stuff from libasn1fix */

static int asn1c_lang_C_type_SEQUENCE_def(arg_t *arg);
static int asn1c_lang_C_type_SET_def(arg_t *arg);
static int asn1c_lang_C_type_CHOICE_def(arg_t *arg);
static int asn1c_lang_C_type_SEx_OF_def(arg_t *arg, int seq_of);
static int _print_tag(arg_t *arg, asn1p_expr_t *expr, struct asn1p_type_tag_s *tag_p);
static int emit_constraint_checking_code(arg_t *arg);
static int emit_single_constraint_check(arg_t *arg, asn1p_constraint_t *ct, int mode);
static int emit_alphabet_tables(arg_t *arg, asn1p_constraint_t *ct, int *table);
static int emit_alphabet_check_cycle(arg_t *arg);
static int check_constraint_type_presence(asn1p_constraint_t *ct, enum asn1p_constraint_type_e type);
static asn1p_expr_type_e _find_terminal_type(arg_t *arg);
static int emit_value_determination_code(arg_t *arg);
static int emit_size_determination_code(arg_t *arg);
static long compute_min_size(arg_t *arg);
static long compute_max_size(arg_t *arg);
static long compute_xxx_size(arg_t *arg, int _max);

typedef struct tag2el_s {
	struct asn1p_type_tag_s el_tag;
	int el_no;
	asn1p_expr_t *from_expr;
} tag2el_t;

static int _fill_tag2el_map(arg_t *arg, tag2el_t **tag2el, int *count, int el_no);
static int _add_tag2el_member(arg_t *arg, tag2el_t **tag2el, int *count, int el_no);

#define	C99_MODE	(arg->flags & A1C_NO_C99)
#define	UNNAMED_UNIONS	(arg->flags & A1C_UNNAMED_UNIONS)

#define	PCTX_DEF INDENTED(		\
	OUT("\n");			\
	OUT("/* Context for parsing across buffer boundaries */\n");	\
	OUT("ber_dec_ctx_t _ber_dec_ctx;\n"));

#define	DEPENDENCIES	do {			\
	int saved_target = arg->target->target;	\
	int saved_indent = arg->indent_level;	\
	int comment_printed = 0;		\
	REDIR(OT_DEPS);				\
	arg->indent_level = 0;			\
	TQ_FOR(v, &(expr->members), next) {	\
		if((!(v->expr_type & ASN_CONSTR_MASK)	\
		&& v->expr_type > ASN_CONSTR_MASK)	\
		|| v->meta_type == AMT_TYPEREF) {	\
			if(!comment_printed++)		\
				OUT("/* Dependencies for %s */\n",	\
				asn1c_type_name(arg, expr, TNF_UNMODIFIED));	\
			OUT("#include <%s.h>\n",			\
				asn1c_type_name(arg, v, TNF_INCLUDE));	\
		}					\
	}						\
	if(expr->expr_type == ASN_CONSTR_SET_OF)	\
		OUT("#include <asn_SET_OF.h>\n");	\
	if(expr->expr_type == ASN_CONSTR_SEQUENCE_OF)	\
		OUT("#include <asn_SEQUENCE_OF.h>\n");	\
	OUT("\n");				\
	REDIR(saved_target);			\
	INDENT(saved_indent);			\
	} while(0)

#define	MKID(id)	asn1c_make_identifier(0, (id), 0)

int
asn1c_lang_C_type_ENUMERATED(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;

	REDIR(OT_DEPS);

	OUT("typedef enum %s {\n", MKID(expr->Identifier));
	TQ_FOR(v, &(expr->members), next) {
		switch(v->expr_type) {
		case A1TC_UNIVERVAL:
			OUT("\t%s\t= %lld,\n",
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

	return asn1c_lang_C_type_SIMPLE_TYPE(arg);
}


int
asn1c_lang_C_type_INTEGER(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;

	REDIR(OT_DEPS);

	if(TQ_FIRST(&(expr->members))) {
		OUT("typedef enum %s {\n", MKID(expr->Identifier));
		TQ_FOR(v, &(expr->members), next) {
			switch(v->expr_type) {
			case A1TC_UNIVERVAL:
				OUT("\t%s\t= %lld,\n",
					asn1c_make_identifier(0,
						expr->Identifier,
						v->Identifier, 0),
					v->value->value.v_integer);
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
		OUT("struct %s {\n",
			MKID(expr->Identifier));
	} else {
		OUT("typedef struct %s {\n",
			MKID(expr->Identifier));
	}

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			if(comp_mode < 3) comp_mode++;
		}
		if(comp_mode == 1 && !v->marker)
			v->marker = EM_OPTIONAL;
		EMBED(v);
	}

	PCTX_DEF;
	OUT("} %s%s", expr->marker?"*":"",
		MKID(expr->Identifier));
	if(arg->embed) OUT(";\n"); else OUT("_t;\n");

	return asn1c_lang_C_type_SEQUENCE_def(arg);
}

static int
asn1c_lang_C_type_SEQUENCE_def(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int elements;	/* Number of elements */
	int tags_impl_skip = 0;
	int comp_mode = 0;	/* {root,ext=1,root,root,...} */
	int ext_start = -1;
	int ext_stop = -1;
	char *p;

	REDIR(OT_STAT_DEFS);

	OUT("#include <constr_SEQUENCE.h>\n");
	OUT("\n");

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	p = MKID(expr->Identifier);
	OUT("static asn1_SEQUENCE_element_t asn1_DEF_%s_elements[] = {\n", p);

	elements = 0;
	INDENTED(TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			if((++comp_mode) == 1)
				ext_start = elements - 1;
			else
				ext_stop = elements - 1;
			continue;
		}
	OUT("{ ");
		elements++;
		OUT("offsetof(struct %s, ", MKID(expr->Identifier));
		OUT("%s), ", MKID(v->Identifier));
		if(v->marker) {
			asn1p_expr_t *tv;
			int opts = 0;
			for(tv = v; tv && tv->marker;
				tv = TQ_NEXT(tv, next), opts++) {
				if(tv->expr_type == A1TC_EXTENSIBLE)
					opts--;
			}
			OUT("%d,", opts);
		} else {
			OUT("0,");
		}
		OUT("\n");
		INDENT(+1);
		if(C99_MODE) OUT(".tag = ");
		_print_tag(arg, v, NULL);
		OUT(",\n");
		if(C99_MODE) OUT(".tag_mode = ");
		if(v->tag.tag_class) {
			if(v->tag.tag_mode == TM_IMPLICIT)
			OUT("-1,\t/* IMPLICIT tag at current level */\n");
			else
			OUT("+1,\t/* EXPLICIT tag at current level */\n");
		} else {
			OUT("0,\n");
		}
		if(C99_MODE) OUT(".type = ");
		OUT("(void *)&asn1_DEF_%s,\n",
			asn1c_type_name(arg, v, TNF_SAFE));
		if(C99_MODE) OUT(".name = ");
		OUT("\"%s\"\n", v->Identifier);
		OUT("},\n");
		INDENT(-1);
	});
	OUT("};\n");

	p = MKID(expr->Identifier);
	OUT("static ber_tlv_tag_t asn1_DEF_%s_tags[] = {\n", p);
	INDENTED(
		if(expr->tag.tag_class) {
			_print_tag(arg, expr, &expr->tag);
			if(expr->tag.tag_mode != TM_EXPLICIT)
				tags_impl_skip++;
		}
		if(!expr->tag.tag_class
		|| (expr->meta_type == AMT_TYPE
			&& expr->tag.tag_mode == TM_EXPLICIT)) {
			struct asn1p_type_tag_s tag;
			if(expr->tag.tag_class)
				OUT(",\n");
			tag.tag_class = TC_UNIVERSAL;
			tag.tag_mode = TM_IMPLICIT;
			tag.tag_value = expr_type2uclass_value[expr->expr_type];
			_print_tag(arg, expr, &tag);
		}
		OUT("\n");
	);
	OUT("};\n");

	OUT("static asn1_SEQUENCE_specifics_t asn1_DEF_%s_specs = {\n", p);
	INDENTED(
		OUT("sizeof(struct %s),\n", p);
		OUT("offsetof(struct %s, _ber_dec_ctx),\n", p);
		OUT("asn1_DEF_%s_elements,\n", p);
		OUT("%d,\t/* Elements count */\n", elements);
		OUT("%d,\t/* Start extensions */\n",
			ext_start);
		OUT("%d\t/* Stop extensions */\n",
			(ext_stop<ext_start)?elements+1:ext_stop, ext_stop);
	);
	OUT("};\n");
	OUT("asn1_TYPE_descriptor_t asn1_DEF_%s = {\n", p);
	INDENTED(
		OUT("\"%s\",\n", expr->Identifier);
		OUT("SEQUENCE_constraint,\n");
		OUT("SEQUENCE_decode_ber,\n");
		OUT("SEQUENCE_encode_der,\n");
		OUT("SEQUENCE_print,\n");
		OUT("SEQUENCE_free,\n");
		OUT("0,\t/* Use generic outmost tag fetcher */\n");
		OUT("asn1_DEF_%s_tags,\n", p);
		OUT("sizeof(asn1_DEF_%s_tags)\n", p);
		OUT("\t/sizeof(asn1_DEF_%s_tags[0]),\n", p);
		OUT("%d,\t/* Tags to skip */\n", tags_impl_skip);
		OUT("%d,\t/* Whether CONSTRUCTED */\n", 1);
		OUT("&asn1_DEF_%s_specs\t/* Additional specs */\n", p);
	);
	OUT("};\n");
	OUT("\n");

	REDIR(OT_DEPS);
	OUT("#include <constr_SEQUENCE.h>\n");
	OUT("\n");
	if(!arg->embed)
	OUT("extern asn1_TYPE_descriptor_t asn1_DEF_%s;\n", p);
	REDIR(OT_TYPE_DECLS);

	return 0;
}

int
asn1c_lang_C_type_SEQUENCE_OF(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;

	DEPENDENCIES;

	if(arg->embed) {
		OUT("struct %s {\n", MKID(expr->Identifier));
	} else {
		OUT("typedef struct %s {\n", MKID(expr->Identifier));
	}

	TQ_FOR(v, &(expr->members), next) {
		INDENTED(OUT("A_SEQUENCE_OF(%s) list;\n",
			asn1c_type_name(arg, v, TNF_RSAFE)));
	}

	PCTX_DEF;
	OUT("} %s%s", expr->marker?"*":"", MKID(expr->Identifier));
	if(arg->embed) OUT(";\n"); else OUT("_t;\n");

	/*
	 * SET OF/SEQUENCE OF definition, SEQUENCE OF mode.
	 */
	return asn1c_lang_C_type_SEx_OF_def(arg, 1);
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
	OUT("enum %s_PR_e {\n", MKID(expr->Identifier));
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
	OUT("};\n");

	REDIR(OT_TYPE_DECLS);

	if(arg->embed) {
		OUT("struct %s {\n", MKID(expr->Identifier));
	} else {
		OUT("typedef struct %s {\n", MKID(expr->Identifier));
	}

	TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			if(comp_mode < 3) comp_mode++;
		}
		if(comp_mode == 1 && !v->marker)
			v->marker = EM_OPTIONAL;
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
	OUT("} %s%s", expr->marker?"*":"", MKID(expr->Identifier));
	if(arg->embed) OUT(";\n"); else OUT("_t;\n");

	return asn1c_lang_C_type_SET_def(arg);
}

/*
 * Compare tags according to their canonical order.
 * Canonical order: [UNIVERSAL] [APPLICATION] [] [PRIVATE]
 * As you see, the class is encoded using the two lowest bits.
 */
static arg_t *_ctc_arg;
static int _canonical_tags_cmp(const void *ap, const void *bp)
	__attribute__ ((unused));
static int
_canonical_tags_cmp(const void *ap, const void *bp) {
	asn1p_expr_t *a, *b;
	struct asn1p_type_tag_s ta, tb;

	(const asn1p_expr_t *)a = *(const asn1p_expr_t * const *)ap;
	(const asn1p_expr_t *)b = *(const asn1p_expr_t * const *)bp;

	if(asn1f_fetch_tag(_ctc_arg->asn, _ctc_arg->mod, a, &ta)
	|| asn1f_fetch_tag(_ctc_arg->asn, _ctc_arg->mod, b, &tb))
		return 0;

	if(ta.tag_class == tb.tag_class) {
		if(ta.tag_value == tb.tag_value)
			return 0;
		else if(ta.tag_value < tb.tag_value)
			return -1;
		else
			return 1;
	} else if(ta.tag_class < tb.tag_class) {
		return -1;
	} else {
		return 1;
	}
}

static int
_tag2el_cmp(const void *ap, const void *bp) {
	const tag2el_t *a = ap;
	const tag2el_t *b = bp;
	const struct asn1p_type_tag_s *ta = &a->el_tag;
	const struct asn1p_type_tag_s *tb = &b->el_tag;

	if(ta->tag_class == tb->tag_class) {
		if(ta->tag_value == tb->tag_value)
			return 0;
		else if(ta->tag_value < tb->tag_value)
			return -1;
		else
			return 1;
	} else if(ta->tag_class < tb->tag_class) {
		return -1;
	} else {
		return 1;
	}
}

static int
asn1c_lang_C_type_SET_def(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int elements;
	int tags_impl_skip = 0;
	int comp_mode = 0;	/* {root,ext=1,root,root,...} */
	int extensible = 0;
	tag2el_t *tag2el = NULL;
	int tag2el_count = 0;
	char *p;

	/*
	 * Fetch every inner tag from the tag to elements map.
	 */
	if(_fill_tag2el_map(arg, &tag2el, &tag2el_count, -1)) {
		if(tag2el) free(tag2el);
		return -1;
	} else {
		/*
		 * Sort the map according to canonical order of their tags.
		 */
		_ctc_arg = arg;
		qsort(tag2el, tag2el_count, sizeof(*tag2el), _tag2el_cmp);
	}


	REDIR(OT_STAT_DEFS);

	OUT("#include <constr_SET.h>\n");
	OUT("\n");

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	p = MKID(expr->Identifier);
	OUT("static asn1_SET_element_t asn1_DEF_%s_elements[] = {\n", p);

	elements = 0;
	INDENTED(TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type != A1TC_EXTENSIBLE) {
			if(comp_mode == 1)
				v->marker = EM_OPTIONAL;
			elements++;
		} else {
			if(comp_mode < 3) comp_mode++;
			continue;
		}
	OUT("{ ");
		p = MKID(expr->Identifier);
		OUT("offsetof(struct %s, ", p);
		p = MKID(v->Identifier);
		OUT("%s), ", p);
		if(v->marker) {
			OUT("1, /* Optional element */\n");
		} else {
			OUT("0,\n");
		}
		INDENT(+1);
		if(C99_MODE) OUT(".tag = ");
		_print_tag(arg, v, NULL);
		OUT(",\n");
		if(C99_MODE) OUT(".tag_mode = ");
		if(v->tag.tag_class) {
			if(v->tag.tag_mode == TM_IMPLICIT)
			OUT("-1,\t/* IMPLICIT tag at current level */\n");
			else
			OUT("+1,\t/* EXPLICIT tag at current level */\n");
		} else {
			OUT("0,\n");
		}
		if(C99_MODE) OUT(".type = ");
		OUT("(void *)&asn1_DEF_%s,\n",
			asn1c_type_name(arg, v, TNF_SAFE));
		if(C99_MODE) OUT(".name = ");
		OUT("\"%s\"\n", v->Identifier);
		OUT("},\n");
		INDENT(-1);
	});
	OUT("};\n");

	p = MKID(expr->Identifier);
	OUT("static ber_tlv_tag_t asn1_DEF_%s_tags[] = {\n", p);
	INDENTED(
		if(expr->tag.tag_class) {
			_print_tag(arg, expr, &expr->tag);
			if(expr->tag.tag_mode != TM_EXPLICIT)
				tags_impl_skip++;
		}
		if(!expr->tag.tag_class
		|| (expr->meta_type == AMT_TYPE
			&& expr->tag.tag_mode == TM_EXPLICIT)) {
			struct asn1p_type_tag_s tag;
			if(expr->tag.tag_class)
				OUT(",\n");
			tag.tag_class = TC_UNIVERSAL;
			tag.tag_mode = TM_IMPLICIT;
			tag.tag_value = expr_type2uclass_value[expr->expr_type];
			_print_tag(arg, expr, &tag);
		}
		OUT("\n");
	);
	OUT("};\n");

	/*
	 * Tags to elements map.
	 */
	p = MKID(expr->Identifier);
	OUT("static asn1_SET_tag2member_t asn1_DEF_%s_tag2el[] = {\n", p);
	if(tag2el_count) {
		int i;
		for(i = 0; i < tag2el_count; i++) {
			OUT("    { ");
			_print_tag(arg, expr, &tag2el[i].el_tag);
			OUT(", ");
			OUT("%d ", tag2el[i].el_no);
			OUT("}, /* %s at %d */\n",
				tag2el[i].from_expr->Identifier,
				tag2el[i].from_expr->_lineno
			);
		}
	}
	OUT("};\n");

	/*
	 * Emit a map of mandatory elements.
	 */
	OUT("static uint8_t asn1_DEF_%s_mmap", p);
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
			OUT("(%d << %d)", v->marker?0:1, 7 - (el % 8));
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

	OUT("static asn1_SET_specifics_t asn1_DEF_%s_specs = {\n", p);
	INDENTED(
		OUT("sizeof(struct %s),\n", p);
		OUT("offsetof(struct %s, _ber_dec_ctx),\n", p);
		OUT("offsetof(struct %s, _presence_map),\n", p);
		OUT("asn1_DEF_%s_elements,\n", p);
		OUT("%d,\t/* Elements count */\n", elements);
		OUT("asn1_DEF_%s_tag2el,\n", p);
		OUT("%d,\t/* Count of tags in the map */\n", tag2el_count);
		OUT("%d,\t/* Whether extensible */\n", extensible);
		OUT("(unsigned int *)asn1_DEF_%s_mmap\t/* Mandatory elements map */\n", p);
	);
	OUT("};\n");
	OUT("asn1_TYPE_descriptor_t asn1_DEF_%s = {\n", p);
	INDENTED(
		OUT("\"%s\",\n", expr->Identifier);
		OUT("SET_constraint,\n");
		OUT("SET_decode_ber,\n");
		OUT("SET_encode_der,\n");
		OUT("SET_print,\n");
		OUT("SET_free,\n");
		OUT("0,\t/* Use generic outmost tag fetcher */\n");
		OUT("asn1_DEF_%s_tags,\n", p);
		OUT("sizeof(asn1_DEF_%s_tags)\n", p);
		OUT("\t/sizeof(asn1_DEF_%s_tags[0]),\n", p);
		OUT("%d,\t/* Tags to skip */\n", tags_impl_skip);
		OUT("%d,\t/* Whether CONSTRUCTED */\n", 1);
		OUT("&asn1_DEF_%s_specs\t/* Additional specs */\n", p);
	);
	OUT("};\n");
	OUT("\n");

	REDIR(OT_DEPS);
	OUT("#include <constr_SET.h>\n");
	OUT("\n");
	if(!arg->embed)
	OUT("extern asn1_TYPE_descriptor_t asn1_DEF_%s;\n", p);
	REDIR(OT_TYPE_DECLS);

	return 0;
}

int
asn1c_lang_C_type_SET_OF(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;

	DEPENDENCIES;

	if(arg->embed) {
		OUT("struct %s {\n", MKID(expr->Identifier));
	} else {
		OUT("typedef struct %s {\n",
			MKID(expr->Identifier));
	}

	TQ_FOR(v, &(expr->members), next) {
		INDENTED(OUT("A_SET_OF(%s) list;\n",
			asn1c_type_name(arg, v, TNF_RSAFE)));
	}

	PCTX_DEF;
	OUT("} %s%s", expr->marker?"*":"", MKID(expr->Identifier));
	if(arg->embed) OUT(";\n"); else OUT("_t;\n");

	/*
	 * SET OF/SEQUENCE OF definition, SET OF mode.
	 */
	return asn1c_lang_C_type_SEx_OF_def(arg, 0);
}

static int
asn1c_lang_C_type_SEx_OF_def(arg_t *arg, int seq_of) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int tags_impl_skip = 0;
	char *p;

	REDIR(OT_DEPS);

	if(seq_of) {
		OUT("#include <constr_SEQUENCE_OF.h>\n");
	} else {
		OUT("#include <constr_SET_OF.h>\n");
		OUT("\n");
	}

	REDIR(OT_STAT_DEFS);

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	p = MKID(expr->Identifier);
	OUT("static asn1_SET_OF_element_t asn1_DEF_%s_elements[] = {\n", p);

	INDENTED(OUT("{ ");
		v = TQ_FIRST(&(expr->members));
		INDENT(+1);
		if(C99_MODE) OUT(".tag = ");
		_print_tag(arg, v, NULL);
		OUT(",\n");
		if(C99_MODE) OUT(".type = ");
		OUT("(void *)&asn1_DEF_%s",
			asn1c_type_name(arg, v, TNF_SAFE));
		OUT(" ");
		OUT("},\n");
		INDENT(-1);
	);
	OUT("};\n");

	p = MKID(expr->Identifier);
	OUT("static ber_tlv_tag_t asn1_DEF_%s_tags[] = {\n", p);
	INDENTED(
		if(expr->tag.tag_class) {
			_print_tag(arg, expr, &expr->tag);
			if(expr->tag.tag_mode != TM_EXPLICIT)
				tags_impl_skip++;
		}
		if(!expr->tag.tag_class
		|| (expr->meta_type == AMT_TYPE
			&& expr->tag.tag_mode == TM_EXPLICIT)) {
			struct asn1p_type_tag_s tag;
			if(expr->tag.tag_class)
				OUT(",\n");
			tag.tag_class = TC_UNIVERSAL;
			tag.tag_mode = TM_IMPLICIT;
			tag.tag_value = expr_type2uclass_value[expr->expr_type];
			_print_tag(arg, expr, &tag);
		}
		OUT("\n");
	);
	OUT("};\n");

	OUT("static asn1_SET_OF_specifics_t asn1_DEF_%s_specs = {\n", p);
	INDENTED(
		OUT("sizeof(struct %s),\n", p);
		OUT("offsetof(struct %s, _ber_dec_ctx),\n", p);
		OUT("asn1_DEF_%s_elements\n", p);
	);
	OUT("};\n");
	OUT("asn1_TYPE_descriptor_t asn1_DEF_%s = {\n", p);
	INDENTED(
		OUT("\"%s\",\n", expr->Identifier);
		if(seq_of) {
			OUT("SEQUENCE_OF_constraint,\n");
			OUT("SEQUENCE_OF_decode_ber,\n");
			OUT("SEQUENCE_OF_encode_der,\n");
			OUT("SEQUENCE_OF_print,\n");
			OUT("SEQUENCE_OF_free,\n");
		} else {
			OUT("SET_OF_constraint,\n");
			OUT("SET_OF_decode_ber,\n");
			OUT("SET_OF_encode_der,\n");
			OUT("SET_OF_print,\n");
			OUT("SET_OF_free,\n");
		}
		OUT("0,\t/* Use generic outmost tag fetcher */\n");
		OUT("asn1_DEF_%s_tags,\n", p);
		OUT("sizeof(asn1_DEF_%s_tags)\n", p);
		OUT("\t/sizeof(asn1_DEF_%s_tags[0]),\n", p);
		OUT("%d,\t/* Tags to skip */\n", tags_impl_skip);
		OUT("%d,\t/* Whether CONSTRUCTED */\n", 1);
		OUT("&asn1_DEF_%s_specs\t/* Additional specs */\n", p);
	);
	OUT("};\n");
	OUT("\n");

	REDIR(OT_DEPS);
	if(!arg->embed)
	OUT("extern asn1_TYPE_descriptor_t asn1_DEF_%s;\n", p);
	REDIR(OT_TYPE_DECLS);

	return 0;
}

int
asn1c_lang_C_type_CHOICE(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	char *p;

	DEPENDENCIES;

	p = MKID(expr->Identifier);

	if(arg->embed) {
		OUT("struct %s {\n", p);
	} else {
		OUT("typedef struct %s {\n", p);
	}

	INDENTED(
		OUT("enum {\n");
		INDENTED(
			OUT("%s_PR_NOTHING,\t"
				"/* No components present */\n", p);
			TQ_FOR(v, &(expr->members), next) {
				if(v->expr_type == A1TC_EXTENSIBLE) continue;
				p = MKID(expr->Identifier);
				OUT("%s_PR_", p);
				p = MKID(v->Identifier);
				OUT("%s,\n", p, p);
			}
		);
		OUT("} present;\n");

		OUT("union {\n", p);
		TQ_FOR(v, &(expr->members), next) {
			EMBED(v);
		}
		if(UNNAMED_UNIONS)	OUT("};\n");
		else			OUT("} choice;\n");
	);

	PCTX_DEF;
	OUT("} %s%s", expr->marker?"*":"", MKID(expr->Identifier));
	if(arg->embed) OUT(";\n"); else OUT("_t;\n");

	return asn1c_lang_C_type_CHOICE_def(arg);
}

static int
asn1c_lang_C_type_CHOICE_def(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int elements;	/* Number of elements */
	int tags_impl_skip = 0;
	int comp_mode = 0;	/* {root,ext=1,root,root,...} */
	int extensible = 0;
	tag2el_t *tag2el = NULL;
	int tag2el_count = 0;
	char *p;

	/*
	 * Fetch every inner tag from the tag to elements map.
	 */
	if(_fill_tag2el_map(arg, &tag2el, &tag2el_count, -1)) {
		if(tag2el) free(tag2el);
		return -1;
	} else {
		/*
		 * Sort the map according to canonical order of their tags.
		 */
		_ctc_arg = arg;
		qsort(tag2el, tag2el_count, sizeof(*tag2el), _tag2el_cmp);
	}

	REDIR(OT_STAT_DEFS);

	OUT("#include <constr_CHOICE.h>\n");
	OUT("\n");

	/*
	 * Print out the table according to which the parsing is performed.
	 */
	p = MKID(expr->Identifier);
	OUT("static asn1_CHOICE_element_t asn1_DEF_%s_elements[] = {\n", p);

	elements = 0;
	INDENTED(TQ_FOR(v, &(expr->members), next) {
		if(v->expr_type != A1TC_EXTENSIBLE) {
			if(comp_mode == 1)
				v->marker = EM_OPTIONAL;
			elements++;
		} else {
			if(comp_mode < 3) comp_mode++;
			continue;
		}
	OUT("{ ");
		p = MKID(expr->Identifier);
		OUT("offsetof(struct %s, ", p);
		p = MKID(v->Identifier);
		if(!UNNAMED_UNIONS) OUT("choice.");
		OUT("%s), ", p);
		if(v->marker) {
			OUT("1, /* Optional element */\n");
		} else {
			OUT("0,\n");
		}
		INDENT(+1);
		if(C99_MODE) OUT(".tag = ");
		_print_tag(arg, v, NULL);
		OUT(",\n");
		if(C99_MODE) OUT(".tag_mode = ");
		if(v->tag.tag_class) {
			if(v->tag.tag_mode == TM_IMPLICIT)
			OUT("-1,\t/* IMPLICIT tag at current level */\n");
			else
			OUT("+1,\t/* EXPLICIT tag at current level */\n");
		} else {
			OUT("0,\n");
		}
		if(C99_MODE) OUT(".type = ");
		OUT("(void *)&asn1_DEF_%s,\n",
			asn1c_type_name(arg, v, TNF_SAFE));
		if(C99_MODE) OUT(".name = ");
		OUT("\"%s\"\n", v->Identifier);
		OUT("},\n");
		INDENT(-1);
	});
	OUT("};\n");

	p = MKID(expr->Identifier);
	OUT("static ber_tlv_tag_t asn1_DEF_%s_tags[] = {\n", p);
	if(arg->embed) {
		/*
		 * Our parent structure has already taken this into account.
		 */
	} else {
	  INDENTED(
		if(expr->tag.tag_class) {
			_print_tag(arg, expr, &expr->tag);
			if(expr->tag.tag_mode != TM_EXPLICIT)
				tags_impl_skip++;
		}
		OUT("\n");
	  );
	}
	OUT("};\n");

	/*
	 * Tags to elements map.
	 */
	p = MKID(expr->Identifier);
	OUT("static asn1_CHOICE_tag2member_t asn1_DEF_%s_tag2el[] = {\n", p);
	if(tag2el_count) {
		int i;
		for(i = 0; i < tag2el_count; i++) {
			OUT("    { ");
			_print_tag(arg, expr, &tag2el[i].el_tag);
			OUT(", ");
			OUT("%d ", tag2el[i].el_no);
			OUT("}, /* %s at %d */\n",
				tag2el[i].from_expr->Identifier,
				tag2el[i].from_expr->_lineno
			);
		}
	}
	OUT("};\n");

	OUT("static asn1_CHOICE_specifics_t asn1_DEF_%s_specs = {\n", p);
	INDENTED(
		OUT("sizeof(struct %s),\n", p);
		OUT("offsetof(struct %s, _ber_dec_ctx),\n", p);
		OUT("offsetof(struct %s, present),\n", p);
		OUT("sizeof(((struct %s *)0)->present),\n", p);
		OUT("asn1_DEF_%s_elements,\n", p);
		OUT("%d,\t/* Elements count */\n", elements);
		OUT("asn1_DEF_%s_tag2el,\n", p);
		OUT("%d,\t/* Count of tags in the map */\n", tag2el_count);
		OUT("%d\t/* Whether extensible */\n", extensible);
	);
	OUT("};\n");
	OUT("asn1_TYPE_descriptor_t asn1_DEF_%s = {\n", p);
	INDENTED(
		OUT("\"%s\",\n", expr->Identifier);
		OUT("CHOICE_constraint,\n");
		OUT("CHOICE_decode_ber,\n");
		OUT("CHOICE_encode_der,\n");
		OUT("CHOICE_print,\n");
		OUT("CHOICE_free,\n");
		OUT("CHOICE_outmost_tag,\n");
		OUT("asn1_DEF_%s_tags,\n", p);
		OUT("sizeof(asn1_DEF_%s_tags)\n", p);
		OUT("\t/sizeof(asn1_DEF_%s_tags[0]),\n", p);
		OUT("%d,\t/* Tags to skip */\n", tags_impl_skip);
		OUT("%d,\t/* Whether CONSTRUCTED */\n", 1);
		OUT("&asn1_DEF_%s_specs\t/* Additional specs */\n", p);
	);
	OUT("};\n");
	OUT("\n");

	REDIR(OT_DEPS);
	if(!arg->embed)
	OUT("extern asn1_TYPE_descriptor_t asn1_DEF_%s;\n", p);
	REDIR(OT_TYPE_DECLS);

	return 0;
}

int
asn1c_lang_C_type_REFERENCE(arg_t *arg) {
	asn1p_ref_t *ref;

	ref = arg->expr->reference;
	if(ref->components[ref->comp_count-1].name[0] == '&') {
		asn1p_module_t *mod;
		asn1p_expr_t *extract;
		arg_t tmp;
		int ret;

		extract = asn1f_class_access_ex(arg->asn, arg->mod, arg->expr,
			ref, &mod);
		if(extract == NULL)
			return -1;

		extract = asn1p_expr_clone(extract);
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
		tmp.mod = mod;
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
	int tags_impl_skip = 0;
	char *p;

	if(arg->embed) {
		REDIR(OT_TYPE_DECLS);

		OUT("%s\t", asn1c_type_name(arg, arg->expr,
			expr->marker?TNF_RSAFE:TNF_CTYPE));
		OUT("%s", expr->marker?"*":" ");
		OUT("%s;", MKID(expr->Identifier));
		if(expr->marker) OUT("\t/* %s */",
			(expr->marker==EM_OPTIONAL)?"OPTIONAL":"DEFAULT");
		OUT("\n");
		return 0;
	}

	REDIR(OT_DEPS);

	OUT("#include <%s.h>\n", asn1c_type_name(arg, expr, TNF_INCLUDE));

	REDIR(OT_TYPE_DECLS);

	OUT("typedef %s\t", asn1c_type_name(arg, arg->expr, TNF_CTYPE));
	OUT("%s", expr->marker?"*":" ");
	OUT("%s_t;\n", MKID(expr->Identifier));
	OUT("\n");

	REDIR(OT_STAT_DEFS);

	p = MKID(expr->Identifier);
	OUT("static ber_tlv_tag_t asn1_DEF_%s_tags[] = {\n", p);
	INDENTED(
		if(expr->tag.tag_class) {
			_print_tag(arg, expr, &expr->tag);
			if(expr->tag.tag_mode != TM_EXPLICIT)
				tags_impl_skip++;
		}
		if(!expr->tag.tag_class
		|| (expr->meta_type == AMT_TYPE
			&& expr->tag.tag_mode == TM_EXPLICIT)) {
			struct asn1p_type_tag_s tag;
			if(expr->tag.tag_class)
				OUT(",\n");
			tag.tag_class = TC_UNIVERSAL;
			tag.tag_mode = TM_IMPLICIT;
			tag.tag_value = expr_type2uclass_value[expr->expr_type];
			_print_tag(arg, expr, &tag);
		}
		OUT("\n");
	);
	OUT("};\n");

	OUT("asn1_TYPE_descriptor_t asn1_DEF_%s = {\n", p);
	INDENTED(
		OUT("\"%s\",\n", expr->Identifier);
		OUT("%s_constraint,\n", p);
		OUT("%s_decode_ber,\n", p);
		OUT("%s_encode_der,\n", p);
		OUT("%s_print,\n", p);
		OUT("%s_free,\n", p);
		OUT("0,\t/* Use generic outmost tag fetcher */\n");
		OUT("asn1_DEF_%s_tags,\n", p);
		OUT("sizeof(asn1_DEF_%s_tags)\n", p);
		OUT("\t/sizeof(asn1_DEF_%s_tags[0]),\n", p);
		OUT("%d,\t/* Tags to skip */\n", tags_impl_skip);
		OUT("-0\t/* Unknown yet */\n");
	);
	OUT("};\n");
	OUT("\n");

	/*
	 * Constraint checking.
	 */
	if(expr->constraints)	/* Emit tables with FROM() constraints */
		emit_alphabet_tables(arg, expr->constraints, 0);
	p = MKID(expr->Identifier);
	OUT("int\n");
	OUT("%s_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,\n", p);
	INDENTED(
	OUT("\t\tasn_app_consume_bytes_f *app_errlog, void *app_key) {\n");
	OUT("\n");
	if(expr->constraints) {

		emit_constraint_checking_code(arg);

		OUT("/* Check the constraints of the underlying type */\n");
		OUT("return asn1_DEF_%s.check_constraints\n",
			asn1c_type_name(arg, expr, TNF_SAFE));
		OUT("\t(td, sptr, app_errlog, app_key);\n");
	} else {
		OUT("/* Make the underlying type checker permanent */\n");
		OUT("td->check_constraints = asn1_DEF_%s.check_constraints;\n",
			asn1c_type_name(arg, expr, TNF_SAFE));
		OUT("return td->check_constraints\n");
		OUT("\t(td, sptr, app_errlog, app_key);\n");
	}
	);
	OUT("}\n");
	OUT("\n");

	/*
	 * Emit suicidal functions.
	 */

	{
	/*
	 * This function replaces certain fields from the definition
	 * of a type with the corresponding fields from the basic type
	 * (from which the current type is inherited).
	 */
	char *type_name = asn1c_type_name(arg, expr, TNF_SAFE);
	OUT("/*\n");
	OUT(" * This type is implemented using %s,\n", type_name);
	OUT(" * so adjust the DEF appropriately.\n");
	OUT(" */\n");
	OUT("static void\n");
	OUT("inherit_TYPE_descriptor(asn1_TYPE_descriptor_t *td) {\n");
	INDENT(+1);
	OUT("td->ber_decoder = asn1_DEF_%s.ber_decoder;\n", type_name);
	OUT("td->der_encoder = asn1_DEF_%s.der_encoder;\n", type_name);
	OUT("td->free_struct = asn1_DEF_%s.free_struct;\n", type_name);
	OUT("td->print_struct = asn1_DEF_%s.print_struct;\n", type_name);
	OUT("td->last_tag_form = asn1_DEF_%s.last_tag_form;\n", type_name);
	OUT("td->specifics = asn1_DEF_%s.specifics;\n", type_name);
	INDENT(-1);
	OUT("}\n");
	OUT("\n");
	}

	p = MKID(expr->Identifier);
	OUT("ber_dec_rval_t\n");
	OUT("%s_decode_ber(asn1_TYPE_descriptor_t *td,\n", p);
	INDENTED(
	OUT("\tvoid **structure, void *bufptr, size_t size, int tag_mode) {\n");
	OUT("inherit_TYPE_descriptor(td);\n");
	OUT("return td->ber_decoder(td, structure,\n");
	OUT("\tbufptr, size, tag_mode);\n");
	);
	OUT("}\n");
	OUT("\n");

	p = MKID(expr->Identifier);
	OUT("der_enc_rval_t\n");
	OUT("%s_encode_der(asn1_TYPE_descriptor_t *td,\n", p);
	INDENTED(
	OUT("\tvoid *structure, int tag_mode, ber_tlv_tag_t tag,\n");
	OUT("\tasn_app_consume_bytes_f *cb, void *app_key) {\n");
	OUT("inherit_TYPE_descriptor(td);\n");
	OUT("return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);\n");
	);
	OUT("}\n");
	OUT("\n");

	p = MKID(expr->Identifier);
	OUT("int\n");
	OUT("%s_print(asn1_TYPE_descriptor_t *td, const void *struct_ptr,\n", p);
	INDENTED(
	OUT("\tint ilevel, asn_app_consume_bytes_f *cb, void *app_key) {\n");
	OUT("inherit_TYPE_descriptor(td);\n");
	OUT("return td->print_struct(td, struct_ptr, ilevel, cb, app_key);\n");
	);
	OUT("}\n");
	OUT("\n");

	p = MKID(expr->Identifier);
	OUT("void\n");
	OUT("%s_free(asn1_TYPE_descriptor_t *td,\n", p);
	INDENTED(
	OUT("\tvoid *struct_ptr, int contents_only) {\n");
	OUT("inherit_TYPE_descriptor(td);\n");
	OUT("td->free_struct(td, struct_ptr, contents_only);\n");
	);
	OUT("}\n");
	OUT("\n");

	REDIR(OT_FUNC_DECLS);

	p = MKID(expr->Identifier);
	OUT("extern asn1_TYPE_descriptor_t asn1_DEF_%s;\n", p);
	OUT("asn_constr_check_f %s_constraint;\n", p);
	OUT("ber_type_decoder_f %s_decode_ber;\n", p);
	OUT("der_type_encoder_f %s_encode_der;\n", p);
	OUT("asn_struct_print_f %s_print;\n", p);
	OUT("asn_struct_free_f %s_free;\n", p);

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
_print_tag(arg_t *arg, asn1p_expr_t *expr, struct asn1p_type_tag_s *tag_p) {
	struct asn1p_type_tag_s tag;

	if(tag_p) {
		tag = *tag_p;
	} else {
		if(asn1f_fetch_tag(arg->asn, arg->mod, expr, &tag)) {
			OUT("-1 /* Ambiguous tag (CHOICE?) */");
			return 0;
		}
	}

	OUT("(");
	switch(tag.tag_class) {
	case TC_UNIVERSAL:		OUT("ASN_TAG_CLASS_UNIVERSAL"); break;
	case TC_APPLICATION:		OUT("ASN_TAG_CLASS_APPLICATION"); break;
	case TC_CONTEXT_SPECIFIC:	OUT("ASN_TAG_CLASS_CONTEXT"); break;
	case TC_PRIVATE:		OUT("ASN_TAG_CLASS_PRIVATE"); break;
	case TC_NOCLASS:
		break;
	}
	OUT(" | (%lld << 2))", tag.tag_value);

	return 0;
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

	return 0;
}

static int
_add_tag2el_member(arg_t *arg, tag2el_t **tag2el, int *count, int el_no) {
	struct asn1p_type_tag_s tag;
	int ret;

	assert(el_no >= 0);

	ret = asn1f_fetch_tag(arg->asn, arg->mod, arg->expr, &tag);
	if(ret == 0) {
		void *p;
		p = realloc(*tag2el, sizeof(tag2el_t) * ((*count) + 1));
		if(p)	*tag2el = p;
		else	return -1;

		DEBUG("Found tag for %s: %ld",
			arg->expr->Identifier,
			(long)tag.tag_value);

		(*tag2el)[*count].el_tag = tag;
		(*tag2el)[*count].el_no = el_no;
		(*tag2el)[*count].from_expr = arg->expr;
		(*count)++;
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
		expr = asn1f_lookup_symbol_ex(tmp.asn, &tmp.mod, tmp.expr,
			arg->expr->reference);
		if(expr) {
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
emit_constraint_checking_code(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_type_e etype;
	int size_present, value_present;

	if(expr->constraints == NULL)
		return 0;	/* No constraints defined */

	etype = _find_terminal_type(arg);

	size_present = check_constraint_type_presence(expr->constraints,
		ACT_CT_SIZE);
	value_present = check_constraint_type_presence(expr->constraints,
		ACT_EL_VALUE);

	if(size_present || value_present) {
		OUT("%s_t *st = sptr;\n", MKID(arg->expr->Identifier));
		if(size_present) {
			OUT("size_t size;\n");
			OUT("size_t min_size __attribute__ ((unused)) = %ld;\n",
				compute_min_size(arg));
			OUT("size_t max_size __attribute__ ((unused)) = %ld;\n",
				compute_max_size(arg));
		}
		if(value_present)
		switch(etype) {
		case ASN_BASIC_INTEGER:
		case ASN_BASIC_ENUMERATED:
			OUT("long value;\n");
			break;
		case ASN_BASIC_BOOLEAN:
			OUT("int value;\n");
			break;
		default:
			break;
		}
		OUT("\n");
	}

	OUT("if(!sptr) {\n");
	INDENT(+1);
		OUT("_ASN_ERRLOG(\"%%s: value not given\", td->name);\n");
		OUT("return -1;\n");
	INDENT(-1);
	OUT("}\n");
	OUT("\n");

	if(size_present)
		emit_size_determination_code(arg);
	if(value_present)
		emit_value_determination_code(arg);

	OUT("\n");
	OUT("if(\n");
	emit_single_constraint_check(arg, expr->constraints, 0);
	OUT(") {\n");
	INDENTED(OUT("/* Constraint check succeeded */\n"));
	OUT("} else {\n");
	INDENT(+1);
		OUT("_ASN_ERRLOG(\"%%s: constraint failed\", td->name);\n");
		OUT("return -1;\n");
	INDENT(-1);
	OUT("}\n");

	return 0;
}

static int
emit_single_constraint_check(arg_t *arg, asn1p_constraint_t *ct, int mode) {
	char *s_v;
	int el;

	assert(arg && ct);

	switch(ct->type) {
	case ACT_INVALID:
		assert(ct->type != ACT_INVALID);
		OUT("-1 /* Invalid constraint at line %d */\n", ct->_lineno);
		break;
	case ACT_EL_VALUE:
		OUT("(");
		if(mode == ACT_CT_SIZE)	s_v = "size";
		else			s_v = "value";
		OUT("%s", s_v);
		if(ct->value->type != ATV_TRUE)
			OUT(" == ");
		switch(ct->value->type) {
		case ATV_INTEGER: OUT("%lld",
			(long long)ct->value->value.v_integer); break;
		case ATV_MIN:	OUT("min_%s", s_v);	break;
		case ATV_MAX:	OUT("max_%s", s_v);	break;
		case ATV_FALSE:	OUT("0");	break;
		case ATV_TRUE:			break;
		default:
			break;
		}
		OUT(")\n");
		break;
	case ACT_EL_RANGE:
	case ACT_EL_LLRANGE:
	case ACT_EL_RLRANGE:
	case ACT_EL_ULRANGE:
		if(mode == ACT_CT_SIZE) {
			s_v = "size";
		} else {
			s_v = "value";
		}
		OUT("((%s", s_v);
		switch(ct->type) {
		case ACT_EL_RANGE:
		case ACT_EL_RLRANGE:
			OUT(" >= ");	break;
		case ACT_EL_LLRANGE:
		case ACT_EL_ULRANGE:
			OUT(" > ");	break;
		default:	break;
		}
		switch(ct->range_start->type) {
		case ATV_INTEGER: OUT("%lld",
			(long long)ct->range_start->value.v_integer); break;
		case ATV_MIN:	OUT("min_%s", s_v);	break;
		case ATV_MAX:	OUT("max_%s", s_v);	break;
		case ATV_FALSE:	OUT("0");	break;
		case ATV_TRUE:			break;
		default:
			break;
		}
		OUT(") && (%s", s_v);
		switch(ct->type) {
		case ACT_EL_RANGE:
		case ACT_EL_LLRANGE:
			OUT(" <= ");	break;
		case ACT_EL_RLRANGE:
		case ACT_EL_ULRANGE:
			OUT(" < ");	break;
		default:	break;
		}
		switch(ct->range_stop->type) {
		case ATV_INTEGER: OUT("%lld",
			(long long)ct->range_stop->value.v_integer); break;
		case ATV_MIN:	OUT("min_%s", s_v);	break;
		case ATV_MAX:	OUT("max_%s", s_v);	break;
		case ATV_FALSE:	OUT("0");	break;
		case ATV_TRUE:			break;
		default:
			break;
		}
		OUT("))\n");
		break;
	case ACT_EL_EXT:
		OUT("0 /* Extensible (...), but not defined herein */\n");
		break;
	case ACT_CT_SIZE:
		if(mode) {
			OUT("0 /* Invalid constraint at line %d */\n",
				ct->_lineno);
			return -1;
		}
		assert(ct->el_count == 1);
		return emit_single_constraint_check(arg,
			ct->elements[0], ACT_CT_SIZE);
	case ACT_CT_FROM:
		if(mode) {
			OUT("0 /* Invalid constraint at line %d */\n",
				ct->_lineno);
			return -1;
		}
		OUT("check_alphabet_%x(sptr)\n", ct);
		break;
	case ACT_CT_WCOMP:
	case ACT_CT_WCOMPS:
		OUT("%d /* Unsupported constraint at line %d */\n",
			ct->type, ct->_lineno);
		return -1;
		break;
	case ACT_CA_SET:
		OUT("(\n");
		INDENT(+1);
		for(el = 0; el < ct->el_count; el++) {
			if(el) OUT("&& ");
			emit_single_constraint_check(arg,
				ct->elements[el], mode);
		}
		INDENT(-1);
		OUT(")\n");
		break;
	case ACT_CA_CSV:
		OUT("(\n");
		INDENT(+1);
		for(el = 0; el < ct->el_count; el++) {
			if(el) OUT("|| ");
			emit_single_constraint_check(arg,
				ct->elements[el], mode);
		}
		INDENT(-1);
		OUT(")\n");
		break;
	case ACT_CA_UNI:
		OUT("(\n");
		INDENT(+1);
		for(el = 0; el < ct->el_count; el++) {
			if(el) OUT("|| ");
			emit_single_constraint_check(arg,
				ct->elements[el], mode);
		}
		INDENT(-1);
		OUT(")\n");
		break;
	case ACT_CA_INT:
		OUT("(\n");
		INDENT(+1);
		for(el = 0; el < ct->el_count; el++) {
			if(el) OUT("&& ");
			emit_single_constraint_check(arg,
				ct->elements[el], mode);
		}
		INDENT(-1);
		OUT(")\n");
		break;
	case ACT_CA_CRC:
		WARNING("Unsupported component relation constraint at line %d",
			ct->_lineno);
		OUT("%d /* Unsupported component relation constraint "
			"at line %d */\n",
			ct->type, ct->_lineno);
		return -1;
	case ACT_CA_EXC:
		WARNING("Unsupported EXCEPT constraint at line %d",
			ct->_lineno);
		OUT("%d /* Unsupported EXCEPT constraint at line %d */\n",
			ct->type, ct->_lineno);
		return -1;
	}

	return 0;
}

static int
check_constraint_type_presence(asn1p_constraint_t *ct, enum asn1p_constraint_type_e type) {
	int el;

	if(ct == NULL) return 0;

	if(ct->type == type) return 1;

	if(type == ACT_EL_VALUE) {
		if(ct->type >= ACT_CT_SIZE
		&& ct->type <= ACT_CT_WCOMPS)
			/* Values defined further
			 * are not really value's values */
			return 0;
		if(ct->type > ACT_EL_VALUE && ct->type < ACT_CT_SIZE)
			return 1;	/* Also values */
	}

	for(el = 0; el < ct->el_count; el++) {
		if(check_constraint_type_presence(ct->elements[el], type))
			return 1;
	}

	return 0;
}

static int
emit_alphabet_tables(arg_t *arg, asn1p_constraint_t *ct, int *table) {
	int ch = 0;
	int ch_start = 0;
	int ch_stop = 0;
	int el = 0;

	assert(arg && ct);

	switch(ct->type) {
	case ACT_INVALID:
		break;
	case ACT_EL_VALUE:
		if(!table) break;

		switch(ct->value->type) {
		case ATV_INTEGER:
			if(ct->value->value.v_integer < 0
			|| ct->value->value.v_integer > 255) {
				OUT("\n");
				OUT("#error Value %lld out of range "
				"for alphabet character at line %d\n",
				(long long)ct->value->value.v_integer,
					ct->_lineno);
				break;
			} else {
				ch = ct->value->value.v_integer;
				table[ch] = 1;
			}
			break;
		case ATV_STRING:
			for(ch = 0; ch < ct->value->value.string.size; ch++)
				table[ct->value->value.string.buf[ch]] = 1;
			break;
		default:
			OUT("\n");
			WARNING("Invalid alphabet character specification "
				"at line %d", ct->_lineno);
			OUT("#error Invalid alphabet character specification "
				"at line %d\n", ct->_lineno);
			break;
		}
		break;
	case ACT_EL_RANGE:
	case ACT_EL_LLRANGE:
	case ACT_EL_RLRANGE:
	case ACT_EL_ULRANGE:
		if(!table) break;

		ch_start = 0;
		ch_stop = 255;

		switch(ct->range_start->type) {
		case ATV_INTEGER:
			ch_start = ct->range_start->value.v_integer; break;
		case ATV_MIN:	ch_start = 0;	break;
		case ATV_MAX:	ch_start = 255;	break;
		case ATV_STRING:
			if(ct->range_start->value.string.size == 1) {
				ch_start = ct->range_start->value.string.buf[0];
				break;
			}
			/* Fall through */
		default:
			OUT("\n");
			FATAL("Invalid alphabet range constraint "
				"at line %d\n", ct->_lineno);
			OUT("#error Invalid alphabet range constraint "
				"at line %d\n", ct->_lineno);
			return -1;
		}

		switch(ct->range_stop->type) {
		case ATV_INTEGER:
			ch_stop = ct->range_stop->value.v_integer; break;
		case ATV_MIN:	ch_stop = 0;	break;
		case ATV_MAX:	ch_stop = 255;	break;
		case ATV_STRING:
			if(ct->range_stop->value.string.size == 1) {
				ch_stop = ct->range_stop->value.string.buf[0];
				break;
			}
			/* Fall through */
		default:
			OUT("\n");
			FATAL("Invalid alphabet range constraint "
				"at line %d\n", ct->_lineno);
			OUT("#error Invalid alphabet range constraint "
				"at line %d\n", ct->_lineno);
			break;
		}

		switch(ct->type) {
		case ACT_EL_RANGE:	break;
		case ACT_EL_RLRANGE:	ch_stop--;	break;
		case ACT_EL_LLRANGE:	ch_start++;	break;
		case ACT_EL_ULRANGE:	ch_start++; ch_stop--; break;
		default:	break;
		}

		if(ch_start > ch_stop) {
			WARNING("Empty character range "
			"alphabet constraint at line %d", ct->_lineno);
			OUT("#warning Empty character range "
			"alphabet constraint at line %d\n", ct->_lineno);
			break;
		}

		for(ch = ch_start; ch <= ch_stop; ch++) {
			if(ch < 0 || ch > 255) continue;
			table[ch] = 1;
		}

		break;
	case ACT_EL_EXT:
		break;
	case ACT_CT_SIZE:
		break;
	case ACT_CT_FROM:
	  if(table) {
			OUT("#error Nested FROM in subtype constraints\n");
			return -1;
	  } else {
			table = alloca(256 * sizeof(table[0]));
			memset(table, 0, 256 * sizeof(table[0]));

			for(el = 0; el < ct->el_count; el++) {
				emit_alphabet_tables(arg, ct->elements[el],
					table);
			}
			OUT("static int alphabet_table_%x[256] = {\n", ct);
			for(ch = 0; ch < 256; ch++) {
				OUT("%d,", table[ch]?1:0);
				if(!((ch+1) % 16)) {
				  if(ch) {
					int c;
					OUT("\t/* ");
					for(c = ch - 16; c < ch; c++) {
						if(table[c]) {
							if(c > 0x20
								&& c < 0x80)
								OUT("%c", c);
							else
								OUT(".", c);
						} else {
							OUT(" ");
						}
					}
					OUT(" */");
				  }
				  OUT("\n");
				}
			}
			OUT("};\n");
			OUT("static int check_alphabet_%x(void *sptr) {\n", ct);
			INDENT(+1);
			OUT("int *table = alphabet_table_%x;\n", ct);
			emit_alphabet_check_cycle(arg);
			OUT("return 1;\n");
			INDENT(-1);
			OUT("};\n");
	  }
		break;
	case ACT_CT_WCOMP:
	case ACT_CT_WCOMPS:
		break;
	case ACT_CA_CRC:
		break;
	case ACT_CA_SET:
	case ACT_CA_CSV:
	case ACT_CA_UNI:
		for(el = 0; el < ct->el_count; el++)
			emit_alphabet_tables(arg, ct->elements[el], table);
		break;
	case ACT_CA_INT:
		if(table) {
			int table2[256];

			assert(ct->el_count >= 1);
			emit_alphabet_tables(arg, ct->elements[0], table);
			for(el = 1; el < ct->el_count; el++) {
				memset(table2, 0, sizeof(table2));
				emit_alphabet_tables(arg,
					ct->elements[el], table2);
				/* Intersection */
				for(ch = 0; ch < 256; ch++) {
					if(table2[ch] == 0)
						table[ch] = 0;
				}
			}
		} else {
			for(el = 0; el < ct->el_count; el++)
				emit_alphabet_tables(arg, ct->elements[el], 0);
		}

		break;
	case ACT_CA_EXC:
		OUT("EXC\n");
		if(table) {
			int table2[256];

			assert(ct->el_count >= 1);
			emit_alphabet_tables(arg, ct->elements[0], table);
			for(el = 1; el < ct->el_count; el++) {
				memset(table2, 0, sizeof(table2));
				emit_alphabet_tables(arg,
					ct->elements[el], table2);
				/* Exclusion */
				for(ch = 0; ch < 256; ch++) {
					if(table2[ch])
						table[ch] = 0;
				}
			}
		} else {
			for(el = 0; el < ct->el_count; el++)
				emit_alphabet_tables(arg, ct->elements[el], 0);
		}
		break;
	}

	return 0;
}

static int
emit_alphabet_check_cycle(arg_t *arg) {
	asn1p_expr_type_e etype;

	etype = _find_terminal_type(arg);
	if(!(etype & ASN_STRING_MASK)
	&& !(etype == ASN_BASIC_OCTET_STRING)) {
		OUT("#error Cannot apply FROM constraint to ASN.1 type %s\n",
			ASN_EXPR_TYPE2STR(etype));
		return -1;
	}

	OUT("/* The underlying type is %s */\n",
		ASN_EXPR_TYPE2STR(etype));
	OUT("%s_t *st = sptr;\n", MKID(arg->expr->Identifier));

	switch(etype) {
	case ASN_STRING_UTF8String:
		OUT("uint8_t *ch = st->buf;\n");
		OUT("uint8_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("for(; ch < end; ch++) {\n");
		INDENT(+1);
		OUT("if(*ch >= 0x80 || !table[*ch]) return 0;\n");
		INDENT(-1);
		OUT("}\n");
		break;
	case ASN_STRING_UniversalString:
		OUT("uint32_t *ch = st->buf;\n");
		OUT("uint32_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("for(; ch < end; ch++) {\n");
		INDENT(+1);
		OUT("uint32_t wc = (((uint8_t *)ch)[0] << 24)\n");
		OUT("\t\t| (((uint8_t *)ch)[1] << 16)\n");
		OUT("\t\t| (((uint8_t *)ch)[2] << 8)\n");
		OUT("\t\t|  ((uint8_t *)ch)[3]\n");
		OUT("if(wc > 255 || !table[wc]) return 0;\n");
		INDENT(-1);
		OUT("}\n");
		OUT("if(ch != end) return 0; /* (size%4)! */\n");
		break;
	case ASN_STRING_BMPString:
		OUT("uint16_t *ch = st->buf;\n");
		OUT("uint16_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("for(; ch < end; ch++) {\n");
		INDENT(+1);
		OUT("uint16_t wc = (((uint8_t *)ch)[0] << 8)\n");
		OUT("\t\t| ((uint8_t *)ch)[1];\n");
		OUT("if(wc > 255 || !table[wc]) return 0;\n");
		INDENT(-1);
		OUT("}\n");
		OUT("if(ch != end) return 0; /* (size%2)! */\n");
		break;
	case ASN_BASIC_OCTET_STRING:
	default:
		OUT("uint8_t *ch = st->buf;\n");
		OUT("uint8_t *end = ch + st->size;\n");
		OUT("\n");
		OUT("for(; ch < end; ch++) {\n");
		INDENT(+1);
		OUT("if(!table[*ch]) return 0;\n");
		INDENT(-1);
		OUT("}\n");
		break;
	}

	return 0;
}

static int
emit_size_determination_code(arg_t *arg) {
	asn1p_expr_type_e etype = _find_terminal_type(arg);

	switch(etype) {
	case ASN_BASIC_BIT_STRING:
		OUT("if(st->size > 0) {\n");
		OUT("\t/* Size in bits */\n");
		OUT("\tsize = (st->size - 1) - (st->buf[0] & 0x7);\n");
		OUT("} else {\n");
		OUT("\tsize = 0;\n");
		OUT("}\n");
		break;
	case ASN_STRING_UniversalString:
		OUT("size = st->size >> 2;\t/* 4 byte per character */\n");
		break;
	case ASN_STRING_BMPString:
		OUT("size = st->size >> 1;\t/* 2 byte per character */\n");
		break;
	case ASN_STRING_UTF8String:
		OUT("size = UTF8String_length(st, td->name, app_errlog, app_key);\n");
		OUT("if(size == (size_t)-1) return -1;\n");
		break;
	default:
		if((etype & ASN_STRING_MASK)
		|| etype == ASN_BASIC_OCTET_STRING) {
			OUT("size = st->size;\n");
			break;
		} else {
			WARNING("Size operation is not defined for %s",
				ASN_EXPR_TYPE2STR(etype));
			OUT("#warning Size operation not defined!\n");
			OUT("size = st->size;\n");
		}
		return -1;
	}

	return 0;
}

static int
emit_value_determination_code(arg_t *arg) {
	asn1p_expr_type_e etype = _find_terminal_type(arg);

	switch(etype) {
	case ASN_BASIC_INTEGER:
	case ASN_BASIC_ENUMERATED:
		OUT("if(asn1_INTEGER2long(st, &value)) {\n");
		INDENT(+1);
		OUT("_ASN_ERRLOG(\"%%s: value too large\", td->name);\n");
		OUT("return -1;\n");
		INDENT(-1);
		OUT("}\n");
		break;
	case ASN_BASIC_BOOLEAN:
		OUT("value = st->value;\n");
		break;
	default:
		WARNING("Value cannot be determined "
			"for constraint check for %s at line %d\n",
			arg->expr->Identifier, arg->expr->_lineno);
		OUT("#error Value cannot be determined for %s at %d\n",
			arg->expr->Identifier, arg->expr->_lineno);
		break;
	}

	return 0;
}

static long compute_min_size(arg_t *arg) { return compute_xxx_size(arg, 0); }
static long compute_max_size(arg_t *arg) { return compute_xxx_size(arg, 1); }

static long compute_xxx_size(arg_t *arg, int _max) {
	asn1p_expr_type_e etype;
	long basic_max = 0x7fffffff;
	long basic_min = 0x80000000;
	long svalue = 0;

	etype = _find_terminal_type(arg);
	switch(etype) {
	case ASN_BASIC_BIT_STRING:
		svalue = _max?basic_max/8:0;
		break;
	case ASN_STRING_UTF8String:
		svalue = _max?basic_max/6:0;
		break;
	case ASN_STRING_UniversalString:
		svalue = _max?basic_max/4:0;
		break;
	case ASN_STRING_BMPString:
		svalue = _max?basic_max/2:0;
		break;
	case ASN_BASIC_OCTET_STRING:
		svalue = _max?basic_max:0;
		break;
	default:
		if((etype & ASN_STRING_MASK)) {
			svalue = _max?basic_max:0;
			break;
		}
		svalue = _max?basic_max:basic_min;
		break;
	}

	return svalue;
}

static asn1p_expr_type_e
_find_terminal_type(arg_t *arg) {
	asn1p_expr_t *expr;
	expr = asn1f_find_terminal_type_ex(arg->asn, arg->mod, arg->expr, NULL);
	assert(expr);
	return expr->expr_type;
}
