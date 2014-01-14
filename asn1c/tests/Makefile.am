
dist_check_SCRIPTS = check-assembly.sh

TESTS_ENVIRONMENT= CC="${CC}" CFLAGS="${TESTSUITE_CFLAGS} ${CFLAGS} -Wno-error=unused-variable" CXXFLAGS="${CXXFLAGS}" ./check-assembly.sh

TESTS = check-*.c

EXTRA_DIST =			\
	check-*.c*		\
	data-62			\
	data-70			\
	data-119		\
	data-126

clean-local:
	rm -rf test-*
