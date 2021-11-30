/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>

int my_strcmp(char const *s, char const *t)
{
	size_t i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;

	return s[i] - t[i];
}

int my_strcmp_ptr_version(char const *s, char const *t)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;

	return *s - *t;
}

int main()
{
	char *s = "hello world1";
	char *t = "hello world1";

	printf("my_strcmp %d\n", my_strcmp(s, t));
	printf("my_strcmp %d\n", my_strcmp_ptr_version(s, t));

	return 0;
}
