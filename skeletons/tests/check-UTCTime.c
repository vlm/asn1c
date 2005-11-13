#define	__ASN_INTERNAL_TEST_MODE__
#include <GeneralizedTime.c>
#include <UTCTime.c>
#include <constraints.c>

static void
check(char *time_str, time_t sample, int as_gmt) {
	UTCTime_t gt;
	struct tm tm;
	time_t tloc;

	gt.buf = (uint8_t *)time_str;
	gt.size = strlen(time_str);

	tloc = asn_UT2time(&gt, &tm, as_gmt);
	printf("[%s] -> %ld == %ld\n", time_str, (long)tloc, (long)sample);
	if(tloc != -1)
	printf("\t%d-%d-%dT%02d:%02d:%02d %ld\n",
		tm.tm_year + 1900,
		tm.tm_mon + 1,
		tm.tm_mday,
		tm.tm_hour,
		tm.tm_min,
		tm.tm_sec,
		GMTOFF(tm)
	);
	assert(tloc == sample);

	assert(tloc == -1 || as_gmt == 0 || GMTOFF(tm) == 0);

	if(as_gmt) check(time_str, sample, as_gmt);
}

int
main(int ac, char **av) {

	(void)av;

	check("0401250", -1, 0);
	check("0401250930", -1, 0);	/* "Z" or "(+|-)hhmm" required */
	check("04012509300", -1, 0);
	check("040125093000-", -1, 0);
	check("040125093007-0", -1, 0);
	check("040125093007-080", -1, 0);
	check("0401250930.01Z", -1, 0);

	check("040125093007Z", 1075023007, 0);
	check("040125093007+00", 1075023007, 0);
	check("040125093007-0800", 1075051807, 0);

	if(ac > 1) {
		/* These will be valid only inside PST time zone */
		check("040125093007", 1075051807, 0);
		check("040125093000,01", 1075051800, 0);
		check("040125093000,1234", 1075051800, 0);
	}

	return 0;
}


/*
 * Dummy function.
 */

asn_enc_rval_t
OCTET_STRING_encode_der(asn_TYPE_descriptor_t *td, void *ptr, int tag_mode, ber_tlv_tag_t tag, asn_app_consume_bytes_f *cb, void *app_key) {
	asn_enc_rval_t erval;

	(void)td;
	(void)ptr;
	(void)tag_mode;
	(void)tag;
	(void)cb;
	(void)app_key;

	memset(&erval, 0, sizeof(erval));
	return erval;
}

asn_enc_rval_t
OCTET_STRING_encode_xer_utf8(asn_TYPE_descriptor_t *td, void *ptr, int ilevel, enum xer_encoder_flags_e flags, asn_app_consume_bytes_f *cb, void *app_key) {
	asn_enc_rval_t erval;

	(void)td;
	(void)ptr;
	(void)ilevel;
	(void)flags;
	(void)cb;
	(void)app_key;

	memset(&erval, 0, sizeof(erval));
	return erval;
}
