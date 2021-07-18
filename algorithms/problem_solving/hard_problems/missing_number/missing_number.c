/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_SIZE (33)

enum skip_number {
	none,
	odd,
	even
};

static size_t total_no_of_bits(int n)
{
	int base = 1;
	size_t count = 0;

	while (base < n) {
		base <<= 1;
		count++;
	}

	return count;
}

static void str_reverse(char *s)
{
	char c;
	ssize_t i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

static size_t get_no_of_bits(char bit, char const *num[], int n,
			     size_t index, enum skip_number skip)
{
	char const *s;
	size_t len;
	size_t i, no_of_bits = 0;
	char lsb_bit;

	for (i = 1; i <= n; i++) {
		s = num[i];
		len = strlen(s);
		lsb_bit = s[len - 1];
		printf("%s lsb %c skip %d\n", s, lsb_bit, skip);
		if ((skip == odd) && ('1' == lsb_bit)) {
			continue;
		} else if ((skip == even) && ('0' == lsb_bit)) {
			continue;
		} else {
			printf("bit %c %s s[index] %c\n", bit, s, s[len - 1 - i]);
			if (bit == s[len - 1 - index])
				no_of_bits++;
		}
	}

	printf("no of %c bits %zu\n", bit, no_of_bits);

	return no_of_bits;
}

static void construct_missing_number(char *out, size_t i, size_t limit,
				     size_t n, char const *num[],
				     enum skip_number skip)
{
	size_t no_of_0s;
	size_t no_of_1s;

	while (i < limit) {
		no_of_0s = get_no_of_bits('0', num, n, i, skip);
		no_of_1s = get_no_of_bits('1', num, n, i, skip);

		if (no_of_1s < no_of_0s)
			out[i++] = '1';
		else
			out[i++] = '0';
	}

}

static void find_and_print_missing_number(int n, char const *num[])
{
	char out[MAX_NUMBER_SIZE] = {0,};
	enum skip_number skip;
	size_t i = 0, no_of_0s, no_of_1s;
	size_t limit = total_no_of_bits(n);

	printf("%s n %d bit_limit %zu\n", __func__, n, limit);
	no_of_0s = get_no_of_bits('0', num, n, 0, none);
	no_of_1s = get_no_of_bits('1', num, n, 0, none);

	printf("0 bits %zu 1 bits %zu\n", no_of_0s, no_of_1s);
	if (no_of_1s < no_of_0s) {
		out[i++] = '1';
		skip = even;
	} else {
		out[i++] = '0';
		skip = odd;
	}
	construct_missing_number(out, i, limit, n, num, skip);
	str_reverse(out);

	printf("missing no is: %s\n", out);
}

int main(int argc, char const *argv[])
{
	if (argc < 3) {
		printf("invalid input: missing_number <binary no 1> <binary no 2> and so on\n");
		return -1;
	}

	find_and_print_missing_number(argc - 1, argv);

	return 0;
}
