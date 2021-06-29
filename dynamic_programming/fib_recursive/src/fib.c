#include "../inc/fib.h"

/*
 * poo design:
 * runtime: O(2 ^ N)
 * space: O(N)
 */
static uint64_t recursive_fib(uint64_t n)
{
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;
	else
		return recursive_fib(n - 1) + recursive_fib(n -2);
}

uint64_t fib(uint64_t n)
{
	return recursive_fib(n);
}
