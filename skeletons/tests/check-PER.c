#include <per_support.c>
#include <assert.h>

int
main() {
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

	return 0;
}
