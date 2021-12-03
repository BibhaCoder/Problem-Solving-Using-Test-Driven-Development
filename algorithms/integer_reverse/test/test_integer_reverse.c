/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/integer_reverse.h"
#include "/Unity/src/unity.h"

static void integer_reverse_input_0(void)
{
	TEST_ASSERT_EQUAL_INT(0, integer_reverse(0));
}

static void integer_reverse_input_1(void)
{
	TEST_ASSERT_EQUAL_INT(3, integer_reverse(3));
	TEST_ASSERT_EQUAL_INT(-3, integer_reverse(-3));
	TEST_ASSERT_EQUAL_INT(9, integer_reverse(9));
	TEST_ASSERT_EQUAL_INT(-9, integer_reverse(-9));
}

static void integer_reverse_input_2(void)
{
	TEST_ASSERT_EQUAL_INT(32, integer_reverse(23));
	TEST_ASSERT_EQUAL_INT(-25, integer_reverse(-52));
	TEST_ASSERT_EQUAL_INT(19, integer_reverse(91));
	TEST_ASSERT_EQUAL_INT(5, integer_reverse(50));
	TEST_ASSERT_EQUAL_INT(-54321, integer_reverse(-12345));
}

static void integer_reverse_input_3(void)
{
	TEST_ASSERT_EQUAL_INT(321, integer_reverse(123));
	TEST_ASSERT_EQUAL_INT(-321, integer_reverse(-123));
	TEST_ASSERT_EQUAL_INT(21, integer_reverse(120));
	TEST_ASSERT_EQUAL_INT(-1, integer_reverse(2147483647));
	TEST_ASSERT_EQUAL_INT(-1, integer_reverse(-2147483648));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(integer_reverse_input_0);
	RUN_TEST(integer_reverse_input_1);

	RUN_TEST(integer_reverse_input_2);
	RUN_TEST(integer_reverse_input_3);

	UNITY_END();

	return 0;
}
