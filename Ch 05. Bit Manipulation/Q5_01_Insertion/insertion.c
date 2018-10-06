#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int update_bits(int m, int n, int i, int j)
{
	int left  = (~0) << (j + 1);
	int right = (1 << i) - 1;
	int mask  = left | right;
	return (m & mask) | (n << i);
}

int main(int argc, const char **argv)
{
	if (argc != 5) {
		fprintf(stderr, "invalid num of args!\nsample usage: %s <num1> <num2> <start> <end>\n",
			argv[0]);
		return -1;
	}

	printf("%s --> %s: %d.\n", argv[1], argv[2],
		update_bits(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])));

	return 0;
}

