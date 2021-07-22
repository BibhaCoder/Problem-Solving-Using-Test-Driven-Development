/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../inc/integer_to_string.h"

static void reverse(char *s)
{
	char c;
	size_t i, j;

	j = 0;
	i = strlen(s) - 1;

	while (i > j) {
		c = s[i], s[i] = s[j], s[j] = c;
		i--;
		j++;
	}
}

static int8_t get_sign(int64_t n)
{
	if (n < 0)
		return -1;
	else
		return 1;
}

void integer_to_string(int64_t n, char *s)
{
	size_t i = 0;
	int8_t sign = 0;

	sign = get_sign(n);
	n *= sign;

	do {
		s[i++] = '0' +  n % 10;
		n = n / 10;
	} while (n);

	if (sign < 0)
		s[i++] = '-';

	s[i] = 0;

	reverse(s);
}
