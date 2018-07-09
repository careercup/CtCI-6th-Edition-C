#include <stdio.h>
#include <string.h>

int checkPermutation(char  s[100], char t[100])
{
	int lettersInS[128],lettersInT[128],i;
	for(i=0;i<128;i++)
	{
		lettersInS[i] = 0;
		lettersInT[i] = 0;
	}
	for(i=0;i<strlen(s);i++)
	{
		lettersInS[s[i]]++;
	}
	for(i=0;i<strlen(t);i++)
	{
		lettersInT[t[i]]++;
	}
	for(i=0;i<128;i++)
	{
		if(lettersInS[i] != lettersInT[i])
		{
			return 0;
		}
	}
	return 1;
}

int main(void) {
	char s[100];
	scanf("%s",s);
	char t[100];
	scanf("%s",t);
	if(checkPermutation(s,t))
	{
		printf("Permutation");
	}
	else
	{
		printf("Not Permutation");
	}
	return 0;
}
