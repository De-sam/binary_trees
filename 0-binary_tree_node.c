#include "binary_trees.h"
/**
 *binary_tree_node - Create a binary tree node
 *@parent: A pointer to the parent node
 *@value: int value to be added in new node
 *
 * Return: pointer to new node or Null if failed
 *
 * Description: Allocates memory for a new tree node
 * and then initailises its value
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (newnode != NULL)
	{
		newnode->n = value;
		newnode->parent = parent;
		newnode->left  = NULL;
		newnode->right = NULL;

	}
	return (newnode);
}
