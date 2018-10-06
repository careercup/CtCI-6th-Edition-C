#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 * only handles *lower letters*.
 */
bool is_all_permutations_palindrome(const char *s)
{
	int letters = 0;
	size_t i = 0, len = 0;

	if (!s)
		return false;

	len = strlen(s);
	for (i = 0; i < len; i++)
		letters ^= 1 << (s[i] - 'a');
	return !letters || !(letters & letters - 1);
}

int main(void)
{
	unsigned short int i = 0;
	char *test_strings[] = { "dogooogdx", "badadb", "abebc", NULL };

	for (i = 0; test_strings[i]; i++) {
		printf("%s: %s.\n",
			test_strings[i],
			is_all_permutations_palindrome(test_strings[i]) ? "yes" : "no");
	}

	return 0;
}

