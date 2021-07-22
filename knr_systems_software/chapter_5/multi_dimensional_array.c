/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>

uint8_t a[10][20];
uint8_t *b[10];

static void test_multi_dimensional_array(void)
{
	printf("sizeof a %zu bytes size of b %zu bytes\n", sizeof(a), sizeof(b));	
}

int main()
{
	test_multi_dimensional_array();

	return 0;
}
