/* OID support contributed by Sean Leonard of SeanTek(R). */

#include "asn1c_internal.h"
#include "asn1c_oid.h"
#include "asn1p_oid.h"		/* Object identifiers (OIDs) */

int asn1c_oid_ber_encode(arg_t *arg, uint8_t **ber, size_t *ber_len) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_oid_t *oid = expr->value->value.oid;
	int is_roid;

	if (expr->expr_type != ATV_OBJECT_IDENTIFIER) {
		if (expr->expr_type == ASN_BASIC_RELATIVE_OID) {
			is_roid = 1;
		} else {
			errno = EINVAL;
			return -1;
		}
	}	else {
		is_roid = 0;
	}

	if (!ber || !ber_len) {
		errno = EINVAL;
		return -1;
	}
	
	/* Compute result. */
	return -1;
}
