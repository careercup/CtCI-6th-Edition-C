#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* WARNING: one has to free t! */
char * compress(char *s)
{
	char *t;
	size_t i = 0, j = 0, len = strlen(s);

	t = calloc(256, sizeof(char));
	if (!t)
		return NULL;

	for (i = 0, j = 1; i < len; i++) {
		if (i == len - 1) {
			sprintf(t + strlen(t), "%c%zu", s[i], j);
			break;
		} else if (s[i] == s[i + 1]) {
			j++;
		} else {
			sprintf(t + strlen(t), "%c%zu", s[i], j);
			j = 1;
		}
	}
	return strlen(t) < len ? t : s;
}

int main(void)
{
	char s[16];

	memset(s, 0x0, sizeof(s));
	sprintf(s, "aaaabbcddd");
	printf("%s --> %s.\n", s, compress(s));

	memset(s, 0x0, sizeof(s));
	sprintf(s, "xyz");
	printf("%s --> %s.\n", s, compress(s));

	memset(s, 0x0, sizeof(s));
	sprintf(s, "spppptttummm");
	printf("%s --> %s.\n", s, compress(s));

	return 0;
}

