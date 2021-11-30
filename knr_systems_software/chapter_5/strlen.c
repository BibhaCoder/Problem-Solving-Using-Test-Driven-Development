/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>

static size_t strlen(char const *s)
{
	char const *t = s;

	while (*t)
		t++;

	return t - s;
}

int main()
{
	char const *s = "0123456789";

	printf("size of %s is %zu\n", s, strlen(s));

	return 0;
}
