
AM_CPPFLAGS =	\
	-I${top_srcdir}/libasn1parser	\
	-I${top_srcdir}/libasn1fix

noinst_LTLIBRARIES = libasn1compiler.la

libasn1compiler_la_LDFLAGS = -all-static
libasn1compiler_la_SOURCES =			\
	asn1compiler.c asn1compiler.h		\
	asn1c_misc.c asn1c_misc.h		\
	asn1c_out.c asn1c_out.h			\
	asn1c_lang.c asn1c_lang.h		\
	asn1c_save.c asn1c_save.h		\
	asn1c_C.c asn1c_C.h			\
	asn1c_compat.c asn1c_compat.h		\
	asn1c_internal.h

libasn1compiler_la_LIBADD =				\
	${top_builddir}/libasn1parser/libasn1parser.la	\
	${top_builddir}/libasn1fix/libasn1fix.la

check_PROGRAMS = check_compiler

TESTS = ${check_PROGRAMS}

LDADD = ${noinst_LTLIBRARIES} ${libasn1compiler_la_LIBADD}
DEPENDENCIES = ${LDADD} 

