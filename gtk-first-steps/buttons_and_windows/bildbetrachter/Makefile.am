## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

bildbetrachterdocdir = ${prefix}/doc/bildbetrachter
bildbetrachterdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(bildbetrachterdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(bildbetrachterdocdir)
