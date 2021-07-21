/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdbool.h>

static void replace_white_spaces(void)
{
	int c;
	bool found_1st_blank = false;

	while ((c = getchar()) != '`') {
		if (c == ' ') {
			if (found_1st_blank) {
				continue;
			} else {
				found_1st_blank = true;
				putchar(c);
			}
		} else {
			found_1st_blank = false;
			putchar(c);
		}
	}

	printf("\n");
}

int main()
{
	replace_white_spaces();

	return 0;
}

