#include "sort.h"

void swap(int *x, int *y);
void max_heap(int *array, size_t size, int index, size_t n);

/**
  *swap- Swaps two ints
  *@x: First int
  *@y: Second int
  *
  */

void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
  *max_heap- Function to heapify a maximum heap
  *@size: Size of array
  *@index: the index
  *@array: the array
  *@n: size of array to run
  *
  */

void max_heap(int *array, size_t size, int index, size_t n)
{
	int max = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < (int)n && array[left] > array[max])
		max = left;

	if (right < (int)n && array[right] > array[max])
		max = right;

	if (max != index)
	{
		swap(&array[index], &array[max]);
		print_array(array, size);
		max_heap(array, size, max, n);
	}
}

/**
  *heap_sort- Heap sort algorith
  *@array: The array to sort
  *@size: the sizw
  *
  */
void heap_sort(int *array, size_t size)
{
	int idx;

	if (!array || size < 2)
		return;

	for (idx = (size - 2) / 2; idx >= 0; --idx)
		max_heap(array, size, idx, size);

	for (idx = (size - 1); idx > 0; --idx)
	{
		swap(&array[0], &array[idx]);
		print_array(array, size);

		max_heap(array, size, 0, idx);
	}
}
