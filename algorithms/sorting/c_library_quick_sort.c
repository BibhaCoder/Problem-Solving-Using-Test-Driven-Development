/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdlib.h>

static int values[] = { 88, 56, 100, 2, 25 };

static int my_cmp_func(void const * a, void const *b)
{
	return (*(int*)a - *(int*)b);
}

int main ()
{
	size_t n;

	printf("Before sorting the list is: \n");
	for(n = 0 ; n < 5; n++)
		printf("%d ", values[n]);

	qsort(values, sizeof(values)/sizeof(values[0]), sizeof(int), my_cmp_func);

	printf("\nAfter sorting the list is: \n");
	for( n = 0 ; n < 5; n++ )
		printf("%d ", values[n]);

	return 0;
}
