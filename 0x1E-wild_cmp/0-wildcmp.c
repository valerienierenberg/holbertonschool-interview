#include "holberton.h"

/**
* wildcmp - compares two strings. s2 can contain the special character '*'
* which can replace any string (including empty string)
* @s1: string 1
* @s2: string 2
* Return: 1 if the strings can be considered identical, 0 otherwise
*/

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '\0')
	{
		if (*s1 == '\0')
			return (1);
		else
			return (0);
	}
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		else
		{
			while (*s1 != '\0')
			{
				if (wildcmp(s1, s2 + 1))
					return (1);
				s1++;
			}
			return (0);
		}
	}
	if (*s1 != *s2 && *s2 != '?')
		return (0);
	return (wildcmp(s1 + 1, s2 + 1));
}
