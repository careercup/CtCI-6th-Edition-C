#include <stdio.h>
#include <stdbool.h>
#include <string.h> // for strlen

bool isUniqueChars(char* str)
{
    int length = strlen(str);

    // check if string is longer than charset
    if (length > 128)
        return false;

    // initialize all elements to false
    bool char_set[128] = {false};

    for (int i = 0; i < length; i++)
    {
        int val = str[i];
        if (char_set[val])
            return false;
        char_set[val] = true;
    }

    return true;
}

int main()
{
    // test some arbitrary strings
    char* testStrings[5] = {"abcde", "hello", "apple", "kite", "padle"};
    for (int i = 0; i < 5; i++)
        // print the string followed by whether or not it has all unique characters
        printf("%s: %s\n", testStrings[i], isUniqueChars(testStrings[i]) ? "true" : "false");
    return 0;
}
