#include "lists.h"
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	dlistint_t *prev_node;
	dlistint_t *next_node;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		prev_node = (*head)->prev;   /* save prev before free */
		next_node = (*head)->next;   /* save next before free */
		prev_node->next = next_node; /* relink: prev->next skips deleted node */
		free(*head);
		if (next_node)
			next_node->prev = prev_node; /* relink: next->prev skips deleted node */
		*head = saved_head;
	}
	return (1);
}
