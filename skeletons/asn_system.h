/*-
 * Copyright (c) 2003, 2004 Lev Walkin <vlm@lionet.info>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
/*
 * Miscellaneous system-dependent types.
 */
#ifndef	_ASN_SYSTEM_H_
#define	_ASN_SYSTEM_H_

#ifdef	HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>	/* For snprintf(3) */
#include <stdlib.h>	/* For *alloc(3) */
#include <string.h>	/* For memcpy(3) */
#include <sys/types.h>	/* For size_t */
#include <stdarg.h>	/* For va_start */
#include <stddef.h>	/* for offsetof and ptrdiff_t */

#ifdef	WIN32

#define	 snprintf	_snprintf
#define	 vsnprintf	_vsnprintf
#define	alloca(size)	_alloca(size)

#ifdef _MSC_VER			/* MSVS.Net */
#ifndef __cplusplus
#define inline __inline
#endif
#define	ssize_t		SSIZE_T
typedef	char		int8_t;
typedef	short		int16_t;
typedef	int		int32_t;
typedef	unsigned char	uint8_t;
typedef	unsigned short	uint16_t;
typedef	unsigned int	uint32_t;
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <float.h>
#define isnan _isnan
#define finite _finite
#define copysign _copysign
#define	ilogb	_logb
#endif	/* _MSC_VER */

#else	/* !WIN32 */

#include <inttypes.h>	/* C99 specifies this file */
/*
 * 1. Earlier FreeBSD version didn't have <stdint.h>,
 * but <inttypes.h> was present.
 * 2. Sun Solaris requires <alloca.h> for alloca(3),
 * but does not have <stdint.h>.
 */
#if	(!defined(__FreeBSD__) || !defined(_SYS_INTTYPES_H_))
#if	defined(sun)
#include <alloca.h>	/* For alloca(3) */
#include <ieeefp.h>	/* for finite(3) */
#else
#include <stdint.h>	/* SUSv2+ and C99 specify this file, for uintXX_t */
#endif	/* defined(sun) */
#endif

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

#endif	/* _ASN_SYSTEM_H_ */
