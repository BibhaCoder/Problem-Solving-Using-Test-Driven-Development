/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>

#define DO_IT_WITHOUT_DO_WHILE_ZERO(x) printf("1st print call n is %u\n", x); \
					printf("2nd print call n is %u\n", x);

#define DO_IT_WITH_DO_WHILE_ZERO(x) do { \
						printf("1st print call n is %u\n", x); \
						printf("2nd print call n is %u\n", x); \
					} while (0);
static void test_macro_call_without_do_while_zero(uint32_t n)
{
	if (n > 0)
		DO_IT_WITHOUT_DO_WHILE_ZERO(n);
}

static void test_macro_call_with_do_while_zero(uint32_t n)
{
	if (n > 0)
		DO_IT_WITH_DO_WHILE_ZERO(n);
}

int main()
{
	printf("1st test without do while 0\n");
	test_macro_call_without_do_while_zero(0);
	printf("2nd test with do while 0\n");
	test_macro_call_with_do_while_zero(0);

	return 0;
}
