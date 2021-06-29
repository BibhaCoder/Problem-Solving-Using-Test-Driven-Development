#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE (100)

enum direction {
	init,
	east,
	south,
	west,
	north,
	max
};

static int create_langtons_ant_matrix(ssize_t r, ssize_t c,
			       enum direction d, size_t steps);

static bool a[MAX_INPUT_SIZE][MAX_INPUT_SIZE];

static void right_rotate(ssize_t r, ssize_t c, enum direction d, size_t steps)
{
	switch(d) {
	case east:
		create_langtons_ant_matrix(r + 1, c, south, steps);
		break;
	case west:
		create_langtons_ant_matrix(r - 1, c, north, steps);
		break;
	case north:
		create_langtons_ant_matrix(r, c + 1, east, steps);
		break;
	case south:
		create_langtons_ant_matrix(r, c - 1, west, steps);
		break;
	default:
		printf("fatal direction\n");
		break;
	}
}

static void left_rotate(ssize_t r, ssize_t c, enum direction d, size_t steps)
{
	switch(d) {
	case east:
		create_langtons_ant_matrix(r - 1, c, north, steps);
		break;
	case west:
		create_langtons_ant_matrix(r + 1, c, south, steps);
		break;
	case north:
		create_langtons_ant_matrix(r, c - 1, west, steps);
		break;
	case south:
		create_langtons_ant_matrix(r, c + 1, east, steps);
		break;
	default:
		printf("fatal direction\n");
		break;
	}
}

static int create_langtons_ant_matrix(ssize_t r, ssize_t c,
				       enum direction d, size_t steps)
{
	static size_t count = 0;

	if (r < 0 || c < 0 || r > MAX_INPUT_SIZE || c > MAX_INPUT_SIZE) {
		printf("invalid r = %zd c = %zd current steps %zd\n", r, c, count);
		return -1;
	}

	if (count++ >= steps) {
		printf("valid r = %zd c = %zd steps %zd\n", r, c, steps);
		return 0;
	}

	if (false == a[r][c]) {
		a[r][c] = true;
		right_rotate(r, c, d, steps);
	} else {
		a[r][c] = false;
		left_rotate(r, c, d, steps);
	}

	return 0;
}

static void print_langtons_ant_matrix(void)
{
	size_t i, j;

	for (i = 0; i < MAX_INPUT_SIZE; i++) {
		for (j = 0; j < MAX_INPUT_SIZE; j++) {
			printf("%c", (a[i][j] == true ? 'X' : ' '));
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	size_t k = 50;

	if (argc < 2) {
		printf("invalid format: a.out <no of steps>");
		return -1;
	}

	create_langtons_ant_matrix(k, k, east, atoi(argv[1]));

	print_langtons_ant_matrix();

	return 0;
}
