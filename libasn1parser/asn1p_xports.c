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
		TQ_INIT(&(xp->members));
	}

	return xp;
}

/*
 * Destroy the xports structure.
 */
void
asn1p_xports_free(asn1p_xports_t *xp) {
	if(xp) {
		if(xp->fromModuleName)
			free(xp->fromModuleName);
		if(xp->identifier.oid)
			asn1p_oid_free(xp->identifier.oid);
		free(xp);
	}
}
