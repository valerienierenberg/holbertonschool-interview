#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void helper_heap_sort(int *array, size_t size, int *cpyarray, size_t cpysize);
void sift_down(int *arr, size_t i, size_t size, int *cpyarray, size_t cpysize);
void swap(int *array, int index1, int index2);

#endif
