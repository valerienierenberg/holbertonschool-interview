#include "binary_trees.h"

/**
* heap_extract - extract the root of a heap
* @root: root of the heap
*/

int heap_extract(heap_t **root)
{
    heap_t *temp;
    int value;

    if (!root || !*root)
        return (0);

    temp = *root;
    value = temp->n;
    *root = temp->left;
    free(temp);
    return (value);
}
