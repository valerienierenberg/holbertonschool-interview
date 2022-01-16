#include "sort.h"

/**
* merge_sort - Sorts an array of integers in ascending order using the
* Merge sort algorithm
* @array: The array to be sorted
* @size: Number of elements in @array
* Return: Nothing
*/
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_rec(array, 0, size - 1);
}

/**
* merge_sort_rec - Helper function for merge sort
* @array: The array to be sorted
* @start: The starting index of the array
* @end: The ending index of the array
* Return: Nothing
*/
void merge_sort_rec(int *array, size_t start, size_t end)
{
	int *temp;
	size_t mid;

	if (start >= end)
		return;

	mid = (start + end) / 2;
	merge_sort_rec(array, start, mid);
	merge_sort_rec(array, mid + 1, end);
	temp = malloc(sizeof(int) * (end - start + 1));
	if (temp == NULL)
		return;
	merge(array, temp, start, mid, end);
	free(temp);
}

/**
* merge - Merges two sorted arrays
* @array: The array to be sorted
* @temp: Temporary array to hold sorted values
* @start: The starting index of the array
* @mid: The middle index of the array
* @end: The ending index of the array
* Return: Nothing
*/
void merge(int *array, int *temp, size_t start, size_t mid, size_t end)
{
	size_t i, j, k;

	i = start;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= end)
		temp[k++] = array[j++];
	for (i = 0; i < k; i++)
        array[start + i] = temp[i];
}
