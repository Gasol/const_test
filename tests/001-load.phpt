--TEST--
Check for const_test presence
--SKIPIF--
<?php
if (!extension_loaded('const_test')) die('skip - const_test extension not loaded');
?>
--FILE--
<?php
echo 'const_test extension is available';
?>
--EXPECT--
const_test extension is available
