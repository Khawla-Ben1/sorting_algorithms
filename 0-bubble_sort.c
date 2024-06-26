#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using Bubble sort
 * @array: The array to be sorted
 * @size: Array's size
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, tmp1;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		tmp1 = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				tmp1 = 1;
				print_array(array, size);
			}
		}
		if (tmp1 == 0)
			break;
	}
}
