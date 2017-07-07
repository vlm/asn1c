#include <stdio.h>
#include <assert.h>

#include <INTEGER.h>
#include <INTEGER.c>
#include <INTEGER_oer.c>

void
check_decode_ok(intmax_t control, uint8_t *buf, size_t size) {
}

int
main() {
	check_decode_ok(0, "", 1);
}
