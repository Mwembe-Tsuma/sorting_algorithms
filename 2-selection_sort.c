#include "sort.h"

/**
  *selection_sort- Selection sort function
  *@array: The array to sort
  *@size: The size
  */
void selection_sort(int *array, size_t size)
{
	int temp, swapped, flags = 0;
	size_t idx, i;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		flags = 0;
		for (idx = i + 1; idx < size; idx++)
		{
			if (array[temp] > array[idx])
			{
				temp = idx;
				flags += 1;
			}
		}
		swapped = array[i];
		array[i] = array[temp];
		array[temp] = swapped;

		if (flags != 0)
			print_array(array, size);
	}
}
