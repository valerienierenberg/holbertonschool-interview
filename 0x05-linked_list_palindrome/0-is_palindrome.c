#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* is_palindrome - checks if a singly linked list is a palindrome
* @head: pointer to head of linked list
* empty list is considered a palindrome
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/

int is_palindrome(listint_t **head)
{
	if (!*head)
		return (1);
	return (pal_meat(head, *head));
}


/**
* pal_meat - helper function to check if list is palindrome
* @left: start of list
* @right: end of list
* empty list is considered a palindrome
* Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/

int pal_meat(listint_t **left, listint_t *right)
{
	/* if the list is empty */
	if (!right)
		return (1);
	/* recurse thru list checking if nodes are present and values are equal */
	if (pal_meat(left, right->next) && (*left)->n == right->n)
	{
		/* traverse through the list */
		*left = (*left)->next;
		/* is palindrome if successfully passes checks all the way through */
		return (1);
	}
	/* not a palindrome */
	else
		return (0);
}
