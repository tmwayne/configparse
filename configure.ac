#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# If the project has a wildly different structure, use autoscan
# to generate an appropriate configure.ac

AC_PREREQ([2.69])
AC_INIT([ConfigParse], [1.0], [tylerwayne3@gmail.com])
AM_INIT_AUTOMAKE

# LT_PREREQ([2.2.])
# LT_INIT([dlopen])

AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
# AC_SEARCH_LIBS([dlopen])

AC_CONFIG_FILES([
  Makefile 
  src/Makefile])

AC_OUTPUT
