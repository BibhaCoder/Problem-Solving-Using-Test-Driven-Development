/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#define MAX_VERTICES_IN_GRAPH (10)

int initialize_adjacancy_list_graph(void);
int destroy_adjacancy_list_graph(void);
int connect(size_t v1, size_t v2);
int dfs_search(size_t start_vertex, size_t *search_array);
void print_graph(void);
