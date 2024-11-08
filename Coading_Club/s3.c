#include<stdio.h>
#include<string.h>
int main()
{
char a[100],*b;
int i,n,k=0;
printf("Enter string 1 \n");
scanf("%[^\n]s",a); //sachin
b=strrev(a); //nihcas
n=strlen(a);
for(i=0;i<n;i++)
{
if(a[i]==b[n-i-1])
continue;
else
{
k=1;
break;
}
}
if(k==0)
printf("the word is palindrome");
else
printf("the word is not a palindrome");
return 0;
}