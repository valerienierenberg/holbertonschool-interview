#include "palindrome.h"

/**
* is_palindrome- checks whether or not a given unsigned int is a palindrome
* @n: unsigned long int
* Return: 1 if n is a palindrome, otherwise 0
*/

int is_palindrome(unsigned long n)
{
	unsigned long r, sum, temp;

	sum = 0;
	temp = n;

	while (n > 0)
	{
		r = n % 10;
		sum = (sum * 10) + r;
		n = n / 10;
	}
	if (temp == sum)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
