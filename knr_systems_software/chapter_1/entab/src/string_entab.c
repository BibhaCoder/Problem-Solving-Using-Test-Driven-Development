#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/string_entab.h"

#define MAX_INPUT_STRING_SIZE (100)
#define NO_OF_SPACES_IN_TAB (8)

static void insert_blanks(char *t, size_t *pos, size_t no_of_blanks)
{
	size_t i = 0;

	while (i < no_of_blanks) {
		t[*pos] = ' ';
		(*pos)++;
		i++;
	}
}

static void insert_tabs(char *t, size_t *pos, size_t no_of_tabs)
{
	size_t i = 0;

	while (i < no_of_tabs) {
		t[*pos] = '\t';
		(*pos)++;
		i++;
	}
}

static size_t get_no_of_consecutive_blanks(char const *s, size_t *index_in_s)
{
	size_t no_of_consecutive_blanks = 0;

	while (s[*index_in_s]) {
		if (' '  != s[*index_in_s])
			break;

		no_of_consecutive_blanks++;
		(*index_in_s)++;
	}

	return no_of_consecutive_blanks;
}

static void replace_blanks_by_tabs(char *t, char const *s,
				   size_t *index_in_s, size_t *index_in_t)
{
	size_t no_of_consecutive_tabs = 0;
	size_t no_of_remaining_blanks = 0;
	size_t no_of_consecutive_blanks = 0;

	no_of_consecutive_blanks = get_no_of_consecutive_blanks(s, index_in_s);
	no_of_consecutive_tabs = no_of_consecutive_blanks / NO_OF_SPACES_IN_TAB;
	no_of_remaining_blanks = no_of_consecutive_blanks % NO_OF_SPACES_IN_TAB;

	if (no_of_consecutive_blanks < NO_OF_SPACES_IN_TAB) {
		insert_blanks(t, index_in_t, no_of_consecutive_blanks);
		return;
	}

	insert_tabs(t, index_in_t, no_of_consecutive_tabs);
	insert_blanks(t, index_in_t, no_of_remaining_blanks);
}

static void entab(char *t, char const *s, size_t len)
{
	size_t index_in_s = 0;
	size_t index_in_t = 0;

	while (s[index_in_s]) {
		if (' ' == s[index_in_s])
			replace_blanks_by_tabs(t, s, &index_in_s, &index_in_t);
		else
			t[index_in_t++] = s[index_in_s++];
	}
}

static bool is_string_valid(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_STRING_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

char *string_entab(char const *s)
{
	char *t;
	size_t input_len;

	if (NULL == s)
		return NULL;

	if (!is_string_valid(s)) {
		printf("invalid string, no null terminator\n");
		return NULL;
	}

	input_len = strlen(s);
	if (0 == input_len)
		return "";

	t = malloc(input_len);
	if (!t) {
		printf("failed to allocate memory for length %zu \n",
		        input_len);
		return NULL;
	}

	entab(t, s, input_len);

	return t;
}
