/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <UTCTime.h>
#include <GeneralizedTime.h>
#include <time.h>
#include <errno.h>
#include <assert.h>

#ifndef	__NO_ASN_TABLE__

/*
 * UTCTime basic type description.
 */
static ber_tlv_tag_t asn1_DEF_UTCTime_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (23 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_UTCTime = {
	"UTCTime",
	UTCTime_constraint,
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	UTCTime_print,
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_UTCTime_tags,
	sizeof(asn1_DEF_UTCTime_tags)
	  / sizeof(asn1_DEF_UTCTime_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
	0	/* No specifics */
};

#endif	/* __NO_ASN_TABLE__ */

/*
 * Check that the time looks like the time.
 */
int
UTCTime_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	const UTCTime_t *st = sptr;
	time_t tloc;

	errno = EPERM;			/* Just an unlikely error code */
	tloc = asn_UT2time(st, 0, 0);
	if(tloc == -1 && errno != EPERM) {
		_ASN_ERRLOG("%s: Invalid time format: %s",
			td->name, strerror(errno));
		return -1;
	}

	return 0;
}

int
UTCTime_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
		asn_app_consume_bytes_f *cb, void *app_key) {
	const UTCTime_t *st = sptr;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(st && st->buf) {
		char buf[32];
		struct tm tm;
		int ret;

		errno = EPERM;
		if(asn_UT2time(st, &tm, 1) == -1 && errno != EPERM)
			return cb("<bad-value>", 11, app_key);

		ret = snprintf(buf, sizeof(buf),
			"%04d-%02d-%02d %02d:%02d%02d (GMT)",
			tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
			tm.tm_hour, tm.tm_min, tm.tm_sec);
		assert(ret > 0 && ret < (int)sizeof(buf));
		return cb(buf, ret, app_key);
	} else {
		return cb("<absent>", 8, app_key);
	}
}

time_t
asn_UT2time(const UTCTime_t *st, struct tm *_tm, int as_gmt) {
	char buf[17+2];	/* "AAMMJJhhmmss+hhmm" = 17, + 2 = 19 */
	GeneralizedTime_t gt;

	if(!st || !st->buf
	|| st->size < 11 || st->size > ((int)sizeof(buf) - 2)) {
		errno = EINVAL;
		return -1;
	}

	gt.buf = buf;
	gt.size = st->size + 2;
	memcpy(gt.buf + 2, st->buf, st->size);
	if(st->buf[0] > 0x35) {
		/* 19xx */
		gt.buf[0] = 0x31;
		gt.buf[1] = 0x39;
	} else {
		/* 20xx */
		gt.buf[0] = 0x32;
		gt.buf[1] = 0x30;
	}

	return asn_GT2time(&gt, _tm, as_gmt);
}

UTCTime_t *
asn_time2UT(UTCTime_t *opt_ut, const struct tm *tm, int force_gmt) {
	GeneralizedTime_t *gt = (GeneralizedTime_t *)opt_ut;

	gt = asn_time2GT(gt, tm, force_gmt);
	if(gt == 0) return 0;

	assert(gt->size >= 2);
	gt->size -= 2;
	memmove(gt->buf, gt->buf + 2, gt->size + 1);

	return (UTCTime_t *)gt;
}

