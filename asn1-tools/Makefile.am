@CODE_COVERAGE_RULES@

SUBDIRS=unber enber

AM_CFLAGS = @ADD_CFLAGS@
AM_CPPFLAGS = -I${top_srcdir}/skeletons

dist_check_SCRIPTS = check-xxber.sh
TESTS_ENVIRONMENT= builddir=${builddir}
TESTS = $(dist_check_SCRIPTS)
CLEANFILES = .check-xxber.*.tmp
