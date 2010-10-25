
AM_CFLAGS = @ADD_CFLAGS@

dist_check_SCRIPTS = check-assembly.sh

TESTS_ENVIRONMENT= CC="${CC}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" ./check-assembly.sh

TESTS = check-*.c

EXTRA_DIST =			\
	check-*.c*		\
	data-62			\
	data-70			\
	data-119		\
	data-126

clean-local:
	rm -rf test-*
