/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include "../inc/circus.h"
#include "/Unity/src/unity.h"

static void test_empty_circus(void)
{
	int status;
	struct person *p = NULL;

	status = find_total_possible_human_towers(p, 0);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_invalid_height_circus(void)
{
	int status;
	struct person p[MAX_PEOPLE] = {
				      {350, 90},
				      };

	status = find_total_possible_human_towers(p, 1);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_2_person_circus(void)
{
	int status;
	struct person p[MAX_PEOPLE] = {
				      {65, 100},
				      {56, 90},
				      };
	struct person const expected[] = {
				          {56, 90},
				          {65, 100},
				          };

	status = find_total_possible_human_towers(p, 2);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_MEMORY(expected, p, sizeof(expected));
}

static void test_5_person_circus(void)
{
	int status;
	struct person p[MAX_PEOPLE] = {
				      {75, 190},
				      {65, 100},
				      {70, 150},
				      {56, 90},
				      {60, 95},
				      };
	struct person const expected[] = {
				          {56, 90},
				          {60, 95},
				          {65, 100},
				          {70, 150},
				          {75, 190},
				          };

	status = find_total_possible_human_towers(p, 5);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_MEMORY(expected, p, sizeof(expected));
}

static void test_7_person_circus(void)
{
	int status;
	struct person p[MAX_PEOPLE] = {
			      {7, 12},
			      {3, 1},
			      {5, 2},
			      {8, 9},
			      {6, 5},
			      {9, 15},
			      {6, 2},
			      };
	struct person const expected[] = {
				          {3, 1},
				          {5, 2},
				          {6, 2},
				          {9, 15},
				          };

	status = find_total_possible_human_towers(p, 7);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_MEMORY(expected, p, sizeof(expected));
}

static void test_9_person_circus(void)
{
	int status;
	struct person p[MAX_PEOPLE] = {
				      {12, 12},
				      {11, 11},
				      {9, 9},
				      {8, 8},
				      {15, 15},
				      {25, 25},
				      {3, 3},
				      {5, 5},
				      {2, 2},
			              };
	struct person const expected[] = {
				          {2, 2},
				          {3, 3},
				          {5, 5},
				          {8, 8},
				          {9, 9},
				          {11, 11},
				          {12, 12},
				          {15, 15},
				          {25, 25},
				          };

	status = find_total_possible_human_towers(p, 9);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_MEMORY(expected, p, sizeof(expected));
}

static void test_3_person_circus(void)
{
	int status;
	struct person p[MAX_PEOPLE] = {
				      {12, 3},
				      {1, 10},
				      {9, 2},
			              };
	struct person const expected[] = {
				          {0, 0},
				          {0, 0},
				          };

	status = find_total_possible_human_towers(p, 3);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_MEMORY(expected, p, sizeof(expected));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_empty_circus);
	RUN_TEST(test_invalid_height_circus);

	RUN_TEST(test_2_person_circus);
	RUN_TEST(test_5_person_circus);
	RUN_TEST(test_7_person_circus);
	RUN_TEST(test_9_person_circus);
	RUN_TEST(test_3_person_circus);

	UNITY_END();

	return 0;
}
