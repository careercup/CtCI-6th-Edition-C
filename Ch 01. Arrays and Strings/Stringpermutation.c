#include <stdio.h>
void swap(char *p,char *q)
{
char temp;
temp=*p;
*p=*q;
*q=temp;
}
void permute(char *a,int l,int r)
{
int i;
if (l==r)
printf("%s\n", a);
else
{
for (i=l;i<=r;i++)
{
swap((a+l),(a+i));
permute(a,l+1,r);
swap((a+l),(a+i));
}
}
}
void main()
{
char str[100];
printf("Enter the String\n");
gets(str);
printf("\n");
int n = strlen(str);
printf("All permutations are :\n");
permute(str,0,n-1);

}
