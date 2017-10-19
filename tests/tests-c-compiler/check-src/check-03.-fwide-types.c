#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include "Enum2.h"
#include "xer_decoder.h"

static char buf[4096];
static int buf_offset;

static int
buf_writer(const void *buffer, size_t size, void *app_key) {
        (void)app_key;
        assert(buf_offset + size < sizeof(buf));
        memcpy(buf + buf_offset, buffer, size);
        buf_offset += size;
        return 0;
}

static void
check_xer(e_Enum2 eval, char *xer_string) {
	asn_dec_rval_t rv;
	char buf2[128];
	Enum2_t *e = 0;
	long val;

	rv = xer_decode(0, &asn_DEF_Enum2, (void **)&e,
		xer_string, strlen(xer_string));
	assert(rv.code == RC_OK);
	assert(rv.consumed == strlen(xer_string));

	asn_INTEGER2long(e, &val);
	printf("%s -> %ld == %d\n", xer_string, val, eval);
	assert(val == eval);

	buf_offset = 0;
	xer_encode(&asn_DEF_Enum2, e, XER_F_CANONICAL, buf_writer, 0);
	buf[buf_offset] = 0;
	sprintf(buf2, "<Enum2>%s</Enum2>", xer_string);
	printf("%d -> %s == %s\n", eval, buf, buf2);
	assert(0 == strcmp(buf, buf2));

	ASN_STRUCT_FREE(asn_DEF_Enum2, e);
}

int
main() {

	check_xer(Enum2_red, "<red/>");
	check_xer(Enum2_green, "<green/>");
	check_xer(Enum2_blue, "<blue/>");
	check_xer(Enum2_orange, "<orange/>");
	check_xer(Enum2_alpha, "<alpha/>");
	check_xer(Enum2_beta, "<beta/>");
	check_xer(Enum2_gamma, "<gamma/>");

	return 0;
}
