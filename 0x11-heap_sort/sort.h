#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, int index, size_t size);

#endif
