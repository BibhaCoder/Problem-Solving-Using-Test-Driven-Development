/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
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
