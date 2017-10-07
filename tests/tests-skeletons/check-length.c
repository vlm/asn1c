#include <stdio.h>
#include <assert.h>

#include <asn_internal.h>
#include <ber_decoder.h>
#include <OCTET_STRING.h>
#include <ber_tlv_length.h>
#include <ber_tlv_tag.h>

uint8_t *buf;
size_t buf_size;
size_t buf_off;

static int
write_to_buf(const void *buffer, size_t size, void *key) {
	(void)key;

	if(buf_off + size > buf_size) {
		size_t n = buf_size?:16;
		while(n < buf_off + size) n <<= 2;
		buf = realloc(buf, n);
		assert(buf);
		buf_size = n;
	}

	memcpy(buf + buf_off, buffer, size);

	buf_off += size;
	return 0;
}


static void
check(size_t size) {
	OCTET_STRING_t *os;
	OCTET_STRING_t *nos = 0;
	OCTET_STRING_t **nosp = &nos;
	asn_enc_rval_t erval;
	asn_dec_rval_t rval;

	os = OCTET_STRING_new_fromBuf(&asn_DEF_OCTET_STRING, 0, size);
	assert(os);
	assert(os->size == 0);

	os->buf = malloc(size);
	assert(os->buf);
	os->size = size;

	for(size_t i = 0; i < size; i++) {
		os->buf[i] = i;
	}

	buf_off = 0;
	erval = der_encode(&asn_DEF_OCTET_STRING,
		os, write_to_buf, 0);
	assert(erval.encoded >= 0 && (size_t)erval.encoded == buf_off);
	assert(buf_off > size);

	rval = ber_decode(0, &asn_DEF_OCTET_STRING, (void **)nosp, buf, buf_off);
	assert(rval.code == RC_OK);
	assert(rval.consumed == buf_off);

	assert(os->size == nos->size);

	for(size_t i = 0; i < size; i++) {
		assert(os->buf[i] == nos->buf[i]);
	}

	if(0) {
	fprintf(stderr, "new(%zd):", size);
	for(size_t i = 0; i < (buf_off<10?buf_off:10); i++)
		fprintf(stderr, " %02x", buf[i]);
	printf("\n");
	}


	ASN_STRUCT_FREE(asn_DEF_OCTET_STRING, os);
	ASN_STRUCT_FREE(asn_DEF_OCTET_STRING, nos);
}

int
main() {
    uint8_t buf1[] = {0x85, 0x00, 0x01, 0x02, 0x03, 0x04};
    uint8_t buf2[] = {0x85, 0x00, 0x7f, 0xff, 0x03, 0x04};
    uint8_t buf3[] = {0x85, 0x00, 0x7f, 0xff, 0xff, 0x04};
    uint8_t buf4[] = {0x89, 0x00, 0x7f, 0xff, 0xff,
                      0xff, 0xff, 0xff, 0xff, 0x04};
    ber_tlv_len_t tlv_len;
    ssize_t ret;

    for(size_t i = 0; i < 66000; i++) {
        if(i == 4500) i = 64000; /* Jump */
        check(i);
    }

    ret = ber_fetch_length(0, buf1, sizeof(buf1), &tlv_len);
    printf("ret=%zd, len=%zd\n", ret, tlv_len);
    assert(ret == sizeof(buf1));
    assert(tlv_len == 0x01020304);

    /*
     * Here although tlv_len is not greater than 2^31,
     * we ought to hit embedded length exploitation preventive checks.
     */
    ret = ber_fetch_length(0, buf2, sizeof(buf2), &tlv_len);
    if(sizeof(tlv_len) <= 4) {
        assert(ret == -1);
    } else {
        printf("ret=%zd, len=%zd\n", ret, tlv_len);
        assert(ret == sizeof(buf2));
        assert(tlv_len == 0x7fff0304);
    }

    if(sizeof(tlv_len) <= 4) {
        ret = ber_fetch_length(0, buf3, sizeof(buf3), &tlv_len);
        printf("ret=%zd\n", ret);
        printf("len=0x%08zx\n", tlv_len);
        assert(ret == -1);
    }
    if(sizeof(tlv_len) <= 8) {
        ret = ber_fetch_length(0, buf4, sizeof(buf4), &tlv_len);
        printf("ret=%zd\n", ret);
        assert(ret == -1);
    }

    return 0;
}
