#ifndef	_ASN1FIX_CONSTRUCTED_H_
#define	_ASN1FIX_CONSTRUCTED_H_

/*
 * Fix extensions in constructed types.
 */
int asn1f_fix_constr_ext(arg_t *);

/*
 * Fix tagging in constructed types.
 */
int asn1f_fix_constr_tag(arg_t *);

/*
 * Check distinctive tagging in constructed types.
 */
int asn1f_check_constr_tags_distinct(arg_t *);

/*
 * Perform automatic tagging.
 */
int asn1f_fix_constr_autotag(arg_t *);

#endif	/* _ASN1FIX_CONSTRUCTED_H_ */
