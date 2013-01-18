--TEST--
Check for const_test presence
--SKIPIF--
<?php
if (!extension_loaded('const_test')) {
    echo 'skip - const_test extension not loaded';
    return;
}
?>
--FILE--
<?php 
echo 'const_test extension is available';
?>
--EXPECT--
const_test extension is available
