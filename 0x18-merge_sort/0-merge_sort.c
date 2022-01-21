#include "sort.h"

/**
* sorts an array of ints using top-down merge sort algorithm
* @array: array to be sorted
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	merge_sort(array, size / 2);
	merge_sort(array + size / 2, size - size / 2);
	merge(array, size);
}

/**
* merges two sorted arrays into one
* @array: array to be merged
* @size: size of array
*/
void merge(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);
	int i = 0, j = size / 2, k = 0;

	if (!temp)
		return;

	while (i < size / 2 && j < size)
		temp[k++] = array[i] < array[j] ? array[i++] : array[j++];

	while (i < size / 2)
		temp[k++] = array[i++];
}
