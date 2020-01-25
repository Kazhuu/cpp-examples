#include "function.hpp"
#include <gtest/gtest.h>

/*
 * Add tests here to test application code by including it normally. These tests
 * are executed by Google Test provided main() function.
 *
 * How tests are linked with test executable check this folder CMakeLists.txt
 * file for more details.
 */
TEST(TestFunction, TestReturnValue)
{
    ASSERT_TRUE(test_function(true));
    ASSERT_FALSE(test_function(false));
}
