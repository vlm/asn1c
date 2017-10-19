#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <DefaultSequence.h>
#include <DefaultSet.h>

uint8_t berSeq1[] = {
  32 | 16, /* [UNIVERSAL 16], constructed */
  6, /* L */
  /* aBool BOOLEAN */
  ((2 << 6) + 0), /* [0], primitive */
  1, /* L */
  0, /* FALSE */
  /* anInteger INTEGER */
  ((2 << 6) + 1), /* [1], primitive */
  1, /* L */
  1
};

uint8_t derSeq1[] = {
  32 | 16, /* [UNIVERSAL 16], constructed */
  3, /* L */
  /* anInteger INTEGER */
  ((2 << 6) + 1), /* [1], primitive */
  1, /* L */
  1
};

uint8_t berSeq2[] = {
  32 | 16, /* [UNIVERSAL 16], constructed */
  3, /* L */
  /* aBool BOOLEAN */
  ((2 << 6) + 0), /* [0], primitive */
  1, /* L */
  0 /* FALSE */
};

uint8_t derSeq2[] = {
  32 | 16, /* [UNIVERSAL 16], constructed */
  0 /* L */
};

uint8_t berSet1[] = {
  32 | 17, /* [UNIVERSAL 17], constructed */
  6, /* L */
  /* aBool BOOLEAN */
  ((2 << 6) + 0), /* [0], primitive */
  1, /* L */
  0, /* FALSE */
  /* anInteger INTEGER */
  ((2 << 6) + 1), /* [1], primitive */
  1, /* L */
  1
};

uint8_t derSet1[] = {
  32 | 17, /* [UNIVERSAL 17], constructed */
  3, /* L */
  /* anInteger INTEGER */
  ((2 << 6) + 1), /* [1], primitive */
  1, /* L */
  1
};

uint8_t berSet2[] = {
  32 | 17, /* [UNIVERSAL 17], constructed */
  3, /* L */
  /* aBool BOOLEAN */
  ((2 << 6) + 0), /* [0], primitive */
  1, /* L */
  0 /* FALSE */
};

uint8_t derSet2[] = {
  32 | 17, /* [UNIVERSAL 17], constructed */
  0 /* L */
};

uint8_t buf2[128];
int buf2_pos;

static int
buf2_fill(const void *buffer, size_t size, void *app_key) {

	(void)app_key;

	if(buf2_pos + size > sizeof(buf2))
		return -1;

	memcpy(buf2 + buf2_pos, buffer, size);
	buf2_pos += size;

	return 0;
}

static void
compare_encoding(asn_enc_rval_t *erval, uint8_t *expected, size_t expected_size,
                 uint8_t *actual) {

  assert(erval->encoded != -1);
  if((size_t)erval->encoded != expected_size) {
    printf("%d != %d\n", (int)erval->encoded, (int)expected_size);
    assert((size_t)erval->encoded == expected_size);
  }
  for(size_t i = 0; i < expected_size; i++) {
      if(expected[i] != actual[i]) {
          fprintf(stderr, "Recreated buffer content mismatch:\n");
          fprintf(stderr, "Byte %zu, %x != %x (%d != %d)\n", i, expected[i],
                  actual[i], expected[i], actual[i]);
      }
      assert(expected[i] == actual[i]);
  }
}

static void
check_sequence(uint8_t *in, size_t in_size, uint8_t *expected,
               size_t expected_size) {
  DefaultSequence_t t, *tp;
  void *tpp = &tp;
  asn_dec_rval_t rval;
  asn_enc_rval_t erval;

  tp = memset(&t, 0, sizeof(t));

  /* Try to decode the BER encoding. */ 
  rval = ber_decode(0, &asn_DEF_DefaultSequence, (void**)tpp, in, in_size);
  assert(rval.code == RC_OK);
  assert(rval.consumed == in_size);

  /* Try to re-create using DER encoding. */
  buf2_pos = 0;
  erval = der_encode(&asn_DEF_DefaultSequence, tp, buf2_fill, 0);
  compare_encoding(&erval, expected, expected_size, buf2);

  ASN_STRUCT_RESET(asn_DEF_DefaultSequence, tp);
}

static void
check_set(uint8_t *in, size_t in_size, uint8_t *expected,
          size_t expected_size) {
  DefaultSet_t t, *tp;
  void *tpp = &tp;
  asn_dec_rval_t rval;
  asn_enc_rval_t erval;

  tp = memset(&t, 0, sizeof(t));

  /* Try to decode the BER encoding. */ 
  rval = ber_decode(0, &asn_DEF_DefaultSet, (void**)tpp, in, in_size);
  assert(rval.code == RC_OK);
  assert(rval.consumed == in_size);

  /* Try to re-create using DER encoding. */
  buf2_pos = 0;
  erval = der_encode(&asn_DEF_DefaultSet, tp, buf2_fill, 0);
  compare_encoding(&erval, expected, expected_size, buf2);
  ASN_STRUCT_RESET(asn_DEF_DefaultSet, tp);
}

int
main(int ac, char **av) {

  (void)ac; /* Unused argument */
  (void)av; /* Unused argument */

  check_sequence(berSeq1, sizeof(berSeq1), derSeq1, sizeof(derSeq1));
  check_sequence(berSeq2, sizeof(berSeq2), derSeq2, sizeof(derSeq2));
  check_set(berSet1, sizeof(berSet1), derSet1, sizeof(derSet1));
  check_set(berSet2, sizeof(berSet2), derSet2, sizeof(derSet2));
}
