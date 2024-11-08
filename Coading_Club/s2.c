//string library
//There are some library functions popularly used in C for string handeling
//strlen(str) => to get the lengeth of a string
//strcmp(str1,str2)=> to compare between two strings
//strcpy(str1,str2)=> To copy string2 to String1
//strrev(str) =>to reverse the string
//strcat(str1,str2)=>concatinate two strings

#include<stdio.h>
#include<string.h>

int main()
{

 char str1[]="Good ";
char str2[]="Morning";
char str3[20], str4[20], *str5;
int i,j,len;

//printf("Enter a string\n");
//scanf("%[^\n]s", &str1);
len=strlen(str1);
printf("The length of %s is %d\n", str1, len);
//scanf("\n");
//printf("Enter 2nd string\n");
//scanf("%[^\n]s", &str2);
i=strcmp(str1,str2);
if(i>0)
{
printf("%s is greater than %s\n", str1,str2);
}
else if(i<0)
printf("%s is less than %s\n", str1,str2);
else
printf("both are equal");

 strcat(str1,str2);
printf("String=%s\n",str1);

 strcpy(str4,str1);
printf("String=%s\n",str4);

 str5=strrev(str2);
printf("String=%s\n",str5);
return 0;
}