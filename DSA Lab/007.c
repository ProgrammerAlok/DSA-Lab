
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i = 0, j = 0, n = 5, a[10];
    FILE *fp1, *fp2;

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    if (fp1 == NULL)
    {
        printf("File does not exist.\n");
        exit(1);
    }

    // take input from file.
    for (i = 0; i < n; i++)
    {
        fscanf(fp1, "%d", &a[i]);
    }

    // bubble sort.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // save output to file.
    for (i = 0; i < 5; i++)
    {
        fprintf(fp2, "%d ", a[i]);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
