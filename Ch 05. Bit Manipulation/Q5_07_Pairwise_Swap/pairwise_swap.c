#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lsr(int x, int n)
{
	return (int) ((unsigned int) x >> n);
}


int swap_odd_even_bits(int x)
{
	return lsr(x & 0xaaaaaaaa, 1) | ((x & 0x55555555) << 1);
}

int main(int argc, const char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "invalid num of args!\nsample usage: %s <num>\n", argv[0]);
		return -1;
	}

	printf("%s --> %d.\n", argv[1], swap_odd_even_bits(atoi(argv[1])));

	return 0;
}

