#ifndef TEST_TEMPLATE_FUNCTION
#define TEST_TEMPLATE_FUNCTION

#include "template_function.cpp"
#include <gtest/gtest.h>

TEST(TestTemplateFunction, testInt) {
	ASSERT_EQ(get_max(10, 11), 11);
	ASSERT_EQ(get_max<int>(11, 12), 12);
}

#endif
