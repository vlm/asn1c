@CODE_COVERAGE_RULES@

AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS =                       \
    -I${top_srcdir}/libasn1common   \
    -I${top_srcdir}/libasn1parser   \
    -I${top_srcdir}/skeletons

noinst_LTLIBRARIES = libasn1-unber-tool.la

libasn1_unber_tool_la_SOURCES =     \
    libasn1_unber_tool.c libasn1_unber_tool.h

bin_PROGRAMS = unber

unber_LDADD = libasn1-unber-tool.la                 \
    $(top_builddir)/libasn1common/libasn1common.la

check_PROGRAMS = check_unber
check_unber_CFLAGS = $(TESTSUITE_CFLAGS) $(LIBFUZZER_CFLAGS)
check_unber_LDADD = libasn1-unber-tool.la           \
    $(top_builddir)/libasn1common/libasn1common.la

dist_check_SCRIPTS=check_unber.sh

# This jump through the shell is needed to run ./check_unber binary with
# proper fuzzing options.
TESTS_ENVIRONMENT=                      \
    ASAN_ENV_FLAGS="@ASAN_ENV_FLAGS@"   \
    builddir=${builddir}
TESTS= check_unber.sh
