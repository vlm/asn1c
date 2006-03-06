
SUBDIRS = standard-modules tests

dist_pkgdata_DATA =				\
		$(srcdir)/*.[ch]		\
		$(srcdir)/file-dependencies

uninstall-local:
	-@echo -n " "
	-rm -f -r $(DESTDIR)$(pkgdatadir)
