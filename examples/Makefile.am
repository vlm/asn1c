
dist_bin_SCRIPTS = crfc2asn1.pl clyx2asn1.pl

ASN1_SOURCE_1 = rfc3280.txt
ASN1_FILES_1 =				\
	rfc3280-PKIX1Explicit88.asn1	\
	rfc3280-PKIX1Implicit88.asn1

all: $(ASN1_FILES_1)

$(ASN1_FILES_1): crfc2asn1.pl $(ASN1_SOURCE_1)
	./crfc2asn1.pl $(ASN1_SOURCE_1)

EXTRA_DIST = rfc*.txt				\
	sample.source.PKIX1/README		\
	sample.source.PKIX1/config.h		\
	sample.source.PKIX1/Makefile		\
	sample.source.PKIX1/regenerate.Makefile	\
	sample.source.TAP3/README		\
	sample.source.TAP3/config.h		\
	sample.source.TAP3/Makefile		\
	sample.source.TAP3/regenerate.Makefile

CLEANFILES = $(ASN1_FILES_1)

clean-local:
	cd sample.source.PKIX1 && make distclean
	cd sample.source.TAP3 && make distclean
