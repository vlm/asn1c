-include Makefile.am.libasncodec

TARGET = j2735-dump
ASN_LIBRARY=libasncodec.a
LIBS += -lm
CFLAGS += -DASN_CONVERTER_TITLE="J2735 DSRC decoder" -DHAVE_CONFIG_H -DJUNKTEST -D_DEFAULT_SOURCE $(ASN_MODULE_CFLAGS) -DPDU=MessageFrame -DASN_PDU_COLLECTION -I.
ASN_CONVERTER_SOURCES := \
	converter-example.c\
	pdu_collection.c

all: maybe-wip-pause MessageFrame.c $(TARGET)

$(TARGET): $(ASN_LIBRARY) $(ASN_CONVERTER_SOURCES:.c=.o)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(TARGET) $(ASN_CONVERTER_SOURCES:.c=.o) $(LDFLAGS) $(ASN_LIBRARY) $(LIBS)

$(ASN_LIBRARY): $(ASN_MODULE_SOURCES:.c=.o)
	$(AR) rcs $@ $^

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(TARGET) $(ASN_LIBRARY)
	rm -f $(ASN_MODULE_SOURCES:.c=.o) $(ASN_CONVERTER_SOURCES:.c=.o)

regen: regenerate-from-asn1-source

regenerate-from-asn1-source:
	../../asn1c/asn1c -S ../../skeletons -pdu=MessageFrame -fcompound-names -gen-PER -pdu=all ../J2735_201603.asn1


MessageFrame.c: ../sample.makefile.regen ../J2735_201603.asn1
	make regen-makefile
	@touch MessageFrame.c
	make

regen-makefile:
	TITLE="J2735 DSRC decoder" \
	ASN1CMDOPTS="-fcompound-names -gen-PER -pdu=all" \
	ASN1MODULES="../J2735_201603.asn1" \
	ASN1PDU=MessageFrame \
	PROGNAME=j2735-dump \
	../sample.makefile.regen

check: ${TARGET} check-ber check-xer check-oer check-per
	@echo ================
	@echo All tests passed
	@echo ================

check-ber:
	@if test -f sample-MessageFrame-1.[db]er ; then \
	for f in sample-*-*.[db]er; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into XER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -iber -oxer $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -b $$b -ixer -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff ./.tmp.1.$$$$ ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -iber -onull $$f || exit 5; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -iber -onull $$f || exit 6; \
	done; done; fi

check-xer:
	@if test -f sample-MessageFrame-1.xer ; then \
	for f in sample-*-*.xer; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into DER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -ixer -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff $$f ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -ixer -onull $$f || exit 5; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -ixer -onull $$f || exit 6; \
	done; done; fi

check-oer:
	@if test -f sample-MessageFrame-1.*oer ; then \
	for f in sample-*-*.*oer; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into XER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -ioer -oxer $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -b $$b -ixer -ooer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	diff $$f ./.tmp.2.$$$$ || exit 4; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait) ($$b) ..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -ioer -onull $$f || exit 5; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -ioer -onull $$f || exit 6; \
	done; done; fi

check-per:
	@if test -f sample-MessageFrame-1-nopad.per ; then \
	for f in sample-*-[1-9]-nopad.per; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding non-padded $$f ($$pdu) into DER into XER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -per-nopad -iper -oder $$f > ./.tmp.1.$$$$ || exit 2; \
	./${TARGET} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 3; \
	./${TARGET} -p $$pdu -b $$b -ixer -oder ./.tmp.2.$$$$ > ./.tmp.3.$$$$ || exit 4; \
	diff ./.tmp.1.$$$$ ./.tmp.3.$$$$ || exit 5; \
	rm -f ./.tmp.[123].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -per-nopad -iper -onull $$f || exit 6; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -per-nopad -iper -onull $$f || exit 7; \
	done; done; fi
	@if test -f sample-MessageFrame-1.per ; then \
	for f in sample-*-[1-9].per; do \
	pdu=`echo $$f | sed -E -e "s/sample-([A-Za-z0-9-]+)-[0-9].*/\1/"`; \
	for b in 1 17 33 980 8192; do \
	echo "Recoding $$f ($$pdu) into DER into XER and back ($$b)..."; \
	./${TARGET} -p $$pdu -b $$b -iper -oder $$f > ./.tmp.1.$$$$ || exit 3; \
	./${TARGET} -p $$pdu -b $$b -iber -oxer ./.tmp.1.$$$$ > ./.tmp.2.$$$$ || exit 4; \
	./${TARGET} -p $$pdu -b $$b -ixer -oper ./.tmp.2.$$$$ > ./.tmp.1.$$$$ || exit 5; \
	diff $$f ./.tmp.1.$$$$ || exit 6; \
	rm -f ./.tmp.[12].$$$$; \
	echo "Test junking $$f (please wait)..."; \
	./${TARGET} -J0.0001 -n 1000 -p $$pdu -b $$b -iper -onull $$f || exit 7; \
	./${TARGET} -J0.001 -n 1000 -p $$pdu -b $$b -iper -onull $$f || exit 8; \
	done; done; fi

maybe-wip-pause:
	@if [ -f WIP ]; then cat WIP; sleep 2; fi

distclean: clean
	rm -f $(ASN_MODULE_SOURCES)
	rm -f $(ASN_MODULE_HEADERS)
	rm -f $(ASN_CONVERTER_SOURCES) $(ASN_CONVERTER_HEADERS)
	rm -f Makefile.am.example
