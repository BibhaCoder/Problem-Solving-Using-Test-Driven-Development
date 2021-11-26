/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>

static void print_eof(void)
{
	printf("%s %d EOF integer value is %d and char value is %c\n",
		__func__, __LINE__, EOF, EOF);
}

int main()
{
	print_eof();

	return 0;
}

