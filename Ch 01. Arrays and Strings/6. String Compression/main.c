#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

static char *compress(const char *s)
{
	const int slen = strlen(s);
	char *c = (char*) malloc(sizeof(char) * (2 * slen) + 1);
	int d = 1;
	int ci = 0;
	for (int si = 1; si <= slen; si++) {
		if (s[si] == s[si-1]) {
			d++;
		} else {
			ci += sprintf(&c[ci], "%c%i", s[si-1], d);
			d = 1;
		}

		if (ci >= slen) {
			free(c);
			return strdup(s);
		}
	}

	return c;
}

int main(const int argc, const char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: main [string [string [...] ] ]\n");
		exit(1);
	}

	char *c = NULL;
	for (int i = 1; i < argc; i++) {
		c = compress(argv[i]);
		printf("%s\n", c);
		free(c);
	}
}

