#include <stdio.h>
#include <string.h>
int isPermutationOfPalindrome(char*, int);

int main()
{
    char s[1000];
    printf("Input: ");
    scanf("%[^\n]", s);
    if(isPermutationOfPalindrome(s, strlen(s)) == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

int isPermutationOfPalindrome(char* s, int len)
{
    char ascii[128];
    int i, odd = 0;
    for(i = 0; i < 128; i++)
        ascii[i] = 0;
    for(i = 0; i < len; i++)
        ascii[s[i]]++;
    for(i = 0; i < 128; i++)
    {
        if(i >= 65 && i <= 90 || i >= 97 && i <=122)
        {
            if(ascii[i]%2 != 0)
                odd++;
            if(odd > 1)
                return 0;
        }
    }
    return 1;
}