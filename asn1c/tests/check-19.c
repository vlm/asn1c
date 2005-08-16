#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <Name.h>

int
main(int ac, char **av) {
	Name_t t;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	memset(&t, 0, sizeof(t));

	/*
	 * No plans to fill it up: just checking whether it compiles or not.
	 */

	return 0;
}
