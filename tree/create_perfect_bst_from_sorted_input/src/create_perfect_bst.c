/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/create_perfect_bst.h"
#include <stdlib.h>
#include <stdbool.h>

#define ASSERT(cond)  { \
			if (!cond) \
				printf("Fatal error %s %d\n", \
					__func__, __LINE__); \
		      } \

struct tree_node {
	int val;
	int count;
	size_t depth;
	struct tree_node *left;
	struct tree_node *right;
};
static struct tree_node *root;
static size_t traversal_index;

static bool is_input_sorted(int const *a, size_t n)
{
	size_t i;

	for (i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			return false;

	return true;
}

static bool is_create_perfect_bst_input_valid(int const *a, size_t num)
{

	if (!a)
		return false;

	if (!num)
		return false;

	if (!is_input_sorted(a, num))
		return false;

	return true;
}

struct tree_node *add_node(struct tree_node *node, int val, size_t depth)
{
	if (!node) {
		node = malloc(sizeof(struct tree_node));
		node->val = val;
		node->left = node->right = NULL;
		node->count = 0;
		node->depth = depth;
	} else if (val == node->val) {
		node->count++;
	} else if (val < node->val) {
		node->left = add_node(node->left, val, ++depth);
	} else {
		node->right = add_node(node->right, val, ++depth);
	}

	return node;
}

static void build_perfect_bst(int const *a, int left, int right)
{
	int mid;

	if (left > right)
		return;

	mid = left + ((right - left) >> 1);

	root = add_node(root, a[mid], 0);

	build_perfect_bst(a, left, mid - 1);
	build_perfect_bst(a, mid + 1, right);
}

int create_perfect_bst(int const *input, size_t num)
{
	if (!is_create_perfect_bst_input_valid(input, num))
		return -1;

	build_perfect_bst(input, 0, num - 1);

	return 0;
}

static void destroy_bst(struct tree_node *root)
{
	if (!root)
		return;

	destroy_bst(root->left);
	free(root);
	destroy_bst(root->right);
}

int destroy_perfect_bst(void)
{
	destroy_bst(root);

	root = NULL;
	traversal_index = 0;

	return 0;
}

static void inorder_traverse(struct tree_node *root, int *out)
{
	if (!root)
		return;

	inorder_traverse(root->left, out);
	out[traversal_index++] = root->val;
	inorder_traverse(root->right, out);
}

static void preorder_traverse_assert_on_depth(struct tree_node *root,
					      size_t level)
{
	if (!root)
		return;

	ASSERT(root->depth == level);
	preorder_traverse_assert_on_depth(root->left, level + 1);
	preorder_traverse_assert_on_depth(root->right, level + 1);
}

int inorder_traverse_bst(int *output)
{
	if (!output)
		return -1;

	inorder_traverse(root, output);

	preorder_traverse_assert_on_depth(root, 0);

	return 0;
}
