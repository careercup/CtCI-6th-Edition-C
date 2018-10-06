#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a, b)	(((a) < (b)) ? (a) : (b))
#define MAX_LINE_LEN	256

void print_last_k_lines(const char *filename, unsigned int k)
{
	FILE *fp;
	char (*lines)[MAX_LINE_LEN + 1];
	unsigned int i, count, start, size;

	fp = fopen(filename, "r");
	if (!fp) {
		fprintf(stderr, "fopen() failed: %s!\n", strerror(errno));
		return;
	}

	lines = calloc(k, sizeof(*lines));
	if (!lines) {
		fprintf(stderr, "malloc() failed: %s!\n", strerror(errno));
		fclose(fp);
		return;
	}

	for (size = 0; fgets(lines[size % k], MAX_LINE_LEN, fp); size++);
	fclose(fp);

	start = size > k ? (size % k) : 0;
	count = MIN(k, size);
	for (i = 0; i < count; i++)
		printf("%s", lines[(start + i) % k]);

	free(lines);
}

int main(int argc, const char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <num_lines>!\n", argv[0]);
		return -1;
	}

	print_last_k_lines("test_file.txt", (unsigned int) atoi(argv[1]));

	return 0;
}

