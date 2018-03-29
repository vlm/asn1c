/*
 * Imports and exports structure.
 */
#ifndef	ASN1_PARSE_XPORTS_H
#define	ASN1_PARSE_XPORTS_H


typedef struct asn1p_xports_s {
	/*
	 * Type of the xports structure.
	 */
	enum asn1p_xports {
		XPT_IMPORTS,
		XPT_EXPORTS,
	} xports_type;

	/*
	 * Module name and optional OID, occur after FROM.
	 */
	char *fromModuleName;		/* Name of the module */
	struct AssignedIdentifier {
		asn1p_oid_t *oid;	/* Optional OID of the module */
		asn1p_value_t *value;	/* DefinedValue */
	} identifier;

	/*
	 * Number of entities to import.
	 */
	TQ_HEAD(struct asn1p_expr_s)	xp_members;

	/*
	 * Pointer to the next xports structure in whatever list.
	 */
	TQ_ENTRY(struct asn1p_xports_s)	xp_next;
} asn1p_xports_t;

/*
 * Constructor and destructor.
 */
asn1p_xports_t *asn1p_xports_new(void);
void asn1p_xports_free(asn1p_xports_t *);

#endif	/* ASN1_PARSE_XPORTS_H */
