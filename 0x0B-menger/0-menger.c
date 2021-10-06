#include "menger.h"

/**
 * TileCarpet - Clones a tile into larger carpet, or blank if center
 * @d: carpet
 * @r: right
 * @c: center
 * @tile: carpet
 * Return: void
 */
void TileCarpet(Carpet d, int r, int c, Carpet tile)
{
	int y0 = tile->dim * r;
	int x0 = tile->dim * c;
	int k, m;

	if ((r == 1) && (c == 1))
	{
		for (k = 0; k < tile->dim; k++)
		{
			for (m = 0; m < tile->dim; m++)
			{
				d->rows[y0 + k][x0 + m] = ' ';
			}
		}
	}
	else
	{
		for (k = 0; k < tile->dim; k++)
		{
			for (m = 0; m < tile->dim; m++)
			{
				d->rows[y0 + k][x0 + m] = tile->rows[k][m];
			}
		}
	}
}

static char s1[] = "#";
static char *r1[] = {s1};
static struct sCarpet single = { 1, s1, r1};

/**
 * Sierpinski - function that draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: Menger Sponge
 */

Carpet Sierpinski(int level)
{
	Carpet carpet;
	Carpet subCarpet;
	int row, col, rb;
	int spc_rqrd;

	subCarpet = (level > 1) ? Sierpinski(level - 1) : &single;

	carpet = malloc(sizeof(struct sCarpet));
	carpet->dim = 3 * subCarpet->dim;
	spc_rqrd = (2 * subCarpet->dim) * (carpet->dim);
	carpet->data = malloc(spc_rqrd * sizeof(char));
	carpet->rows = malloc(carpet->dim * sizeof(char *));
	for (row = 0; row < subCarpet->dim; row++)
	{
		carpet->rows[row] = carpet->data + row * carpet->dim;
		rb = row + subCarpet->dim;
		carpet->rows[rb] = carpet->data + rb * carpet->dim;
		rb = row + 2 * subCarpet->dim;
		carpet->rows[rb] = carpet->data + row * carpet->dim;
	}

	for (col = 0; col < 3; col++)
	{
    /* 2 rows of tiles to copy - third group points to same data a first */
		for (row = 0; row < 2; row++)
			TileCarpet(carpet, row, col, subCarpet);
	}

	if (subCarpet != &single)
	{
		free(subCarpet->rows);
		free(subCarpet->data);
		free(subCarpet);
	}
	return (carpet);
}

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 * Return: Menger Sponge
 */

void menger(int level)
{
	Carpet carp;

	if (level < 0)
	{
		return;
	}
	carp = Sierpinski(level);
	CarpetPrint(carp);
}
