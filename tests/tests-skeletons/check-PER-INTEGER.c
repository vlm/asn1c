#include <stdio.h>
#include <assert.h>

#include <INTEGER.h>
#include <INTEGER.c>
#include <per_support.c>
#include <per_support.h>

static int FailOut(const void *data, size_t size, void *op_key) {
    (void)data;
    (void)size;
    (void)op_key;
	assert(!"UNREACHABLE");
	return 0;
}

static void normalize(asn_per_outp_t *po) {
	if(po->nboff >= 8) {
		po->buffer += (po->nboff >> 3);
		po->nbits  -= (po->nboff & ~0x07);
		po->nboff  &= 0x07;
	}
}

static void
check_per_encode_constrained(int lineno, int unsigned_, long value, long lbound, unsigned long ubound, int bit_range) {
	INTEGER_t st;
	INTEGER_t *reconstructed_st = 0;
	struct asn_INTEGER_specifics_s specs;
	struct asn_per_constraints_s cts;
	asn_enc_rval_t enc_rval;
	asn_dec_rval_t dec_rval;
	asn_per_outp_t po;
	asn_per_data_t pd;

	if(unsigned_)
		printf("%d: Recoding %s %lu [%ld..%lu]\n", lineno,
		  unsigned_ ? "unsigned" : "signed", value, lbound, ubound);
	else
		printf("%d: Recoding %s %ld [%ld..%lu]\n", lineno,
		  unsigned_ ? "unsigned" : "signed", value, lbound, ubound);

    if(ubound > LONG_MAX) {
        printf("Skipped test, unsupported\n");
        return;
    }

	memset(&st, 0, sizeof(st));
	memset(&po, 0, sizeof(po));
	memset(&pd, 0, sizeof(pd));
	memset(&cts, 0, sizeof(cts));
	memset(&specs, 0, sizeof(specs));

	cts.value.flags = APC_CONSTRAINED;
	cts.value.range_bits = bit_range;
	cts.value.effective_bits = bit_range;
	cts.value.lower_bound = lbound;
	cts.value.upper_bound = ubound;

	if(unsigned_)
		asn_ulong2INTEGER(&st, (unsigned long)value);
	else
		asn_long2INTEGER(&st, value);

	po.buffer = po.tmpspace;
	po.nboff = 0;
	po.nbits = 8 * sizeof(po.tmpspace);
	po.output = FailOut;

	specs.field_width = sizeof(long);
	specs.field_unsigned = unsigned_;

	asn_DEF_INTEGER.specifics = &specs;
	enc_rval = INTEGER_encode_uper(&asn_DEF_INTEGER, &cts, &st, &po);
	assert(enc_rval.encoded == 0);

	normalize(&po);

	assert(po.buffer == &po.tmpspace[bit_range / 8]);

	if(unsigned_) {
		unsigned long recovered_value =
			  ((uint32_t)po.tmpspace[0] << 24)
			| ((uint32_t)po.tmpspace[1] << 16)
			| ((uint32_t)po.tmpspace[2] << 8)
			| ((uint32_t)po.tmpspace[3] << 0);
		recovered_value >>= (32 - bit_range);
		recovered_value += cts.value.lower_bound;
		assert(recovered_value == (unsigned long)value);
	} else {
		long recovered_value =
			  ((uint32_t)po.tmpspace[0] << 24)
			| ((uint32_t)po.tmpspace[1] << 16)
			| ((uint32_t)po.tmpspace[2] << 8)
			| ((uint32_t)po.tmpspace[3] << 0);
		recovered_value = (unsigned long)recovered_value >> (32 - bit_range);
        if(per_long_range_unrebase(recovered_value, cts.value.lower_bound,
                                   cts.value.upper_bound, &recovered_value)
           < 0) {
            assert(!"Unreachable");
        }
		assert(recovered_value == value);
	}
	assert(po.nboff == (size_t)((bit_range == 32) ? 0 : (8 - (32 - bit_range))));
	assert(po.nbits ==  8 * (sizeof(po.tmpspace) - (po.buffer-po.tmpspace)));
	assert(po.flushed_bytes == 0);

	pd.buffer = po.tmpspace;
	pd.nboff = 0;
	pd.nbits = 8 * (po.buffer - po.tmpspace) + po.nboff;
	pd.moved = 0;
	dec_rval = INTEGER_decode_uper(0, &asn_DEF_INTEGER, &cts,
					(void **)&reconstructed_st, &pd);
	assert(dec_rval.code == RC_OK);
	if(unsigned_) {
		unsigned long reconstructed_value = 0;
		asn_INTEGER2ulong(reconstructed_st, &reconstructed_value);
		assert(reconstructed_value == (unsigned long)value);
	} else {
		long reconstructed_value = 0;
		asn_INTEGER2long(reconstructed_st, &reconstructed_value);
		assert(reconstructed_value == value);
	}
	ASN_STRUCT_RESET(asn_DEF_INTEGER, &st);
	ASN_STRUCT_FREE(asn_DEF_INTEGER, reconstructed_st);
}

#define	CHECK(u, v, l, r, b)	\
	check_per_encode_constrained(__LINE__, u, v, l, r, b)

int
main() {
  int unsigned_;
  for(unsigned_ = 0; unsigned_ < 2; unsigned_++) {
	int u = unsigned_;

	/* Encode a signed 0x8babab into a range constrained by 0..2^29-1 */
	CHECK(u, 0x8babab, 0, 536870911UL, 29);
	CHECK(u, 0x8babab, 0, 1073741823UL, 30);
	CHECK(u, 0x8babab, 0, 2147483647UL, 31);

	CHECK(u, 0x8babab, 10, 536870901UL, 29);
	CHECK(u, 0x8babab, 10, 1073741803UL, 30);
	CHECK(u, 0x8babab, 10, 2147483607UL, 31);

	CHECK(0, 0x8babab, -10, 536870901UL, 29);
	CHECK(0, 0x8babab, -10, 1073741803UL, 30);
	CHECK(0, 0x8babab, -10, 2147483607UL, 31);

	CHECK(u, 11, 10, 536870901UL, 29);
	CHECK(u, 11, 10, 1073741803UL, 30);
	CHECK(u, 11, 10, 2147483607UL, 31);

	CHECK(0, 1, -10, 536870901UL, 29);
	CHECK(0, 1, -10, 1073741803UL, 30);
	CHECK(0, 1, -10, 2147483607UL, 31);

	CHECK(u, 10, 10, 536870901UL, 29);
	CHECK(u, 10, 10, 1073741803UL, 30);
	CHECK(u, 10, 10, 2147483607UL, 31);

	CHECK(0, 0, -10, 536870901UL, 29);
	CHECK(0, 0, -10, 1073741803UL, 30);
	CHECK(0, 0, -10, 2147483607UL, 31);

	CHECK(0, -1, -10, 536870901UL, 29);
	CHECK(0, -1, -10, 1073741803UL, 30);
	CHECK(0, -1, -10, 2147483607UL, 31);

	CHECK(0, -10, -10, 536870901UL, 29);
	CHECK(0, -10, -10, 1073741803UL, 30);
	CHECK(0, -10, -10, 2147483607UL, 31);

	CHECK(u, 536870901UL, 10, 536870901UL, 29);
	CHECK(u, 1073741803UL, 10, 1073741803UL, 30);
	CHECK(u, 2147483607UL, 10, 2147483607UL, 31);

	CHECK(0, 536870901UL, -10, 536870901UL, 29);
	CHECK(0, 1073741803UL, -10, 1073741803UL, 30);
	CHECK(0, 2147483607UL, -10, 2147483607UL, 31);

	CHECK(0, -2147483648, -2147483648, 2147483647, 32);
	CHECK(0, -10, -2147483648, 2147483647, 32);
	CHECK(0,  -1, -2147483648, 2147483647, 32);
	CHECK(0,   0, INT32_MIN, INT32_MAX, 32);
	CHECK(0,   0, -2147483648, 2147483647, 32);
	CHECK(0,   1, -2147483648, 2147483647, 32);
	CHECK(0,  10, -2147483648, 2147483647, 32);
	CHECK(0,  2147483647, -2147483648, 2147483647, 32);

	CHECK(1,  0, 0, 4294967295UL, 32);
	CHECK(1,  1, 0, 4294967295UL, 32);
	CHECK(1, 10, 0, 4294967295UL, 32);
	CHECK(1, 2000000000, 0, 4294967295UL, 32);
	CHECK(1, 2147483647, 0, 4294967295UL, 32);

#ifdef  TEST_64BIT
	CHECK(1, 2147483648, 0, 4294967295UL, 32);
	CHECK(1, 4000000000, 0, 4294967295UL, 32);
	CHECK(1, 4294967295UL, 0, 4294967295UL, 32);
#endif

	CHECK(1, 10, 10, 4294967285UL, 32);
	CHECK(1, 11, 10, 4294967285UL, 32);

#ifdef  TEST_64BIT
	if(sizeof(long) > sizeof(uint32_t)) {
		CHECK(0,   0, -10, 4294967285UL, 32);
		CHECK(0,   1, -10, 4294967285UL, 32);
		CHECK(0,  -1, -10, 4294967285UL, 32);
		CHECK(0, -10, -10, 4294967285UL, 32);
		CHECK(0, -10, -10, 4294967285UL, 32);
		CHECK(0, 0x8babab, -10, 4294967285UL, 32);

		CHECK(u, 0x8babab, 0, 4294967295UL, 32);
		CHECK(u, 11, 10, 4294967205UL, 32);
		CHECK(u, 10, 10, 4294967205UL, 32);
		CHECK(u, 4294967205UL, 10, 4294967285UL, 32);

		CHECK(0, 4294967205UL, -10, 4294967285UL, 32);
		CHECK(u, 4294967295UL, 1, 4294967295UL, 32);

		CHECK(u, 2000000000, 0, 4294967295UL, 32);
		CHECK(u, 2147483647, 0, 4294967295UL, 32);
		CHECK(u, 2147483648, 0, 4294967295UL, 32);
		CHECK(u, 4000000000, 0, 4294967295UL, 32);
	}
#endif
 }

  return 0;
}
