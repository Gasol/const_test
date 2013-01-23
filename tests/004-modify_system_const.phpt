--TEST--
Check for modify system constant
--SKIPIF--
<?php if (!extension_loaded('const_test')) die('skip - const_test extension not loaded'); ?>
--FILE--
<?php
echo PATH_SEPARATOR . PHP_EOL;
modify_const(PATH_SEPARATOR);
echo PATH_SEPARATOR . PHP_EOL;
?>
--EXPECT--
:
:
