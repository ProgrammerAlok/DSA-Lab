/*
Arrays insertion -
row wise
column wise
spiral
*/

#include <stdio.h>
#include <stdlib.h>

void RowWiseInsersion(int *arr, int n)
{
    int i, j, k, c = 0;
    int **a;
    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = arr[c++];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void ColumnWiseInsersion(int *arr, int n)
{
    int i, j, k, c = 0;
    int **a;
    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[j][i] = arr[c++];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void SpiralInsersion(int *arr, int n)
{
    int i = 0, j = 0, min_row = 0, min_col = 0, max_row = n-1, max_col = n-1, index=0;
    int a[n][n];
    while(index<n*n)
    {
        for (i = min_row, j=min_col; j <= max_col && index<n*n; j++)
        {
            a[i][j] = *(arr + index);
            index++;
        }
        min_row++;
        for (i = min_row, j=max_col; i <= max_row && index<n*n; i++)
        {
            a[i][j] = *(arr + index);
            index++;
        }
        max_col--;
        for (i = max_row, j=max_col; j >= min_col && index<n*n; j--)
        {
            a[i][j] = *(arr + index);
            index++;
        }
        max_row--;
        for (i = max_row, j=min_col; i >= min_row && index<n*n; i--)
        {
            a[i][j] = *(arr + index);
            index++;
        }
        min_col++;     
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, m, n;
    printf("Enter the order of matrix : \n");
    scanf("%d", &n);
    int *a = (int *)calloc(n * n, sizeof(int));
    printf("Enter %d numbers:\n", n * n);
    for (i = 0; i < n * n; i++)
    {
        scanf("%d", (a + i));
    }
    printf("\n");

    printf("Matrix column wise insert ::\n");
    RowWiseInsersion(a, n);
    printf("\n");

    printf("Matrix row wise insert ::\n");
    ColumnWiseInsersion(a, n);
    printf("\n");

    printf("Matrix spiral insert ::\n");
    SpiralInsersion(a, n);
    printf("\n");

    return 0;
}