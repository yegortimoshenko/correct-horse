bin_PROGRAMS = correct-horse

if GTK_FOUND
  bin_PROGRAMS += correct-horse-gtk

  desktop_DATA = correct-horse.desktop
  desktopdir = $(datadir)/applications

  pixmaps_DATA = correct-horse.png
  pixmapsdir = $(datadir)/icons/hicolor/256x256/apps
endif

lib_LTLIBRARIES = libcorrecthorse.la
libcorrecthorse_la_SOURCES = src/random.c

correct_horse_SOURCES = src/main.c
correct_horse_LDADD = $(lib_LTLIBRARIES)

correct_horse_gtk_SOURCES = src/main-gtk.c
correct_horse_gtk_CFLAGS = $(GTK_CFLAGS)
correct_horse_gtk_LDADD = $(GTK_LIBS) $(lib_LTLIBRARIES)

BUILT_SOURCES = src/dictionary.h

src/dictionary.h: src/dictionary.txt
	head -65536 $< | ./arraify correct_horse_dictionary > $@
