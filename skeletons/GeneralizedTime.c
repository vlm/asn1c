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

#if	defined(WIN32) || defined(__CYGWIN__)
#warning PLEASE STOP AND READ!
#warning	localtime_r is implemented via localtime(), which is not thread-safe.
#warning	gmtime_r is implemented via gmtime(), which is not thread-safe.
#warning
#warning	You must fix the code by inserting appropriate locking
#warning	if you want to use asn_GT2time() or asn_UT2time().
#warning PLEASE STOP AND READ!

static struct tm *localtime_r(const time_t *tloc, struct tm *result) {
	struct tm *tm;
	if((tm = localtime(tloc)))
		return memcpy(result, tm, sizeof(struct tm));
	return 0;
}

static struct tm *gmtime_r(const time_t *tloc, struct tm *result) {
	struct tm *tm;
	if((tm = gmtime(tloc)))
		return memcpy(result, tm, sizeof(struct tm));
	return 0;
}

static time_t timegm(struct tm *tm) {
	time_t tloc;
	char *tz;
	char *buf;

	tz = getenv("TZ");
         _putenv("TZ=UTC");
	_tzset();
	tloc = mktime(tm);
	if (tz) {
		buf = alloca(strlen(tz) + 4);
		sprintf(buf, "TZ=%s", tz);
	} else {
		buf = "TZ=";
	}
	_putenv(buf);
	_tzset();
	return tloc;
}

#if 0	/* Alternate version */
/* vlm: I am not sure about validity of this algorithm. */
static time_t timegm(struct tm *tm) {
	struct tm tmp;
	time_t tloc = mktime(tm);
	localtime_r(&tloc, &tmp);	/* Figure out our GMT offset */
	tloc += tmp.tm_gmtoff;
	tm->tm_zone = "GMT";
	tm->tm_gmtoff = 0;	/* Simulate GMT */
	return tloc;
}
#endif
#endif	/* WIN32 */

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
	GeneralizedTime_encode_der, /* Implemented in terms of OCTET STRING */
	GeneralizedTime_print,
	OCTET_STRING_free,
	0, /* Use generic outmost tag fetcher */
	asn1_DEF_GeneralizedTime_tags,
	sizeof(asn1_DEF_GeneralizedTime_tags)
	  / sizeof(asn1_DEF_GeneralizedTime_tags[0]),
	1,	/* Single UNIVERSAL tag may be implicitly overriden */
	-1,	/* Both ways are fine */
	0, 0,	/* No members */
	0	/* No specifics */
};

#endif	/* __NO_ASN_TABLE__ */

/*
 * Check that the time looks like the time.
 */
int
GeneralizedTime_constraint(asn1_TYPE_descriptor_t *td, const void *sptr,
		asn_app_consume_bytes_f *app_errlog, void *app_key) {
	const GeneralizedTime_t *st = (const GeneralizedTime_t *)sptr;
	time_t tloc;

	errno = EPERM;			/* Just an unlikely error code */
	tloc = asn_GT2time(st, 0, 0);
	if(tloc == -1 && errno != EPERM) {
		_ASN_ERRLOG(app_errlog, app_key,
			"%s: Invalid time format: %s (%s:%d)",
			td->name, strerror(errno), __FILE__, __LINE__);
		return -1;
	}

	return 0;
}

der_enc_rval_t
GeneralizedTime_encode_der(asn1_TYPE_descriptor_t *td, void *ptr,
	int tag_mode, ber_tlv_tag_t tag,
	asn_app_consume_bytes_f *cb, void *app_key) {
	GeneralizedTime_t *st = (GeneralizedTime_t *)ptr;
	der_enc_rval_t erval;

	/* If not canonical DER, re-encode into canonical DER. */
	if(st->size && st->buf[st->size-1] != 'Z') {
		struct tm tm;
		time_t tloc;

		errno = EPERM;
		tloc = asn_GT2time(st, &tm, 1);	/* Recognize time */
		if(tloc == -1 && errno != EPERM) {
			/* Failed to recognize time. Fail completely. */
			erval.encoded = -1;
			erval.failed_type = td;
			erval.structure_ptr = ptr;
			return erval;
		}
		st = asn_time2GT(0, &tm, 1);	/* Save time canonically */
		if(!st) {
			/* Memory allocation failure. */
			erval.encoded = -1;
			erval.failed_type = td;
			erval.structure_ptr = ptr;
			return erval;
		}
	}

	erval = OCTET_STRING_encode_der(td, st, tag_mode, tag, cb, app_key);

	if(st != ptr) {
		FREEMEM(st->buf);
		FREEMEM(st);
	}

	return erval;
}

int
GeneralizedTime_print(asn1_TYPE_descriptor_t *td, const void *sptr, int ilevel,
	asn_app_consume_bytes_f *cb, void *app_key) {
	const GeneralizedTime_t *st = (const GeneralizedTime_t *)sptr;

	(void)td;	/* Unused argument */
	(void)ilevel;	/* Unused argument */

	if(st && st->buf) {
		char buf[32];
		struct tm tm;
		int ret;

		errno = EPERM;
		if(asn_GT2time(st, &tm, 1) == -1 && errno != EPERM)
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

/*
 * Where to look for offset from GMT, Phase I.
 * Several platforms are known.
 */
#if defined(__FreeBSD__)				\
	|| (defined(__GNUC__) && defined(__APPLE_CC__))	\
	|| (defined __GLIBC__ && __GLIBC__ >= 2)
#undef	HAVE_TM_GMTOFF
#define	HAVE_TM_GMTOFF
#endif	/* BSDs and newer glibc */

/*
 * Where to look for offset from GMT, Phase II.
 */
#ifdef	HAVE_TM_GMTOFF
#define	GMTOFF(tm)	((tm).tm_gmtoff)
#else	/* HAVE_TM_GMTOFF */
#define	GMTOFF(tm)	(-timezone)
#endif	/* HAVE_TM_GMTOFF */

time_t
asn_GT2time(const GeneralizedTime_t *st, struct tm *ret_tm, int as_gmt) {
	struct tm tm_s;
	uint8_t *buf;
	uint8_t *end;
	int gmtoff_h = 0;
	int gmtoff_m = 0;
	int gmtoff = 0;	/* h + m */
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
	B2F(gmtoff_h);
	B2F(gmtoff_h);
	if(buf[-3] == 0x2D)	/* Negative */
		gmtoff = -1;
	else
		gmtoff = 1;

	if((end - buf) == 2) {
		B2F(gmtoff_m);
		B2F(gmtoff_m);
	} else if(end != buf) {
		errno = EINVAL;
		return -1;
	}

	gmtoff = gmtoff * (3600 * gmtoff_h + 60 * gmtoff_m);

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

	tm_s.tm_sec -= gmtoff;

	/*** AT THIS POINT tm_s is either GMT or local (unknown) ****/

	if(offset_specified) {
		tloc = timegm(&tm_s);
	} else {
		/*
		 * Without an offset (or 'Z'),
		 * we can only guess that it is a local zone.
		 * Interpret it in this fashion.
		 */
		tloc = mktime(&tm_s);
	}
	if(tloc == -1) {
		errno = EINVAL;
		return -1;
	}

	if(ret_tm) {
		if(as_gmt) {
			if(offset_specified) {
				*ret_tm = tm_s;
			} else {
				if(gmtime_r(&tloc, ret_tm) == 0) {
					errno = EINVAL;
					return -1;
				}
			}
		} else {
			if(localtime_r(&tloc, ret_tm) == 0) {
				errno = EINVAL;
				return -1;
			}
		}
	}

	return tloc;
}


GeneralizedTime_t *
asn_time2GT(GeneralizedTime_t *opt_gt, const struct tm *tm, int force_gmt) {
	struct tm tm_s;
	long gmtoff;
	const unsigned int buf_size = 24; /* 4+2+2 +2+2+2 +4 + cushion */
	char *buf;
	char *p;
	int size;

	/* Check arguments */
	if(!tm) {
		errno = EINVAL;
		return 0;
	}

	/* Pre-allocate a buffer of sufficient yet small length */
	(void *)buf = MALLOC(buf_size);
	if(!buf) return 0;

	gmtoff = GMTOFF(*tm);

	if(force_gmt && gmtoff) {
		tm_s = *tm;
		tm_s.tm_sec -= gmtoff;
		timegm(&tm_s);	/* Fix the time */
		tm = &tm_s;
#ifdef	HAVE_TM_GMTOFF
		assert(!GMTOFF(tm_s));	/* Will fix itself */
#else
		gmtoff = 0;		/* Intervention required */
#endif
	}

	size = snprintf(buf, buf_size, "%04d%02d%02d%02d%02d%02d",
		tm->tm_year + 1900,
		tm->tm_mon + 1,
		tm->tm_mday,
		tm->tm_hour,
		tm->tm_min,
		tm->tm_sec
	);
	assert(size == 14);

	p = buf + size;
	if(force_gmt) {
		*p++ = 0x5a;	/* 'Z' */
		*p++ = 0;
		size++;
	} else {
		int ret = snprintf(p, buf_size - size, "%+03ld%02ld",
			gmtoff / 3600, gmtoff % 3600);
		assert(ret >= 5 && ret <= 7);
		size += ret;
	}

	if(opt_gt) {
		if(opt_gt->buf)
			FREEMEM(opt_gt->buf);
	} else {
		(void *)opt_gt = CALLOC(1, sizeof *opt_gt);
		if(!opt_gt) { free(buf); return 0; }
	}

	opt_gt->buf = (unsigned char *)buf;
	opt_gt->size = size;

	return opt_gt;
}


