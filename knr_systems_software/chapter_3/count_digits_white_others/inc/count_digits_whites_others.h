/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#define MAX_INPUT_LINE_SIZE (100)

struct digits_whites_others {
	size_t digits;
	size_t whites;
	size_t others;
};

ssize_t count_digits_whites_others(char const *s,
				   struct digits_whites_others *t);
