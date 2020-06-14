#include "sort.h"



/**
 * swap - Entry point
 * @a: arr
 * @x: int
 * @y: int
 * Return: Always
 */
void swap(int *a, int x, int y)
{
	int tmp;

	tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;

}

/**
 * partition - Entry point
 * @a: arr
 * @left: int
 * @right: int
 * @size: int
 * Return: Always 0
 */

int partition(int *a, int left, int right, int size)
{
	int pivot = right, i, j;

	for (i = j = left ; j < right ; j++)
	{

		if (a[j] < a[pivot])
		{
			if (i < j)
			{
				swap(a, j, i);
				print_array(a, size);

			}
			i++;
		}
	}
	if (a[i] > a[pivot])
	{
		swap(a, i, pivot);
		if (i != pivot)
			print_array(a, size);
	}
	return (i);
}

/**
 * qs - Entry point
 * @a: arr
 * @left: int
 * @right: int
 * @size: int
 * Return: Always 0
 */
void qs(int *a, int left, int right, int size)
{
	int index;

	if (right > left)
	{
	index = partition(a, left, right, size);
	qs(a, left, index - 1, size);
	qs(a, index + 1, right, size);
	}
}



/**
 * quick_sort - Entry point
 * @a: arr
 * @size: int
 * Return: Always 0
 */
void quick_sort(int *a, size_t size)
{

	if (!a || !size)
		return;

	qs(a, 0, size - 1, size);

}
