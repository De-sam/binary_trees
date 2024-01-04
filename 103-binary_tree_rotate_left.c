#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;
	binary_tree_t *right_subtree;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	right_subtree = new_root->left;

	new_root->left = tree;
	tree->right = right_subtree;

	if (tree->right != NULL)
		tree->right->parent = tree;

	new_root->parent = tree->parent;
	tree->parent = new_root;

	if (new_root->parent == NULL)
		return (new_root);

	{
		if (new_root->parent->left == tree)
			new_root->parent->left = new_root;
		else
			new_root->parent->right = new_root;
	}

	return (new_root);
}
