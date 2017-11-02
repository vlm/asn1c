@CODE_COVERAGE_RULES@

SUBDIRS = check-src

dist_check_SCRIPTS = check-assembly.sh

#Filter out the coverage options from CFLAGS as we don't need
#code coverage data for the tests executables
CFLAGS = $(filter-out $(CODE_COVERAGE_CFLAGS), @CFLAGS@)

TESTS_ENVIRONMENT= \
				   CC="${CC}" \
				   CXX="${CXX}" \
				   CFLAGS="${TESTSUITE_CFLAGS} ${CFLAGS}" \
				   CXXFLAGS="${CXXFLAGS}" \
				   LDFLAGS="${LDFLAGS}" \
				   LIBFUZZER_CFLAGS="${LIBFUZZER_CFLAGS}" \
				   ASAN_ENV_FLAGS="@ASAN_ENV_FLAGS@"       \
				   srcdir=${srcdir} \
				   abs_top_srcdir=${abs_top_srcdir} \
				   abs_top_builddir=${abs_top_builddir} \
				   ${srcdir}/check-assembly.sh

TESTS = 
TESTS += check-src/check-03.-fwide-types.c
TESTS += check-src/check-119.-fwide-types.-gen-PER.c
TESTS += check-src/check-119.-gen-PER.c
TESTS += check-src/check-126.-gen-PER.c
TESTS += check-src/check-127.-gen-PER.c
TESTS += check-src/check-131.-gen-PER.c
TESTS += check-src/check-132.-gen-PER.c
TESTS += check-src/check-133.-gen-PER.c
TESTS += check-src/check-135.-gen-OER.c
TESTS += check-src/check-148.c
TESTS += check-src/check-19.c
TESTS += check-src/check-22.-fwide-types.c
TESTS += check-src/check-24.-fwide-types.c
TESTS += check-src/check-25.-fwide-types.c
TESTS += check-src/check-30.-fwide-types.c
TESTS += check-src/check-31.-fwide-types.c
TESTS += check-src/check-32.c
TESTS += check-src/check-33.c
TESTS += check-src/check-35.c
TESTS += check-src/check-39.c
TESTS += check-src/check-41.-fwide-types.c
TESTS += check-src/check-41.c
TESTS += check-src/check-42.c
TESTS += check-src/check-43.c
TESTS += check-src/check-44.c
TESTS += check-src/check-46.c
TESTS += check-src/check-48.c
TESTS += check-src/check-50.c
TESTS += check-src/check-59.c
TESTS += check-src/check-60.c
TESTS += check-src/check-62.c
TESTS += check-src/check-65.c
TESTS += check-src/check-70.-fwide-types.c
TESTS += check-src/check-70.c
TESTS += check-src/check-72.-fcompound-names.c
TESTS += check-src/check-73.c
TESTS += check-src/check-92.-findirect-choice.c
TESTS += check-src/check-92.c
TESTS += check-src/check-158.-fcompound-names.c

if TEST_64BIT
TESTS += check-src/check64-134.-gen-PER.c
TESTS += check-src/check64-136.-gen-OER.c
endif

XFAIL_TESTS =
XFAIL_TESTS += check-src/check-158.-fcompound-names.c

EXTRA_DIST =    \
    data-62     \
    data-70     \
    data-119    \
    data-126    \
    check-src/check64-134.-gen-PER.c    \
    check-src/check64-136.-gen-OER.c

clean-local:
	rm -rf test-*
