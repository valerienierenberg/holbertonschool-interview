#include "binary_trees.h"

/**
 * find_h - find height of tree
 * @tree: pointer to root of tree
 * Return: if NULL return 0
 */

size_t find_h(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = find_h(tree->left);
	right = find_h(tree->right);
	if (left > right)
	return (left + 1);
	else
	return (right + 1);
}

/**
 * balance - returns balance factor
 * @tree: root of tree
 * Return: balance factor
 */

int balance(const binary_tree_t *tree)
{
	int left, right, bal;

	if (tree == NULL)
	{
		return (0);
	}
	left = find_h(tree->left);
	right = find_h(tree->right);
	bal = left - right;

	return (bal);
}

/**
 * tree_sort - sorts new tree
 * @root: root of tree
 * Return: tree
 */

void tree_sort(binary_tree_t *root)
{
	int place_holder;
	heap_t *tmp;

	if (!root->left && !root->right)
		return;

	if (root->right && root->right->n > root->left->n)
		tmp = root->right;
	else
		tmp = root->left;

	if (root->n < tmp->n)
	{
		place_holder = root->n;
		root->n = tmp->n;
		tmp->n = place_holder;
		tree_sort(tmp);
	}
}


/**
 * heap_extract - extracts root of max heap
 * @root: root node of binary search tree
 *
 * Return: value of node deleted
 */

int heap_extract(heap_t **root)
{
	heap_t *min = *root, *tmp = NULL;
	int res;

	if (!root || !(*root))
		return (0);
	res = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (res);
	}
	while (min != NULL)
	{
		if (!min->left && !min->right)
			break;
		if (balance(min) <= 0)
			min = min->right;
		else
			min = min->left;
	}
	if (!min->parent)
	{
		res = min->n;
		free(min);
		return (res);
	}
	tmp = min->parent;
	(*root)->n = min->n;
	if (tmp->left == min)
		tmp->left = NULL;
	else
		tmp->right = NULL;
	free(min);

	tree_sort(*root);

	return (res);
}
