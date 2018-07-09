#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isRotation(char*, char*, int, int);
int isSubstring(char*, char*, int, int);

int main()
{
    char s1[1000], s2[1000];
    printf("String 1: ");
    scanf("%s", s1);
    printf("String 2: ");
    scanf("%s", s2);
    if(isRotation(s1, s2, strlen(s1), strlen(s2)) == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

int isRotation(char* s1, char* s2, int len1, int len2)
{
    char* s;
    s = (char*)malloc(len2*2*sizeof(char));
    s = s2;
    strcat(s, s2);
    if(isSubstring(s, s1, strlen(s), strlen(s1)))
        return 1;
    else
        return 0;
}

int isSubstring(char* s, char* s1, int len, int len1)
{
    int i = 0, j = 0;
    char temp = s1[0];
    loop:
    while(s[i] != temp)
    {
        i++;
        if(i >= len)
            return 0;
    }
    while(s[i] == s1[j])
    {
        i++;
        j++;
        if(i >= len && j < len1)
            return 0;
        else if(j >= len1)
            return 1;
        else if(i >= len && j >= len1)
            return 1;
        else
            goto loop;
    }

}