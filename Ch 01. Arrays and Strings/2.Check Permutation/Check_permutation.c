//
//  Check_permutation.c
//  Check that one string is a permutation of the other one
//  by checking that both strings have similar characters frequency
//

#include <stdio.h>
#include <stdbool.h>

bool isLengthEqual(char *str1, char *str2)
{
    while (*str1 && *str2) {
        str1++;
        str2++;
    }

    return (*str1 == '\0' && *str2 == '\0');
}

bool isPermutation(char *str1, char *str2)
{
    bool isLengthEqual(char *str1, char *str2);
    int charactersFrequency[128] = {}; // to be able to work with 128 ASCII alphabet

    if (! isLengthEqual(str1, str2)) { // permuted string needs to have the same length
        return false;
    }

    while (*str1) { // count characters frequency for str1
        charactersFrequency[(int) *str1]++;
        str1++;
    }

    while (*str2) { // comparing str2 characters frequency against characters frequency for str1
        if (--charactersFrequency[(int) *str2] < 0) {
            return false;
        }

        str2++;
    }

    return true;
}

int main(void) {
    bool isPermutation(char *str1, char *str2);
    char str1[80];
    char str2[80];

    printf("First string: ");
    fgets(str1, 80, stdin);

    printf("Second string: ");
    fgets(str2, 80, stdin);

    printf("Strings are: %s\n", isPermutation(str1, str2) ? "permutations." : "not permutations.");
    
    return 0;
}
