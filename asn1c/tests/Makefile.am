
check_SCRIPTS = check-assembly.sh

TESTS_ENVIRONMENT= CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" ./check-assembly.sh

if CPLUSPLUS_FOUND
TESTS = check-*.c check-*.cc	## Include C++ test filed (.cc)
else
TESTS = check-*.c
endif

EXTRA_DIST = ${check_SCRIPTS} check-*.c*

clean:
	for t in test-*; do rm -rf $$t; done
