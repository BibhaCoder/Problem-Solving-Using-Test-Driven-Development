#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define GRAPH_MAX_VERTICES (150000000)

struct graph_vertex {
	struct graph_vertex *next;
	uint32_t degree;
	uint32_t val;
	bool dfs_visited;
	uint32_t path_to;
	bool bfs_visited;
	uint32_t dfs_connected_component_id;
};

struct queue {
	uint32_t val;
	struct queue *next;
	struct queue *prev;
};

struct stack {
	uint32_t root;
	uint32_t val;
	struct stack *next;
};
static struct stack *top;

static struct queue *head;
static struct queue *tail;

static struct graph_vertex *nodes[GRAPH_MAX_VERTICES];

static int initalize_graph(size_t n)
{
	size_t i;
	struct graph_vertex *v;

	for (i = 0; i < n; i++) {
		v = (struct graph_vertex *)malloc(sizeof(struct graph_vertex));
		if (!v)
			return -1;
		v->next = NULL;
		v->degree = 0;
		v->val = i;
		v->dfs_visited = false;
		v->dfs_connected_component_id = -1;
		v->path_to = -1;
		v->bfs_visited = false;
		nodes[i] = v;
	}

	return 0;
}

static void clear_previous_search_path(size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) {
		nodes[i]->path_to = -1;
		nodes[i]->dfs_visited = false;
	}
}

static bool is_adjacent(uint32_t p, uint32_t q)
{
	bool found = false;
	const struct graph_vertex *t;

	if (p >= GRAPH_MAX_VERTICES || q >= GRAPH_MAX_VERTICES) {
		printf("invalid nodes %u %u\n", p ,q);
		return false;
	}

	t = nodes[p];

	while (t) {
		if (t->val == q) {
			found = true;
			break;
		}
		t = t->next;
	}

	return found;
}

static void connect_edge(uint32_t p, uint32_t q)
{
	struct graph_vertex *v;
	struct graph_vertex *prev;
	struct graph_vertex *tail;

	if (p == q)
		return;

	if (is_adjacent(p, q))
		return;

	v = (struct graph_vertex *)malloc(sizeof(struct graph_vertex));
	if (!v)
		return;
	v->val = q;
	v->next = NULL;

	prev = tail = nodes[p];
	while (tail) {
		prev = tail;
		tail = tail->next;
	}

	prev->next = v;
	nodes[p]->degree += 1;
}

static void print_node_params(const struct graph_vertex *v, bool print_degree)
{
	if (!v)
		return;

	if (print_degree)
		printf("[%u : (degree : %u)]-->", v->val, v->degree);
	else
		printf("[%u]-->", v->val);
}

static void print_node(size_t i)
{
	const struct graph_vertex *v;

	v = nodes[i];
	print_node_params(v, true);
	while (v) {
		v = v->next;
		print_node_params(v, false);
	}
	printf("NULL\n");
}

static void print_graph(size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		print_node(i);
}

static void connect_edges_of_the_graph(size_t n)
{
	time_t t;
	size_t i;
	uint32_t p;
	uint32_t q;

	srand((unsigned) time(&t));

	for (i = 0; i < n; i++) {
		p = rand() % n;
		q = rand() % n;
		connect_edge(p, q);
		connect_edge(q, p);
        }
}

static size_t get_max_degree_of_graph(size_t n)
{
	size_t i;
	size_t degree = 0;
	uint32_t vertex = 0;

	for (i = 0; i < n; i++) {
		if (nodes[i]->degree > degree) {
			degree = nodes[i]->degree;
			vertex = i;
		}
	}

	printf("vertex [%u] has max degree %u\n",
		nodes[vertex]->val,
		nodes[vertex]->degree);

	print_node(vertex);

	return degree;
}

static void destroy_graph(size_t n)
{
	size_t i;
	struct graph_vertex *head;
	struct graph_vertex *node;

	for (i = 0; i < n; i++) {
		head = nodes[i];
		while (head) {
			node = head->next;
			free(head);
			head = node;
		}
	}
}

static void test_graph(size_t n)
{
	if (initalize_graph(n))
		return;

	connect_edges_of_the_graph(n);

	print_graph(n);

	get_max_degree_of_graph(n);
}

static void push(uint32_t root, uint32_t val)
{
	struct stack *s;

	s = malloc(sizeof(*s));
	if (!s) {
		printf("failed to allocate memory for stack push operation\n");
		return;
	}

	s->root = root;
	s->val = val;

	s->next = top;
	top = s;
}

static void pop(struct stack *s)
{
	struct stack *t;

	if (!top) {
		printf("stack is empty\n");
		return;
	}

	t = top;
	*s = *t;

	top = top->next;
	free(t);
}

static bool is_stack_empty(void)
{
	if (!top)
		return true;
	else
		return false;
}

static void dfs_visit_adjacent_list(uint32_t root, struct graph_vertex *v_node)
{
	while (v_node) {
		if (!(nodes[v_node->val]->dfs_visited))
			push(root, v_node->val);
		v_node = v_node->next;
	}
}

static void dfs(struct graph_vertex *root, size_t dfs_component_id)
{
	struct stack s;
	struct graph_vertex *v_node;

	push(root->val, root->val);

	while (!is_stack_empty()) {
		pop(&s);
		v_node = nodes[s.val];
		v_node->dfs_visited = true;
		v_node->dfs_connected_component_id = dfs_component_id;
		v_node->path_to = s.root;
		dfs_visit_adjacent_list(v_node->val, v_node->next);
	}
}

static void dfs_recursive(struct graph_vertex *w)
{
	struct graph_vertex *v;

	w->dfs_visited = true;

	v = w->next;
	if (!v)
		return;
	v = nodes[v->val];

	do {
		if (!v->dfs_visited) {
			dfs_recursive(v);
			v->path_to = w->val;
		}
		v = v->next;
	} while (v);
}

static int enqueue(uint32_t val)
{
	struct queue *q;

	q = malloc(sizeof(*q));
	if (!q)
		return -1;

	if (!tail) {
		q->val = val;
		q->prev = NULL;
		q->next = NULL;
		tail = head = q;
		return 0;
	}

	q->val = val;
	q->next = NULL;
	tail->next = q;
	q->prev = tail;
	tail = q;

	return 0;
}

static uint32_t dequeue(void)
{
	uint32_t val;
	struct queue *q;

	if (!head) {
		printf("queue is empty\n");
		return GRAPH_MAX_VERTICES;
	}

	q = head;
	val = q->val;
	head = head->next;
	if (!head)
		tail = head;
	else
		head->prev = NULL;

	free(q);

	return val;
}

static bool is_qeueu_empty(void)
{
	if (!head)
		return true;
	else
		return false;
}

static void bfs_visit_adjacent_list(uint32_t w, struct graph_vertex *v_node)
{
	while (v_node) {
		if (!(nodes[v_node->val]->bfs_visited)) {
			nodes[v_node->val]->bfs_visited = true;
			enqueue(v_node->val);
			nodes[v_node->val]->path_to = w;
		}
		v_node = v_node->next;
	}
}

static void bfs(struct graph_vertex *w_node)
{
	uint32_t w;

	w_node->bfs_visited = true;
	enqueue(w_node->val);

	while (!is_qeueu_empty()) {
		w = dequeue();
		bfs_visit_adjacent_list(w, nodes[w]);
	}
}

static void find_path_between_nodes(const struct graph_vertex *s,
				    const struct graph_vertex *e)
{
	int path;
	uint32_t path_length = 0;
	const struct graph_vertex *node;

	printf("[%u]->", e->val);
	path = e->path_to;
	while (-1 != path) {
		printf("[%u]->", path);
		path_length++;
		if (path == s->val) {
			printf("found path to %u with path length %u\n",
				s->val, path_length);
			return;
		}
		node = nodes[path]; 
		path = node->path_to;
	}

	printf("there is no path between %u and %u\n", s->val, e->val);
}

static void perform_dfs_search_using_stack(size_t n, uint32_t s, uint32_t e)
{
	clock_t t;
	double time_taken;

	t = clock();
	dfs(nodes[s], -1);
	printf("DFS search:\n");
	find_path_between_nodes(nodes[s], nodes[e]);
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("DFS search took %f seconds\n", time_taken);
}

static void perform_bfs_search_using_queue(size_t n, uint32_t s, uint32_t e)
{
	clock_t t;
	double time_taken;

	t = clock();
	bfs(nodes[s]);
	printf("DFS search:\n");
	find_path_between_nodes(nodes[s], nodes[e]);
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("BFS search took %f seconds\n", time_taken);
}

static void perform_graph_search(size_t n, uint32_t s, uint32_t e)
{
	perform_dfs_search_using_stack(n, s, e);

	clear_previous_search_path(n);

	perform_bfs_search_using_queue(n, s, e);
}

static bool is_connected(uint32_t p, uint32_t q)
{
	if (nodes[p]->dfs_connected_component_id ==
		nodes[q]->dfs_connected_component_id)
		return true;
	else
		return false;
}

static void print_requested_component_vertices(size_t n)
{
	size_t i;
	uint32_t id;

	printf("Enter requested dfs connected componenet id:");
	scanf("%u", &id);

	for (i = 0; i < n; i++)
		if (id == nodes[i]->dfs_connected_component_id)
			printf("[%u]->", nodes[i]->val);

	printf("\n");
}

static void find_connected_components(size_t n, uint32_t s, uint32_t e)
{
	size_t i;
	size_t count = 0;

	for (i = 0; i < n; i++) {
		if (!nodes[i]->dfs_visited) {
			dfs(nodes[i], count);
			count++;
		}
	}

	printf("found total %zu dfs connected components in a graph with %zu vertices\n",
		count, n);

	if (is_connected(s, e))
		printf("%u and %u are connected are in connected component id %u\n",
			s, e, nodes[s]->dfs_connected_component_id);
	else
		printf("%u and %u are not connected\n", s, e);

	print_requested_component_vertices(n);
}

int main(int argc, char *argv[])
{
	size_t n;
	uint32_t s, e;

	if (argc < 2) {
		printf("invalid input\n");
		return -1;
	}

	n = atoi(argv[1]);
	s = atoi(argv[2]);
	e = atoi(argv[3]);

	if ((n >= GRAPH_MAX_VERTICES) || (s >= n) || (e >= n)) {
		printf("invalid input\n");
		return -1;
	}

	test_graph(n);
	perform_graph_search(n, s, e);
	find_connected_components(n, s, e);
	destroy_graph(n);

	return 0;
}
