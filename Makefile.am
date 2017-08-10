
ACLOCAL_AMFLAGS = -I m4

@CODE_COVERAGE_RULES@
CODE_COVERAGE_IGNORE_PATTERN="tests/*" "lex.yy.c" "y.tab.c" "asn1p_l.l" "asn1p_y.y"

SUBDIRS = 				\
	libasn1parser libasn1fix	\
	libasn1print libasn1compiler	\
	skeletons examples \
	doc asn1c tests

docsdir = $(datadir)/doc/asn1c

docs_DATA = README.md INSTALL.md REQUIREMENTS.md FAQ ChangeLog BUGS

EXTRA_DIST = README.md INSTALL.md REQUIREMENTS.md FAQ LICENSE BUGS
