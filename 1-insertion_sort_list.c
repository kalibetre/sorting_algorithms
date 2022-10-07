#include "sort.h"

/**
 * insertion_sort_list - sorts a list using insertion algorithm
 * @list: the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp_1, *temp_2;

	if (list != NULL && *list != NULL)
	{
		node = (*list)->next;
		while (node != NULL)
		{
			temp_1 = node;
			node = node->next;
			while (temp_1->prev != NULL && temp_1->prev->n > temp_1->n)
			{
				temp_2 = temp_1->prev;
				temp_2->next = temp_1->next;
				temp_1->prev = temp_2->prev;

				if (temp_2->prev != NULL)
					temp_2->prev->next = temp_1;
				if (temp_1->next != NULL)
					temp_1->next->prev = temp_2;

				temp_1->next = temp_2;
				temp_2->prev = temp_1;

				if (temp_1->prev == NULL)
					*list = temp_1;

				print_list(*list);
			}
		}
	}
}
