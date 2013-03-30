## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = bildbetrachter_gtk.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(BILDBETRACHTER_GTK_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = bildbetrachter_gtk

bildbetrachter_gtk_SOURCES = \
	main.c \
	bildbetrachter-gtk.h \
	bildbetrachter-gtk.c	

bildbetrachter_gtk_LDFLAGS = \
	-Wl,--export-dynamic

bildbetrachter_gtk_LDADD = $(BILDBETRACHTER_GTK_LIBS)


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

