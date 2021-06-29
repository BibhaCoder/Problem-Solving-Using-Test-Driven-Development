#include <stdio.h>
#define MAX_VERTICES_IN_GRAPH (10)

int initialize_adjacancy_list_graph(void);
int destroy_adjacancy_list_graph(void);
int connect(size_t v1, size_t v2);
int bfs_search(size_t start_vertex, size_t *search_array);
void print_graph(void);
