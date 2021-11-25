/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/3_sum.h"
#include <stdbool.h>

/**
 * Solution 1: using sorting and 2 pointers(left and right)
 * Input can be sorted in O(NlogN) and using 2 pointers left and right
 * for each ingteger in array a pair can be found pairs can be found in O(N).
 * Total runtime of O(N^2)
 *
 * Solution 2: Brute force every tripet combination in array like 3 nested loops:
 * for (i = 0; i < N; i++)
 * 	for (j = i + 1 ; j < N; j++)
 * 		for (k = j + 1; k < N; k++)
 * Total runtime O(N^3)
 */

static int32_t __three_sum(int32_t *array, size_t size, int32_t sum)
{
	size_t i, left, right;
	int32_t temp_sum, total_three_sum_triplets = 0;

	for (i = 0; i < size - 1; i++) {
		left = i + 1;
		right = size - 1;
		while (left < right) {
			temp_sum = array[i] + array[left] + array[right];
			if (temp_sum == sum) {
				printf("[%d %d %d]==>(sum = %d)\n",
					array[i], array[left], array[right], sum);
				total_three_sum_triplets++;
				break;
			}
			else if (temp_sum > sum) {
				right--;
			} else {
				left++;
			}
		} 
	}

	return total_three_sum_triplets;
}

int32_t three_sum(int32_t *array, size_t size, int32_t sum)
{
	if (!array)
		return -1;

	if (size < 3 || size > MAX_INPUT_ARRAY_SIZE)
		return -1;

	return __three_sum(array, size, sum);
}
