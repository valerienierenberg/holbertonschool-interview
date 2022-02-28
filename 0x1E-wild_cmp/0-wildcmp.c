#include "holberton.h"

/**
 * wildcmp - compares two strings. S2 can contain wildcards.
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if strings match, 0 if not
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == '\0' && *s2 != '\0')
		return (0);
	else if (*s1 != '\0' && *s2 == '\0')
		return (0);
	else if (*s1 != '\0' && *s2 != '\0')
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		else if (*s1 == *s2)
			return (wildcmp(s1 + 1, s2 + 1));
		else if (*s2 == '?')
			return (wildcmp(s1 + 1, s2 + 1));
		else
			return (0);
	}
	return (0);
}