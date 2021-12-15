#include "binary_trees.h"

/**
* heap_extract - extract the root of a heap
* @root: root of the heap
* Your function must return the value stored in the root node
* The root node must be freed and replace with the last level-order node of the heap
* Once replaced, the heap must be rebuilt if necessary
* Return: the value of the root node
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
    if (*root)
        heapify(root);
    return (value);
}

void heapify(heap_t **root)
{
    heap_t *temp;
    heap_t *parent;
    heap_t *child;

    temp = *root;
    parent = temp->parent;
    child = temp->left;
    while (child)
    {
        if (child->n > temp->n)
        {
            swap_nodes(&temp, &child);
            temp = child;
            child = temp->left;
        }
        else
            break;
    }
    if (parent && temp->n > parent->n)
    {
        swap_nodes(&temp, &parent);
        heapify(&parent);
    }
}

void swap_nodes(heap_t **a, heap_t **b)
{
    heap_t *temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
