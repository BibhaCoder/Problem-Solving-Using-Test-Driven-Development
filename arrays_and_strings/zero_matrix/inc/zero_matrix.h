/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stddef.h>
#include <stdint.h>

#define MAX_ROWS (10)
#define MAX_COLUMNS (10)

int zero_matrix(size_t rows, size_t columns, uint8_t (*matrix)[columns]);
void print_matrix(size_t rows, size_t columns, uint8_t (*matrix)[columns]);
