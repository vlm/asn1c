#ifndef	ASN1FIX_CLASS_H
#define	ASN1FIX_CLASS_H

/*
 * Fetch the element from the class-related stuff (thing) by its reference.
 */
asn1p_expr_t *asn1f_class_access(arg_t *, asn1p_expr_t *rhs_pspecs,
                                 const asn1p_ref_t *);

#endif	/* ASN1FIX_CLASS_H */
