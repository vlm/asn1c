#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include <T1.h>
#include <T2.h>

static unsigned char buf[4096];
static int buf_offset;

static int
_buf_writer(const void *buffer, size_t size, void *app_key) {
	unsigned char *b, *bend;
	(void)app_key;
	assert(buf_offset + size < sizeof(buf));
	if (buffer) {
		memcpy(buf + buf_offset, buffer, size);
	}
	b = buf + buf_offset;
	bend = b + size;
	printf("=> [");
	for(; b < bend; b++)
		printf(" %02X", *b);
	printf("]:%zd\n", size);
	buf_offset += size;
	return 0;
}

static int
save_object(void *bs, asn_TYPE_descriptor_t *td) {
	asn_enc_rval_t rval; /* Return value */
	int i;

	buf_offset = 0;
	
	rval = der_encode(td, bs, _buf_writer, 0);
	if (rval.encoded == -1) {
		fprintf(stderr,
			"Cannot encode %s: %s\n",
			rval.failed_type->name, strerror(errno));
		assert(rval.encoded != -1);
		return -1;	/* JIC */
	}

	buf[buf_offset++] = 0xab;	/* Finalize with garbage */

	asn_fprint(stderr, td, bs);

	printf("OUT: [");
	for(i = 0; i < buf_offset; i++)
		printf(" %02x", buf[i]);
	printf("]\n");

	return 0;
}

static int
load_object(void *bs, asn_TYPE_descriptor_t *td) {
	asn_dec_rval_t rval;

	fprintf(stderr, "\nLOADING OBJECT OF SIZE %d\n", buf_offset);

	rval = ber_decode(0, td, (void **)&bs, buf, buf_offset);
	assert(rval.code == RC_OK);

	asn_fprint(stderr, td, bs);

	return (rval.code == RC_OK)?0:-1;
}

/* [3] IMPLICIT SEQUENCE { b BOOLEAN } */
uint8_t test_any_buf1[] = { 0xa3, 0x80, /* [3], constructed, indefinite */
	0x01, 0x01, 0xff,	/* b BOOLEAN ::= TRUE */
	0x00, 0x00 /* End of content octets */ };

/* b BOOLEAN */
uint8_t test_any_buf2[] = { 0x01, 0x01, 0x13 };

int
main() {
	asn_TYPE_descriptor_t *td1 = &asn_DEF_T1;
	asn_TYPE_descriptor_t *td2 = &asn_DEF_T2;
	T1_t t1, t1_new;
	T2_t t2, t2_new;
	int ret;

	/*
	 * Test the T1 with constructed indefinite length ANY encoding.
	 */
	memset(&t1, 0, sizeof(t1));
	memset(&t1_new, 0, sizeof(t1_new));

	t1.i = 112233;
	t1.any.buf = test_any_buf1;
	t1.any.size = sizeof(test_any_buf1);

	/* Save->Load must succeed */
	save_object(&t1, td1);
	ret = load_object(&t1_new, td1);

	assert(ret == 0);
	assert(t1_new.i == 112233);
	assert(t1_new.any.size == (ssize_t)sizeof(test_any_buf1));
	assert(memcmp(t1_new.any.buf, test_any_buf1, sizeof(test_any_buf1)) == 0);

	/*
	 * Test the T1 with primitive encoding.
	 */
	memset(&t1, 0, sizeof(t1));
	ASN_STRUCT_RESET(asn_DEF_T1, &t1_new);

	t1.i = -112233;
	t1.any.buf = test_any_buf2;
	t1.any.size = sizeof(test_any_buf2);

	/* Save->Load must succeed */
	save_object(&t1, td1);
	ret = load_object(&t1_new, td1);

	assert(ret == 0);
	assert(t1_new.i == -112233);
	assert(t1_new.any.size == (ssize_t)sizeof(test_any_buf2));
	assert(memcmp(t1_new.any.buf, test_any_buf2, sizeof(test_any_buf2)) == 0);
	ASN_STRUCT_RESET(asn_DEF_T1, &t1_new);

	/*
	 * Test the T2 empty sequence.
	 */
	memset(&t2, 0, sizeof(t2));
	memset(&t2_new, 0, sizeof(t2_new));

	t2.i = 332211;
	t2.any = calloc(1, sizeof(*t2.any));
	t2.any->buf = 0;
	t2.any->size = 0;

	/* Save->Load must succeed */
	save_object(&t2, td2);
	ret = load_object(&t2_new, td2);

	assert(ret == 0);
	assert(t2_new.i == 332211);
	assert(t2_new.any->size == 0);

	/*
	 * Test the T2 sequence.
	 */
	ASN_STRUCT_RESET(asn_DEF_T2, &t2);
	ASN_STRUCT_RESET(asn_DEF_T2, &t2_new);

	t2.i = 332211;
	t2.any = calloc(1, sizeof(*t2.any));
	t2.any->buf = test_any_buf1;
	t2.any->size = sizeof(test_any_buf1);

	/* Save->Load must succeed */
	save_object(&t2, td2);
	ret = load_object(&t2_new, td2);

	assert(ret == 0);
	assert(t2_new.i == 332211);
	assert(t2_new.any->size == (ssize_t)sizeof(test_any_buf1));
	assert(memcmp(t2_new.any->buf, test_any_buf1, sizeof(test_any_buf1)) == 0);

	/*
	 * Test the T2 sequence with primitive encoding.
	 */
	t2.any->buf = NULL;
	t2.any->size = 0;
	ASN_STRUCT_RESET(asn_DEF_T2, &t2);
	ASN_STRUCT_RESET(asn_DEF_T2, &t2_new);

	t2.i = 0;
	t2.any = calloc(1, sizeof(*t2.any));
	t2.any->buf = test_any_buf2;
	t2.any->size = sizeof(test_any_buf2);

	/* Save->Load must succeed */
	save_object(&t2, td2);
	ret = load_object(&t2_new, td2);

	assert(ret == 0);
	assert(t2_new.i == 0);
	assert(t2_new.any->size == (ssize_t)sizeof(test_any_buf2));
	assert(memcmp(t2_new.any->buf, test_any_buf2, sizeof(test_any_buf2)) == 0);

	/*
	 * Test T2 with ANY element omitted.
	 */
	free(t2.any);
	t2.any = 0;
	ASN_STRUCT_RESET(asn_DEF_T2, &t2_new);

	save_object(&t2, td2);
	ret = load_object(&t2_new, td2);

	assert(ret == 0);
	assert(t2_new.i == 0);
	assert(t2_new.any == 0);

	printf("OK\n");

	return ret;
}
