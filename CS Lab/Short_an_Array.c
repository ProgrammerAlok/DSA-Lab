// WAP to short a array.

#include <stdio.h>
#include <stdlib.h>

int a, b, c, d, n, *arr;

void BubbleShort(int arr[], int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void Print(int arr[], int n)
{
    printf("Short of the array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr+i));
    }
}

int Input()
{
    printf("How many number you want to enter : \n");
    scanf("%d", &n);
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter the %d numbers : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    return arr, n;
}

int main()
{
    Input();
    BubbleShort(arr, n);
    Print(arr, n);
    return 0;
}