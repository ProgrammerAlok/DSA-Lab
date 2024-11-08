#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char ch;
    FILE *fp;
    fp = fopen("file_1.txt", "r");
    ch = fgetc(fp);
    while(!feof(fp))
    {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
    return 0;
}