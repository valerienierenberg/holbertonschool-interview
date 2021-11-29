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
	if (array == NULL || size < 1)
		return (-1);
	return (advanced_binary_helper(array, 0, size - 1, value));
}

/**
* advanced_binary_helper - recursive helper function
* @array: array to search
* @start: start of array
* @end: end of array
* @value: value to search for
* Return: index of value or -1 if not found
*/

int advanced_binary_helper(int *array, size_t start, size_t end, int value)
{
	size_t middle = start + (end - start) / 2;

	if (start > end)
		return (-1);

	if (array[middle] == value)
		return (middle);

	if (array[middle] < value)
		return (advanced_binary_helper(array, middle + 1, end, value));

	if (array[middle] > value)
		return (advanced_binary_helper(array, start, middle - 1, value));

	return (-1);
}