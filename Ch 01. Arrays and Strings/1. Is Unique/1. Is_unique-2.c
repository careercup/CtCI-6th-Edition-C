#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_unique(const char *s)
{
#if 0
#define NUM_LETTERS 26
	bool alphabet[NUM_LETTERS] = { false };
	size_t i = 0, len = 0, index = 0;

	if (!s)
		return false;

	len = strlen(s);
	for (i = 0; i < len; i++) {
		index = s[i] - 'a';
		if (alphabet[index] == true)
			return false;
		alphabet[index] = true;
	}
	return true;
#else
	size_t i = 0, len = 0;
	unsigned int val = 0, checker = 0;

	if (!s)
		return false;

	len = strlen(s);
	for (i = 0; i < len; i++) {
		val = 1 << (s[i] - 'a');
		if ((checker & val) > 0)
			return false;
		checker |= val;
	}
	return true;
#endif
}

int main(void)
{
	unsigned short int i = 0;
	char *test_strings[] = { "cracking", "the", "coding", "interview", NULL };

	for (i = 0; test_strings[i]; i++) {
		printf("%s: %s.\n",
			test_strings[i],
			is_unique(test_strings[i]) ? "yes" : "no");
	}

	return 0;
}

