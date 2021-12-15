#include "binary_trees.h"

/**
* heap_extract - extract the root of a heap
* @root: root of the heap
*/
int heap_extract(heap_t **root)
{
	int data;
	heap_t *temp;

	if (!root || !(*root))
		return (0);
	temp = *root;
	data = temp->n;
	if (temp->left)
		heap_insert(&temp->left, temp->left);
	if (temp->right)
		heap_insert(&temp->right, temp->right);
	*root = temp->left;
	free(temp);
	return (data);
}

int heap_insert(heap_t **root, heap_t *node)
{
    heap_t *temp;

    if (!root || !node)
        return (-1);
    if (!(*root))
    {
        *root = node;
        return (1);
    }
    temp = *root;
    if (node->n > temp->n)
    {
        node->right = temp;
        *root = node;
    }
    else
    {
        while (temp->right && temp->right->n < node->n)
            temp = temp->right;
        if (temp->right)
            temp->right->left = node;
        node->right = temp->right;
        temp->right = node;
    }
    return (1);
}
