@CODE_COVERAGE_RULES@

dist_check_SCRIPTS = check-bundles.sh

#Filter out the coverage options from CFLAGS as we don't need
#code coverage data for the tests executables
CFLAGS = $(filter-out $(CODE_COVERAGE_CFLAGS), @CFLAGS@)

TESTS_ENVIRONMENT=                          \
    CC="${CC}"                              \
    MAKE="${MAKE}"                          \
    CFLAGS="${TESTSUITE_CFLAGS} ${CFLAGS}"  \
    CFLAGS_M32="${CFLAGS_M32}"              \
    LDFLAGS="${LDFLAGS}"                    \
    LIBFUZZER_CFLAGS="${LIBFUZZER_CFLAGS}"  \
    ASAN_ENV_FLAGS="@ASAN_ENV_FLAGS@"       \
    srcdir=${srcdir}                        \
    abs_top_srcdir=${abs_top_srcdir}        \
    abs_top_builddir=${abs_top_builddir}    \
    ${srcdir}/check-bundles.sh


TESTS =
TESTS += bundles/01-1.txt
TESTS += bundles/01-2.txt

EXTRA_DIST =                    \
    random-test-driver.c        \
    $(srcdir)/bundles/README    \
    $(srcdir)/bundles/*.txt

clean-local:
	rm -rf .tmp.*
