#include "sort.h"

/**
 * swap - function to swap two integers
 * @a: first int
 * @b: second int
 *
 * Return: 0
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partition through an array of ints
 * @array: arr to be partitioned
 * @size : array size
 * @low: starting index of the partition
 * @high: ending index of the partition
 *
 * Return: index of the pivot element after partitioning
*/

int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high], a = low, b;

	for (b = low; b <= high - 1; b++)
	{
		if (array[b] < pivot)
		{
			if (a != b)
			{
				swap(&array[a], &array[b]);
				print_array(array, size);
			}
			a++;
		}
	}
	if (pivot != array[a])
	{
		swap(&array[a], &array[high]);
		print_array(array, size);
	}
	return (a);
}

/**
 * quick_sort_helper - recursive sort
 * @array: arr to be partitioned
 * @size : array size
 * @low: starting index of the partition
 * @high: ending index of the partition
 *
 * Return: index of the pivot element after partitioning
 */

void quick_sort_helper(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, size, low, high);
		quick_sort_helper(array, size, low, pivot_idx - 1);
		quick_sort_helper(array, size, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - sort an arr of ints in ascending order
 * @array: arr
 * @size : array size
 *
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_helper(array, size, 0, size - 1);
}
