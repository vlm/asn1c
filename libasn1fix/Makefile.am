
AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS =				\
	-I$(top_srcdir)/libasn1parser

noinst_LTLIBRARIES = libasn1fix.la

libasn1fix_la_LDFLAGS = -all-static
libasn1fix_la_SOURCES =					\
	asn1fix.c asn1fix.h				\
	asn1fix_internal.h				\
	asn1fix_misc.c asn1fix_misc.h			\
	asn1fix_value.c asn1fix_value.h			\
	asn1fix_compat.c asn1fix_compat.h		\
	asn1fix_constr.c asn1fix_constr.h		\
	asn1fix_cstring.c asn1fix_cstring.h		\
	asn1fix_retrieve.c asn1fix_retrieve.h		\
	asn1fix_bitstring.c asn1fix_bitstring.h		\
	asn1fix_constraint.c asn1fix_constraint.h	\
	asn1fix_integer.c asn1fix_integer.h		\
	asn1fix_crange.c asn1fix_crange.h		\
	asn1fix_dereft.c asn1fix_dereft.h		\
	asn1fix_derefv.c asn1fix_derefv.h		\
	asn1fix_export.c asn1fix_export.h		\
	asn1fix_param.c asn1fix_param.h			\
	asn1fix_class.c asn1fix_class.h			\
	asn1fix_tags.c asn1fix_tags.h			\
	asn1fix_enum.c asn1fix_enum.h			\
	asn1fix_cws.c asn1fix_cws.h			\
	asn1fix_constraint_compat.c

check_PROGRAMS = check_fixer

check_fixer_LDADD = $(noinst_LTLIBRARIES)		\
	$(top_builddir)/libasn1parser/libasn1parser.la
check_fixer_DEPENDENCIES = $(check_fixer_LDADD)

TESTS_ENVIRONMENT= ./check_fixer
TESTS = ${top_srcdir}/tests/*.asn1
## TESTS = ${check_PROGRAMS}	# This is an alternate form of testing

