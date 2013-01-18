--TEST--
Check for modify constant with APC disabled
--SKIPIF--
<?php
if (!extension_loaded('const_test')) {
    die('skip - const_test extension not loaded');
}
if (!extension_loaded('apc')) {
    die('skip - apc extension not loaded');
}
?>
--INI--
apc.enabled=0
apc.cli_enable=0
--FILE--
<?php
echo CONST_TEST_FOO . PHP_EOL;
echo CONST_TEST_BAR . PHP_EOL;
echo CONST_TEST_ZOO . PHP_EOL;
echo PATH_SEPARATOR . PHP_EOL;

modify_const(CONST_TEST_FOO);
modify_const(CONST_TEST_BAR);
modify_const(CONST_TEST_ZOO);
modify_const(PATH_SEPARATOR);

echo CONST_TEST_FOO . PHP_EOL;
echo CONST_TEST_BAR . PHP_EOL;
echo CONST_TEST_ZOO . PHP_EOL;
echo PATH_SEPARATOR . PHP_EOL;
?>
--EXPECT--
Foo
Bar
Zoo
:
Foo
Bar
Zoo
:
