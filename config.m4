dnl const_test PHP Extension
dnl
dnl Copyright (C) 2013 Gasol Wu <gasol.wu@gmail.com>
dnl All rights reserved.
dnl
dnl Use and distribution licensed under the PHP license.  See
dnl the LICENSE file in this directory for full text.

PHP_ARG_ENABLE(const_test, whether to enable const_test support,
[  --enable-const_test           Enable const_test support])

if test "$PHP_CONST_TEST" != "no"; then
  PHP_NEW_EXTENSION(const_test, const_test.c, $ext_shared)
fi
