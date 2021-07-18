/*  
 * Copyright (c) 2017 BibhaCoder. All rights reserved.  
 * Licensed under the MIT License. See MIT license for full license information.  
 */

#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define MAX_NUMBER (1000)

static uint64_t memoization_array[MAX_NUMBER];

static uint64_t fib_recursive(uint64_t n)
{
	uint64_t result;

	if (n == 1 || n == 2)
		return 1;
	else
		result = fib_recursive(n - 1) + fib_recursive(n - 2);

	return result;
}

static uint64_t fib_memoization(uint64_t n)
{
	uint64_t result;

	if (n == 1 || n == 2)
		return 1;

	/* dynamic programming: return already computed results */
	if (memoization_array[n])
		return memoization_array[n];
	else
		result = fib_memoization(n - 1) + fib_memoization(n - 2);

	/* dynamic programming: store already computed results */
	memoization_array[n] = result;

	return result;
}

static void compute_fib_recursive(uint64_t n)
{
	uint64_t result;
	double t, time_taken;

	t = clock();
	result = fib_recursive(n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%s took %f seconds to compute fibinaci of %lu and result is %lu\n",
		__func__, time_taken, n, result);
}

static void compute_fib_memoization(uint64_t n)
{
	uint64_t result;
	double t, time_taken;

	t = clock();
	result = fib_memoization(n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%s took %f seconds to compute fibinaci of %lu and result is %lu\n",
		__func__, time_taken, n, result);
}

int main()
{
	compute_fib_memoization(50);
	compute_fib_recursive(50);

	return 0;
}
