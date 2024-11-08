#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Prime(int *a)
{
    int i;
    for (i = 2; i < *a; i++)
    {
        if (*(a) % i == 0)
        {
            return 0;
            break;
        }
    }
    if (*a == i)
    {
        return 1;
    }
}

void Input(int *a)
{
    printf("Enter a number: \n");
    scanf("%d", a);
}

int main()
{
    int n;
    Input(&n);
    for (int i = 2; i <= n; i++)
    {
        if (Prime(&i))
        {
            printf("%d\n", i);
        }
        
    }
    return 0;
}