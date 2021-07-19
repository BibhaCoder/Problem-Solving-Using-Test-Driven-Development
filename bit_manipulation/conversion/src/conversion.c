/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/conversion.h"

static uint8_t count_1_bits(uint32_t val)
{
	uint8_t num_of_ones = 0;

	while (val) {
		num_of_ones++;
		val = val & (val - 1);
	}

	return num_of_ones;
}

uint8_t conversion(uint32_t num1, uint32_t num2)
{
	uint32_t diff_bits = num1 ^ num2;

	return count_1_bits(diff_bits);
}
