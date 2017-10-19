#include <stdio.h>
#include <assert.h>
#include <time.h>

#include <GeneralizedTime.c>
#include <UTCTime.h>

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

static void
compare(int lineno, int cmp_control, const char *astr, const char *bstr) {
    UTCTime_t a = {(uint8_t *)strdup(astr), strlen(astr), {0, 0, 0, 0, 0}};
    UTCTime_t b = {(uint8_t *)strdup(bstr), strlen(bstr), {0, 0, 0, 0, 0}};
    int cmp_result =
        asn_DEF_UTCTime.op->compare_struct(&asn_DEF_UTCTime, &a, &b);
    if(cmp_result != cmp_control) {
        fprintf(stderr, "%03d: [%s] == [%s] = %d, expected %d\n", lineno, astr,
                bstr, cmp_result, cmp_control);
        assert(cmp_result == cmp_control);
    }
    ASN_STRUCT_RESET(asn_DEF_UTCTime, &a);
    ASN_STRUCT_RESET(asn_DEF_UTCTime, &b);
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

    compare(__LINE__, 0, "040125093007", "040125093007");
    compare(__LINE__, 0, "040125093007-0000", "040125093007Z");
    compare(__LINE__, 1, "040125093008", "040125093007");
    compare(__LINE__, 1, "040125093008-0000", "040125093007-0000");
    compare(__LINE__, 0, "040125093008-0000", "040125093008-0000");
    compare(__LINE__, 1, "040125093008-0000", "040125093007Z");
    compare(__LINE__, 0, "040125093007-0000", "040125093007+0000");
    compare(__LINE__, 1, "040125093007-0030", "040125093007Z");
    compare(__LINE__, -1, "040125093007+0030", "040125093007Z");

	return 0;
}

