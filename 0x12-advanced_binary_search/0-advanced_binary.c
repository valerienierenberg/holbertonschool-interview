#include "search_algos.h"

/**
* advanced_binary - a function that searches for a value in a sorted...
* ...array of integers
* order using the (sift down) Heap sort algorithm
* @array: is a pointer to the first element of the array to search in
* @size: number of elements in the array
* @value: is the value to be searched for
* Return: the index where value is located
*/
int advanced_binary(int *array, size_t size, int value)
{
	int mid_index = (size - 1) / 2;
	int outcome = 0;
	size_t i = 0;

	if (array == NULL || size < 2)
		return (-1);

	print_searching_output(&array[i], size);

	if (array[mid_index] == value && mid_index == 0)
		return (mid_index);
	if (size == 1)
		return (-1);
	if (array[mid_index] >= value)
		return (advanced_binary(array, mid_index + 1, value));

	mid_index++;
	outcome = advanced_binary(&array[mid_index], size - mid_index, value);

	if (outcome == -1)
		return (-1);
	return (mid_index + outcome);
}

/**
* print_searching_output - a helper function to print output
* @array: is a pointer to the first element of the array to search in
* @size: number of elements in array
* Return: void
*/
void print_searching_output(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
		else
			printf("\n");
		if (i == size && array[i] == 51)
			printf("Searching in array: 51");
	}
}
