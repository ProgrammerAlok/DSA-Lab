// WAP to print the location of different type of array variable.

#include <stdio.h>

int menu()
{
    int n;
    printf("\nEnter your choice : \n  Press 1 for print integer memory location.\n  Press 2 for print float memory location.\n  Press 3 for print character memory location.\n  Press 4 for print double type memory location.\n  Press 0 for exit.\n-> ");
    scanf("%d", &n);
    return n;
}

void arrIntLoc()
{
    int a[5], i = 0;
    printf("  Integer type memory location are : \n");
    for (i = 0; i < 5; i++)
    {
        printf("%p ", a[i]);
    }
}

void arrFloatLoc()
{
    float a[5];
    int i = 0;
    printf("  Float type memory location are : \n");
    for (i = 0; i < 5; i++)
    {
        printf("%p ", a[i]);
    }
}

void arrcharLoc()
{
    char a[5];
    int i = 0;
    printf("  Character type memory location are : \n");
    for (i = 0; i < 5; i++)
    {
        printf("%p ", a[i]);
    }
}

void arrDoubleLoc()
{
    double a[5];
    int i = 0;
    printf("  Double type memory location are : \n");
    for (i = 0; i < 5; i++)
    {
        printf("%p ", a[i]);
    }
}

int main()
{
    while (1)
    {
        int n = menu();
        switch (n)
        {
        case 1:
            arrIntLoc();
            break;

        case 2:
            arrFloatLoc();
            break;

        case 3:
            arrcharLoc();
            break;

        case 4:
            arrDoubleLoc();
            break;

        default:
            n==0? printf("Thank you.\n") : printf("Enter a valid input.\n");
            break;
        }
        if (n==0)
        {
            break;
        }
        
    }

    return 0;
}