@CODE_COVERAGE_RULES@

AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS =                       \
    -I${top_srcdir}/libasn1common   \
    -I${top_srcdir}/libasn1parser   \
    -I${top_srcdir}/skeletons

unber_LDADD = $(top_builddir)/libasn1common/libasn1common.la

bin_PROGRAMS = unber
