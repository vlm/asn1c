/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * Miscellaneous system-dependent types.
 */
#ifndef	_ASN_TYPES_H_
#define	_ASN_TYPES_H_

#include <stdio.h>	/* For fprintf() */
#include <stdlib.h>	/* For *alloc(3) */
#include <string.h>	/* For memcpy(3) */
#include <sys/types.h>	/* For size_t */
#include <stdarg.h>	/* For va_start */
#include <stddef.h>	/* for offsetof and ptrdiff_t */
#include <stdint.h>	/* SUSv2+ and C99 specify this file, for uintXX_t */

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

#define	CALLOC(nmemb, size)	calloc(nmemb, size)
#define	MALLOC(size)		malloc(size)
#define	REALLOC(oldptr, size)	realloc(oldptr, size)
#define	FREEMEM(ptr)		free(ptr)

#ifndef	MIN		/* Suitable for comparing primitive types (integers) */
#if defined(__GNUC__)
#define	MIN(a,b)	({ __typeof a _a = a; __typeof b _b = b;	\
	((_a)<(_b)?(_a):(_b)); })
#else	/* !__GNUC__ */
#define	MIN(a,b)	((a)<(b)?(a):(b))	/* Unsafe variant */
#endif /* __GNUC__ */
#endif	/* MIN */

/*
 * A macro for debugging the ASN.1 internals.
 * You may enable or override it.
 */
#ifndef	ASN_DEBUG	/* If debugging code is not defined elsewhere... */
#if	EMIT_ASN_DEBUG == 1	/* And it was asked to emit this code... */
#ifdef	__GNUC__
#define	ASN_DEBUG(fmt, args...)	do {		\
		fprintf(stderr, fmt, ##args);	\
		fprintf(stderr, "\n");		\
	} while(0)
#else	/* !__GNUC__ */
extern void ASN_DEBUG_f(const char *fmt, ...);
#define	ASN_DEBUG	ASN_DEBUG_f
#endif	/* __GNUC__ */
#else	/* EMIT_ASN_DEBUG != 1 */
#ifdef	__GNUC__
#define	ASN_DEBUG(fmt, args...)	((void)0)	/* Emit a no-op operator */
#else	/* __GNUC__ */
static void ASN_DEBUG(const char *fmt, ...) { (void)fmt; };
#endif	/* __GNUC__ */
#endif	/* EMIT_ASN_DEBUG */
#endif	/* ASN_DEBUG */


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
