@CODE_COVERAGE_RULES@

check_PROGRAMS =            \
    check-ber_tlv_tag       \
    check-length            \
    check-OIDs              \
    check-GeneralizedTime   \
    check-OCTET_STRING      \
    check-UTF8String        \
    check-UTCTime           \
    check-INTEGER           \
    check-REAL              \
    check-XER               \
    check-OER-INTEGER       \
    check-OER-NativeEnumerated \
    check-PER-UniversalString  \
    check-PER               \
    check-PER-INTEGER

#Filter out the coverage options from CFLAGS as we don't need
#code coverage data for the tests executables
CFLAGS = $(filter-out $(CODE_COVERAGE_CFLAGS), @CFLAGS@)
AM_CPPFLAGS = -I$(top_srcdir)/skeletons $(TESTSUITE_CFLAGS)
AM_CFLAGS = $(TESTSUITE_CFLAGS)
AM_LDFLAGS = $(top_builddir)/skeletons/libasn1cskeletons.la
LDADD = -lm

TESTS = $(check_PROGRAMS)
TESTS_ENVIRONMENT= ASAN_OPTIONS=detect_leaks=1 UBSAN_OPTIONS=print_stacktrace=1
