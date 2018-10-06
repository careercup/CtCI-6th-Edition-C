#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b)	(((a) < (b)) ? (a) : (b))
#define MAX(a, b)	(((a) > (b)) ? (a) : (b))

int magic_index_helper(int *arr, int start, int end)
{
	int mid, left, left_index, right_index;

	if (end < start)
		return -1;

	mid = (start + end) / 2;
	if (arr[mid] == mid)
		return mid;

	left_index = MIN(mid - 1, arr[mid]);
	left = magic_index_helper(arr, start, left_index);
	if (left >= 0)
		return left;

	right_index = MAX(mid + 1, arr[mid]);
	return magic_index_helper(arr, right_index, end);
}

int magic_index(int *arr, int arr_size)
{
	return magic_index_helper(arr, 0, arr_size - 1);
}

int magic_index_helper_distinct(int *arr, int start, int end)
{
	int mid;

	if (end < start)
		return -1;

	mid = (start + end) / 2;
	if (arr[mid] == mid)
		return mid;
	else if (arr[mid] > mid)
		return magic_index_helper_distinct(arr, start, mid - 1);
	else
		return magic_index_helper_distinct(arr, mid + 1, end);
}

int magic_index_distinct(int *arr, int arr_size)
{
	return magic_index_helper_distinct(arr, 0, arr_size - 1);
}

int main(void)
{
	int arr[] = { -10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13 };
	int arr_size = sizeof(arr) / sizeof(int);
	int arr_distinct[] = { -10, -5, -2, 1, 2, 3, 4, 7, 9, 12, 13 };
	int arr_size_distinct = sizeof(arr_distinct) / sizeof(int);
	int i;

	printf("distinct array: ");
	for (i = 0; i < arr_size_distinct; i++)
		printf("%d, ", arr_distinct[i]);
	printf("\n");
	printf("magic index distinct: %d.\n", magic_index_distinct(arr_distinct, arr_size_distinct));

	printf("array: ");
	for (i = 0; i < arr_size; i++)
		printf("%d, ", arr[i]);
	printf("\n");
	printf("magic index: %d.\n", magic_index(arr, arr_size));

	return 0;
}

