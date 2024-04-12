#include "lists.h"
/**
  * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
  * @head: the head of the dlistint_t lst
  * @index: the node to be located
  * Return: address of the located node otherwise NULL
  */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
