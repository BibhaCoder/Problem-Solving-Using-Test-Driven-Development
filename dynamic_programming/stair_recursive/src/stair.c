#include "../inc/stair.h"

/*
 * poor design:
 * runtime: O(3 ^ N)
 * space: O(N)
 */
static uint64_t recursive_stair(uint8_t n)
{
	if (0 == n)
		return 1;
	else if (1 == n)
		return 1;
	else if (2 == n)
		return 2;
	else
		return recursive_stair(n - 3) + recursive_stair(n - 2) +
		       recursive_stair(n - 1);
}

uint64_t stair(uint8_t n)
{
	return recursive_stair(n);
}
