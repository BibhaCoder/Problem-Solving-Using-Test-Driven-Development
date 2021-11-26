/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/stair.h"

/*
 * best optimial solution:
 * runtime: O(N)
 * space: O(N)
 */
static uint64_t dp_stair(uint8_t n)
{
	uint8_t i;
	uint64_t stair[MAX_STAIR_SIZE] = {0, };

	stair[0] = 1;
	stair[1] = 1;
	stair[2] = 2;

	for (i = 3; i <= n; i++)
		stair[i] =  stair[i - 1] + stair[i - 2] + stair[i - 3];

	return stair[n];
}

uint64_t stair(uint8_t n)
{
	 if (n > MAX_STAIR_SIZE)
		return 0;

	return dp_stair(n);
}
