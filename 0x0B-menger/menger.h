#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct sCarpet - doubly linked list
 * @dim: dimensions
 * @data: character data
 * @rows: number of rows
 */
typedef struct sCarpet
{
	int dim;
	char *data;
	char **rows;
} *Carpet;

void menger(int level);
void TileCarpet(Carpet d, int r, int c, Carpet tile);
Carpet Sierpinski(int level);
void CarpetPrint(Carpet carp);

#endif
