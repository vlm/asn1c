
dist_bin_SCRIPTS = crfc2asn1.pl clyx2asn1.pl

ASN1_SOURCE_1 = rfc3280.txt
ASN1_FILES_1 =				\
	rfc3280-PKIX1Explicit88.asn1	\
	rfc3280-PKIX1Implicit88.asn1

ASN1_SOURCE_2 = rfc3525.txt
ASN1_FILES_2 =				\
	rfc3525-MEDIA-GATEWAY-CONTROL.asn1

ASN1_SOURCE_3 = rfc4511.txt
ASN1_FILES_3 =				\
	rfc4511-Lightweight-Directory-Access-Protocol-V3.asn1

all: $(ASN1_FILES_1) $(ASN1_FILES_2) $(ASN1_FILES_3)

$(ASN1_FILES_1): crfc2asn1.pl $(ASN1_SOURCE_1)
	./crfc2asn1.pl $(ASN1_SOURCE_1)

$(ASN1_FILES_2): crfc2asn1.pl $(ASN1_SOURCE_2)
	./crfc2asn1.pl $(ASN1_SOURCE_2)

$(ASN1_FILES_3): crfc2asn1.pl $(ASN1_SOURCE_3)
	./crfc2asn1.pl $(ASN1_SOURCE_3)

EXTRA_DIST = $(srcdir)/rfc*.txt					\
	$(srcdir)/sample.regen.makefile				\
	$(srcdir)/sample.source.*/README			\
	$(srcdir)/sample.source.*/config.h			\
	$(srcdir)/sample.source.*/Makefile			\
	$(srcdir)/sample.source.*/sample-*

CLEANFILES = $(ASN1_FILES_1) $(ASN1_FILES_2) $(ASN1_FILES_3)

clean-local:
	for dir in sample.source.*; do (cd $$dir && make distclean); done
