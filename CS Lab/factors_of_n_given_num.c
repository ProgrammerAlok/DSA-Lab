#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("How many numbers : \n");
    scanf("%d", &n);
    int a[n], b[20], i, j = 0, k = 0;
    printf("Enter the numbers : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for(i=1 ; i<=a[0] ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if(a[j]%i==0)
            {
                if(j==n-1)
                {
                    b[k]=i;
                    k++;
                }
            }
            else
            {
                break;
            }
        }
    }

    printf("The mutual factors are : \n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", b[i]);
    }

    return 0;
}