/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *test_strcat(char const *s, char const *t)
{
	size_t len;
	char *new;

	len = strlen(s) + strlen(t) + 1;
	new = malloc(len);
	printf("allocated memory address %p\n", new);
	if (!new)
		return NULL;

	while((*new++ = *s++)) ;
	new--;
	while((*new++ = *t++)) ;

	return new - len;
}

static void test_1_str_cat_pointer_version(void)
{
	char const *s = "01234";
	char const *t = "56789abcdef";
	char *n;

	n = test_strcat(s, t);
	if (!n)
		return;

	printf("s: %s t: %s new: %s\n", s, t, n);
	printf("freed memory address %p\n", n);
	free(n);
}

static void test_2_str_cat_pointer_version(void)
{
	char const *s = "space time ";
	char const *t = "odyssey";
	char *n;

	n = test_strcat(s, t);
	if (!n)
		return;

	printf("s: %s t: %s new: %s\n", s, t, n);
	printf("freed memory address %p\n", n);
	free(n);
}

int main()
{
	test_1_str_cat_pointer_version();
	test_2_str_cat_pointer_version();

	return 0;
}
