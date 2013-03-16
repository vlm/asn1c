AC_INIT([asn1c], [0.9.24], [vlm@lionet.info])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])

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

case "$host_os" in
cygwin)
	case "$target" in
	*mingw*)
		CC="$CC -mno-cygwin"
	esac
	;;
esac

AC_ARG_ENABLE(Werror,
  [  --enable-Werror         abort compilation after any C compiler warning],
	enable_werror=$enableval, enable_werror=no)
if test x$enable_werror = xyes; then
  ADD_CFLAGS="-Werror -W -Wpointer-arith"
fi
AC_SUBST(ADD_CFLAGS)

dnl Add these flags if we're using GCC.
case "$GCC" in
 yes)
   CFLAGS="$CFLAGS -Wall"
   CFLAGS="$CFLAGS -Wshadow"
   CFLAGS="$CFLAGS -Wcast-qual"
   CFLAGS="$CFLAGS -Wcast-align"
   CFLAGS="$CFLAGS -Wchar-subscripts"
   CFLAGS="$CFLAGS -Wmissing-prototypes"
   CFLAGS="$CFLAGS -Wmissing-declarations"
   ;;
esac


dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(sys/param.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_CHECK_TYPE(intmax_t, int64_t)

dnl For mingw
AC_SEARCH_LIBS(getopt, iberty)

AC_CHECK_FUNCS(strtoimax strtoll)
AC_CHECK_FUNCS(mergesort)
AC_CHECK_FUNCS(mkstemps)

AC_OUTPUT(				\
skeletons/standard-modules/Makefile	\
skeletons/tests/Makefile		\
libasn1compiler/Makefile		\
libasn1parser/Makefile			\
libasn1print/Makefile			\
asn1c/tests/Makefile			\
libasn1fix/Makefile			\
doc/docsrc/Makefile			\
skeletons/Makefile			\
examples/Makefile			\
tests/Makefile				\
asn1c/Makefile				\
doc/Makefile				\
asn1c.spec				\
Makefile				\
)

