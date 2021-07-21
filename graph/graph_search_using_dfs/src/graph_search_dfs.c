/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdlib.h>
#include <stdbool.h>
#include "../inc/graph_search_dfs.h"

struct graph_node {
	size_t val;
	struct graph_node *next;
};

/* graph is a hash table */
static struct graph_node *graph[MAX_VERTICES_IN_GRAPH];
static bool dfs_visit_array[MAX_VERTICES_IN_GRAPH];

int initialize_adjacancy_list_graph(void)
{
	size_t i;

	for (i = 0; i < MAX_VERTICES_IN_GRAPH; i++) {
		graph[i] = malloc(sizeof(struct graph_node));
		if (!graph[i])
			return -1;
		graph[i]->val = i;
		dfs_visit_array[i] = false;
		graph[i]->next = NULL;
	}

	return 0;
}

int destroy_adjacancy_list_graph(void)
{
	size_t i;
	struct graph_node *node;
	struct graph_node *prev;

	for (i = 0; i < MAX_VERTICES_IN_GRAPH; i++) {
		node = graph[i];
		while (node) {
			prev = node;
			node = node->next;
			free(prev);
		}
	}

	return 0;
}

static bool is_vertex_valid(size_t v)
{
	if (v >= MAX_VERTICES_IN_GRAPH)
		return false;

	return true;
}

static bool is_connected(size_t *visited, struct graph_node *node, size_t end)
{
	if (!node)
		return false;

	if (visited[node->val])
		return false;

	visited[node->val] = true;
	if (end == node->val)
		return true;

	while (node) {
		if (!visited[node->val])
			if (is_connected(visited, graph[node->val], end))
				return true;
		node = node->next;
	}

	return false;

}

static bool is_dfs_connected(size_t start, size_t end)
{
	size_t visited[MAX_VERTICES_IN_GRAPH] = {0,};
	struct graph_node *start_node = graph[start];

	return is_connected(visited, start_node, end);

}

static int connect_vertices(size_t v1, size_t v2)
{
	struct graph_node *node;

	if (!is_vertex_valid(v1))
		return -1;

	if (!is_vertex_valid(v2))
		return -1;

	if (is_dfs_connected(v1, v2))
		return -1;

	node = malloc(sizeof(struct graph_node));
	if (!node)
		return -1;

	node->val = v2;
	node->next = graph[v1]->next;
	graph[v1]->next = node;

	return 0;
}

int connect(size_t v1, size_t v2)
{
	if (!is_vertex_valid(v1) || !is_vertex_valid(v2))
		return -1;

	return connect_vertices(v1, v2);
}

static void dfs(struct graph_node *node, size_t *dfs_path)
{
	static size_t i = 0;

	if (!node)
		return;

	if (dfs_visit_array[node->val])
		return;

	dfs_visit_array[node->val] = true;
	dfs_path[i++] = node->val;

	while (node) {
		if (!dfs_visit_array[node->val])
			dfs(graph[node->val], dfs_path);

		node = node->next;
	}
}

void print_graph(void)
{
	size_t i;
	struct graph_node *node;

	for (i = 0; i < MAX_VERTICES_IN_GRAPH; i++) {
		node = graph[i];
		printf("[%zu]-->", i);
		while (node) {
			printf("%zu-->", node->val);
			node = node->next;
		}
		printf("NULL\n");
	}
}

int dfs_search(size_t start_vertex, size_t *dfs_path)
{
	if (!is_vertex_valid(start_vertex))
		return -1;

	if (!dfs_path)
		return -1;

	dfs(graph[start_vertex], dfs_path);

	return 0;
}
