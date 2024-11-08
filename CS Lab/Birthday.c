#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void EnterDoB(int n)
{
    int a[n][3], i;
    printf("Enter the age of the persons in DD MM YYYY format: \n"); 
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a[i][0], a[i][1], a[i][2]);
    }
    
}


int main()
{
    int n;
    printf("How many DOB you want to enter: \n");
    scanf("%d", &n);
    int DOB[n][3];
    EnterDoB(n);
    printf("%d", DOB[1][3]);
    return 0;
}