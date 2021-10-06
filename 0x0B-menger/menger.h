#ifndef MENGER_H
#define MENGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * CarpetPrint - function that prints a 2D Menger Sponge
 * @carp: Carpet to print
 * Return: void
 */
void CarpetPrint(Carpet carp)
{
	char obuf[730];
	int row;

	for (row = 0; row < carp->dim; row++)
	{
		strncpy(obuf, carp->rows[row], carp->dim);
		printf("%s\n", obuf);
	}
}

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
