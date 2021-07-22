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
#include "../inc/htoi.h"

static bool is_input_string_valid(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_LINE_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_hex(char c)
{
	if ('A' <= c && c <= 'F')
		return true;
	else if ('a' <= c && c <= 'f')
		return true;
	else
		return false;
}

static bool is_input_string_valid_for_htoi(char const *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++) {
		if (!isdigit(s[i]) && !is_hex(s[i]))
			return false;
	}

	return true;
}

static bool is_input_valid(char const *input_number)
{
	if (!input_number) {
		printf("null pointer input\n");
		return false;
	}

	if (!is_input_string_valid(input_number)) {
		printf("invalid string with no null terminator\n");
		return false;
	}

	if (strlen(input_number) >= MAX_INPUT_LINE_SIZE) {
		printf("input string longer than allowed size %d\n",
			MAX_INPUT_LINE_SIZE);
		return false;
	}

	return true;
}

static bool is_input_hex_string_valid(char const *input_number)
{
	if (!is_input_string_valid_for_htoi(input_number)) {
		printf("invalid string number for htoi: %.*s\n",
		       MAX_INPUT_LINE_SIZE, input_number);
		return false;
	}

	return true;
}

static uint64_t convert_hex_string_into_number(char const *s)
{
	size_t i;
	uint64_t number = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (is_hex(s[i])) {
			if (islower(s[i]))
				number = number * 16 + (10 + s[i] - 'a');
			else
				number = number * 16 + (10 + s[i] - 'A');
		} else {
			number = number * 10 + s[i] - '0';
		}
	}

	return number;
}

static void skip_white_spaces(char const **s)
{
	while (isspace(**s))
		(*s)++;
}

static void skip_hex_symbol(char const **s)
{
	if (**s == '0')
		(*s)++;
	if (**s == 'x')
		(*s)++;
	if (**s == 'X')
		(*s)++;
}

uint64_t htoi(char const *s)
{
	if (!is_input_valid(s))
		return 0;

	skip_white_spaces(&s);

	skip_hex_symbol(&s);

	if (!is_input_hex_string_valid(s))
		return 0;

	return convert_hex_string_into_number(s);
}
