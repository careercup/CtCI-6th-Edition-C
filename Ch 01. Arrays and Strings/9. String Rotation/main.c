#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

static int isRotation(const char *a, const char *b)
{
	const int alen = strlen(a);
	const int blen = strlen(b);

	if (alen != blen)
		return 0;

	// should equal strings be considered a rotation on 0?
	if (0 == strcmp(a, b))
		return 0;

	char *buf = (char*) malloc(sizeof(char) * ((2 * alen) + 1));
	memcpy(buf, b, blen);
	memcpy(&buf[blen], b, blen + 1);

	const char *c = strstr(buf, a); // our one call to 'substring'
	free(buf);

	return (NULL != c);
}

int main(const int argc, const char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage: main string1 string2\n");
		exit(1);
	}

	if (isRotation(argv[1], argv[2]))
		printf("True\n");
	else
		printf("False\n");
}
