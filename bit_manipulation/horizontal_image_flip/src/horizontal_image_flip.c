/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/horizontal_image_flip.h"
#include <stdbool.h>
#include <limits.h>

static bool is_input_valid(uint8_t *image, ssize_t size)
{
	if (!image)
		return false;
	else if (size < 0)
		return false;
	else
		return true;
}

static void swap(uint8_t *image, ssize_t i, ssize_t j)
{
	uint8_t temp;

	temp =  image[i];
	image[i] = image[j];
	image[j] = temp;
}

static void flip_row(uint8_t *image, ssize_t size_in_bytes)
{
	ssize_t i;
	ssize_t middle_of_row = size_in_bytes >> 1;

	for (i = 0; i < middle_of_row; i++)
		swap(image, i, middle_of_row + i);
}

static int __horizontal_image_flip(uint8_t *image, ssize_t size_in_bytes)
{
	ssize_t i;
	ssize_t size_in_bits = size_in_bytes * CHAR_BIT;
	ssize_t num_rows = size_in_bytes / NUM_MAX_BYTES_IN_ROW;

	if (size_in_bits <= NUM_MAX_PIXELS_IN_ROW) {
		flip_row(image, size_in_bytes);
		return 0;
	}

	for (i = 0; i < num_rows; i++)
		flip_row(&image[i * NUM_MAX_BYTES_IN_ROW], NUM_MAX_BYTES_IN_ROW);

	return 0;
}

int horizontal_image_flip(uint8_t *image, ssize_t size_in_bytes)
{
	if (!is_input_valid(image, size_in_bytes))
		return -1;

	return __horizontal_image_flip(image, size_in_bytes);
}
