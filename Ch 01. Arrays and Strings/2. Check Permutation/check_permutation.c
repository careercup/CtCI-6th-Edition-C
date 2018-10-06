#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check_permutation(const char *s, const char *t)
{
#define NUM_LETTERS 26
	int letters[NUM_LETTERS] = { 0 };
	size_t i = 0, len_s = 0, len_t = 0;

	if (!s || !t)
		return false;

	len_s = strlen(s);
	len_t = strlen(t);
	if (len_s != len_t)
		return false;

	for (i = 0; i < len_s; i++)
		letters[s[i] - 'a']++;
	for (i = 0; i < len_t; i++) {
		if (--letters[t[i] - 'a'] < 0)
			return false;
	}
	return true;
}

int main(void)
{
	unsigned short int i = 0;
	char *test_strings[] = { "dog", "god", "bad", "bed", "aabc", "abbc", "defg", "fgde", NULL };

	for (i = 0; test_strings[i] && test_strings[i + 1]; i = i + 2) {
		printf("%s vs %s: %s.\n",
			test_strings[i], test_strings[i + 1],
			check_permutation(test_strings[i], test_strings[i + 1]) ? "yes" : "no");
	}

	return 0;
}

