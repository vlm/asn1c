#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <Programming.h>

int
main(int ac, char **av) {
	Programming_t p;

	memset(&p, 0, sizeof(p));

	/*
	 * No plans to fill it up: just checking whether it compiles or not.
	 */

	return 0;
}
