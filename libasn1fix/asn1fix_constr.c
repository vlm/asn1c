#include "asn1fix_internal.h"

static int _asn1f_check_if_tag_must_be_explicit(arg_t *arg, asn1p_expr_t *v);
static int _asn1f_compare_tags(arg_t *arg, asn1p_expr_t *a, asn1p_expr_t *b);

int
asn1f_pull_components_of(arg_t *arg) {
	TQ_HEAD(asn1p_expr_t) list;
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *memb;
	int r_value = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
		break;
	default:
		return 0;
	}

	TQ_INIT(&list);

	/*
	 * Look into
	 */
	while((memb = TQ_REMOVE(&(expr->members), next))) {
		asn1p_expr_t *coft;	/* COMPONENTS OF thing itself */
		asn1p_expr_t *terminal;	/* Terminal of the referenced type */

		if(memb->expr_type != A1TC_COMPONENTS_OF) {
			TQ_ADD(&list, memb, next);
			continue;
		}

		coft = TQ_FIRST(&memb->members);
		assert(coft);
		assert(!TQ_NEXT(coft, next));

		/*
		 * Find the referenced type.
		 */
		terminal = asn1f_find_terminal_type(arg, coft);
		if(!terminal || (terminal->expr_type != expr->expr_type)) {
			FATAL("COMPONENTS OF at line %d "
				"must reference a %s type",
				coft->_lineno,
				expr->expr_type==ASN_CONSTR_SET
					? "SET" : "SEQUENCE"
			);
			TQ_ADD(&list, memb, next);
			r_value = -1;
			continue;
		}

		/*
		 * Clone the final structure.
		 */

		coft = asn1p_expr_clone(terminal, 1 /* Skip extensions */);
		if(!coft) return -1;	/* ENOMEM */

		asn1p_expr_free(memb);	/* Don't need it anymore*/

		/*
		 * Move all components of the cloned structure
		 * into the current one.
		 */
		while((memb = TQ_REMOVE(&(coft->members), next)))
			TQ_ADD(&list, memb, next);

		asn1p_expr_free(coft);	/* Remove wrapper */
	}

	/* Move the stuff back */
	TQ_MOVE(&(expr->members), &list);

	return r_value;
}

int
asn1f_fix_constr_ext(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	TQ_HEAD(asn1p_expr_t) root_list;
	TQ_HEAD(asn1p_expr_t) ext_list;
	TQ_HEAD(asn1p_expr_t) *cur_list;
	int r_value = 0;
	int ext_count = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		break;
	default:
		return 0;
	}

	DEBUG("%s(%s) for line %d", __func__,
		expr->Identifier, expr->_lineno);

	TQ_INIT(&root_list);
	TQ_INIT(&ext_list);
	cur_list = (void *)&root_list;

	while((v = TQ_REMOVE(&(expr->members), next))) {
		if(v->expr_type == A1TC_EXTENSIBLE) {
			ext_count++;
			switch(ext_count) {
			case 1: cur_list = (void *)&ext_list; break;
			case 2:
				cur_list = (void *)&root_list;
				if(v->value) {
					FATAL("Optional extension marker "
						"must not contain "
						"an exception mark "
						"at line %d", v->_lineno);
					r_value = -1;
				}
				asn1p_expr_free(v);
				continue;
			case 3:
				FATAL("Third extension marker "
				"is not allowed at line %d", v->_lineno);
			default:
				r_value = -1;
			}
		}

		TQ_ADD(cur_list, v, next);
	}

	/*
	 * Copy the root list and extension list back into the main list.
	 */
	TQ_MOVE(&(expr->members), &root_list);
	while((v = TQ_REMOVE(&ext_list, next)))
		TQ_ADD(&(expr->members), v, next);

	if(arg->mod->module_flags & MSF_EXTENSIBILITY_IMPLIED
	&& ext_count == 0) {
		v = asn1p_expr_new(0);
		if(v) {
			v->Identifier = strdup("...");
			v->expr_type = A1TC_EXTENSIBLE;
			v->meta_type = AMT_TYPE;
			v->_lineno = expr->_lineno;	/* The best we can do */
			if(v->Identifier == NULL) {
				asn1p_expr_free(v);
				r_value = -1;
			} else {
				TQ_ADD(&(expr->members), v, next);
			}
		} else {
			r_value = -1;
		}
	}

	return r_value;
}


int
asn1f_fix_constr_tag(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int fl_impl_tags = 0;
	int fl_auto_tags = 0;
	int root_tagged = 0;	/* The root component is manually tagged */
	int ext_tagged = 0;	/* The extensions are manually tagged */
	int component_number = 0;
	int r_value = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		break;
	default:
		return 0;
	}

	fl_impl_tags = (arg->mod->module_flags & MSF_IMPLICIT_TAGS);
	fl_auto_tags = (arg->mod->module_flags & MSF_AUTOMATIC_TAGS);

	DEBUG("%s(%s) {%d, %d} for line %d", __func__,
		expr->Identifier, fl_impl_tags, fl_auto_tags, expr->_lineno);

	TQ_FOR(v, &(expr->members), next) {
		int must_explicit = 0;

		if(v->expr_type == A1TC_EXTENSIBLE) {
			component_number++;
			continue;
		}

		if(v->tag.tag_class == TC_NOCLASS) {
			continue;
		} else {
			switch(component_number) {
			case 0: case 2:
				root_tagged = 1; break;
			default:
				ext_tagged = 1; break;
			}
		}

		must_explicit = _asn1f_check_if_tag_must_be_explicit(arg, v);

		if(fl_impl_tags) {
			if(v->tag.tag_mode != TM_EXPLICIT) {
				if(must_explicit)
					v->tag.tag_mode = TM_EXPLICIT;
				else
					v->tag.tag_mode = TM_IMPLICIT;
			}
		} else {
			if(v->tag.tag_mode == TM_DEFAULT) {
				v->tag.tag_mode = TM_EXPLICIT;
			}
		}

		/*
		 * Perform a final sanity check.
		 */
		if(must_explicit) {
			if(v->tag.tag_mode == TM_IMPLICIT) {
				FATAL("%s tagged in IMPLICIT mode "
					"but must be EXPLICIT at line %d",
					v->Identifier, v->_lineno);
				r_value = -1;
			} else {
				v->tag.tag_mode = TM_EXPLICIT;
			}
		}
	}

	if(ext_tagged && !root_tagged) {
		FATAL("In %s at line %d: "
			"extensions are tagged "
			"but root components are not",
			expr->Identifier, expr->_lineno);
		r_value = -1;
	} else if(!root_tagged && !ext_tagged && fl_auto_tags) {
		expr->auto_tags_OK = 1;
	}

	return r_value;
}

int
asn1f_fix_constr_autotag(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	asn1_integer_t tag_value = 0;
	int r_value = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		if(expr->auto_tags_OK)
			break;
		/* Automatic tagging is not applicable */
		/* Fall through */
	default:
		return 0;
	}

	DEBUG("%s(%s) for line %d", __func__,
		expr->Identifier, expr->_lineno);

	TQ_FOR(v, &(expr->members), next) {
		int must_explicit;

		if(v->expr_type == A1TC_EXTENSIBLE)
			break;

		if(0) {
			/* This may be not true in case COMPONENTS OF */
			assert(v->tag.tag_class == TC_NOCLASS);
		}

		must_explicit = _asn1f_check_if_tag_must_be_explicit(arg, v);

		v->tag.tag_class = TC_CONTEXT_SPECIFIC;
		v->tag.tag_mode = must_explicit ? TM_EXPLICIT : TM_IMPLICIT;
		v->tag.tag_value = tag_value++;
	}

	return r_value;
}

/*
 * Check that tags are distinct.
 */
int
asn1f_check_constr_tags_distinct(arg_t *arg) {
	asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *v;
	int r_value = 0;

	switch(expr->expr_type) {
	case ASN_CONSTR_SEQUENCE:
	case ASN_CONSTR_SET:
	case ASN_CONSTR_CHOICE:
		break;
	default:
		return 0;
	}

	TQ_FOR(v, &(expr->members), next) {
		/*
		 * In every series of non-mandatory components,
		 * the tags must be distinct from each other AND the
		 * tag of the following mandatory component.
		 * For SET and CHOICE treat everything as a big set of
		 * non-mandatory components.
		 */
		if(expr->expr_type != ASN_CONSTR_SEQUENCE || v->marker) {
			asn1p_expr_t *nv;
			for(nv = v; (nv = TQ_NEXT(nv, next));) {
				if(_asn1f_compare_tags(arg, v, nv))
					r_value = -1;
				if(expr->expr_type == ASN_CONSTR_SEQUENCE
				&& !nv->marker) break;
			}
		}
	}

	return r_value;
}

static int
_asn1f_check_if_tag_must_be_explicit(arg_t *arg, asn1p_expr_t *v) {
	asn1p_expr_t *reft;

	reft = asn1f_find_terminal_type(arg, v);
	if(reft) {
		switch(reft->expr_type) {
		case ASN_CONSTR_CHOICE:
			return 1;
		default:
			return 0;
		}
	}

	return 0;
}

/*
 * Check that the tags are distinct.
 */
static int
_asn1f_compare_tags(arg_t *arg, asn1p_expr_t *a, asn1p_expr_t *b) {
	struct asn1p_type_tag_s ta, tb;
	int ra, rb;
	int ret;

	ra = asn1f_fetch_tag(arg->asn, arg->mod, a, &ta);
	rb = asn1f_fetch_tag(arg->asn, arg->mod, b, &tb);

	/*
	 * If both tags are explicitly or implicitly given, use them.
	 */
	if(ra == 0 && rb == 0) {
		/*
		 * Simple case: fetched both tags.
		 */
		if(ta.tag_value == tb.tag_value
		&& ta.tag_class == tb.tag_class) {
			char *p = (a->expr_type == A1TC_EXTENSIBLE)
				?"potentially ":"";
			FATAL("Component \"%s\" at line %d %shas the same tag "
				"with component \"%s\" at line %d",
				a->Identifier,
				a->_lineno,
				p,
				b->Identifier,
				b->_lineno
			);
			if((arg->mod->module_flags & MSF_EXTENSIBILITY_IMPLIED)
			&& (a->expr_type == A1TC_EXTENSIBLE)
			&& (b->expr_type == A1TC_EXTENSIBLE)) {
				FATAL("The previous error is due to "
					"improper use of "
					"EXTENSIBILITY IMPLIED flag "
					"of module %s",
					arg->mod->Identifier);
			}
			return -1;
		} else {
			/* Tags are distinct */
			return 0;
		}
	}

	/**********************************************************
	 * Now we must perform some very funny recursion to check
	 * multiple components of CHOICE type, etc.
	 */

	DEBUG("Comparing tags %s:%x <-> %s:%x",
		a->Identifier, a->expr_type,
		b->Identifier, b->expr_type);

	if(a->meta_type == AMT_TYPEREF) {

		DEBUG(" %s is a type reference", a->Identifier);

		a = asn1f_lookup_symbol(arg, a->module, a->reference);
		if(!a) return 0;	/* Already FATAL()'ed somewhere else */
		WITH_MODULE(a->module, ret = _asn1f_compare_tags(arg, a, b));
		return ret;
	}

	if(a->expr_type == ASN_CONSTR_CHOICE) {
		asn1p_expr_t *v;

		DEBUG(" %s is a choice type (%d)", a->Identifier, a->_mark);

		/*
		 * Iterate over members of CHOICE.
		 */
		//if(a->_mark & TM_RECURSION) return 0;
		TQ_FOR(v, &(a->members), next) {
			//a->_mark |= TM_RECURSION;
			ret = _asn1f_compare_tags(arg, v, b);
			//a->_mark &= ~TM_RECURSION;
			if(ret) return ret;
		}
		return 0;
	}

	if(b->expr_type == ASN_CONSTR_CHOICE) {
		return _asn1f_compare_tags(arg, b, a);
	}

	if(a->_mark & TM_RECURSION) return 0;
	if(b->_mark & TM_RECURSION) return 0;
	a->_mark |= TM_RECURSION;
	b->_mark |= TM_RECURSION;
	ret = _asn1f_compare_tags(arg, b, a);
	a->_mark &= ~TM_RECURSION;
	b->_mark &= ~TM_RECURSION;

	return ret;
}

