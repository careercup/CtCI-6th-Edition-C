#include <stdio.h>
#include <string.h>
int isUnique(char*, int);

int main()
{
    char s[1000];
    printf("Input: ");
    scanf("%[^\n]", s);
    if(isUnique(s, strlen(s)) == 1)
        printf("%s is unique.\n", s);
    else
        printf("%s is not unique.\n", s);
    return 0;
}

int isUnique(char* s, int len)
{
    int ascii[128], i;
    if(len > 128)
        return 0;
    for(i = 0; i < 128; i++)
        ascii[i] = 0;
    for(i = 0; i < len; i++)
    {
        if(ascii[s[i]] != 0)
            return 0;
        else
            ascii[s[i]]++;
    }
    return 1;
}