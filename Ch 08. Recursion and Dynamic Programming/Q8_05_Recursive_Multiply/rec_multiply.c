#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int rec_multiply_helper(unsigned int bigger, unsigned int smaller)
{
	if (smaller == 0)	return 0;
	if (smaller == 1)	return bigger;
	return bigger + rec_multiply_helper(bigger, smaller - 1);
}

unsigned int rec_multiply_helper2(unsigned int bigger, unsigned int smaller)
{
	unsigned int s, half_sum;

	if (smaller == 0)	return 0;
	if (smaller == 1)	return bigger;

	s = smaller >> 1;
	half_sum = rec_multiply_helper2(bigger, s);
	if (smaller % 2)
		return half_sum + half_sum + bigger;
	else
		return half_sum + half_sum;
}

unsigned int rec_multiply(unsigned int x, unsigned int y)
{
	unsigned int smaller, bigger;

	if (x > y) {
		bigger = x;
		smaller = y;
	} else {
		bigger = y;
		smaller = x;
	}

	return rec_multiply_helper2(bigger, smaller);
}

int main(int argc, const char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "invalid num of args!\nsample usage: %s <num1> <num2>\n",
			argv[0]);
		return -1;
	}

	printf("%s * %s = %u.\n", argv[1], argv[2], rec_multiply(atoi(argv[1]), atoi(argv[2])));

	return 0;
}

