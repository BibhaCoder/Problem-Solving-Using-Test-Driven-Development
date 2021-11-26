/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>

#define MAX_LINE_SIZE (100)

static void get_line(char *line, size_t limit)
{
	int c;
	size_t i;

	c = getchar();
	for (i = 0; i < (limit - 1) && (c != EOF) && (c != '\n'); i++) {
		line[i] = c;
		c =  getchar();
	}

	if ('\n' == c) {
		line[i] = c;
		i++;
	}

	line[i] = '\0';
}

int main()
{
	char line[MAX_LINE_SIZE];

	get_line(line, MAX_LINE_SIZE);

	printf("input line is -> %s\n", line);

	return 0;
}
