#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sorted_merge(int *arr_a, int size_a, int *arr_b, int size_b)
{
	int index_a = size_a - 1;
	int index_b = size_b - 1;
	int index_merged = size_a + size_b - 1;

	while (index_b >= 0) {
		if (index_a >= 0 && arr_a[index_a] > arr_b[index_b]) {
			arr_a[index_merged] = arr_a[index_a];
			index_a--;
		} else {
			arr_a[index_merged] = arr_b[index_b];
			index_b--;
		}
		index_merged--;
	}
}

int main(void)
{
	int arr_a[] = { 1, 2, 3, 34, 37, 49, 82, 130, -1 , -1, -1, -1, -1, -1 };
	int arr_b[] = { 4, 7, 39, 72, 123, 150 };
	int size_b = sizeof(arr_b) / sizeof(int);
	int i, size_a;

	printf("array a: ");
	for (i = 0; arr_a[i] != -1; i++)
		printf("%d ", arr_a[i]);
	printf("\b.\n");
	size_a = i;

	printf("array b: ");
	for (i = 0; i < size_b; i++)
		printf("%d ", arr_b[i]);
	printf("\b.\n");

	sorted_merge(arr_a, size_a, arr_b, size_b);
	printf("sorted array: ");
	for (i = 0; i < size_a + size_b; i++)
		printf("%d ", arr_a[i]);
	printf("\b.\n");

	return 0;
}

