
dist_bin_SCRIPTS = crfc2asn1.pl clyx2asn1.pl

ASN1_SOURCE_0 = rfc2459.txt
ASN1_FILES_0 =				\
	rfc2459-PKIX1Explicit88.asn1	\
	rfc2459-PKIX1Implicit88.asn1	\
	rfc2459-PKIX1Explicit93.asn1	\
	rfc2459-PKIX1Implicit93.asn1

ASN1_SOURCE_1 = rfc3280.txt
ASN1_FILES_1 =				\
	rfc3280-PKIX1Explicit88.asn1	\
	rfc3280-PKIX1Implicit88.asn1

all: $(ASN1_FILES_0) $(ASN1_FILES_1)

$(ASN1_FILES_0): crfc2asn1.pl $(ASN1_SOURCE_0)
	./crfc2asn1.pl $(ASN1_SOURCE_0)

$(ASN1_FILES_1): crfc2asn1.pl $(ASN1_SOURCE_1)
	./crfc2asn1.pl $(ASN1_SOURCE_1)

EXTRA_DIST = rfc*.txt
CLEANFILES = *.asn1
