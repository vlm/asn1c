#define	__NO_ASN_TABLE__
#include "../GeneralizedTime.c"
#include "../constraints.c"

static void
check(char *time_str, time_t sample) {
	GeneralizedTime_t gt;
	struct tm tm;
	time_t tloc;

	gt.buf = time_str;
	gt.size = strlen(time_str);

	tloc = asn_GT2time(&gt, &tm);
	printf("[%s] -> %ld == %ld\n", time_str, (long)tloc, (long)sample);
	if(tloc != -1)
	printf("\t%d-%d-%dT%02d:%02d:%02d %ld\n",
		tm.tm_year + 1900,
		tm.tm_mon + 1,
		tm.tm_mday,
		tm.tm_hour,
		tm.tm_min,
		tm.tm_sec,
		tm.tm_gmtoff
	);
	assert(tloc == sample);
}

int
main(int ac, char **av) {

	check("200401250", -1);
	check("2004012509300", -1);
	check("20040125093000-", -1);
	check("20040125093007-0", -1);
	check("20040125093007-080", -1);
	check("200401250930.01Z", -1);

	check("20040125093007Z", 1075023007);
	check("20040125093007+00", 1075023007);
	check("20040125093007.01+0000", 1075023007);
	check("20040125093007,1+0000", 1075023007);
	check("20040125093007-0800", 1075051807);

	if(ac > 1) {
		/* These will be valid only inside PST time zone */
		check("20040125093007", 1075051807);
		check("200401250930", 1075051800);
		check("20040125093000,01", 1075051800);
		check("20040125093000,1234", 1075051800);
	}

	return 0;
}
