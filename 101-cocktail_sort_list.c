#include "sort.h"

/**
 * swap - Entry point
 * @back: a
 * @current: b
 * Return: Always
 */

void swap(listint_t *back, listint_t *current)
{
	if (back->prev)
		back->prev->next = current;
	if (current->next)
		current->next->prev = current->prev;
	back->next = current->next;
	current->prev = back->prev;
	back->prev = current;
	current->next = back;
}

/**
 * cocktail_sort_list - Entry point
 * @list: l
 * Return: Always
 */

void cocktail_sort_list(listint_t **list)
{
	int x;
	listint_t *loop, *h;

	if (!list || !*list || !(*list)->next)
		return;
	while (1)
	{ x = 0;
		loop = *list;
		while (loop->next)
		{
			if (loop->n > loop->next->n)
			{
				swap(loop, loop->next);
				if (!loop->prev->prev)
					*list = loop->prev;
				x = 1;
				print_list(*list);
			} else
				loop = loop->next;

		}
		while (loop->prev)
		{
			if (loop->n < loop->prev->n)
			{
				swap(loop->prev, loop);
				if (!loop->prev)
					*list = loop;
				print_list(*list);
				x = 1;
			}
			else
				loop = loop->prev;
			if (!loop->prev)
				h = loop;
		}
		*list = h;
		if (x == 0)
			break;
	}
}
