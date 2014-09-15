
dist_check_SCRIPTS = check-assembly.sh

TESTS_ENVIRONMENT= CC="${CC}" CFLAGS="${TESTSUITE_CFLAGS} ${CFLAGS}" CXXFLAGS="${CXXFLAGS}" srcdir=${srcdir} top_srcdir=${top_srcdir} top_builddir=${top_builddir} ${srcdir}/check-assembly.sh

TESTS = ${srcdir}/check-src/check-*.c
if TEST_64BIT
TESTS += ${srcdir}/check-src/check64-*.c
endif

EXTRA_DIST =			\
	check-src/		\
	data-62			\
	data-70			\
	data-119		\
	data-126

clean-local:
	rm -rf test-*
