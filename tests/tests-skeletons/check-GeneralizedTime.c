#include <stdio.h>
#include <assert.h>
#include <time.h>

#include <GeneralizedTime.c>
#include <math.h>	/* for pow(3) */

static void
recognize(char *time_str, time_t expect, int as_gmt) {
	GeneralizedTime_t gt;
	struct tm tm;
	time_t tloc;
	int fv, fp;

	gt.buf = (uint8_t *)time_str;
	gt.size = strlen(time_str);

	tloc = asn_GT2time_frac(&gt, &fv, &fp, &tm, as_gmt);
	printf("%s: [%s] -> %ld == %ld\n",
		as_gmt?"GMT":"ofs", time_str, (long)tloc, (long)expect);

	if(tloc != -1) {
		printf("\t%04d-%02d-%02dT%02d:%02d:%02d.%f(%d/%d)%+03ld%02ld\n",
		tm.tm_year + 1900,
		tm.tm_mon + 1,
		tm.tm_mday,
		tm.tm_hour,
		tm.tm_min,
		tm.tm_sec,
		(double)fv * pow(0.1, fp), fv, fp,
		(GMTOFF(tm) / 3600),
		labs(GMTOFF(tm) % 3600)
		);
	}
	assert(tloc == expect);

#ifdef	HAVE_TM_GMTOFF
	assert(tloc == -1 || as_gmt == 0 || GMTOFF(tm) == 0);
#endif

	if(!as_gmt) recognize(time_str, expect, 1);
}

static void
encode(time_t tloc, const char *expect, int force_gmt) {
	GeneralizedTime_t *gt;
	struct tm tm, *tmp;

	tmp = localtime_r(&tloc, &tm);
	assert(tmp);

	gt = asn_time2GT(0, &tm, force_gmt);
	if(gt) {
		assert(expect);
		printf("[%s] vs [%s] (%d)\n",
			gt->buf, expect, force_gmt);
		assert(gt->size == strlen((char *)gt->buf));
		assert(!strcmp((char *)gt->buf, expect));
	} else {
		assert(!expect);
	}
	ASN_STRUCT_FREE(asn_DEF_GeneralizedTime, gt);
}

#define	RECODE(foo, bar)	recode(__LINE__, foo, bar)

static void
recode(int lineno, char *time_str, const char *expect) {
	int frac_value, frac_digits;
	GeneralizedTime_t gt;
	struct tm tm;
	time_t tloc;
	char *tz;

	gt.buf = (uint8_t *)time_str;
	gt.size = strlen(time_str);

	tloc = asn_GT2time_frac(&gt, &frac_value, &frac_digits, &tm, 1);
	assert(tloc != -1);

	gt.buf = 0;
	asn_time2GT_frac(&gt, &tm, frac_value, frac_digits, 1);
	assert(gt.buf);

	tz = getenv("TZ");
	printf("%d: [%s] (%ld) => [%s] == [%s] (%d, %d) (TZ=%s)\n",
		lineno, time_str, (long)tloc, gt.buf,
		expect, frac_value, frac_digits,
		tz ? tz : "");

	assert(strcmp((char *)gt.buf, expect) == 0);
	FREEMEM(gt.buf);
}

static void
check_fractions() {
	GeneralizedTime_t *gt = 0;
	struct tm tm;
	int fv, fd;
	time_t tloc;

	memset(&tm, 0, sizeof tm);
	tm.tm_year = 70;
	tm.tm_mday = 1;

	gt = asn_time2GT_frac(gt, &tm, -1, -1, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000Z") == 0);

	gt = asn_time2GT_frac(gt, &tm, 0, 0, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000Z") == 0);

	gt = asn_time2GT_frac(gt, &tm, 0, -1, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000Z") == 0);

	gt = asn_time2GT_frac(gt, &tm, -1, 0, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000Z") == 0);

	gt = asn_time2GT_frac(gt, &tm, 10, 0, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000Z") == 0);

	/* Normalization should happen prior to calling the _frac() */
	gt = asn_time2GT_frac(gt, &tm, 55, 2, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000.55Z") == 0);

	gt = asn_time2GT_frac(gt, &tm, 5, 2, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000.05Z") == 0);

	/* Normalization should happen prior calling the _frac() */
	gt = asn_time2GT_frac(gt, &tm, 900, 2, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000Z") == 0);

	gt = asn_time2GT_frac(gt, &tm, 90, 2, 1);
	assert(gt);
	printf("[%s]\n", gt->buf);
	assert(strcmp((char *)gt->buf, "19700101000000.9Z") == 0);

	tloc = asn_GT2time_prec(gt, &fv, 0, 0, 1);
	assert(tloc == 0);
	assert(fv == 0);

	tloc = asn_GT2time_prec(gt, &fv, 1, 0, 1);
	assert(tloc == 0);
	assert(fv == 9);

	tloc = asn_GT2time_prec(gt, &fv, 2, 0, 1);
	assert(tloc == 0);
	assert(fv == 90);

	tloc = asn_GT2time_frac(gt, &fv, &fd, 0, 1);
	assert(tloc == 0);
	assert(fv == 9);
	assert(fd == 1);

	gt->buf[gt->size-1] = '0';
	gt->buf[gt->size++] = 'Z';
	gt->buf[gt->size] = '\0';

	tloc = asn_GT2time_frac(gt, &fv, &fd, 0, 1);
	assert(tloc == 0);
	assert(fd == 2);
	assert(fv == 90);

	tloc = asn_GT2time_prec(gt, &fv, 1, 0, 1);
	assert(tloc == 0);
	assert(fv == 9);

	tloc = asn_GT2time_prec(gt, &fv, 100, 0, 1);
	assert(tloc == 0);
	assert(fv == 0);

	FREEMEM(gt->buf);
	FREEMEM(gt);
}

static void
compare(int lineno, int cmp_control, const char *astr, const char *bstr) {
    GeneralizedTime_t a = {(uint8_t *)strdup(astr), strlen(astr), {0, 0, 0, 0, 0}};
    GeneralizedTime_t b = {(uint8_t *)strdup(bstr), strlen(bstr), {0, 0, 0, 0, 0}};
    int cmp_result = asn_DEF_GeneralizedTime.op->compare_struct(
        &asn_DEF_GeneralizedTime, &a, &b);
    if(cmp_result != cmp_control) {
        fprintf(stderr, "%03d: [%s] == [%s] = %d, expected %d\n", lineno, astr,
                bstr, cmp_result, cmp_control);
        assert(cmp_result == cmp_control);
    }
    ASN_STRUCT_RESET(asn_DEF_GeneralizedTime, &a);
    ASN_STRUCT_RESET(asn_DEF_GeneralizedTime, &b);
}

int
main(int ac, char **av) {
	char *tz = getenv("TZ");

	(void)av;

	printf("TZ = [%s]\n", tz ? tz : "");

	check_fractions();

	recognize("200401250", -1, 0);
	recognize("2004012509300", -1, 0);
	recognize("20040125093000-", -1, 0);
	recognize("20040125093007-0", -1, 0);
	recognize("20040125093007-080", -1, 0);
	recognize("200401250930.01Z", -1, 0);

	/* These six are from X.690:11.7.5 */
	recognize("19920520240000Z", -1, 0);  /* midnight represented incorrectly */
	recognize("19920622123421.0Z", 709216461, 0);  /* spurious trailing zeros */
	recognize("19920722132100.30Z", 711811260, 0); /* spurious trailing zeros */
	recognize("19920521000000Z", 706406400, 0);
	recognize("19920622123421Z", 709216461, 0);
	recognize("19920722132100.3Z", 711811260, 0);

	recognize("20040125093007Z", 1075023007, 0);
	recognize("20040125093007+00", 1075023007, 0);
	recognize("20040125093007.01+0000", 1075023007, 0);
	recognize("20040125093007,1+0000", 1075023007, 0);
	recognize("20040125093007-0800", 1075051807, 0);

	recognize("19920722132100.123000123Z", 711811260, 0);
	recognize("19920722132100.1230000123Z", 711811260, 0);
	recognize("19920722132100.12300000123Z", 711811260, 0);

	encode(1075023007, "20040125093007Z", 1);

	if(ac > 1) {
		/* These will be valid only inside PST time zone */
		recognize("20040125093007", 1075051807, 0);
		recognize("200401250930", 1075051800, 0);
		recognize("20040125093000,01", 1075051800, 0);
		recognize("20040125093000,1234", 1075051800, 0);

		encode(1075023007, "20040125013007-0800", 0);
		RECODE("20050702123312", "20050702193312Z");
	}

#if defined(sun) || defined(__sun) || defined(_sun_) || defined(__solaris__)
	printf("Solaris does not have a decent timegm() function.\n");
#else	/* !solaris */
	RECODE("20050702123312Z", "20050702123312Z");
	RECODE("20050702123312+01", "20050702113312Z");
	RECODE("20050702123312,0+01", "20050702113312Z");
	RECODE("20050702123312,1+01", "20050702113312.1Z");
	RECODE("20050702123312.01+01", "20050702113312.01Z");
	RECODE("20050702123312.00+01", "20050702113312Z");
	RECODE("20050702123312.30+01", "20050702113312.3Z");
	RECODE("20050702123312,30000+01", "20050702113312.3Z");
	RECODE("20050702123312,300000000+01", "20050702113312.3Z");
	RECODE("20050702123312.123456+01", "20050702113312.123456Z");
	RECODE("20050702123312.1234567+01", "20050702113312.1234567Z");
	RECODE("20050702123312.12345678+01", "20050702113312.12345678Z");
	RECODE("20050702123312.123456789+01", "20050702113312.123456789Z");
	RECODE("20050702123312.1234567891+01", "20050702113312.123456789Z");
	RECODE("20050702123312.2000000000+01", "20050702113312.2Z");
	RECODE("20050702123312.3000000000+01", "20050702113312.3Z");
	RECODE("20050702123312.4000000000+01", "20050702113312.4Z");
	RECODE("20050702123312.5000000000+01", "20050702113312.5Z");
	RECODE("20050702123312.5000000011+01", "20050702113312.500000001Z");
	RECODE("20050702123312.5000000001+01", "20050702113312.5Z");
	RECODE("20050702123312.000000001+01", "20050702113312.000000001Z");
	RECODE("20050702123312.0000000001Z", "20050702123312Z");
	RECODE("20050702123312.0000000100Z", "20050702123312.00000001Z");
	RECODE("20050702123312.0080000010+1056", "20050702013712.008000001Z");
#endif

    compare(__LINE__, 0, "20040125093007", "20040125093007");
    compare(__LINE__, 0, "20040125093007-0000", "20040125093007Z");
    compare(__LINE__, 1, "20040125093008", "20040125093007");
    compare(__LINE__, 1, "20040125093008-0000", "20040125093007-0000");
    compare(__LINE__, 0, "20040125093008-0000", "20040125093008-0000");
    compare(__LINE__, 1, "20040125093008-0000", "20040125093007Z");
    compare(__LINE__, 0, "20040125093007-0000", "20040125093007+0000");
    compare(__LINE__, 1, "20040125093007-0030", "20040125093007Z");
    compare(__LINE__, -1, "20040125093007+0030", "20040125093007Z");

	return 0;
}

