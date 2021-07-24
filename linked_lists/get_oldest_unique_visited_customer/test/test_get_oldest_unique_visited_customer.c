/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/get_oldest_unique_visited_customer.h"
#include "/Unity/src/unity.h"
#include <stdlib.h>
#include <stdio.h>

static void get_oldest_unique_customer_invalid_input_0(void)
{
	TEST_ASSERT_EQUAL_INT(-1, get_oldest_unique_visited_customer());
}

static void get_oldest_unique_customer_invalid_input_1(void)
{
	TEST_ASSERT_EQUAL_INT(-1, visit_service(MAX_NUM_CUSTOMERS + 1));
	TEST_ASSERT_EQUAL_INT(-1, visit_service(MAX_NUM_CUSTOMERS + 1));
}

static void get_oldest_unique_customer_valid_input_0(void)
{
	TEST_ASSERT_EQUAL_INT(0, visit_service(2));
	TEST_ASSERT_EQUAL_INT(2, get_oldest_unique_visited_customer());
}

static void get_oldest_unique_customer_valid_input_1(void)
{
	TEST_ASSERT_EQUAL_INT(0, visit_service(3));
	TEST_ASSERT_EQUAL_INT(2, get_oldest_unique_visited_customer());
}

static void get_oldest_unique_customer_valid_input_2(void)
{
	TEST_ASSERT_EQUAL_INT(0, visit_service(5));
	TEST_ASSERT_EQUAL_INT(2, get_oldest_unique_visited_customer());
}

static void get_oldest_unique_customer_valid_input_3(void)
{
	TEST_ASSERT_EQUAL_INT(0, visit_service(2));
	TEST_ASSERT_EQUAL_INT(3, get_oldest_unique_visited_customer());
}

static void get_oldest_unique_customer_valid_input_4(void)
{
	TEST_ASSERT_EQUAL_INT(0, visit_service(8));
	TEST_ASSERT_EQUAL_INT(3, get_oldest_unique_visited_customer());
}

static void get_oldest_unique_customer_valid_input_5(void)
{
	TEST_ASSERT_EQUAL_INT(0, visit_service(3));
	TEST_ASSERT_EQUAL_INT(5, get_oldest_unique_visited_customer());
}

static void get_oldest_unique_customer_valid_input_6(void)
{
	TEST_ASSERT_EQUAL_INT(0, visit_service(5));
	TEST_ASSERT_EQUAL_INT(8, get_oldest_unique_visited_customer());
}

static void test_reset_customer_visits(void)
{
	TEST_ASSERT_EQUAL_INT(0, reset_customer_visits());
}

static void get_oldest_unique_customer_valid_N_users(uint32_t num_users)
{
	uint32_t i;
	uint32_t r;
	uint32_t first_customer;

	printf("start %u customer visits\n", num_users);
	first_customer =  rand() % num_users;
	TEST_ASSERT_EQUAL_INT(0, visit_service(first_customer));
	for (i = 0; i < num_users; i++) {
		if (first_customer != i)
			TEST_ASSERT_EQUAL_INT(0, visit_service(i));
	}
	printf("end %u customer visits\n", num_users);

	printf("start %u random customer visits except %u\n",
	       num_users, first_customer);
	for (i = 0; i < num_users; i++) {
		r = rand() % num_users;
		if (first_customer != r)
			TEST_ASSERT_EQUAL_INT(0, visit_service(r));
	}
	printf("end %u random customer visits except %u\n",
	       num_users, first_customer);

	TEST_ASSERT_EQUAL_INT(first_customer, get_oldest_unique_visited_customer());

	TEST_ASSERT_EQUAL_INT(0, reset_customer_visits());
}

static void get_oldest_unique_customer_valid_1_million_users(void)
{
	get_oldest_unique_customer_valid_N_users(1000000);
}

static void get_oldest_unique_customer_valid_10_million_users(void)
{
	get_oldest_unique_customer_valid_N_users(10000000);
}

static void get_oldest_unique_customer_valid_20_million_users(void)
{
	get_oldest_unique_customer_valid_N_users(20000000);
}

static void get_oldest_unique_customer_valid_50_million_users(void)
{
	get_oldest_unique_customer_valid_N_users(50000000);
}

static void get_oldest_unique_customer_valid_100_million_users(void)
{
	get_oldest_unique_customer_valid_N_users(100000000);
}

static void run_tests(void)
{
	RUN_TEST(get_oldest_unique_customer_invalid_input_0);
	RUN_TEST(get_oldest_unique_customer_invalid_input_1);

	RUN_TEST(get_oldest_unique_customer_valid_input_0);
	RUN_TEST(get_oldest_unique_customer_valid_input_1);
	RUN_TEST(get_oldest_unique_customer_valid_input_2);
	RUN_TEST(get_oldest_unique_customer_valid_input_3);
	RUN_TEST(get_oldest_unique_customer_valid_input_4);
	RUN_TEST(get_oldest_unique_customer_valid_input_5);
	RUN_TEST(get_oldest_unique_customer_valid_input_6);

	RUN_TEST(test_reset_customer_visits);
	RUN_TEST(get_oldest_unique_customer_valid_1_million_users);
	RUN_TEST(get_oldest_unique_customer_valid_10_million_users);
	RUN_TEST(get_oldest_unique_customer_valid_20_million_users);
	RUN_TEST(get_oldest_unique_customer_valid_50_million_users);
	RUN_TEST(get_oldest_unique_customer_valid_100_million_users);
}

int main()
{
	UNITY_BEGIN();

	while (1)
		run_tests();

	UNITY_END();

	return 0;
}
