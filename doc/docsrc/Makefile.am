
XELATEX_FLAGS = -halt-on-error -file-line-error
XELATEX = xelatex

regen:
	$(XELATEX) $(XELATEX_FLAGS) -no-pdf asn1c-usage
	$(XELATEX) $(XELATEX_FLAGS) -no-pdf asn1c-usage
	$(XELATEX) $(XELATEX_FLAGS) asn1c-usage

EXTRA_DIST = $(srcdir)/*.tex

CLEANFILES = *.*~ *.aux *.dvi *.log *.out *.toc
