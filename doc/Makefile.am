
docsdir = $(datadir)/doc/asn1c

docs_DATA =	$(srcdir)/*.pdf	\
		$(srcdir)/*.html

EXTRA_DIST =	$(srcdir)/*.pdf	\
		$(srcdir)/*.html

regen:
	pdflatex --output-format=dvi asn1c-usage
	pdflatex --output-format=dvi asn1c-usage
	pdflatex --output-format=dvi asn1c-usage
	dvipdf asn1c-usage

CLEANFILES = *.*~ *.aux *.dvi *.log *.out *.toc
