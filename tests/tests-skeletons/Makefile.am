@CODE_COVERAGE_RULES@

check_PROGRAMS =            \
    check-ber_tlv_tag       \
    check-length            \
    check-bits              \
    check-OIDs              \
    check-GeneralizedTime   \
    check-OCTET_STRING      \
    check-UTF8String        \
    check-UTCTime           \
    check-INTEGER           \
    check-REAL              \
    check-XER               \
    check-OER-support       \
    check-OER-INTEGER       \
    check-OER-NativeEnumerated \
    check-PER-support       \
    check-PER-UniversalString  \
    check-PER-INTEGER

#Filter out the coverage options from CFLAGS as we don't need
#code coverage data for the tests executables
CFLAGS = $(filter-out $(CODE_COVERAGE_CFLAGS), @CFLAGS@)
AM_CFLAGS = -I$(top_srcdir)/skeletons $(TESTSUITE_CFLAGS)
AM_LDFLAGS = $(top_builddir)/skeletons/libasn1cskeletons.la
LDADD = -lm

TESTS = $(check_PROGRAMS)
TESTS_ENVIRONMENT= @ASAN_ENV_FLAGS@ UBSAN_OPTIONS=print_stacktrace=1
