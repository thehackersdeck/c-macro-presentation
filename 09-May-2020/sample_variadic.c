//!gcc '{0}' -I. -o test; ./test

#include <exotic/cester.h>

CESTER_BEFORE_ALL(test_instance,
    test_instance->arg = "Hello World";
)

CESTER_TEST(check_shared_arg, test_instance,
    cester_assert_string_equal(test_instance->arg, "Hello World");
    cester_assert_not_equal(2, 1);
)