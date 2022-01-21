#include "sort.h"

/**
* merge_sort - Merge sort
* @array: Array to sort
* @size: Size of array
*/

void merge_sort(int *array, size_t size)
{
	size_t i, j, k;
	int *temp;

	if (size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	for (i = 0; i < size; i++)
		temp[i] = array[i];

	for (i = 0, j = size / 2, k = 0; k < size; k++)
	{
		if (j >= size)
			array[k] = temp[i++];
		else if (i >= size / 2)
			array[k] = temp[j++];
		else if (temp[i] < temp[j])
			array[k] = temp[i++];
		else
			array[k] = temp[j++];
	}
	free(temp);
}
