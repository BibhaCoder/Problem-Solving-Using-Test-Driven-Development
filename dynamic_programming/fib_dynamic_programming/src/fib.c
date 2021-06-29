#include "../inc/fib.h"

/*
 * best optimial design:
 * runtime: O(N)
 * space: O(N)
 */
static uint64_t dynamic_programming_fib(uint64_t n)
{
	uint64_t i;
	uint64_t fib[DP_FIB_MAX_INPUT] = {0, };

	/* dynamic programming: bottom up approach */
	fib[0] = 0;
	fib[1] = 1;

	for (i = 2; i <= n; i++)
		fib[i] = fib[i - 1] + fib[i - 2]; 

	return fib[n];
}

uint64_t fib(uint64_t n)
{
	if (n > DP_FIB_MAX_INPUT)
		return 0;

	return dynamic_programming_fib(n);
}
