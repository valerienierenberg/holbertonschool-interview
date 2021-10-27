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

    if (array == NULL)
        return (NULL);
    root = binary_tree_t(array[0]);
    if (root == NULL)
        return (NULL);
    if (size > 1)
        root = sorted_array_to_avl_rec(root, array + 1, size - 1);
    return (root);
}

binary_tree_t *sorted_array_to_avl_rec(binary_tree_t *root,
                        int *array, size_t size)
{
    binary_tree_t *left = NULL, *right = NULL;
    size_t left_size = 0, right_size = 0;

    if (root == NULL || array == NULL)
        return (NULL);
    if (size == 0)
        return (root);
    left_size = size / 2;
    right_size = size - left_size - 1;
    left = sorted_array_to_avl_rec(root->left, array, left_size);
    right = sorted_array_to_avl_rec(root->right, array + left_size + 1,
                    right_size);
    root->left = left;
    root->right = right;
    return (root);
}
