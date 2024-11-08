// Enter a n digits input from user and save it in a file. And also plot it in k plots, and find any of plot is prime or not, if prime is found save it in a another file. 

#include <stdio.h>
#include <math.h>

int Prime(int a)
{
    int i;
    for (i = 2; i < a; i++)
    {
        if (a % i == 0)
        {
            return -1;
            break;
        }
    }
    if (a == i)
    {
        return 1;
    }
}

int main()
{
    int a, m, n, i, j, k, l;
    FILE *fp_1, *fp_2;
    int count;
    fp_1 = fopen("Input.txt", "w");
    printf("Enter how many digits : \n");
    scanf("%d", &m);
    while (1)
    {
        count = 0;
        printf("Enter the %d digits : \n", m);
        scanf("%d", &a);
        j = a;
        while (j)
        {
            j = j / 10;
            count++;
        }
        if (count == m)
        {
            fprintf(fp_1, "%d", a);
            fclose(fp_1);
            break;
        }
        else
            printf("Enter a correct digits.\n");
    }
    printf("Enter how many plots : \n");
    scanf("%d", &n);
    int d = pow(10, n);
    int b[50];
    j = a;
    k = 0;
    while (j)
    {
        b[k] = j % d;
        k++;
        j = j / d;
    }

    // for (i = 0; i < k; i++)
    // {
    //     printf("%d ", b[i]);
    // }

    int c = 0, v=0, z;
    fp_2 = fopen("Result.txt", "w");
    for (i = 0; i < k; i++)
    {
        z=b[i];
        Prime(z);
        if(Prime(z)==1 && z>1)
        {
            fprintf(fp_2, "%d\n", z);
            c++;
        }
    }
    fclose(fp_2);
    if(c!=0)
        printf("Prime found.\n");
    else
        printf("Prime is not found.\n");
    return 0;
}