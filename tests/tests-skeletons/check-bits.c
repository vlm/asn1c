#include <stdio.h>
#include <assert.h>

#include <asn_bit_data.c>

static void
check_asn_bits_decoding() {
	uint8_t buf[] = { 0xB7, 0x19, 0x2F, 0xEE, 0xAD };
	uint8_t tmpbuf[10];
	int32_t z;
	asn_bit_data_t pos;
	memset(&pos, 0, sizeof(pos));

	pos.buffer = buf;
	pos.nboff = 0;
	pos.nbits = sizeof(buf) * 8;

	z = asn_get_few_bits(&pos, 32);
	assert(z == -1);
	assert(pos.nbits == sizeof(buf) * 8);

	z = asn_get_few_bits(&pos, 0);
	assert(z == 0);
	assert(pos.nboff == 0);
	assert(pos.nbits == sizeof(buf) * 8);

	z = asn_get_few_bits(&pos, 1);
	assert(z == 1);
	assert(pos.nboff == 1);
	assert(pos.nbits == sizeof(buf) * 8);

	z = asn_get_few_bits(&pos, 2);
	assert(z == 1);
	assert(pos.nboff == 3);
	assert(pos.nbits == sizeof(buf) * 8);

	z = asn_get_few_bits(&pos, 2);
	assert(z == 2);
	assert(pos.nboff == 5);
	assert(pos.nbits == sizeof(buf) * 8);

	z = asn_get_few_bits(&pos, 3);
	assert(z == 7);
	assert(pos.nboff == 8);
	assert(pos.nbits == sizeof(buf) * 8);

	z = asn_get_few_bits(&pos, 8);
	assert(z == 0x19);
	assert(pos.nboff == 8);
	assert(pos.nbits == (sizeof(buf) - 1) * 8);

	z = asn_get_few_bits(&pos, 1);
	assert(z == 0);
	assert(pos.nboff == 1);
	assert(pos.nbits == (sizeof(buf) - 2) * 8);

	z = asn_get_few_bits(&pos, 3);
	assert(z == 2);
	assert(pos.nboff == 4);
	assert(pos.nbits == (sizeof(buf) - 2) * 8);

	z = asn_get_few_bits(&pos, 8);
	assert(z == 254);
	assert(pos.nboff == 12);

	pos.buffer = buf;
	pos.nboff = 2;
	pos.nbits = sizeof(buf) * 8;
	z = asn_get_few_bits(&pos, 24);
	assert(z == 14443711);

	pos.buffer = (unsigned char *)"\001";
	pos.nboff = 7;
	pos.nbits = 7;
	z = asn_get_few_bits(&pos, 1);
	assert(pos.nboff == 7);
	assert(pos.nbits == 7);
	assert(z == -1);

	pos.buffer = (unsigned char *)"\001";
	pos.nboff = 7;
	pos.nbits = 8;
	z = asn_get_few_bits(&pos, 1);
	assert(pos.nboff == 8);
	assert(pos.nbits == 8);
	assert(z == 1);

	pos.buffer = (unsigned char *)"\000";
	pos.nboff = 7;
	pos.nbits = 8;
	z = asn_get_few_bits(&pos, 1);
	assert(pos.nboff == 8);
	assert(pos.nbits == 8);
	assert(z == 0);
	z = asn_get_few_bits(&pos, 1);
	assert(pos.nboff == 8);
	assert(pos.nbits == 8);
	assert(z == -1);

	pos.buffer = (unsigned char *)"\000";
	pos.nboff = 7;
	pos.nbits = 9;
	z = asn_get_few_bits(&pos, 1);
	assert(pos.nboff == 8);
	assert(pos.nbits == 9);
	assert(z == 0);
	z = asn_get_few_bits(&pos, 1);
	assert(pos.nboff == 1);
	assert(pos.nbits == 1);
	assert(z == 0);

	pos.buffer = (unsigned char *)"\001";
	pos.nboff = 7;
	pos.nbits = 9;
	z = asn_get_few_bits(&pos, 1);
	assert(pos.nboff == 8);
	assert(pos.nbits == 9);
	assert(z == 1);
	z = asn_get_few_bits(&pos, 1);
	assert(pos.nboff == 1);
	assert(pos.nbits == 1);
	assert(z == 0);

	/* Get full 31-bit range */
	pos.buffer = buf;
	pos.nboff = 7;
	pos.nbits = sizeof(buf) * 8;
	z = asn_get_few_bits(&pos, 31);
	assert(z == 1179384747);

	/* Get a bit shifted range */
	pos.buffer = buf;
	pos.nboff = 6;
	pos.nbits = sizeof(buf) * 8;
	z = asn_get_few_bits(&pos, 31);
	assert(z == 1663434197);

	pos.buffer = buf;
	pos.nboff = 0;
	pos.nbits = sizeof(buf) * 8;
	z = asn_get_many_bits(&pos, tmpbuf, 0, sizeof(buf) * 8);
	assert(z == 0);
	assert(buf[0] == tmpbuf[0]);
	assert(buf[1] == tmpbuf[1]);
	assert(buf[2] == tmpbuf[2]);
	assert(buf[3] == tmpbuf[3]);
	assert(buf[4] == tmpbuf[4]);

	pos.buffer = buf;
	pos.nboff = 1;
	pos.nbits = sizeof(buf) * 8;
	z = asn_get_many_bits(&pos, tmpbuf, 0, sizeof(buf) * 8);
	assert(z == -1);

	pos.buffer = buf;
	pos.nboff = 1;
	pos.nbits = sizeof(buf) * 8;
	z = asn_get_many_bits(&pos, tmpbuf, 0, sizeof(buf) * 8 - 1);
	assert(z == 0);
	assert(tmpbuf[0] == 110);
	assert(tmpbuf[1] == 50);
	assert(tmpbuf[2] == 95);
	assert(tmpbuf[3] == 221);
	assert(tmpbuf[4] == 90);

	pos.buffer = buf;
	pos.nboff = 1;
	pos.nbits = sizeof(buf) * 8;
	z = asn_get_many_bits(&pos, tmpbuf, 1, sizeof(buf) * 8 - 1);
	assert(z == 0);
	assert(tmpbuf[0] == 55);
	assert(tmpbuf[0] != buf[0]);
	assert(tmpbuf[1] == buf[1]);
	assert(tmpbuf[2] == buf[2]);
	assert(tmpbuf[3] == buf[3]);
	assert(tmpbuf[4] == buf[4]);
}

static int Ignore(const void *data, size_t size, void *op_key) {
    (void)data;
    (void)size;
    (void)op_key;
	return 0;
}

static void
check_asn_bits_encoding() {
	asn_bit_outp_t po;
	int ret;

	po.buffer = po.tmpspace;
	po.nboff = 0;
	po.nbits = 0;
	po.output = Ignore;
	po.op_key = 0;
	po.tmpspace[0] = 0xff;

	ret = asn_put_few_bits(&po, 0, 0);
	assert(ret == 0);
	assert(po.nboff == 0);
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0xff);

	ret = asn_put_few_bits(&po, 0, 1);
	assert(ret == 0);
	assert(po.nboff == 1);
	assert(po.nbits == 8 * sizeof(po.tmpspace));
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0x00);

	ret = asn_put_few_bits(&po, 1, 1);
	assert(ret == 0);
	assert(po.nboff == 2);
	assert(po.nbits == 8 * sizeof(po.tmpspace));
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0x40);

	ret = asn_put_few_bits(&po, 1, 1);
	assert(ret == 0);
	assert(po.nboff == 3);
	assert(po.nbits == 8 * sizeof(po.tmpspace));
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0x60);

	ret = asn_put_few_bits(&po, 15, 5);
	assert(ret == 0);
	assert(po.nboff == 8);
	assert(po.nbits == 8 * sizeof(po.tmpspace));
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0x6F);

	ret = asn_put_few_bits(&po, 0xf0ff, 16);
	assert(ret == 0);
	assert(po.nboff == 16);
	assert(po.nbits == 8 * sizeof(po.tmpspace) - 8);
	assert(po.buffer == po.tmpspace + 1);
	assert(po.tmpspace[0] == 0x6F);
	assert(po.tmpspace[1] == 0xf0);
	assert(po.tmpspace[2] == 0xff);

	po.nboff--;

	ret = asn_put_few_bits(&po, 2, 1);
	assert(ret == 0);
	assert(po.nboff == 8);
	assert(po.nbits == 8 * sizeof(po.tmpspace) - 16);
	assert(po.buffer == po.tmpspace + 2);
	assert(po.tmpspace[0] == 0x6F);
	assert(po.tmpspace[1] == 0xf0);
	assert(po.tmpspace[2] == 0xfe);

	ret = asn_put_few_bits(&po, 2, 32);
	assert(ret == -1);

	ret = asn_put_few_bits(&po, 2, -1);
	assert(ret == -1);

	ret = asn_put_few_bits(&po, -1, 31);
	assert(ret == 0);
	assert(po.nboff == 31);
	assert(po.nbits == 8 * sizeof(po.tmpspace) - 24);
	assert(po.buffer == po.tmpspace + 3);
	assert(po.tmpspace[0] == 0x6F);
	assert(po.tmpspace[1] == 0xf0);
	assert(po.tmpspace[2] == 0xfe);
	assert(po.tmpspace[3] == 0xff);
	assert(po.tmpspace[4] == 0xff);
	assert(po.tmpspace[5] == 0xff);
	assert(po.tmpspace[6] == 0xfe);

}

/*
 * Add N bits after P bits. Should result in N+P bits added.
 */
static void
check_asn_bits_encoding_auto() {
    int prior, next;
    int ret, i;

    for(prior = 0; prior <= 31; prior++) {
      for(next = 0; next <= 31; next++) {
        asn_bit_outp_t po;
        po.buffer = po.tmpspace;
        po.nboff = 0;
        po.nbits = 0;
        po.output = Ignore;
        po.op_key = 0;
        po.tmpspace[0] = 0xff;

        ret = asn_put_few_bits(&po, -1, prior);
        assert(ret == 0);

		ASN_DEBUG(" (out{nboff=%d,nbits=%d,buf_offset=%d})", (int)po.nboff, (int)po.nbits, (int)(po.buffer - po.tmpspace));

        ret = asn_put_few_bits(&po, -1, next);
        assert(ret == 0);

		ASN_DEBUG(" (out{nboff=%d,nbits=%d,buf_offset=%d})", (int)po.nboff, (int)po.nbits, (int)(po.buffer - po.tmpspace));

		ASN_DEBUG("Putting %d + %d bits (%d/%d), got %d bytes and %d bits",
            prior, next, (prior + next) / 8, (prior + next) % 8,
            (int)(po.buffer - po.tmpspace), (int)po.nboff);
        assert((po.buffer - po.tmpspace) * 8 + po.nboff == (size_t)(prior + next));
        for(i = 0; i < (po.buffer - po.tmpspace); i++)
            assert(po.tmpspace[0] == (unsigned char)-1);
      }
    }
}

static void
check_asn_bits_sweep_with(uint8_t buf[], int already_bits, int add_bits) {
	size_t buf_size = 8;
	asn_bit_data_t pos;
	asn_bit_outp_t out;
	int32_t d_already;
	int32_t d_add;
	int32_t d_left;
	int left_bits;

	memset(&pos, 0, sizeof(pos));
	pos.buffer = buf;
	pos.nboff = 0;
	pos.nbits = buf_size * 8;

	memset(&out, 0, sizeof(out));
	out.buffer = out.tmpspace;
	out.nbits = 8 * sizeof(out.tmpspace);
	assert(sizeof(out.tmpspace) >= buf_size);
	memcpy(out.buffer, buf, buf_size);

	d_already = asn_get_few_bits(&pos, already_bits);
	d_add = asn_get_few_bits(&pos, add_bits);

	asn_put_few_bits(&out, d_already, already_bits);
	asn_put_few_bits(&out, d_add, add_bits);
	if(out.nboff % 8) {
		left_bits = 8 - (out.nboff % 8);
		d_left = asn_get_few_bits(&pos, left_bits);
	} else {
		left_bits = 0;
		d_left = 0;
	}
	asn_put_few_bits(&out, d_left, left_bits);
	assert(0 == (out.nboff % 8));

	if(0 != memcmp(out.tmpspace, buf, buf_size)) {
		printf("IN: ");
		for(size_t i = 0; i < buf_size; i++)
			printf(" %02x", buf[i]);
		printf("\nOUT:");
		for(size_t i = 0; i < buf_size; i++)
			printf(" %02x", out.tmpspace[i]);
		printf(" (out{nboff=%d,left=%d,%02x})\n", (int)out.nboff, left_bits, (int)d_left);
		assert(0 == memcmp(out.tmpspace, buf, buf_size));
	}
}

static void
check_asn_bits_sweep() {
	uint8_t buf[3][8] = {
		{ 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA },
		{ 0xB7, 0x19, 0x2F, 0xEE, 0xAD, 0x11, 0xAA, 0x55 },
		{ 0xEE, 0xAD, 0x11, 0xAA, 0x55, 0xB7, 0x19, 0x2F }
	};
	int already_bits;
	int add_bits;
	int buf_idx;

	for(buf_idx = 0; buf_idx < 3; buf_idx++) {
	 for(already_bits = 0; already_bits < 24; already_bits++) {
	  for(add_bits = 0; add_bits <= 31; add_bits++) {
	   check_asn_bits_sweep_with(buf[buf_idx], already_bits, add_bits);
	  }
	 }
	}
}

int
main() {
	check_asn_bits_decoding();
	check_asn_bits_encoding();
	check_asn_bits_encoding_auto();
	check_asn_bits_sweep();
	return 0;
}
