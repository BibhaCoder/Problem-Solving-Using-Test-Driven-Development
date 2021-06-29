#include <stdbool.h>
#include <stddef.h>

struct bst {
	struct bst *left;
	struct bst *right;
	int val;
	size_t count;
};

void inorder_traverse(struct bst *root);
struct bst *build_correct_bst(struct bst *root, int val);
struct bst *build_incorrect_bst(struct bst *root, int val);
int destroy_valid_bst(struct bst *root);
bool is_bst(struct bst *root);
