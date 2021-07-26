#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
* add_nodeint- adds a new node at the beginning of a listint_t list
* @n: int
* @head: first node
* Return: the address of the new element, or NULL if it failed
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));

	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = *head;

	*head = newnode;

return (newnode);
}

/**
* insert_nodeint_at_index - Function that inserts a
* new node at a given position.
* @head: double pointer
* @idx: int index
* @n: n value
* Return: the address of the new node, or NULL if it failed
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *cpy = *head;
	listint_t *new;
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
		return (add_nodeint(head, n));

	new = malloc(sizeof(listint_t));
		if (new == NULL)
		return (NULL);

	while (cpy != NULL)
	{
		if ((idx - 1) == i)
	{
		new->n = n;
		new->next = cpy->next;
		cpy->next = new;
		return (new);
	}
	cpy = cpy->next;
	i++;
}
return (NULL);
}
