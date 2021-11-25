/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/zero_matrix.h"
#include </Unity/src/unity.h>

static void test_invalid_matrix_zero_input_1(void)
{
	uint8_t (*matrix)[3] = NULL;

	TEST_ASSERT_EQUAL_INT(-1, zero_matrix(3, 3, matrix));
}

static void test_invalid_matrix_zero_input_2(void)
{
	uint8_t matrix[11][11];

	TEST_ASSERT_EQUAL_INT(-1, zero_matrix(11, 11, matrix));
}

static void test_invalid_matrix_zero_input_3(void)
{
	uint8_t matrix[10][11];

	TEST_ASSERT_EQUAL_INT(-1, zero_matrix(11, 11, matrix));
}

static void test_invalid_matrix_zero_input_4(void)
{
	uint8_t matrix[11][10];

	TEST_ASSERT_EQUAL_INT(-1, zero_matrix(11, 11, matrix));
}

static void test_valid_matrix_zero_3x3(void)
{
	uint8_t matrix[3][3] =  {
					{1, 2, 3},
					{4, 0, 5},
					{6, 7, 8},
				};
	uint8_t matrix_expected[3][3] =  {
						{1, 0, 3},
						{0, 0, 0},
						{6, 0, 8},
						};

	TEST_ASSERT_EQUAL_INT(0, zero_matrix(3, 3, matrix));
	print_matrix(3, 3, matrix_expected);
	print_matrix(3, 3, matrix);
	TEST_ASSERT_EQUAL_MEMORY(matrix_expected, matrix, sizeof(matrix));
}

static void test_valid_matrix_zero_5x5(void)
{
	uint8_t matrix[5][5] =  {
					{1, 2, 3, 5, 7},
					{4, 0, 5, 6, 8,},
					{6, 7, 8, 8, 10},
					{6, 7, 8, 8, 10},
					{6, 7, 8, 8, 10},
				};
	uint8_t matrix_expected[5][5] =  {
						{1, 0, 3, 5, 7},
						{0, 0, 0, 0, 0,},
						{6, 0, 8, 8, 10},
						{6, 0, 8, 8, 10},
						{6, 0, 8, 8, 10},
					};

	TEST_ASSERT_EQUAL_INT(0, zero_matrix(5, 5, matrix));
	print_matrix(5, 5, matrix_expected);
	print_matrix(5, 5, matrix);
	TEST_ASSERT_EQUAL_MEMORY(matrix_expected, matrix, sizeof(matrix));
}

static void test_valid_matrix_zero_7x7(void)
{
	uint8_t matrix[7][7] =  {
				 {1, 2, 3, 5, 7, 3, 2},
				 {4, 5, 5, 0, 8, 5, 8},
				 {8, 7, 8, 8, 10, 17, 19},
				 {12, 8, 8, 8, 10, 19, 19},
				 {12, 8, 8, 8, 10, 12, 12},
				 {12, 8, 8, 8, 10, 12, 12},
				 {12, 8, 8, 8, 10, 17, 17},
				};
	uint8_t matrix_expected[7][7] =  {
					 {1, 2, 3, 0, 7, 3, 2},
					 {0, 0, 0, 0, 0, 0, 0},
					 {8, 7, 8, 0, 10, 17, 19},
					 {12, 8, 8, 0, 10, 19, 19},
					 {12, 8, 8, 0, 10, 12, 12},
					 {12, 8, 8, 0, 10, 12, 12},
					 {12, 8, 8, 0, 10, 17, 17},
					};

	TEST_ASSERT_EQUAL_INT(0, zero_matrix(7, 7, matrix));
	print_matrix(7, 7, matrix_expected);
	print_matrix(7, 7, matrix);
	TEST_ASSERT_EQUAL_MEMORY(matrix_expected, matrix, sizeof(matrix));
}

static void test_valid_matrix_zero_10x10(void)
{
	uint8_t matrix[10][10] =  {
				 {1, 2, 3, 5, 7, 3, 2, 1, 2, 3},
				 {4, 5, 5, 5, 8, 5, 8, 1, 2, 3},
				 {8, 7, 8, 8, 10, 17, 19, 1, 2, 3},
				 {12, 8, 8, 8, 10, 19, 19, 1, 2, 3},
				 {12, 8, 8, 8, 10, 12, 12, 1, 2, 3},
				 {12, 8, 8, 8, 10, 12, 12, 1, 2, 3},
				 {12, 8, 8, 8, 10, 17, 17, 1, 2, 3},
				 {12, 8, 8, 8, 10, 17, 17, 1, 2, 3},
				 {12, 8, 8, 8, 10, 17, 17, 1, 2, 3},
				 {12, 8, 8, 8, 10, 17, 17, 1, 2, 3},
				};
	uint8_t matrix_expected[10][10] =  {
				 {1, 2, 3, 5, 7, 3, 2, 1, 2, 3},
				 {4, 5, 5, 5, 8, 5, 8, 1, 2, 3},
				 {8, 7, 8, 8, 10, 17, 19, 1, 2, 3},
				 {12, 8, 8, 8, 10, 19, 19, 1, 2, 3},
				 {12, 8, 8, 8, 10, 12, 12, 1, 2, 3},
				 {12, 8, 8, 8, 10, 12, 12, 1, 2, 3},
				 {12, 8, 8, 8, 10, 17, 17, 1, 2, 3},
				 {12, 8, 8, 8, 10, 17, 17, 1, 2, 3},
				 {12, 8, 8, 8, 10, 17, 17, 1, 2, 3},
				 {12, 8, 8, 8, 10, 17, 17, 1, 2, 3},
					};

	TEST_ASSERT_EQUAL_INT(0, zero_matrix(10, 10, matrix));
	print_matrix(10, 10, matrix_expected);
	print_matrix(10, 10, matrix);
	TEST_ASSERT_EQUAL_MEMORY(matrix_expected, matrix, sizeof(matrix));
}

static void test_valid_matrix_zero_10x10_a(void)
{
	uint8_t matrix[10][10] =  {
				 {0, 2, 3, 5, 7, 3, 2, 1, 2, 3},
				 {4, 5, 5, 5, 8, 5, 8, 1, 2, 3},
				 {8, 7, 8, 8, 1, 7, 9, 1, 2, 3},
				 {2, 8, 8, 8, 1, 9, 9, 1, 2, 3},
				 {2, 8, 8, 8, 1, 2, 2, 1, 2, 3},
				 {2, 8, 8, 8, 1, 2, 2, 1, 2, 3},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				};
	uint8_t matrix_expected[10][10] =  {
				 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				 {0, 5, 5, 5, 8, 5, 8, 1, 2, 3},
				 {0, 7, 8, 8, 1, 7, 9, 1, 2, 3},
				 {0, 8, 8, 8, 1, 9, 9, 1, 2, 3},
				 {0, 8, 8, 8, 1, 2, 2, 1, 2, 3},
				 {0, 8, 8, 8, 1, 2, 2, 1, 2, 3},
				 {0, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {0, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {0, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {0, 8, 8, 8, 1, 7, 7, 1, 2, 3},
					};

	TEST_ASSERT_EQUAL_INT(0, zero_matrix(10, 10, matrix));
	print_matrix(10, 10, matrix_expected);
	print_matrix(10, 10, matrix);
	TEST_ASSERT_EQUAL_MEMORY(matrix_expected, matrix, sizeof(matrix));
}

static void test_valid_matrix_zero_10x10_b(void)
{
	uint8_t matrix[10][10] =  {
				 {1, 2, 3, 5, 7, 3, 2, 1, 2, 3},
				 {4, 5, 5, 5, 8, 5, 8, 1, 2, 3},
				 {8, 7, 8, 8, 1, 7, 9, 1, 2, 3},
				 {2, 8, 8, 8, 1, 9, 9, 1, 2, 3},
				 {2, 8, 8, 8, 1, 2, 2, 1, 2, 3},
				 {2, 8, 8, 8, 1, 2, 2, 1, 2, 3},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 3},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 0},
				};
	uint8_t matrix_expected[10][10] =  {
				 {1, 2, 3, 5, 7, 3, 2, 1, 2, 0},
				 {4, 5, 5, 5, 8, 5, 8, 1, 2, 0},
				 {8, 7, 8, 8, 1, 7, 9, 1, 2, 0},
				 {2, 8, 8, 8, 1, 9, 9, 1, 2, 0},
				 {2, 8, 8, 8, 1, 2, 2, 1, 2, 0},
				 {2, 8, 8, 8, 1, 2, 2, 1, 2, 0},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 0},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 0},
				 {2, 8, 8, 8, 1, 7, 7, 1, 2, 0},
				 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					};

	TEST_ASSERT_EQUAL_INT(0, zero_matrix(10, 10, matrix));
	print_matrix(10, 10, matrix_expected);
	print_matrix(10, 10, matrix);
	TEST_ASSERT_EQUAL_MEMORY(matrix_expected, matrix, sizeof(matrix));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_matrix_zero_input_1);
	RUN_TEST(test_invalid_matrix_zero_input_2);
	RUN_TEST(test_invalid_matrix_zero_input_3);
	RUN_TEST(test_invalid_matrix_zero_input_4);
	RUN_TEST(test_valid_matrix_zero_3x3);
	RUN_TEST(test_valid_matrix_zero_5x5);
	RUN_TEST(test_valid_matrix_zero_7x7);
	RUN_TEST(test_valid_matrix_zero_10x10);
	RUN_TEST(test_valid_matrix_zero_10x10_a);
	RUN_TEST(test_valid_matrix_zero_10x10_b);

	UNITY_END();

	return 0;
}
