#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NUM (20)

struct tree_node {
	size_t size;
	uint32_t val;
	uint32_t times;
	bool is_leaf;
	size_t depth;
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *parent;
};

static size_t min_depth = SIZE_MAX;
static size_t max_depth = 0;

static struct tree_node *print_tree_nodes(struct tree_node *node)
{
	static struct tree_node largest_node = {0, };

	if (NULL != node) {
		print_tree_nodes(node->left);
		if (largest_node.size < node->size)
			largest_node = *node;
		printf("%u -> parent(%u)\n",
			node->val, ((node->parent) ? node->parent->val : -1));
		print_tree_nodes(node->right);
	}

	return &largest_node;
}

static size_t get_size(struct tree_node *node)
{
	if (!node)
		return 0;

	return node->size;
}

static struct tree_node *add_tree_node(struct tree_node *node,
					uint32_t val, size_t depth)
{
	struct tree_node *temp;

	if (NULL == node) {
		node = malloc(sizeof(struct tree_node));
		node->val = val;
		node->times = 1;
		node->left = node->right = NULL;
		node->is_leaf = true;
		node->depth = depth;
		node->parent = NULL;
	} else if (val == node->val) {
		node->times++;
	} else if(val < node->val) {
		depth++;
		temp = add_tree_node(node->left, val, depth);
		node->left  = temp;
		temp->parent = node;
		node->is_leaf = false;
	} else if(val > node->val) {
		depth++;
		temp = add_tree_node(node->right, val, depth);
		node->right  = temp;
		temp->parent = node;
		node->is_leaf = false;
	}

	/* +1 for itself */
	node->size = 1 + get_size(node->left) + get_size(node->right);

	return node;
}

static size_t rank(struct tree_node *node, uint32_t key)
{
	if (!node)
		return 0;

	if (key == node->val)
		return get_size(node);
	else if (key < node->val)
		return rank(node->left, key);
	else
		return 1 + get_size(node->left) + rank(node->right, key);
}

static struct tree_node *find_node(struct tree_node *root, uint32_t val)
{
	struct tree_node *node = root;

	while (node != NULL) {
		if (val < node->val)
			node = node->left;
		else if (val > node->val)
			node = node->right;
		else
			return node;
	}

	return NULL;
}

static void look_up_val_in_bst(struct tree_node *root)
{
	uint32_t val = root->val + 1;

	if (find_node(root, val))
		printf("found %u in bst with rank %zu\n", val,
			rank(root, val));
	else
		printf("did not find %u in bst\n", val);
}

static struct tree_node *create_bst_tree(void)
{
	size_t i;
	uint32_t val;
	struct tree_node *root = NULL;
	time_t t;

	srand(time(&t));

	for (i = 0; i < MAX_NUM; i++) {
		val = rand() % MAX_NUM;
		root = add_tree_node(root, val, 0); 
	}

	return root;
}

static struct tree_node *find_min_in_bst(struct tree_node *root)
{
	struct tree_node *prev;
	struct tree_node *node = root;

	while(node) {
		prev = node;
		node = node->left;
	}

	return prev;
}

static void find_max_in_bst(struct tree_node *root)
{
	struct tree_node *prev;
	struct tree_node *node = root;

	while(node) {
		prev = node;
		node = node->right;
	}

	printf("max node is %u(size %zu)\n", prev->val, prev->size);
}

static struct tree_node *get_floor(struct tree_node *node, uint32_t val)
{
	struct tree_node *t;

	if (!node)
		return NULL;

	if (val == node->val)
		return node;
	if (val < node->val)
		return get_floor(node->left, val);
	t = get_floor(node->right, val);
	if (t != NULL)
		return t;
	else
		return node;
}

static struct tree_node *get_ceiling(struct tree_node *node, uint32_t val)
{
	struct tree_node *t;

	if (!node)
		return NULL;

	if (val == node->val)
		return node;
	if (val > node->val)
		return get_ceiling(node->right, val);
	t = get_ceiling(node->left, val);
	if (t != NULL)
		return t;
	else
		return node;
}

static void find_floor_and_ceiling(struct tree_node *root)
{
	uint32_t val = root->val + 1;
	struct tree_node *t;

	t = get_floor(root, val);
	if (t)
		printf("found %u in bst as floor of %u\n",
			t->val, val);
	else
		printf("did not find floor of %u in bst\n", val);

	t = get_ceiling(root, val);
	if (t)
		printf("found %u in bst as ceiling of %u\n",
			t->val, val);
	else
		printf("did not find ceiling of %u in bst\n", val);

}

static struct tree_node *delete_min_in_bst(struct tree_node *node)
{
	if (NULL == node->left)
		return node->right;

	node->left = delete_min_in_bst(node->left);
	node->size = 1 + get_size(node->left) + get_size(node->right);

	return node;
}

static struct tree_node *delete_node(struct tree_node *node, uint32_t key)
{
	struct tree_node *temp_node;
	if (!node)
		return NULL;

	if (key < node->val) {
		temp_node = delete_node(node->left, key);
		node->left = temp_node;
		if (temp_node) {
			temp_node->parent = node;
			if (temp_node->left == NULL && temp_node->right == NULL)
				temp_node->is_leaf = true;
		}
	} else if (key > node->val) {
		temp_node = delete_node(node->right, key);
		node->right = temp_node;
		if (temp_node) {
			temp_node->parent = node;
			if (temp_node->left == NULL && temp_node->right == NULL)
				temp_node->is_leaf = true;
		}
	} else {
		if (node->right == NULL)
			return node->left;
		struct tree_node *t = node;

		node = find_min_in_bst(t->right);
		node->right = delete_min_in_bst(t->right);
		node->left = t->left;
		if (node->left == NULL && node->right == NULL)
			node->is_leaf = true;
		else
			node->is_leaf = false;
		if (t->left)
			t->left->parent = node;
	}

	node->size = 1 + get_size(node->left) + get_size(node->right);

	return node;
}

static void print_inorder_bst(struct tree_node *root)
{
	if (!root)
		return;

	if (root) {
		print_inorder_bst(root->left);
		printf("val %u\n", root->val);
		print_inorder_bst(root->right);
	}
}

static void convert_bst_to_doubly_linked_list(struct tree_node *root,
					      struct tree_node **head)
{
	static struct tree_node *prev = NULL;

	if (root == NULL)
		return;

	convert_bst_to_doubly_linked_list(root->left, head);

	if (prev == NULL) {
		*head = root;
	} else {
		prev->right = root;
		root->left = prev;
	}
	prev = root;

	convert_bst_to_doubly_linked_list(root->right, head);
}

static void create_doubly_linked_list(struct tree_node *root)
{
	struct tree_node *head, *temp;
	convert_bst_to_doubly_linked_list(root, &head);

	printf("created doubly linked list is:\n");
	for (temp = head; temp; temp = temp->right)
		printf("%u-->", temp->val);

	printf("\n");
}

static bool is_leaf_node(struct tree_node *node)
{
	if (!(node->left) && !(node->right))
		return true;
	else
		return false;
}

static void calculate_min_depth(struct tree_node *root, size_t level)
{
	if (!is_leaf_node(root))
		return;

	if (level < min_depth)
		min_depth = level;
}

static void calculate_max_depth(struct tree_node *root, size_t level)
{
	if (!is_leaf_node(root))
		return;

	if (level > max_depth)
		max_depth = level;
}

static void preorder_depth_calc_bst(struct tree_node *root, size_t level)
{
	if(!root)
		return;

	calculate_min_depth(root, level);
	calculate_max_depth(root, level);

	preorder_depth_calc_bst(root->left, level + 1);
	preorder_depth_calc_bst(root->right, level + 1);
}

static size_t absolute_diff(size_t val1, size_t val2)
{
	if (val1 > val2)
		return val1 - val2;
	else
		return val2 - val1;
}

static bool is_bst_is_balanced(uint32_t node_val,
				size_t left_subtree_height,
				size_t right_subtree_height)
{
	bool balanced = false;
	size_t diff = absolute_diff(left_subtree_height, right_subtree_height);

	if (diff >= 1) {
		printf("subtree at node %u is -unbalanced-\n", node_val);
		balanced =  false;
	} else {
		balanced = true;
		printf("subtree at node %u is [balanced]\n", node_val);
	}

	return balanced;
}

static void check_node_left_and_right_subtree_size(struct tree_node *node)
{
	size_t left_subtree_size;
	size_t right_subtree_size;

	left_subtree_size = get_size(node->left);
	right_subtree_size = get_size(node->right);

	printf("node is %u and size of left subtree is %zd\n",
		node->val, left_subtree_size);
	printf("node is %u and size of right subtree is %zd\n",
		node->val, right_subtree_size);

	is_bst_is_balanced(node->val, left_subtree_size, right_subtree_size);
}

static void check_if_bst_is_balanced(struct tree_node *root)
{
	if (!root)
		return;

	check_node_left_and_right_subtree_size(root);
	check_if_bst_is_balanced(root->left);
	check_if_bst_is_balanced(root->right);
}

static void test_bst(void)
{
	struct tree_node *largest_node;
	struct tree_node *root;

	root = create_bst_tree();
	printf("root of the tree is %u(size %zu)\n", root->val, root->size);

	print_inorder_bst(root);

	preorder_depth_calc_bst(root, 0);
	printf("min depth is %zd and max depth is %zd\n", min_depth, max_depth);

	check_if_bst_is_balanced(root);

	create_doubly_linked_list(root);
}

int main()
{
	test_bst();

	return 0;
}
