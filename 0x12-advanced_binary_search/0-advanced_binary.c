#include "search_algos.h"

/**
* advanced_binary - binary search using recursion
* @array: array to search
* @size: size of array
* @value: value to search for
* Return: index of value or -1 if not found
*/

int advanced_binary(int *array, size_t size, int value)
{
	size_t mid = size / 2;
	int *left;
	int *right;

	if (array == NULL || size == 0)
		return (-1);
	left = array;
	right = array + mid;
	if (size == 1)
	{
		if (*left == value)
			return (0);
		else
			return (-1);
	}
	if (value == *left)
		return (0);
	if (value > *left)
		return (advanced_binary(right, size - mid, value));
	if (value < *left)
		return (advanced_binary(left, mid, value));
	return (-1);
}