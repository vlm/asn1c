
dist_man1_MANS = asn1c.1 unber.1 enber.1

if HAVE_PANDOC

PANDOC_OPTIONS= --from markdown --to man        \
		--variable header="Version ${VERSION}"  \
		--variable adjusting:l                  \
		--variable hyphenate:""                 \
		--standalone

%.1: %.man.md
	${PANDOC} ${PANDOC_OPTIONS} -o $@ $<

endif

