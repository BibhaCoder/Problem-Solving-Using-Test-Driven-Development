#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "../inc/getint.h"

static bool is_input_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_STRING_SIZE; i++)
		if (!s[i])
			return true;

	return false;
}

static bool is_sign_char(char c)
{
	if ('+' == c || '-' == c)
		return true;
	else
		return false;
}

static bool is_input_string_valid_for_getint(char const *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		if (!isdigit(s[i]) && !is_sign_char(s[i]) && !isspace(s[i]))
			return false;

	return true;
}

static bool is_input_valid(char const *s)
{
	if (!s)
		return false;
	if (!is_input_string_null_terminated(s))
		return false;
	if (!is_input_string_valid_for_getint(s))
		return false;
	if (!strlen(s))
		return false;

	return true;
}

static void skip_white_spaces(char const **s)
{
	while (isspace(**s))
		(*s)++;
}

int convert_string_to_number(char const *s)
{
	size_t i;
	int sign = 1;
	int num = 0;

	skip_white_spaces(&s);

	if (is_sign_char(*s)) {
		sign = (*s == '-' ? -1 : 1); 
		s++;
	}

	if (!isdigit(*s))
		return ERROR;

	for (i = 0; s[i]; i++)
		num = 10 * num + s[i] - '0';

	return num * sign;
}

int getint(char const *s)
{
	if (!is_input_valid(s))
		return ERROR;

	return convert_string_to_number(s);
}
