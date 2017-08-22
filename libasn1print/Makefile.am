
AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS =                       \
    -I$(top_srcdir)/libasn1common   \
    -I$(top_srcdir)/libasn1parser   \
    -I$(top_srcdir)/libasn1fix

noinst_LTLIBRARIES = libasn1print.la

libasn1print_la_LIBADD = $(top_builddir)/libasn1common/libasn1common.la
libasn1print_la_SOURCES =           \
    asn1print.c asn1print.h

