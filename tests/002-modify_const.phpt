--TEST--
Check for modify constant
--SKIPIF--
<?php
if (!extension_loaded('const_test')) die('skip - const_test extension not loaded');
?>
--FILE--
<?php
echo CONST_TEST_FOO . PHP_EOL;
echo CONST_TEST_BAR . PHP_EOL;
echo CONST_TEST_ZOO . PHP_EOL;

modify_const(CONST_TEST_FOO);
modify_const(CONST_TEST_BAR);
modify_const(CONST_TEST_ZOO);

echo CONST_TEST_FOO . PHP_EOL;
echo CONST_TEST_BAR . PHP_EOL;
echo CONST_TEST_ZOO . PHP_EOL;
?>
--EXPECT--
Foo
Bar
Zoo
Foo
Bar
Zoo
