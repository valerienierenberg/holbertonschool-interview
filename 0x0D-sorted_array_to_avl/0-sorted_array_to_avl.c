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
    size_t i;

    if (array == NULL)
        return (NULL);
    for (i = 0; i < size; i++)
    {
        root = avl_insert(root, array[i]);
    }
    return (root);
}

avl_t *avl_insert (avl_t *root, int value)
{
    avl_t *new_node, *parent, *current;

    new_node = malloc(sizeof(avl_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    /*new_node->height = 0;*/
    if (root == NULL)
        return (new_node);
    parent = NULL;
    current = root;
    while (current != NULL)
    {
        parent = current;
        if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }
    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->parent = parent;
    return (new_node);
}
