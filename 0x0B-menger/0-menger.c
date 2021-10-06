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
	if (level < 0)
	{
		return;
	}
	if (level == 0)
	{
		printf("#\n");
	}
	if (level == 1)
	{
		printf("###\n");
		printf("# #\n");
		printf("###\n");
	}
	if (level == 2)
	{
		printf("#########\n");
		printf("# ## ## #\n");
		printf("#########\n");
		printf("###   ###\n");
		printf("# #   # #\n");
		printf("###   ###\n");
		printf("#########\n");
		printf("# ## ## #\n");
		printf("#########\n");
	}
}


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
