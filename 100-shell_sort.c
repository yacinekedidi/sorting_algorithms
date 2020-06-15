#include "sort.h"


/**
 * shell_sort - Entry point
 * @a: arr
 * @size: size
 * Return: Always 0
 */

void shell_sort(int *a, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (!a || !size)
		return;
	while (gap < (size / 3))
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap ; i < size ; i++)
		{
			for (j = i ; j >= gap && a[j - gap] > a[j] ; j -= gap)
			{
				tmp = a[j];
				a[j] = a[j - gap];
				a[j - gap] = tmp;
			}
		}
		gap /= 3;
		print_array(a, size);
	}

}
