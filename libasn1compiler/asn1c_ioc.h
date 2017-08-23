#ifndef	ASN1_IOC_H
#define	ASN1_IOC_H

#include "asn1compiler.h"
#include "asn1p_class.h"

typedef struct asn1c_ioc_table_and_objset_s {
    asn1p_ioc_table_t *ioct;
    asn1p_expr_t *objset;
    int fatal_error; /* if ioct == NULL then specifies error or 0. */
} asn1c_ioc_table_and_objset_t;

asn1c_ioc_table_and_objset_t asn1c_get_ioc_table(arg_t *arg);

int emit_ioc_table(arg_t *arg, asn1p_expr_t *context,
                    asn1c_ioc_table_and_objset_t);

const asn1p_ref_t *asn1c_get_information_object_set_reference_from_constraint(
    arg_t *arg, const asn1p_constraint_t *ct);


#endif	/* ASN1_IOC_H */
