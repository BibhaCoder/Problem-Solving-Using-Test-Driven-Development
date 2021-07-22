/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../inc/getbit.h"

static bool is_getbit_input_valid(size_t p, size_t n)
{
	if (!n)
		return false;

	if (p < n - 1)
		return false;

	return true;
}

static ssize_t extract_bits(size_t x, size_t p, size_t n)
{
	return (x >> (p + 1 - n)) & (~(~0 << n));
}

ssize_t getbit(size_t x, size_t p, size_t n)
{
	if (!is_getbit_input_valid(p, n))
		return -1;

	return extract_bits(x, p, n);
}
