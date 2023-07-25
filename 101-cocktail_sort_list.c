#include "sort.h"

listint_t *swap(listint_t *node, listint_t **list);

/**
  *swap- Swaps two nodes
  *@node: The node
  *@list: The lsit
  *
  *Return: A pointer to the swapped node
  */

listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *previous = node->prev, *curr = node;

	previous->next = curr->next;
	if (curr->next)
		curr->next->prev = previous;
	curr->next = previous;
	curr->prev = previous->prev;
	previous->prev = curr;

	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}

/**
  *cocktail_sort_list- sorts a doubly linked list of ints in ascending
  *order using the Cocktail sort algorithm
  *
  *@list: The list of integers
  *
  */

void cocktail_sort_list(listint_t **list)
{
	listint_t *newNode;
	int swaps = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	newNode = *list;
	while (swaps == 1)
	{
		swaps = 0;
		while (newNode->next)
		{
			if (newNode->n > newNode->next->n)
			{
				newNode = swap(newNode->next, list);
				swaps = 1;
				print_list(*list);
			}
			newNode = newNode->next;
		}
		if (swaps == 0)
			break;
		swaps = 0;
		while (newNode->prev)
		{
			if (newNode->n < newNode->prev->n)
			{
				newNode = swap(newNode, list);
				swaps = 1;
				print_list(*list);
			}
			else
				newNode = newNode->prev;
		}
	}
}
