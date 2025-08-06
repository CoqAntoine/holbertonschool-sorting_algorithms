#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    int i, j;
    int valeur_insertion;
    listint_t **temp = **list;

	if (list == NULL)
		return;

	for (i = 0; list != NULL; i++)
	{
        temp = temp->next;
        valeur_insertion = (*list)->n;
		for (j = i; j > 0 && valeur_insertion < (*list)->prev->n; j--)
		{

            print_list(list);
		}
	}
}
