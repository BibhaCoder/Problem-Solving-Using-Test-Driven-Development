/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH (100)

static int generate_all_substring(char const *s)
{
	size_t i, sub_string_len, len;
	char sub_string[MAX_STRING_LENGTH] = {0,};

	if (!s)
		return -1;

	len = strlen(s);
	for (sub_string_len = 1; sub_string_len <= len; sub_string_len++) {
		for (i = 0; (i + sub_string_len) <= len; i++) {
			strncpy(sub_string, (s + i), sub_string_len);
			printf("%s\n", sub_string);
		}
	}

	return 0;
}

int main()
{
	char const *s0 = "12345";
	char const *s = "abcd";
	char const *t = "abcde";
	char const *s1 = "abcdef";
	char const *t1 = "abcdefg";
	char const *s2 = "abcdefghijklmnopqrstuvwxyz";

	generate_all_substring(s);

	generate_all_substring(t);

	generate_all_substring(s1);

	generate_all_substring(t1);

	generate_all_substring(s0);

	generate_all_substring(s2);

	return 0;
}
