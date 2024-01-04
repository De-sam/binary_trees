#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue;
	size_t front, rear;

	if (tree == NULL || func == NULL)
		return;

	/* Use a queue to perform level-order traversal */
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	front = 0;
	rear = 0;

	if (queue == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}
