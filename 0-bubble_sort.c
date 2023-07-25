#include "sort.h"

/**
 * bubble_sort - sorts an arr of ints in ascending order
 * @array: Pointer to the array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		swapped = 0;
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			/*swap the elements*/
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
	if (swapped == 0)
		return;
}
