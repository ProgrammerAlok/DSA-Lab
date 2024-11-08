// Find the enter number is Armstrong or not.

#include <stdio.h>
#include <math.h>

int Armstrong(int a)
{
    int d = 0, sum = 0, r;
    r = a;
    while (a > 0)
    {
        a = a / 10;
        d++;
    }
    a = r;
    while (a > 0)
    {
        int lastdigit = a % 10;
        sum += pow(lastdigit, d);
        a = a / 10;
    }

    if (sum == r)
        return 1;
    else
        return 0;
}

void Print(int n)
{
    int a = Armstrong(n);
    if (a)
    {
        printf("Armstrong : %d\n", n);
    }
    // else
    // {
    //     printf("Not Armstrong : %d\n", n);
    // }
}

int main()
{
    int a;
    printf("Enter a number: \n");
    scanf("%d", &a);
    for (int i = 10; i < a; i++)
    {
        Print(i);
    }
    return 0;
}