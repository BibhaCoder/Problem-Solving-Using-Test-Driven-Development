/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>

static void test_floating_point_limit_1(void)
{
	float const limit = 2e7;
	float i;

	for (i = limit - 10; i < limit; i += 1.2)
		printf("i is %f and limit is %f\n", i, limit);

}

static void test_floating_point_limit_2(void)
{
	float const limit = 2e7;
	float i;

	for (i = limit - 10; i < limit; i += 1.7)
		printf("i is %f and limit is %f\n", i, limit);

}

static void test_floating_point_limit_3(void)
{
	float const limit = 2e7;
	float i;

	for (i = limit - 10; i < limit; i += 1.5)
		printf("i is %f and limit is %f\n", i, limit);

}

static void test_floating_point_limit_4(void)
{
	float const limit = 2e7;
	float i;
	float index = 1.0;

	for (i = 0; i < 2e7; i++)
		printf("index is %f\n", index++);

	for (i = limit - 10; i < limit; i += 1.0)
		printf("i is %f and limit is %f\n", i, limit);

}

int main()
{
	test_floating_point_limit_1();
	test_floating_point_limit_2();
	test_floating_point_limit_3();
	test_floating_point_limit_4();

	return 0;
}
