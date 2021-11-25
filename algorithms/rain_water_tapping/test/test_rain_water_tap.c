/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/rain_water_tap.h"
#include "/Unity/src/unity.h"

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

static void rain_water_tap_invalid_input_1(void)
{
	size_t const arr[] = {1, 2};

	TEST_ASSERT_EQUAL(0, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_invalid_input_2(void)
{
	size_t const arr[] = {2, 1};

	TEST_ASSERT_EQUAL(0, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_3_element_array(void)
{
	size_t const arr[] = {5, 0, 5};

	TEST_ASSERT_EQUAL(5, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_4_element_array(void)
{
	size_t const arr[] = {5, 2, 3, 5};

	TEST_ASSERT_EQUAL(5, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_5_element_array(void)
{
	size_t const arr[] = {5, 2, 3, 1, 7};

	TEST_ASSERT_EQUAL(9, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_6_element_array(void)
{
	size_t const arr[] = {3, 0, 0, 2, 0, 4};

	TEST_ASSERT_EQUAL(10, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_12_element_array(void)
{
	size_t const arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	TEST_ASSERT_EQUAL(6, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_20_element_array(void)
{
	size_t const arr[] = {35, 1, 7, 1, 4, 2, 1, 0, 1, 3, 2, 1, 2, 1, 8, 25, 4, 3, 1, 7};

	TEST_ASSERT_EQUAL(329, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_25_element_array(void)
{
	size_t const arr[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5};

	TEST_ASSERT_EQUAL(115, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

static void rain_water_tap_35_element_array(void)
{
	size_t const arr[] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5};

	TEST_ASSERT_EQUAL(165, tap_rain_water(arr, ARRAY_SIZE(arr)));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(rain_water_tap_invalid_input_1);
	RUN_TEST(rain_water_tap_invalid_input_2);

	RUN_TEST(rain_water_tap_3_element_array);
	RUN_TEST(rain_water_tap_4_element_array);
	RUN_TEST(rain_water_tap_5_element_array);
	RUN_TEST(rain_water_tap_6_element_array);
	RUN_TEST(rain_water_tap_12_element_array);
	RUN_TEST(rain_water_tap_20_element_array);
	RUN_TEST(rain_water_tap_25_element_array);
	RUN_TEST(rain_water_tap_35_element_array);

	UNITY_END();

	return 0;
}
