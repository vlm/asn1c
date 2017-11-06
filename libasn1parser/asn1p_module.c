#include <stdlib.h>
#include <string.h>
#include <genhash.h>

#include "asn1parser.h"

/*
 * Construct a new empty module.
 */
asn1p_module_t *
asn1p_module_new() {
	asn1p_module_t *mod;

	mod = calloc(1, sizeof *mod);
	if(mod) {
		TQ_INIT(&(mod->exports));
		TQ_INIT(&(mod->imports));
		TQ_INIT(&(mod->members));

        mod->members_hash = genhash_new(cmpf_string, hashf_string, NULL, NULL);
        assert(mod->members_hash);
    }
	return mod;
}

/*
 * Destroy the module.
 */
void
asn1p_module_free(asn1p_module_t *mod) {
	if(mod) {
		asn1p_expr_t *expr;
		asn1p_xports_t *xports;

		free(mod->ModuleName);
		free(mod->source_file_name);

		asn1p_oid_free(mod->module_oid);

		while((xports = TQ_REMOVE(&(mod->exports), xp_next)))
			asn1p_xports_free(xports);

		while((xports = TQ_REMOVE(&(mod->imports), xp_next)))
			asn1p_xports_free(xports);

		while((expr = TQ_REMOVE(&(mod->members), next)))
			asn1p_expr_free(expr);

        genhash_destroy(mod->members_hash);
        mod->members_hash = NULL;

		free(mod);
	}
}

asn1p_t *
asn1p_new() {
	asn1p_t *asn;
	asn = calloc(1, sizeof(*asn));
	if(asn) {
		TQ_INIT(&(asn->modules));
	}
	return asn;
}


void
asn1p_delete(asn1p_t *asn) {
	if(asn) {
		asn1p_module_t *mod;
		while((mod = TQ_REMOVE(&(asn->modules), mod_next)))
			asn1p_module_free(mod);
		free(asn);
	}
}


void
asn1p_module_move_members(asn1p_module_t *to, asn1p_module_t *from) {
    if(from) {
        while(TQ_FIRST(&(from->members))) {
            asn1p_expr_t *expr = TQ_REMOVE(&from->members, next);
            TQ_ADD(&to->members, expr, next);
            genhash_add(to->members_hash, expr->Identifier, expr);
        }
        assert(TQ_FIRST(&from->members) == 0);

        genhash_empty(from->members_hash, 0, 0);
    }
}

void
asn1p_module_member_add(asn1p_module_t *mod, asn1p_expr_t *expr) {
    if(expr) {
        TQ_ADD(&mod->members, expr, next);
        genhash_add(mod->members_hash, expr->Identifier, expr);
    }
}
