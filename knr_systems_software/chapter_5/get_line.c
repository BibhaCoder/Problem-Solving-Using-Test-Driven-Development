/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdlib.h>
#define LINE_MAX_LENGTH (10)

static char *get_line(size_t len)
{
	char c;
	char *s;
	size_t i;

	if (len == 0 || len > LINE_MAX_LENGTH)
		return NULL;

	s = malloc(len + 1);
	if (!s)
		return NULL;

	c = getc(stdin);
	for (i = 0; i < len; i++) {
		if (c == '\n')
			break;
		s[i] = c;
		c = getc(stdin);
	}
	s[i] = '\0';

	return s;
}

static void test_get_line(void)
{
	char *s = get_line(LINE_MAX_LENGTH);

	if (!s) {
		printf("failed to read line");
		return;
	}

	printf("%s: %s\n", __func__, s);
	free(s);
}

int main()
{
	test_get_line();

	return 0;
}
