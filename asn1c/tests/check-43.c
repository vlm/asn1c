#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <Test-structure-1.h>
#include <Choice-1.h>

int
main(int ac, char **av) {
	Test_structure_1_t ts1;
	Choice_1_t cs1;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	memset(&ts1, 0, sizeof(ts1));
	memset(&cs1, 0, sizeof(cs1));

	/*
	 * No plans to fill it up: just checking whether it compiles or not.
	 */

	return 0;
}
