#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int advanced_binary(int *array, size_t size, int value);
int advanced_binary_helper(int *array, size_t start, size_t end, int value);

#endif
