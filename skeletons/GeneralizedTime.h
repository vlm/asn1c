/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_GeneralizedTime_H_
#define	_GeneralizedTime_H_

#include <constr_TYPE.h>
#include <OCTET_STRING.h>

typedef OCTET_STRING_t GeneralizedTime_t;  /* Implemented using OCTET STRING */

extern asn1_TYPE_descriptor_t asn1_DEF_GeneralizedTime;

asn_constr_check_f GeneralizedTime_constraint;
asn_struct_print_f GeneralizedTime_print;

/***********************
 * Some handy helpers. *
 ***********************/

/* On error returns -1 and errno set to EINVAL */
struct tm;	/* <time.h> */
time_t asn_GT2time(const GeneralizedTime_t *, struct tm *_optional_tm4fill);

#endif	/* _GeneralizedTime_H_ */
