#include "../inc/expand.h"
#include <stdbool.h>
#include <stdio.h>

static bool is_expand_input_valid(char const *s)
{
	if (!s)
		return false;

	return true;
}

char *expand(char const *s)
{
	if (!is_expand_input_valid(s))
		return NULL;

	return NULL;
}
