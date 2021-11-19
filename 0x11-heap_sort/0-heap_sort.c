#include "sort.h"

/**
* heap_sort - function that sorts an array of integers in ascending
* order using the (sift down) Heap sort algorithm
* @array: integers
* @size: size of the array
* Return: void
*/

void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	helper_heap_sort(array, size, array, size);
}

/**
* helper_heap_sort - function that helps & prints
* @array: integers
* @size: size of the array
* @cpyarray: copy of entire array to print
* @cpysize: copy of size to print
* Return: void
*/

void helper_heap_sort(int *array, size_t size, int *cpyarray, size_t cpysize)
{
	size_t i = 0, temp = 0;

	for (i = (size - 1) / 2; (int)i >= 0; i--)
	{
		sift_down(array, i, size, cpyarray, cpysize);
	}

	for (i = size - 1; i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		cpyarray[i] = array[i];
		cpyarray[0] = array[0];
		print_array(array, size);
		sift_down(array, 0, i, cpyarray, cpysize);
	}
}

/**
* sift_down - function that sifts down
* @arr: ints
* @i: index
* @size: size of array
* @cpyarray: copy of entire array to print
* @cpysize: copy of size of array for printing purposes
* Return: void
*/

void sift_down(int *arr, size_t i, size_t size, int *cpyarray, size_t cpysize)
{
	size_t left, right, largest;
	int temp = 0;

	left = 2 * i + 1;
	right = 2 * i + 2;
	largest = i;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		cpyarray[i] = arr[i];
		cpyarray[largest] = arr[largest];
		print_array(arr, size);
		sift_down(arr, largest, size, cpyarray, cpysize);
	}
}
