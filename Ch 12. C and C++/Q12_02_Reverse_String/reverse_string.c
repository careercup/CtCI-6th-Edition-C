#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN	256

size_t mystrlen(const char *s)
{
	size_t count;

	for (count = 0; s[count]; count++);
	return count;
}

void reverse(char *s)
{
	size_t len = mystrlen(s);
	size_t i, j;
	int c;

	for (i = 0, j = len - 1; i < j; i++, j--) {
		c    = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main(int argc, const char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <string>!\n", argv[0]);
		return -1;
	}

	printf("input:\t%s.\n", argv[1]);
	reverse((char *) argv[1]);
	printf("output:\t%s.\n", argv[1]);

	return 0;
}

