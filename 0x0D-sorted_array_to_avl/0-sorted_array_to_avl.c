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
	for (i = 0; i < (int)size; i++)
	{
		root = avl_insert(root, array[i]);
	}
	return (root);
}

/**
 * avl_insert - function that builds an AVL tree from an array
 * @root: root node
 * @value: value of the node
 * Return: AVL tree
 */
avl_t *avl_insert(avl_t *root, int value)
{
	avl_t *new_node, *temp;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	/*new_node->height = 0;*/
	if (root == NULL)
		return (new_node);
	temp = root;
	while (temp != NULL)
	{
		if (value < temp->n)
		{
			if (temp->left == NULL)
			{
				temp->left = new_node;
				break;
			}
			temp = temp->left;
		}
		else
		{
			if (temp->right == NULL)
			{
				temp->right = new_node;
				break;
			}
			temp = temp->right;
		}
	}
	return (root);
}
