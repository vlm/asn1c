#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <Test-structure-1.h>
#include <Sets.h>

int
main(int ac, char **av) {
	Test_structure_1_t ts1;
	Sets_t s1;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	memset(&ts1, 0, sizeof(ts1));
	memset(&s1, 0, sizeof(s1));

	/*
	 * No plans to fill it up: just checking whether it compiles or not.
	 */

	return 0;
}
