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
	size_t middle;

	if (array == NULL || size < 1)
		return (-1);

	middle = size / 2;

	if (array[middle] == value)
		return (middle);

	if (array[middle] < value)
		return (advanced_binary(array + middle + 1, size - middle - 1, value));

	return (advanced_binary(array, middle, value));
}
