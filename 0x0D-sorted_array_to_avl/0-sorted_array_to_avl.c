#include "binary_trees.h"

/**
* sorted_array_to_avl - function that builds an AVL tree from an array
* @array: is a pointer to the first element of the array to be converted
* @size: is the number of element in the array
* Return:a pointer to the root node of the created AVL tree, or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (avl_tree(array, 0, size - 1, NULL));
}

/**
 * avl_tree - function to create a tree and set values
 * @root: root of the tree
 * @array: array that is sorted
 * @first: beginning of array
 * @last: end of array
 *
 * Return: new AVL tree
 */
avl_t *avl_tree(int *array, int first, int last, avl_t *root)
{
	/* between used to get divide array by 2 */
	int btw;

	if (first > last)
		return (NULL);
	btw = (first + last) / 2;
	root = avl_insert(root, array[btw]);
	if (root == NULL)
		return (NULL);
	root->left = avl_tree(array, first, btw - 1, root);
	root->right = avl_tree(array, btw + 1, last, root);
	return (root);
}

/**
 * avl_insert - function that inserts a node into an AVL tree
 * @root: root of the tree
 * @value: value to be inserted
 *
 * Return: new added value(s)
 */
avl_t *avl_insert(avl_t *root, int value)
{
	avl_t *newV = NULL;

	newV = malloc(sizeof(avl_t));
	if (newV == NULL)
		return (NULL);
	(newV)->n = value;
	(newV)->left = NULL;
	(newV)->right = NULL;

	if (root == NULL)
	{
		newV->parent = NULL;
		root = newV;
	}
	else
		newV->parent = root;
	return (newV);
}
