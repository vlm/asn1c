@CODE_COVERAGE_RULES@

check_PROGRAMS = test-param-helper
dist_check_SCRIPTS = check-bundles.sh

#Filter out the coverage options from CFLAGS as we don't need
#code coverage data for the tests executables
CFLAGS = $(filter-out $(CODE_COVERAGE_CFLAGS), @CFLAGS@)

# Override single test fuzzing time using "make check FUZZ_TIME=1"
FUZZ_TIME=10

TESTS_ENVIRONMENT=                          \
    CC="${CC}"                              \
    MAKE="${MAKE}"                          \
    CFLAGS="${TESTSUITE_CFLAGS} ${CFLAGS}"  \
    CFLAGS_M32="${CFLAGS_M32}"              \
    LDFLAGS="${LDFLAGS}"                    \
    LIBFUZZER_CFLAGS="${LIBFUZZER_CFLAGS}"  \
    FUZZ_TIME="${FUZZ_TIME}"                \
    ASAN_ENV_FLAGS="@ASAN_ENV_FLAGS@"       \
    srcdir=${srcdir}                        \
    abs_builddir=${abs_builddir}            \
    abs_top_srcdir=${abs_top_srcdir}        \
    abs_top_builddir=${abs_top_builddir}    \
    ${srcdir}/check-bundles.sh

TESTS =
TESTS += bundles/00-NULL-bundle.txt
TESTS += bundles/01-BOOLEAN-bundle.txt
TESTS += bundles/02-INTEGER-bundle.txt
TESTS += bundles/03-ENUMERATED-bundle.txt
TESTS += bundles/04-REAL-bundle.txt
TESTS += bundles/05-BIT-STRING-bundle.txt
TESTS += bundles/06-OCTET-STRING-bundle.txt
TESTS += bundles/07-VisibleString-bundle.txt
TESTS += bundles/08-OBJECT-IDENTIFIER-bundle.txt
TESTS += bundles/09-RELATIVE-OID-bundle.txt
TESTS += bundles/10-UTF8String-bundle.txt
TESTS += bundles/11-BMPString-bundle.txt
TESTS += bundles/12-UniversalString-bundle.txt
TESTS += bundles/13-UTCTime-bundle.txt
TESTS += bundles/14-GeneralizedTime-bundle.txt
TESTS += bundles/15-CHOICE-bundle.txt
TESTS += bundles/16-SEQUENCE-bundle.txt
TESTS += bundles/17-SEQUENCE-OF-bundle.txt
TESTS += bundles/19-SET-OF-bundle.txt

EXTRA_DIST =                    \
    random-test-driver.c        \
    $(srcdir)/bundles/README    \
    $(srcdir)/bundles/*.txt

clean-local:
	rm -rf .tmp.*
