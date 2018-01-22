#include <stdio.h>
#include <string.h>
void URLify(char*, int);

int main()
{
    char s[1000];
    printf("Input: ");
    scanf("%[^\n]", s);
    printf("URLify(\"%s\") = ", s);
    URLify(s, strlen(s));
    printf("%s\n", s);
    return 0;
}

void URLify(char* s, int len)
{
    int i, j = len - 1;
    while(s[j] == ' ' && j>=0)
        j--;
    if(j >= 0)
    {
        i = len - 1;
        for(; j >= 0; j--)
        {
            if(s[j] == ' ')
            {
                s[i--] = '0';
                s[i--] = '2';
                s[i--] = '%';
            }
            else
                s[i--] = s[j];
        }
        for(j = 0; j < len; j++)
            s[j] = s[j+i+1];
    }
}