AM_CPPFLAGS = -I$(top_srcdir)/skeletons

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
	check-PER

AM_LDFLAGS = $(top_srcdir)/skeletons/libasn1cskeletons.la
LDADD = -lm

TESTS = $(check_PROGRAMS)
