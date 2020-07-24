#include "miunit.h"
#include <dlfcn.h>

char *test_dummy()
{

}

char *all_tests()
{
	mu_suite_start();

	mu_run_test(test_dummy);

	return NULL
}

RUN_TESTS(all_tests);
