#include<stdio.h>
#include<string.h>
int checkPermutation(char*, char*, int, int);

int main()
{
    char s1[1000], s2[1000];
    printf("String 1: ");
    scanf("%[^\n]", s1);
    printf("String 2: ");
    scanf("%[^\n]", s2);
    if(checkPermutation(s1, s2, strlen(s1), strlen(s2)) == 1)
        printf("%s and %s are permutations of each other.\n", s1, s2);
    else
        printf("%s and %s are not permutations of each other.\n", s1, s2);
    return 0;
}

int checkPermutation(char* s1, char* s2, int len1, int len2)
{
    int ascii[128], i;
    if(len1 != len2)
        return 0;
    else
    {
        for(i = 0; i < 128; i++)
            ascii[i] = 0;
        for(i = 0; i < len1; i++)
            ascii[s1[i]]++;
        for(i = 0; i < len2; i++)
        {
            ascii[s2[i]]--;
            if(ascii[s2[i]] < 0)
                return 0;
        }
    }
    return 1;
}