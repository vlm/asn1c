AC_INIT([asn1c], [0.9.28], [vlm@lionet.info])

AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([-Wall -Wno-extra-portability -Werror foreign])
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
LT_INIT
AC_CONFIG_MACRO_DIR([m4])

AM_MAINTAINER_MODE
AM_PROG_AR
AM_PROG_LIBTOOL

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_YACC
AM_PROG_LEX
AC_PATH_PROG(AR, ar, ar, $PATH:/usr/ucb:/usr/ccs/bin)	dnl for Solaris

dnl If you need to see the details, just run make V=1.
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

case "$host_os" in
cygwin)
	case "$target" in
	*mingw*)
		CC="$CC -mno-cygwin"
	esac
	;;
esac

AC_ARG_ENABLE(Werror,
  [AS_HELP_STRING([--enable-Werror],
                  [abort compilation after any C compiler warning])],
  [enable_werror=$enableval], [enable_werror=no])
  AS_IF([test x$enable_werror != xno], [
      TESTSUITE_CFLAGS="-Werror -W -Wpointer-arith"
      ADD_CFLAGS="-Werror -W -Wpointer-arith"
  ])

AC_ARG_ENABLE([ASN_DEBUG],
  [AS_HELP_STRING([--enable-ASN_DEBUG],
                  [produce debug log during `make check` testing])],
  [enable_asn_debug=$enableval], [enable_asn_debug=no])
  AS_IF([test x$enable_asn_debug != xno], [
      TESTSUITE_CFLAGS="-DEMIT_ASN_DEBUG"
  ])

AX_CHECK_COMPILE_FLAG([-Wall], [CFLAGS="$CFLAGS -Wall"])
AX_CHECK_COMPILE_FLAG([-Wcast-qual], [CFLAGS="$CFLAGS -Wcast-qual"])
AX_CHECK_COMPILE_FLAG([-Wchar-subscripts],
      [CFLAGS="$CFLAGS -Wchar-subscripts"])
AX_CHECK_COMPILE_FLAG([-Wmissing-prototypes],
      [CFLAGS="$CFLAGS -Wmissing-prototypes"])
AX_CHECK_COMPILE_FLAG([-Wmissing-declarations],
      [CFLAGS="$CFLAGS -Wmissing-declarations"])

dnl There are legitimate uses for these features, disable warnings/errors.
AX_CHECK_COMPILE_FLAG([-Wno-error=cast-align],
      [CFLAGS="$CFLAGS -Wno-error=cast-align"])
AX_CHECK_COMPILE_FLAG([-Wno-error=visibility],
      [CFLAGS="$CFLAGS -Wno-error=visibility"])
AX_CHECK_COMPILE_FLAG([-Wno-error=parentheses-equality],
      [CFLAGS="$CFLAGS -Wno-error=parentheses-equality"])
AX_CHECK_COMPILE_FLAG([-Wno-error=unused-variable],
      [TESTSUITE_CFLAGS="$TESTSUITE_CFLAGS -Wno-error=unused-variable"])

AC_SUBST(ADD_CFLAGS)
AC_SUBST(TESTSUITE_CFLAGS)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(sys/param.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_CHECK_TYPE(intmax_t, int64_t)

dnl Test if we should check features that depend on 64-bitness.
AC_MSG_CHECKING(size of long is longer than 32 bit)
AS_VAR_PUSHDEF([WIDE_LONG], [WIDE_LONG])
AC_TRY_COMPILE([#include "confdefs.h"
#include <sys/types.h>
], [switch (0) case 0: case (sizeof ($1) >= 8):;],
    WIDE_LONG=yes, WIDE_LONG=no)
AC_MSG_RESULT($WIDE_LONG)
AM_CONDITIONAL([TEST_64BIT], [test x$WIDE_LONG = xyes])
AS_VAR_POPDEF([WIDE_LONG])

dnl For mingw
AC_SEARCH_LIBS(getopt, iberty)

AC_CHECK_FUNCS(strtoimax strtoll)
AC_CHECK_FUNCS(mergesort)
AC_CHECK_FUNCS(mkstemps)
AC_CHECK_FUNCS(timegm)
AC_CHECK_DECLS(alloca strcasecmp)
AC_TRY_LINK_FUNC([symlink],[AC_DEFINE([HAVE_SYMLINK], 1, [Define to 1 if you have the symlink function.])])

AC_OUTPUT(				\
skeletons/tests/Makefile		\
libasn1compiler/Makefile		\
libasn1parser/Makefile			\
libasn1print/Makefile			\
asn1c/tests/Makefile			\
libasn1fix/Makefile			\
doc/docsrc/Makefile			\
skeletons/Makefile			\
examples/Makefile			\
asn1c/Makefile				\
doc/Makefile				\
asn1c.spec				\
Makefile				\
)

