#include <stdlib.h>
#include <string.h>

#include "asn1parser.h"

/*
 * Construct a new structure that would hold the EXPORTS or IMPORTS
 * clause data.
 */
asn1p_xports_t *
asn1p_xports_new() {
	asn1p_xports_t *xp;

	xp = calloc(1, sizeof *xp);
	if(xp) {
		TQ_INIT(&(xp->xp_members));
	}

	return xp;
}

/*
 * Destroy the xports structure.
 */
void
asn1p_xports_free(asn1p_xports_t *xp) {
	if(xp) {
		asn1p_expr_t *expr;

		free(xp->fromModuleName);
		asn1p_oid_free(xp->identifier.oid);

		while((expr = TQ_REMOVE(&(xp->xp_members), next)))
			asn1p_expr_free(expr);

		free(xp);
	}
}
