#include "sort.h"
#include <stdlib.h>

/**
 * max - returns the maximum element in the array
 * @array: the array
 * @size: the size of the array
 *
 * Return: returns the maximum value
 */
int max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - counting sort implementation
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t max_val;
	int *count_ary, *output;
	size_t j;

	if (array == NULL || size < 2)
		return;
	max_val = max(array, size);
	count_ary = malloc(sizeof(int) * (max_val + 1));
	if (count_ary == NULL)
		return;

	for (j = 0; j <= max_val; j++)
		count_ary[j] = 0;
	for (j = 0; j < size; j++)
		count_ary[array[j]]++;
	for (j = 1; j < (max_val + 1); j++)
		count_ary[j] += count_ary[j - 1];

	print_array(count_ary, max_val + 1);

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count_ary);
		return;
	}
	for (j = 0; j < size; j++)
	{
		output[count_ary[array[j]] - 1] = array[j];
		count_ary[array[j]]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(count_ary);
	free(output);
}
