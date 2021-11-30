/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/is_bst.h"
#include "/Unity/src/unity.h"
#include <stdio.h>
#include <stdlib.h>

static void is_bst_invalid_input_0(void)
{
	TEST_ASSERT_FALSE(is_bst(NULL));
}

static void is_bst_valid_input_0(void)
{
	struct bst *root = NULL;

	TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, 5));
	TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, 3));
	TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, 8));
	TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, 4));
	TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, 1));
	TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, 10));
	TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, 7));

	printf("inorder traverse of valid bst:");
	inorder_traverse(root);
	printf("\n");

	TEST_ASSERT_TRUE(is_bst(root));

	TEST_ASSERT_EQUAL_INT(0, destroy_valid_bst(root));
}

static void is_bst_valid_size_1_million(void)
{
	int r;
	size_t i;
	struct bst *root = NULL;

	for (i = 0 ; i < 1000000; i++) {
		r = rand() % 1000000;
		TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, r));
	}

	printf("inorder traverse of valid bst:");
	inorder_traverse(root);
	printf("\n");

	TEST_ASSERT_TRUE(is_bst(root));

	TEST_ASSERT_EQUAL_INT(0, destroy_valid_bst(root));
}

static void is_bst_valid_size_100_million(void)
{
	int r;
	size_t i;
	struct bst *root = NULL;

	for (i = 0 ; i < 100000000; i++) {
		r = rand() % 100000000;
		TEST_ASSERT_NOT_NULL(root = build_correct_bst(root, r));
	}

	printf("inorder traverse of valid bst:");
	inorder_traverse(root);
	printf("\n");

	TEST_ASSERT_TRUE(is_bst(root));

	TEST_ASSERT_EQUAL_INT(0, destroy_valid_bst(root));
}

static void is_incorrect_bst_input_0(void)
{
	struct bst *root = NULL;

	TEST_ASSERT_NOT_NULL(root = build_incorrect_bst(root, 5));
	TEST_ASSERT_NOT_NULL(root = build_incorrect_bst(root, 3));
	TEST_ASSERT_NOT_NULL(root = build_incorrect_bst(root, 8));
	TEST_ASSERT_NOT_NULL(root = build_incorrect_bst(root, 4));
	TEST_ASSERT_NOT_NULL(root = build_incorrect_bst(root, 1));
	TEST_ASSERT_NOT_NULL(root = build_incorrect_bst(root, 10));
	TEST_ASSERT_NOT_NULL(root = build_incorrect_bst(root, 7));

	printf("inorder traverse of valid bst:");
	inorder_traverse(root);
	printf("\n");

	TEST_ASSERT_FALSE(is_bst(root));

	TEST_ASSERT_EQUAL_INT(0, destroy_valid_bst(root));
}

static void test_is_bst(void)
{
	RUN_TEST(is_bst_invalid_input_0);

	RUN_TEST(is_bst_valid_input_0);
	RUN_TEST(is_bst_valid_size_1_million);
	RUN_TEST(is_bst_valid_size_100_million);

	RUN_TEST(is_incorrect_bst_input_0);
}

int main()
{
	UNITY_BEGIN();

	while (1)
		test_is_bst();

	UNITY_END();

	return 0;
}
