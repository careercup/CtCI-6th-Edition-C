#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void oneAway(char*, char*, int, int);

int main()
{
    char s1[1000], s2[1000];
    printf("String 1: ");
    scanf("%s", s1);
    printf("String 2: ");
    scanf("%s", s2);
    oneAway(s1, s2, strlen(s1), strlen(s2));
    return 0;
}

void oneAway(char* s1, char* s2, int len_a, int len_b)
{
    int matches, i, flag1 = 0, flag2 = 0, len = len_a;
    if(len_a != len_b && len_a + 1 != len_b && len_a != len_b + 1)
    {
        printf("More than an edit away.\n");
        return;
    }
    if(len_a > len_b)
        len = len_b;
    for(i = 0; i < len; i++)
    {
        if(s1[i + flag1] == s2[i + flag2])
            matches++;
        else
        {
            if(len_a == len_b)
            {
                if(flag1 == 0 && flag2 == 0)
                {
                    flag1++;
                    flag2++;
                }
                else
                {
                    printf("More than an edit away.\n");
                    return;
                }
            }
            else if(len_a == len_b + 1)
            {
                if(flag1 == 0)
                {
                    flag1++;
                    i--;
                }
                else
                {
                    printf("More than an edit away.\n");
                    return;
                }
            }
            else if(len_a + 1 == len_b)
            {
                if(flag2 == 0)
                {
                    flag2++;
                    i--;
                }
                else
                {
                    printf("More than an edit away.\n");
                    return;
                }
            }
            else
            {
                printf("More than an edit away.\n");
                return;
            }
        }
    }

    if(flag1 == 0 && flag2 == 0 && len_a == len_b)
    {
        printf("0 edits away.\n");
        return;
    }
    else if((flag1 == 0 && flag2 == 0 && (len_a == len_b + 1 || len_a + 1 == len_b)) || (flag1 == 0 && flag2 == 1 && len_a + 1 == len_b) || (flag1 == 1 && flag2 == 0 && len_a == len_b + 1))
    {
        printf("1 edit away.\n");
        return;
    }
    else
        printf("More than an edit away.\n");
    return;
}