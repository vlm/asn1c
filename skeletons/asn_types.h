/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * Miscellaneous system-dependent types.
 */
#ifndef	_ASN_TYPES_H_
#define	_ASN_TYPES_H_

#ifdef	HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>	/* For fprintf() */
#include <stdlib.h>	/* For *alloc(3) */
#include <string.h>	/* For memcpy(3) */
#include <sys/types.h>	/* For size_t */
#include <stdarg.h>	/* For va_start */
#include <stddef.h>	/* for offsetof and ptrdiff_t */

#include <inttypes.h>	/* C99 specifies this file */

/*
 * Earlier FreeBSD version didn't have <stdint.h>,
 * but <inttypes.h> was present.
 */
#if	!defined(__FreeBSD__) || !defined(_SYS_INTTYPES_H_) /* Workaround */
#include <stdint.h>	/* SUSv2+ and C99 specify this file, for uintXX_t */
#endif

#ifdef	WIN32
#define	 snprintf	_snprintf
#define	 vsnprintf	_vsnprintf
#define	alloca(size)	_alloca(size)
#endif	/* WIN32 */

#ifndef	__GNUC__
#define	__attribute__(ignore)
#endif

#ifndef	offsetof	/* If not defined by <stddef.h> */
#define	offsetof(s, m)	((ptrdiff_t)&(((s *)0)->m) - (ptrdiff_t)((s *)0))
#endif	/* offsetof */

#ifndef	MIN		/* Suitable for comparing primitive types (integers) */
#if defined(__GNUC__)
#define	MIN(a,b)	({ __typeof a _a = a; __typeof b _b = b;	\
	((_a)<(_b)?(_a):(_b)); })
#else	/* !__GNUC__ */
#define	MIN(a,b)	((a)<(b)?(a):(b))	/* Unsafe variant */
#endif /* __GNUC__ */
#endif	/* MIN */

/*
 * Generic type of an application-defined callback to return various
 * types of data to the application.
 * EXPECTED RETURN VALUES:
 *  -1: Failed to consume bytes. Abort the mission.
 * Other return values indicate success, and ignored.
 */
typedef int (asn_app_consume_bytes_f)(const void *buffer, size_t size,
	void *application_specific_key);

#endif	/* _ASN_TYPES_H_ */
