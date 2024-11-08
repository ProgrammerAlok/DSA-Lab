
// .......Ternary Operator.....

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    // for two variable.

    // int a, b, c;
    // printf("Enter a, b number : \n");
    // scanf("%d %d", &a , &b );
    // c=(a>b)?a:b;
    // printf("%d", c);

    //for three variable.
    int a, b, c, d;
    printf("Enter a, b, c number : \n");
    scanf("%d %d %d", &a , &b, &c );
    d=(a>b)?(a>c)?a:c:(b>c)?b:c;
    printf("%d", d);

    return 0;
}