
AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS = -I${top_srcdir}/libasn1parser

noinst_LTLIBRARIES = libasn1print.la

libasn1print_la_LDFLAGS = -all-static
libasn1print_la_SOURCES =			\
	asn1print.c asn1print.h

LDADD = ${noinst_LTLIBRARIES} ${libasn1fix_la_LIBADD}
DEPENDENCIES = ${LDADD} 

TESTS = ${check_PROGRAMS}
