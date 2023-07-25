#include "sort.h"

/**
 * countSort - function to do counting sort
 * @array: The array
 * @size: array size
 * @digit_exp: least significant digit
 */
void countSort(int *array, size_t size, size_t digit_exp)
{
	int count[10] = {0}, *output;
	int left, max_elem;
	size_t a, arr_size;

	output = malloc(sizeof(int) * size);

	for (a = 0; a < size; a++)
		count[(array[a] / digit_exp) % 10]++;
	for (left = 1; left < 10; left++)
		count[left] += count[left - 1];
	for (max_elem = size - 1; max_elem >= 0; max_elem--)
	{
		output[count[(array[max_elem] / digit_exp) % 10] - 1] = array[max_elem];
		count[(array[max_elem] / digit_exp) % 10]--;
	}
	for (arr_size = 0; arr_size < size; arr_size++)
		array[arr_size] = output[arr_size];
	free(output);
}

/**
 * radix_sort - radix sort function
 * @array: the array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_elem;
	size_t a, digit_exp;

	if (!array || size < 2)
		return;

	max_elem = 0;
	for (a = 0; a < size; a++)
		if (array[a] > max_elem)
			max_elem = array[a];
	for (digit_exp = 1; max_elem / digit_exp > 0; digit_exp *= 10)
	{
		countSort(array, size, digit_exp);
		print_array(array, size);
	}
}
