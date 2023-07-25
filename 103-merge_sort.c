#include "sort.h"

void print_arr(int *array, int Beg, int End);
void copy_array(int *src, int Beg, int End, int *dest);
void top_merge(int *src, int Beg, int Mid, int End, int *dest);
void top_split_merge(int *src, int Beg, int End, int *dest);

/**
  *print_arr- Prints array of ints
  *@array: The array
  *@Beg: starting index
  *@End: Ending index
  */

void print_arr(int *array, int Beg, int End)
{
	int idx;

	for (idx = Beg; idx < End; idx++)
		if (idx < End - 1)
			printf("%i, ", array[idx]);
		else
			printf("%i\n", array[idx]);
}
/**
  *copy_array- Copies array from source to destination
  *@src: source array
  *@Beg: starting index
  *@End: Ending index
  *@dest: The destination array
  */
void copy_array(int *src, int Beg, int End, int *dest)
{
	int idx;

	for (idx = Beg; idx < End; idx++)
		dest[idx] = src[idx];
}

/**
  *top_merge- Sorts sublist by ascending order
  *@src: source array
  *@Beg: left run starting index
  *@End: right run ending index
  *@Mid: left run starting index
  *@dest: The destination array
  */

void top_merge(int *src, int Beg, int Mid, int End, int *dest)
{
	int idx, x, y;

	idx = Beg, x = Mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_arr(src, Beg, Mid);
	printf("[right]: ");
	print_arr(src, Mid, End);
	for (y = Beg; y < End; y++)
	{
		if (idx < Mid && (x >= End || src[idx] <= src[x]))
		{
			dest[y] = src[idx];
			idx++;
		}
		else
		{
			dest[y] = src[x];
			x++;
		}
	}
	printf("[Done]: ");
	print_arr(dest, Beg, End);
}

/**
  *top_split_merge- Split and merge function
  *@Beg: Begining index
  *@src: Source array
  *@End: Ending index
  *@dest:Destination array
  */

void top_split_merge(int *src, int Beg, int End, int *dest)
{
	int Mid;

	if (End - Beg < 2)
		return;
	Mid = (End + Beg) / 2;

	top_split_merge(dest, Beg, Mid, src);
	top_split_merge(dest, Mid, End, src);
	top_merge(src, Beg, Mid, End, dest);
}
/**
  *merge_sort - Sorts array of ints using marge sort
  *@array: The array
  *@size: The size
  *
  */
void merge_sort(int *array, size_t size)
{
	int *copy;

	if (!array || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;

	copy_array(array, 0, size, copy);
	top_split_merge(copy, 0, size, array);

	free(copy);
}
