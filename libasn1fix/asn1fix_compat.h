#ifndef	_ASN1FIX_COMPAT_H_
#define	_ASN1FIX_COMPAT_H_

/*
 * Check that the expressions given are compatible in their type.
 * ORDER DOES MATTER!
 * The compatibility is being checked as if the value of b were used
 * to assign it to type a.
 */
int asn1f_check_type_compatibility(arg_t *arg,
	asn1p_expr_t *a,
	asn1p_expr_t *b);

#endif	/* _ASN1FIX_COMPAT_H_ */
