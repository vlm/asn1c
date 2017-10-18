/*
 * A collection of data members of unspecified types.
 */
#ifndef	ASN1_PARSER_EXPR_H
#define	ASN1_PARSER_EXPR_H

/*
 * Meta type of the ASN expression.
 */
typedef enum asn1p_expr_meta {
	AMT_INVALID,
	AMT_TYPE,		/* Type1 ::= INTEGER */
	AMT_TYPEREF,		/* Type2 ::= Type1 */
	AMT_VALUE,		/* value1 Type1 ::= 1 */
	AMT_VALUESET,		/* ValueSet Type1 ::= { value1 } */
	AMT_OBJECT,		/* object CLASS ::= {...} */
	AMT_OBJECTCLASS,	/* FUNCTION ::= CLASS {...} */
	AMT_OBJECTFIELD,	/* ... */
	AMT_EXPR_META_MAX
} asn1p_expr_meta_e;

/*
 * ASN type of the expression.
 */
typedef enum asn1p_expr_type {
	/*
	 * Internal types.
	 */
	A1TC_INVALID,		/* Invalid type */
	A1TC_REFERENCE,		/* Reference to the type defined elsewhere */
	A1TC_EXPORTVAR,		/* We're exporting this definition */
	A1TC_UNIVERVAL,		/* A value of an ENUMERATED, INTEGER or BS */
	A1TC_BITVECTOR,		/* A plain collection of bits */
	A1TC_OPAQUE,		/* Opaque data encoded as a bitvector */
	A1TC_EXTENSIBLE,	/* An extension marker "..." */
	A1TC_COMPONENTS_OF,	/* COMPONENTS OF clause */
	A1TC_VALUESET,		/* Value set definition */
	A1TC_CLASSDEF,		/* Information Object Class */
	A1TC_INSTANCE,		/* Instance of Object Class */

	/*
	 * ASN.1 Class field types
	 */
#define	ASN_CLASSFIELD_MASK	0x10	/* Every class field type */
	A1TC_CLASSFIELD_TFS	= ASN_CLASSFIELD_MASK,	/* TypeFieldSpec */
	A1TC_CLASSFIELD_FTVFS,		/* FixedTypeValueFieldSpec */
	A1TC_CLASSFIELD_VTVFS,		/* VariableTypeValueFieldSpec */
	A1TC_CLASSFIELD_FTVSFS,		/* FixedTypeValueSetFieldSpec */
	A1TC_CLASSFIELD_VTVSFS,		/* VariableTypeValueSetFieldSpec */
	A1TC_CLASSFIELD_OFS,		/* ObjectFieldSpec */
	A1TC_CLASSFIELD_OSFS,		/* ObjectSetFieldSpec */

	/*
	 * ASN.1 Constructed types
	 */
#define	ASN_CONSTR_MASK		0x20	/* Every constructed type */
	ASN_CONSTR_SEQUENCE	= ASN_CONSTR_MASK,	/* SEQUENCE */
	ASN_CONSTR_CHOICE,		/* CHOICE */
	ASN_CONSTR_SET,			/* SET */
	ASN_CONSTR_SEQUENCE_OF,		/* SEQUENCE OF */
	ASN_CONSTR_SET_OF,		/* SET OF */
	ASN_CONSTR_OPEN_TYPE,

	/*
	 * ASN.1 Basic types
	 */
#define	ASN_BASIC_MASK		0x40	/* Every basic type */
	ASN_TYPE_ANY		= ASN_BASIC_MASK,	/* ANY (deprecated) */
	ASN_BASIC_BOOLEAN,
	ASN_BASIC_NULL,
	ASN_BASIC_INTEGER,
	ASN_BASIC_REAL,
	ASN_BASIC_ENUMERATED,
	ASN_BASIC_BIT_STRING,
	ASN_BASIC_OCTET_STRING,
	ASN_BASIC_OBJECT_IDENTIFIER,
	ASN_BASIC_RELATIVE_OID,
	ASN_BASIC_EXTERNAL,
	ASN_BASIC_EMBEDDED_PDV,
	ASN_BASIC_CHARACTER_STRING,
	ASN_BASIC_UTCTime,
	ASN_BASIC_GeneralizedTime,

	/*
	 * ASN.1 String types
	 */
#define	ASN_STRING_KM_MASK	0x100	/* Known multiplier */
#define	ASN_STRING_NKM_MASK	0x200	/* Not a known multiplier */
#define	ASN_STRING_MASK		0x300	/* Every restricted string type */
	ASN_STRING_IA5String	= ASN_STRING_KM_MASK,
	ASN_STRING_PrintableString,
	ASN_STRING_VisibleString,
	ASN_STRING_ISO646String,	/* aka VisibleString */
	ASN_STRING_NumericString,
	ASN_STRING_UniversalString,
	ASN_STRING_BMPString,
	ASN_STRING_UTF8String	= ASN_STRING_NKM_MASK,
	ASN_STRING_GeneralString,
	ASN_STRING_GraphicString,
	ASN_STRING_TeletexString,
	ASN_STRING_T61String,
	ASN_STRING_VideotexString,
	ASN_STRING_ObjectDescriptor,
	ASN_EXPR_TYPE_MAX
} asn1p_expr_type_e;

#include "asn1p_expr_str.h"
#include "asn1p_expr2uclass.h"

struct asn1p_module_s;	/* Forward declaration */
struct asn1p_ioc_table_s;	/* Forward declaration */

/*
 * A named collection of types.
 */
typedef struct asn1p_expr_s {

	/*
	 * Human readable name.
	 */
	char *Identifier;

	/*
	 * Meta type of the expression (type, value, value set, etc).
	 */
	asn1p_expr_meta_e meta_type;

	/*
	 * ASN type of the expression.
	 */
	asn1p_expr_type_e expr_type;

	/*
	 * Referenced type, defined elsewhere.
	 * (If expr_type == A1TC_REFERENCE)
	 */
	asn1p_ref_t	*reference;

	/*
	 * Constraints for the type.
	 */
	asn1p_constraint_t *constraints;

	/*
	 * This field is holding the transformed constraints, with all the
	 * parent constraints taken into account.
	 */
	asn1p_constraint_t *combined_constraints;

	/*
	 * Left hand side parameters for parametrized type declaration
	 * Type{Param1, Param2} ::= SEQUENCE { a Param1, b Param2 }
	 */
	asn1p_paramlist_t *lhs_params;
	/*
	 * Right hand type specialization.
	 * Type2 ::= Type{Param1}
	 */
	struct asn1p_expr_s *rhs_pspecs;	/* ->members */
	/*
	 * If lhs_params is defined, this structure represents all possible
	 * specializations of the parent expression.
	 */
	struct {
		struct asn1p_pspec_s {
			struct asn1p_expr_s *rhs_pspecs;
			struct asn1p_expr_s *my_clone;
		} *pspec;
		int pspecs_count;	/* Number of specializations */
	} specializations;
	int spec_index;	/* -1, or 0-based specialization index in the parent */

	/*
	 * The actual value (DefinedValue or inlined value).
	 */
	asn1p_value_t *value;

	/*
	 * The WITH SYNTAX clause.
	 */
	asn1p_wsyntx_t *with_syntax;

	/* Information Object Class table, specific for a class or object set */
    struct asn1p_ioc_table_s *ioc_table;

	/*
	 * A tag.
	 */
	struct asn1p_type_tag_s {
		enum {
			TC_NOCLASS,
			TC_UNIVERSAL,
			TC_APPLICATION,
			TC_CONTEXT_SPECIFIC,
			TC_PRIVATE,
		} tag_class;
		enum {
			TM_DEFAULT,
			TM_IMPLICIT,
			TM_EXPLICIT,
		} tag_mode;
		asn1c_integer_t tag_value;
	} tag;

	struct asn1p_expr_marker_s {
		enum asn1p_expr_marker_e {
		  EM_NOMARK,
		  EM_INDIRECT	= 0x01,	/* 00001 Represent as pointer */
		  EM_OMITABLE	= 0x02,	/* 00010 May be absent in encoding */
		  EM_OPTIONAL	= 0x07,	/* 00111 Optional member */
		  EM_DEFAULT	= 0x0F,	/* 01111 default_value */
		  EM_UNRECURSE	= 0x10,	/* 10000 Use safe naming */
		} flags;
		asn1p_value_t *default_value;	/* For EM_DEFAULT case */
	} marker;
	int unique;	/* UNIQUE */
	int ref_cnt;	/* reference count */

	/*
	 * Whether automatic tagging may be applied for subtypes.
	 */
	int auto_tags_OK;

	/*
	 * Members of the constructed type.
	 */
	TQ_HEAD(struct asn1p_expr_s)	members;

	/*
	 * Next expression in the list.
	 */
	TQ_ENTRY(struct asn1p_expr_s)	next;

	struct asn1p_expr_s *parent_expr;	/* optional */

	struct asn1p_module_s *module;	/* Defined in module */

	/*
	 * Line number where this structure is defined in the original
	 * grammar source.
	 */
	int _lineno;

	/*
	 * Marks are used for various purposes.
	 * Here are some predefined ones.
	 */
	enum {
	  TM_NOMARK	= 0,
	  TM_RECURSION	= (1<<0), /* Used to break recursion */
	  TM_BROKEN	= (1<<1), /* A warning was already issued */
	  TM_PERFROMCT	= (1<<2), /* PER FROM() constraint tables emitted */
	  TM_NAMECLASH	= (1<<3),  /* Name clash found, need to add module name to resolve */
	  TM_NAMEGIVEN  = (1<<4),  /* The expression has already yielded a name */
	  TM_SKIPinUNION  = (1<<5) /* Do not include this identifier in union again due to name duplication,
                                      especially for OPENTYPE. */
	} _mark;

	/*
	 * Some tags used by the compiler.
	 */
	int _anonymous_type;	/* This type is unnamed */
	int _type_unique_index;	/* A per top-level-type unique index */
	int _type_referenced;	/* This type is referenced from another place */

	/*
	 * Opaque data may be attached to this structure,
	 * probably by compiler.
	 */
	void *data;
	void (*data_free)(void *data);
} asn1p_expr_t;


/*
 * Constructor and destructor.
 */
asn1p_expr_t *asn1p_expr_new(int _lineno, struct asn1p_module_s *);
asn1p_expr_t *asn1p_expr_clone(asn1p_expr_t *, int skip_extensions);
asn1p_expr_t *asn1p_expr_clone_with_resolver(asn1p_expr_t *,
	asn1p_expr_t *(*resolver)(asn1p_expr_t *to_resolve, void *resolver_arg),
	void *resolver_arg);
void asn1p_expr_add(asn1p_expr_t *to, asn1p_expr_t *what);
void asn1p_expr_add_many(asn1p_expr_t *to, asn1p_expr_t *from_what);
asn1p_expr_t *asn1p_lookup_child(asn1p_expr_t *tc, const char *name);
int asn1p_expr_compare(const asn1p_expr_t *, const asn1p_expr_t *);
void asn1p_expr_free(asn1p_expr_t *expr);
void asn1p_expr_set_source(asn1p_expr_t *, asn1p_module_t *, int lineno);

asn1p_paramlist_t *asn1p_get_namespace(asn1p_expr_t *);

#define	TAG2STRING_BUFFER_SIZE	64	/* buf should be at least this big */
const char *asn1p_tag2string(const struct asn1p_type_tag_s *tag, char *opt_buf);

#define MODULE_NAME_OF(expr) \
		((!expr) ? "" : \
			(!(expr->_mark & TM_NAMECLASH) ? "" : \
				(!expr->module ? "" : expr->module->ModuleName))), \
		((!expr) ? "" : \
			(!(expr->_mark & TM_NAMECLASH) ? "" : "_"))

#endif	/* ASN1_PARSER_EXPR_H */
