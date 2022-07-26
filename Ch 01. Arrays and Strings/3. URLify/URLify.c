#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Replaces all ' ' with '%20'
 * @param str null-terminated string
 * @return pointer to the new string
 */
char *URLify(const char *str)
{
    static const char *space = "%20";
    int len = strlen(str);
    int num = 0;

    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ')
        {
            num++;
        }
    }

    int resLen = len + 2 * num;
    char *res = (char *)malloc(resLen+1);

    int strIndex = 0;
    int resIndex = 0;
    
    while(strIndex < len && resIndex < resLen)
    {
        if(str[strIndex] == ' ')
        {
            strncpy(res+resIndex, space, strlen(space));
            resIndex += strlen(space);
        }
        else
        {
            res[resIndex++] = str[strIndex];
        }

        strIndex++;
    }

    res[resIndex] = 0;

    return res;
}


int main()
{
    assert(strcmp(URLify("http://HELLOWORLD.com"), "http://HELLOWORLD.com") == 0);
    assert(strcmp(URLify("http://HELLO WORLD.com"), "http://HELLO%20WORLD.com") == 0);
    assert(strcmp(URLify("http://HELLO WORLD.com"), "http://HELLO%30WORLD.com") != 0);

    return 0;
}

