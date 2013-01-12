dnl $Id$
dnl config.m4 for extension const_test

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(const_test, for const_test support,
dnl Make sure that the comment is aligned:
dnl [  --with-const_test             Include const_test support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(const_test, whether to enable const_test support,
dnl Make sure that the comment is aligned:
dnl [  --enable-const_test           Enable const_test support])

if test "$PHP_CONST_TEST" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-const_test -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/const_test.h"  # you most likely want to change this
  dnl if test -r $PHP_CONST_TEST/$SEARCH_FOR; then # path given as parameter
  dnl   CONST_TEST_DIR=$PHP_CONST_TEST
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for const_test files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       CONST_TEST_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$CONST_TEST_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the const_test distribution])
  dnl fi

  dnl # --with-const_test -> add include path
  dnl PHP_ADD_INCLUDE($CONST_TEST_DIR/include)

  dnl # --with-const_test -> check for lib and symbol presence
  dnl LIBNAME=const_test # you may want to change this
  dnl LIBSYMBOL=const_test # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $CONST_TEST_DIR/lib, CONST_TEST_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_CONST_TESTLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong const_test lib version or lib not found])
  dnl ],[
  dnl   -L$CONST_TEST_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(CONST_TEST_SHARED_LIBADD)

  PHP_NEW_EXTENSION(const_test, const_test.c, $ext_shared)
fi
