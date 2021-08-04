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
	/* heap_t *cpy = *root; */
	heap_t *new = NULL;

	new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);

	if (*root == NULL)
	{
		new->n = value;
		new->parent = NULL;
		new->left = NULL;
		new->right = NULL;
		*root = new;
		return (new);
	}
	return (NULL);
}
