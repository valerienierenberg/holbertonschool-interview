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
		if (current->left == NULL)
		{
			current->left = new;
			new->n = value;
			new->parent = current;
			new->left = new->right = NULL;

			if (value > current->n)
			{
				current = new;
				return (new);
			}
		}
		else
		{
			current->right = new;
			new->n = value;
			new->parent = current;
			if (value > current->n)
			{
				new = current;
				return (new);
			}
		}
	}
	return (NULL);
}
