/*
 * Type constraints.
 */
#ifndef	ASN1_PARSER_CONSTRAINT_H
#define	ASN1_PARSER_CONSTRAINT_H

typedef struct asn1p_constraint_s {

	enum asn1p_constraint_type_e {
		ACT_INVALID,		/* for assertions */
		/*
		 * Constraint elements.
		 */
		ACT_EL_TYPE,		/* T (contained subtype) */
		ACT_EL_VALUE,		/* 123, "A", (elementary value) */
		ACT_EL_RANGE,		/* 1..2 (elementary range) */
		ACT_EL_LLRANGE,		/* 1<..2 (elementary range) */
		ACT_EL_RLRANGE,		/* 1..<2 (elementary range) */
		ACT_EL_ULRANGE,		/* 1<..<2 (elementary range) */
		ACT_EL_EXT,		/* ... (extensibility mark) */
		/*
		 * Constraint types.
		 */
		ACT_CT_SIZE,		/* SIZE constraint type */
		ACT_CT_FROM,		/* FROM constraint type */
		ACT_CT_WCOMP,		/* WITH COMPONENT */
		ACT_CT_WCOMPS,		/* WITH COMPONENTS */
		ACT_CT_CTDBY,		/* CONSTRAINED BY */
		ACT_CT_CTNG,		/* CONTAINING Type */
		ACT_CT_PATTERN,		/* PATTERN Value */
		/*
		 * Arrays of constraints.
		 */
		ACT_CA_SET,		/* A set of constraints: (c1)(c2) */
		ACT_CA_CRC,		/* Comp. relation c-t: ({a}{@b}) */
		ACT_CA_CSV,		/* Comma-separated constraints array */
		ACT_CA_UNI,		/* UNION (|) */
		ACT_CA_INT,		/* INTERSECTION (^) */
		ACT_CA_EXC,		/* EXCEPT */
		ACT_CA_AEX,		/* ALL EXCEPT */
	} type;

	enum asn1p_constr_pres_e {
		ACPRES_DEFAULT,
		ACPRES_PRESENT,
		ACPRES_ABSENT,
		ACPRES_OPTIONAL,
	} presence;

	struct asn1p_constraint_s *parent_ct;	/* optional */

	/*
	 * Separate types and values.
	 */
	asn1p_value_t *containedSubtype;
	asn1p_value_t *value;
	asn1p_value_t *range_start;
	asn1p_value_t *range_stop;

	/*
	 * A collection of constraint elements.
	 */
	struct asn1p_constraint_s **elements;
	unsigned int el_count;	/* Number of meaningful elements */
	unsigned int el_size;	/* Size of the allocated (elements) */

	struct asn1p_module_s *module;	/* Defined in module */
	int _lineno;	/* Position in a source file */
} asn1p_constraint_t;

/* Human-readable constraint type description */
const char *asn1p_constraint_type2str(enum asn1p_constraint_type_e);

const asn1p_constraint_t *asn1p_get_component_relation_constraint(
    asn1p_constraint_t *);

int asn1p_constraint_compare(const asn1p_constraint_t *,
                             const asn1p_constraint_t *);
void asn1p_constraint_set_source(asn1p_constraint_t *,
                                 struct asn1p_module_s *module, int lineno);

/*
 * Constructors and a recursive destructor.
 */
asn1p_constraint_t *asn1p_constraint_new(int _lineno, asn1p_module_t *mod);
void asn1p_constraint_free(asn1p_constraint_t *);

/*
 * Clone the constraint and all its children.
 */
asn1p_constraint_t *asn1p_constraint_clone(asn1p_constraint_t *source_to_clone);
asn1p_constraint_t *asn1p_constraint_clone_with_resolver(
	asn1p_constraint_t *source_to_clone,
	asn1p_value_t *(*resolver)(asn1p_value_t *, void *), void *);

/*
 * Insert additional element into the element array of a (to) constraint.
 */
int asn1p_constraint_insert(asn1p_constraint_t *into, asn1p_constraint_t *what);
int asn1p_constraint_prepend(asn1p_constraint_t *before, asn1p_constraint_t *what);

#endif	/* ASN1_PARSER_CONSTRAINT_H */
