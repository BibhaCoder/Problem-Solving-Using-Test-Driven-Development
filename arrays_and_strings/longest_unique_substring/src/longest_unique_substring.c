/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdbool.h>
#include "../inc/longest_unique_substring.h"

#define MAX_UNIQUE_ASCII_CHARS (256)

static ssize_t __longest_unique_substring(char const *s)
{
	size_t i;
	ssize_t longest_length, current_length;
	bool char_map[MAX_UNIQUE_ASCII_CHARS] = {false, };

	longest_length = current_length = 0;
	for (i = 0; s[i]; i++) {
		if (!char_map[s[i]]) {
			char_map[s[i]] = true;
			current_length++;
			if (current_length > longest_length)
				longest_length = current_length;
		} else {
			current_length = 1;
		}
	}

	return longest_length;
}

ssize_t longest_unique_substring(char const *s)
{
	if (!s)
		return -1;

	return __longest_unique_substring(s);
}
