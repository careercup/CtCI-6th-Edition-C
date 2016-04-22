// C program to find Unique character
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isUniqueChars(char *str,int size)
{
if(size > 128)
	return false;
	
bool index[128] = {0};
int i;
for (i = 0; i < size; i++)
{
    int val = str[i];
    if(index[val])
    {
        return false;
    }
    index[val] = true;
} 
return true;
}

int main()
{
char str[] = "CTCI";
int size = strlen(str);
if (isUniqueChars(str,size)) 
	printf("Unique");
else
    printf("Not unique");
getchar();
return 0;
}
