#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n, k, t1 = 0, t2 = 0, size;
        scanf("%d %d", &n, &k);
            size = n / 2;
        int arr[n], arr1[size], arr2[size];
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        for (int j = 0; j < k; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i % 2 != 0 && i != 0)
                {
                    arr1[t1] = arr[i];
                    t1++;
                }
                else if (i == 0 || i % 2 == 0)
                {
                    arr2[t2] = arr[i];
                    t2++;
                }
            }
            for(int l = 0; l < n; l++)
            {
                if(l < size)
                    arr[l] = arr2[l];
                else
                    arr[l] = arr1[l - size];
            }
            t1 = 0;
            t2 = 0;
        }
        for(int i = 0; i < n; i++)
                printf("%d ",arr[i]);
            printf("\n");
    }
    return 0;
}