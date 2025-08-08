#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - sort with quick sort
 * @array: pointer to the first index of the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    size_t i, j;
	int index = 0, temp = 0, changement = 0;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		changement = 0;
		temp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (temp > array[j])
			{
				temp = array[j];
				index = j;
				changement = 1;
			}
		}
		if (changement == 1)
		{
			array[index] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
