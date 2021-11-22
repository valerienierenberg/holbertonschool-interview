#include "sort.h"

/**
* heap_sort - a function that sorts an array of integers in ascending
* order using the (sift down) Heap sort algorithm
* @array: integers
* @size: size of the array
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		sift_down(array, size, i, size);
	}

	for (i = (size - 1); i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		if (i != 0)
		{
			print_array(array, size);
		}
		sift_down(array, i, 0, size);
	}
}

/**
* sift_down - function that sifts down values
* @arr: ints
* @size: size of array
* @i: index
* @cpysize: copy of size of array for printing
* Return: void
*/
void sift_down(int *arr, size_t size, size_t i, size_t cpysize)
{
	size_t left, right, cpy;
	int temp = 0;

	left = 2 * i + 1;
	right = 2 * i + 2;
	cpy = i;

	if (left < size && arr[left] > arr[cpy])
		cpy = left;

	if (right < size && arr[right] > arr[cpy])
		cpy = right;

	if (cpy != i)
	{
		temp = arr[i];
		arr[i] = arr[cpy];
		arr[cpy] = temp;
		print_array(arr, cpysize);
		sift_down(arr, size, cpy, cpysize);
	}
}
