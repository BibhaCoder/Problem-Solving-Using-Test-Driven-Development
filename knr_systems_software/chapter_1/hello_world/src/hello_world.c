#include "../inc/hello_world.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

	if (strlen(s) < HELLO_WORLD_STRING_LENGTH)
		return false;

	return true;
}

int hello_world(char *s)
{
	if (!is_input_string_valid(s))
		return -1;

	snprintf(s, 13, "hello, world");

	return 0;
}
