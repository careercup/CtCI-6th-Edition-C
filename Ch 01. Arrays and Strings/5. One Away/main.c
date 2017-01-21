#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

static int oneAway(const char *a, const char *b)
{
	const int alen = strlen(a);
	const int blen = strlen(b);
	if (alen < blen)
		return oneAway(b, a);

	if (alen - blen > 1)
		return 0;

	int edits = 0;
	for (int ai = 0, bi = 0; bi < blen; ai++) {
		if (a[ai] != b[bi]) {
			if (0 != edits)
				return 0;
			edits++;

			if (alen == blen)
				bi++;
		} else {
			bi++;
		}
	}

	if (alen == blen && edits == 0)
		return 0;

	return 1;
}

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage: main string1 string2\n");
		exit(1);
	}

	if (0 < oneAway(argv[1], argv[2]))
		printf("True\n");
	else
		printf("False\n");
}
