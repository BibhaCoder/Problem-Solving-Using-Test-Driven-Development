/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/my_atoi.h"

static bool is_input_string_valid(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_LINE_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_string_valid_for_atoi(char const *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] < '0' || s[i] > '9')
			return false;

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

	if (!is_input_string_valid_for_atoi(input_number)) {
		printf("invalid string number for atoi %.*s\n",
		       MAX_INPUT_LINE_SIZE, input_number);
		return false;
	}

	if (strlen(input_number) >= MAX_INPUT_LINE_SIZE) {
		printf("input string longer than allowed size %d\n",
			MAX_INPUT_LINE_SIZE);
		return false;
	}

	return true;
}

static uint64_t convert_string_into_number(char const *s)
{
	size_t i;
	uint64_t number = 0;

	for (i = 0; s[i] != '\0'; i++)
		number = number * 10 + s[i] - '0';

	return number;
}

size_t my_atoi(char const *s)
{
	if (!is_input_valid(s))
		return 0;

	return convert_string_into_number(s);
}
