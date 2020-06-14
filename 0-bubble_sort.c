#include "sort.h"

/**
 * bubble_sort - Entry point
 * @array: array
 * @size: size
 * Return: Always
 */

void bubble_sort(int *array, size_t size)
{
size_t i, j, x;
int tmp;

if (!array || !size)
	return;

for (i = 0; i < size ; i++)
{
	x = 0;
	for (j = 0 ; j < size - 1 ; j++)
	{
		if (array[j] > array[j + 1])
		{
			x = 1;
			tmp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = tmp;
			print_array(array, size);
		}
	}
	if (x == 0)
		break;
}

}
