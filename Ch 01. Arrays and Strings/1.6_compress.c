#include <stdio.h>
#include <string.h>
char* compress(char* s, int len);

int main()
{
    char s[1000];
    printf("Input: ");
    scanf("%s", s);
    printf("On compression: %s\n", compress(s, strlen(s)));
    return 0;
}

char* compress(char* s, int len)
{
    char result[len+1], temp;
    int i, j = len - 1, count;
    for(i = len - 1; i >= 0;)
    {
        count = 0;
        temp = s[i];
        while(s[i] == temp && i >= 0)
        {
            count++;
            i--;
        }
        while(count > 0)
        {
            result[j--] = (count%10) + 48;
            count /= 10;
            if(j == -1)
                return s;
        }
        result[j--] = temp;
        if(j == -1 && i != 0)
            return s;
    }
    i = 0;
    while(i+j+1 <= len)
    {
        result[i] = result[i+j+1];
        i++;
    }
    result[len] = '\0';
    s = result;
    return s;
}