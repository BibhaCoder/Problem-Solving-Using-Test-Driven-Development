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
#include "../inc/scientific_atof.h"

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

static bool is_decimal_point(char c)
{
	if ('.' == c)
		return true;

	return false;
}

static bool is_float_exponent(char c)
{
	if ('e' == c || 'E' == c)
		return true;

	return false;
}

static bool is_input_string_valid_for_scientific_atof(char const *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
		if (!isdigit(s[i]) && !issign(s[i]) &&
		    !isspace(s[i]) && !is_decimal_point(s[i]) &&
		    !is_float_exponent(s[i]))
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

	if (!is_input_string_valid_for_scientific_atof(s))
		return false;

	return true;
}

static double skip_sign_char(char const **s)
{
	double sign = 1;

	if ('-' == **s) {
		sign = -1;
		(*s)++;
	} else if('+' == **s){
		(*s)++;
	}

	return sign;
}

static double get_exponent_power(char const *s)
{
	size_t i;
	double sign = 1;
	uint32_t power = 0;
	double exponent_power = 1;

	s++;
	sign = skip_sign_char(&s);

	for (i = 0; isdigit(s[i]); i++)
		power = 10 * power + s[i] - '0';

	while (power) {
		exponent_power *= 10;
		power--;
	}

	if (sign < 0)
		exponent_power = 1.0 / exponent_power; 
	else
		exponent_power = 1.0 * exponent_power; 
	
	return exponent_power;
}

static double convert_string_into_double(char const *s)
{
	size_t i;
	double sign;
	double power = 1;
	double number = 0;
	double exponent_power = 1;

	sign = skip_sign_char(&s);

	for (i = 0; isdigit(s[i]); i++)
		number = number * 10 + s[i] - '0';

	if (is_decimal_point(s[i])) {
		power = 1.0;
		i++;
	}

	for (; isdigit(s[i]); i++) {
		number = number * 10 + s[i] - '0';
		power *= 10;
	}

	if (is_float_exponent(s[i]))
		exponent_power = get_exponent_power(&s[i]);

	return ((number * sign) / power) * exponent_power;
}

static void skip_white_spaces(char const **s)
{
	while (isspace(**s))
		(*s)++;
}

int scientific_atof(char const *s, double *output_number)
{
	if (!is_input_valid(s))
		return -1;

	skip_white_spaces(&s);

	*output_number = convert_string_into_double(s);

	return 0;
}
