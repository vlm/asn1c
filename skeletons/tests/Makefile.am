check_PROGRAMS = \
	check-ber_tlv_tag	\
	check-length		\
	check-OIDs		\
	check-GeneralizedTime	\
	check-OCTET_STRING	\
	check-UTF8String	\
	check-UTCTime		\
	check-INTEGER		\
	check-REAL		\
	check-XER		\
	check-PER		\
	check-PER-INTEGER

AM_CPPFLAGS = -I$(top_srcdir)/skeletons $(TESTSUITE_CFLAGS)
AM_LDFLAGS = $(top_builddir)/skeletons/libasn1cskeletons.la
LDADD = -lm

TESTS = $(check_PROGRAMS)
