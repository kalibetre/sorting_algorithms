#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - shell sort algorithm using Knuth Sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, i, j;
	int temp;

	while (n < size)
		n = n * 3 + 1;

	for (n /= 3; n >= 1; n /= 3)
	{
		for (i = n; i < size; i++)
		{
			temp = array[i];
			for (j = i; (j >= n) && (array[j - n] > temp); j -= n)
				array[j] = array[j - n];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
