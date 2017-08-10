#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <Epyt.h>

int
main(int ac, char **av) {
	Type_t t;
	Epyt_t ept;
	Ypet_t ypt;

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	memset(&t, 0, sizeof(t));
	memset(&ept, 0, sizeof(ept));
	memset(&ypt, 0, sizeof(ypt));

	/*
	 * No plans to fill it up: just checking whether it compiles or not.
	 */

	return 0;
}
