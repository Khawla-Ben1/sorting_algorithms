#include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
    int smallest, temp;
    size_t i, j;

    if (!array || size < 2)
        return;

    i = 0;
    while (i < size - 1)
    {
        smallest = i;
        j = i + 1;
        while (j < size)
        {
            if (array[j] < array[smallest])
                smallest = j;
            j++;
        }
        if (smallest != (int)i)
        {
            temp = array[i];
            array[i] = array[smallest];
            array[smallest] = temp;
            print_array(array, size);
        }
        i++;
    }
}
