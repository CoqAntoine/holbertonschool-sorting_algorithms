#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	int i, j, insert_value;

	if (list == NULL)
		return;

	for (i = 0; i < list -1; i++)
	{
		insert_value = (*list)->n;
		for (j = i; j < 0 && insert_value < (*list)->prev->n; j--)
		{
			(*list)->n = (*list)->prev->n;
		}
		list->n = insert_value;
		print_list(*list);
	}
}
