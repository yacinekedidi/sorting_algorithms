#include "sort.h"



/**
 * selection_sort - Entry point
 * @a: array
 * @size: size
 * Return: Always
 */

void selection_sort(int *a, size_t size)
{
	size_t i, j, min;
	int tmp, x, f;

	if (!a || !size)
		return;

	for (i = 0 ; i < size - 1 ; i++)
	{
		x = a[i];
		min = i;
		f = 0;
		for (j = i + 1 ; j < size ; j++)
		{
			if (a[j] < x)
			{
				min = j;
				x = a[j];
				f++;
			}
		}
		if (f > 0)
		{
			tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
			print_array(a, size);
		}
	}
}
