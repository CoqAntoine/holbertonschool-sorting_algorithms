#include <stdio.h>
#include "sort.h"

/**
 * switch_sort - change 2 nodes in a doubly linked list
 * @list: pointer to the start of the list
 * @node1: pointer to the first node to change.
**/
void switch_sort_insert(listint_t **list, listint_t *node1)
{
	listint_t *node2 = node1->next;

	if (!node1 || !node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert_node;
	int insert_value;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	i = (*list)->next;

	while (i != NULL)
	{
		insert_node = i;
		insert_value = i->n;

		while (insert_node->prev && insert_value < insert_node->prev->n)
		{
			switch_sort_insert(list, insert_node->prev);
			print_list(*list);
		}

		i = i->next;
	}
}
