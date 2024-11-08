
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * Random(int lower, int upper, int count)
{
    int i;
    int *arr = (int *)calloc(count, sizeof(int));
    for (i = 0; i < count; i++)
    {
        int num = (rand() % (upper - lower + 1)) + lower;
        arr[i] = num;
    }
    return arr;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int * firstLastNDigit(int arr[], int size, int numberofdigit)
{
    if(size>2*numberofdigit)
    {
        int *temp = (int *)calloc(2*numberofdigit, sizeof(int));
        int *temp1 = (int *)calloc(numberofdigit, sizeof(int));
        int *temp2 = (int *)calloc(numberofdigit, sizeof(int));
        //for first N-digit number
        int i=0, k=0;
        for(i=0;i<numberofdigit;i++)
        {
            temp1[i] = arr[k];
            k++;
        }
        bubbleSort(temp1, numberofdigit);
        while (k!=size)
        {
        //printf("\nit is working\n");
            if(temp1[numberofdigit-1]>arr[k])
            {
                temp1[numberofdigit-1]=arr[k];
                bubbleSort(temp1, numberofdigit);
            }
            k++;            
        }
        for(i=0;i<numberofdigit;i++)
        {
            temp[i]=temp1[i];
        }

        
        //for last N-digit number
        k=0;
        for(i=0;i<numberofdigit;i++)
        {
            temp2[i] = arr[k];
            k++;

        }
        bubbleSort(temp2, numberofdigit);
        while (k!=size)
        {
            if(temp2[0]<arr[k])
            {
                temp2[0]=arr[k];
                bubbleSort(temp2, numberofdigit);
            } 
            k++;            
        }
        k=0;
    
        for(i=numberofdigit;i<2*numberofdigit;i++)
        {
            temp[i]=temp2[k]; k++;
        }


        free(temp1);
        free(temp2);
        return temp;
    }
    else
    {
        bubbleSort(arr, size);
        return arr;
    }
}

int main()
{

    // generate random 1000 number and save in a file.
    FILE *fp1 = NULL, *fp2 = NULL;
    int n = 1000, i = 0;
    // int *a = printRandoms(int lower, int upper,int count);
    int *a = Random(-500, 500, n);
    fp1 = fopen("generate.txt", "w");
    i = 0;
    while (i < 1000)
    {
        fprintf(fp1, " %d", a[i]);
        i++;
    }
    fclose(fp1);



    // m[] take input from file
    int *m = (int *)calloc(n, sizeof(int));
    fp1 = fopen("generate.txt", "r");
    i = 0;
    while (i < n)
    {
        int x;
        fscanf(fp1, " %d", &m[i]);
        i++;
    }
    fclose(fp1);


    // find max and min
    i = 0;
    int max = m[i], min = m[i];
    for (i = 0; i < n; i++)
    {
        max = max < m[i] ? m[i] : max;
        min = min > m[i] ? m[i] : min;
    }
    printf("Max = %d and Min = %d", max, min);



    // save negetive numbers to file.
    fp1 = fopen("negetive.txt", "w");
    fp2 = fopen("generate.txt", "r");
    i = 0;
    while (i < n)
    {
        int x;
        fscanf(fp2, " %d", &x);
        if (x < 0)
            fprintf(fp1, " %d", x);
        i++;
    }
    fclose(fp1);
    fclose(fp2);


    // first and last N digit number to a array.
    int *a1 = firstLastNDigit(a, n, 1);
    printf("\n");
    for(i=0;i<10;i++)
    {
        printf(" %d", a1[i]);
    }


    free(a);
    free(a1);
    free(m);
    return 0;
}