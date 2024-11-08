// WAP to print the digit frequency in a number.

#include <stdio.h>

void Number()
{
    int a[50], b[10] = {0}, n, i = 0, j = 0;

    printf("Enter a number : \n");
    scanf("%d", &n);

    while (n)
    {
        a[i] = n % 10;
        b[a[i]] += 1;
        n /= 10;
        i++;
    }

    for (j = 0; j < 10; j++)
    {
        if (*(b + j) != 0)
        {
            printf("%d occurse %d times.\n", j, j[b]);
        }
    }
}

int main()
{
    int n;
    printf("Enter how many times : \n");
    scanf("%d", &n);
    while (n--)
    {
        Number();
    }

    return 0;
}