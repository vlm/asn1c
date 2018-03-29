#ifndef	ASN1_COMPILER_INTERNAL_H
#define	ASN1_COMPILER_INTERNAL_H

#ifdef	HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>		/* for strlen(3) and memset(3) */
#include <ctype.h>		/* for isalnum(3) */
#include <sys/types.h>		/* for fstat(2) */
#include <limits.h>		/* for PATH_MAX */
#include <stdarg.h>
#include <errno.h>
#include <assert.h>

#ifdef	HAVE_SYS_STAT_H
#include <sys/stat.h>		/* for fstat(2) */
#endif

#ifdef	HAVE_UNISTD_H
#include <unistd.h>		/* for unlink(2) */
#endif

#ifndef PATH_MAX
#define PATH_MAX    1024
#endif

#ifdef	_WIN32
#include <io.h>
#include <malloc.h>
#include <fcntl.h>
#define	open	_open
#define	close	_close
#define	snprintf	_snprintf
#define	vsnprintf	_vsnprintf
#else
#include <glob.h>		/* for glob(3) */
#endif
#include <fcntl.h>		/* for open(2) */

#include "asn1compiler.h"
#include "asn1_namespace.h"

struct asn1c_ioc_table_and_objset_s;

typedef struct arg_s {

	enum asn1c_flags flags;

	void (*logger_cb)(int _severity, const char *fmt, ...);

	int (*default_cb)(struct arg_s *, const struct asn1c_ioc_table_and_objset_s *opt);

	struct compiler_streams *target;

    asn1p_t *asn;
    asn1_namespace_t *ns;
    asn1p_expr_t *expr;

    int embed;
} arg_t;

/*
 * Logging.
 */
#define	LOG(ll, fmt, args...)	do {			\
		arg->logger_cb(ll, fmt, ##args);	\
	} while(0)
#define	DEBUG(fmt, args...)	do {		\
		if(arg->flags & A1C_DEBUG)	\
			LOG(-1, fmt, ##args);	\
	} while(0)
#define	WARNING(fmt, args...)	LOG(0, fmt, ##args);
#define	FATAL(fmt, args...)	LOG(1, fmt, ##args);

#endif	/* ASN1_COMPILER_INTERNAL_H */
