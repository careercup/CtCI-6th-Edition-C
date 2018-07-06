#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEST_STRING_SIZE 10

static bool is_permutation(const char *s1, const char *s2) {
  char letters[128] = {0};

  const char *tmp = s1;
  while (*tmp) {
    letters[(int)*tmp]++;
    tmp++;
  }

  tmp = s2;
  while (*tmp) {
    letters[(int)*tmp]--;
    if (letters[(int)*tmp] < 0) {
      return false;
    }
    tmp++;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  char pairs[][2][MAX_TEST_STRING_SIZE] = {
      {"apple", "papel"}, {"carrot", "tarroc"}, {"hello", "llloh"}};
  int number_of_pairs = sizeof(pairs) / sizeof(pairs[0]);
  for (int i = 0; i < number_of_pairs; ++i) {
    printf("%s, %s : %s\n", pairs[i][0], pairs[i][1],
           is_permutation(pairs[i][0], pairs[i][1]) ? "true" : "false");
  }
  return 0;
}