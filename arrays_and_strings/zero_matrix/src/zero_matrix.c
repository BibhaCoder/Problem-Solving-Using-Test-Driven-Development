/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/zero_matrix.h"
#include <stdbool.h>
#include <stdio.h>

static bool
is_input_matrix_valid(size_t rows, size_t columns, uint8_t (*matrix)[columns])
{
	if (!matrix)
		return false;

	else if (rows > MAX_ROWS)
		return false;
	else if (columns > MAX_COLUMNS)
		return false;
	else
		return true;
}

void print_matrix(size_t rows, size_t columns, uint8_t (*matrix)[columns])
{
	size_t i, j;

	printf("\n");
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			printf("%u ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

static void
create_zero_maps(size_t rows, size_t columns, uint8_t (*matrix)[columns],
		 bool *rows_map, bool *columns_map)
{
	size_t i, j;

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			if (matrix[i][j] == 0) {
				rows_map[i] = true;
				columns_map[j] = true;
			}
		}
	}
}

static void
zero_out_rows(size_t row, size_t columns, uint8_t (*matrix)[columns])
{
	size_t i;

	for (i = 0; i < columns; i++)
		matrix[row][i] = 0;
}

static void
zero_out_columns(size_t column, size_t rows, size_t columns,
		 uint8_t (*matrix)[columns])
{
	size_t i;

	for (i = 0; i < rows; i++)
		matrix[i][column] = 0;
}

static int
zero_out_matrix_by_rows_and_columns(size_t rows,
				    size_t columns,
				    uint8_t (*matrix)[columns])
{
	size_t i;
	bool zero_rows_map[MAX_ROWS] = {false, };
	bool zero_columns_map[MAX_COLUMNS] = {false, };

	create_zero_maps(rows, columns, matrix, zero_rows_map,
			 zero_columns_map);

	print_matrix(rows, columns, matrix);

	for (i = 0; i < rows; i++)
		if (zero_rows_map[i])
			zero_out_rows(i, columns, matrix);

	print_matrix(rows, columns, matrix);

	for (i = 0; i < columns; i++)
		if (zero_columns_map[i])
			zero_out_columns(i, rows, columns, matrix);

	print_matrix(rows, columns, matrix);

	return 0;
}

int zero_matrix(size_t rows, size_t columns, uint8_t (*matrix)[columns])
{
	if (!is_input_matrix_valid(rows, columns, matrix))
		return -1;

	return zero_out_matrix_by_rows_and_columns(rows, columns, matrix);
}
