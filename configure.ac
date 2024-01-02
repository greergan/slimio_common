AC_COPYRIGHT([[Copyright 2023 Jeff Greer. All rights reserved. Restrictions apply, see COPYRIGHT and LICENSE files.]])
AC_INIT([slimio_commong], [0.1.0])
AC_LANG_PUSH([C++])
PKG_PROG_PKG_CONFIG
cwd=`pwd`
CPPFLAGS="-I$cwd/include $CPPFLAGS"
AC_SUBST(CPPFLAGS)
AC_SUBST(LDFLAGS)
AM_INIT_AUTOMAKE
AC_PROG_CXX
AC_CONFIG_HEADERS([include/config.h])
AC_CONFIG_FILES([
	Makefile
	src/Makefile
])
LT_INIT
AC_OUTPUT