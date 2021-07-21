/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>

static void echo_with_wrong_char_type(void)
{
	char c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}

int main()
{
	echo_with_wrong_char_type();

	return 0;
}
