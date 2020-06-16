#include "sort.h"


/**
 * counting_sort - Entry point
 * @array: arr
 * @size: s
 * Return: Always 0
 */
void counting_sort(int *array, size_t size)
{
	int *a, max = array[0], j, *b;
	size_t i;

	if (!array || size < 2)
		return;
	i = 0;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	} a = malloc(sizeof(int) * (max + 1));
	if (!a)
		return;
	for (j = 0 ; j < (max + 1) ; j++)
		a[j] = 0;
	for (i = 0 ; i < size ; i++)
		a[array[i]] += 1;

	for (j = 0 ; j < (max + 1) ; j++)
		a[j] += a[j - 1];
	print_array(a, max + 1);
	b = malloc(sizeof(int) * size);
	if (!b)
	{
		free(a);
		return;
	}
	for (i = 0 ; i < size ; i++)
	{
		b[a[array[i]] - 1] = array[i];
		a[array[i]] -= 1;
	}
	for (i = 0 ; i < size ; i++)
		array[i] = b[i];
	free(a);
	free(b);
}
