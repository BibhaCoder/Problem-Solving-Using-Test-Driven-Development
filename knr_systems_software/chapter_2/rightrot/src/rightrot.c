/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include "../inc/rightrot.h"

static bool is_rightrot_input_valid(size_t x, uint8_t n)
{
	if (!n)
		return false;

	if (n > (sizeof(x) * CHAR_BIT))
		return false;

	return true;
}

static ssize_t get_left_shift_bits(size_t x, uint8_t n)
{
	return (sizeof(x) * CHAR_BIT) - n;
}

static ssize_t rightrot_bits(size_t x, uint8_t n)
{
	return (x >> n) | (x << get_left_shift_bits(x, n));
}

ssize_t rightrot(size_t x, uint8_t n)
{
	if (!is_rightrot_input_valid(x, n))
		return -1;

	return rightrot_bits(x, n);
}
