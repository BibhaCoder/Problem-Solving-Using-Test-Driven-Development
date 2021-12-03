/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/integer_reverse.h"
#include <limits.h>
#include <stdio.h>

static int32_t __integer_reverse(int32_t num)
{
	int32_t out_num = 0;

	printf("num %d\n", num);
	while (num) {
		out_num = (out_num * 10) + (num % 10);
		num /= 10;
		printf("out_num %d num %d\n", out_num, num);
	}

	return out_num;
}

static bool is_input_valid(int32_t num)
{
	int32_t last_digit;

	/* invalid inputs which can lead to int32 overflow */

	if ((num > 1000000000)) {
		last_digit = num % 10;
		if (last_digit > 2)
			return false;
	}

	if ((num < -1000000000)) {
		last_digit = num % 10;
		if (last_digit < -2)
			return false;
	}

	if (INT_MIN == num)
		return false;

	if (INT_MAX == num)
		return false;

	return true;
}

int32_t integer_reverse(int32_t num)
{
	if ((-10 < num) && (num < 10))
		return num;

	if (!is_input_valid(num))
		return -1;

	return __integer_reverse(num);
}

