#include <sort.h>

/**
* heap_sort - function that sorts an array of integers in ascending
* order using the (sift down) Heap sort algorithm
* @array: integers
* @size: size of the array
* Return: void
*/

void heap_sort(int *array, size_t size)
{
    int i, j, temp;

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
