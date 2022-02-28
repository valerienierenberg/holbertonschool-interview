#include "holberton.h"

/**
* wildcmp - compares two strings and returns 1 if the strings can be considered identical, 0 otherwise
* @s1: string 1
* @s2: string 2
* Return: 1 if the strings can be considered identical, 0 otherwise
*/

int wildcmp(char *s1, char *s2)
{
    int i = 0, j = 0;

    while (s1[i] != '\0')
    {
        if (s2[j] == '*')
        {
            while (s2[j] == '*')
                j++;
            while (s1[i] != s2[j] && s1[i] != '\0')
                i++;
            if (s1[i] == '\0')
                return (0);
            j++;
            i++;
        }
        else if (s1[i] != s2[j])
            return (0);
        else
            i++, j++;
    }
    if (s2[j] != '\0')
        return (0);
    return (1);
}
