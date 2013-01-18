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

#ifndef PHP_CONST_TEST_H
#define PHP_CONST_TEST_H

extern zend_module_entry const_test_module_entry;
#define phpext_const_test_ptr &const_test_module_entry

#ifdef PHP_WIN32
#	define PHP_CONST_TEST_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_CONST_TEST_API __attribute__ ((visibility("default")))
#else
#	define PHP_CONST_TEST_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(const_test);
PHP_MSHUTDOWN_FUNCTION(const_test);
PHP_RINIT_FUNCTION(const_test);
PHP_RSHUTDOWN_FUNCTION(const_test);
PHP_MINFO_FUNCTION(const_test);

PHP_FUNCTION(modify_const);

#ifdef ZTS
#define CONST_TEST_G(v) TSRMG(const_test_globals_id, zend_const_test_globals *, v)
#else
#define CONST_TEST_G(v) (const_test_globals.v)
#endif

#endif	/* PHP_CONST_TEST_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
