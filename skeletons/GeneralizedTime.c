/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <GeneralizedTime.h>
#include <time.h>
#include <errno.h>
#ifndef	__NO_ASSERT_H__
#include <assert.h>
#endif	/* __NO_ASSERT_H__ */

#ifndef	__NO_ASN_TABLE__

/*
 * GeneralizedTime basic type description.
 */
static ber_tlv_tag_t asn1_DEF_GeneralizedTime_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (24 << 2))
};
asn1_TYPE_descriptor_t asn1_DEF_GeneralizedTime = {
	"GeneralizedTime",
	GeneralizedTime_constraint, /* Check validity of time */
	OCTET_STRING_decode_ber,    /* Implemented in terms of OCTET STRING */
	OCTET_STRING_encode_der,    /* Implemented in terms of OCTET STRING */
	GeneralizedTime_print,
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_GeneralizedTime_tags,
	sizeof(asn1_DEF_GeneralizedTime_tags)
	  / sizeof(asn1_DEF_GeneralizedTime_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
};

#endif	/* __NO_ASN_TABLE__ */

/*
 * Check that the time looks like the time.
 */
int
GeneralizedTime_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	const GeneralizedTime_t *st = sptr;
	time_t tloc;

	errno = EPERM;			/* Just an unlikely error code */
	tloc = asn_GT2time(st, 0);
	if(tloc == -1 && errno != EPERM) {
		_ASN_ERRLOG("%s: Invalid time format: %s",
			td->name, strerror(errno));
		return -1;
	}

	return 0;
}

int
GeneralizedTime_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const GeneralizedTime_t *st = sptr;

	if(st && st->buf) {
		char buf[32];
		struct tm tm;
		int ret;

		errno = EPERM;
		if(asn_GT2time(st, &tm) == -1 && errno != EPERM)
			return cb("<bad-value>", 11, app_key);

		ret = snprintf(buf, sizeof(buf),
			"%04d-%02d-%02d %02d:%02d%02d",
			tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
			tm.tm_hour, tm.tm_min, tm.tm_sec);
		assert(ret > 0 && ret < sizeof(buf));
		return cb(buf, ret, app_key);
	} else {
		return cb("<absent>", 8, app_key);
	}
}

/*
 * Where to look for offset from GMT, Phase I.
 * Several platforms are known.
 */
#if defined(__FreeBSD__) || (defined(__GNUC__) && defined(__APPLE_CC__))
#undef	HAVE_TM_ZONE
#define	HAVE_TM_ZONE
#endif	/* BSDs */

/*
 * Where to look for offset from GMT, Phase II.
 */
#ifdef	HAVE_TM_ZONE
#define	GMTOFF	(tm_s.tm_gmtoff)
#else	/* HAVE_TM_ZONE */
#define	GMTOFF	(-timezone)
#endif	/* HAVE_TM_ZONE */

time_t
asn_GT2time(const GeneralizedTime_t *st, struct tm *_tm) {
	struct tm tm_s;
	uint8_t *buf;
	uint8_t *end;
	int tm_gmtoff_h = 0;
	int tm_gmtoff_m = 0;
	int tm_gmtoff = 0;	/* h + m */
	int offset_specified = 0;
	time_t tloc;

	if(!st || !st->buf) {
		errno = EINVAL;
		return -1;
	} else {
		buf = st->buf;
		end = buf + st->size;
	}

	if(st->size < 10) {
		errno = EINVAL;
		return -1;
	}

	/*
	 * Decode first 10 bytes: "AAAAMMJJhh"
	 */
	memset(&tm_s, 0, sizeof(tm_s));
#undef	B2F
#undef	B2T
#define	B2F(var)	do {					\
		unsigned ch = *buf;				\
		if(ch < 0x30 && ch > 0x39) {			\
			errno = EINVAL;				\
			return -1;				\
		} else {					\
			var = var * 10 + (ch - 0x30);		\
			buf++;					\
		}						\
	} while(0)
#define	B2T(var)	B2F(tm_s.var)

	B2T(tm_year);	/* 1: A */
	B2T(tm_year);	/* 2: A */
	B2T(tm_year);	/* 3: A */
	B2T(tm_year);	/* 4: A */
	B2T(tm_mon);	/* 5: M */
	B2T(tm_mon);	/* 6: M */
	B2T(tm_mday);	/* 7: J */
	B2T(tm_mday);	/* 8: J */
	B2T(tm_hour);	/* 9: h */
	B2T(tm_hour);	/* 0: h */

	if(buf == end) goto local_finish;

	/*
	 * Parse [mm[ss[(.|,)ffff]]]
	 *        ^^
	 */
	switch(*buf) {
	case 0x30: case 0x31: case 0x32: case 0x33: case 0x34:
	case 0x35: case 0x36: case 0x37: case 0x38: case 0x39:
		tm_s.tm_min = (*buf++) - 0x30;
		if(buf == end) { errno = EINVAL; return -1; }
		B2T(tm_min);
		break;
	case 0x2B: case 0x2D:	/* +, - */
		goto offset;
	case 0x5A:		/* Z */
		goto utc_finish;
	default:
		errno = EINVAL;
		return -1;
	}

	if(buf == end) goto local_finish;

	/*
	 * Parse [mm[ss[(.|,)ffff]]]
	 *           ^^
	 */
	switch(*buf) {
	case 0x30: case 0x31: case 0x32: case 0x33: case 0x34:
	case 0x35: case 0x36: case 0x37: case 0x38: case 0x39:
		tm_s.tm_sec = (*buf++) - 0x30;
		if(buf == end) { errno = EINVAL; return -1; }
		B2T(tm_sec);
		break;
	case 0x2B: case 0x2D:	/* +, - */
		goto offset;
	case 0x5A:		/* Z */
		goto utc_finish;
	default:
		errno = EINVAL;
		return -1;
	}

	if(buf == end) goto local_finish;

	/*
	 * Parse [mm[ss[(.|,)ffff]]]
	 *               ^ ^
	 */
	switch(*buf) {
	case 0x2C: case 0x2E:	/* (.|,) */
		/* Fractions of seconds are not supported
		 * by time_t or struct tm. Skip them */
		for(buf++; buf < end; buf++) {
			switch(*buf) {
			case 0x30: case 0x31: case 0x32: case 0x33: case 0x34:
			case 0x35: case 0x36: case 0x37: case 0x38: case 0x39:
				continue;
			default:
				break;
			}
			break;
		}
	}

	if(buf == end) goto local_finish;

	switch(*buf) {
	case 0x2B: case 0x2D:	/* +, - */
		goto offset;
	case 0x5A:		/* Z */
		goto utc_finish;
	default:
		errno = EINVAL;
		return -1;
	}


offset:

	if(end - buf < 3) {
		errno = EINVAL;
		return -1;
	}
	buf++;
	B2F(tm_gmtoff_h);
	B2F(tm_gmtoff_h);
	if(buf[-3] == 0x2D)	/* Negative */
		tm_gmtoff = -1;
	else
		tm_gmtoff = 1;

	if((end - buf) == 2) {
		B2F(tm_gmtoff_m);
		B2F(tm_gmtoff_m);
	} else if(end != buf) {
		errno = EINVAL;
		return -1;
	}

	tm_gmtoff = tm_gmtoff * (3600 * tm_gmtoff_h + 60 * tm_gmtoff_m);

	/* Fall through */
utc_finish:

	offset_specified = 1;

	/* Fall through */
local_finish:

	/*
	 * Validation.
	 */
	if((tm_s.tm_mon > 12 || tm_s.tm_mon < 1)
	|| (tm_s.tm_mday > 31 || tm_s.tm_mday < 1)
	|| (tm_s.tm_hour > 23)
	|| (tm_s.tm_sec > 60)
	) {
		errno = EINVAL;
		return -1;
	}

	/* Canonicalize */
	tm_s.tm_mon -= 1;	/* 0 - 11 */
	tm_s.tm_year -= 1900;
	tm_s.tm_isdst = -1;

	tloc = mktime(&tm_s);
	if(tloc == -1) {
		errno = EINVAL;
		return -1;
	}

	if(offset_specified) {
		/*
		 * Offset from GMT is specified in the time expression.
		 */
		tloc += GMTOFF - tm_gmtoff;
		if(_tm && (localtime_r(&tloc, &tm_s) == NULL)) {
			/* Could not reconstruct the time */
			return -1;
		}
	}

	if(_tm) memcpy(_tm, &tm_s, sizeof(struct tm));

	return tloc;
}

