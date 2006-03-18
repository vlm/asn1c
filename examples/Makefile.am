
dist_bin_SCRIPTS = crfc2asn1.pl clyx2asn1.pl

ASN1_SOURCE_1 = rfc3280.txt
ASN1_FILES_1 =				\
	rfc3280-PKIX1Explicit88.asn1	\
	rfc3280-PKIX1Implicit88.asn1

all: $(ASN1_FILES_1)

$(ASN1_FILES_1): crfc2asn1.pl $(ASN1_SOURCE_1)
	./crfc2asn1.pl $(ASN1_SOURCE_1)

EXTRA_DIST = $(srcdir)/rfc*.txt					\
	$(srcdir)/sample.source.PKIX1/README			\
	$(srcdir)/sample.source.PKIX1/config.h			\
	$(srcdir)/sample.source.PKIX1/Makefile			\
	$(srcdir)/sample.source.PKIX1/regenerate.Makefile	\
	$(srcdir)/sample.source.TAP3/README			\
	$(srcdir)/sample.source.TAP3/config.h			\
	$(srcdir)/sample.source.TAP3/Makefile			\
	$(srcdir)/sample.source.TAP3/regenerate.Makefile

CLEANFILES = $(ASN1_FILES_1)

clean-local:
	cd sample.source.PKIX1 && make distclean
	cd sample.source.TAP3 && make distclean
	cd sample.source.MHEG5 && make distclean
