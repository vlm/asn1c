/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#ifndef	_UTCTime_H_
#define	_UTCTime_H_

#include <constr_TYPE.h>
#include <OCTET_STRING.h>

typedef OCTET_STRING_t UTCTime_t;  /* Implemented using OCTET STRING */

extern asn1_TYPE_descriptor_t asn1_DEF_UTCTime;

asn_constr_check_f UTCTime_constraint;
asn_struct_print_f UTCTime_print;

/***********************
 * Some handy helpers. *
 ***********************/

struct tm;	/* <time.h> */

/* See asn_GT2time() in GeneralizedTime.h */
time_t asn_UT2time(const UTCTime_t *, struct tm *_optional_tm4fill, int as_gmt);

/* See asn_time2GT() in GeneralizedTime.h */
UTCTime_t *asn_time2UT(UTCTime_t *__opt_ut, const struct tm *, int force_gmt);

#endif	/* _UTCTime_H_ */
