#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	size_t front ,rear;
	int non_full_node_seen;

	if (tree == NULL)
		return (0);

	/* Use a queue for level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	front = 0, rear = 0;
	non_full_node_seen = 0;

	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		/* If a non-full node has been seen before, all nodes must be leaves */
		if (non_full_node_seen && (current->left || current->right))
		{
			free(queue);
			return (0);
		}

		/* If a non-full node is encountered, mark it */
		if ((current->left && !current->right) || (!current->left && current->right))
			non_full_node_seen = 1;

		/* Enqueue left child if it exists */
		if (current->left)
			queue[rear++] = current->left;

		/* Enqueue right child if it exists */
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);

	/* All conditions satisfied, the tree is complete */
	return (1);
}
