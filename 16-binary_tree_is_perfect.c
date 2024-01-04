#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	size_t nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_count_nodes(tree);

	if (((size_t)1 << height) - 1 == nodes)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_count_nodes - Counts the nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Total number of nodes in the tree
 */
size_t binary_tree_count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_count_nodes(tree->left)
	 + binary_tree_count_nodes(tree->right) + 1);
}
