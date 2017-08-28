#include <stdio.h>
#include <assert.h>
#include <sys/time.h>

#include <UTF8String.h>

static void
check(int expect_length, char *buf, int buflen) {
	UTF8String_t st;
	int ret;

	if(buflen < 0) buflen = strlen(buf);

	st.buf = (uint8_t *)buf;
	st.size = buflen;
	printf("[");

	for(ret = 0; ret < buflen; ret++)
		printf("%c", buf[ret]);
	ret = UTF8String_length(&st);
	printf("]: size=%d, expect=%d, got=%d\n",
		buflen, expect_length, ret);
	assert(ret == expect_length);
}

static int
check_speed() {
	int cycles = 1000000;
	double start, stop;
	struct timeval tv;
	UTF8String_t st;
	char long_test[] =
		"a\303\237a\303\237a\303\237a\303\237"
		"a\303\237a\303\237a\303\237a\303\237"
		"a\303\237a\303\237a\303\237a\303\237"
		"a\303\237a\303\237a\303\237a\303\237"
		"a\303\237a\303\237a\303\237a\303\237";
	int ret;
	int i;

	st.buf = (uint8_t *)long_test;
	st.size = sizeof(long_test) - 1;

	ret = UTF8String_length(&st);
	assert(ret == 40);
	printf("Now wait a bit...\n");

	gettimeofday(&tv, 0);
	start = tv.tv_sec + tv.tv_usec / 1000000.0;
	for(i = 0; i < cycles; i++) {
		ret += UTF8String_length(&st);
	}
	gettimeofday(&tv, 0);
	stop = tv.tv_sec + tv.tv_usec / 1000000.0;

	printf("%d cycles in %.3fms\n", cycles, stop - start);

	return ret;
}

int
main() {

	check(0, "", 0);
	check(1, "\0", 1);
	check(1, "a", 1);
	check(2, "ab", 2);
	check(3, "abc", 3);
	assert(sizeof("a\303\237cd") == 6);
	check(4, "a\303\237cd", 5);
	check(3, "a\370\211\200\201\257c", 7);
	check(3, "\320\273\320\265\320\262", 6);

	check(-1, "a\303", 2);	/* Truncated */
	check(-2, "\377", 1);	/* Invalid UTF-8 sequence start */
	check(-2, "\200", 1);
	check(-2, "\320\273\265\320\262", 5);
	check(-3, "\320c", 2);	/* Not continuation */
	check(-3, "a\370\200\200\200c", 6);
	check(-4, "a\370\200\200\200\257c", 7);
	check(-4, "\320\273\320\265\340\200\262", 7);
	check(-5, 0, 0);

	check_speed();

	return 0;
}

