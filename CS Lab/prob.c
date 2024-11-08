#include <stdio.h>

void riffel(int *a, int n)
{
    int i = 0, j = 0;
    int size = n / 2;
    int p[size], q[size];

    for (i = 0; i < n / 2; i++)
    {
        p[i] = a[(2 * i)];
    }
    for (i = 0; i < n / 2; i++)
    {
        q[i] = a[(2 * i) + 1];
    }
    for (i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            a[i] = p[i];
        }
        else
        {
            a[i] = q[j];
            j++;
        }
    }
}

void riffelCall(int *a, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        riffel(a, n);
    }
}

void Print(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    int a, b, c[20], d;
    printf(" enter a even number  ");
    scanf("%d", &n);

    while (n--)
    {
        scanf("%d %d", &a, &b);
        d = a;
        if ((d / 2) * 2 != a)
        {
            printf("Please enter a even number instade of %d.\n", a);
            continue;
        }
        for (int i = 0; i < a; i++)
        {
            c[i] = i + 1;
        }
        riffelCall(c, a, b);
        Print(c, a);
    }

    return 0;
}
