#include "sort.h"

/**
 * swap - Entry point
 * @x: ele
 * @y: ele
 * Return: Always
 */

void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}


/**
 * shell_sort - Entry point
 * @a: arr
 * @size: size
 * Return: Always 0
 */

void shell_sort(int *a, size_t size)
{
	size_t gap = 1, i, j;

	if (!a || !size)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap ; i < size ; i++)
		{
			for (j = i ; j >= gap ;)
			{
				if (a[j - gap] > a[j])
				{
					swap(&a[j - gap], &a[j]);
					j -= gap;
				}
			}
		}
		gap /= 3;
		print_array(a, size);
	}

}
