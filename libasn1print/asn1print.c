#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#include <asn1parser.h>
#include <asn1fix_export.h>
#include <asn1fix_crange.h>

#include "asn1print.h"

#define	INDENT(fmt, args...)	do {					\
		int __i = level; while(__i--) putchar(' ');		\
		printf(fmt, ##args);					\
	} while(0)

static int asn1print_module(asn1p_t *asn, asn1p_module_t *mod, enum asn1print_flags flags);
static int asn1print_oid(asn1p_oid_t *oid, enum asn1print_flags flags);
static int asn1print_ref(asn1p_ref_t *ref, enum asn1print_flags flags);
static int asn1print_tag(asn1p_expr_t *tc, enum asn1print_flags flags);
static int asn1print_params(asn1p_paramlist_t *pl,enum asn1print_flags flags);
static int asn1print_with_syntax(asn1p_wsyntx_t *wx, enum asn1print_flags flags);
static int asn1print_constraint(asn1p_constraint_t *, enum asn1print_flags);
static int asn1print_value(asn1p_value_t *val, enum asn1print_flags flags);
static int asn1print_expr(asn1p_t *asn, asn1p_module_t *mod, asn1p_expr_t *tc, enum asn1print_flags flags,
		int level);

/*
 * Print the contents of the parsed ASN tree.
 */
int
asn1print(asn1p_t *asn, enum asn1print_flags flags) {
	asn1p_module_t *mod;

	if(asn == NULL) {
		errno = EINVAL;
		return -1;
	}

	TQ_FOR(mod, &(asn->modules), mod_next) {
		asn1print_module(asn, mod, flags);
	}

	return 0;
}

static int
asn1print_module(asn1p_t *asn, asn1p_module_t *mod, enum asn1print_flags flags) {
	asn1p_expr_t *tc;

	printf("\n%s ", mod->Identifier);
	if(mod->module_oid) {
		asn1print_oid(mod->module_oid, flags);
		printf("\n");
	}

	printf("DEFINITIONS");

	if(mod->module_flags & MSF_TAG_INSTRUCTIONS)
		printf(" TAG INSTRUCTIONS");
	if(mod->module_flags & MSF_XER_INSTRUCTIONS)
		printf(" XER INSTRUCTIONS");
	if(mod->module_flags & MSF_EXPLICIT_TAGS)
		printf(" EXPLICIT TAGS");
	if(mod->module_flags & MSF_IMPLICIT_TAGS)
		printf(" IMPLICIT TAGS");
	if(mod->module_flags & MSF_AUTOMATIC_TAGS)
		printf(" AUTOMATIC TAGS");
	if(mod->module_flags & MSF_EXTENSIBILITY_IMPLIED)
		printf(" EXTENSIBILITY IMPLIED");

	printf(" ::=\n");
	printf("BEGIN\n\n");

	TQ_FOR(tc, &(mod->members), next) {
		asn1print_expr(asn, mod, tc, flags, 0);
		if(flags & APF_DEBUG_CONSTRAINTS)
			printf("\n");
		else
			printf("\n\n");
	}

	printf("END\n");

	return 0;
}

static int
asn1print_oid(asn1p_oid_t *oid, enum asn1print_flags flags) {
	int ac;
	int accum = 0;

	(void)flags;	/* Unused argument */

	printf("{");
	for(ac = 0; ac < oid->arcs_count; ac++) {
		if(accum + strlen(oid->arcs[ac].name?:"") > 50) {
			printf("\n\t");
			accum = 0;
		} else if(ac) printf(" ");

		if(oid->arcs[ac].name) {
			printf("%s(%d)",
				oid->arcs[ac].name,
				(int)oid->arcs[ac].number);
			accum += strlen(oid->arcs[ac].name);
		} else {
			printf("%d",
				(int)oid->arcs[ac].number);
		}
		accum += 4;
	}
	printf(" }");

	return 0;
}

static int
asn1print_ref(asn1p_ref_t *ref, enum asn1print_flags flags) {
	int cc;

	(void)flags;	/* Unused argument */

	for(cc = 0; cc < ref->comp_count; cc++) {
		if(cc) printf(".");
		printf("%s", ref->components[cc].name);
	}

	return 0;
}

static int
asn1print_tag(asn1p_expr_t *tc, enum asn1print_flags flags) {
	struct asn1p_type_tag_s *tag = &tc->tag;

	(void)flags;	/* Unused argument */

	if(tag->tag_class == TC_NOCLASS)
		return 0;

	printf("[");
	switch(tag->tag_class) {
	case TC_NOCLASS:
		assert(tag->tag_class != TC_NOCLASS);
		break;
	case TC_UNIVERSAL:	printf("UNIVERSAL ");	break;
	case TC_PRIVATE:	printf("PRIVATE ");	break;
	case TC_APPLICATION:	printf("APPLICATION ");	break;
	case TC_CONTEXT_SPECIFIC:
		break;
	}
	printf("%lld]", (long long)tag->tag_value);

	switch(tag->tag_mode) {
	case TM_DEFAULT: break;
	case TM_IMPLICIT: printf(" IMPLICIT"); break;
	case TM_EXPLICIT: printf(" EXPLICIT"); break;
	}

	return 0;
}

static int
asn1print_value(asn1p_value_t *val, enum asn1print_flags flags) {

	if(val == NULL)
		return 0;

	switch(val->type) {
	case ATV_NOVALUE:
		break;
	case ATV_REFERENCED:
		return asn1print_ref(val->value.reference, flags);
	case ATV_INTEGER:
		printf("%lld", (long long)val->value.v_integer);
		return 0;
	case ATV_MIN: printf("MIN"); return 0;
	case ATV_MAX: printf("MAX"); return 0;
	case ATV_FALSE: printf("FALSE"); return 0;
	case ATV_TRUE: printf("TRUE"); return 0;
	case ATV_REAL:
		printf("%f", val->value.v_double);
		return 0;
	case ATV_STRING:
		{
			char *p = val->value.string.buf;
			putchar('"');
			if(strchr(p, '"')) {
				/* Mask quotes */
				for(; *p; p++) {
					if(*p == '"')
						putchar(*p);
					putchar(*p);
				}
			} else {
				fputs(p, stdout);
			}
			putchar('"');
		}
		return 0;
	case ATV_UNPARSED:
		fputs(val->value.string.buf, stdout);
		return 0;
	case ATV_BITVECTOR:
		{
			uint8_t *bitvector;
			int bits;
			int i;

			bitvector = val->value.binary_vector.bits;
			bits = val->value.binary_vector.size_in_bits;

			printf("'");
			if(bits%8) {
				for(i = 0; i < bits; i++) {
					uint8_t uc;
					uc = bitvector[i>>3];
					putchar(((uc >> (7-(i%8)))&1)?'1':'0');
				}
				printf("'B");
			} else {
				char hextable[16] = "0123456789ABCDEF";
				for(i = 0; i < (bits>>3); i++) {
					putchar(hextable[bitvector[i] >> 4]);
					putchar(hextable[bitvector[i] & 0x0f]);
				}
				printf("'H");
			}
		}
	}

	assert(val->type || !"Unknown");

	return 0;
}

static int
asn1print_constraint(asn1p_constraint_t *ct, enum asn1print_flags flags) {
	int symno = 0;

	if(ct == 0) return 0;

	if(ct->type == ACT_CA_SET)
		printf("(");

	switch(ct->type) {
	case ACT_EL_VALUE:
		asn1print_value(ct->value, flags);
		break;
	case ACT_EL_RANGE:
	case ACT_EL_LLRANGE:
	case ACT_EL_RLRANGE:
	case ACT_EL_ULRANGE:
		asn1print_value(ct->range_start, flags);
			switch(ct->type) {
			case ACT_EL_RANGE: printf(".."); break;
			case ACT_EL_LLRANGE: printf("<.."); break;
			case ACT_EL_RLRANGE: printf("..<"); break;
			case ACT_EL_ULRANGE: printf("<..<"); break;
			default: printf("?..?"); break;
			}
		asn1print_value(ct->range_stop, flags);
		break;
	case ACT_EL_EXT:
		printf("...");
		break;
	case ACT_CT_SIZE:
	case ACT_CT_FROM:
		switch(ct->type) {
		case ACT_CT_SIZE: printf("SIZE("); break;
		case ACT_CT_FROM: printf("FROM("); break;
		default: printf("??? ("); break;
		}
		assert(ct->el_count != 0);
		assert(ct->el_count == 1);
		asn1print_constraint(ct->elements[0], flags);
		printf(")");
		break;
	case ACT_CT_WCOMP:
	case ACT_CT_WCOMPS:
		printf("???");
		break;
	case ACT_CA_SET: symno++;
	case ACT_CA_CRC: symno++;
	case ACT_CA_CSV: symno++;
	case ACT_CA_UNI: symno++;
	case ACT_CA_INT: symno++;
	case ACT_CA_EXC:
		{
			char *symtable[] = { " EXCEPT ", " ^ ", " | ", ",",
					"", "(" };
			int i;
			for(i = 0; i < ct->el_count; i++) {
				enum asn1print_flags nflags = flags;
				if(i) fputs(symtable[symno], stdout);
				if(ct->type == ACT_CA_CRC) fputs("{", stdout);
				asn1print_constraint(ct->elements[i], nflags);
				if(ct->type == ACT_CA_CRC) fputs("}", stdout);
				if(i+1 < ct->el_count
				&& ct->type == ACT_CA_SET)
					fputs(")", stdout);
			}
		}
		break;
	case ACT_INVALID:
		assert(ct->type != ACT_INVALID);
		break;
	}

	if(ct->type == ACT_CA_SET)
		printf(")");

	return 0;
}

static int
asn1print_params(asn1p_paramlist_t *pl, enum asn1print_flags flags) {
	if(pl) {
		int i;
		printf("{");
		for(i = 0; i < pl->params_count; i++) {
			if(i) printf(", ");
			if(pl->params[i].governor) {
				asn1print_ref(pl->params[i].governor, flags);
				printf(":");
			}
			printf("%s", pl->params[i].argument);
		}
		printf("}");
	}

	return 0;
}

static int
asn1print_with_syntax(asn1p_wsyntx_t *wx, enum asn1print_flags flags) {
	if(wx) {
		asn1p_wsyntx_chunk_t *wc;
		printf(" WITH SYNTAX {");
		TQ_FOR(wc, &(wx->chunks), next) {
			if(wc->ref) {
				asn1print_ref(wc->ref, flags);
			} else {
				fwrite(wc->buf, 1, wc->len, stdout);
			}
		}
		printf("}\n");
	}

	return 0;
}

static int
asn1print_crange_value(asn1cnst_edge_t *edge, int as_char) {
	switch(edge->type) {
	case ARE_MIN: printf("MIN"); break;
	case ARE_MAX: printf("MAX"); break;
	case ARE_VALUE:
		if(as_char) {
			printf("\"%c\"", (unsigned char)edge->value);
		} else {
			printf("%lld", (long long)edge->value);
		}
	}
	return 0;
}

static int
asn1print_constraint_explain_type(asn1p_expr_type_e expr_type, asn1p_constraint_t *ct, enum asn1p_constraint_type_e type) {
	asn1cnst_range_t *range;
	int as_char = (type==ACT_CT_FROM);
	int i;

	range = asn1constraint_compute_PER_range(expr_type, ct, type, 0, 0);
	if(!range) return -1;

	switch(type) {
	case ACT_CT_FROM: printf("(FROM("); break;
	case ACT_CT_SIZE: printf("(SIZE("); break;
	default: printf("("); break;
	}
	for(i = -1; i < range->el_count; i++) {
		asn1cnst_range_t *r;
		if(i == -1) {
			if(range->el_count) continue;
			r = range;
		} else {
			r = range->elements[i];
		}
		if(i > 0) {
			printf(" | ");
		}
		asn1print_crange_value(&r->left, as_char);
		if(r->left.type != r->right.type
		|| r->left.value != r->right.value) {
			printf("..");
			asn1print_crange_value(&r->right, as_char);
		}
	}
	if(range->extensible)
		printf(",...");
	printf(type==ACT_EL_RANGE?")":"))");

	if(range->empty_constraint)
		printf(":Empty!");

	asn1constraint_range_free(range);
	return 0;
}

static int
asn1print_constraint_explain(asn1p_expr_type_e expr_type,
		asn1p_constraint_t *ct) {

	asn1print_constraint_explain_type(expr_type, ct, ACT_EL_RANGE);
	printf(" ");
	asn1print_constraint_explain_type(expr_type, ct, ACT_CT_SIZE);
	printf(" ");
	asn1print_constraint_explain_type(expr_type, ct, ACT_CT_FROM);

	return 0;
}

static int
asn1print_expr(asn1p_t *asn, asn1p_module_t *mod, asn1p_expr_t *tc, enum asn1print_flags flags, int level) {
	int SEQ_OF = 0;

	if(flags & APF_LINE_COMMENTS)
	INDENT("-- #line %d\n", tc->_lineno);
	if(tc->Identifier)
		INDENT("%s", tc->Identifier);

	if(tc->params) {
		asn1print_params(tc->params, flags);
	}

	if(tc->meta_type != AMT_VALUE
	&& tc->expr_type != A1TC_EXTENSIBLE) {
		if(level) {
			if(tc->Identifier)
				printf("\t");
		} else {
			printf(" ::=");
		}
	}

	if(tc->tag.tag_class) {
		printf(" ");
		asn1print_tag(tc, flags);
	}

	switch(tc->expr_type) {
	case A1TC_EXTENSIBLE:
		if(tc->value) {
			printf("!");
			asn1print_value(tc->value, flags);
		}
		break;
	case A1TC_COMPONENTS_OF:
		SEQ_OF = 1; /* Equivalent to SET OF for printint purposes */
		printf("    COMPONENTS OF");
		break;
	case A1TC_REFERENCE:
	case A1TC_UNIVERVAL:
	case A1TC_PARAMETRIZED:
		break;
	case A1TC_CLASSDEF:
		printf(" CLASS");
		break;
	case A1TC_CLASSFIELD:
		/* Nothing to print here */
		break;
	case ASN_CONSTR_SET_OF:
	case ASN_CONSTR_SEQUENCE_OF:
		SEQ_OF = 1;
		if(tc->expr_type == ASN_CONSTR_SET_OF)
			printf(" SET");
		else
			printf(" SEQUENCE");
		if(tc->constraints) {
			printf(" ");
			asn1print_constraint(tc->constraints, flags);
		}
		printf(" OF");
		break;
	default:
		{
			char *p = ASN_EXPR_TYPE2STR(tc->expr_type);
			printf(" %s", p?p:"<unknown type!>");
		}
		break;
	}

	if(tc->reference) {
		printf(" ");
		asn1print_ref(tc->reference, flags);
	}

	/*
	 * Display the descendants (children) of the current type.
	 */
	if(TQ_FIRST(&(tc->members))) {
		asn1p_expr_t *se;	/* SubExpression */
		int put_braces = !SEQ_OF; /* Don't need 'em, if SET OF... */

		if(put_braces) printf(" {\n");

		TQ_FOR(se, &(tc->members), next) {
			/*
			 * Print the expression as it were a stand-alone type.
			 */
			asn1print_expr(asn, mod, se, flags, level + 4);
			switch(se->marker) {
			case EM_NOMARK: break;
			case EM_OPTIONAL: printf(" OPTIONAL"); break;
			case EM_DEFAULT: printf(" DEFAULT <?>"); break;
			}
			if(TQ_NEXT(se, next)) {
				printf(",");
				INDENT("\n");
			}
		}

		if(put_braces) {
			printf("\n");
			INDENT("}");
		}
	}

	if(tc->with_syntax)
		asn1print_with_syntax(tc->with_syntax, flags);

	if(!SEQ_OF && tc->constraints) {
		printf(" ");
		asn1print_constraint(tc->constraints, flags);
	}

	if(tc->unique) {
		printf(" UNIQUE");
	}

	if(tc->meta_type == AMT_VALUE
	&& tc->expr_type != A1TC_EXTENSIBLE) {
		if(tc->expr_type == A1TC_UNIVERVAL)
			printf("(");
		else
			printf(" ::= ");
		asn1print_value(tc->value, flags);
		if(tc->expr_type == A1TC_UNIVERVAL)
			printf(")");
	}

	/*
	 * The following section exists entirely for debugging only.
	 */
	if(flags & APF_DEBUG_CONSTRAINTS
	&& tc->expr_type != A1TC_EXTENSIBLE) {
		asn1p_expr_t *top_parent;

		if(tc->combined_constraints) {
			printf("\n-- Combined constraints: ");
			asn1print_constraint(tc->combined_constraints, flags);
		}

		top_parent = asn1f_find_terminal_type_ex(asn, mod, tc);
		if(top_parent) {
			printf("\n-- PER-visible constraints (%s): ",
				top_parent->Identifier);
			asn1print_constraint_explain(top_parent->expr_type,
				tc->combined_constraints);
		}
		printf("\n");
	}

	return 0;
}

