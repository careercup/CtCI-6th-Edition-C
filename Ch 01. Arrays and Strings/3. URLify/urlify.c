#include <stdio.h>
#include <string.h>

void urlify(char *s, int len)
{
	int i = 0, max_len = 0, space_count = 0;

	if (!s)
		return;

	for (i = 0; i < len; i++) {
		if (s[i] == ' ')
			space_count++;
	}
	max_len = len + space_count * 2;

	s[len] = '\0';
	for (i = len - 1; i >= 0; i--) {
		if (s[i] == ' ') {
			s[--max_len] = '0';
			s[--max_len] = '2';
			s[--max_len] = '%';
		} else {
			s[--max_len] = s[i];
		}
	}
}

int main(void)
{
	char s1[16];
	char s2[27];
	char s3[11];

	sprintf(s1, "Mr John Doe");
	printf("'%s' --> ", s1);
	urlify(s1, 11);
	printf("'%s'.\n", s1);

	sprintf(s2, " Start with  blank");
	printf("'%s' --> ", s2);
	urlify(s2, 18);
	printf("'%s'.\n", s2);

	sprintf(s3, "SimpleTest");
	printf("'%s' --> ", s3);
	urlify(s3, 10);
	printf("'%s'.\n", s3);

	return 0;
}

