#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
* insert_node- adds a new node at the beginning of a listint_t list
* @number: int to insert in sorted position
* @head: first node
* Return: the address of the new node, or NULL if it failed
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *p1, *p2, *p;

	p1 = NULL;
	p2 = *head;  /* p2 points to first node */
	for (; p2->n < number; p2 = p2->next)
	{
		p1 = p2;
		if (p2->next == NULL)
		{
			p2 = p2->next;   /* insertion at end */
			break;
		}
	}
	/* key node found and insert new node */
	p = malloc(sizeof(listint_t));  /* space for new node */
	p->n = number; /* place value in the new node */
	p->next = p2; /*link new node to key node */
	if (p1 == NULL)
		*head = p; /* new node becomes the first node */
	else
		p1->next = p; /* new node inserted in middle */
	return (*head);
}
