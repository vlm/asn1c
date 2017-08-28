#ifndef	ASN1FIX_TAGS_H
#define	ASN1FIX_TAGS_H

struct asn1_namespace_s;   /* Forward declaration */

enum asn1f_aft_flags_e {
	AFT_IMAGINARY_ANY	= 0x01,	/* Treat ANY tag as [IMAGINARY ANY] */
	AFT_FETCH_OUTMOST	= 0x02,	/* Fetch only outmost tag */
	AFT_FULL_COLLECT	= 0x04,	/* Collect all tags */
	AFT_CANON_CHOICE	= 0x08,	/* Fetch the minimal CHOICE root tag */
};

/*
 * Allocate and return an array of tags for the given type.
 * Type1 ::= [2] EXPLICIT Type2
 * Type2 ::= [3] IMPLICIT Type3
 * Type3 ::= [4] EXPLICIT SEQUENCE { ... }
 * Will return [2][3][UNIVERSAL 16] for the Type1.
 */
int asn1f_fetch_tags(asn1p_t *asn, struct asn1_namespace_s *ns,
                     asn1p_module_t *mod, asn1p_expr_t *expr,
                     struct asn1p_type_tag_s **tags,
                     enum asn1f_aft_flags_e flags);

/*
 * Fetch the outmost tag of the given type.
 * Type1 ::= Type2
 * Type2 ::= [2] Type3
 * Type3 ::= SEQUENCE { ... }
 * Will yield [2] for Type1.
 */
int asn1f_fetch_outmost_tag(asn1p_t *asn, struct asn1_namespace_s *ns,
                            asn1p_module_t *mod, asn1p_expr_t *expr,
                            struct asn1p_type_tag_s *tag,
                            enum asn1f_aft_flags_e);

#endif	/* ASN1FIX_TAGS_H */
