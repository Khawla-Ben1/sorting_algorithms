#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		insertion_point = current->prev;

		while (insertion_point != NULL && temp->n < insertion_point->n)
		{
			if (insertion_point->prev != NULL)
				insertion_point->prev->next = temp;
			temp->prev = insertion_point->prev;
			insertion_point->prev = temp;
			insertion_point->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = insertion_point;
			temp->next = insertion_point;

			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);

			insertion_point = temp->prev;
		}
		current = current->next;
	}
}
