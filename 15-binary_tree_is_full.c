#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If the node has either no children or both children */
	if ((tree->left == NULL && tree->right == NULL) ||
	    (tree->left != NULL && tree->right != NULL))
	{
		/* Check the same condition for the left and right subtrees */
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	}

	return (0); /* Not a full tree */
}
