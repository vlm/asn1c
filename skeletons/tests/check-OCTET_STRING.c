#define	EMIT_ASN_DEBUG	1
#include <OCTET_STRING.c>
#include <BIT_STRING.c>
#include <xer_decoder.c>
#include <xer_support.c>
#include <ber_decoder.c>
#include <ber_tlv_length.c>
#include <ber_tlv_tag.c>
#include <der_encoder.c>
#include <constraints.c>
#include <sys/time.h>

#define	HEX	0
#define	BINARY	1
#define	UTF8	2

static void
check(int type, char *tagname, char *xmlbuf, char *verify) {
	int xmllen = strlen(xmlbuf);
	int verlen = verify ? strlen(verify) : 0;
	asn_TYPE_descriptor_t *td = &asn_DEF_OCTET_STRING;
	OCTET_STRING_t *st = 0;
	asn_dec_rval_t rc;
	xer_type_decoder_f *decoder = 0;

	switch(type) {
	case HEX: decoder = OCTET_STRING_decode_xer_hex; break;
	case BINARY:
		td = &asn_DEF_BIT_STRING;
		decoder = OCTET_STRING_decode_xer_binary; break;
	case UTF8: decoder = OCTET_STRING_decode_xer_utf8; break;
	}

	rc = decoder(0, td, (void **)&st, tagname, xmlbuf, xmllen);
	printf("[%s] => [%s]:%d vs [%s]:%d, code %d\n",
		xmlbuf,
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
	check(UTF8, "z", "<z>a&#3000000000;b</z>", "a&#3000000000;b");
	check(UTF8, "z", "<z>a&#5000000000;b</z>", "a&#5000000000;b");
	check(UTF8, "z", "<z>a&#300</z>", "a&#300");
	check(UTF8, "z", "<z>a&#-300;</z>", "a&#-300;");
	check(UTF8, "z", "<z>a<ff/>b</z>", "a\014b");
	check(UTF8, "z", "<z>a<soh/>b</z>", "a\001b");
	check(UTF8, "z", "<z>a<bel/></z>", "a\007");

	return 0;
}

