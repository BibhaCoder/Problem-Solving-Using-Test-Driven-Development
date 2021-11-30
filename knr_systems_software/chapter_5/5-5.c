/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>

static void str_n_cpy(char *s, char const *t, size_t n)
{
	size_t i;

	for (i = 0; i < n && t[i]; i++)
		s[i] = t[i];

	s[i] = '\0';
}

static void test_1_str_n_cpy(void)
{
	char s[10];
	char t[5] = {'0', '1', '2', '3'};
	
	str_n_cpy(s, t, 50000000);

	printf("s: %s t: %s\n", s, t);
}

int main()
{
	test_1_str_n_cpy();

	return 0;
}
