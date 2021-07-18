/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>

void test(void)
{
	char s[10] = "hello";

	printf("%.*s\n", 2, s);
}

int main()
{
	test();
	return 0;
}
