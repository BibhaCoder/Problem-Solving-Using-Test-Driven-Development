#include "../inc/bit_flip.h"
#include "/Unity/src/unity.h"

static void bit_flip_input_0(void)
{
	uint32_t num = ~(uint32_t)0;
	int const expected_val = 32;
	int ret;

	ret = bit_flip(num);
	TEST_ASSERT_EQUAL_INT(expected_val, ret);
}

static void bit_flip_input_1(void)
{
	uint32_t num = 0;
	int const expected_val = 1;
	int ret;

	ret = bit_flip(num);
	TEST_ASSERT_EQUAL_INT(expected_val, ret);
}

static void bit_flip_input_2(void)
{
	uint32_t num = 16;
	int const expected_val = 2;
	int ret;

	ret = bit_flip(num);
	TEST_ASSERT_EQUAL_INT(expected_val, ret);
}

static void bit_flip_input_3(void)
{
	uint32_t num = 1024;
	int const expected_val = 2;
	int ret;

	ret = bit_flip(num);
	TEST_ASSERT_EQUAL_INT(expected_val, ret);
}

static void bit_flip_input_4(void)
{
	uint32_t num = 7;
	int const expected_val = 4;
	int ret;

	ret = bit_flip(num);
	TEST_ASSERT_EQUAL_INT(expected_val, ret);
}

static void bit_flip_input_5(void)
{
	uint32_t num = 1775;
	int const expected_val = 8;
	int ret;

	ret = bit_flip(num);
	TEST_ASSERT_EQUAL_INT(expected_val, ret);
}

static void bit_flip_input_6(void)
{
	uint32_t num = 1775; /*in binary 11011101111 */
	int const expected_val = 8;
	int ret;

	ret = bit_flip(num);
	TEST_ASSERT_EQUAL_INT(expected_val, ret);
}

static void bit_flip_input_7(void)
{
	uint32_t num = 10;
	int const expected_val = 3;
	int ret;

	ret = bit_flip(num);
	TEST_ASSERT_EQUAL_INT(expected_val, ret);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(bit_flip_input_0);
	RUN_TEST(bit_flip_input_1);
	RUN_TEST(bit_flip_input_2);
	RUN_TEST(bit_flip_input_3);
	RUN_TEST(bit_flip_input_4);
	RUN_TEST(bit_flip_input_5);
	RUN_TEST(bit_flip_input_6);
	RUN_TEST(bit_flip_input_7);

	UNITY_END();

	return 0;
}
