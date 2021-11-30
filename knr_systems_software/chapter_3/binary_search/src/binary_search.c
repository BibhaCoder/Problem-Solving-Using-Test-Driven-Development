/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/binary_search.h"
#include <stdbool.h>
#include <stddef.h>

static bool is_input_sorted(int32_t const *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1 ; i++)
		if (array[i] > array[i + 1])
			return false;

	return true;
}

static bool is_input_valid(int32_t const *array, size_t size)
{
	if (!array)
		return false;
	else if (size > MAX_INPUT_SIZE)
		return false;
	else if (!is_input_sorted(array, size))
		return false;
	else 
		return true;
}

static int32_t __binary_search_2_checks(int32_t const *a, size_t size, int32_t const val)
{
	int32_t mid = 0;
	int32_t min = 0;
	int32_t max = size - 1;

	while (min <= max) {
		mid = min + ((max - min) >> 1);
		if (val > a[mid])
			min = mid + 1;
		else if (val < a[mid])
			max = mid - 1;
		else
			return mid;
			
	}

	return -1;
}

static int32_t __binary_search_3_checks(int32_t const *a, size_t size, int32_t const val)
{
	int32_t mid = 0;
	int32_t min = 0;
	int32_t max = size - 1;

	while (min <= max) {
		mid = min + ((max - min) >> 1);
		if (val > a[mid])
			min = mid + 1;
		else if (val < a[mid])
			max = mid - 1;
		else
			return mid;
			
	}

	return -1;
}

static int32_t
__binary_search_2_checks_return_min_if_found(int32_t const *a, size_t size,
					     int32_t const val)
{
	int32_t mid = 0;
	int32_t min = 0;
	int32_t max = size - 1;

	while (min < max) {
		mid = min + ((max - min) >> 1);
		if (val > a[mid])
			min = mid + 1;
		else
			max = mid;
	}

	if (val == a[min])
		return min;
	else
		return -1;
}

static int32_t
__binary_search_2_checks_return_max_if_found(int32_t const *a, size_t size,
					     int32_t const val)
{
	int32_t mid = 0;
	int32_t min = 0;
	int32_t max = size - 1;

	while (min < max) {
		mid = min + ((max - min) >> 1);
		if (val > a[mid])
			min = mid + 1;
		else
			max = mid;
	}

	if (val == a[max])
		return max;
	else
		return -1;
}

int binary_search(int32_t const *array, size_t size, int32_t val)
{
	if (!is_input_valid(array, size))
		return -1;

	return __binary_search_2_checks_return_max_if_found(array, size, val);
}
