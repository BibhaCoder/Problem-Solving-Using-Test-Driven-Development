/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/string_reverse.h"

#define MAX_INPUT_STRING_SIZE (100)

static void reverse(char *t, size_t len)
{
	char c;
	int left = 0;
	int right = len - 1;

	while (left <= right) {
		c = t[left];
		t[left] = t[right];
		t[right] = c;

		left++;
		right--;
	}
}

char *string_reverse(char const *s)
{
	char *t = NULL;
	size_t len;

	if (NULL == s)
		return NULL;

	len = strlen(s);
	if (0 == len)
		return "";

	if (len >= MAX_INPUT_STRING_SIZE) {
		printf("invalid length %zu\n", len);
		return NULL;
	}

	t = malloc(len);
	if (NULL == t) {
		printf("failed to allocate memory for size %zu\n", len);
		return NULL;
	}

	memcpy(t, s, len);
	reverse(t, len);

	return t;
}
