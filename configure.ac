#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([profanity], [0.1.9dev], [boothj5web@gmail.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for programs.
AC_PROG_CC

AC_ARG_WITH([strophe],
    [AS_HELP_STRING([--with-strophe], [use libstrophe instead of libcouplet])])

# Checks for libraries.
AC_CHECK_LIB([headunit], [main], [], 
    [AC_MSG_NOTICE([headunit not found, will not be able to run tests])])
AC_CHECK_LIB([notify], [main], [], 
    [AC_MSG_NOTICE([libnotify module not found])])

PKG_CHECK_MODULES([libnotify], [libnotify], [], 
    [AC_MSG_NOTICE([libnotify module not found])])
PKG_CHECK_MODULES([openssl], [openssl], [],
    [AC_MSG_ERROR([openssl is required for profanity])])
PKG_CHECK_MODULES([libcurl], [libcurl], [],
    [AC_MSG_ERROR([libcurl is required for profanity])])
PKG_CHECK_MODULES([ncurses], [ncurses], [],
    [AC_MSG_ERROR([ncurses is required for profanity])])
PKG_CHECK_MODULES([glib], [glib-2.0], [],
    [AC_MSG_ERROR([glib-2.0 is required for profanity])])

if test "x$with_strophe" = xyes; then
    AC_CHECK_LIB([expat], [main], [],
        [AC_MSG_ERROR([expat is required for profanity])])
    AC_CHECK_LIB([xml2], [main], [],
        [AC_MSG_ERROR([libxml2 is required for profanity])])
    AC_CHECK_LIB([strophe], [main], [],
        [AC_MSG_ERROR([libstrophe is required for profanity])])
else
    PKG_CHECK_MODULES([libcouplet], [libcouplet >= 0.8], [],
        [AC_MSG_ERROR([libcouplet is required for profanity])])
    AC_CHECK_LIB([couplet], [main], [],
        [AC_MSG_ERROR([libcouplet is required for profanity])])
    AM_CFLAGS="$AM_CFLAGS $libcouplet_CFLAGS"
    LIBS="$LIBS $libcouplet_LIBS"
fi

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])
AC_CHECK_HEADERS([ncurses.h], [], [])
AC_CHECK_HEADERS([ncurses/ncurses.h], [], [])

AM_CFLAGS="$AM_CFLAGS $libnotify_CFLAGS $libcurl_CFLAGS $ncurses_CFLAGS $glib_CFLAGS"
AM_CFLAGS="$AM_CFLAGS -Wall"
LIBS="$LIBS $libnotify_LIBS $openssl_LIBS $libcurl_LIBS $ncurses_LIBS $glib_LIBS"

AC_SUBST(AM_CFLAGS)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([atexit memset strdup strndup strstr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
