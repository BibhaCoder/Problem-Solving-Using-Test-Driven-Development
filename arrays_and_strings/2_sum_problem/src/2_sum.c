/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/2_sum.h"
#include <stdbool.h>

/**
 * Solution 1: using hash map without sorting the input array
 * Best optimal O(N) solution is using hash map but require O(N)
 * space for extra hash map memory
 *
 *
 * Solution 2: using sorting and 2 pointers(left and right)
 * Input can be sorted in O(NlogN) and using 2 pointers left and right
 * pairs can be constructed in O(N). Total runtime of O(NlogN)
 */

static int32_t __two_sum(uint32_t *array, size_t size, uint32_t sum)
{
	size_t i;
	int32_t missing_pair;
	int32_t total_two_sum_pairs = 0;
	bool hash_map[MAX_INT_SIZE + 1] =  {0, };

	for (i = 0; i < size; i++) {
		missing_pair = sum - array[i];
		if (missing_pair > MAX_INT_SIZE)
			continue;
		if (missing_pair < 0)
			continue;
		if (hash_map[missing_pair]) {
			total_two_sum_pairs++;
			printf("[%d %d]==>(sum = %d)\n", array[i], missing_pair, sum);
		} else {
			hash_map[array[i]] = true;
		}
	}

	return total_two_sum_pairs;
}

static bool is_input_valid(uint32_t *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++) {
		if (array[i] > MAX_INT_SIZE)
			return false;
	}

	return true;
}

int32_t two_sum(uint32_t *array, size_t size, uint32_t sum)
{
	if (!array)
		return -1;

	if (size < 2 || size > MAX_INT_SIZE)
		return -1;

	if (!is_input_valid(array, size))
		return -1;

	return __two_sum(array, size, sum);
}
