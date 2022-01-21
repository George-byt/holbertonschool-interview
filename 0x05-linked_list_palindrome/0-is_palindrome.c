#include "lists.h"
#include <stdlib.h>
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 *
 * Description: checks if a singly linked list is a palindrome.
 */
int is_palindrome(listint_t **head)
{
  listint_t *iterate;
  int i, j, len;
  int nums[100000];

  if (head == NULL)
    return (0);

  if (*head == NULL)
    return (1);

  i = 0;
  for (iterate = *head; iterate != NULL; iterate = (*iterate).next)
    {
      nums[i] = (*iterate).n;
      i++;
    }

  len = i;
  i--;
  for (j = 0; j < len; j++, i--)
    {
      if (nums[j] != nums[i])
	return (0);
    }
  return (1);
}
