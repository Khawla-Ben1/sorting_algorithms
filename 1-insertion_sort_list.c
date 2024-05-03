#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *temp;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->prev;

        while (temp != NULL && temp->n > current->n)
        {
            if (temp->prev != NULL)
                temp->prev->next = current;
            if (current->next != NULL)
                current->next->prev = temp;

            temp->next = current->next;
            current->prev = temp->prev;

            current->next = temp;
            temp->prev = current;

            if (current->prev == NULL)
                *list = current;

            print_list(*list);
            temp = current->prev;
        }
        current = current->next;
    }
}
