#include "../inc/remove_duplicates.h"
#include "/Unity/src/unity.h"

static void test_remove_duplicate_invalid_input(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL_INT(-1, remove_duplicates(l));
	TEST_ASSERT_EQUAL(-1, add_item(&l, 101));
}

static void test_remove_duplicate_valid_input_size_1(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 0));
	TEST_ASSERT_NOT_NULL(l);
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_remove_duplicate_valid_input_size_2(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(-1, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, remove_duplicates(l));
	TEST_ASSERT_EQUAL(0, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_remove_duplicate_valid_input_size_3(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, remove_duplicates(l));
	TEST_ASSERT_EQUAL(0, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_remove_duplicate_valid_input_size_5(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(-1, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, remove_duplicates(l));
	TEST_ASSERT_EQUAL(0, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_remove_duplicate_valid_input_size_8(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 4));
	TEST_ASSERT_EQUAL(0, add_item(&l, 5));
	TEST_ASSERT_EQUAL(0, add_item(&l, 8));
	TEST_ASSERT_EQUAL(-1, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, remove_duplicates(l));
	TEST_ASSERT_EQUAL(0, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_remove_duplicate_valid_input_size_12(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 4));
	TEST_ASSERT_EQUAL(0, add_item(&l, 5));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(-1, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, remove_duplicates(l));
	TEST_ASSERT_EQUAL(0, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_remove_duplicate_valid_input_size_17(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 4));
	TEST_ASSERT_EQUAL(0, add_item(&l, 5));
	TEST_ASSERT_EQUAL(0, add_item(&l, 6));
	TEST_ASSERT_EQUAL(0, add_item(&l, 7));
	TEST_ASSERT_EQUAL(0, add_item(&l, 8));
	TEST_ASSERT_EQUAL(0, add_item(&l, 9));
	TEST_ASSERT_EQUAL(0, add_item(&l, 10));
	TEST_ASSERT_EQUAL(0, add_item(&l, 11));
	TEST_ASSERT_EQUAL(0, add_item(&l, 12));
	TEST_ASSERT_EQUAL(0, add_item(&l, 13));
	TEST_ASSERT_EQUAL(0, add_item(&l, 14));
	TEST_ASSERT_EQUAL(0, add_item(&l, 15));
	TEST_ASSERT_EQUAL(0, add_item(&l, 16));
	TEST_ASSERT_EQUAL(0, add_item(&l, 17));
	TEST_ASSERT_EQUAL(0, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, remove_duplicates(l));
	TEST_ASSERT_EQUAL(0, assert_no_duplicates(l));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_remove_duplicate_invalid_input);
	RUN_TEST(test_remove_duplicate_valid_input_size_1);
	RUN_TEST(test_remove_duplicate_valid_input_size_2);
	RUN_TEST(test_remove_duplicate_valid_input_size_3);
	RUN_TEST(test_remove_duplicate_valid_input_size_5);
	RUN_TEST(test_remove_duplicate_valid_input_size_8);
	RUN_TEST(test_remove_duplicate_valid_input_size_12);
	RUN_TEST(test_remove_duplicate_valid_input_size_17);

	UNITY_END();

	return 0;
}
