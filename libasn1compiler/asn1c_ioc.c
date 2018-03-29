#include "asn1c_internal.h"
#include "asn1c_ioc.h"
#include "asn1c_out.h"
#include "asn1c_misc.h"
#include <asn1fix_export.h>
#include <asn1print.h>

#define MKID(expr) asn1c_make_identifier(0, (expr), 0)

/*
 * Given the table constraint or component relation constraint
 * ({ObjectSetName}{...}) returns "ObjectSetName" as a reference.
 */
const asn1p_ref_t *
asn1c_get_information_object_set_reference_from_constraint(arg_t *arg,
    const asn1p_constraint_t *ct) {

    if(!ct) return NULL;
    assert(ct->type == ACT_CA_CRC);
    assert(ct->el_count >= 1);

    DEBUG("Component Relation Constraint: %s", asn1p_constraint_string(ct));

    assert(ct->elements[0]->type == ACT_EL_VALUE);

    asn1p_value_t *val = ct->elements[0]->value;
    if(val->type == ATV_VALUESET && val->value.constraint->type == ACT_EL_TYPE) {
        asn1p_value_t *csub = val->value.constraint->containedSubtype;
        if(!csub) {
            /* Ignore */
        } else if(csub->type == ATV_REFERENCED) {
            return csub->value.reference;
        } else if(csub->type == ATV_TYPE) {
            if(csub->value.v_type->expr_type == A1TC_REFERENCE) {
                assert(csub->value.v_type->reference);
                return csub->value.v_type->reference;
            }
        }
    }
    if(val->type != ATV_REFERENCED) {
        FATAL("Set reference: %s", asn1f_printable_value(val));
        assert(val->type == ATV_REFERENCED);
    }

    return val->value.reference;
}

static asn1c_ioc_table_and_objset_t
asn1c_get_ioc_table_from_objset(arg_t *arg, const asn1p_ref_t *objset_ref, asn1p_expr_t *objset) {
    asn1c_ioc_table_and_objset_t ioc_tao = { 0, 0, 1 };

    (void)objset_ref;

    if(objset->ioc_table) {
        ioc_tao.ioct = objset->ioc_table;
        ioc_tao.objset = objset;
        ioc_tao.fatal_error = 0;
    } else {
        FATAL("Information Object Set %s contains no objects at line %d",
              objset->Identifier, objset->_lineno);
    }

    return ioc_tao;
}

asn1c_ioc_table_and_objset_t
asn1c_get_ioc_table(arg_t *arg) {
    asn1p_expr_t *expr = arg->expr;
	asn1p_expr_t *memb;
    asn1p_expr_t *objset = 0;
    const asn1p_ref_t *objset_ref = NULL;
    asn1c_ioc_table_and_objset_t safe_ioc_tao = {0, 0, 0};
    asn1c_ioc_table_and_objset_t failed_ioc_tao = { 0, 0, 1 };

    TQ_FOR(memb, &(expr->members), next) {
        const asn1p_constraint_t *cr_ct =
            asn1p_get_component_relation_constraint(memb->constraints);
        const asn1p_ref_t *tmpref =
            asn1c_get_information_object_set_reference_from_constraint(arg,
                                                                       cr_ct);
        if(tmpref) {
            if(objset_ref && asn1p_ref_compare(objset_ref, tmpref) != 0) {
                FATAL(
                    "Object set reference on line %d differs from object set "
                    "reference on line %d",
                    objset_ref->_lineno, tmpref->_lineno);
                return failed_ioc_tao;
            }
            objset_ref = tmpref;
        }

    }

    if(!objset_ref) {
        return safe_ioc_tao;
    }

    objset = WITH_MODULE_NAMESPACE(
        arg->expr->module, expr_ns,
        asn1f_lookup_symbol_ex(arg->asn, expr_ns, arg->expr, objset_ref));
    if(!objset) {
        FATAL("Cannot found %s", asn1p_ref_string(objset_ref));
        return failed_ioc_tao;
    }

    return asn1c_get_ioc_table_from_objset(arg, objset_ref, objset);
}

static int
emit_ioc_value(arg_t *arg, struct asn1p_ioc_cell_s *cell) {

    if(cell->value && cell->value->meta_type == AMT_VALUE) {
        const char *prim_type = NULL;
        int primitive_representation = 0;

        asn1p_expr_t *cv_type =
            asn1f_find_terminal_type_ex(arg->asn, arg->ns, cell->value);

        switch(cv_type->expr_type) {
        case ASN_BASIC_INTEGER:
        case ASN_BASIC_ENUMERATED:
            switch(asn1c_type_fits_long(arg, cell->value /* sic */)) {
            case FL_NOTFIT:
                GEN_INCLUDE_STD("INTEGER");
                prim_type = "INTEGER_t";
                break;
            case FL_PRESUMED:
            case FL_FITS_SIGNED:
                primitive_representation = 1;
                prim_type = "long";
                break;
            case FL_FITS_UNSIGN:
                prim_type = "unsigned long";
                primitive_representation = 1;
                break;
            }
            break;
        case ASN_BASIC_OBJECT_IDENTIFIER:
            prim_type = "OBJECT_IDENTIFIER_t";
            break;
        case ASN_BASIC_RELATIVE_OID:
            prim_type = "RELATIVE_OID_t";
            break;
        default: {
            char *p = strdup(MKID(cell->value));
            FATAL("Unsupported type %s for value %s",
                  asn1c_type_name(arg, cell->value, TNF_UNMODIFIED), p);
            free(p);
            return -1;
        }
        }
        OUT("static const %s asn_VAL_%d_%s = ", prim_type,
            cell->value->_type_unique_index, MKID(cell->value));

        asn1p_expr_t *expr_value = cell->value;
        while(expr_value->value->type == ATV_REFERENCED) {
            expr_value = WITH_MODULE_NAMESPACE(
                expr_value->module, expr_ns,
                asn1f_lookup_symbol_ex(arg->asn, expr_ns, expr_value,
                                       expr_value->value->value.reference));
            if(!expr_value) {
                FATAL("Unrecognized value type for %s", MKID(cell->value));
                return -1;
            }
        }

        if(!primitive_representation) OUT("{ ");

        switch(expr_value->value->type) {
        case ATV_INTEGER:
            if(primitive_representation) {
                OUT("%s", asn1p_itoa(expr_value->value->value.v_integer));
                break;
            } else {
                asn1c_integer_t v = expr_value->value->value.v_integer;
                if(v >= 0) {
                    if(v <= 127) {
                        OUT("\"\\x%02x\", 1", (int)v);
                        break;
                    } else if(v <= 32767) {
                        OUT("\"\\x%02x\\x%02x\", 2", (int)(v >> 8), (int)(v & 0xff));
                        break;
                    }
                }
                FATAL("Unsupported value %s range for type %s",
                      asn1f_printable_value(expr_value->value),
                      MKID(cell->value));
                return -1;
            }
        case ATV_UNPARSED:
            OUT("\"not supported\", 0 };\n");
            FATAL("Inappropriate value %s for type %s",
                  asn1f_printable_value(expr_value->value), MKID(cell->value));
            return 0;   /* TEMPORARY FIXME FIXME */
        default:
            FATAL("Inappropriate value %s for type %s",
                  asn1f_printable_value(expr_value->value), MKID(cell->value));
            return -1;
        }

        if(primitive_representation) {
            OUT(";\n");
        } else {
            OUT(" };");
            OUT(" /* %s */\n", asn1f_printable_value(expr_value->value));
        }
    }

    return 0;
}

static int
emit_ioc_cell(arg_t *arg, struct asn1p_ioc_cell_s *cell) {
    OUT("{ \"%s\", ", cell->field->Identifier);

    if(!cell->value) {
        /* Ignore */
    } else if(cell->value->meta_type == AMT_VALUE) {
        GEN_INCLUDE(asn1c_type_name(arg, cell->value, TNF_INCLUDE));
        OUT("aioc__value, ");
        OUT("&asn_DEF_%s, ", asn1c_type_name(arg, cell->value, TNF_SAFE));
        OUT("&asn_VAL_%d_%s", cell->value->_type_unique_index,
            MKID(cell->value));

    } else if(cell->value->meta_type == AMT_TYPEREF) {
        GEN_INCLUDE(asn1c_type_name(arg, cell->value, TNF_INCLUDE));
        OUT("aioc__type, &asn_DEF_%s", MKID(cell->value));
    } else {
        return -1;
    }

    OUT(" }");

    return 0;
}

/*
 * Refer to skeletons/asn_ioc.h
 */
int
emit_ioc_table(arg_t *arg, asn1p_expr_t *context, asn1c_ioc_table_and_objset_t ioc_tao) {
    size_t columns = 0;

    (void)context;
    GEN_INCLUDE_STD("asn_ioc");

    REDIR(OT_IOC_TABLES);

    /* Emit values that are used in the Information Object Set table first */
    for(size_t rn = 0; rn < ioc_tao.ioct->rows; rn++) {
        asn1p_ioc_row_t *row = ioc_tao.ioct->row[rn];
        for(size_t cn = 0; cn < row->columns; cn++) {
            if(emit_ioc_value(arg, &row->column[cn])) {
                return -1;
            }
        }
    }

    /* Emit the Information Object Set */
    OUT("static const asn_ioc_cell_t asn_IOS_%s_%d_rows[] = {\n",
        MKID(ioc_tao.objset), ioc_tao.objset->_type_unique_index);
    INDENT(+1);

    for(size_t rn = 0; rn < ioc_tao.ioct->rows; rn++) {
        asn1p_ioc_row_t *row = ioc_tao.ioct->row[rn];
        columns = columns ? columns : row->columns;
        if(columns != row->columns) {
            FATAL("Information Object Set %s row column mismatch on line %d",
                  ioc_tao.objset->Identifier, ioc_tao.objset->_lineno);
            return -1;
        }
        for(size_t cn = 0; cn < row->columns; cn++) {
            if(rn || cn) OUT(",\n");
            emit_ioc_cell(arg, &row->column[cn]);
        }
    }
    OUT("\n");

    INDENT(-1);
    OUT("};\n");

    OUT("static const asn_ioc_set_t asn_IOS_%s_%d[] = {\n",
        MKID(ioc_tao.objset), ioc_tao.objset->_type_unique_index);
    INDENT(+1);
    OUT("%zu, %zu, asn_IOS_%s_%d_rows\n", ioc_tao.ioct->rows, columns,
        MKID(ioc_tao.objset), ioc_tao.objset->_type_unique_index);
    INDENT(-1);
    OUT("};\n");

    return 0;
}

