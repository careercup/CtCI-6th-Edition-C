#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEST_STRING_SIZE 10

static int cmpcharp(const void *p1, const void *p2) {
  return *(char *)p1 - *(char *)p2;
}

static bool is_permutation(const char *s1, const char *s2) {
  bool result = false;

  char *word1copy = strdup(s1);
  char *word2copy = strdup(s2);

  qsort(word1copy, strlen(word1copy), sizeof(char), cmpcharp);
  qsort(word2copy, strlen(word2copy), sizeof(char), cmpcharp);

  result = strcmp(word1copy, word2copy) ? false : true;

  /* Need to free as strdup allocated memory */
  free(word1copy);
  free(word2copy);

  return result;
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