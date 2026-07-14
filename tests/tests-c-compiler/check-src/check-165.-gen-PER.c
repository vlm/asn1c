/*
 * UPER forward compatibility: an old decoder must skip the unknown
 * extension additions produced by a newer version of the protocol and
 * keep decoding the remaining fields (X.691).
 * The golden byte streams below were produced from abstract values by
 * a commercial ASN.1 toolchain (the project's interoperability
 * reference), cross-checked with the independent asn1tools codec, from
 * a newer version of this module:
 *   T': SEQUENCE { seq1 MsgCount, ..., seq10 MsgCount OPTIONAL }
 *       (a single flat, ungrouped extension addition -- value
 *       { seq1 1, seq10 9 })
 *   C': CHOICE { c1, c2, ..., c3 MsgCount }                   (c3 chosen)
 *   M': SEQUENCE { a MsgCount, t T', b MsgCount }
 *       (value { a 5, t { seq1 1, seq10 9 }, b 7 }, to check that a
 *       SEQUENCE field *following* another SEQUENCE with a skipped
 *       extension is also recovered correctly, mirroring the N test
 *       below for CHOICE)
 */
#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <T.h>
#include <C.h>
#include <N.h>
#include <M.h>

int main() {
	asn_dec_rval_t rv;

	/*
	 * A SEQUENCE with one unknown extension addition present:
	 * ext-present=1, seq1=1, 1-bit ext bitmap 1, one open type
	 * (1 byte of content, holding seq10=9 padded to an octet).
	 */
	static const unsigned char seq_ext[] =
		"\x81\x01\x01\x12";
	T_t *t = 0;
	rv = uper_decode(0, &asn_DEF_T, (void *)&t, seq_ext,
			sizeof(seq_ext) - 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(t->seq1 == 1);
	ASN_STRUCT_FREE(asn_DEF_T, t);

	/*
	 * A CHOICE selecting an alternative unknown to this version:
	 * ext=1, extension index 0 (c3), open type of 1 byte (value 9).
	 * Must decode as "no alternative selected" instead of failing.
	 */
	static const unsigned char cho_ext[] = "\x80\x01\x12";
	C_t *c = 0;
	rv = uper_decode(0, &asn_DEF_C, (void *)&c, cho_ext,
			sizeof(cho_ext) - 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(c->present == C_PR_NOTHING);
	ASN_STRUCT_FREE(asn_DEF_C, c);

	/*
	 * The same unknown CHOICE alternative nested in a SEQUENCE:
	 * the fields after the CHOICE must still be recovered.
	 * { a 5, ch c3:9, b 7 }
	 */
	static const unsigned char nest_ext[] = "\x0b\x00\x02\x24\x1c";
	N_t *n = 0;
	rv = uper_decode(0, &asn_DEF_N, (void *)&n, nest_ext,
			sizeof(nest_ext) - 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(n->a == 5);
	assert(n->ch.present == C_PR_NOTHING);
	assert(n->b == 7);
	ASN_STRUCT_FREE(asn_DEF_N, n);

	/*
	 * A SEQUENCE-with-skipped-extension nested in another SEQUENCE:
	 * the field after it must still be recovered (the SEQUENCE
	 * analogue of the CHOICE case above).
	 * { a 5, t { seq1 1 (seq10 unknown, skipped) }, b 7 }
	 */
	static const unsigned char nest_seq[] = "\x0b\x02\x02\x02\x24\x1c";
	M_t *m = 0;
	rv = uper_decode(0, &asn_DEF_M, (void *)&m, nest_seq,
			sizeof(nest_seq) - 1, 0, 0);
	assert(rv.code == RC_OK);
	assert(m->a == 5);
	assert(m->t.seq1 == 1);
	assert(m->b == 7);
	ASN_STRUCT_FREE(asn_DEF_M, m);

	/* Sanity: same-version encodings still round-trip. */
	unsigned char buf[8];
	T_t t0;
	memset(&t0, 0, sizeof(t0));
	t0.seq1 = 5;
	asn_enc_rval_t er = uper_encode_to_buffer(&asn_DEF_T, 0, &t0,
			buf, sizeof(buf));
	assert(er.encoded == 8);
	assert(buf[0] == 0x05);

	C_t c0;
	memset(&c0, 0, sizeof(c0));
	c0.present = C_PR_c1;
	c0.choice.c1 = 9;
	er = uper_encode_to_buffer(&asn_DEF_C, 0, &c0, buf, sizeof(buf));
	assert(er.encoded == 9);
	assert(buf[0] == 0x04 && buf[1] == 0x80);

	printf("Finished OK\n");
	return 0;
}
