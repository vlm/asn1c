/*-
 * Copyright (c) 2005 Lev Walkin <vlm@lionet.info>. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id$
 */
#ifdef	HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#ifdef	HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef	HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef	HAVE_SYS_STAT_H
#include <sys/stat.h>		/* for stat(2) */
#endif

#ifndef	_WIN32
#include <sysexits.h>		/* for EX_USAGE & others */
#else	/* _WIN32 */
#ifndef	EX_USAGE
#define	EX_USAGE 64
#endif
#ifndef	EX_DATAERR
#define	EX_DATAERR 65
#endif
#ifndef	EX_SOFTWARE
#define	EX_SOFTWARE 70
#endif
#ifndef	EX_OSERR
#define	EX_OSERR 71
#endif
#ifndef	EX_OSFILE
#define	EX_OSFILE 72
#endif
#if defined HAVE_DECL_ALLOCA && !HAVE_DECL_ALLOCA
#define	alloca _alloca
#endif
#define	snprintf _snprintf
#endif	/* _WIN32 */

