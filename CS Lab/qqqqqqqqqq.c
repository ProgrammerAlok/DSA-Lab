#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char m[12];
    printf("Enter a mobile number : \n");
    scanf("%[^\n]s", m);
    for(int i=0; i<10;i++)
    {
        if(m[i]>100 && m[i]<110)
            printf("%c = %d\n", m[i], m[i]);
    }
    return 0;
}