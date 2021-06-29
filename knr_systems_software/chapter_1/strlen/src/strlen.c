#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/string_length.h"

static bool is_input_string_valid(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_LINE_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_valid(char const *input_line)
{
	if (!input_line) {
		printf("null pointer input\n");
		return false;
	}

	if (!is_input_string_valid(input_line)) {
		printf("invalid string with no null terminator\n");
		return false;
	}

	if (strlen(input_line) >= MAX_INPUT_LINE_SIZE) {
		printf("input string longer than allowed size %d\n",
			MAX_INPUT_LINE_SIZE);
		return false;
	}

	return true;
}

size_t string_length(char const *s)
{
	size_t length = 0;

	if (!is_input_valid(s))
		return 0;

	while (s[length])
		length++;

	return length;
}
