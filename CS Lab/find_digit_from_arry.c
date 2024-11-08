

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int *a, n, i, m, j;
    printf("Enter how many numbers: \n");
    scanf("%d", &n);
    a=(int *)malloc(n*sizeof(int));
    printf("Enter the numbers: \n");
    for(i=0 ; i<n ;i++)
    {
        scanf("%d", a+i);
    }
    printf("Enter the number whis is to be find: \n");
    scanf("%d", &m);
    for ( i = 0; i < n; i++)
    {
        if(m==*(a+i))
            printf("The number is find at the index : %d.", i);
            
    }
    
    return 0;
}