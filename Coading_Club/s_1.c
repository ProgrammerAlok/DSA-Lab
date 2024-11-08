[08:33 am] Dr.Satyabrata Maity
#include<string.h>
#include<stdio.h>
int main()
{
char name[100], rev[100];
int i, len;
printf("Enetr a name::\n");
scanf("%[^\n]s", &name); //Sachin
//printf("The name you entered is ::%s\n", name);
i=0;
while(name[i] !='\0') // i=0, name[0]=S !='\0' name[1]=a !='\0' name[2]=c !=0 name[3]=h name[4]=i name[5]=n name[6]='\0' false
{
printf("%c", name[i]); //print S a c h i n leave
i++; //i=1 2 3 4 5 6
}
printf("The length of the string is %d\n", i); //length is 6
len=i;
for(i=0;i<len;i++)
rev[i]=name[len-i-1];
rev[len]='\0';
printf(" Input string=%s reverse=%s\n", name, rev);
return 0;
}

