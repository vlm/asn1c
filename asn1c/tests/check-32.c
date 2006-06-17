#undef	NDEBUG
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <assert.h>

#include <Programming.h>
#include <SeqWithMandatory.h>
#include <SeqWithOptional.h>

int
main(int ac, char **av) {
	Programming_t p;
	SeqWithMandatory_t swm;
	SeqWithOptional_t *swo = 0;
	Error_t *err;
	asn_enc_rval_t erv;
	asn_dec_rval_t drv;
	char buf[128];
	size_t bufsize = sizeof(buf);

	(void)ac;	/* Unused argument */
	(void)av;	/* Unused argument */

	/*
	 * No plans to fill Programming_t up:
	 * just checking whether it compiles or not.
	 */
	memset(&p, 0, sizeof(p));

	/*
	 * Construct a dummy sequence:
	 * SeqWithMandatory ::= {
	 * 	seqOfMan [0] EXPLICIT SEQUENCE OF Error
	 * }
	 */
	err = calloc(1, sizeof *err);
	memset(&swm, 0, sizeof swm);
	OCTET_STRING_fromBuf(&swm.someString, "Oley", 4);
	ASN_SEQUENCE_ADD(&swm.seqOfMan, err);

	/*
	 * Encode the sequence.
	 */
	erv = der_encode_to_buffer(&asn_DEF_SeqWithMandatory,
			&swm, buf, &bufsize);
	assert(erv.encoded == bufsize);

	/*
	 * Try to decode it using a compatible type.
	 */
	drv = ber_decode(0, &asn_DEF_SeqWithOptional, (void **)&swo,
			buf, bufsize);
	assert(drv.code == RC_OK);
	assert(drv.consumed == bufsize);
	assert(swo->seqOfOpt != 0);

	xer_fprint(stderr, &asn_DEF_SeqWithOptional, swo);
	swo->seqOfOpt = 0;

	bufsize = sizeof(buf);
	erv = der_encode_to_buffer(&asn_DEF_SeqWithOptional,
			swo, buf, &bufsize);
	assert(erv.encoded == bufsize);

	swo = 0;
	drv = ber_decode(0, &asn_DEF_SeqWithMandatory, (void **)&swo,
			buf, bufsize);
	assert(drv.code != RC_OK);
	swo = 0;
	drv = ber_decode(0, &asn_DEF_SeqWithOptional, (void **)&swo,
			buf, bufsize);
	assert(drv.code == RC_OK);
	assert(drv.consumed == bufsize);
	assert(swo->seqOfOpt == 0);

	xer_fprint(stderr, &asn_DEF_SeqWithOptional, swo);

	printf("Finished\n");

	return 0;
}
