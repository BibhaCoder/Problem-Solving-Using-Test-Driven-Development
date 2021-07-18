/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FIRST_DIGITS (9)
#define MAX_NUM_COUNTRIES (213)

static void test_benfords_law_world_covid_data(void)
{
	uint64_t i;
	double result;
	uint64_t sum = 0;
	uint64_t world_covid_1st_digit_count[NUM_FIRST_DIGITS + 1] =
					{0, 61, 48, 24, 18, 15, 7, 17, 11, 12};

	printf("benford's law: for august-05 2020 total infections data for 215 countries\n");

	for (i = 1; i <= NUM_FIRST_DIGITS; i++) {
		result = (world_covid_1st_digit_count[i] * 100.0) / (MAX_NUM_COUNTRIES);
		sum += world_covid_1st_digit_count[i];
		printf("digit %lu occured %lf precent\n", i, result);
	}
	printf("total countries %lu\n", sum);
}

int main()
{
	test_benfords_law_world_covid_data();

	return 0;
}
