#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/string_detab.h"

#define MAX_INPUT_STRING_SIZE (100)
#define NO_OF_SPACES_IN_TAB (8)

static void replace_tabs_by_space(char *t, size_t pos)
{
	size_t index_in_t;

	for (index_in_t = 0; index_in_t < NO_OF_SPACES_IN_TAB; index_in_t++)
		t[pos + index_in_t] = ' ';
}

static void detab(char const *s, char *t)
{
	size_t index_in_s = 0;
	size_t index_in_t = 0;

	for ( ; s[index_in_s] != '\0'; index_in_s++) {
		if ('\t' == s[index_in_s]) {
			replace_tabs_by_space(t, index_in_t);
			index_in_t += NO_OF_SPACES_IN_TAB;
		} else {
			t[index_in_t++] = s[index_in_s];
		}
	}
}

static size_t get_no_of_tabs(char const *s)
{
	size_t i;
	size_t no_of_tabs = 0;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == '\t')
			no_of_tabs++;

	return no_of_tabs;
}

char *string_detab(char const *s)
{
	char *t;
	size_t len;
	size_t no_of_tabs;
	size_t output_string_length;

	if (NULL == s)
		return NULL;

	len = strlen(s);
	if (0 == len)
		return "";

	if (len >= MAX_INPUT_STRING_SIZE) {
		printf("invalid length %zu\n", len);
		return NULL;
	}

	no_of_tabs = get_no_of_tabs(s);
	/* +1 is for null terminator at the end */
	output_string_length =
		(len - no_of_tabs) + (no_of_tabs * NO_OF_SPACES_IN_TAB) + 1;
	t = malloc(output_string_length);
	if (NULL == t) {
		printf("failed to allocate memory for size %zu\n", len);
		return NULL;
	}

	memset(t, 0, output_string_length);
	detab(s, t);

	return t;
}
