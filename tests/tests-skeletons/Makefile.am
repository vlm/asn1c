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

if EXPLICIT_M32
check_PROGRAMS +=                   \
    check-32-ber_tlv_tag            \
    check-32-length                 \
    check-32-bits                   \
    check-32-OIDs                   \
    check-32-GeneralizedTime        \
    check-32-OCTET_STRING           \
    check-32-UTF8String             \
    check-32-UTCTime                \
    check-32-INTEGER                \
    check-32-REAL                   \
    check-32-XER                    \
    check-32-OER-support            \
    check-32-OER-INTEGER            \
    check-32-OER-NativeEnumerated   \
    check-32-PER-support            \
    check-32-PER-UniversalString    \
    check-32-PER-INTEGER

check_32_ber_tlv_tag_CFLAGS=$(CFLAGS_M32)
check_32_ber_tlv_tag_LDADD=$(LDADD_32)
check_32_ber_tlv_tag_SOURCES=check-ber_tlv_tag.c
check_32_length_CFLAGS=$(CFLAGS_M32)
check_32_length_LDADD=$(LDADD_32)
check_32_length_SOURCES=check-length.c
check_32_bits_CFLAGS=$(CFLAGS_M32)
check_32_bits_LDADD=$(LDADD_32)
check_32_bits_SOURCES=check-bits.c
check_32_OIDs_CFLAGS=$(CFLAGS_M32)
check_32_OIDs_LDADD=$(LDADD_32)
check_32_OIDs_SOURCES=check-OIDs.c
check_32_GeneralizedTime_CFLAGS=$(CFLAGS_M32)
check_32_GeneralizedTime_LDADD=$(LDADD_32)
check_32_GeneralizedTime_SOURCES=check-GeneralizedTime.c
check_32_OCTET_STRING_CFLAGS=$(CFLAGS_M32)
check_32_OCTET_STRING_LDADD=$(LDADD_32)
check_32_OCTET_STRING_SOURCES=check-OCTET_STRING.c
check_32_UTF8String_CFLAGS=$(CFLAGS_M32)
check_32_UTF8String_LDADD=$(LDADD_32)
check_32_UTF8String_SOURCES=check-UTF8String.c
check_32_UTCTime_CFLAGS=$(CFLAGS_M32)
check_32_UTCTime_LDADD=$(LDADD_32)
check_32_UTCTime_SOURCES=check-UTCTime.c
check_32_INTEGER_CFLAGS=$(CFLAGS_M32)
check_32_INTEGER_LDADD=$(LDADD_32)
check_32_INTEGER_SOURCES=check-INTEGER.c
check_32_REAL_CFLAGS=$(CFLAGS_M32)
check_32_REAL_LDADD=$(LDADD_32)
check_32_REAL_SOURCES=check-REAL.c
check_32_XER_CFLAGS=$(CFLAGS_M32)
check_32_XER_LDADD=$(LDADD_32)
check_32_XER_SOURCES=check-XER.c
check_32_OER_support_CFLAGS=$(CFLAGS_M32)
check_32_OER_support_LDADD=$(LDADD_32)
check_32_OER_support_SOURCES=check-OER-support.c
check_32_OER_INTEGER_CFLAGS=$(CFLAGS_M32)
check_32_OER_INTEGER_LDADD=$(LDADD_32)
check_32_OER_INTEGER_SOURCES=check-OER-INTEGER.c
check_32_OER_NativeEnumerated_CFLAGS=$(CFLAGS_M32)
check_32_OER_NativeEnumerated_LDADD=$(LDADD_32)
check_32_OER_NativeEnumerated_SOURCES=check-OER-NativeEnumerated.c
check_32_PER_support_CFLAGS=$(CFLAGS_M32)
check_32_PER_support_LDADD=$(LDADD_32)
check_32_PER_support_SOURCES=check-PER-support.c
check_32_PER_UniversalString_CFLAGS=$(CFLAGS_M32)
check_32_PER_UniversalString_LDADD=$(LDADD_32)
check_32_PER_UniversalString_SOURCES=check-PER-UniversalString.c
check_32_PER_INTEGER_CFLAGS=$(CFLAGS_M32)
check_32_PER_INTEGER_LDADD=$(LDADD_32)
check_32_PER_INTEGER_SOURCES=check-PER-INTEGER.c

LDADD_32 = -lm $(top_builddir)/skeletons/libasn1cskeletons_c89_32.la
endif

#Filter out the coverage options from CFLAGS as we don't need
#code coverage data for the tests executables
CFLAGS = $(filter-out $(CODE_COVERAGE_CFLAGS), @CFLAGS@) \
    -I$(top_srcdir)/skeletons $(TESTSUITE_CFLAGS)
LDADD = -lm $(top_builddir)/skeletons/libasn1cskeletons.la

TESTS = $(check_PROGRAMS)
TESTS_ENVIRONMENT=                      \
    @ASAN_ENV_FLAGS@                    \
    UBSAN_OPTIONS=print_stacktrace=1    \
    ${srcdir}/disable-leak-check-m32.sh

EXTRA_DIST = disable-leak-check-m32.sh
