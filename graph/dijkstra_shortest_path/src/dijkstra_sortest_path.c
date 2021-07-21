/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../inc/dijkstra_shortest_path.h"
#include "../inc/min_heap.h"

struct graph_node {
	bool visited;
	int val;
	int edge_weight;
	struct graph_node *next;
};

static struct graph_node *graph[MAX_VERTICES_IN_GRAPH];
static int dijkstra_shortest_path_array[MAX_VERTICES_IN_GRAPH];
static int dijkstra_previous_vertex_array[MAX_VERTICES_IN_GRAPH];

int initialize_adjacancy_list_graph(void)
{
	int i;

	for (i = 0; i < MAX_VERTICES_IN_GRAPH; i++) {
		graph[i] = malloc(sizeof(struct graph_node));
		if (!graph[i])
			return -1;
		graph[i]->val = i;
		graph[i]->visited = 0;
		graph[i]->edge_weight = 0;
		graph[i]->next = NULL;
	}

	return 0;
}

int destroy_adjacancy_list_graph(void)
{
	int i;
	struct graph_node *node;
	struct graph_node *prev;

	for (i = 0; i < MAX_VERTICES_IN_GRAPH; i++) {
		node = graph[i];
		while (node) {
			prev = node;
			node = node->next;
			free(prev);
		}
		graph[i] = NULL;
	}

	reset_min_heap();

	return 0;
}

static bool is_vertex_valid(int v)
{
	if (v >= MAX_VERTICES_IN_GRAPH)
		return false;
	else if (v < 0)
		return false;
	else
		return true;
}

static int connect_vertices(int v1, int v2, int edge_weight)
{
	struct graph_node *node;

	if (!is_vertex_valid(v1))
		return -1;

	if (!is_vertex_valid(v2))
		return -1;

	node = malloc(sizeof(struct graph_node));
	if (!node)
		return -1;

	node->val = v2;
	node->edge_weight = edge_weight;
	node->next = graph[v1]->next;
	graph[v1]->next = node;

	return 0;
}

int connect(int v1, int v2, int edge_weight)
{
	if (!is_vertex_valid(v1) || !is_vertex_valid(v2))
		return -1;

	return connect_vertices(v1, v2, edge_weight);
}

static void print_vertex_with_weight(struct graph_node *node)
{
	printf("[%d](edge_weight: %d)-->", node->val, node->edge_weight);
}

void print_graph(void)
{
	int i;
	struct graph_node *node;

	for (i = 0; i < MAX_VERTICES_IN_GRAPH; i++) {
		node = graph[i];
		printf("[%d]-->", node->val);
		while (node) {
			print_vertex_with_weight(node);
			node = node->next;
		}
		printf("NULL\n");
	}
}

int initialize_dijkstra_shortest_path(int start_vertex, int end_vertex)
{
	int i;

	if (!is_vertex_valid(start_vertex))
		return -1;

	if (!is_vertex_valid(end_vertex))
		return -1;

	dijkstra_shortest_path_array[start_vertex] = 0;
	for (i = start_vertex + 1; i <= end_vertex; i++)
		dijkstra_shortest_path_array[i] = INT_MAX;

	insert_in_min_heap(start_vertex, 0);
	for (i = start_vertex + 1; i <= MAX_VERTICES_IN_GRAPH; i++)
		insert_in_min_heap(i, INT_MAX);

	return 0;
}

/**
 * this is poor design:
 * runtime: O(V ^ 2)
 */
static int get_shortest_unvisited_vertex(int start, int end)
{
	int i;
	int shortest = INT_MAX;
	int shortest_index = INT_MAX;

	for (i = start; i <= end; i++) {
		if (graph[i]->visited)
			continue;
		if (shortest > dijkstra_shortest_path_array[i]) {
			shortest = dijkstra_shortest_path_array[i]; 
			shortest_index = i;
		}
	}

	if (INT_MAX != shortest_index)
		return shortest_index;
	else
		return 0;
}

/**
 * best optimial design:
 * use min heap to get shortest distance vertex
 * runtime: O(ElogV)
 *
 * this is an example of greedy algorithm
 */
static int get_shortest_unvisited_vertex_using_min_heap(int start, int end)
{
	struct min_heap item;

	if (!is_vertex_valid(start))
		return 0;

	if (!is_vertex_valid(end))
		return 0;

	if (get_min(&item))
		return 0;

	if (item.index >= MAX_VERTICES_IN_GRAPH)
		return 0;

	return item.index;
}

static void visit_neighbors(struct graph_node *node)
{
	int index;
	int weight;
	int current_weight = dijkstra_shortest_path_array[node->val];
	int previous_vertex = node->val;

	if (node->visited)
		return;

	printf("visit %d\n", node->val);
	node = node->next;
	for ( ; NULL != node; node = node->next) {
		index = node->val;
		if (graph[index]->visited)
			continue;
		weight = current_weight + node->edge_weight;
		if (weight < dijkstra_shortest_path_array[index]) {
			dijkstra_shortest_path_array[index] = weight;
			dijkstra_previous_vertex_array[index] = previous_vertex;
			update_min_heap(index, weight);
			printf("min_heap after update weight:\n");
			print_min_heap();
		}
	}
}

static void __dijkstra_shortest_path(int start, int end)
{
	int item;

	printf("min_heap before dijkstar greed search start:\n");
	print_min_heap();
	while ((item = get_shortest_unvisited_vertex_using_min_heap(start, end))) {
		visit_neighbors(graph[item]);
		graph[item]->visited = true;
		delete_min();
		printf("min_heap after delete min:\n");
		print_min_heap();
	}
}

int *dijkstra_shortest_path(int start, int end)
{
	if (!is_vertex_valid(start))
		return NULL;

	if (!is_vertex_valid(end))
		return NULL;

	__dijkstra_shortest_path(start, end);

	return &dijkstra_shortest_path_array[start];
}

int *dijkstra_get_previous_visisted_vertices(int start, int end)
{
	if (!is_vertex_valid(start))
		return NULL;

	if (!is_vertex_valid(end))
		return NULL;

	return &dijkstra_previous_vertex_array[start];
}
