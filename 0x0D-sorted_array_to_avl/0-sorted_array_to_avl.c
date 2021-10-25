#include "binary_trees.h"

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: array from which to build the AVL tree
 * @size: size of tree
 * Return: AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    int i;

    if (array == NULL)
        return (NULL);
    for (i = 0; i < size; i++)
    {
        root = avl_insert(root, array[i]);
    }
    return (root);
}
