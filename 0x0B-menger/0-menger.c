#include "menger.h"
#include<math.h>

/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: the level of the Menger Sponge to draw
 * Return: 
 */

void menger(int level)
{
    int width, height, z = pow(3, level);
    int check;
    char printchar;

    if (level < 0)
    {
        ;
    }
    if (level == 0)
    {
        printf("#\n");
        return;
    }
    for (height = 0; height < z; height++)
    {
        for (width = 0; width < z; width++)
        {
            check = 1;
            printchar = '#';
            for (; check < z; check *= 3)
            {
                if ((height / check) % 3 == 1 &&
                    (width / check) % 3 == 1)
                    {
                       printchar = ' ';
                       break;
                    }
            }
            printf("%c", printchar);
        }
        printf("\n");
    }
}
