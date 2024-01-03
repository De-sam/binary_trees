#include "binary_trees.h"
/**
 * binary_tree_insert_left -Inserts a node at the left-child of a given node
 * @parent:pointer to the node for insertion of left child
 * @value: The value to be stored in the new node
 *
 *Return: Either a pointer to the created node or NULL
 *
 * Description: If left-child already exist in parent node, it is replaced
 * by the new one
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
	{
		return (NULL);
	}
	binary_tree_t *newnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (!newnode)
	{
		return (NULL);
	}
	newnode->n = value;
	newnode->parent = parent;
	newnode->left = parent->left;
	newnode->right = NULL;

	if (parent->left != NULL)
	{
		parent->left->parent = newnode;
	}
	parent->left = newnode;
	return (newnode);
}