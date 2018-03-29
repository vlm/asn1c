
XELATEX_FLAGS = -halt-on-error -file-line-error
XELATEX = xelatex
TEXSRC = '\def\asnver{@VERSION@}\input{asn1c-usage}'

regen:
	$(XELATEX) $(XELATEX_FLAGS) -no-pdf $(TEXSRC)
	$(XELATEX) $(XELATEX_FLAGS) -no-pdf $(TEXSRC)
	$(XELATEX) $(XELATEX_FLAGS) $(TEXSRC)

EXTRA_DIST = $(srcdir)/*.tex $(srcdir)/*.inc

CLEANFILES = *.*~ *.aux *.dvi *.log *.out *.toc
