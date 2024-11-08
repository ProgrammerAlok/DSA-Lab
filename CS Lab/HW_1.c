#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int z;
    int n, i, n2, n3;
    // float n2;
    printf("Press 1 for check a number is prime or not.\n");
    printf("Press 2 for check a number is even or odd.\n");
    printf("Press 3 for check a number is divisible by 5 or not.\n");
    scanf("%d", &z);
    switch (z)
    {
    case 1:
        while(n!=0)
        {
            int flag=0;
            printf("Enter a number: \n");
        scanf("%d", &n);
        for(i=2 ; i<=n/2 ; i++)
        {
            if(n%i==0)
            {
            flag=1;
            break;
            }
        }
        if(flag==0)
        {
            printf("%d is a prime number.\n", n);
        }
        else
        {
            printf("%d is not a prime number.\n", n);
        }
        }
        break;
    
    case 2 :
    while (n2!=0)
    {    
        printf("Enter a number: \n");
        scanf("%d", &n2);
        if(n2==0)
            printf("if %d is divisible by something it becomes infinity.\n", n2);
        else if(n2%2==0)
            printf("%d is a even number.\n", n2);
        else
            printf("%d is a odd number.\n", n2);
    }  

    case 3:
    while(n3!=0)
    {   printf("Enter a number: \n");
        scanf("%d", &n3);
        if(n3==0)
            printf("if %d is divisible by something it becomes infinity.\n", n3);
        else if(n3%5==0)
            printf("%d is divisible by %d.\n", n3, 5);
        else
            printf("%d is not divisible by %d.\n", n3, 5);

    }                         

    default:
        printf("Please enter a valid number.\n");
        break;
    }
    return 0;
}