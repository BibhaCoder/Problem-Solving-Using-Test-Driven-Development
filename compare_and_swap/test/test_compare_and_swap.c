#include "../inc/compare_and_swap.h"
#include "/Unity/src/unity.h"

static void test_invalid_input_compare_and_swap(void)
{
	TEST_ASSERT_EQUAL_INT(-1, compare_and_swap(NULL, 5, 8));
}


static int32_t add(int32_t val_1, int32_t val_2)
{
	int32_t total, old_sum, new_sum;

	total = val_1 + val_2;
	old_sum = total;
	new_sum = total;

	while (compare_and_swap(&total, old_sum, new_sum))
		old_sum = total;

	return total;
}

static void test_valid_input_1_compare_and_swap(void)
{
	TEST_ASSERT_EQUAL_INT(5, add(3, 2));
}

static void test_valid_input_2_compare_and_swap(void)
{
	TEST_ASSERT_EQUAL_INT(17, add(8, 9));
}

static void test_valid_input_3_compare_and_swap(void)
{
	TEST_ASSERT_EQUAL_INT(100, add(50, 50));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_input_compare_and_swap);
	RUN_TEST(test_valid_input_1_compare_and_swap);
	RUN_TEST(test_valid_input_2_compare_and_swap);
	RUN_TEST(test_valid_input_3_compare_and_swap);

	UNITY_END();

	return 0;
}

