#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int num_ways(unsigned int height)
{
    unsigned int paths[3] = { 1, 1, 2 };
    unsigned int new_path;
    
    if (height < 3)
        return paths[height];
    while (height-- > 2) {
        new_path = paths[0] + paths[1] + paths[2];
        paths[0] = paths[1];
        paths[1] = paths[2];
        paths[2] = new_path;
    }
    return paths[2];
}

int main(int argc, const char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "invalid num of args!\nsample usage: %s <staircase_len>\n",
			argv[0]);
		return -1;
	}

	printf("%s --> %u.\n", argv[1], num_ways(atoi(argv[1])));

	return 0;
}

