#include "binary_trees.h"

/**
* heap_insert - inserts a value into a Max Binary Heap
* @root: a double pointer to the root node of the Heap
* @value: value stored in the node to be inserted
*
* Return: pointer to the inserted node, or NULL on failure
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *current = *root;
	heap_t *new = malloc(sizeof(heap_t));
		if (new == NULL)
			return (NULL);

	if (*root == NULL)
	{
		new->n = value;
		new->parent = new->left = new->right = NULL;
		*root = new;
		return (new);
	}
	else
	{
		if (value > (current->n))
		{
			current->right = heap_insert(&current->right, value);
			new = current;
			return (new);
		}
		else
		{
			current->left = heap_insert(&current->left, value);
			new = current;
			return (new);
		}
	}
	return (NULL);
}
