#include "../inc/is_bst.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct bst *build_correct_bst(struct bst *root, int val)
{
	if (!root) {
		root = malloc(sizeof(struct bst));
		root->left = root->right = NULL;
		root->val = val;
	} else if (root->val == val) {
		root->count++;
	} else if (val < root->val) {
		root->left = build_correct_bst(root->left, val);
	} else {
		root->right = build_correct_bst(root->right, val);
	}

	return root;
}

struct bst *build_incorrect_bst(struct bst *root, int val)
{
	if (!root) {
		root = malloc(sizeof(struct bst));
		root->left = root->right = NULL;
		root->val = val;
	} else if (root->val == val) {
		root->count++;
	} else if (val > root->val) {
		root->left = build_correct_bst(root->left, val);
	} else {
		root->right = build_correct_bst(root->right, val);
	}

	return root;
}

/**
 * design 1: create sorted array using inorder traversal and make sure array
 * is sorted inorder for tree to be a binary search tree
 * runtime: O(N)
 * memory: O(N)
 */
void inorder_traverse(struct bst *root)
{
	if (!root)
		return;

	inorder_traverse(root->left);
	printf("[%d]-->", root->val);
	inorder_traverse(root->right);
}

/**
 * design 2: pass min and max at every iteration
 * best possible solution
 * runtime: O(N)
 * memory: O(1)
 *
 */
static bool __is_bst(struct bst *node, int min, int max)
{
	if (!node)
		return true;

	printf("node->val %d, min %d, max %d\n", node->val, min, max);
	if (node->val < min || node->val > max)
		return false;

	return __is_bst(node->left, min, node->val) &&
	       __is_bst(node->right, node->val, max);
}

bool is_bst(struct bst *root)
{
	if (!root)
		return false;

	return __is_bst(root, INT_MIN, INT_MAX);
}

int destroy_valid_bst(struct bst *root)
{
	if (!root)
		return 0;

	destroy_valid_bst(root->left);
	destroy_valid_bst(root->right);
	free(root);

	return 0;
}
