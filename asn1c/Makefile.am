@CODE_COVERAGE_RULES@

AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS =                       \
    -I${top_srcdir}/libasn1compiler \
    -I${top_srcdir}/libasn1common   \
    -I${top_srcdir}/libasn1parser   \
    -I${top_srcdir}/libasn1print    \
    -I${top_srcdir}/libasn1fix      \
    -I${top_srcdir}/skeletons       \
    -DDATADIR=\"$(pkgdatadir)\"

asn1c_LDADD =                                           \
    $(top_builddir)/libasn1common/libasn1common.la      \
    $(top_builddir)/libasn1parser/libasn1parser.la      \
    $(top_builddir)/libasn1print/libasn1print.la        \
    $(top_builddir)/libasn1fix/libasn1fix.la            \
    $(top_builddir)/libasn1compiler/libasn1compiler.la

bin_PROGRAMS = asn1c
