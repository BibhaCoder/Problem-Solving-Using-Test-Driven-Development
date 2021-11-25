/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/image_flip.h"
#include <stdbool.h>

static bool is_input_valid(size_t rows, size_t columns, uint8_t (*image)[columns])
{
	if (!image)
		return false;

	if (!rows)
		return false;

	if (!columns)
		return false;

	/* odd number of columns */
	if (columns & 0x1)
		return false;

	return true;
}

static void swap(size_t columns, size_t row, uint8_t (*image)[columns], size_t p, size_t q)
{
	uint8_t temp = image[row][p];

	image[row][p] = image[row][q];
	image[row][q] = temp;
}

static int __image_flip(size_t rows, size_t columns, uint8_t (*image)[columns])
{
	size_t i, j;
	size_t half_column = columns >> 1;

	for (i = 0; i < rows; i++)
		for (j = 0; j < half_column; j++)
			swap(columns, i, image, j, (j + half_column));

	return 0;
}

int image_flip(size_t rows, size_t columns, uint8_t (*image)[columns])
{
	if (!is_input_valid(rows, columns, image))
		return -1;

	return __image_flip(rows, columns, image);
}
