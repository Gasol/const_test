--TEST--
Check for modify constant
--SKIPIF--
<?php
if (!extension_loaded('const_test')) {
    die('skip - const_test extension not loaded');
}
?>
--FILE--
<?php
class Foo
{
    const FOO_CONST = 'Foo::FOO_CONST';
}

echo CONST_TEST_FOO . PHP_EOL;
echo CONST_TEST_BAR . PHP_EOL;
echo CONST_TEST_ZOO . PHP_EOL;
echo PATH_SEPARATOR . PHP_EOL;
echo Foo::FOO_CONST . PHP_EOL;

modify_const(CONST_TEST_FOO);
modify_const(CONST_TEST_BAR);
modify_const(CONST_TEST_ZOO);
modify_const(PATH_SEPARATOR);
modify_const(Foo::FOO_CONST);

echo CONST_TEST_FOO . PHP_EOL;
echo CONST_TEST_BAR . PHP_EOL;
echo CONST_TEST_ZOO . PHP_EOL;
echo PATH_SEPARATOR . PHP_EOL;
echo Foo::FOO_CONST . PHP_EOL;
?>
--EXPECT--
Foo
Bar
Zoo
:
Foo::FOO_CONST
Foo
Bar
Zoo
:
Foo::FOO_CONST
