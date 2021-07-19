/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/bit_flip.h"
#include <limits.h>

#define MAX(a, b) (a > b ? a : b)

static uint32_t const all_ones = ~(uint32_t)0;

static int __bit_flip(uint32_t n)
{
	int current_length = 0;
	int previous_length = 0;
	int max_length = 0;

	while (n) {
		if (n & 0x1) {
			current_length++;
		} else {
			previous_length = (n & 0x2) ? current_length : 0;
			current_length = 0;
		}

		max_length = MAX(max_length, previous_length + current_length + 1);
		n >>= 1;
	}

	return max_length;
}

int bit_flip(uint32_t val)
{
	if (val == all_ones)
		return sizeof(val) * CHAR_BIT;
	else if (!val)
		return 1;
	else if (!(val & (val - 1)))
		return 2;
	else
		return __bit_flip(val);
}
