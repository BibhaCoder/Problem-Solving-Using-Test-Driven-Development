/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdlib.h>
#include <stdbool.h>
#include "../inc/graph_search_bfs.h"

#define ASSERT(cond) { \
			if (cond) \
				printf("detected a fatal error %s %d\n", __func__, __LINE__); \
		     }\

struct graph_node {
	size_t val;
	struct graph_node *next;
};

static struct graph_node *graph[MAX_VERTICES_IN_GRAPH];
static bool bfs_visit_array[MAX_VERTICES_IN_GRAPH];
static size_t bfs_queue[MAX_VERTICES_IN_GRAPH];
static size_t bfs_queue_front_pointer;
static size_t bfs_queue_back_pointer;


int initialize_adjacancy_list_graph(void)
{
	size_t i;

	for (i = 0; i < MAX_VERTICES_IN_GRAPH; i++) {
		graph[i] = malloc(sizeof(struct graph_node));
		if (!graph[i])
			return -1;
		graph[i]->val = i;
		bfs_visit_array[i] = false;
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

static int enqueue(size_t val)
{
	if (bfs_queue_back_pointer >= MAX_VERTICES_IN_GRAPH) {
		printf("queue is full\n");
		return -1;
	}

	bfs_queue[bfs_queue_back_pointer++] = val;

	return 0;
}

static int dequeue(size_t *val)
{
	if (bfs_queue_front_pointer > bfs_queue_front_pointer) {
		printf("queue is empty\n");
		return -1;
	}

	*val = bfs_queue[bfs_queue_front_pointer++];

	return 0;
}

static bool is_bfs_queue_empty(void)
{
	if (bfs_queue_front_pointer > bfs_queue_back_pointer)
		return true;
	else
		return false;
}

static void traverse_bsf_neighbors(struct graph_node *node,
				   size_t *bfs_path, size_t *index)
{
	while (node) {
		if (!bfs_visit_array[node->val]) {
			bfs_path[(*index)++] = node->val;
			bfs_visit_array[node->val] = true;
			ASSERT(enqueue(node->val));
		}
		node = node->next;
	}
}

static void bfs(struct graph_node *node, size_t *bfs_path)
{
	size_t next = 0;
	size_t i = 0;

	if (!node)
		return;

	bfs_visit_array[node->val] = true;
	bfs_path[i++] = node->val;
	ASSERT(enqueue(node->val));

	while (!is_bfs_queue_empty()) {
		traverse_bsf_neighbors(node, bfs_path, &i);
		ASSERT(dequeue(&next));
		node = graph[next];
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

int bfs_search(size_t start_vertex, size_t *bfs_path)
{
	if (!is_vertex_valid(start_vertex))
		return -1;

	if (!bfs_path)
		return -1;

	bfs(graph[start_vertex], bfs_path);

	return 0;
}
