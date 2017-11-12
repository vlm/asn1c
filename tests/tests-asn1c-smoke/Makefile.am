
dist_check_SCRIPTS = check-asn1c-smoke.sh
TESTS_ENVIRONMENT= MAKE=${MAKE}                     \
                    top_builddir=${top_builddir}    \
                    top_srcdir=${top_srcdir}
TESTS = $(dist_check_SCRIPTS)
CLEANFILES = Makefile.am.* test* *.[acho]

EXTRA_DIST = README
