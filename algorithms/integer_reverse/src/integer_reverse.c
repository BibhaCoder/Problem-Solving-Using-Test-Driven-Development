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

int32_t integer_reverse(int32_t num)
{
	if ((-10 < num) && (num < 10))
		return num;

	/* invalid input can lead to int32 overflow */
	if (INT_MIN == num)
		return -1;

	/* invalid input can lead to int32 overflow */
	if (INT_MAX == num)
		return -1;

	return __integer_reverse(num);
}

