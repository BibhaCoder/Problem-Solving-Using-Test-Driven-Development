/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/atof.h"

static bool is_input_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_LINE_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool issign(char c)
{
	if ('+' == c ||'-' == c)
		return true;

	return false;
}

static bool isdecimal(char c)
{
	if ('.' == c)
		return true;

	return false;
}

static bool is_input_string_valid_for_atof(char const *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
		if (!isdigit(s[i]) && !issign(s[i]) &&
		    !isspace(s[i]) && !isdecimal(s[i]))
			return false;

	return true;
}

static bool is_input_valid(char const *s)
{
	if (!s)
		return false;

	if (!is_input_string_null_terminated(s))
		return false;

	if (!strlen(s))
		return false;

	if (!is_input_string_valid_for_atof(s))
		return false;

	return true;
}

static double skip_sign(char const **s)
{
	double sign = 1;

	if ('-' == **s) {
		sign = -1;
		(*s)++;
	} else if ('+' == **s) {
		(*s)++;
	}

	return sign;
}

static double convert_string_into_double(char const *s)
{
	size_t i;
	double sign;
	double power = 1;
	double number = 0;

	sign = skip_sign(&s);

	for (i = 0; isdigit(s[i]); i++)
		number = number * 10 + s[i] - '0';

	if ('.' == s[i]) {
		power = 1.0;
		i++;
	}

	for (; isdigit(s[i]); i++) {
		number = number * 10 + s[i] - '0';
		power *= 10;
	}

	return (number * sign) / power;
}

static void skip_white_spaces(char const **s)
{
	while (isspace(**s))
		(*s)++;
}

int atof(char const *s, double *output_number)
{
	if (!is_input_valid(s))
		return -1;

	skip_white_spaces(&s);

	*output_number = convert_string_into_double(s);

	return 0;
}
