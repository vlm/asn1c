#include <stdio.h>
#include <assert.h>

#include <asn_internal.h>
#include <xer_decoder.h>

static void
check(char *tag, char *name, xer_check_tag_e value) {
	xer_check_tag_e xct;

	xct = xer_check_tag(tag, strlen(tag), name);
	printf("[%s] vs [%s]: %d == %d\n",
		tag, name, xct, value);
	assert(xct == value);
}

static void
check_next(char *xerbuf, int expected_chunk_size, pxer_chunk_type_e expected_chunk_type) {
	int xerbuf_len = strlen(xerbuf);
	pxer_chunk_type_e ch_type;
	ssize_t ch_size;
	int state = 0;

	if(expected_chunk_size == -1)
		expected_chunk_size = xerbuf_len;
	ch_size = xer_next_token(&state, xerbuf, xerbuf_len, &ch_type);

	printf("[%s]:%d\n", xerbuf, xerbuf_len);
	printf("chunk sizes: %ld vs %ld, chunk types: %d vs %ld\n",
		(long)ch_size, (long)expected_chunk_size,
		ch_type, (long)expected_chunk_type
	);

	if(expected_chunk_type == PXER_WMORE) {
		assert(ch_size == 0);
	} else {
		assert(ch_size == expected_chunk_size);
		assert(ch_type == expected_chunk_type);
	}
}

int
main() {

	check("", "", XCT_BROKEN);
	check("<", "", XCT_BROKEN);
	check(">", "", XCT_BROKEN);
	check("</", "", XCT_BROKEN);
	check("/>", "", XCT_BROKEN);

	check("<>", "", XCT_UNKNOWN_OP);
	check("</>", "", XCT_UNKNOWN_CL);

	check("", "a", XCT_BROKEN);
	check("<>", "a", XCT_UNKNOWN_OP);
	check("</>", "a", XCT_UNKNOWN_CL);

	check("a", "a", XCT_BROKEN);
	check("<a>", "a", XCT_OPENING);
	check("</a>", "a", XCT_CLOSING);
	check("</a/>", "a", XCT_BROKEN);
	check("<a/>", "a", XCT_BOTH);

	check("<a>", "a", XCT_OPENING);
	check("</a>", "a", XCT_CLOSING);
	check("</a/>", "a", XCT_BROKEN);
	check("<a/>", "a", XCT_BOTH);

	check("<tag>", "a", XCT_UNKNOWN_OP);
	check("<tag>", "tag", XCT_OPENING);
	check("</tag>", "tag", XCT_CLOSING);
	check("</tag/>", "tag", XCT_BROKEN);
	check("<tag/>", "tag", XCT_BOTH);


	check("<tag>", "ta", XCT_UNKNOWN_OP);
	check("</tag>", "ta", XCT_UNKNOWN_CL);
	check("</tag/>", "ta", XCT_BROKEN);
	check("<tag/>", "ta", XCT_UNKNOWN_BO);

	check("<tag attribute=\"value\"/>", "tag", XCT_BOTH);

	check_next("<tag/>", -1, PXER_TAG);
	check_next("<tag", -1, PXER_WMORE);
	check_next("tag", -1, PXER_TEXT);
	check_next("tag<s", 3, PXER_TEXT);
	check_next("</a/>la", 5, PXER_TAG);
	check_next("<!--blah", -1, PXER_COMMENT);
	check_next("<!--blah-", -1, PXER_WMORE);
	check_next("<!--blah--", -1, PXER_WMORE);
	check_next("<!--blah-->", -1, PXER_COMMENT);

	return 0;
}
