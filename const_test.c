/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_const_test.h"

/* If you declare any globals in php_const_test.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(const_test)
*/

/* True global resources - no need for thread safety here */
static int le_const_test;

const zend_function_entry const_test_functions[] = {
	PHP_FE(modify_const,	NULL)
	PHP_FE_END	/* Must be the last line in const_test_functions[] */
};

/* {{{ const_test_module_entry
 */
zend_module_entry const_test_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"const_test",
	const_test_functions,
	PHP_MINIT(const_test),
	PHP_MSHUTDOWN(const_test),
	PHP_RINIT(const_test),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(const_test),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(const_test),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CONST_TEST
ZEND_GET_MODULE(const_test)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(const_test)
{
	srand(time(NULL));
	REGISTER_STRING_CONSTANT("CONST_TEST_FOO", "Foo", CONST_CS|CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("CONST_TEST_BAR", "Bar", CONST_CS|CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("CONST_TEST_ZOO", "Zoo", CONST_CS|CONST_PERSISTENT);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(const_test)
{
	return SUCCESS;
}
/* }}} */

PHP_RINIT_FUNCTION(const_test)
{
	return SUCCESS;
}
/* }}} */

PHP_RSHUTDOWN_FUNCTION(const_test)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(const_test)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "const_test support", "enabled");
	php_info_print_table_end();
}
/* }}} */

void gen_random(char *s, const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		//int rnd = rand();
		//int index = rnd % (sizeof(alphanum) - 1);
		int index = s[i] % (sizeof(alphanum) - 1);
		s[i] = alphanum[index];
	}

	s[len] = 0;
}

PHP_FUNCTION(modify_const)
{
	char *str = NULL;
	int str_len = 0;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
		RETURN_FALSE;
	}

	gen_random(str, str_len);
	RETURN_STRINGL(str, strlen(str), 0);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
