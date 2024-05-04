#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Cocktail shaker sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *left, *right, *current;

    if (list == NULL || *list == NULL)
        return;
    do {
        swapped = 0;
        for (left = *list; left->next != NULL; left = left->next)
        {
            if (left->n > left->next->n)
            {
                swapped = 1;
                if (left->prev != NULL)
                    left->prev->next = left->next;
                else
                    *list = left->next;
                left->next->prev = left->prev;
                left->prev = left->next;
                left->next = left->next->next;
                left->prev->next = left;
                if (left->next != NULL)
                    left->next->prev = left;
                print_list(*list);
                printf("\n");
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (right = left->prev; right != NULL; right = right->prev)
        {
            if (right->prev != NULL && right->n < right->prev->n)
            {
                swapped = 1;
                if (right->next != NULL)
                    right->next->prev = right->prev;
                right->prev->next = right->next;
                right->next = right->prev;
                right->prev = right->prev->prev;
                right->next->prev = right;
                if (right->prev != NULL)
                    right->prev->next = right;
                else
                    *list = right;
                print_list(*list);
                printf("\n");
            }
        }
    }
    while (swapped);
}
