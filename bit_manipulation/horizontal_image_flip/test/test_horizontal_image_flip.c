/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/horizontal_image_flip.h"
#include </Unity/src/unity.h>

#define NUM_ARRAY_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))

static void test_horizontal_image_flip_invalid_input_1(void)
{
	uint8_t *image = NULL;

	TEST_ASSERT_EQUAL_INT(-1, horizontal_image_flip(image, 0));
}

static void test_horizontal_image_flip_invalid_input_2(void)
{
	uint8_t image[] =  {0xAA, 0xBB};

	TEST_ASSERT_EQUAL_INT(-1, horizontal_image_flip(image, -1));
}

static void test_horizontal_image_flip_valid_input_1(void)
{
	uint8_t image[] =  {0xAA, 0xBB};
	uint8_t const flipped_image[] =  {0xBB, 0xAA};

	TEST_ASSERT_EQUAL_INT(0, horizontal_image_flip(image, sizeof(image)));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(flipped_image, image, NUM_ARRAY_ELEMENTS(image));
}

static void test_horizontal_image_flip_valid_input_2(void)
{
	uint8_t image[] =  {0xAA, 0xBB, 0xCC, 0xDD};
	uint8_t const flipped_image[] =  {0xCC, 0xDD, 0xAA, 0xBB};

	TEST_ASSERT_EQUAL_INT(0, horizontal_image_flip(image, sizeof(image)));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(flipped_image, image, NUM_ARRAY_ELEMENTS(image));
}

static void test_horizontal_image_flip_valid_input_3(void)
{
	uint8_t image[] =  {0xAA, 0xBB, 0xCC, 0xDD, 0x11, 0x22, 0x33, 0x44};
	uint8_t const flipped_image[] =  {0x11, 0x22, 0x33, 0x44, 0xAA, 0xBB, 0xCC, 0xDD};

	TEST_ASSERT_EQUAL_INT(0, horizontal_image_flip(image, sizeof(image)));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(flipped_image, image, NUM_ARRAY_ELEMENTS(image));
}

static void test_horizontal_image_flip_valid_input_4(void)
{
	uint8_t image[] =  {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55};
	uint8_t const flipped_image[] =  {0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE};

	TEST_ASSERT_EQUAL_INT(0, horizontal_image_flip(image, sizeof(image)));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(flipped_image, image, NUM_ARRAY_ELEMENTS(image));
}

static void test_horizontal_image_flip_valid_input_5(void)
{
	uint8_t image[] = {
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55
			  };
	uint8_t const flipped_image[] =
				{
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE
				};

	TEST_ASSERT_EQUAL_INT(0, horizontal_image_flip(image, sizeof(image)));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(flipped_image, image, NUM_ARRAY_ELEMENTS(image));
}

static void test_horizontal_image_flip_valid_input_6(void)
{
	uint8_t image[] = {
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55
			  };
	uint8_t const flipped_image[] =
				{
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE
				};

	TEST_ASSERT_EQUAL_INT(0, horizontal_image_flip(image, sizeof(image)));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(flipped_image, image, NUM_ARRAY_ELEMENTS(image));
}

static void test_horizontal_image_flip_valid_input_7(void)
{
	uint8_t image[] = {
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55
			  };
	uint8_t const flipped_image[] =
				{
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE
				};

	TEST_ASSERT_EQUAL_INT(0, horizontal_image_flip(image, sizeof(image)));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(flipped_image, image, NUM_ARRAY_ELEMENTS(image));
}

static void test_horizontal_image_flip_valid_input_8(void)
{
	uint8_t image[] = {
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55,
				0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x11, 0x22, 0x33, 0x44, 0x55
			  };
	uint8_t const flipped_image[] =
				{
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE,
					0x11, 0x22, 0x33, 0x44, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE
				};

	TEST_ASSERT_EQUAL_INT(0, horizontal_image_flip(image, sizeof(image)));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(flipped_image, image, NUM_ARRAY_ELEMENTS(image));
}

static void run_tests(void)
{
	RUN_TEST(test_horizontal_image_flip_invalid_input_1);
	RUN_TEST(test_horizontal_image_flip_invalid_input_2);
	RUN_TEST(test_horizontal_image_flip_valid_input_1);
	RUN_TEST(test_horizontal_image_flip_valid_input_2);
	RUN_TEST(test_horizontal_image_flip_valid_input_3);
	RUN_TEST(test_horizontal_image_flip_valid_input_4);
	RUN_TEST(test_horizontal_image_flip_valid_input_5);
	RUN_TEST(test_horizontal_image_flip_valid_input_6);
	RUN_TEST(test_horizontal_image_flip_valid_input_7);
	RUN_TEST(test_horizontal_image_flip_valid_input_8);
}

int main()
{
	UNITY_BEGIN();

	run_tests();

	UNITY_END();

	return 0;
}
