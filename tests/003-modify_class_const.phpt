--TEST--
Check for modify constant declared in class
--SKIPIF--
<?php if (!extension_loaded('const_test')) die('skip - const_test extension not loaded'); ?>
--FILE--
<?php
class Foo
{
    const FOO_CONST = 'Foo::FOO_CONST';
}

echo Foo::FOO_CONST . PHP_EOL;
modify_const(Foo::FOO_CONST);
echo Foo::FOO_CONST . PHP_EOL;
?>
--EXPECT--
Foo::FOO_CONST
Foo::FOO_CONST
