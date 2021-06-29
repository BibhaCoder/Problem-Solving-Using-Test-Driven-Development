#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../inc/strend.h" 

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_STRING_SIZE; i++)
		if (!s[i])
			return true;

	return false;
}

static bool is_input_string_valid(char const *s)
{
	if (!s)
		return false;

	if (!is_string_null_terminated(s))
		return false;

	if (!strlen(s))
		return false;

	return true;
}

bool find_string_at_end(char const *s, char const *t)
{
	size_t i, j, k;
	size_t right_most_position;

	right_most_position = strlen(s) - strlen(t);

	for (i = right_most_position; s[i]; i++) {
		for (j = i, k = 0; t[k] && s[j] == t[k]; k++, j++)
			;
		if (!t[k] && k > 0)
			return true;
		else
			return false;
	}

	return false;
}

bool strend(char const *s, char const *t)
{
	if (!is_input_string_valid(s))
		return false;

	if (!is_input_string_valid(t))
		return false;

	if (strlen(s) < strlen(t))
		return false;

	return find_string_at_end(s, t);
}
