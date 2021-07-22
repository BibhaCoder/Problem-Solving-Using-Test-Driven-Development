/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../inc/setbits.h"

static bool is_setbits_input_valid(size_t p, size_t n)
{
	if (!n)
		return false;

	if (p < n - 1)
		return false;

	return true;
}

ssize_t set_required_bits(size_t x, size_t p, size_t n, size_t y)
{
	size_t x_mask = x & ~((~(~0 << n) << (p + 1 - n)));
	size_t y_mask = y & (~(~0 << n)) << (p + 1 - n);

	return x_mask | y_mask;
}

ssize_t setbits(size_t x, size_t p, size_t n, size_t y)
{
	if (!is_setbits_input_valid(p, n))
		return -1;

	return set_required_bits(x, p, n, y);
}
