#include <stdio.h>
#include "../inc/string_find.h"
#include <stdbool.h>
#include <string.h>

static bool is_input_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_STRING_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_string_valid(char const *s)
{
	if (!s)
		return false;

	if (!is_input_string_null_terminated(s))
		return false;

	if (!strlen(s))
		return false;

	return true;
}

static char const *look_up_string(char const *s, char const *t)
{
	size_t i, j, k;

	for (i = 0; s[i]; i++) {
		for (j = i, k = 0; t[k] && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && !t[k])
			return &s[i];
	}

	return NULL;
}

char const *string_find(char const *s, char const *t)
{
	if (!is_input_string_valid(s))
		return NULL;

	if (!is_input_string_valid(t))
		return NULL;

	return look_up_string(s, t);
}
