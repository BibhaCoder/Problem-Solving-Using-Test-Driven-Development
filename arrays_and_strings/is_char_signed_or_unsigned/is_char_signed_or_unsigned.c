/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>

int main()
{
	char c = 255;

	 /* 0x01111111 : 127 is largest posible positive signed 8 bit integer */
	if (c > 127)
		printf("char is unsigned\n");
	else
		printf("char is signed\n");

	return 0;
}
