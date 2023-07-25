#include "sort.h"

/**
  *selection_sort- Selection sort function
  *to sort array of ints in ascending order
  *@array: The array to sort
  *@size: The size
  */
void selection_sort(int *array, size_t size)
{
	int i, idx, min_idx, temp, n = (int)size;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (idx = i + 1; idx < n; idx++)
		{
			if (array[idx] < array[min_idx])
			{
				min_idx = idx;
			}
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
