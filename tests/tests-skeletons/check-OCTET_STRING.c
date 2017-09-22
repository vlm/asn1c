#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>

#include <OCTET_STRING.h>
#include <BIT_STRING.h>

enum encoding_type { HEX, BINARY, UTF8 };

#define check(t, tag, buf, verify)  check_impl(__LINE__, t, tag, buf, verify)

static void
check_impl(int lineno, enum encoding_type type, char *tagname, char *xmlbuf, char *verify) {
	size_t xmllen = strlen(xmlbuf);
	size_t verlen = verify ? strlen(verify) : 0;
	asn_TYPE_descriptor_t *td = &asn_DEF_OCTET_STRING;
	OCTET_STRING_t *st = 0;
	OCTET_STRING_t **stp = &st;
	asn_dec_rval_t rc;
	xer_type_decoder_f *decoder = 0;

	switch(type) {
	case HEX:
		decoder = OCTET_STRING_decode_xer_hex;
		break;
	case BINARY:
		td = &asn_DEF_BIT_STRING;
		decoder = OCTET_STRING_decode_xer_binary;
		break;
	case UTF8:
		decoder = OCTET_STRING_decode_xer_utf8;
		break;
	}

	rc = decoder(0, td, (void **)stp, tagname, xmlbuf, xmllen);
	printf("%03d: [%s] => [%s]:%zu vs [%s]:%zu, code %d\n",
		lineno, xmlbuf,
		st ? (const char *)st->buf : "", st ? st->size : 0,
		verify ? verify : "", verlen, rc.code);

	if(verify) {
		assert(rc.code == RC_OK);
		assert(st);
		assert(st->buf);
		assert(st->size == verlen);
		assert(!memcmp(st->buf, verify, verlen));
	} else {
		assert(rc.code != RC_OK);
	}

	ASN_STRUCT_FREE(*td, st);
}

static char buf[1024];

static int
write_buf(const void *buffer, size_t size, void *key) {
	size_t *off = key;
	assert(*off + size < sizeof(buf));
	memcpy(buf + *off, buffer, size);
	*off += size;
	return 0;
}

static void
encode(char *orig, char *encoded) {
	OCTET_STRING_t os;
	size_t written = 0;
	asn_enc_rval_t er;

	memset(&os, 0, sizeof(os));

	OCTET_STRING_fromString(&os, orig);

	er = OCTET_STRING_encode_xer_utf8(&asn_DEF_OCTET_STRING, &os,
			0, 0, write_buf, &written);
	assert(er.encoded >= 0);
	buf[er.encoded] = '\0';
	printf("Orig: [%s], encoded: [%s], check [%s]\n",
		orig, buf, encoded);
	assert(strcmp(buf, encoded) == 0);
	ASN_STRUCT_RESET(asn_DEF_OCTET_STRING, &os);
}

int
main() {

	check(HEX, 0, "<OCTET_STRING>41424</OCTET_STRING>",
		"AB@");

	check(HEX, 0, "<!--comment--><OCTET_STRING>\n"
		"<!--comment-->41424</OCTET_STRING>",
		"AB@");

	check(HEX, 0, "<OCTET_STRING blah blah> 4 1 4 2 4 5 44 </OCTET_STRING>",
		"ABED");

	/* Some hard cases */
	check(HEX, "z", "<z><!-- < -->40</z>", "@");
	check(HEX, "z", "<z><!-- <-->40</z>", "@");
	check(HEX, "z", "<z><!-- -->>40</z>", 0);
	check(HEX, "z", "<z><!-- <some <sometag>-->40</z>", "@");
	check(HEX, "z", "<z><!-- <some <sometag-->>40</z>", 0);

	check(HEX, "z", "ignored<z>40</z>stuff", "@");

	check(HEX, "tag", "<tag>4</tag>", "@");
	check(HEX, "a-z", "<a-z>7 375 73 6c6 9<!--/-->6 b</a-z>", "suslik");

	/* This one has a comment in a not-yet-supported place */ 
	/* check(HEX, "a-z", "<a-z>73 75 73 6c 6<!--/-->9 6b</a-z>",
		"suslik"); */

	check(BINARY, "tag", "<tag/>", "");
	check(BINARY, "tag", "<tag>blah</tag>", 0);
	check(BINARY, "tag", "<tag>01000001</tag>", "A");
	check(BINARY, "tag", "<tag>01000<!--blah--> 00 101 00001</tag>", "AB");

	check(UTF8, 0, "<OCTET_STRING>one, two, three</OCTET_STRING>",
		"one, two, three");

	check(UTF8, "z", "<z></z>", "");
	check(UTF8, "z", "<z z z>&lt;&amp;&gt;</z z z>", "<&>");
	check(UTF8, "z", "<z z z>a&lt;b&amp;c&gt;d</z z z>", "a<b&c>d");
	check(UTF8, "z", "<z z z>a&lt</z z z>", "a&lt");
	check(UTF8, "z", "<z z z>a&sdfsdfsdf;b</z z z>", "a&sdfsdfsdf;b");
	check(UTF8, "z", "<z z z>a&#x20;b</z z z>", "a b");
	check(UTF8, "z", "<z z z>a&#32;b</z z z>", "a b");
	check(UTF8, "z", "<z>a&#32323;b</z>", "a\347\271\203b");
	check(UTF8, "z", "<z>a&#x4fc4;|</z>", "a\xe4\xbf\x84|");
    /* Last unicode point */
	check(UTF8, "z", "<z>a&#x10ffff;|</z>", "a\xf4\x8f\xbf\xbf|");
	check(UTF8, "z", "<z>a&#1114111;|</z>", "a\xf4\x8f\xbf\xbf|");
    /* One past the last unicode point */
	check(UTF8, "z", "<z>a&#x110000;|</z>", "a&#x110000;|");
	check(UTF8, "z", "<z>a&#1114112;|</z>", "a&#1114112;|");
	check(UTF8, "z", "<z>a&#3000000000;b</z>", "a&#3000000000;b");
	check(UTF8, "z", "<z>a&#5000000000;b</z>", "a&#5000000000;b");
	check(UTF8, "z", "<z>a&#300</z>", "a&#300");
	check(UTF8, "z", "<z>a&#-300;</z>", "a&#-300;");
	check(UTF8, "z", "<z>a<ff/>b</z>", "a\014b");
	check(UTF8, "z", "<z>a<soh/>b</z>", "a\001b");
	check(UTF8, "z", "<z>a<bel/></z>", "a\007");

	encode("", "");
	encode("a", "a");
	encode("a\nb", "a\nb");
	encode("a\bc", "a<bs/>c");
	encode("ab\01c\ndef\r\n", "ab<soh/>c\ndef\r\n");

	return 0;
}

