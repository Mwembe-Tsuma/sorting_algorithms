#include "sort.h"

void bitonic_merge(int *arr, int lt, int rt, int direction);
void bitonic_recursive_sort(
	int *arr, int lt, int rt, int direction, size_t size);

/**
 * bitonic_sort - function to sort an array of ints using bitonic sort
 * @array: Pointer to the arr
 * @size: Size of the array
 *
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursive_sort(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursive_sort - sorts a sub array recursively
 * @arr: Pointer to the array
 * @lt: left index of the sub array
 * @rt: right index of the sub array
 * @direction: flag to show the sorting direction
 * @size: array size
 *
 */
void bitonic_recursive_sort(
	int *arr, int lt, int rt, int direction, size_t size)
{
	int mid_idx;

	if (rt - lt >= 1)
	{
		mid_idx = (rt + lt) / 2;

		printf("Merging [%d/%lu] ", rt - lt + 1, size);

		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");

		print_array(arr + lt, rt - lt + 1);
		bitonic_recursive_sort(arr, lt, mid_idx, 1, size);
		bitonic_recursive_sort(arr, mid_idx + 1, rt, 0, size);
		bitonic_merge(arr, lt, rt, direction);

		printf("Result [%d/%lu] ", rt - lt + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");

		print_array(arr + lt, rt - lt + 1);
	}
}

/**
 * bitonic_merge - function to perfom bitonic merge on an arr
 * @arr: pointer to the array
 * @lt: left index of the sub-array
 * @rt: right index of the sub-array
 * @direction: flag to indicate merge direction
 *
 * Return: void
 */
void bitonic_merge(int *arr, int lt, int rt, int direction)
{
	int temp, a, mid_point = (lt + rt) / 2, mid = (rt - lt + 1) / 2;

	if (rt - lt >= 1)
	{
		for (a = lt; a < lt + mid; a++)
		{
			if (direction == (arr[a] > arr[a + mid]))
			{
				temp = arr[a + mid];
				arr[a + mid] = arr[a];
				arr[a] = temp;
			}
		}

		bitonic_merge(arr, lt, mid_point, direction);
		bitonic_merge(arr, mid_point + 1, rt, direction);
	}
}

