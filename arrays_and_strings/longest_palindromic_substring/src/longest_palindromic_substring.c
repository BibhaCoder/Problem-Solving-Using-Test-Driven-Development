/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/longest_palindromic_substring.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Solution 1: generate all substrings with longest to shortest
 * substring length. Check longest 1st and if its palindrome then
 * return this substring.
 *
 * Runtime: O(N ^ 2) since its generating all substrings with length
 * N -> (N - 1) -> (N - 2) -> (N - 3) -> .. -> 3 -> 2 -> 1
 *
 */

static bool is_palindrome(char const *s)
{
	size_t len;
	size_t left, right;

	len = strlen(s);
	if (1 == len)
		return true;

	left = 0;
	right = len - 1;
	while (left < right) {
		if (s[left] != s[right])
			return false;

		left++;
		right--;
	}

	return true;
}

static char *__longest_palindromic_substring(char const *s)
{
	size_t i, sub_string_len, len;
	char *sub_string;

	len = strlen(s);
	sub_string = malloc(len + 1);
	if (!sub_string)
		return NULL;

	memset(sub_string, 0, len + 1);
	for (sub_string_len = len; sub_string_len > 0; sub_string_len--) {
		for (i = 0; (i + sub_string_len) <= len; i++) {
			strncpy(sub_string, (s + i), sub_string_len);
			sub_string[sub_string_len] = '\0';
			if (is_palindrome(sub_string))
				return sub_string;
		}
	}

	return NULL;
}

char *longest_palindromic_substring(char const *s)
{
	if (!s)
		return NULL;

	return __longest_palindromic_substring(s);
}
