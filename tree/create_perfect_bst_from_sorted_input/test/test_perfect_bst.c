#include "../inc/create_perfect_bst.h"
#include "/Unity/src/unity.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void test_perfect_bst_invalid_input_1(void)
{
	int status;
	int const *input = NULL;

	status = create_perfect_bst(input, 5);
	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_perfect_bst_invalid_input_2(void)
{
	int status;
	int const input[] = {1, 2, 3};

	status = create_perfect_bst(input, 0);
	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_perfect_bst_invalid_input_3(void)
{
	int status;
	int const input[] = {2, 1, 3};

	status = create_perfect_bst(input, 3);
	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_perfect_bst_valid_input_for_size_3(void)
{
	int status;
	int output[] = {0, 0, 0};
	int const input[] = {1, 2, 3};

	status = create_perfect_bst(input, ARRAY_SIZE(output));
	TEST_ASSERT_EQUAL_INT(0, status);

	status = inorder_traverse_bst(output);
	TEST_ASSERT_EQUAL_INT(0, status);

	TEST_ASSERT_EQUAL_INT_ARRAY(input, output, ARRAY_SIZE(output));

	TEST_ASSERT_EQUAL_INT(0, destroy_perfect_bst());
}

static void test_perfect_bst_valid_input_for_size_5(void)
{
	int status;
	int output[] = {0, 0, 0, 0, 0};
	int const input[] = {1, 2, 3, 4, 5};

	status = create_perfect_bst(input, ARRAY_SIZE(output));
	TEST_ASSERT_EQUAL_INT(0, status);

	status = inorder_traverse_bst(output);
	TEST_ASSERT_EQUAL_INT(0, status);

	TEST_ASSERT_EQUAL_INT_ARRAY(input, output, ARRAY_SIZE(output));

	TEST_ASSERT_EQUAL_INT(0, destroy_perfect_bst());
}

static void test_perfect_bst_valid_input_for_size_7(void)
{
	int status;
	int output[] = {0, 0, 0, 0, 0, 0, 0};
	int const input[] = {1, 2, 3, 4, 5, 6, 7};

	status = create_perfect_bst(input, ARRAY_SIZE(output));
	TEST_ASSERT_EQUAL_INT(0, status);

	status = inorder_traverse_bst(output);
	TEST_ASSERT_EQUAL_INT(0, status);

	TEST_ASSERT_EQUAL_INT_ARRAY(input, output, ARRAY_SIZE(output));

	TEST_ASSERT_EQUAL_INT(0, destroy_perfect_bst());
}

static void test_perfect_bst_valid_input_for_size_9(void)
{
	int status;
	int output[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int const input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	status = create_perfect_bst(input, ARRAY_SIZE(output));
	TEST_ASSERT_EQUAL_INT(0, status);

	status = inorder_traverse_bst(output);
	TEST_ASSERT_EQUAL_INT(0, status);

	TEST_ASSERT_EQUAL_INT_ARRAY(input, output, ARRAY_SIZE(output));

	TEST_ASSERT_EQUAL_INT(0, destroy_perfect_bst());
}

static void test_perfect_bst_valid_input_for_size_10(void)
{
	int status;
	int output[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int const input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	status = create_perfect_bst(input, ARRAY_SIZE(output));
	TEST_ASSERT_EQUAL_INT(0, status);

	status = inorder_traverse_bst(output);
	TEST_ASSERT_EQUAL_INT(0, status);

	TEST_ASSERT_EQUAL_INT_ARRAY(input, output, ARRAY_SIZE(output));

	TEST_ASSERT_EQUAL_INT(0, destroy_perfect_bst());
}

static void test_perfect_bst_valid_input_for_size_25(void)
{
	int status;
	int output[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int const input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

	status = create_perfect_bst(input, ARRAY_SIZE(output));
	TEST_ASSERT_EQUAL_INT(0, status);

	status = inorder_traverse_bst(output);
	TEST_ASSERT_EQUAL_INT(0, status);

	TEST_ASSERT_EQUAL_INT_ARRAY(input, output, ARRAY_SIZE(output));

	TEST_ASSERT_EQUAL_INT(0, destroy_perfect_bst());
}

static void test_perfect_bst_valid_input_for_size_8(void)
{
	int status;
	int output[] = {0, 0, 0, 0, 0, 0, 0, 0};
	int const input[] = {1, 2, 3, 4, 5, 6, 7, 8};

	status = create_perfect_bst(input, ARRAY_SIZE(output));
	TEST_ASSERT_EQUAL_INT(0, status);

	status = inorder_traverse_bst(output);
	TEST_ASSERT_EQUAL_INT(0, status);

	TEST_ASSERT_EQUAL_INT_ARRAY(input, output, ARRAY_SIZE(output));

	TEST_ASSERT_EQUAL_INT(0, destroy_perfect_bst());
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_perfect_bst_invalid_input_1);
	RUN_TEST(test_perfect_bst_invalid_input_2);
	RUN_TEST(test_perfect_bst_invalid_input_3);

	RUN_TEST(test_perfect_bst_valid_input_for_size_3);
	RUN_TEST(test_perfect_bst_valid_input_for_size_5);
	RUN_TEST(test_perfect_bst_valid_input_for_size_7);
	RUN_TEST(test_perfect_bst_valid_input_for_size_8);
	RUN_TEST(test_perfect_bst_valid_input_for_size_9);
	RUN_TEST(test_perfect_bst_valid_input_for_size_10);
	RUN_TEST(test_perfect_bst_valid_input_for_size_25);

	UNITY_END();

	return 0;
}
