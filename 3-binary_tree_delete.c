#include "binary_trees.h"
/**
 * binary_tree_delete -Inserts a node at the left-child of a given node
 * @tree: pointer to the root node of the tree to delete
 *
 *Return: Either a pointer to the created node or NULL
 *
 *Description: If tree is NULL, do nothing.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
