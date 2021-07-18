/*  
 * Copyright (c) 2017 BibhaCoder. All rights reserved.  
 * Licensed under the MIT License. See MIT license for full license information.  
 */

#include "../inc/graph_search_bfs.h"
#include "/Unity/src/unity.h"

static void test_graph_initialization(void)
{
	int status;

	status = initialize_adjacancy_list_graph();

	TEST_ASSERT_EQUAL_INT(0, status);
}

static void test_graph_destroy(void)
{
	int status;

	status = destroy_adjacancy_list_graph();

	TEST_ASSERT_EQUAL_INT(0, status);
}

static void test_connect_invalid_vertices(void)
{
	int status;

	status = connect(-1, 20);
	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_connect_1_and_3_vertices(void)
{
	int status;

	status = connect(1, 3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void test_connect_3_and_4_vertices(void)
{
	int status;

	status = connect(3, 4);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void test_connect_3_and_2_vertices(void)
{
	int status;

	status = connect(3, 2);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void test_dup_connect_1_and_3_vertices(void)
{
	int status;

	status = connect(1, 3);
	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_invalid_bfs_search(void)
{
	int status;
	size_t bfs_found_path[MAX_VERTICES_IN_GRAPH] = {0};

	status = bfs_search(-1, bfs_found_path);
	TEST_ASSERT_EQUAL_INT(-1, status);

	status = bfs_search(MAX_VERTICES_IN_GRAPH + 1, bfs_found_path);
	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_valid_bfs_search(void)
{
	int status;
	size_t bfs_found_path[MAX_VERTICES_IN_GRAPH] = {0};
	size_t const bfs_expected_path[MAX_VERTICES_IN_GRAPH] = {1, 3, 2, 4};

	status = bfs_search(1, bfs_found_path);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_UINT32_ARRAY(bfs_expected_path, bfs_found_path,
				       MAX_VERTICES_IN_GRAPH);

}

static void test_print_graph(void)
{
	print_graph();
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_graph_initialization);

	RUN_TEST(test_connect_invalid_vertices);

	RUN_TEST(test_connect_1_and_3_vertices);
	RUN_TEST(test_connect_3_and_4_vertices);
	RUN_TEST(test_connect_3_and_2_vertices);
	RUN_TEST(test_dup_connect_1_and_3_vertices);

	RUN_TEST(test_invalid_bfs_search);
	RUN_TEST(test_valid_bfs_search);

	RUN_TEST(test_print_graph);

	RUN_TEST(test_graph_destroy);

	UNITY_END();

	return 0;
}
