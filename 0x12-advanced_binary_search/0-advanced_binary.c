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
	size_t mid = 0;

	if (array == NULL)
		return (-1);

	mid = size / 2;

	if (array[mid] == value)
		return (mid);

	if (size == 1)
		return (-1);

	if (array[mid] > value)
		return (advanced_binary(array, mid, value));

	if (array[mid] < value)
		return (advanced_binary(&array[mid + 1], size - mid - 1, value));

	return (-1);
}