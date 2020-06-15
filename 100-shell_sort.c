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
 * @array: arr
 * @size: size
 * Return: Always 0
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (!array || size < 2)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;

	for (; gap >= 1 ; gap /= 3)
	{
		for (i = gap ; i < size ; i++)
		{
			for (j = i ; j >= gap && array[j - gap] > array[j] ;)
			{
				swap(&array[j - gap], &array[j]);
				j -= gap;
			}
		}
		print_array(array, size);
	}

}
