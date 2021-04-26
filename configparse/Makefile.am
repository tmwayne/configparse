BUILT_SOURCES = parser.h
AM_YFLAGS = -d

lib_LTLIBRARIES = libconfigparse.la
libconfigparse_la_SOURCES = parser.y lexer.l configparse.c
libconfigparse_la_CPPFLAGS = -I$(includedir)
libconfigparse_la_LIBADD = $(libdir)/libdict.la

include_HEADERS = configparse.h
