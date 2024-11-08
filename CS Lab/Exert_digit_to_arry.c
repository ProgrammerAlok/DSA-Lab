#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n, j=0;
    printf("Enter a number: \n");
    scanf("%d", &n);
    int a=n, i=0, k=0, rem;
    while(a>0)
    {
        a=a/10;
        i++;
    }
    int b=n, c[i];
    while (b>0)
    {
        int temp = b%10;
        c[-1-j]=temp;
        b=b/10;
        j++;
    }
    printf("The numbers are: \n");
    while (k<i )
    {
        printf("\t%d", c[k]);
        k++;
    }
    
    return 0;
}