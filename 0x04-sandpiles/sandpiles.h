#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid1(int grid[3][3]);
int check_stable(int grid1[3][3]);

#endif /* SANDPILES_H */
