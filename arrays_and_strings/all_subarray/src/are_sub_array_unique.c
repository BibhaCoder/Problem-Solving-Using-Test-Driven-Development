#include "../inc/are_all_sub_array_unique.h"
#include <stdlib.h>
#include <string.h>

#define MAX_TWO_DIGITS_NUM (99)

static int size_two_temp_sub_arrays[MAX_ARRAY_SIZE * 2];

static bool is_input_valid(int const *array, size_t size)
{
	if (!array)
		return false;
	if (0 == size)
		return false;
	if (MAX_ARRAY_SIZE < size)
		return false;
	else
		return true;
}

static bool are_two_dup_consecutive_elements(int const *a, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
		if (a[i] == a[i + 1])
			return true;

	return false;
}

static bool compare_2_sub_arrays(int *a1, int const *a2,
				 size_t a1_size, size_t compare_size)
{
	size_t i;

	for (i = 0; i < a1_size; i++) {
		if (!memcmp(&a1[i], &a2[0], compare_size))
			return false;
	}

	return true;
}

/* this is a poor design:
 * runtime: O(N^2)
 * memory: O(N)
 */
static bool are_sub_arrays_unique(int const *a, size_t size)
{
	size_t i, j;
	size_t const sub_array_size = 2;
	size_t const sub_array_compare_size = 2 * sizeof(a[0]);

	/* its good enough to check only size 2 sub arrays
	 * to check if there are unique sub arrays of any size
	 * since any sub array of size 2 or higher must have to
	 * have at least size 2 subarray same:
	 * size 3 sub array will have to have size 2 + size 1
	 * size 4 sub array will have to have size 3(size 2 + 1) + size 1
	 * size N sub array will have to have size 2 + size 3 + size (N-1)
	 */

	/* runtime is still O(N ^ 2) if we can use a balanced search tree
	 * to look up for previous sub array(logN) then this problem can be
	 * solved in log(NlogN)
	 */
	memset(size_two_temp_sub_arrays, 0, sizeof(size_two_temp_sub_arrays));

	for (i = 0, j = 0; (i + sub_array_size) <= size; i++, j += sub_array_size) {
		if (!compare_2_sub_arrays(&size_two_temp_sub_arrays[0], &a[i],
					  j, sub_array_compare_size))
			return false;
		memcpy(&size_two_temp_sub_arrays[j], &a[i], sub_array_compare_size);
	}

	return true;
}

static int convert_array_two_elements_to_num(int const *a)
{
	int num = 0;

	num = a[0] * 10;
	num = num + a[1];

	return num;
}

/*
 * this is best optimal design:
 * runtime: O(N)
 * memory: O(1)
 */
static bool are_sub_arrays_unique_using_hash_map(int const *a, size_t size)
{
	int num;
	size_t i;
	size_t const required_sub_array_size = 2;
	bool two_digits_num_hash_map[MAX_TWO_DIGITS_NUM] = {false, };

	for (i = 0; (i + required_sub_array_size) <= size; i++) {
		num = convert_array_two_elements_to_num(&a[i]);
		if (two_digits_num_hash_map[num])
			return false;
		else
			two_digits_num_hash_map[num] = true;
	}

	return true;
}

bool are_all_sub_arrays_unique(int const *array, size_t size)
{
	if (!is_input_valid(array, size))
		return false;

	if (are_two_dup_consecutive_elements(array, size))
		return false;

	/* return are_sub_arrays_unique(array, size); */
	return are_sub_arrays_unique_using_hash_map(array, size);
}
