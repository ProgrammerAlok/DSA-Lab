/*
WAP to print a pattern like:
    *
   * *
  * * *
 * * * *
* * * * *
 * * * *
  * * *
   * *
    *
*/

#include <stdio.h>

int n, i, j, k;

void Diamond()
{
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)

            printf(" ");

        for (k = 1; k <= i; k++)

            printf("* ");

        printf("\n");
    }

    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= (i - 1); j++)

            printf(" ");

        for (k = 1; k <= n - i + 1; k++)

            printf("* ");

        printf("\n");
    }
}

int Input()
{
    printf("Enter a number: \n");
    scanf("%d", &n);
}

int main()
{
    Input();
    Diamond();

    return 0;
}