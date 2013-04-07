
dist_bin_SCRIPTS = crfc2asn1.pl

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
	$(srcdir)/sample.source.LDAP3				\
	$(srcdir)/sample.source.MEGACO				\
	$(srcdir)/sample.source.MHEG5				\
	$(srcdir)/sample.source.RRC				\
	$(srcdir)/sample.source.TAP3				\
	$(srcdir)/sample.source.PKIX1				\
	$(srcdir)/sample.makefile.regen

dist-hook:
	rm -f `find $(distdir) -name "*.core" -or -name ".tmp.*"`
	rm -f `find $(distdir) -name "*.[ch].??????"`

CLEANFILES = $(ASN1_FILES_1) $(ASN1_FILES_2) $(ASN1_FILES_3)

clean-local:
	for dir in sample.source.*; do (cd $$dir && make distclean); done
