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
    int i, temp;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
    {
        sift_down(array, i, size);
    }

    for (i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        sift_down(array, 0, i);
    }
}

/**
* sift_down - function that sifts down
* Return: void
*/

void sift_down(int *array, int index, size_t size)
{
    int left, right, largest;

    left = 2 * index + 1;
    right = 2 * index + 2;
    largest = index;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != index)
    {
        swap(array, largest, index);
        sift_down(array, largest, size);
    }
}
