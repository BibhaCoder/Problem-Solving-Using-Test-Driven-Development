/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <sys/types.h>

#define NUM_MAX_PIXELS_IN_ROW (80)
#define NUM_MAX_BYTES_IN_ROW (NUM_MAX_PIXELS_IN_ROW/CHAR_BIT)

int horizontal_image_flip(uint8_t *image, ssize_t size_in_bytes);
