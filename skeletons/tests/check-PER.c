#include <per_support.c>
#include <assert.h>

static void
check_per_decoding() {
	uint8_t buf[] = { 0xB7, 0x19, 0x2F, 0xEE, 0xAD };
	uint8_t tmpbuf[10];
	int32_t z;
	asn_per_data_t pos;

	pos.buffer = buf;
	pos.nboff = 0;
	pos.nbits = sizeof(buf) * 8;

	z = per_get_few_bits(&pos, 32);
	assert(z == -1);
	assert(pos.nbits == sizeof(buf) * 8);

	z = per_get_few_bits(&pos, 0);
	assert(z == 0);
	assert(pos.nboff == 0);
	assert(pos.nbits == sizeof(buf) * 8);

	z = per_get_few_bits(&pos, 1);
	assert(z == 1);
	assert(pos.nboff == 1);
	assert(pos.nbits == sizeof(buf) * 8);

	z = per_get_few_bits(&pos, 2);
	assert(z == 1);
	assert(pos.nboff == 3);
	assert(pos.nbits == sizeof(buf) * 8);

	z = per_get_few_bits(&pos, 2);
	assert(z == 2);
	assert(pos.nboff == 5);
	assert(pos.nbits == sizeof(buf) * 8);

	z = per_get_few_bits(&pos, 3);
	assert(z == 7);
	assert(pos.nboff == 8);
	assert(pos.nbits == sizeof(buf) * 8);

	z = per_get_few_bits(&pos, 8);
	assert(z == 0x19);
	assert(pos.nboff == 8);
	assert(pos.nbits == (sizeof(buf) - 1) * 8);

	z = per_get_few_bits(&pos, 1);
	assert(z == 0);
	assert(pos.nboff == 1);
	assert(pos.nbits == (sizeof(buf) - 2) * 8);

	z = per_get_few_bits(&pos, 3);
	assert(z == 2);
	assert(pos.nboff == 4);
	assert(pos.nbits == (sizeof(buf) - 2) * 8);

	z = per_get_few_bits(&pos, 8);
	assert(z == 254);
	assert(pos.nboff == 12);

	pos.buffer = buf;
	pos.nboff = 2;
	pos.nbits = sizeof(buf) * 8;
	z = per_get_few_bits(&pos, 24);
	assert(z == 14443711);

	/* Get full 31-bit range */
	pos.buffer = buf;
	pos.nboff = 7;
	pos.nbits = sizeof(buf) * 8;
	z = per_get_few_bits(&pos, 31);
	assert(z == 1179384747);

	/* Get a bit shifted range */
	pos.buffer = buf;
	pos.nboff = 6;
	pos.nbits = sizeof(buf) * 8;
	z = per_get_few_bits(&pos, 31);
	assert(z == 1663434197);

	pos.buffer = buf;
	pos.nboff = 0;
	pos.nbits = sizeof(buf) * 8;
	z = per_get_many_bits(&pos, tmpbuf, 0, sizeof(buf) * 8);
	assert(z == 0);
	assert(buf[0] == tmpbuf[0]);
	assert(buf[1] == tmpbuf[1]);
	assert(buf[2] == tmpbuf[2]);
	assert(buf[3] == tmpbuf[3]);
	assert(buf[4] == tmpbuf[4]);

	pos.buffer = buf;
	pos.nboff = 1;
	pos.nbits = sizeof(buf) * 8;
	z = per_get_many_bits(&pos, tmpbuf, 0, sizeof(buf) * 8);
	assert(z == -1);

	pos.buffer = buf;
	pos.nboff = 1;
	pos.nbits = sizeof(buf) * 8;
	z = per_get_many_bits(&pos, tmpbuf, 0, sizeof(buf) * 8 - 1);
	assert(z == 0);
	assert(tmpbuf[0] == 110);
	assert(tmpbuf[1] == 50);
	assert(tmpbuf[2] == 95);
	assert(tmpbuf[3] == 221);
	assert(tmpbuf[4] == 90);

	pos.buffer = buf;
	pos.nboff = 1;
	pos.nbits = sizeof(buf) * 8;
	z = per_get_many_bits(&pos, tmpbuf, 1, sizeof(buf) * 8 - 1);
	assert(z == 0);
	assert(tmpbuf[0] == 55);
	assert(tmpbuf[0] != buf[0]);
	assert(tmpbuf[1] == buf[1]);
	assert(tmpbuf[2] == buf[2]);
	assert(tmpbuf[3] == buf[3]);
	assert(tmpbuf[4] == buf[4]);
}

static int Ignore(const void *data, size_t size, void *op_key) {
	return 0;
}

static void
check_per_encoding() {
	asn_per_outp_t po;
	int ret;

	po.buffer = po.tmpspace;
	po.nboff = 0;
	po.nbits = 0;
	po.outper = Ignore;
	po.op_key = 0;
	po.tmpspace[0] = 0xff;

	ret = per_put_few_bits(&po, 0, 0);
	assert(ret == 0);
	assert(po.nboff == 0);
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0xff);

	ret = per_put_few_bits(&po, 0, 1);
	assert(ret == 0);
	assert(po.nboff == 1);
	assert(po.nbits == 8 * sizeof(po.tmpspace));
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0x00);

	ret = per_put_few_bits(&po, 1, 1);
	assert(ret == 0);
	assert(po.nboff == 2);
	assert(po.nbits == 8 * sizeof(po.tmpspace));
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0x40);

	ret = per_put_few_bits(&po, 1, 1);
	assert(ret == 0);
	assert(po.nboff == 3);
	assert(po.nbits == 8 * sizeof(po.tmpspace));
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0x60);

	ret = per_put_few_bits(&po, 15, 5);
	assert(ret == 0);
	assert(po.nboff == 8);
	assert(po.nbits == 8 * sizeof(po.tmpspace));
	assert(po.buffer == po.tmpspace);
	assert(po.tmpspace[0] == 0x6F);

	ret = per_put_few_bits(&po, 0xf0ff, 16);
	assert(ret == 0);
	assert(po.nboff == 16);
	assert(po.nbits == 8 * sizeof(po.tmpspace) - 8);
	assert(po.buffer == po.tmpspace + 1);
	assert(po.tmpspace[0] == 0x6F);
	assert(po.tmpspace[1] == 0xf0);
	assert(po.tmpspace[2] == 0xff);

	po.nboff--;

	ret = per_put_few_bits(&po, 2, 1);
	assert(ret == 0);
	assert(po.nboff == 8);
	assert(po.nbits == 8 * sizeof(po.tmpspace) - 16);
	assert(po.buffer == po.tmpspace + 2);
	assert(po.tmpspace[0] == 0x6F);
	assert(po.tmpspace[1] == 0xf0);
	assert(po.tmpspace[2] == 0xfe);

	ret = per_put_few_bits(&po, 2, 32);
	assert(ret == -1);

	ret = per_put_few_bits(&po, 2, -1);
	assert(ret == -1);

	ret = per_put_few_bits(&po, -1, 31);
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

int
main() {
	check_per_decoding();
	check_per_encoding();
	return 0;
}
