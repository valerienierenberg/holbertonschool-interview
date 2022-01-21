#include "sort.h"

/**
* merge_sort - sorts an array of ints using top-down merge sort algorithm
* @array: array to be sorted
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	merge_sort(array, size / 2);
	merge_sort(array + (size / 2), size - (size / 2));
	merge(array, size);
}

/**
* merge - merges two sorted arrays into one
* @array: array to be sorted
* @size: size of array
*/
void merge(int *array, size_t size)
{
	int *temp = malloc(sizeof(int) * size);
	size_t i = 0, j = 0, k = 0;

	while (i < size / 2 && j < size - (size / 2))
	{
		if (array[i] < array[j + (size / 2)])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j + (size / 2)];
			j++;
		}
		k++;
	}
	while (i < size / 2)
	{
		temp[k] = array[i];
		k++;
		i++;
	}
	while (j < size - (size / 2))
	{
		temp[k] = array[j + (size / 2)];
		k++;
		j++;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	free(temp);
}
