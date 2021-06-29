#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../inc/invert.h"

static bool is_invert_input_valid(size_t p, size_t n)
{
	if (!n)
		return false;

	if (p + 1 < n)
		return false;

	return true;
}

ssize_t invert_bits(size_t x, size_t p, size_t n)
{
	return x ^ ((~(~0 << n) << (p + 1 - n)));
}

ssize_t invert(size_t x, size_t p, size_t n)
{
	if (!is_invert_input_valid(p, n))
		return -1;

	return invert_bits(x, p, n);
}
