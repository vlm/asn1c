#ifndef	_ASN1FIX_CONSTRUCTED_H_
#define	_ASN1FIX_CONSTRUCTED_H_

/*
 * Pull in COMPONENTS OF.
 */
int asn1f_pull_components_of(arg_t *);

/*
 * Fix extensions in constructed types.
 */
int asn1f_fix_constr_ext(arg_t *);

/*
 * Fix tagging in constructed types.
 */
int asn1f_fix_constr_tag(arg_t *, int fix_top_level);

/*
 * Check distinctive tagging in constructed types.
 */
int asn1f_check_constr_tags_distinct(arg_t *);

/*
 * Perform automatic tagging.
 */
int asn1f_fix_constr_autotag(arg_t *);

#endif	/* _ASN1FIX_CONSTRUCTED_H_ */
