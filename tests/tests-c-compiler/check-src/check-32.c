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
			&swm, buf, sizeof buf);
	assert(erv.encoded > 0);
	buf[erv.encoded] = '\0';

	/*
	 * Try to decode it using a compatible type.
	 */
	drv = ber_decode(0, &asn_DEF_SeqWithOptional, (void **)&swo,
			buf, erv.encoded);
	assert(drv.code == RC_OK);
	assert((ssize_t)drv.consumed == erv.encoded);
	assert(swo->seqOfOpt != 0);

	xer_fprint(stderr, &asn_DEF_SeqWithOptional, swo);
	void *tmp = swo->seqOfOpt;
	swo->seqOfOpt = 0;

	erv = der_encode_to_buffer(&asn_DEF_SeqWithOptional,
			swo, buf, sizeof buf);
	assert(erv.encoded > 0);
	buf[erv.encoded] = '\0';

	swo->seqOfOpt = tmp;
	ASN_STRUCT_RESET(asn_DEF_SeqWithMandatory, &swm);
	ASN_STRUCT_FREE(asn_DEF_SeqWithOptional, swo);
	swo = 0;

	drv = ber_decode(0, &asn_DEF_SeqWithMandatory, (void **)&swo,
			buf, erv.encoded);
	assert(drv.code != RC_OK);
	ASN_STRUCT_FREE(asn_DEF_SeqWithOptional, swo);
	swo = 0;
	drv = ber_decode(0, &asn_DEF_SeqWithOptional, (void **)&swo,
			buf, erv.encoded);
	assert(drv.code == RC_OK);
	assert((ssize_t)drv.consumed == erv.encoded);
	assert(swo->seqOfOpt == 0);

	xer_fprint(stderr, &asn_DEF_SeqWithOptional, swo);
	ASN_STRUCT_FREE(asn_DEF_SeqWithOptional, swo);

	printf("Finished\n");

	return 0;
}
