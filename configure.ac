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

# Checks for libraries.
AC_CHECK_LIB([notify], [main], [], 
    [AC_MSG_NOTICE([libnotify not found, desktop notifications no supported])])
AC_CHECK_LIB([headunit], [main], [], 
    [AC_MSG_NOTICE([headunit not found, will not be able to run tests])])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])
AC_CHECK_HEADERS([ncurses.h], [], [])
AC_CHECK_HEADERS([ncurses/ncurses.h], [], [])

PKG_CHECK_MODULES([libnotify], [libnotify], [], 
    [AC_MSG_NOTICE([libnotify module not found])])
PKG_CHECK_MODULES([libcouplet], [libcouplet >= 0.8], [],
    [AC_MSG_ERROR([libcouplet is required for profanity])])
PKG_CHECK_MODULES([libcurl], [libcurl], [],
    [AC_MSG_ERROR([libcurl is required for profanity])])
PKG_CHECK_MODULES([ncurses], [ncurses], [],
    [AC_MSG_ERROR([ncurses is required for profanity])])
PKG_CHECK_MODULES([glib], [glib-2.0], [],
    [AC_MSG_ERROR([glib-2.0 is required for profanity])])


AM_CFLAGS="-Wall $libnotify_CFLAGS $libcouplet_CFLAGS $libcurl_CFLAGS $ncurses_CFLAGS $glib_CFLAGS "
LIBS="$LIBS $libcouplet_LIBS $libnotify_LIBS $libcurl_LIBS $ncurses_LIBS $glib_LIBS"

AC_SUBST(AM_CFLAGS)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([atexit memset strdup strndup strstr])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
