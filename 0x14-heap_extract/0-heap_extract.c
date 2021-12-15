#include "binary_trees.h"

/**
* heap_extract - extract the root of a heap
* @root: root of the heap
*/
int heap_extract(heap_t **root)
{
	heap_t *tmp;
	int ret;

	if (!root || !*root)
		return (0);

	tmp = *root;

	if ((*root)->left)
		*root = (*root)->left;
	else if ((*root)->right)
		*root = (*root)->right;
	else
		*root = NULL;

	ret = tmp->n;

	free(tmp);
	return (ret);
}