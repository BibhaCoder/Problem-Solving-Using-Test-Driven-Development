/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/image_flip.h"
#include "/Unity/src/unity.h"

static void image_flip_test_invalid_input_0(void)
{
	TEST_ASSERT_EQUAL_INT(-1, image_flip(0, 0, NULL));
}

static void image_flip_test_invalid_input_1(void)
{
	uint8_t image[2][2] =  {{1, 2},
				{3, 4}};

	TEST_ASSERT_EQUAL_INT(-1, image_flip(0, 2, image));
}

static void image_flip_test_invalid_input_2(void)
{
	uint8_t image[2][2] =  {{1, 2},
				{3, 4}};

	TEST_ASSERT_EQUAL_INT(-1, image_flip(2, 0, image));
}

static void image_flip_test_invalid_input_3(void)
{
	uint8_t image[2][3] =  {{1, 2, 3},
				{3, 4, 5}};

	TEST_ASSERT_EQUAL_INT(-1, image_flip(2, 3, image));
}

static void image_flip_test_valid_input_0(void)
{
	uint8_t image[2][2] =  {{1, 2},
				{3, 4}};

	uint8_t flipped_image[2][2] =  {{2, 1},
					{4, 3}};

	TEST_ASSERT_EQUAL_INT(0, image_flip(2, 2, image));
	TEST_ASSERT_EQUAL_MEMORY(flipped_image, image, sizeof(flipped_image));
}

static void image_flip_test_valid_input_1(void)
{
	uint8_t image[][4] =  {{1, 2, 3, 4},
			       {3, 4, 5, 6}};

	uint8_t flipped_image[][4] =  {{3, 4, 1, 2},
				       {5, 6, 3, 4}};

	TEST_ASSERT_EQUAL_INT(0, image_flip(2, 4, image));
	TEST_ASSERT_EQUAL_MEMORY(flipped_image, image, sizeof(flipped_image));
}

static void image_flip_test_valid_input_2(void)
{
	uint8_t image[][4] =  {{1, 2, 3, 4},
			       {6, 7, 8, 9},
			       {2, 4, 6, 8},
			       {3, 4, 5, 6}};

	uint8_t flipped_image[][4] =  {{3, 4, 1, 2},
				       {8, 9, 6, 7},
				       {6, 8, 2, 4},
				       {5, 6, 3, 4}};

	TEST_ASSERT_EQUAL_INT(0, image_flip(4, 4, image));
	TEST_ASSERT_EQUAL_MEMORY(flipped_image, image, sizeof(flipped_image));
}

static void image_flip_test_valid_input_3(void)
{
	uint8_t image[][8] =  {{3, 3, 3, 3, 5, 5, 5, 5},
			       {3, 3, 3, 3, 5, 5, 5, 5},
			       {3, 3, 3, 3, 5, 5, 5, 5},
			       {3, 3, 3, 3, 5, 5, 5, 5},
			       {3, 3, 3, 3, 5, 5, 5, 5},
			       {3, 3, 3, 3, 5, 5, 5, 5},
			       {3, 3, 3, 3, 5, 5, 5, 5},
			       {3, 3, 3, 3, 5, 5, 5, 5}};

	uint8_t flipped_image[][8] =  {{5, 5, 5, 5, 3, 3, 3, 3},
				       {5, 5, 5, 5, 3, 3, 3, 3},
				       {5, 5, 5, 5, 3, 3, 3, 3},
				       {5, 5, 5, 5, 3, 3, 3, 3},
				       {5, 5, 5, 5, 3, 3, 3, 3},
				       {5, 5, 5, 5, 3, 3, 3, 3},
				       {5, 5, 5, 5, 3, 3, 3, 3},
				       {5, 5, 5, 5, 3, 3, 3, 3}};

	TEST_ASSERT_EQUAL_INT(0, image_flip(8, 8, image));
	TEST_ASSERT_EQUAL_MEMORY(flipped_image, image, sizeof(flipped_image));
}

static void image_flip_test_valid_input_4(void)
{
	uint8_t image[][8] =  {{2, 2, 2, 2, 5, 5, 5, 5},
			       {2, 2, 2, 2, 5, 5, 5, 5},
			       {2, 2, 2, 2, 5, 5, 5, 5},
			       {2, 2, 2, 2, 5, 5, 5, 5},
			       {2, 2, 2, 2, 5, 5, 5, 5},
			       {2, 2, 2, 2, 5, 5, 5, 5},
			       {2, 2, 2, 2, 5, 5, 5, 5},
			       {2, 2, 2, 2, 5, 5, 5, 5}};

	uint8_t flipped_image[][8] =  {{5, 5, 5, 5, 2, 2, 2, 2},
				       {5, 5, 5, 5, 2, 2, 2, 2},
				       {5, 5, 5, 5, 2, 2, 2, 2},
				       {5, 5, 5, 5, 2, 2, 2, 2},
				       {5, 5, 5, 5, 2, 2, 2, 2},
				       {5, 5, 5, 5, 2, 2, 2, 2},
				       {5, 5, 5, 5, 2, 2, 2, 2},
				       {5, 5, 5, 5, 2, 2, 2, 2}};

	TEST_ASSERT_EQUAL_INT(0, image_flip(8, 8, image));
	TEST_ASSERT_EQUAL_MEMORY(flipped_image, image, sizeof(flipped_image));
}

static void image_flip_test_valid_input_5(void)
{
	uint8_t image[][8] =  {{1, 1, 1, 1, 2, 2, 2, 2},
			       {1, 1, 1, 1, 2, 2, 2, 2},
			       {1, 1, 1, 1, 2, 2, 2, 2},
			       {1, 1, 1, 1, 2, 2, 2, 2},
			       {1, 1, 1, 1, 2, 2, 2, 2},
			       {1, 1, 1, 1, 2, 2, 2, 2},
			       {1, 1, 1, 1, 2, 2, 2, 2},
			       {1, 1, 1, 1, 2, 2, 2, 2}};

	uint8_t flipped_image[][8] =  {{2, 2, 2, 2, 1, 1, 1, 1},
				       {2, 2, 2, 2, 1, 1, 1, 1},
				       {2, 2, 2, 2, 1, 1, 1, 1},
				       {2, 2, 2, 2, 1, 1, 1, 1},
				       {2, 2, 2, 2, 1, 1, 1, 1},
				       {2, 2, 2, 2, 1, 1, 1, 1},
				       {2, 2, 2, 2, 1, 1, 1, 1},
				       {2, 2, 2, 2, 1, 1, 1, 1}};

	TEST_ASSERT_EQUAL_INT(0, image_flip(8, 8, image));
	TEST_ASSERT_EQUAL_MEMORY(flipped_image, image, sizeof(flipped_image));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(image_flip_test_invalid_input_0);
	RUN_TEST(image_flip_test_invalid_input_1);
	RUN_TEST(image_flip_test_invalid_input_2);
	RUN_TEST(image_flip_test_invalid_input_3);

	RUN_TEST(image_flip_test_valid_input_0);
	RUN_TEST(image_flip_test_valid_input_1);
	RUN_TEST(image_flip_test_valid_input_2);
	RUN_TEST(image_flip_test_valid_input_3);
	RUN_TEST(image_flip_test_valid_input_4);
	RUN_TEST(image_flip_test_valid_input_5);


	UNITY_END();

	return 0;
}
