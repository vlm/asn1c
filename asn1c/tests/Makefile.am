
AM_CFLAGS = @ADD_CFLAGS@

check_SCRIPTS = check-assembly.sh

TESTS_ENVIRONMENT= CC="${CC}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" ./check-assembly.sh

TESTS = check-*.c

EXTRA_DIST =			\
	$(check_SCRIPTS)	\
	check-*.c*		\
	data-*/Makefile		\
	data-*/README		\
	data-*/*.*

clean:
	rm -rf test-*
