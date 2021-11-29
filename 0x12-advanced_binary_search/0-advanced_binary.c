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
	if (array == NULL)
		return (-1);

	return (advanced_binary_rec(array, 0, size - 1, value));
}

/**
* advanced_binary_rec - recursive binary search
* @array: array to search
* @start: starting index
* @end: ending index
* @value: value to search for
* Return: index of value or -1 if not found
*/

int advanced_binary_rec(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (start > end)
		return (-1);

	mid = (start + end) / 2;
	if (array[mid] == value)
		return (mid);
	else if (array[mid] < value)
		return (advanced_binary_rec(array, mid + 1, end, value));
	else
		return (advanced_binary_rec(array, start, mid - 1, value));
}