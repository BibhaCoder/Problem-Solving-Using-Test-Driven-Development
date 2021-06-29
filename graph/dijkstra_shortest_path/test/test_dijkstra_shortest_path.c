#include "../inc/dijkstra_shortest_path.h"
#include "/Unity/src/unity.h"

#define ARRAY_NUM_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))

static void test_graph_destroy(void)
{
	int status;

	status = destroy_adjacancy_list_graph();

	TEST_ASSERT_EQUAL_INT(0, status);
}

static void test_connect_invalid_vertices(void)
{
	int status;

	status = connect(-1, 20, 0);
	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_dijkstra_shortest_path_0(void)
{
	int start_vertex = 1;
	int end_vertex = 5;
	int *out;
	int const expected_shortest_paths[] = {0, 3, 7, 1, 2};
	int const expected_previous_visted_vertices[] = {0, 4, 5, 1, 4};


	TEST_ASSERT_EQUAL_INT(0, initialize_adjacancy_list_graph());
	RUN_TEST(test_connect_invalid_vertices);

	TEST_ASSERT_EQUAL_INT(0, connect(1, 2, 6));
	TEST_ASSERT_EQUAL_INT(0, connect(1, 4, 1));

	TEST_ASSERT_EQUAL_INT(0, connect(2, 3, 5));
	TEST_ASSERT_EQUAL_INT(0, connect(2, 4, 2));
	TEST_ASSERT_EQUAL_INT(0, connect(2, 5, 2));
	TEST_ASSERT_EQUAL_INT(0, connect(2, 1, 6));
	TEST_ASSERT_EQUAL_INT(0, connect(3, 2, 5));

	TEST_ASSERT_EQUAL_INT(0, connect(3, 5, 5));

	TEST_ASSERT_EQUAL_INT(0, connect(4, 1, 1));
	TEST_ASSERT_EQUAL_INT(0, connect(4, 2, 2));
	TEST_ASSERT_EQUAL_INT(0, connect(4, 5, 1));

	TEST_ASSERT_EQUAL_INT(0, connect(5, 2, 2));
	TEST_ASSERT_EQUAL_INT(0, connect(5, 3, 5));
	TEST_ASSERT_EQUAL_INT(0, connect(5, 4, 1));

	TEST_ASSERT_EQUAL_INT(0, initialize_dijkstra_shortest_path(start_vertex, end_vertex));
	TEST_ASSERT_EQUAL_INT(-1, initialize_dijkstra_shortest_path(-1, 11));
	TEST_ASSERT_EQUAL_INT(-1, initialize_dijkstra_shortest_path(10, -1));

	out = dijkstra_shortest_path(start_vertex, end_vertex);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_shortest_paths, out,
				    ARRAY_NUM_ELEMENTS(expected_shortest_paths));
	out = dijkstra_get_previous_visisted_vertices(start_vertex, end_vertex);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_previous_visted_vertices, out,
				    ARRAY_NUM_ELEMENTS(expected_previous_visted_vertices));
	print_graph();
	RUN_TEST(test_graph_destroy);
}

static void test_dijkstra_shortest_path_1(void)
{
	int start_vertex = 1;
	int end_vertex = 5;
	int *out;
	int const expected_shortest_paths[] = {0, 4, 7, 8, 15};
	int const expected_previous_visted_vertices[] = {0, 1, 2, 1, 4};

	TEST_ASSERT_EQUAL_INT(0, initialize_adjacancy_list_graph());
	RUN_TEST(test_connect_invalid_vertices);

	TEST_ASSERT_EQUAL_INT(0, connect(1, 2, 4));
	TEST_ASSERT_EQUAL_INT(0, connect(1, 4, 8));

	TEST_ASSERT_EQUAL_INT(0, connect(2, 1, 4));
	TEST_ASSERT_EQUAL_INT(0, connect(2, 3, 3));

	TEST_ASSERT_EQUAL_INT(0, connect(3, 2, 3));
	TEST_ASSERT_EQUAL_INT(0, connect(3, 4, 4));

	TEST_ASSERT_EQUAL_INT(0, connect(4, 1, 8));
	TEST_ASSERT_EQUAL_INT(0, connect(4, 3, 4));

	TEST_ASSERT_EQUAL_INT(0, connect(4, 5, 7));

	TEST_ASSERT_EQUAL_INT(0, connect(5, 4, 7));

	TEST_ASSERT_EQUAL_INT(0, initialize_dijkstra_shortest_path(start_vertex, end_vertex));
	TEST_ASSERT_EQUAL_INT(-1, initialize_dijkstra_shortest_path(-1, 20));
	TEST_ASSERT_EQUAL_INT(-1, initialize_dijkstra_shortest_path(20, -1));

	out = dijkstra_shortest_path(start_vertex, end_vertex);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_shortest_paths, out,
				    ARRAY_NUM_ELEMENTS(expected_shortest_paths));
	out = dijkstra_get_previous_visisted_vertices(start_vertex, end_vertex);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_previous_visted_vertices, out,
				    ARRAY_NUM_ELEMENTS(expected_previous_visted_vertices));
	print_graph();
	RUN_TEST(test_graph_destroy);
}

static void test_dijkstra_shortest_path_2(void)
{
	int start_vertex = 1;
	int end_vertex = 5;
	int *out;
	int const expected_shortest_paths[] = {0, 100, 200, 160, 280};
	int const expected_previous_visted_vertices[] = {0, 1, 4, 1, 3};

	TEST_ASSERT_EQUAL_INT(0, initialize_adjacancy_list_graph());

	TEST_ASSERT_EQUAL_INT(0, connect(1, 2, 100));
	TEST_ASSERT_EQUAL_INT(0, connect(1, 4, 160));

	TEST_ASSERT_EQUAL_INT(0, connect(2, 3, 120));
	TEST_ASSERT_EQUAL_INT(0, connect(2, 4, 180));

	TEST_ASSERT_EQUAL_INT(0, connect(3, 5, 80));

	TEST_ASSERT_EQUAL_INT(0, connect(4, 5, 140));
	TEST_ASSERT_EQUAL_INT(0, connect(4, 3, 40));

	TEST_ASSERT_EQUAL_INT(0, connect(5, 2, 100));

	TEST_ASSERT_EQUAL_INT(0, initialize_dijkstra_shortest_path(start_vertex, end_vertex));
	TEST_ASSERT_EQUAL_INT(-1, initialize_dijkstra_shortest_path(-1, 20));
	TEST_ASSERT_EQUAL_INT(-1, initialize_dijkstra_shortest_path(20, -1));

	out = dijkstra_shortest_path(start_vertex, end_vertex);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_shortest_paths, out,
				    ARRAY_NUM_ELEMENTS(expected_shortest_paths));
	out = dijkstra_get_previous_visisted_vertices(start_vertex, end_vertex);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected_previous_visted_vertices, out,
				    ARRAY_NUM_ELEMENTS(expected_previous_visted_vertices));
	print_graph();
	RUN_TEST(test_graph_destroy);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_dijkstra_shortest_path_0);
	RUN_TEST(test_dijkstra_shortest_path_1);
	RUN_TEST(test_dijkstra_shortest_path_2);

	UNITY_END();

	return 0;
}
