#include <stdio.h>
#include <stdint.h>
#include "../inc/bitcount.h"

static uint8_t count_1_bits(uint32_t x)
{
	size_t no_of_1_bits = 0;

	while (x) {
		no_of_1_bits++;
		x &= (x - 1);
	}

	return no_of_1_bits;
}

uint8_t bitcount(uint32_t x)
{
	return count_1_bits(x);
}
