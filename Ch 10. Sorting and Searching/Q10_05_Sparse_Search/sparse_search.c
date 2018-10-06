#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char *s[], int size, const char *t)
{
	int first = 0;
	int last = size - 1;

	if (!s || !t || !strcmp(t, ""))
		return -1;

	while (first <= last) {
		/* Move mid to the middle */
		int mid = (last + first) / 2;

		/* If mid is empty, find closest non-empty string */
		if (!strcmp(s[mid], "")) { 
			int left = mid - 1;
			int right = mid + 1;
			while (1) {
				if (left < first && right > last) {
					return -1;
				} else if (right <= last && strcmp(s[right], "")) {
					mid = right;
					break;
				} else if (left >= first && strcmp(s[left], "")) {
					mid = left;
					break;
				}
				right++;
				left--;
			}
		}

		int res = strcmp(s[mid], t);
		if (res == 0) // Found it!
			return mid;
		else if (res < 0) // Search right
			first = mid + 1;
		else // Search left
			last = mid - 1;
	}

	return -1;
}

int main(void)
{
	char *s[14] = { "apple", "", "", "banana", "", "", "", "carrot", "duck", "", "", "eel", "", "flower" };

	printf("searching 'ac': %d.\n", search(s, 14, "ac"));
	printf("searching 'apple': %d.\n", search(s, 14, "apple"));
	printf("searching 'banana': %d.\n", search(s, 14, "banana"));
	printf("searching 'duck': %d.\n", search(s, 14, "duck"));
	printf("searching 'flower': %d.\n", search(s, 14, "flower"));

	return 0;
}

