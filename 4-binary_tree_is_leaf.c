#include "binary_trees.h"

/**
 *binary_tree_is_leaf - Checks if a node is a leaf
 *@node: pointer to the node to be checked
 *
 * Return: 1 if node is a leaf,0 otherwise
 *         if Node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int is_leaf = 0;

	if (node != NULL)
	{
		is_leaf = (node->left == NULL) && (node->right == NULL);
	}

	return (is_leaf);
}
