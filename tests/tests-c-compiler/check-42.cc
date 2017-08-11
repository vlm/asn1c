/*
 * This file checks that the output may be compiled by the C++ compiler.
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <VariablePart.h>

int
main() {
	VariablePart_t t;

	t.present = VariablePart_PR_vrange;

	return 0;
}
