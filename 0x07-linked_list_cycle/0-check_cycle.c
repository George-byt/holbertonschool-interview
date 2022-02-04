#include "lists.h"
/**
 * check_cycle - Function that finds a loop in a linked list.
 * @list: Single linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
listint_t *falcon = list;
listint_t *turtle = list;

if (!list)
return (0);

while (falcon->next && falcon && turtle)
{
turtle = turtle->next;
falcon = falcon->next;
if (!falcon->next)
return (0);
falcon = falcon->next;
if (falcon == turtle)
return (1);
}
return (0);
}
