#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a[3][3], b[3][3], c[3][3];
    int i, j, r1, c1, r2, c2;
    
    // printf("Enter the order of matrix(eg.. 3x3): \n");
    // scanf("%dx%d", &r1, &c1);
    
    
    printf("Enter the element of the first matrix column wise: \n");
    for(i=0 ; i<3 ;i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the element of the second matrix column wise: \n");
    for(i=0 ; i<3 ;i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0 ; i<3 ;i++)
    {
        for(j=0 ; j<3 ; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%d  ", c[i][j]);
        }
        printf("\n");
    }

    // printf("The addition of two matrix is: \n");
    // for(i=0 ; i<r1 ;i++)
    // {
    //     for(j=0 ; j<c1 ; j++)
    //     {
    //         printf("%d  ", c[i][j]);

    //     }
    //     printf("\n");
    // }
    return 0;
}