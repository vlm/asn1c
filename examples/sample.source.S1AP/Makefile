ASN_PROGRAM = s1ap-dump
CFLAGS += -DHAVE_CONFIG_H -DJUNKTEST -D_DEFAULT_SOURCE
begin: S1AP-PDU.c maybe-wip-pause all

-include converter-example.mk

S1AP-PDU.c: ../sample.makefile.regen ../s1ap-14.4.0.asn1
	make regen-makefile
	@touch S1AP-PDU.c
	make

regen-makefile:
	ASN_CMDOPTS="-pdu=all -fcompound-names -findirect-choice -fno-include-deps -flink-skeletons -gen-PER" \
	ASN_MODULES="../s1ap-14.4.0.asn1" \
	ASN_PDU=S1AP-PDU \
	ASN_PROGRAM=s1ap-dump \
	../sample.makefile.regen

check: ${ASN_PROGRAM} check-ber check-xer check-oer check-per check-aper
	@echo ================
	@echo All tests passed
	@echo ================

check-ber:
	@if test -f sample-S1AP-PDU-1.[db]er ; then \
	for f in sample-*-*.[db]er; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into XER and back ($$b)..."; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -iber -oxer $$f > ./.tmp.1.$$$$ || exit 2; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -ixer -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff ./.tmp.1.$$$$ ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${ASN_PROGRAM} -J0.0001 -n 1000 -p $$pdu -b $$b -iber -onull $$f || exit 5; \
	./${ASN_PROGRAM} -J0.001 -n 1000 -p $$pdu -b $$b -iber -onull $$f || exit 6; \
	done; done; fi

check-xer:
	@if test -f sample-S1AP-PDU-1.xer ; then \
	for f in sample-*-*.xer; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into DER and back ($$b)..."; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -ixer -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff $$f ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${ASN_PROGRAM} -J0.0001 -n 1000 -p $$pdu -b $$b -ixer -onull $$f || exit 5; \
	./${ASN_PROGRAM} -J0.001 -n 1000 -p $$pdu -b $$b -ixer -onull $$f || exit 6; \
	done; done; fi

check-oer:
	@if test -f sample-S1AP-PDU-1.*oer ; then \
	for f in sample-*-*.*oer; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into XER and back ($$b)..."; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -ioer -oxer $$f > ./.tmp.1.$$$$ || exit 2; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -ixer -ooer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff $$f ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait) ($$b) ..."; \
	./${ASN_PROGRAM} -J0.0001 -n 1000 -p $$pdu -b $$b -ioer -onull $$f || exit 5; \
	./${ASN_PROGRAM} -J0.001 -n 1000 -p $$pdu -b $$b -ioer -onull $$f || exit 6; \
	done; done; fi

check-per:
	@if test -f sample-S1AP-PDU-1-nopad.per ; then \
	for f in sample-*-[1-9]-nopad.per; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding non-padded $$f ($$pdu) into DER into XER and back ($$b)..."; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -per-nopad -iper -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -ixer -oder ./.tmp.2.$$$$ > ./.tmp.3.$$$$ || exit 4; \
	diff ./.tmp.1.$$$$ ./.tmp.3.$$$$ || exit 5; \
	rm -f ./.tmp.[123].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${ASN_PROGRAM} -J0.0001 -n 1000 -p $$pdu -b $$b -per-nopad -iper -onull $$f || exit 6; \
	./${ASN_PROGRAM} -J0.001 -n 1000 -p $$pdu -b $$b -per-nopad -iper -onull $$f || exit 7; \
	done; done; fi
	@if test -f sample-S1AP-PDU-1.per ; then \
	for f in sample-*-[1-9].per; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into DER into XER and back ($$b)..."; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -iper -oder $$f > ./.tmp.1.$$$$ || exit 3; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 4; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -ixer -oper ./.tmp.2.$$$$ > ./.tmp.1.$$$$ || exit 5; \
	diff $$f ./.tmp.1.$$$$ || exit 6; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${ASN_PROGRAM} -J0.0001 -n 1000 -p $$pdu -b $$b -iper -onull $$f || exit 7; \
	./${ASN_PROGRAM} -J0.001 -n 1000 -p $$pdu -b $$b -iper -onull $$f || exit 8; \
	done; done; fi

check-aper:
	@files=$$(find . -type f -regex '^.*\/sample-.*-[0-9]+.aper$$' | sort -V); \
	if [ -n "$$files" ]; then \
	for f in $$files; do \
	pdu=`echo $$f | sed -E -e "s/.*sample-([A-Za-z0-9-]+)-[0-9]+.*/\\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into XER and back ($$b)..."; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -iaper -oxer $$f > ./.tmp.1.$$$$ || exit 3; \
	./${ASN_PROGRAM} -p $$pdu -b $$b -ixer -oaper ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 4; \
	diff $$f ./.tmp.2.$$$$ || exit 6; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${ASN_PROGRAM} -J0.0001 -n 1000 -p $$pdu -b $$b -iaper -onull $$f || exit 7; \
	./${ASN_PROGRAM} -J0.001 -n 1000 -p $$pdu -b $$b -iaper -onull $$f || exit 8; \
	done; done; fi

maybe-wip-pause:
	@if [ -f WIP ]; then cat WIP; sleep 2; fi

distclean: clean
	rm -f $(ASN_MODULE_SRCS)
	rm -f $(ASN_MODULE_HDRS)
	rm -f $(ASN_PROGRAM_SRCS) $(ASN_PROGRAM_HDRS)
	rm -f converter-example.mk
