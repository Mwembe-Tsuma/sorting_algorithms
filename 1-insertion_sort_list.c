#include "sort.h"

/**
  *insertion_sort_list- Insertion sort function
  *for a doubly linked list
  *@list: The list to sort
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *back, *newNode, *temp;

	if (list == NULL || (*list)->next == NULL)
		return;

	back = (*list);
	head = (*list)->next;
	while (head)
	{
		newNode = head->next;
		while (back && head->n < back->n)
		{
			if (back->prev)
				back->prev->next = head;
			else
				*list = head;
			if (head->next)
				head->next->prev = back;
			temp = head->next;
			head->next = back;
			head->prev = back->prev;
			back->next = temp;
			back->prev = head;

			print_list(*list);
			back = head->prev;
		}
		head = newNode;
		if (head)
			back = head->prev;
	}
}
