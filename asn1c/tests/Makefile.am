
AM_CFLAGS = @ADD_CFLAGS@

check_SCRIPTS = check-assembly.sh

TESTS_ENVIRONMENT= CC="${CC}" CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" ./check-assembly.sh

if CPLUSPLUS_FOUND
TESTS = check-*.c check-*.cc	## Include C++ test filed (.cc)
else
TESTS = check-*.c
endif

EXTRA_DIST =			\
	$(check_SCRIPTS)	\
	check-*.c*		\
	data-*/Makefile		\
	data-*/*.*

clean:
	rm -rf test-*
