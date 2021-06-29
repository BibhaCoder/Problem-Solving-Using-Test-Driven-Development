#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "../inc/strindex.h"

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_valid(char const *s)
{
	if (!s)
		return false;

	if(!strlen(s))
		return false;

	if (!is_string_null_terminated(s))
		return false;

	return true;
}

static ssize_t find_string_t_in_string_s(char const *s, char const *t)
{
	ssize_t i, j ,k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}

ssize_t strindex(char const *s, char const *t)
{
	if (!is_input_valid(s))
		return -1;

	if (!is_input_valid(t))
		return -1;

	if (strlen(t) > strlen(s))
		return -1;

	return find_string_t_in_string_s(s, t);
}
