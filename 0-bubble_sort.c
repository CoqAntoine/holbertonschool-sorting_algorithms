#include <stdio.h>
#include "sort.h"

/**
 * switch_sort - function to switch 2 elements of the array
 * @array: pointer to the first index of the array
 * @i: first elemment
 * @j: second element
 * Return: the array with the elements switched
 */
int *switch_sort(int *array, size_t i, size_t j)
{
	size_t temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;

	return (array);
}

/**
 * bubble_sort - function to sort with the bubble method
 * @array: pointer to the first index of the array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
				switch_sort(array, j, j + 1);
		}
	}
}
