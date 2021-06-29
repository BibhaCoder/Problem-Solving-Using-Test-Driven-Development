#include <stdio.h>

#define MAX_VERTICES_IN_GRAPH (10)

int initialize_adjacancy_list_graph(void);
int destroy_adjacancy_list_graph(void);
int connect(int v1, int v2, int edge_weight);
int initialize_dijkstra_shortest_path(int start_vertex, int end_vertex);
int *dijkstra_shortest_path(int start_vertex, int end_vertex);
int *dijkstra_get_previous_visisted_vertices(int start_vertex, int end_vertex);
void print_graph(void);
