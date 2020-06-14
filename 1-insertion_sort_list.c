#include "sort.h"

/**
 * swap - Entry point
 * @back: node
 * @current: node
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
 * insertion_sort_list - Entry point
 * @list: head
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop, *current;


	if (!*list || !list || !(*list)->next)
		return;
	loop = (*list)->next;

	while (loop)
	{
		current = loop;
		loop = loop->next;
		while (current && current->prev)
		{

			if (current->prev->n > current->n)
			{
				swap(current->prev, current);
				if (!current->prev)
					*list = current;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
