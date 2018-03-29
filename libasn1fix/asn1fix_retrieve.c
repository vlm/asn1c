#include "asn1fix_internal.h"

enum ftt_what {
	FTT_TYPE,	/* Find the type of the given expression */
	FTT_VALUE,	/* Find the value of the given expression */
	FTT_CONSTR_TYPE /* Find the type of the given expression having constraint */ 
};

static asn1p_expr_t *asn1f_find_terminal_thing(arg_t *arg, asn1p_expr_t *expr, enum ftt_what);
static int asn1f_compatible_with_exports(arg_t *arg, asn1p_module_t *mod, const char *name);


/*
 * Lookup a child by its name.
 */
asn1p_expr_t *
asn1f_lookup_child(asn1p_expr_t *tc, const char *name) {
	asn1p_expr_t *child_tc;

	TQ_FOR(child_tc, &(tc->members), next) {
		if(child_tc->Identifier
		&& strcmp(child_tc->Identifier, name) == 0) {
			return child_tc;
		}
	}

	errno = ESRCH;
	return NULL;
}

static asn1p_expr_t *
asn1f_lookup_in_module(asn1p_module_t *mod, const char *name) {
    asn1p_expr_t *expr = genhash_get(mod->members_hash, name);
    if(!expr) {
        asn1p_expr_t *memb;
        TQ_FOR(memb, &mod->members, next) {
            if(memb->expr_type == ASN_BASIC_ENUMERATED) {
                asn1p_expr_t *v = asn1f_lookup_child(memb, name);
                if(v) return v;
            }
        }
    }

    return expr;
}

asn1p_module_t *
asn1f_lookup_in_imports(arg_t *arg, asn1p_module_t *mod, const char *name) {
	asn1p_xports_t *xp;

	/*
	 * Search in which exactly module this name is defined.
	 */
	TQ_FOR(xp, &(mod->imports), xp_next) {
        asn1p_module_t *fromModule =
            asn1f_lookup_module(arg, xp->fromModuleName, NULL);
        asn1p_expr_t *tc = (asn1p_expr_t *)0;

        TQ_FOR(tc, &(xp->xp_members), next) {
            if(strcmp(name, tc->Identifier) == 0)
				break;

			if(!fromModule)
				continue;

            asn1p_expr_t *v =
                asn1f_lookup_in_module(fromModule, name);
            if(v) break;
		}
		if(tc) break;
	}
	if(xp == NULL) {
		errno = ESRCH;
		return NULL;
	}

	/*
	 * Okay, right now we have a module name and, hopefully, an OID.
	 * Search the arg->asn for the specified module.
	 */
	mod = asn1f_lookup_module(arg, xp->fromModuleName, xp->identifier.oid);
	if(mod == NULL) {
		/* Conditional debug */
		if(!(arg->expr->_mark & TM_BROKEN)) {
			arg->expr->_mark |= TM_BROKEN;
			FATAL("Cannot find external module \"%s\" "
				"mentioned for "
				"\"%s\" at line %d. "
				"Obtain this module and instruct compiler to process it too.",
				xp->fromModuleName, name, arg->expr->_lineno);
		}
		/* ENOENT/ETOOMANYREFS */
		return NULL;
	}

	/*
	 * Check that the EXPORTS section of this module contains
	 * the symbol we care about, or it is EXPORTS ALL.
	 */
	if(asn1f_compatible_with_exports(arg, mod, name)) {
		errno = EPERM;
		return NULL;
	}

	return mod;
}

asn1p_module_t *
asn1f_lookup_module(arg_t *arg, const char *module_name, const asn1p_oid_t *oid) {
	asn1p_module_t *mod;

	assert(module_name);

	/*
	 * If OID is given, the module_name is unused.
	 * If OID is not given, the module_name may mean
	 * either the real module's name, or the symbol which is the
	 * result of renaming. Check this first.
	 */
	if(oid == 0) {
		asn1p_xports_t *xp;
		/*
		 * Check inside the IMPORTS section for possible renaming.
		 * Renaming practically means that a module_name is mentioned
		 * somewhere in the IMPORTS section AND OID is given.
		 */
		TQ_FOR(xp, &(arg->mod->imports), xp_next) {
			if(strcmp(module_name, xp->fromModuleName))
				continue;
			if(oid) {
				FATAL("Ambiguous reference: "
					"%s "
					"matches several modules",
					module_name);
				errno = ETOOMANYREFS;
				return NULL;
			}
			/*
			 * Yes, there is a renaming.
			 * Make lookup use OID instead.
			 */
			oid = xp->identifier.oid;
		}
	}

	/*
	 * Perform lookup using OID or module_name.
	 */
	TQ_FOR(mod, &(arg->asn->modules), mod_next) {
		if(oid) {
			if(mod->module_oid) {
				if(asn1p_oid_compare(oid,
					mod->module_oid)) {
					continue;
				} else {
					/* Match! Even if name doesn't. */
					return mod;
				}
			} else {
				/* Not match, even if name is the same. */
				continue;
			}
		}
	
		if(strcmp(module_name, mod->ModuleName) == 0)
			return mod;
	}

	DEBUG("\tModule \"%s\" not found", module_name);

	errno = ENOENT;
	return NULL;
}

static asn1p_expr_t *
asn1f_lookup_symbol_impl(arg_t *arg, asn1p_expr_t *rhs_pspecs, const asn1p_ref_t *ref, int recursion_depth) {
    asn1_namespace_t *initial_namespace = arg->ns;
	asn1p_ref_t tmp_ref;
	asn1p_module_t *imports_from;
	char *modulename;
	char *identifier;

    if(ref->module && arg->mod != ref->module) {
        return WITH_MODULE(
            ref->module,
            asn1f_lookup_symbol_impl(arg, rhs_pspecs, ref, recursion_depth));
    }

	/*
	 * First of all, a reference to a symbol may be specified
	 * using several possible forms:
	 * a) simple identifier
	 *	v INTEGER ::= value
	 * b) external reference
	 * 	v INTEGER ::= Module1.value
	 * c) class-related stuff (the most complex stuff)
	 * 	v ::= <[A-Z][A-Z0-9a-z-]*>.&<[A-Z0-9a-z-]+>.
	 * All other forms are not implemented at this moment.
	 */

	DEBUG("Lookup (%s) in %s for line %d",
		asn1f_printable_reference(ref),
		asn1_namespace_string(initial_namespace),
		ref->_lineno);

	if(recursion_depth++ > 30 /* Arbitrary constant */) {
        FATAL(
            "Excessive circular referencing detected in namespace %s for %s at "
            "line %d",
            asn1_namespace_string(initial_namespace),
            asn1f_printable_reference(ref), ref->_lineno);
        errno = ETOOMANYREFS;
		return NULL;
	}

	if(ref->comp_count == 1) {
		modulename = NULL;
		identifier = ref->components[0].name;
	} else if(ref->comp_count == 2
		&& ref->components[1].name[0] != '&') {
		modulename = ref->components[0].name;
		identifier = ref->components[1].name;
	} else if(ref->comp_count > 1
		&& isupper(ref->components[0].name[0])
		&& ref->components[1].name[0] == '&') {
		asn1p_expr_t *extract;
		/*
		 * This is a reference to a CLASS-related stuff.
		 * Employ a separate function for that.
		 */
		extract = asn1f_class_access(arg, rhs_pspecs, ref);
		
		return extract;
	} else {
		DEBUG("\tToo many components: %d", ref->comp_count);
		errno = EINVAL;
		return NULL;
	}

    if(modulename) {
        /*
         * The modulename is specified inside this reference.
         * To avoid recursion, reformat the reference
         * as it were local to that module.
         */
        tmp_ref = *ref;
        tmp_ref.components++; /* Hide the first element */
        tmp_ref.comp_count--;
        assert(tmp_ref.comp_count > 0);
        ref = &tmp_ref;
    }

    asn1_namespace_t *my_namespace = initial_namespace;

#define DISPOSE_OF_MY_NAMESPACE()               \
    do {                                        \
        int tmp_errno = errno;                  \
        if(my_namespace != initial_namespace) { \
            asn1_namespace_free(my_namespace);  \
            my_namespace = NULL;                \
        }                                       \
        errno = tmp_errno;                      \
    } while(0)

    /*
     * If module name is specified explicitly
     * OR the current module's IMPORTS clause contains the identifier,
     * switch namespace to that module.
     */
    if(modulename) {
        imports_from = asn1f_lookup_module(arg, modulename, 0);
        if(imports_from == NULL) {
            FATAL(
                "Module \"%s\" "
                "mentioned at line %d is not found",
                modulename, ref->_lineno);
            return NULL;
        }

        /*
         * Check that the EXPORTS section of this module contains
         * the symbol we care about, or it is EXPORTS ALL.
         */
        if(asn1f_compatible_with_exports(arg, imports_from, identifier)) {
            errno = EPERM;
            return NULL;
        }

        DISPOSE_OF_MY_NAMESPACE();
        my_namespace = asn1_namespace_new_from_module(imports_from, 1);
        DEBUG("Lookup (%s) in %s for line %d", asn1f_printable_reference(ref),
              asn1_namespace_string(my_namespace), ref->_lineno);
    }

    size_t namespace_switches = 0;

    /*
     * Search through all layers of the namespace.
     */
    for(ssize_t ns_item = my_namespace->elements_count - 1; ns_item >= 0;
        ns_item--) {
        struct asn1_namespace_element_s *ns_el =
            &my_namespace->elements[ns_item];

        switch(ns_el->selector) {
        case NAM_SYMBOL:
            if(modulename) {
                /*
                 * Trying to match a fully specified "Module.Symbol"
                 * against the "Symbol" parameter. Doesn't match.
                 */
                continue;
            }
            if(strcmp(ns_el->u.symbol.identifier, identifier) != 0) {
                continue;
            } else {
                DEBUG("Lookup (%s) in %s for line %d => found as parameter",
                      asn1f_printable_reference(ref),
                      asn1_namespace_string(my_namespace), ref->_lineno);
                DISPOSE_OF_MY_NAMESPACE();
                return ns_el->u.symbol.resolution;
            }
        case NAM_SPACE: {
            asn1p_expr_t *ref_tc; /* Referenced tc */
            /*
             * Do a direct symbol search in the given module.
             */
            ref_tc = asn1f_lookup_in_module(ns_el->u.space.module, identifier);
            if(ref_tc) {
                /* It is acceptable that we don't use input parameters */
                if(rhs_pspecs && !ref_tc->lhs_params) {
                    WARNING(
                        "Parameterized type %s expected "
                        "for %s at line %d",
                        ref_tc->Identifier, asn1f_printable_reference(ref),
                        ref->_lineno);
                }
                if(!rhs_pspecs && ref_tc->lhs_params) {
                    FATAL(
                        "Type %s expects specialization "
                        "from %s at line %d",
                        ref_tc->Identifier, asn1f_printable_reference(ref),
                        ref->_lineno);
                    errno = EPERM;
                    DISPOSE_OF_MY_NAMESPACE();
                    return NULL;
                }
                if(rhs_pspecs && ref_tc->lhs_params) {
                    /* Specialize the target */
                    ref_tc =
                        asn1f_parameterization_fork(arg, ref_tc, rhs_pspecs);
                }

                DISPOSE_OF_MY_NAMESPACE();
                return ref_tc;
            }
        }

    /*
            if(!expr && !(arg->expr->_mark & TM_BROKEN)
               && !(imports_from->_tags & MT_STANDARD_MODULE)) {
                arg->expr->_mark |= TM_BROKEN;
                if(modulename) {
                } else {
                    FATAL(
                        "Module %s referred in IMPORTS section "
                        "for %s of module %s does not contain "
                        "the requested symbol",
                        imports_from->ModuleName,
                        asn1f_printable_reference(ref), mod->ModuleName);
                }
            }
        */

            /* Search inside the IMPORTS section of the given module */
            imports_from =
                asn1f_lookup_in_imports(arg, ns_el->u.space.module, identifier);
            if(imports_from) {

                if(namespace_switches++ > 10 /* Arbitrary constant */) {
                    FATAL(
                        "Excessive circular referencing detected in namespace "
                        "%s for %s at "
                        "line %d",
                        asn1_namespace_string(arg->ns),
                        asn1f_printable_reference(ref), ref->_lineno);
                    errno = ETOOMANYREFS;
                    DISPOSE_OF_MY_NAMESPACE();
                    return NULL;
                }

                /* Switch namespace */
                DISPOSE_OF_MY_NAMESPACE();
                my_namespace = asn1_namespace_new_from_module(imports_from, 1);
                DEBUG("Lookup (%s) in %s for line %d",
                      asn1f_printable_reference(ref),
                      asn1_namespace_string(my_namespace), ref->_lineno);
                ns_item = my_namespace->elements_count;

                continue;
            } else if(errno != ESRCH) {
                /*
                 * Return only if the name was not found.
                 * If module was not found or more serious error
                 * encountered, just return preserving the errno.
                 */
                DISPOSE_OF_MY_NAMESPACE();
                return NULL;
            }

            if(modulename) {
                FATAL(
                    "Module %s referred by %s in module %s "
                    "does not contain the requested symbol",
                    ns_el->u.space.module->ModuleName,
                    asn1f_printable_reference(ref), modulename);
                break;
            }

            /* Search failed in the given namespace */
            continue;
        }
    }

    DEBUG(
        "Namespace %s does not contain \"%s\" "
        "mentioned at line %d: %s",
        asn1_namespace_string(my_namespace), identifier, ref->_lineno,
        strerror(errno));

    DISPOSE_OF_MY_NAMESPACE();

    if(asn1f_check_known_external_type(identifier) == 0) {
		errno = EEXIST; /* Exists somewhere */
	} else {
		errno = ESRCH;
	}
	return NULL;
}


asn1p_expr_t *
asn1f_lookup_symbol(arg_t *arg, asn1p_expr_t *rhs_pspecs,
                    const asn1p_ref_t *ref) {
    return asn1f_lookup_symbol_impl(arg, rhs_pspecs, ref, 0);
}

asn1p_expr_t *
asn1f_find_terminal_type(arg_t *arg, asn1p_expr_t *expr) {
	return asn1f_find_terminal_thing(arg, expr, FTT_TYPE);
}

asn1p_expr_t *
asn1f_find_terminal_value(arg_t *arg, asn1p_expr_t *expr) {
	return asn1f_find_terminal_thing(arg, expr, FTT_VALUE);
}

asn1p_expr_t *
asn1f_find_ancestor_type_with_PER_constraint(arg_t *arg, asn1p_expr_t *expr) {
	return asn1f_find_terminal_thing(arg, expr, FTT_CONSTR_TYPE);
}

static asn1p_expr_t *
asn1f_find_terminal_thing(arg_t *arg, asn1p_expr_t *expr, enum ftt_what what) {
	asn1p_ref_t *ref = 0;
	asn1p_expr_t *tc;

    if(arg->mod != expr->module) {
        return WITH_MODULE(expr->module,
                           asn1f_find_terminal_thing(arg, expr, what));
    }

    switch(what) {
    case FTT_TYPE:
    case FTT_CONSTR_TYPE:
        /* Expression may be a terminal type itself */
        if(expr->expr_type != A1TC_REFERENCE) {
            return expr;
        }
        ref = expr->reference;
        break;
    case FTT_VALUE:

	DEBUG("%s(%s->%s) meta %d for line %d",
		"VALUE", expr->Identifier, asn1f_printable_reference(ref),
		expr->meta_type, expr->_lineno);

        assert(expr->meta_type == AMT_VALUE);
        assert(expr->value);
        /* Expression may be a terminal type itself */
        if(expr->value->type != ATV_REFERENCED) {
            return expr;
        }
        ref = expr->value->value.reference;
        break;
    }

	DEBUG("%s(%s->%s) for line %d",
		(what == FTT_VALUE)?"VALUE":"TYPE",
		expr->Identifier, asn1f_printable_reference(ref),
		expr->_lineno);

	assert(ref);

	/*
	 * Lookup inside the type itself (ENUMERATED, INTEGER, etc).
	 */
	if(what == FTT_VALUE) {
		asn1p_expr_t *val_type_tc;
		val_type_tc = asn1f_find_terminal_type(arg, expr);
        if(val_type_tc
           && WITH_MODULE(val_type_tc->module,
                          asn1f_look_value_in_type(arg, val_type_tc, expr))) {
            return expr;
        }
		if(expr->value->type != ATV_REFERENCED) {
            return expr;
		}
		assert(ref == expr->value->value.reference);
		ref = expr->value->value.reference;
	}

	/*
	 * Lookup inside the default module and its IMPORTS section.
	 */
    tc = asn1f_lookup_symbol(arg, expr->rhs_pspecs, ref);
    if(tc == NULL) {
		/*
	 	 * Lookup inside the ref's module and its IMPORTS section.
	 	 */
        tc = WITH_MODULE(ref->module,
                         asn1f_lookup_symbol(arg, expr->rhs_pspecs, ref));
        if(tc == NULL) {
			DEBUG("\tSymbol \"%s\" not found: %s",
				asn1f_printable_reference(ref),
				strerror(errno));
            return NULL;
		}
	}

	/*
	 * Recursive loops detection.
	 */
    if(tc->_mark & TM_RECURSION) {
        DEBUG("Recursion loop detected for %s at line %d",
              asn1f_printable_reference(ref), ref->_lineno);
        errno = EPERM;
        return NULL;
    }

    tc->_type_referenced = 1;

    if((what == FTT_CONSTR_TYPE) && (tc->constraints)) {
        return tc;
    }

    tc->_mark |= TM_RECURSION;
    expr = WITH_MODULE(tc->module, asn1f_find_terminal_thing(arg, tc, what));
    tc->_mark &= ~TM_RECURSION;

    return expr;
}


/*
 * Make sure that the specified name is present or otherwise does
 * not contradict with the EXPORTS clause of the specified module.
 */
static int
asn1f_compatible_with_exports(arg_t *arg, asn1p_module_t *mod, const char *name) {
	asn1p_xports_t *exports;
	asn1p_expr_t *item;

	assert(mod);
	assert(name);

	exports = TQ_FIRST(&(mod->exports));
	if(exports == NULL) {
		/* No EXPORTS section or EXPORTS ALL; */
		return 0;
	}

	TQ_FOR(item, &(exports->xp_members), next) {
		if(strcmp(item->Identifier, name) == 0)
			return 0;
	}

	/* Conditional debug */
	if(!(arg->expr->_mark & TM_BROKEN)) {
		arg->expr->_mark |= TM_BROKEN;
		FATAL("EXPORTS section of module %s in %s "
			"does not mention %s at line %d",
			mod->ModuleName, mod->source_file_name, name,
			arg->expr->_lineno);
	}

	errno = ESRCH;
	return -1;
}
