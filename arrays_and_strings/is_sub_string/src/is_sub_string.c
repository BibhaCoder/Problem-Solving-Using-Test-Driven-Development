#include "../inc/is_sub_string.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_STRING_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static ssize_t find_string(char const *s, char const *t)
{
	ssize_t i, j, k;

	for (i = 0; s[i]; i++) {
		for (j = i, k = 0; t[k] && s[j] == t[k]; k++, j++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}

static bool __is_sub_string(char const *s, char const *t)
{
	bool ret;
	char *temp;
	size_t s_len;
	size_t temp_len;

	s_len =  strlen(s);
	temp_len = (s_len << 1) + 1;
	temp = malloc(temp_len);
	if (!temp)
		return false;
	memset(temp, 0, temp_len);
	strncpy(temp, s, s_len);
	strncpy(temp + s_len, s, s_len);

	ret = find_string(temp, t) >= 0 ? true : false;
	free(temp);

	return ret;
}

static bool is_input_valid(char const *s)
{
	if (!s)
		return false;
	else if (!is_string_null_terminated(s))
		return false;
	else
		return true;
}

bool is_sub_string(char const *s, char const *t)
{
	if (!is_input_valid(s))
		return false;

	if (!is_input_valid(t))
		return false;

	return __is_sub_string(s, t);
}
