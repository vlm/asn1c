
SUBDIRS = . tests webcgi

AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS = \
	-I${top_srcdir}/libasn1compiler	\
	-I${top_srcdir}/libasn1parser	\
	-I${top_srcdir}/libasn1print	\
	-I${top_srcdir}/libasn1fix	\
	-I${top_srcdir}/skeletons	\
	-DDATADIR=\"$(pkgdatadir)\"

LDADD =	\
	$(top_builddir)/libasn1parser/libasn1parser.la	\
	$(top_builddir)/libasn1print/libasn1print.la	\
	$(top_builddir)/libasn1fix/libasn1fix.la	\
	$(top_builddir)/libasn1compiler/libasn1compiler.la

asn1c_SOURCES = asn1c.c	\
	tlv_decoder.c tlv_decoder.h

bin_PROGRAMS = asn1c

dist_man1_MANS = asn1c.1

check_SCRIPTS = check-parsing.sh
TESTS = check-parsing.sh
EXTRA_DIST = check-parsing.sh
CLEANFILES = .check-parsing.*.tmp
