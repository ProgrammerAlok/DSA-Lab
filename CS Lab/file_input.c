#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fp;
    char s[100];
    fp = fopen("file_1.txt", "a+");
    printf("Enter a string : \n");
    gets(s);
    for(int i=0 ; i<(strlen(s)) ; i++)
    {
        fputc(s[i], fp);
    }
    fclose(fp);
    return 0;
}