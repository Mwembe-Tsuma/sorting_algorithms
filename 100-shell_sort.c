#include "sort.h"

/**
  *shell_sort- Sorts arr of ints in ascending order using shell algorithm
  *@array: The arrays of integers
  *@size: The size
  *
  */

void shell_sort(int *array, size_t size)
{
	int idx, j, n, gap, max_knuth, tmp;

	if (array == NULL || size < 2)
		return;

	n = (int)size;
	for (gap = 1; gap < n; gap = (gap * 3) + 1)
	{
		max_knuth = gap;
	}
	for (gap = max_knuth; gap > 0; gap = (gap - 1) / 3)
	{
		for (idx = gap; idx < n; idx++)
		{
			tmp = array[idx];
			for (j = idx; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
