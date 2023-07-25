#include "sort.h"

/**
  *counting_sort- Function to sort array of intergers
  *using counting sort algorithm
  *
  *@array; The array of integers
  *@size: The size
  */

void counting_sort(int *array, size_t size)
{
	int idx, maximum, temp;
	int *counter, *results;

	if (!array || size < 2)
		return;

	maximum = array[0];
	for (idx = 0; idx < (int)size; idx++)
	{
		if (array[idx] > maximum)
			maximum = array[idx];
	}
	counter = calloc((maximum + 1), sizeof(int));
	if (!counter)
		return;
	for (idx = 0; idx < (int)size; idx++)
		counter[array[idx]]++;

	for (idx = 0, temp = 0; idx < maximum + 1;  idx++)
	{
		temp = counter[idx] + temp;
		counter[idx] = temp;
	}
	print_array(counter, maximum +1);
	results = malloc(sizeof(int) * size);
	if (!results)
		return;

	for (idx = 0; idx < (int)size; idx++)
	{
		results[counter[array[idx]] - 1] = array[idx];
		counter[array[idx]]--;
	}
	for (idx = 0; idx < (int)size; idx++)
		array[idx] = results[idx];
	free(counter);
	free(results);
}
