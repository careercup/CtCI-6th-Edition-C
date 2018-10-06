#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int bit_swap_req(int x, int y)
{
	unsigned int count = 0;
	int tmp;

	for (tmp = x ^ y; tmp; tmp &= (tmp - 1))
		count++;
	return count;
}

int main(int argc, const char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "invalid num of args!\nsample usage: %s <num1> <num2>\n",
			argv[0]);
		return -1;
	}

	printf("%s --> %s: %u.\n", argv[1], argv[2],
		bit_swap_req(atoi(argv[1]), atoi(argv[2])));

	return 0;
}

