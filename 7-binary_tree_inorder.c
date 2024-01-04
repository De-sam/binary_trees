#include "binary_trees.h"

/**
 * binary_tree_inorder - traversing using the in-order algorithm
 * @tree:Pointer to the root node of the tree
 * @func:Pointer to a function that calls each node
 *
 * if tree or func is NULL, do nothing
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
