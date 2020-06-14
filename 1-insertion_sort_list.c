#include "sort.h"

/**
 * insertion_sort_list - Entry point
 * @list: head
 * Return: Always
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop, *back, *tmp, *current;


	if (!*list)
		return;
	loop = (*list)->next;

	while (loop)
	{
		current = loop;
		loop = loop->next;
		back = current->prev;
		while (back)
		{
			tmp = back->prev;
			if (back->n > current->n)
			{
				if (back->prev)
					back->prev->next = current;
				if (current->next)
					current->next->prev = back;
				back->next = current->next;
				current->prev = back->prev;
				back->prev = current;
				current->next = back;
				if (!current->prev)
					*list = current;
				print_list(*list);
			}
			back = tmp;
		}
	}
}
