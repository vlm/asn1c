
check_SCRIPTS = ./check-assembly.sh

TESTS_ENVIRONMENT= ./check-assembly.sh
TESTS = check-*.c

EXTRA_DIST = ${check_SCRIPTS} check-*.c

clean:
	for t in test-*; do rm -rf $$t; done
