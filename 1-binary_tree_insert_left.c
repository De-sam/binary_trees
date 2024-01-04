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
	binary_tree_t *newnode;

	if (parent == NULL)
	{
		return (NULL);
	}
	newnode = binary_tree_node(parent, value);
	if (!newnode)
	{
		return (NULL);
	}

	if (parent->left != NULL)
	{
		newnode->left = parent->left;
		parent->left->parent = newnode;
	}

	parent->left = newnode;
	return (newnode);
}
