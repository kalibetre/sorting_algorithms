#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_array_limit - prints array between bounds
 * @array: the array
 * @low: lower limit
 * @high: upper limit
 */
void print_array_limit(int *array, size_t low, size_t high)
{
	size_t i;

	i = low;
	while (array && i < high)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * merge_arry - merges the two halfs of a merge sort sub arrays
 * @array: the array
 * @cpy_array: copy of the array
 * @low: lower bound
 * @m: middle bound
 * @high: upper bound
 */
void merge_arry(int *array, int *cpy_array, size_t low, size_t m, size_t high)
{
	size_t k, i = low, j = m;

	printf("Merging...\n");
	printf("[left]: ");
	print_array_limit(array, low, m);
	printf("[right]: ");
	print_array_limit(array, m, high);

	for (k = low; k < high; k++)
	{
		if (i < m && (j >= high || array[i] <= array[j]))
		{
			cpy_array[k] = array[i];
			i++;
		}
		else
		{
			cpy_array[k] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array_limit(cpy_array, low, high);
}

/**
 * merge_sort_rec - runs a merge sort recursively
 * @cpy_array: copy of the array
 * @array: the array
 * @low: lower bound
 * @high: upper bound
 */
void merge_sort_rec(int *cpy_array, int *array, size_t low, size_t high)
{
	size_t m;

	if (high - low <= 1)
		return;

	m = (low + high) / 2;

	merge_sort_rec(array, cpy_array, low, m);
	merge_sort_rec(array, cpy_array, m, high);
	merge_arry(cpy_array, array, low, m, high);
}

/**
 * merge_sort - sorts an array using merge sort algo impl
 * @array: the array
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *cpy_array;
	size_t i;

	if (array == NULL || size < 2)
		return;

	cpy_array = malloc(sizeof(int) * size);
	if (cpy_array == NULL)
		return;
	for (i = 0; i < size; i++)
		cpy_array[i] = array[i];

	merge_sort_rec(cpy_array, array, 0, size);
	free(cpy_array);
}
