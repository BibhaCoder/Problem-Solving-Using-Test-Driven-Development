/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/integer_palindrome.h"
#include <limits.h>

static bool __is_integer_palindrome(int32_t num)
{
	int32_t temp_num = num;
	int32_t out_num = 0;

	while (num) {
		out_num = (out_num * 10) + (num % 10);
		num /= 10;
	}

	if (temp_num == out_num)
		return true;
	else
		return false;
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

bool is_integer_palindrome(int32_t num)
{
	if (!is_input_valid(num))
		return false;

	return __is_integer_palindrome(num);
}

