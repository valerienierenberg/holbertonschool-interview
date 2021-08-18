#include "sandpiles.h"

/**
* sandpiles_sum- computes the sum of two sandpiles
* @grid1: first sandpile, matrix of ints
* @grid2: second sandpile, matrix of ints
* Return: sum of two sandpiles
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, num;
    int newgrid[3][3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            num = grid1[i][j];
            if (num < 4)
            {
                newgrid[i][j] = grid1[i][j];
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            num = grid1[i][j];
            if (num >= 4)
            {
                newgrid[i][j] = grid1[i][j] - 4;
                newgrid[i + 1][j]++;
                newgrid[i - 1][j]++;
                newgrid[i][j + 1]++;
                newgrid[i][j - 1]++;
            }
        }
    }
    grid1 = newgrid;
}
