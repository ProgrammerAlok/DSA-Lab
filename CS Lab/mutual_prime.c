#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int a, b, i, j = 0, k = 0, l, m, n, p[20], q[20], f = 0;
    printf("Enter two number : \n");
    scanf("%d %d", &a, &b);

    for (i = 2; i <= a; i++)
    {
        if (a % i == 0)
        {
            p[j] = i;
            j++;
        }
    }

    for (i = 2; i <= b; i++)
    {
        if (b % i == 0)
        {
            q[k] = i;
            k++;
        }
    }

    for (i = 0; i < j; i++)
    {
        for (l = 0; l < k; l++)
        {
            if (p[i] == q[l])
            {
                f++;
                
            }
        }
    }

    if (f == 0)
    {
        printf("%d and %d are mutual prime.\n", a, b);
    }

    else
    {
        printf("%d and %d are not mutual prime.\n", a, b);
    }

    return 0;
}