/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>

enum rbt_parent_branch_color {
	black = 0,
	red,
};

struct rbt_tree_node {
	uint32_t val;
	enum rbt_parent_branch_color color;
	struct rbt_tree_node *left;
	struct rbt_tree_node *right;
};

static bool is_node_red(struct rbt_tree_node *node)
{
	if (!node)
		return false;

	if (node->color == red)
		return true;
	else
		return false;
}

static struct rbt_tree_node *rotate_left(struct rbt_tree_node *node)
{
	struct rbt_tree_node *temp;

	if (!node) {
		printf("invalid null node\n");
		return NULL;
	}

	if (node->right.color != red) {
		printf("invalid right leaning rbt\n");
		return NULL;
	}

	temp = node->right;

	temp->left = node;
	node->right = temp->left;

	temp->color = node->color;
	node->color = red;

	return temp;
}

static struct rbt_tree_node *rotate_right(struct rbt_tree_node *node)
{
	struct rbt_tree_node *temp;

	if (!node) {
		printf("invalid null node\n");
		return NULL;
	}

	if (node->left.color != red) {
		printf("invalid left leaning rbt\n");
		return NULL;
	}

	temp = node->left;

	temp->right = node;
	node->left = temp->right;

	temp->color = node->color;
	node->color = red;

	return temp;
}

static void color_flip(struct rbt_tree_node *node)
{
	if (!node)
		return;

	if (!is_node_red(node->left))
		return;

	if (!is_node_red(node->right))
		return;

	node->color = red;
	node->left.color = black;
	node->right.color = black;
}
