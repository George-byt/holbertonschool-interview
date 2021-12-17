#include "lists.h"
#include <stdlib.h>
/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: inserts a number into a sorted singly linked list or
 * NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	(*new).n = number;
	(*new).next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		for (current = *head; current != NULL; current = (*current).next)
		{
			if (current == *head)
			{
				if (number < (*current).n)
				{
					(*new).next = *head;
					*head = new;
					return (*head);
				}
			}
			else if ((*current).next == NULL)
			{
				(*current).next = new;
				return (*head);
			}

			if (number < (*(*current).next).n)
			{
				(*new).next = (*current).next;
				(*current).next = new;
				return (*head);
			}
		}
	}
	return (NULL);
}
