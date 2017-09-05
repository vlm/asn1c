#include "asn1c_internal.h"
#include "asn1c_naming.h"
#include "asn1c_misc.h"
#include "asn1c_misc.h"
#include <asn1_buffer.h>

static abuf *
construct_base_name(abuf *buf, arg_t *arg, int compound_names,
                    int avoid_keywords) {
    const char *id;

    if(!buf) buf = abuf_new();

    if(compound_names && arg->expr->parent_expr) {
        arg_t tmparg = *arg;
        tmparg.expr = arg->expr->parent_expr;
        construct_base_name(buf, &tmparg, compound_names, 0);
        if(buf->length) {
            abuf_str(buf, "__"); /* component separator */
        }
    }

    id = asn1c_make_identifier(
        ((avoid_keywords && !buf->length) ? AMI_CHECK_RESERVED : 0), arg->expr,
        0);

    abuf_str(buf, id);

    return buf;
}

static struct c_names
c_name_impl(arg_t *arg, int avoid_keywords) {
    asn1p_expr_type_e expr_type = arg->expr->expr_type;
    struct c_names names;
    int compound_names = 0;

    static abuf b_base_name;
    static abuf b_short_name;
    static abuf b_full_name;
    static abuf b_as_member;
    static abuf b_presence_enum;
    static abuf b_presence_name;
    static abuf b_members_enum;
    static abuf b_members_name;

    abuf_clear(&b_base_name);
    abuf_clear(&b_short_name);
    abuf_clear(&b_full_name);
    abuf_clear(&b_as_member);
    abuf_clear(&b_presence_enum);
    abuf_clear(&b_presence_name);
    abuf_clear(&b_members_enum);
    abuf_clear(&b_members_name);

    if((arg->flags & A1C_COMPOUND_NAMES)) {
        if((expr_type & ASN_CONSTR_MASK)
           || expr_type == ASN_BASIC_ENUMERATED
           || ((expr_type == ASN_BASIC_INTEGER
                || expr_type == ASN_BASIC_BIT_STRING))) {
            compound_names = 1;
        }
    }

    abuf *base_name =
        construct_base_name(NULL, arg, compound_names, avoid_keywords);
    abuf *part_name =
        construct_base_name(NULL, arg, compound_names, 0);
    abuf *member_name =
        construct_base_name(NULL, arg, 0, 1);

    abuf_printf(&b_base_name, "%s", base_name->buffer);
    if(!arg->expr->_anonymous_type) {
        if(arg->embed) {
            abuf_printf(&b_short_name, "%s", member_name->buffer);
        } else {
            abuf_printf(&b_short_name, "%s_t", member_name->buffer);
        }
    }
    abuf_printf(&b_full_name, "struct %s", base_name->buffer);
    abuf_printf(&b_as_member, "%s", member_name->buffer);
    abuf_printf(&b_presence_enum, "enum %s_PR", part_name->buffer);
    abuf_printf(&b_presence_name, "%s_PR", part_name->buffer);
    abuf_printf(&b_members_enum, "enum %s", base_name->buffer);
    abuf_printf(&b_members_name, "e_%s", part_name->buffer);

    names.base_name = b_base_name.buffer;
    names.short_name = b_short_name.buffer;
    names.full_name = b_full_name.buffer;
    names.as_member = b_as_member.buffer;
    names.presence_enum = b_presence_enum.buffer;
    names.presence_name = b_presence_name.buffer;
    names.members_enum = b_members_enum.buffer;
    names.members_name = b_members_name.buffer;

    abuf_free(base_name);
    abuf_free(part_name);
    abuf_free(member_name);

    return names;
}

struct c_names
c_name(arg_t *arg) {
    return c_name_impl(arg, 1);
}

const char *
c_member_name(arg_t *arg, asn1p_expr_t *expr) {
    static abuf ab;

    abuf_clear(&ab);

    abuf_printf(&ab, "%s_%s", c_name_impl(arg, 0).base_name,
                asn1c_make_identifier(0, expr, 0));

    return ab.buffer;
}


const char *
c_presence_name(arg_t *arg, asn1p_expr_t *expr) {
    static abuf ab;

    abuf_clear(&ab);

    if(expr) {
        abuf_printf(&ab, "%s_PR_%s", c_name_impl(arg, 0).base_name,
                    asn1c_make_identifier(0, expr, 0));
    } else {
        abuf_printf(&ab, "%s_PR_NOTHING", c_name_impl(arg, 0).base_name);
    }

    return ab.buffer;
}


