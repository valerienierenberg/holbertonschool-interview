#include "holberton.h"

/**
* main - program that multiplies two positive numbers
* @argc: number of arguments
* @argv: array of arguments
* Return: 0
*/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
    if (_atoi(argv[1]) == 0 || _atoi(argv[2]) == 0)
    {
        printf("Error\n");
        exit(98);
    }
	printf("%d\n", _atoi(argv[1]) * _atoi(argv[2]));
	return (0);
}

/**
* _atoi - converts a string to an integer
* @s: string to be converted
* Return: integer
*/

int _atoi(char *s)
{
    int i, sign, num;

    i = 0;
    sign = 1;
    num = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' ||
        s[i] == '\f' || s[i] == '\r')
        i++;
    if (s[i] == '-')
        sign = -1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return (num * sign);
}
