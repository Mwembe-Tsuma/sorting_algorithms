#include "sort.h"

int hoare_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);

/**
 * hoare_partition - partitions an array
 * @array: array to be partitioned
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: array size
 *
 * Return: Partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], temp;
	size_t a, b;

	a = low - 1;
	b = high + 1;

	while (1)
	{
		do {
			a++;
		} while (array[a] < pivot);
		do {
			b--;
		} while (array[b] > pivot);
		if (a >= b)
			return (a);
		if (a != b)
		{
			temp = array[a];
			array[a] = array[b];
			array[b] = temp;
			print_array(array, size);
		}
	}
	return (0);
}

/**
 * quick_sort_recursive - sorts an arr of ints in ascending order
 * @array: array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: array size
 *
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = hoare_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_idx - 1, size);
		quick_sort_recursive(array, pivot_idx, high, size);
	}
}

/**
 * quick_sort_hoare - function to sort an array using quick sort algo
 * @array: Pointer to the array
 * @size: array size
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_recursive(array, 0, (int)size - 1, size);
}
