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
    if (*root)
        (*root)->parent = NULL;
    free(temp);
    if (*root)
        heap_sift_down(*root);
    return (value);
}

void heap_sift_down(heap_t *root)
{
    heap_t *temp;

    if (!root)
        return;
    while (root->left)
    {
        if (root->n > root->left->n)
        {
            if (root->n > root->right->n)
            {
                temp = root->left;
                root->left = root->right;
                root->right = temp;
            }
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        root = root->left;
    }
}
