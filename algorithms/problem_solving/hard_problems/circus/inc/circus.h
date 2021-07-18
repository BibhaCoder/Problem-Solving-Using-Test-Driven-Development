/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#define MAX_PEOPLE (10)

struct person {
	uint16_t height;
	uint16_t weight;
};

int find_total_possible_human_towers(struct person *p, size_t n);
void  print_people(struct person *p, size_t n);
