#include "sort.h"


/**
 * lomuto_partition - Implements Lomuto partition scheme
 * @array: The array to be partitioned
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: The size of the array
 *
 * Return: The index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    if (i + 1 != high)
        print_array(array, size);
    return (i + 1);
}

/**
 * quicksort - Implements quick sort recursively
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: The size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);

        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}
