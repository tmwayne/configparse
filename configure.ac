#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# If the project has a wildly different structure, use autoscan
# to generate an appropriate configure.ac

AC_PREREQ([2.69])
AC_INIT([ConfigParse], [1.0], [tylerwayne3@gmail.com])
AM_INIT_AUTOMAKE

LT_PREREQ([2.2.])
LT_INIT([dlopen])

AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX([noyywrap])

# Checks for libraries.
AC_SEARCH_LIBS([dlopen], [dl])
AC_SEARCH_LIBS([dict_new], [dict])
AC_SEARCH_LIBS([assert], [error])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([strdup])

AC_CONFIG_FILES([
  Makefile 
  configparse/Makefile
  src/Makefile
  test/Makefile])

AC_OUTPUT
