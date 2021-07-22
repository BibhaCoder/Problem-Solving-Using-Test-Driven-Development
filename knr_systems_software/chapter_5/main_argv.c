/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>

static void print_input_argv(int argc, char const *argv[])
{
	size_t i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc) ? " ": "");

	printf("\n");
}

int main(int argc, char const *argv[])
{
	print_input_argv(argc, argv);

	return 0;
}

