## Process this file with automake to produce Makefile.in

INCLUDES = \
	-I$(top_srcdir)/intl \
	$(GNOME_INCLUDEDIR)

bin_PROGRAMS = gnome-telnet

gnome_telnet_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h

gnome_telnet_LDADD = $(GNOME_LIBDIR) $(GNOMEUI_LIBS) $(ZVT_LIBS) $(INTLLIBS)

