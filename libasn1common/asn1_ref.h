/*
 * Generic reference to the yet unknown type defined elsewhere.
 */
#ifndef	ASN1_REFERENCE_H
#define	ASN1_REFERENCE_H

struct asn1p_module_s;

typedef struct asn1p_ref_s {

	/*
	 * A set of reference name components.
	 * A reference name consists of several components separated by dots:
	 * "OBJECT-CLASS.&Algorithm.&id"
	 */
	struct asn1p_ref_component_s {
		enum asn1p_ref_lex_type_e {
			RLT_UNKNOWN,		/* Invalid? */
			/*
			 * Object class reference "OCLASS1",
			 * type reference "Type1",
			 * value reference "id",
			 * type field reference "&Type1",
			 * value field reference "&id",
			 * "OBJECT-CLASS"
			 */
			RLT_CAPITALS,
			RLT_Uppercase,
			RLT_lowercase,
			RLT_AmpUppercase,
			RLT_Amplowercase,
			RLT_Atlowercase,
			RLT_AtDotlowercase,
			RLT_MAX
		} lex_type;	/* Inferred lexical type of the identifier */
		char *name;	/* An identifier */
	} *components;

	size_t comp_count;	/* Number of the components in the reference name. */
	size_t comp_size;	/* Number of allocated structures */

	struct asn1p_module_s *module;	/* Defined in module */
	int _lineno;	/* Number of line in the file */
} asn1p_ref_t;

/*
 * Constructor and destructor.
 */
asn1p_ref_t *asn1p_ref_new(int _lineno, struct asn1p_module_s *mod);
void asn1p_ref_free(asn1p_ref_t *);

asn1p_ref_t *asn1p_ref_clone(asn1p_ref_t *ref);

void asn1p_ref_set_source(asn1p_ref_t *, struct asn1p_module_s *module,
                          int lineno);


/*
 * Lexicographically compare references.
 */
int asn1p_ref_compare(const asn1p_ref_t *, const asn1p_ref_t *);

/*
 * Return a pointer to a statically allocated buffer representing the
 * complete reference.
 */
const char *asn1p_ref_string(const asn1p_ref_t *);

/*
 * Add a new reference component to the existing reference structure.
 *
 * RETURN VALUES:
 *  0:		All clear.
 * -1/EINVAL:	Invalid arguments
 * -1/ENOMEM:	Memory allocation failed
 */
int asn1p_ref_add_component(asn1p_ref_t *,
	const char *name, enum asn1p_ref_lex_type_e);

#endif	/* ASN1_REFERENCE_H */
