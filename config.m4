PHP_ARG_ENABLE(const_test, whether to enable const_test support,
[  --enable-const_test           Enable const_test support])

if test "$PHP_CONST_TEST" != "no"; then
  PHP_NEW_EXTENSION(const_test, const_test.c, $ext_shared)
fi
