/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>

static void echo(void)
{
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);
}

int main()
{
	echo();

	return 0;
}
