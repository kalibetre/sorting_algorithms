#include "sort.h"

/**
 * selection_sort - sorts an array using the selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (array != NULL && size > 1)
	{
		for (i = 0; i < size; i++)
		{
			min_idx = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[min_idx] > array[j])
					min_idx = j;
			}
			if (min_idx != i)
			{
				temp = array[min_idx];
				array[min_idx] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
