#include <stdio.h>
#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @x: First integer to swap.
 * @y: Second integer to swap.
 *
 * Picture two kids trading Pok  mon cards  ^`^t they just swap them.
 * This function does exactly that but with numbers inside memory.
**/
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto - Lomuto partition scheme for quicksort.
 * @array: The array of integers to sort.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the full array.
 *
 * This is where the magic happens  ^`^t we pick the last element as
 * the 'pivot' and rearrange the array so that:
 * all numbers smaller than or equal to it are on the left,
 * and all the bigger numbers go on the right.
**/
int lomuto(int *array, int low, int high)
{
	int pivot_value = array[high];
	int i, j;

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return (i);
}

/**
 * quick_sort - Sort an array of integers in ascending order using quicksort.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * This is the 'party planner' - it sets everything up for quicksort
 * by calling the recursive function with the full array.
 * If the array is empty or has only one element, we just... do nothing.
 */
void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size -1, size);
}

/**
 * quicksort_recursion - Recursively sort an array using quicksort.
 * @array: The array of integers to sort.
 * @low: Starting index of the current partition.
 * @high: Ending index of the current partition.
 * @size: Size of the full array.
 *
 * Think of this like cutting a cake into smaller and smaller pieces
 * until all slices are perfectly sized. We use recursion to zoom into
 * each partition until it's so small (one element) that it's already 'sorted'.
**/
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto(array, low, high);

		print_array(array, size);

		quicksort_recursion(array, low, pivot_index -1, size);
		quicksort_recursion(array, pivot_index +1, high, size);
	}
}
