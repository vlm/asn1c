@CODE_COVERAGE_RULES@

AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS =                       \
    -I${top_srcdir}/libasn1common   \
    -I${top_srcdir}/libasn1parser   \
    -I${top_srcdir}/skeletons

noinst_LTLIBRARIES = libasn1-unber-tool.la

libasn1_unber_tool_la_SOURCES =     \
    libasn1_unber_tool.c libasn1_unber_tool.h

unber_LDADD = libasn1-unber-tool.la                 \
    $(top_builddir)/libasn1common/libasn1common.la

bin_PROGRAMS = unber
